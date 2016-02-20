// LLY@FYSY 
// sword.c : an example weapon

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
	set_name(HIW "镶着十三颗明珠的剑" NOR, ({ "jewelsword" ,}) );
	set_weight(13000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一柄里包皮鞘，黄金吞口，上面缀着十三颗豆大明珠的长剑，江湖中不认得这柄剑的人并不多。\n");
		set("value", 1);set("no_get",1);
		set("no_drop",1);
		set("material", "steel");
	}
	init_sword(80);
	set("wield_msg", "没有人能看得见$N拔剑的动作，$N的$n忽然间就已经闪电般拔出。。\n");
	set("unwield_msg", "$N将$n收回剑鞘里。\n");
	setup();
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int pro;
        int dam;
        dam = (int) me->query("force");
        victim->receive_damage("gin",dam/13);
        victim->receive_damage("sen",dam/13);
        victim->receive_damage("kee",dam/13);
        return HIW "镶着十三颗明珠的剑上的明珠反射出耀眼的光芒扰的$n双眼刺痛。\n" NOR;
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
 