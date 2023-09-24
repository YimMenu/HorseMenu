#pragma once

namespace YimMenu
{
	class ExceptionHandler final
	{
	public:
		ExceptionHandler();
		virtual ~ExceptionHandler();

	private:
		void* m_Handler;
		uint32_t m_OldErrorMode;
	};

	extern LONG VectoredExceptionHandler(EXCEPTION_POINTERS* exception_info);
}