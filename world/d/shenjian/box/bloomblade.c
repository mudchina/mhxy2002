#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name( HIR "血刀" NOR, ({ "bloomblade" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",
                        
"通体暗红的宽面窄刃长刀。\n"
);
		set("no_get",1);
		set("no_drop",1);
                set("value", 1);
		set("for_bandit",1);
                set("material", "steel");
                set("wield_msg", "$N「唰」地一声抽出一把红光闪动$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插入腰间的刀鞘。\n");
        }

        init_blade(85);
        setup();

}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int pro;
	int dam;
	pro = (int) victim->query_temp("apply/armor_vs_fire");
	dam = (int) me->query("force");
	if(dam > pro)
	{
	victim->receive_wound("kee",10);
	return HIR "血刀幻起一片红光罩住$n的全身。\n" NOR;
	}
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