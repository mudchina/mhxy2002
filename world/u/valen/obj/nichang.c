// jiasha.c
//

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
              set_name(MAG"七色霓裳"NOR, ({"color cloth", "nichang", "cloth" }) );
          set("long", "此乃织女用七彩云霞特别织就的天衣，触手轻似无物。\n");
	set_weight(0);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 40);
		set("armor_prop/dodge", 50);
                set("armor_prop/personality", 10);
                set("value", 50000);
                set("female_only", 1);

	}
	setup();
}

