#include "FiberPool.hpp"

#include "ScriptMgr.hpp"

namespace YimMenu
{
	void FiberPool::InitImpl(int num_fibers)
	{
		for (std::size_t i = 0; i < num_fibers; ++i)
		{
			ScriptMgr::AddScript(std::make_unique<Script>(&ScriptEntry));
		}
	}

	void FiberPool::DestroyImpl()
	{
		std::lock_guard lock(m_Mutex);

		while (!m_Jobs.empty())
			m_Jobs.pop();
	}

	void FiberPool::PushImpl(std::function<void()> callback)
	{
		std::lock_guard lock(m_Mutex);
		m_Jobs.push(std::move(callback));
	}

	void FiberPool::Tick()
	{
		std::unique_lock lock(m_Mutex);

		if (!m_Jobs.empty())
		{
			auto job = std::move(m_Jobs.top());
			m_Jobs.pop();
			lock.unlock();

			std::invoke(std::move(job));
		}
	}

	void FiberPool::ScriptEntry()
	{
		while (true)
		{
			FiberPool::GetInstance().Tick();
			ScriptMgr::Yield();
		}
	}
}