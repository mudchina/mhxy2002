// ken 1999.12.11

#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name(HIG"凝碧剑" NOR, ({ "ningsword" ,"sword"}) );
        set_weight(70000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",                        
"这正是华山掌门的信物凝碧剑。\n");
                set("value", 1);
		set("for_bandit",1);
		set("no_get",1);
		set("no_drop",1);
                set("material", "steel");
                set("wield_msg", "$N从古朴的剑鞘中抽出一柄寒气逼人的$n。\n");
                set("unwield_msg", "$N随手中将$n抛向空中，$n化作一道碧光落入剑鞘之中。\n");
             }

        init_sword(100);
        setup();

}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int pro;
	int dam;
	dam = (int) me->query("force");
        victim->receive_damage("gin",dam/7);
        victim->receive_damage("kee",dam/5);  
	victim->receive_damage("sen",dam/7);
	return HIG "一片碧色光芒将$n罩在无尽的幻想中，幻象中的$n显得精神恍惚！！！\n" NOR;
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