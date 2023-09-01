#pragma once
#include "BoolCommand.hpp"

namespace YimMenu
{
	class LoopedCommand : public BoolCommand
	{
	protected:
		virtual void OnTick() = 0;

	public:
		LoopedCommand(std::string name, std::string label, std::string description);
		void Tick();
	};
}