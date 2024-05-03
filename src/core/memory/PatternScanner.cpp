#include "PatternScanner.hpp"

#include "Module.hpp"
#include "game/pointers/Pointers.hpp"

#include <functional>
#include <future>


namespace YimMenu
{
	PatternScanner::PatternScanner(const Module* module) :
	    m_Module(module),
	    m_Patterns()
	{
	}

	bool PatternScanner::Scan()
	{
		if (!m_Module || !m_Module->Valid())
			return false;


		Pointers.Cache.Load();
		bool scanSuccess = true;
		std::vector<std::future<bool>> jobs;
		bool forceUpdate = false;
		if (Pointers.Cache.IsCacheOutdated())
		{
			LOG(INFO) << "CACHE OUTDATED";
			forceUpdate = true;
			Pointers.Cache.IncrementCacheVersion();
		}

		for (const auto& [pattern, func] : m_Patterns)
		{
			uintptr_t cachedPointer = Pointers.Cache.GetData(pattern->Name().data());
			if (cachedPointer != 0 && !forceUpdate)
			{
				LOG(INFO) << "USING CACHED PTR";
				std::invoke(func, cachedPointer);
			}
			else
			{
				LOG(INFO) << "QUEUEING PTR SCAN...";
				jobs.emplace_back(std::async(&PatternScanner::ScanInternal, this, pattern, func));
			}
		}


		for (auto& job : jobs)
		{
			job.wait();

			if (scanSuccess)
				scanSuccess = job.get();
		}
		if (!scanSuccess)
		{
			LOG(FATAL) << "Some patterns have not been found, continuing would be foolish.";
		}

		return scanSuccess;
	}

	bool PatternScanner::ScanInternal(const IPattern* pattern, PatternFunc func) const
	{
		const auto signature = pattern->Signature();

		for (auto i = m_Module->Base(); i < m_Module->End(); ++i)
		{
			if (signature.size() + i > m_Module->End())
				break;

			const auto instruction = reinterpret_cast<std::uint8_t*>(i);
			bool found             = true;
			for (std::size_t instructionIdx = 0; instructionIdx < signature.size(); ++instructionIdx)
			{
				if (signature[instructionIdx] && signature[instructionIdx].value() != instruction[instructionIdx])
				{
					found = false;
				}
			}

			if (found)
			{
				LOG(INFO) << "Found pattern [" << pattern->Name() << "] : [" << HEX(i) << "]";

				std::invoke(func, i);

				Pointers.Cache.GetOrUpdate(pattern->Name().data(), i);

				return true;
			}
		}

		LOG(WARNING) << "Failed to find pattern [" << pattern->Name() << "]";
		return false;
	}
}