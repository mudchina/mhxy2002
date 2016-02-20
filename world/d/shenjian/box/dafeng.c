#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name( HIG "大风刀" NOR, ({ "windblade" }) );
        set_weight(70000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",
                        
"一把身宽体厚，刀背一溜儿钢环的宝刀－海内十三件神兵利器之一\n"
);
                set("value", 1);
		set("for_bandit",1);
                set("material", "steel");
		set("no_get",1);
		set("no_drop",1);  
                set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
        }

        init_blade(75);
        setup();

}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int pro;
	int dam;
	dam = (int) me->query("force");
	victim->receive_damage("sen",dam/5);
	return HIG "大风刀发出的呼啸声扰得$n心神不宁。\n" NOR;
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