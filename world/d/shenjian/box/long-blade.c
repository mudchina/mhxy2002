//lmd@wenxin
#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name( HIC "闪电龙麟劈" NOR, ({ "long-blade" }) );
        set_weight(70000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",
                        
"一把闪着丝丝麟光的宝刀，是传说中三大神兵之一\n"
);
                set("value", 1);
                set("for_bandit",1);
                set("material", "steel");
		set("no_get",1);
		set("no_drop",1);
                set("wield_msg", "$N一声轻啸，一拍腰间的刀鞘，一道闪电过后手中多了一把$n。\n");
                set("unwield_msg", "$N随手中将向天空一抛，$n化作一阵清风，回到鞘中。\n");
        }

        init_blade(100);
        setup();

}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int pro;
        int dam;
        dam = (int) me->query("force");
        victim->receive_damage("gin",dam/5);
        return HIC "闪电龙麟劈忽然化作数条青龙扑向$n，幻影过后$n觉得精力大减！！！\n" NOR;
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
