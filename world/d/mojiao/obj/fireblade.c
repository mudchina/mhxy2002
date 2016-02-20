#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
   set_name(RED "魔刀" NOR, ({"fire blade", "blade", "dao"}));
   set_weight(5000);
   set("unit", "把");
   set("long", "一把深红色的刀，上面正燃烧着一道道的烈火。\n");
   set("value", 89000);
   set("material", "fire");
   set("wield_msg",
"$N手一挥$n，顿时一道红光直冲云霄！\n");
   set("unwield_msg",
"$N轻轻的将$n一搓，化做了一团火球捏在手中，\n");

   init_blade(50);

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
     if( (int)env->query_skill("evil-force", 1) < 120 )
     {
        message_vision("只见火焰轰的一声跳了一下，$N脸上被火烧了几个大泡。\n", env);
        env->apply_condition("heavy_fire_poison", 10);
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
        victim->receive_damage("kee",90);
        return HIR "$N运劲猛的一震手中的魔刀，顿时射出漫天的魔火烧向了$n，$n被烧的焦头烂额！！！\n" NOR;
}
