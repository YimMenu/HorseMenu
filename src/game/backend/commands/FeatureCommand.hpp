#pragma once
#include "../../../common.hpp"

namespace YimMenu
{
	class FeatureCommand;

	inline std::map<std::string, FeatureCommand> RegisteredCommands;

	class FeatureCommand
	{
	private:
		std::string name;
		std::string label;
		int num_args = 0;
		bool looped  = false;
		bool* global = nullptr;

		std::function<void()> feature_function;

	public:
		FeatureCommand(std::string name, std::string label, std::function<void()> func, int num_args = 0, bool looped = false, bool* global = nullptr) :
		    name(name),
		    label(label),
		    num_args(num_args),
		    feature_function(func),
		    looped(looped),
		    global(global)
		{
			RegisteredCommands.insert({name, *this});
		}

		std::vector<int> hotkey_modifiers;
		bool hotkey_listener;

		std::string GetName()
		{
			return name;
		}

		std::string GetLabel()
		{
			return label;
		}

		bool IsLooped()
		{
			return looped;
		};

		bool* GetGlobal()
		{
			return global;
		};

		void Call();
	};


}