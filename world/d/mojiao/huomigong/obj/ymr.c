//modify by ken 2001.7.7
#include <ansi.h>
inherit F_UNIQUE;
#include <weapon.h>

inherit BLADE;

void create()
{
   set_name(HIR "炎魔刃" NOR, ({"evil blade", "blade", "dao"}));
   set_weight(5000);
   set("unit", "把");
   set("long", "一把深红色的刀，看起来是非常的邪恶．以致于你每次拿起这把刀时
都有要杀人的欲望．\n");
   set("value", 89000);
   set("material", "fire");
   set("wield_msg",
"$N手猛的一拍刀鞘，顿时飞一条全身冒着熊熊烈火的魔龙化做一把深红色的长刀
落在了$N的手中！\n");
   set("unwield_msg",
"$N轻轻的将$n一拍，$n化做了一条火龙飞进了$N的手里．\n");
   set("replace_file", "/d/mojiao/obj/fireblade");

   init_blade(210);

   if( clonep(this_object()) ) {
     set_default_object(__FILE__);
   }
   setup();
}

void init()
{   
   remove_call_out("do_melt");
   call_out("do_melt", 1);
}

void do_melt()
{
   if(this_object()) call_out("melt", 40+random(40));
}

void melt()
{
   object env;

        if(!this_object()) return;

   env=environment(this_object());

   if( env->is_character() )
   {//a player or a NPC.
     if( (int)env->query_skill("evil-force", 1) < 140 )
     {
        message_vision("只见火焰轰的一声跳了一下，$N脸上被火烧了几个大泡。\n", env);
        env->apply_condition("evil_fire_poison", 10);
        //note, 中毒了。
        destruct(this_object());
        return;
     }
   }

   else if( (int)env->query_max_encumbrance() > 0 && !environment(env) )
   {//a room.
     if( (string)env->query("outdoors") != "mojiao" )
     {
        tell_object(env,"刀上的火焰跳了几下便熄了。\n");
        destruct(this_object());
        return;
     }
   }

}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int pro;
        int dam;
        dam = (int) me->query("max_force");
        victim->receive_damage("kee",dam/10);
        return HIR "炎魔刃化做数条火龙飞向$n，一阵热风扫过之后，$n只觉得的体力大减！！！\n" NOR;
}
