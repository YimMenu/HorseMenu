#include "ExceptionHandler.hpp"
#include "StackTrace.hpp"

#include <unordered_set>
#include <hde64.h>

namespace YimMenu
{
	inline auto HashStackTrace(std::vector<uint64_t> stack_trace)
	{
		auto data        = reinterpret_cast<const char*>(stack_trace.data());
		std::size_t size = stack_trace.size() * sizeof(uint64_t);

		return std::hash<std::string_view>()({data, size});
	}

	ExceptionHandler::ExceptionHandler()
	{
		LOG(INFO) << "ExceptionHandler initialized";
		m_OldErrorMode = SetErrorMode(0);
		m_Handler      = SetUnhandledExceptionFilter(&VectoredExceptionHandler);
	}

	ExceptionHandler::~ExceptionHandler()
	{
		SetErrorMode(m_OldErrorMode);
		SetUnhandledExceptionFilter(reinterpret_cast<decltype(&VectoredExceptionHandler)>(m_Handler));
	}

	inline static StackTrace trace;
	LONG VectoredExceptionHandler(EXCEPTION_POINTERS* exception_info)
	{
		const auto exception_code = exception_info->ExceptionRecord->ExceptionCode;
		if (exception_code == EXCEPTION_BREAKPOINT || exception_code == DBG_PRINTEXCEPTION_C || exception_code == DBG_PRINTEXCEPTION_WIDE_C)
			return EXCEPTION_CONTINUE_SEARCH;

		static std::unordered_set<std::size_t> logged_exceptions;

		trace.NewStackTrace(exception_info);
		const auto trace_hash = HashStackTrace(trace.GetFramePointers());
		if (const auto it = logged_exceptions.find(trace_hash); it == logged_exceptions.end())
		{
			LOG(FATAL) << trace;
			Logger::FlushQueue();

			logged_exceptions.insert(trace_hash);
		}

		if (IsBadReadPtr(reinterpret_cast<void*>(exception_info->ContextRecord->Rip), 8))
		{
			auto return_address_ptr = (uint64_t*)exception_info->ContextRecord->Rsp;
			if (IsBadReadPtr(reinterpret_cast<void*>(return_address_ptr), 8))
			{
				LOG(FATAL) << "Cannot resume execution, crashing";
				return EXCEPTION_CONTINUE_SEARCH;
			}
			else
			{
				exception_info->ContextRecord->Rip = *return_address_ptr;
				exception_info->ContextRecord->Rsp += 8;
			}
		}
		else
		{
			hde64s opcode{};
			hde64_disasm(reinterpret_cast<void*>(exception_info->ContextRecord->Rip), &opcode);
			if (opcode.flags & F_ERROR)
			{
				LOG(FATAL) << "Cannot resume execution, crashing";
				return EXCEPTION_CONTINUE_SEARCH;
			}
			exception_info->ContextRecord->Rip += opcode.len;
		}

		return EXCEPTION_CONTINUE_EXECUTION;
	}
}

static YimMenu::ExceptionHandler _ExceptionHandler{};