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
		m_OldErrorMode    = SetErrorMode(0);
		m_Handler         = SetUnhandledExceptionFilter(&VectoredExceptionHandler);
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

		hde64s opcode{};
		hde64_disasm(reinterpret_cast<void*>(exception_info->ContextRecord->Rip), &opcode);
		if (opcode.flags & F_ERROR)
		{
			LOG(FATAL) << "Cannot resume execution, crashing";
			return EXCEPTION_CONTINUE_SEARCH;
		}

		exception_info->ContextRecord->Rip += opcode.len;
		return EXCEPTION_CONTINUE_EXECUTION;
	}
}

static YimMenu::ExceptionHandler _ExceptionHandler{};