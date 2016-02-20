inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIB"水池"NOR, ({ "pool" , "水池"}) );
	set_weight(500);
	set_max_encumbrance(200000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "一个发出鱼鳞般的光芒的水池，可以ｓｗｉｍ\n");
		set("value", 1);
	}
}
int is_container() { return 1; }
