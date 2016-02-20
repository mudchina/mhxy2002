//妖狐鞭法，yaohu-whip.c
//created by foc,27-08-01
//特点说明：攻击力高，命中高，pfm强，无种族限制。

inherit SKILL;
#include <ansi.h>;

mapping *action = ({
   ([   "action":
"$N将妖力运上手中$w，将$w朝着$n一挥，凌厉的妖气顿时附在$w上，\n从各个方向袭向$n，看起来$n已经无处躲闪了！\n",
     "dodge":     -5,
     "parry":    -30,
     "damage":    80,
     "damage_type":   "割伤"
   ]),
   ([   "action":
"$N凌空跃起，右手一挥，"+HIG"手中$w居然变长了"NOR"。$N将妖力一运，\n那$w立刻像有灵性似的，暴风骤雨般卷向$n！\n",
     "dodge":     -15,
     "parry":     -25,
     "damage":     90,
     "damage_type":   "割伤"
   ]),
   ([   "action":
"$N浑身放出"+HIR"红色的妖气"NOR"，接着手中的$w居然像"+HIG"植物"NOR"一样开出了大\n大小小颜色"+HIM"艳丽的花"NOR"！$N手一抖，那些"+HIM"花"NOR"立刻四散而开。漫天的"+HIM"花瓣"NOR"带\n着锐利的妖气袭向$n！\n",
     "dodge":     -20,
     "parry":      10,
     "damage":     50,
     "damage_type":   "无数刺伤"
   ]),
   ([   "action":
"$N大喝一声，将手中$w卷了起来拿在手里。$n正在奇怪，\n突然$N右手一扬，手里的$w长出很多"+HIG"尖利的刺"NOR"来，旋转着卷向$n！\n",
     "dodge":     -10,
     "parry":      -5,
     "damage":     80,
     "damage_type":   "割伤"
   ]),
   ([   "action":
"$N浑身放出"+HIR"红色的妖气"NOR"，四周突然出现了无数"+BLINK""+HIM"花瓣"NOR"，漂浮于$N的周围。\n接着，$N右手使了个巧力，$w上居然产生了强烈的气旋。\n果然，在那气旋之下，所有的"+BLINK""+HIM"花瓣"NOR"向着$n飞射而去，声势惊人！\n",
     "dodge":     -30,
     "parry":      10,
     "damage":     70,
     "damage_type":   "无数刺伤"
   ]),
   ([   "action":
"$N将手中$w一抛，而"+HIG"$w却像有灵性似的，围绕着$N不断旋转"NOR"。\n接着，$N飞身而上，朝着$n撞去。人还未到，$n的脸上\n已经被锐利的妖气划出了好几道伤痕。\n",
     "dodge":    -30,
     "parry":    -30,
     "damage":   150,
     "damage_type":   "无数割伤"
   ]),
   ([   "action":
"$N的妖气突然起了变化，"+HIG"手中$w突然变得笔直无比"NOR"。接着$N将\n手中$w向着$n投掷而去，同时手指一弹，一朵"+BLINK""+HIR"蔷薇"NOR"闪电般射向$n！\n",
     "dodge":     10,
     "parry":    -10,
     "damage":    90,
     "damage_type":   "刺伤加割伤"
   ]),
});

int valid_learn(object me)
{
   object ob;
   
   if((int)me->query_skill("yaohu-whip",1)>=282)
     return notify_fail("你在这种鞭法上的造诣已经无人能及，找谁学啊？\n");
   if( (int)me->query("combat_exp")<500000)
     return notify_fail("你对战斗的领悟还太少，不能灵活运用自己的妖气来到达攻击的效果。\n");
   if((int)me->query("daoxing")<200000)
     return notify_fail("就你这点修为，现在就想学？做梦！\n");
   if((int)me->query_skill("throwing",1)<100)
     return notify_fail("这种鞭法需要用到暗器技术，你还没达到标准。\n");
   if((int)me->query_skill("yaoli",1)<100) 
     return notify_fail("你的妖力不足以开始学习这种鞭法。\n");
   if((int)me->query_skill("whip",1)<100)
     return notify_fail("先把基础打好了再来吧！\n"); 
   if( (int)me->query("max_force") < 500 )
     return notify_fail("你的妖力不够，没有办法学习妖狐鞭法。\n");
   if((int)me->query_skill("unarmed",1)<100)
     return notify_fail("你的臂力还不够，再多练练吧！\n");
   if( !(ob = me->query_temp("weapon"))
   ||   (string)ob->query("skill_type") != "whip" )
     return notify_fail("你必须先找一把鞭子才能练鞭法。\n");

   return 1;
}

