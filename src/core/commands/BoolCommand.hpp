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
		virtual void SaveState(nlohmann::json& value) override;
		virtual void LoadState(nlohmann::json& value) override;

		bool m_State = false;

	public:
		BoolCommand(std::string name, std::string label, std::string description);
		bool GetState();
		void SetState(bool state);

		inline void Shutdown()
		{
			this->OnDisable();
		}
	};
}