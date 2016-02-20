//firehit.c 邪王炎杀炼狱焦
//created by foc,20-06-01
//特点说明：连续性攻击pfm……杀伤力fear自己试试吧！
//随等级的提升，越来越厉害。

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
     int damage, time, myto, yourto, ft;
     if( !target ) target = offensive_target(me);
     if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
     return notify_fail("你要对谁使用「邪王炎杀炼狱焦」？\n");
     if(!me->is_fighting(target))
     return notify_fail("只能在战斗中使用「邪王炎杀炼狱焦」。\n");
     if(me->query_temp("firehit_busy"))
     return notify_fail("你刚想出招，右手却是一阵剧痛，力量根本使不出来。\n");
     if( (int)me->query_skill("evilfight",1) < 60 )
     return notify_fail("以你现在的炎杀拳修为，要用是不太可能的。\n");
     if( (int)me->query_skill("unarmed",1) < 60 )
     return notify_fail("你的基础都没打好，别乱玩火。\n");
     if( (int)me->query("max_force") < 700 )
     return notify_fail("开玩笑，以你现在的妖力要用这招，只能在晚上做梦的时候。\n");
     if( (int)me->query("force") < 300 )
     return notify_fail("你现在似乎心有余而力不足。\n");
     if( me->query_skill_mapped("force")!="evileye" )
     return notify_fail("你必须使用邪眼术来发动连击。\n");
     if((int)me->query_skill("evileye",1) < 60)
     return notify_fail("你的邪眼术修为不够，不能很好地控制力量的使用。\n");
     if((int)me->query("combat_exp") < 200000 )
     return notify_fail("对于战斗，你的领悟还太少，使用这招会有困难。\n");
     if((int)me->query("daoxing") < 100000 )
     return notify_fail("你的修为不够高，就算用出来了威力也不会大。\n");
     if((int)me->query("combat_exp")+(int)me->query("daoxing") > (int)target->query("combat_exp")*3+(int)target->query("daoxing")*3+(int)target->query("kar")*100 )
     return notify_fail("哎，哎，对手这么弱，别欺负小朋友嘛！\n");
     if((int)me->query_skill("evileye",1) > 60) ft=1;
     if((int)me->query_skill("evileye",1) > 120) ft=2;
     if((int)me->query_skill("evileye",1) > 180) ft=3;
     if((int)me->query_skill("evileye",1) > 240) ft=4;
     time =4-(int)me->query_skill("evileye",1)/60;
     if(time < 0) time=1;
