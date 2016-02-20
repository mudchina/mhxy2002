#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
            set_name(HIW"蝉翼剑"NOR, ({"chanyi sword", "sword"}));
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "一把如丝、如线、如痕、如隐的薄剑\n");
                set("value", 5000);
 //               set("material", "crimsonsteel");
                set("wield_msg",
    "$N「唰」地一声抽出一把$n握在手中．天空似乎白了.\n");
                set("unwield_msg",
    "白光一闪，$N手中的$n寂然不见........\n");
          set("weapon_prop/cor", 10);
        set("no_get","神剑认主，你非其主人.......\n");
        set("no_give","神兵利器怎可轻易给人？\n");
        set("no_drop","江湖险恶，不可轻易放下手中的兵仞...\n");
        set("no_sell","小店怎敢收取传说中的神刃....\n");
        }
        
            init_sword(180);
        setup();
}
