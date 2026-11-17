#include "core/commands/Command.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/data/ItemTypes.hpp"

#include <climits>
#include <cstdlib>

#ifndef u32
typedef unsigned int u32;
#endif

namespace Terminus::Features
{
	// Structures required for inventory operations
	struct sGuid
	{
		alignas(8) int data1;
		alignas(8) int data2;
		alignas(8) int data3;
		alignas(8) int data4;
	};

	struct sSlotInfo
	{
		alignas(8) sGuid guid;
		alignas(8) int f_1;
		alignas(8) int f_2;
		alignas(8) int f_3;
		alignas(8) int slotId;
	};

	struct sItemInfo
	{
		alignas(8) int f_0;
		alignas(8) int f_1;
		alignas(8) int f_2;
		alignas(8) int f_3;
		alignas(8) int f_4;
		alignas(8) int f_5;
		alignas(8) int f_6;
	};

	// Helper functions
	sGuid CreateNewGUID()
	{
		sGuid guid{};
		return guid;
	}

	sGuid GetPlayerInventoryItemGUID(u32 item, sGuid guid, u32 slotId)
	{
		sGuid outGuid{};
		INVENTORY::INVENTORY_GET_GUID_FROM_ITEMID(1, (Any*)&guid, item, slotId, (Any*)&outGuid);
		return outGuid;
	}

	sGuid GetPlayerInventoryGUID()
	{
		return GetPlayerInventoryItemGUID(MISC::GET_HASH_KEY("CHARACTER"), CreateNewGUID(), MISC::GET_HASH_KEY("SLOTID_NONE"));
	}

	u32 GetItemGroup(u32 item)
	{
		sItemInfo info{};

		if (!ITEMDATABASE::_ITEMDATABASE_IS_KEY_VALID(item, 0))
		{
			return 0;
		}
		if (!ITEMDATABASE::ITEMDATABASE_FILLOUT_ITEM_INFO(item, (Any*)&info))
		{
			return 0;
		}
		return info.f_2;
	}

	sSlotInfo GetItemSlotInfo(u32 item)
	{
		sSlotInfo slotInfo{};

		slotInfo.guid = GetPlayerInventoryGUID();
		slotInfo.slotId = MISC::GET_HASH_KEY("SLOTID_SATCHEL");

		u32 group = GetItemGroup(item);
		switch (group)
		{
		case 0xC2286F01: // CLOTHING
			if (!INVENTORY::_INVENTORY_FITS_SLOT_ID(item, MISC::GET_HASH_KEY("SLOTID_WARDROBE")))
			{
				slotInfo.guid = GetPlayerInventoryItemGUID(MISC::GET_HASH_KEY("WARDROBE"), slotInfo.guid, MISC::GET_HASH_KEY("SLOTID_WARDROBE"));
				slotInfo.slotId = INVENTORY::_GET_DEFAULT_ITEM_SLOT_INFO(item, MISC::GET_HASH_KEY("WARDROBE"));
			}
			else
			{
				slotInfo.slotId = MISC::GET_HASH_KEY("SLOTID_WARDROBE");
			}
			break;
		case 0x95A6F147: // HORSE
			slotInfo.slotId = MISC::GET_HASH_KEY("SLOTID_ACTIVE_HORSE");
			break;
		case 0x80FB92CD: // UPGRADE
			if (INVENTORY::_INVENTORY_FITS_SLOT_ID(item, MISC::GET_HASH_KEY("SLOTID_UPGRADE")))
			{
				slotInfo.slotId = MISC::GET_HASH_KEY("SLOTID_UPGRADE");
			}
			break;
		default:
			if (INVENTORY::_INVENTORY_FITS_SLOT_ID(item, MISC::GET_HASH_KEY("SLOTID_SATCHEL")))
			{
				slotInfo.slotId = MISC::GET_HASH_KEY("SLOTID_SATCHEL");
			}
			else if (INVENTORY::_INVENTORY_FITS_SLOT_ID(item, MISC::GET_HASH_KEY("SLOTID_WARDROBE")))
			{
				slotInfo.slotId = MISC::GET_HASH_KEY("SLOTID_WARDROBE");
			}
			else
			{
				slotInfo.slotId = INVENTORY::_GET_DEFAULT_ITEM_SLOT_INFO(item, MISC::GET_HASH_KEY("CHARACTER"));
			}
			break;
		}
		return slotInfo;
	}