damage=(int)me->query_skill("evilfight",1)+(int)me->query_skill("evileye", 1)+random((int)me->query("kar"))*3;
     myto=(int)me->query("combat_exp")/5+(int)me->query("daoxing");
     yourto=(int)target->query("combat_exp")/5+(int)target->query("daoxing");
     message_vision(HIC "$N头上的邪眼张开，顿时光芒大盛，强大的妖气不断在$N的右手上集中。\n" NOR,me,target);
     message_vision(HIR "突然，那妖气一变，一团熊熊燃烧的火焰出现了！\n" NOR,me,target);
     message_vision(HIG "$N大喝一声：“看招，邪王炎杀炼狱焦！”然后催动火焰发起了攻击！\n" NOR,me,target);
     message_vision(HIY "只见$N右拳连续击出，强大的妖气结合着火焰，带着巨大的冲击力向$n冲了过去！\n" NOR,me,target);
{    
     if(target->is_busy() || random(myto) >= random(myto+yourto))
{
     message_vision(GRN "结果$n惨叫一声，胸口已经中了好几拳，青烟直冒，好象肉被烧焦了。\n" NOR,me,target);
     target->receive_damage("kee",damage*ft/2);
     target->receive_damage("sen",damage*ft/2);
     target->receive_wound("kee",damage*ft/2);
     target->receive_wound("sen",damage*ft/2);
     COMBAT_D->report_status(target, 0);
     me->add("force",-100);
}
     else
{
     message_vision(GRN "但是$n气灌双手，将$N这几拳全部挡了下来。\n" NOR,me,target);
     tell_object (target, "不过你的手却受到了些许程度的烧伤。\n");
     target->receive_damage("kee",100);
     target->receive_damage("sen",100);
     COMBAT_D->report_status(target, 0);
     me->add("force",-100);
}
}
     message_vision(HIM "$N跃至空中，一个旋身，右脚带着炎热的火焰向$n劈将过来。\n" NOR,me,target);
{
     if(target->is_busy() || random(myto) >= random(myto+yourto))
{
     message_vision(GRN "$n躲避不及，被$N踢到了脖子，只听见“嚓”的一声响。$n顿时觉得天旋地转。\n" NOR,me,target);
     target->receive_damage("kee",damage*ft/2);
     target->receive_damage("sen",damage*ft/2);
     target->receive_wound("kee",damage*ft/2);
     COMBAT_D->report_status(target, 0);
     me->add("force",-100);
}
     else
{
     message_vision(GRN "$n不慌不忙，运力用右臂挡住了这一击。\n" NOR,me,target);
     me->add("force",-100);
}
}
     message_vision(HIW "$N脚未落地，发一声喊，双拳上的火焰立刻变得更炎热了，\n接着$N左右拳连番击出，破坏性的拳力夹着火焰，急风暴雨般卷向了$n！\n" NOR,me,target);
{
     if(target->is_busy() || random(myto) >= random(myto+yourto))
{
     message_vision(GRN "$n躲闪不及，全身上下一共中了几十拳，惨叫不断。\n" NOR,me,target);
     target->receive_damage("kee",damage*ft/2);
     target->receive_damage("kee",damage*ft/2);
     target->receive_wound("kee",damage*ft/2);
     target->receive_wound("sen",damage*ft/2);
     COMBAT_D->report_status(target, 0);
     me->add("force",-100);
}
     else
{
     message_vision(GRN "$n眼见$N的攻势汹汹，不敢硬拼，一连串的老驴打滚避了开去，狼狈之极。\n" NOR,me,target);
     me->add("force",-100);
}
}
     if((int)me->query_skill("evileye",1) >= 120 && target->is_living())
{
     message_vision(HIB "$N连击完毕，却又一咬牙，头上的邪眼放射出一道炙\n热的火焰。这一招实在是诡异，$n想躲也来不及了！\n" NOR,me,target);
     me->add("force",-200);
     target->receive_damage("kee",damage*ft/2);
     target->receive_damage("sen",damage*ft/2);
     target->receive_wound("kee",damage*ft/8);
     target->receive_wound("sen",damage*ft/8);
     COMBAT_D->report_status(target, 0);
     time +=1;
}
     if((int)me->query_skill("evileye",1) >= 180 && target->is_living())
{
     message_vision(HIR "$N刚一落地，$n见有机会，立刻上前抢攻！谁知$N一声冷笑，斗气再度放出，右手\n现出了黑色的龙纹，接着左手按在了右手之上。$n顿时感觉不妙。果然，$N大\n喝一声，右手化掌往前一推，一团黑色火焰立刻化做一条火龙击向$n！\n" NOR,me,target);
     time +=1;
     if(target->is_busy() || random(myto) >= random(myto+yourto))
{
     message_vision(GRN "$n躲闪不及，被那火龙穿胸而过，受伤不轻。\n" NOR,me,target);
     target->receive_damage("kee",damage*ft/2);
     target->receive_damage("sen",damage*ft/4);
     target->receive_wound("kee",damage*ft/10);
     target->receive_wound("sen",damage*ft/10);
     COMBAT_D->report_status(target, 0);
     me->reveive_wound("kee",20);
     me->receive_wound("sen",20);
     me->add("force",-100);
}
     else
{
     message_vision(GRN "$n连退数步，竭尽全力挡住了$N的攻击，不过却受了点烧伤。\n" NOR,me,target);
     me->reveive_wound("kee",10);
     me->receive_wound("sen",10);
     me->add("force",-100);
     target->receive_damage("kee",100);
     target->receive_damage("sen",100);
     COMBAT_D->report_status(target, 0);
}
}
     if(present("sword", this_player()) && (int)me->query_skill("evilsword",1) > 120 && target->is_living())
{
     message_vision(MAG "$N抓住机会，快步奔向$n，拔出剑带着紫黑色妖气斩向$n！\n" NOR,me,target);
     time +=1;
     if(target->is_busy() || random(myto) > random(myto+yourto))
{
     message_vision(GRN "结果$n的胸口被斩中，鲜血呼地就喷了出来。\n" NOR,me,target);
     target->receive_damage("kee",(int)me->query_skill("evilsword",1));
     target->receive_damage("sen",(int)me->query_skill("evilsword",1));
     target->receive_wound("kee",(int)me->query_skill("evilsword",1)/12);
     target->receive_wound("sen",(int)me->query_skill("evilsword",1)/12);
     COMBAT_D->report_status(target, 0);
     me->add("force",-100);
}
     else
{
     message_vision(GRN "但是$n使了个铁板桥，刚好躲过了这致命的攻击。\n" NOR,me,target);
     me->add("force",-100);
}
}
     if((int)me->query_skill("evilfight",1) > 240 && target->is_living())
{
     message_vision(GRN "$n大声骂道：“死妖怪，看你还有什么招！”骂完，冲上来欲作攻击。\n$N发动连击之后，体力有些透支，似乎只能挨打了！\n" NOR,me,target);
     message_vision(RED "但是$N拼出全力，将妖气变成烈焰向四周放射而出！\n" NOR,me,target);
     time +=1;
     if(target->is_busy() || random(myto) > random(myto+yourto))
{
     message_vision(GRN "结果$n被这火焰一烧，动作不免慢了下来。不过似乎并没有受到多重的伤害。\n" NOR,me,target);
     target->start_busy(4);
     time=0;
}
     else
{
     message_vision(GRN "不过$n巧妙地躲过了这一击，没有受到任何伤害。\n" NOR,me,target);
}
     tell_object (me, "一股鲜血从你的邪眼中射了出来，溅了一地！\n");
     me->receive_wound("kee",(int)me->query_skill("evileye",1));
     me->receive_wound("sen",(int)me->query_skill("evileye",1));
     COMBAT_D->report_status(me, 0);

}
     message_vision(HIG "$N停止了攻击，开始慢慢回复妖力。\n" NOR,me,target);
     if(time > 7) time=7;
     me->start_busy(time);
     if((int)target->query("kee") > 0)
     tell_object (target, "好机会，趁现在赶快发动攻击！\n");     
     me->set_temp("firehit_busy",1);
     call_out("remove_effect",120+random(5),me);

     return 1;
}

void remove_effect(object me)
{
  if (!me) return;
  me->delete_temp("firehit_busy");
  message_vision(HIW "$N觉得妖力恢复了，右手开始放出强大的妖气。\n" NOR,me);
}
