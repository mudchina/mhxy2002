// 一线灵光

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        string msg,start;
        int ap, dp, success;
        target = offensive_target(me);

//      if( me->is_busy())
//              return notify_fail("你正忙着呢，先应付眼前的事吧。\n");

        if( (int)me->query("mana") < 100 )
                return notify_fail("你的法力不够了！\n");
        
        if(me->query("family/family_name")!="灵界")
                return notify_fail("你非灵界弟子，还是在这呆着吧..\n");

        if( (int)me->query("sen") < (int)me->query("max_sen")/5 )
                return notify_fail("你精神太差，难以集中精力念咒。\n");

        if( (int)me->query_skill("kongming-spells", 1) < 20)
             return notify_fail("你还不能领悟一线灵光。\n");

        ap=me->query_skill("spells")+me->query("max_mana")/10;
        if(target) dp=target->query_skill("spells")+target->query("max_mana")/10;

        if(!me->is_fighting() )
        {
          message_vision(HIC"只见$N身形一晃，化做一道灵光，寂然不见了。\n"NOR,me);
                me->add("sen", -me->query("max_sen")/10);
                me->add("mana", -50);
                success=1;
        }
        else
        {
message_vision(HIC"只见$N身形一晃，化做一道灵光。\n"NOR, me);
                if(random(ap+dp)>dp/2)
                {
message_vision(HIC"灵光寂然不见，只留下$n呆呆的立在原地。\n"NOR,me,target);
                        me->add("sen", -me->query("max_sen")/8);
                        me->add("mana", -50);
                        success=1;
                }
else message_vision(HIC"但$n眼急手快，身形晃动中，拦在$N身前。\n"NOR,me,target);
                me->add("mana", -50);
        }
        if(success)
        {
start="/d/lingjie/shengdian";
                me->move(start);
message("vision",HIW+me->name()+"的灵光一聚，静静而立。\n"NOR,environment(me),me),

tell_object(me, HIC"神殿里灵光一现，光影你中现出身形。\n"NOR);
                return 3+random(3);
        }
        return 3+random(5);

}