	bool AddItemWithGUID(u32 item, sGuid& guid, sSlotInfo& slotInfo, u32 quantity, u32 addReason)
	{
		if (!INVENTORY::_INVENTORY_IS_GUID_VALID((Any*)&slotInfo.guid))
		{
			return false;
		}
		if (!INVENTORY::_INVENTORY_ADD_ITEM_WITH_GUID(1, (Any*)&guid, (Any*)&slotInfo.guid, item, slotInfo.slotId, quantity, addReason))
		{
			return false;
		}
		return true;
	}

	bool AddItemToInventory(u32 item, u32 quantity)
	{
		sSlotInfo slotInfo = GetItemSlotInfo(item);
		sGuid guid = GetPlayerInventoryItemGUID(item, slotInfo.guid, slotInfo.slotId);
		return AddItemWithGUID(item, guid, slotInfo, quantity, MISC::GET_HASH_KEY("ADD_REASON_DEFAULT"));
	}

	// Try to parse a string as a numeric hash value
	u32 TryParseHashValue(const char* str)
	{
		char* endptr;
		long long value = strtoll(str, &endptr, 10);

		// If the entire string was consumed and it's within valid range
		if (*endptr == '\0' && value >= INT_MIN && value <= INT_MAX)
		{
			u32 hash = static_cast<u32>(value);
			// Verify this hash is valid in the game's database
			if (ITEMDATABASE::_ITEMDATABASE_IS_KEY_VALID(hash, 0))
			{
				return hash;
			}
		}
		return 0;
	}

	// Try to add an item using both string name and fallback to hash
	bool TryAddItem(const char* itemName, u32 quantity)
	{
		// First attempt: Try using Joaat on the string name
		u32 itemHash = Joaat(itemName);

		if (itemHash != 0)
		{
			if (AddItemToInventory(itemHash, quantity))
			{
				return true; // Success using string name
			}
		}

		// Second attempt: Try parsing the string as a direct hash value
		// This handles cases where the string is like "-1035515486"
		u32 hashValue = TryParseHashValue(itemName);
		if (hashValue != 0)
		{
			if (AddItemToInventory(hashValue, quantity))
			{
				return true; // Success using direct hash
			}
		}

		return false; // Both attempts failed
	}

	// Main command class
	class GiveAllItems : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			int addedCount = 0;
			int failedCount = 0;
			u32 quantity = 1; // Use 1 for testing, increase as needed

			// Get the size of the array
			const size_t itemCount = sizeof(Data::g_ItemTypes) / sizeof(Data::g_ItemTypes[0]);

			// Properly iterate through all items with bounds checking
			for (size_t i = 0; i < itemCount; i++)
			{
				const char* itemName = Data::g_ItemTypes[i];

				// Skip null or empty entries
				if (!itemName || itemName[0] == '\0')
					continue;

				// Try to add the item (uses both string name and hash fallback)
				if (TryAddItem(itemName, quantity))
				{
					addedCount++;
				}
				else
				{
					failedCount++;
				}
			}

			// Optional: Show completion notification
			// char notificationText[256];
			// snprintf(notificationText, sizeof(notificationText), "Added %d items to inventory. Failed: %d", addedCount, failedCount);
			// UI::_0x202709F4C58A0424(notificationText, 0);
		}
	};

	static GiveAllItems _GiveAllItems{"giveallitems", "Give All Items", "Gives you all satchel items"};
}