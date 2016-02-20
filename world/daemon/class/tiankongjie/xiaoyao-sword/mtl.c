//icejia
#include <ansi.h>
 
inherit SSERVER;

int perform(object me, object target)
{
  string msg,targetrude;
  int success,hurt,diff,damage;
  int myexp=(int)me->query("combat_exp")/3000;
  int mylev=(int)me->query_skill("unarmed");
  int mystr=(int)me->query("str")+(int)(me->query_skill("sword")/10-2);
  int mykar=(int)me->query_kar();
  int targetlev, targetstr,targetkar,targetexp,targeteffkee;
  string *hitone = ({
    "$n眼见刀光铺天盖地袭来，却不知如何躲避，结果一道剑气穿体而过！\n",
    "$n侧身急转，企图躲过刀光，但为时已晚，剑气从肩头穿出！\n",
    "$n被这阵势吓呆了，无从躲闪，一道剑光正好划上小腹。\n",
  });
  string *missone = ({
    "$n轻轻一闪，将剑气避了开去，虽然剑气来势凶猛，但没伤到$n分毫。\n",
    "$n高举手中兵刃奋力一挡，只见一阵黄光，$N发出的剑气被硬挡下来！\n",
    "$n无视剑光的凶猛，反而运真气抵抗，两股真气在空中相遇，发出一道强光。\n",
  });
  string *hittwo = ({
    "$n丝毫没有在意这看似平常的一剑，却不想其中变化异常，结果$n身上出现严重的划伤！\n",
    "$n没想道$N攻势如此之快，急忙低头闪避，但无法躲开，被剑气划得皮开肉绽！\n",
    "由于$N攻势太快，$n回防不及，喉上被割掉一片皮，显然伤得不轻！\n",
  });
  string *misstwo = ({
    "$n身体微微一侧，避过了$N的快剑。\n",
    "$n似乎早已料到这一招，顺势将$N的手腕上一推，避了开去。\n",
    "眼看这招要把$n脑袋戳个对穿，突然间$n运气于兵刃之上，反戈一击，逼的$N只好回手自救。\n",
  });
  string *hitthree = ({
    "$n一时眼花，$N乘势一掌，穿透了$n的心汇穴，$n吐出一口鲜血。\n",
    "$n看清$N的掌风来路，一把将$N的手腕抓住，不想$N化气为刀锋，刀光正好划中$n的命门！\n",
    "$n企图用兵刃撩开$N的掌沿，却被$N看出意图，转身改用剑柄磕上$n的心海穴！\n",
  });
  string *missthree = ({
    "$n似乎早已熟知这招的套路，几个急转之下，将$N的招数尽数破解。\n",
    "$n看清$N的剑气来路，一把将$N的手腕抓住，将这招破于无形。\n",
    "$n不顾自身危险，中宫直进，反点向$N的百汇穴，果然将来招化解了。\n",
  });
  string *hit=({
    HIC"$N运功结束，霸气也随之消散。\n"NOR,
    HIC"这天空界的曼佗罗剑阵果然不同凡响，$n几个踉跄，已经站不住了。\n"NOR,
    HIC"$N纵声狂笑道：“怎么样？你该知道厉害了吧！！！”\n"NOR,
  });
  string *miss;
  
        if( (string)me->query("family/family_name") != "天空界")
     return notify_fail("你不是天空界的人，不使不出那招。\n");
  if( !target ) target = offensive_target(me);
  if( !target
     ||      !target->is_character()
     ||      !me->is_fighting(target) )
    return notify_fail("只能对战斗对手施展“曼佗罗剑阵”。\n");
  targetexp=(int)target->query("combat_exp")/5000;
  targetlev=(int)target->query_skill("parry");
  targetstr=(int)target->query("str")+(int)(target->query_skill("dodge")/10-2);
  targetkar=(int)target->query_kar();
  miss=({
    HIM"$n哈哈大笑道：“人言天空界的曼佗罗剑阵多么厉害，今天看来，也不过如此！”\n"NOR,
    HIM"$n一阵狂笑：“要胜我？再等十年吧！”\n"NOR,
    HIM"$n仰天大笑道：“雕虫小技，何足挂齿！”\n"NOR,
  });
  if((string)me->query_skill_mapped("force")!="mtl-force")
    return notify_fail("这式曼佗罗剑阵需用曼佗罗心经的寒气来驱动。\n");
  if(me->query_skill("mtl-force",1) < 250)
    return notify_fail("你的内功底子不足，无法将真气散出体外。\n");
  if(me->query_skill("xiaoyao-sword",1)<250)
    return notify_fail("你对逍遥剑不够熟悉，无法运剑自如！\n");
  if(me->query_skill("piaoyun-zhang",1)<250)
    return notify_fail("你对飘云掌不够熟悉，无法认准穴位！\n");
  if(me->query("max_force") < 2000 || me->query("force")<1500)
    return notify_fail("你的内力不足，不足以以真气伤人。\n");
  msg = HIC "$N打喝一声运起曼佗罗心经。刹那间天寒之气散布出体外形成漫天大雾。
"HIW"白雾中$N剑人和一象$n飞射过去！\n" NOR;
  if( random(mylev+targetlev+mystr*3+targetstr*3) > (targetlev+targetstr*3))
    {
      msg += hitone[random(sizeof(hitone))];
      success+=1;
      if(random(mykar+targetkar)>targetkar) hurt+=1;
      damage=15+random(mykar/3);
    }
  else msg+=missone[random(sizeof(missone))];
  msg+=HIW"\n$N落地之后，顺势歪歪斜斜自云雾中刺出一剑！\n"NOR;
  if( random(myexp+targetexp+mylev+targetlev) > (targetexp+targetlev))
    {
      msg += hittwo[random(sizeof(hittwo))];
      success+=1;
      if(random(mykar+targetkar)>targetkar) hurt+=1;
      damage+=15+random(mykar/3);
    }
  else msg+=misstwo[random(sizeof(misstwo))];
  msg+=HIW"\n$N运功驱动真气扑向$n，同时脚下几个回转，一掌拍了过去！\n"NOR;
  if(random(myexp+targetexp+mykar*10+targetkar*10)>(targetexp+targetkar))
    {
      msg+=hitthree[random(sizeof(hitthree))];
      success+=1;
      if(random(mykar+targetkar)>targetkar) hurt+=1;
      damage+=15+random(mykar/3);
    }
  else msg+=missthree[random(sizeof(missthree))];
  diff=3-success;
  if (diff<0) diff = 0;
  if (success) hurt=damage*hurt/success;
  else hurt=0;
  me->add("force", -(400*success+200*diff));
  targeteffkee=(int)target->query("eff_kee");
  target->receive_wound("kee", targeteffkee*hurt/50);
  target->receive_damage("kee", target->query("kee")*(damage-hurt)/50);

  if(success)
    {
    me->start_busy(2+random(4-(mykar+5)/10));
  msg+=hit[random(sizeof(hit))];  
  message_vision(msg, me, target);
  COMBAT_D->report_status(target);        

    }
  else
    {
        me->start_busy(1+random(4-(mykar+5)/10));
      msg+=miss[random(sizeof(miss))];
  message_vision(msg, me, target);
    }       
  return 1;
}


