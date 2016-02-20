// TIE@FY3

#include <ansi.h>
#include <weapon.h>
inherit WHIP;
void create()
{
        set_name( "慈悲鞭", ({ "whip" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("value", 1);set("no_shown",1);
		set("no_get",1);
		set("no_drop",1);  
                set("material", "skin");
        }
        init_whip(120);

        set("wield_msg", "$N口宣佛号，从腰间摸出一条$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n束在腰间。\n");

        setup();
}

void init()
{
	add_action("do_make","remake");
}
int do_make()
{
	object me;
	object obj;
	me=this_player();
	obj=new(__DIR__"box");
	obj->move(me);
	if(query("equipped")) unequip();
	tell_object(me,"你将手中的"+query("name")+"又拆开，组成个箱子。\n");
        destruct(this_object());
	return 1;
}          