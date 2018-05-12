class CfgPatches
{
    class adv_aceRefill
    {
        units[] = {
			"adv_aceRefill_autoKitItem"
			,"adv_aceRefill_manualKitItem"
		};
        weapons[] = {
			"adv_aceRefill_autoKit"
			,"adv_aceRefill_manualKit"
		};
        requiredVersion = 1.82;
        requiredAddons[] = {
			"ace_common"
			,"ace_medical"
			,"cba_common"
		};
		version = "1.0.1";
		versionStr = "1.0.1";
		author = "[SeL] Belbo // Adrian";
		authorUrl = "http://spezialeinheit-luchs.de/";
    };
};

#define MACRO_ADDITEM(ITEM,COUNT) class _xx_##ITEM { \
    name = #ITEM; \
    count = COUNT; \
}

class cfgFunctions {
	class adv_aceRefill {
		tag = "adv_aceRefill";
		class init
		{
			file = "adv_aceRefill\functions";
			class init { postInit = 1; };
			class itemCheck {};
			class refill {};
		};
	};
};

class cfgWeapons {
	class CBA_MiscItem;
	class CBA_MiscItem_ItemInfo;
	
    class adv_aceRefill_manualKit: CBA_MiscItem {
        scope = 2;
		scopeCurator = 2;
        displayName = "$STR_ADV_REFILL_NAME";
        picture = "\A3\Weapons_F\Items\data\UI\gear_Medikit_CA.paa";
		editorPreview = "\A3\EditorPreviews_F_Orange\Data\CfgVehicles\Land_FirstAidKit_01_closed_F.jpg";
		model = "\A3\Weapons_F\Items\Medikit";
        descriptionShort = "$STR_ADV_REFILL_DESCRIPTION";
        descriptionUse = "$STR_ADV_REFILL_DESCRIPTIONUSE";
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 120;
        };
	};
	
    class adv_aceRefill_autoKit: adv_aceRefill_manualKit {
        displayName = "$STR_ADV_REFILL_NAME_AUTO";
		descriptionShort = "$STR_ADV_REFILL_DESCRIPTION_AUTO";
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 80;
        };
	};
};

class cfgVehicles {
	class Item_Base_F;
	
	class adv_aceRefill_manualKitItem: Item_Base_F {
        scope = 2;
        scopeCurator = 2;
        displayName = "$STR_ADV_REFILL_NAME";
        author = "[SeL] Belbo";
        vehicleClass = "Items";
		model = "\A3\Weapons_F\Items\Medikit";
        class TransportItems {
            MACRO_ADDITEM(adv_aceRefill_manualKit,1);
        };
	};
	class adv_aceRefill_autoKitItem: adv_aceRefill_manualKitItem {
		displayName = "$STR_ADV_REFILL_NAME_AUTO";
        class TransportItems {
            MACRO_ADDITEM(adv_aceRefill_autoKit,1);
        };
	};
};