int valid_enable(string usage)
{
   return usage=="whip" || usage=="parry";
}

int practice_skill(object me)
{
   if((int)me->query_skill("yaohu-whip",1)>=282)
     return notify_fail("你在这种鞭法上的造诣已经无人能及，再怎么练也不会有进步了。\n");
   if( (int)me->query("kee") < 100
   ||   (int)me->query("force") < 100 )
     return notify_fail("你的妖力或气血不够，没有办法练习妖狐鞭法。\n");
   if( (int)me->query("combat_exp")<600000)
     return notify_fail("你对战斗的领悟还太少，怎么练啊？\n");
   if((int)me->query("daoxing")<300000)
     return notify_fail("就你这点修为，现在就想练？做梦！\n");
   if((int)me->query_skill("throwing",1)<100)
     return notify_fail("这种鞭法需要用到暗器技术，你还没达到标准。\n");
   if((int)me->query_skill("whip",1)<100)
     return notify_fail("先把基础打好了再来吧！\n"); 
   if( (int)me->query("max_force") < 500 )
     return notify_fail("你的妖力不够，没有办法练习妖狐鞭法。\n");
   if((int)me->query_skill("unarmed",1)<100)
     return notify_fail("你的臂力还不够，再多练练吧！\n");
   me->receive_damage("kee", 50);
   me->add("force", -10);
   write("你按着所学练了一遍妖狐鞭法。\n");
   return 1;
}
void skill_improved(object me)
{
   if((int)me->query_skill("yaohu-whip",1)==60)
{
   me->improve_skill("yaohu-whip",60000);
   me->improve_skill("yaohu-whip",60000);
   me->improve_skill("yaohu-whip",60000);
   me->improve_skill("yaohu-whip",60000);
   me->improve_skill("yaohu-whip",60000);
   tell_object (me, "你经过练习，突然有所领悟，鞭法猛地进步了！\n");
}
   if((int)me->query_skill("yaohu-whip",1)==120)
{
   me->improve_skill("yaohu-whip",60000);
   me->improve_skill("yaohu-whip",60000);
   me->improve_skill("yaohu-whip",60000);
   me->improve_skill("yaohu-whip",60000);
   me->improve_skill("yaohu-whip",60000);
   me->improve_skill("yaohu-whip",60000);
   me->improve_skill("yaohu-whip",60000);
   tell_object (me, "你经过练习，突然有所领悟，鞭法猛地进步了！\n");
}
   if((int)me->query_skill("yaohu-whip",1)==180)
{
   me->improve_skill("throwing",60000);
   me->improve_skill("throwing",60000);
   me->improve_skill("throwing",60000);
   me->improve_skill("throwing",60000);
   me->improve_skill("throwing",60000);
   me->improve_skill("throwing",60000);
   me->improve_skill("throwing",60000);
   me->improve_skill("throwing",60000);
   tell_object (me, "在练习中，你突然领悟到一些暗器使用的法门。\n");
}
   if((int)me->query_skill("yaohu-whip",1)==240)
{
   me->add("str",2);
   me->add("spi",2);
   me->add("int",5);
   me->add("per",2);
   me->add("combat_exp",200000);
   me->add("daoxing",100000);
   tell_object (me, "当你完成了这个阶段的练习时，突然觉得自己的身体有点不一样了。\n");
}
   if((int)me->query_skill("yaohu-whip",1)==280)
{
   me->improve_skill("yaohu-aoyi",10000);
   tell_object (me, "你突然领悟到了一些东西。\n");
   message("channel:rumor", HIM + "【谣言】某人：听说"+
     me->query("name")+"已经进入了鞭法的终极修炼境界！\n"NOR,users());
   message_vision(HIG "$N右手一绘，手中的鞭子划过一条优美的弧线，\n四周的东西还没被碰到，就留下了无数的划伤。\n" NOR,me);
   tell_object (me, "从现在起，你的妖狐鞭法就进入了最终的境界，\n以后的进步只能看你的运气了。\n");
}
   return;
}

string perform_action_file(string func)
{
        return CLASS_D("mojie") + "/yaohu-whip/" + func;
}