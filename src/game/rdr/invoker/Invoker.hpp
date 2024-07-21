#pragma once
#include "Crossmap.hpp"
#include "game/pointers/Pointers.hpp"

#include <script/scrNativeHandler.hpp>
#include <script/types.hpp>

enum class NativeIndex;
namespace YimMenu
{
	class CustomCallContext : public rage::scrNativeCallContext
	{
	public:
		constexpr CustomCallContext()
		{
			m_ReturnValue = &m_ReturnStack[0];
			m_Args         = &m_ArgStack[0];
		}

	private:
		uint64_t m_ReturnStack[10];
		uint64_t m_ArgStack[40];
	};

	class NativeInvoker
	{
		static inline std::array<rage::scrNativeHandler, g_Crossmap.size()> m_Handlers;
		static inline bool m_AreHandlersCached{false};

	public:
		constexpr NativeInvoker(){};

		constexpr void BeginCall()
		{
			m_CallContext.reset();
		}

		template<int index, bool fix_vectors>
		constexpr void EndCall()
		{
			// TODO: try to get rid of this
			if (!m_AreHandlersCached) [[unlikely]]
				CacheHandlers();

			m_Handlers[index](&m_CallContext);
			if constexpr (fix_vectors)
				Pointers.FixVectors(&m_CallContext);
		}

		template<typename T>
		constexpr void PushArg(T&& value)
		{
			m_CallContext.PushArg(std::forward<T>(value));
		}

		template<typename T>
		constexpr T& GetReturnValue()
		{
			return *m_CallContext.GetReturnValue<T>();
		}

	public:
		static void CacheHandlers();

		template<int index, typename Ret, typename... Args>
		static constexpr FORCEINLINE Ret Invoke(Args&&... args)
		{
			NativeInvoker invoker{};

			invoker.BeginCall();
			(invoker.PushArg(std::forward<Args>(args)), ...);
			invoker.EndCall<index, std::is_same_v<Ret, Vector3>>();

			if constexpr (!std::is_same_v<Ret, void>)
			{
				return invoker.GetReturnValue<Ret>();
			}
		}

		static constexpr rage::scrNativeHandler GetNativeHandler(NativeIndex index)
		{
			if (!m_AreHandlersCached) [[unlikely]]
				CacheHandlers();

			return m_Handlers[(int)index];
		}

		CustomCallContext m_CallContext{};
	};
}