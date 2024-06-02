#include "byte_patch_manager.hpp"

namespace YimMenu
{
	void Byte_Patch_Manager::InitImpl()
	{
		// put patches here

		LOG(INFO) << "Byte patch manager initialized";
	}

	void Byte_Patch_Manager::Init()
	{
		GetInstance().InitImpl();
	}

	Byte_Patch_Manager::~Byte_Patch_Manager()
	{
		BytePatch::RestoreAll();
	}

}