// LLY@FYSY 
// sword.c : an example weapon

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("三少爷的剑", ({ "3childe-sword", "sword" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把黑鱼皮鞘,黄金吞口的长剑,长七尺三存,份量大约有十来斤左右。\n");
		set("value", 76000);
		set("material", "steel");
	}
	init_sword(65);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "寒光一闪，$N的手中忽然多了一把$n。\n");
	set("unwield_msg", "$N手中的$n在一阵剑光之后便已不见。\n");

// The setup() is required.

	setup();
}
