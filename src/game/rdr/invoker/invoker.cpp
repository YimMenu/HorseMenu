#include "invoker.hpp"
#include "game/pointers/Pointers.hpp"

extern "C" void _call_asm(void* context, void* function, void* ret);

namespace YimMenu
{
	native_call_context::native_call_context()
	{
		m_return_value = &m_return_stack[0];
		m_args         = &m_arg_stack[0];
	}

	void native_invoker::begin_call()
	{
		m_call_context.reset();
	}

	void native_invoker::end_call(scrNativeHash hash)
	{

		auto native_address = Pointers.GetNativeAddress(hash);

		if (!native_address)
		{
			LOG(WARNING) << "Exception caught while trying to call " << (hash) << " native.";
			return;
		}

		scrNativeHandler handler = (scrNativeHandler) native_address;

		handler(&m_call_context);
	}
}