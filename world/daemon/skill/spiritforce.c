// spiritforce.c ， 灵力
//created by foc,10-6-01
//特点：极难修炼或者学习。不过好处可是很多的。要小心学习或练习
//中可能会意外死亡。

inherit FORCE;

#include <ansi.h>

int valid_enable(string usage) 
{ 
     return usage=="force"; 
}

int valid_learn(object me) 
{
        if( (int)me->query("int") < 25 || (int)me->query_skill("literate", 1 ) < 109 )
        return notify_fail("你的悟性不足以开始了解什么是灵气。\n");
        if( (int)me->query_skill("spiritforce", 1 ) > 285 )
        return notify_fail("你的灵力修为已经到了前所未有的境界，要再进步是不可能的了。\n");
        if( (int)me->query_skill("force", 1) < 60 )
        return notify_fail("你现在的体质根本没办法开始灵力的修炼。\n");
        if( (int)me->query_skill("force", 1) < (int)me->query_skill("spiritforce", 1) )
{
        me->receive_damage("kee", (int)me->query_skill("spiritforce", 1) * 2 );
        message_vision(HIR"$N身体内的灵气突然开始向身体外膨胀，$N不由得惨叫一声，鲜血已\n经从全身流了出来。\n"NOR,me);
        write ("看起来你的基础没有打好。\n");
}
        if( (int)me->query("max_kee") < 350 && (int)me->query_skill("spiritforce", 1) < 60 && (int)me->query_skill("spiritforce", 1) > 30 )
        return notify_fail("现在你已经进入了灵力的第二阶段修行，没有足够的体力是没办法应付的。\n"); 
        if( (int)me->query_skill("force", 1)/3 > (int)me->query_skill("spiritforce", 1 ) - random((int)me->query("kar")) )
{
        me->improve_skill("spiritforce", 80000 );
        message_vision(HIC"$N似乎领悟到了什么，在灵力上的修炼猛地进步了！"NOR,me);
}
        return 1;
}

int practice_skill(object me)
{
      if( (int)me->query_skill("spiritforce", 1 ) < 60 )
      return notify_fail("通过练习进步？好主意！不过似乎你的灵力修为还不足以开始自我修行。\n爱惜生命吧，别玩出火来了。\n");
      if( (int)me->query_skill("force", 1) < 100 )
      return notify_fail("你的基础不够，就这么练习搞不好就翘辫子了！\n");
      if( (int)me->query("max_kee") < 350 && (int)me->query_skill("spiritforce", 1) < 60 && (int)me->query_skill("spiritforce", 1) > 30 )
      return notify_fail("现在你已经进入了灵力的第二阶段修行，没有足够的体力是没办法应付的。\n"); 
      if( (int)me->query_skill("force", 1) < (int)me->query_skill("spiritforce", 1) )
{     
      me->receive_damage("kee", (int)me->query_skill("spiritforce", 1) * 2 );
      message_vision(HIR"$N身体内的灵气突然开始向身体外膨胀，$N不由得惨叫一声，鲜血已\n经从全身流了出来。\n"NOR,me); 
      write ("没有足够的基础可不能随便练习灵力。\n");
}
      if( (int)me->query_skill("force", 1)/4 > (int)me->query_skill("spiritforce", 1) - random((int)me->query("kar")) )
{
      me->improve_skill("spiritforce", 80000 );
      message_vision(HIC"$N似乎领悟到了什么，在灵力上的修炼猛地进步了！"NOR,me);
}
      if( (int)me->query_skill("spiritforce", 1 ) > 285 )
      return notify_fail("你的灵力修为已经到了前所未有的境界，要再进步是不可能的了。\n");
      
      return 1;
}

string exert_function_file(string func)
{
      return CLASS_D("mojie") + "/spiritforce/" + func;
}


void skill_improved(object me)
{
      if((int)me->query_skill("spiritforce", 1 )==70 )
{
      me->add("str", 2 );
      message_vision(GRN"$N试着放出灵气，结果立刻形成了巨大的灵气旋涡，花花草草都被刮走了，哇！\n"NOR,me);
      write ("你深深地吸了口气，觉得自己的力量变强了。\n");
}
      if((int)me->query_skill("spiritforce", 1 )==140 )
{
      me->add("spi", 2 );
      message_vision(GRN"$N全身的灵气突然自己放了出来，在空气中形成了一个模糊的人形。\n但是很快就消失了。"NOR,me);
}
      if((int)me->query_skill("spiritforce", 1 )==210 )
{
      me->add("max_force", 400 );
      message_vision(GRN"$N全身的灵气突然释放出来，形成一个了巨大的凤凰。$N觉得自己好象悟到了什么，但却说不上来。\n"NOR,me);
}
      if((int)me->query_skill("spiritforce", 1 )==280 )
{
      me->add("con", 2);
      me->add("cps", 2);
      me->add("cor", 3);
      me->add("spi", 2);
      me->add("int", 3);
      me->add("kar", -2);
      me->add("per", 3);
      me->add("daoxing", 500000);
      me->add("combat_exp", 500000);
      me->improve_skill("segokee",10000);
      message_vision(HIY"$N的双眼放出金黄色的光，接着全身的灵气也变成了纯金黄色。你终于练成圣光气了，连如\n来佛祖都没练成过的终极斗气！\n"NOR,me);
      write ("你心中十分欣喜，但又想到练成这种为天地所妒忌的斗气，不免有损于阳寿和福缘，轻轻地叹了口气。\n");
      message("channel:rumor", HIM + "【谣言】如来佛祖：听说"+
     me->query("name")+"练成传说中的圣光气了！哇，不会来抢我的位子吧？\n"NOR,users());

}

}
