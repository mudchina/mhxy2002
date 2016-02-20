#include <weapon.h>
inherit THROWING;
void create()
{
	set_name("梅树幼苗", ({ "tree", "plum tree" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","又软又轻的树苗，也许你可以用来造（ｍａｋｅ）些东西．\n");
		set("unit", "捆");
		set("base_unit", "根");
		set("base_weight", 10000);
		set("base_value", 1);
	}
	set_amount(1);
	init_throwing(20);
	setup();
}
void init()
{
  if(this_player()==environment())
  add_action("do_make","make");

}

int do_make()
{
	object msword;
	if(query_amount() < 2)
	return notify_fail("才"+chinese_number(query_amount())+
	"根梅树幼苗，什么也造不出呀．．．\n");
	msword = new(__DIR__"msword");
	if(msword->move(this_player()))
	write("你用灵巧的双手造出了一把小木剑。\n");
            destruct(this_object());

		return 1;
			
}
