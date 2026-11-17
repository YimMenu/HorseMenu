#pragma once
#include <rage/atArray.hpp>

// TODO

class CInventoryItemInfo
{
public:
	char pad_0000[0x0008];
	uint32_t m_hash; // 0x0008
};

class CInventoryItem
{
public:
	char pad_0000[0x0018];
	uint32_t m_amount; // 0x0018
	char pad_001C[0x001C];
	CInventoryItemInfo* m_info; // 0x0038
};

class CInventoryItemList
{
public:
	char pad_0000[0x0048];
	rage::atArray<CInventoryItem*> m_items; // 0x0048
};

// TODO: figure this out so we can iterate the pool ourselves instead of calling a game function
class CInventoryNode
{
public:
	uint32_t m_id;
	char pad_0004[0x0004];
	uint64_t m_value; // 0x0008
	uint64_t m_next; // 0x0010
};

class CInventoryPool
{
public:
	char pad_0000[0x1640];
	CInventoryNode** m_nodes; // 0x1640
	uint32_t m_count; // 0x1648
};
