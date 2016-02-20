#include <weapon.h>
inherit HAMMER;
void create()
{
        set_name("流星锤", ({ "flying hammer" }) );
        set_weight(12000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
  		set("no_get",1);
		set("no_drop",1);              set("long", "这是一把用铁链子栓着的铁锤\n");
                set("value", 1);
                set("material", "iron");
                set("wield_msg", "$N拿出一把$n，试了试重量，然後握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

 
     init_hammer(125);
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