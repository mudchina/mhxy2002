// xiaoran 

#include <ansi.h>
#include <armor.h>
#include <command.h>
inherit FINGER;
inherit F_AUTOLOAD;

void create()
{
	set_name(HIC"钻石"HIY"戒指"NOR, ({"zuanshi jiezhi","zuanjie","jiezhi","ring"}));
	set("weight", 0);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "这是"HIC"萧然"NOR"送给"HIM"情深の缘浅"NOR"的订婚钻戒。\n");
		set("value", 0);
		set("material", "gold");
		set("armor_prop/armor", 30);
		set("armor_prop/dodge", 30);
		set("no_sell",1);
		set("no_get",1);
		set("no_drop","你还是决定让这段"HIR"爱"NOR"永恒，所以你一定不会放弃。\n");
//		set("no_give","你回忆起和萧然在一起"HIM"开心的日子"NOR"，怎么舍得将"+this_object()->query("name")+"放弃呢？你还是决定让这段"HIR"爱永恒"NOR"。\n");
	}
	setup();
}	

 int query_autoload()
 {
        return 1;
 }