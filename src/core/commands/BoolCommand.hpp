#pragma once
#include "Command.hpp"

namespace YimMenu
{
	class BoolCommand : public Command
	{
	protected:
		virtual void OnEnable(){};
		virtual void OnDisable(){};
		virtual void OnCall() override;

		bool m_State = false;

	public:
		BoolCommand(std::string name, std::string label, std::string description);
		bool GetState();
		void SetState(bool state);
	};
}