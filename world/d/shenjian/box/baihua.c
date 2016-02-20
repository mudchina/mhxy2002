
#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name( HIR "无" + HIG "双" + HIC "百花剑" NOR, ({ "baihua sword", "sword"}) );
        set_weight(70000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long",
                        
"一把闪着奇异光芒的锋利宝剑，是传说中三大神兵器之一。\n"
);
                set("value", 18000);
                set("for_bandit",1);
                set("material", "steel");
                set("wield_msg", "$N从镶满五色宝石的翡翠剑鞘中抽出一柄寒气逼人的$n。\n");
                set("unwield_msg", "$N随手中将$n抛向空中，$n化作片片飞花落入翡翠剑鞘中。\n");
        }
        init_sword(100);
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int pro;
        int dam;
        dam = (int) me->query("force");
        victim->receive_damage("gin",dam/10);
        victim->receive_damage("sen",dam/10);
        victim->receive_damage("kee",dam/10);
        return HIG "无形的剑气化做片片飞花将$n罩在无尽的幻想中，幻象中的$n显得精神恍惚！！！\n" NOR;
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
