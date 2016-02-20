#include <ansi.h>
#include <skill.h>

inherit SKILL;


string *strong_msg= ({
HIR"$N双手圆转，每一招都竟然含着太极式的阴阳变化，精微奥妙!!\n$N以慢打快、以静制动,已是绝顶武功！\n"NOR,
HIB"$N轻轻一笑，左臂伸出，左右连划了九个圆圈!!\n$N默用"NOR+HIR"第一神功"NOR+HIB",虚而又实，一旦被其套住即送即拉！！\n"NOR,
HIY"$N右肩斜闪，左指或点或画,无使断绝,却是刚猛，刺空之声破体而来！\n"NOR,
HIG"\n突然,$N乘势向左斜出半步,相距只是电光般一闪!\n"NOR,
HIM"\n$N真气蓬勃,剑气忽缓而不疏，剑意有余而不尽,真是奥妙无穷！\n"NOR,
WHT"\n突然,$N俯身斜倚，身行连动,越奔越快，真如电掣风行！\n"NOR,
});
string *xue_name = ({ 
"劳宫穴","膻中穴","曲池穴","关元穴","曲骨穴","中极穴","承浆穴","天突穴","百会穴",
"幽门穴","章门穴","大横穴","紫宫穴","冷渊穴","天井穴","极泉穴","清灵穴","至阳穴",}); 


string *hit_msg= ({
HIR"\n$P只感觉一股"NOR+HIB"寒阴真气"NOR+HIR"扑面而来,不由大叫一声,全身却如同坠入冰柱!\n"NOR,
HIC"$N大喝一声"NOR+HIB"“好一招六脉神剑”"NOR+HIR"！\n"NOR,
HIW"\n$P凝神定气，却见其越奔越快，突然感觉背后"NOR+HIB"六股指风"NOR+HIW"分别指向自己经脉六穴"NOR+HIR"!!\n"NOR,
});
string *dodge_msg = ({
"$n足下一个踉跄，乘势向左斜出半步，恰符合了凌波微步中"+HIM"「忽焉纵体」"NOR+"的步子，闪了开来。\n",
"$n使出"+HIR"「流风回雪」"NOR+"歪歪斜斜退了几步，似乎不成章法，却在间不容缓的空隙中躲过了$N的攻势。\n",
"$n身形闪处，突然转向，使出了"+WHT"「神光离合」"NOR+"，$N加紧攻势，竟无法碰到$n一片衣角。\n",
"$n大喝一声，使出"+GRN"「乍阴还阳」"NOR+"，左足向右踏出，不料踏实之时，身子已在西北角上。\n",
"$n一式"+HIC"「以遨以嬉」"NOR+"，瞻之在前，忽焉在后，$N招式的落点和$n身子间总有厘毫之差。\n",
"$N的招式明明可以把$n围住，不知怎的，$n一式"+HIG"「轻云蔽月」"NOR+"，又如鬼魅般的跨出了圈外\n",
"$n一式"+HIW"「体迅飞枭」"NOR+"，似乎自管自地踏步，毫不理会，每一步都踏在别人意想不到的所在。\n",
"$n一式"+HIR"「飘忽若神」"NOR+"，侧身斜进，抢步“既济”，立闪“未济”，闪得几闪，已欺到$N的身后。\n",
});

string *sword_msg = ({
"$N举剑狂挥，迅速无比地点向$n的$l，却令人看不出其所用是什么招式",
"$N运剑如风，剑光霍霍中反攻$n的$l，尝试逼$n自守，剑招似是「伏魔剑」的「龙吞式」",
"只见$N不退反进，身如飘风，诡异地一式「天柱云气」，动向无定不可捉摸地指向$n的$l",
"$N以攻为守，以进为退，凝神运气向$n猛攻快打地挥出方位大异的泰山「快活三」三剑",
"$N突然一剑点向$n的$l，虽一剑却暗藏无数后着，$n手足无措，不知如何是好",
"$N将$w随手一摆，但见$n自己向$w撞将上来，神剑之威，实人所难测",
"$N剑招突变，使出衡山的「一剑落九雁」，削向$n的$l，怎知剑到中途，突然转向，大出$n意料之外",
"$N满场游走，东刺一剑，西刺一剑，令$n莫明其妙，分不出$N剑法的虚实",
"$N随手一剑指向$n，落点正是$n的破绽所在，端的是神妙无伦，不可思议",
"$n攻向$N的$l，$N不退反进，使出恒山剑招「绵里藏针」，森森剑气充溢四周",
"$N奇诡地向$n挥出「泉鸣芙蓉」、「鹤翔紫盖」、「石廪书声」、「天柱云气」及「雁回祝融」衡山五神剑",
"$N剑随身转，续而刺出十九剑，竟然是华山「玉女十九剑」，但奇的是这十九剑便如一招，手法之快，直是匪夷所思",
"$N突然使出青城派松风剑法的「鸿飞冥冥」，可是方位却有所偏差，$w对着$n一绞，企图突破$n的攻势",
"$N举起$w运使「太极剑」剑意，划出大大小小无数个圆圈，无穷无尽源源不绝地缠向$n",
"$N含笑抱剑，气势庄严，$w轻挥，尽融「达摩剑」为一式，闲舒地刺向$n",
"$n窥准$N一招华山剑法「有凤来仪」的趋势，准备进行反击，却见$N突然虚步提腰，使出酷似武当「蜻蜓点水」的一招",
"但见$N挺身而上，$w一旋，一招仿佛泰山剑法的「来鹤清泉」直刺$n的$l",
"$N剑意突焕气象森严，便似千军万马奔驰而来，长枪大戟，黄沙千里，尽括嵩山剑势击向$n",
"$N手中$w越转越快，使的居然是衡山的「百变千幻云雾十三式」，剑式有如云卷雾涌，旁观者不由得目为之眩",
"$N剑势忽缓而不疏，剑意有余而不尽，化恒山剑法为一剑，向$n慢慢推去",
"$N突然运剑如狂，一手关外的「乱披风剑法」，猛然向$n周身乱刺乱削",
"$N脸上突现笑容，似乎已看破$n的武功招式，胸有成竹地一剑刺向$n的$l",
"$N剑挟刀势，大开大阖地乱砍一通，但招招皆击在$n攻势的破绽，$n不得不守",
"却见$N身随剑走，左边一拐，右边一弯，剑招也是越转越加狠辣，竟化「泰山十八盘」为一剑攻向$n",
"$N反手横剑刺向$n的$l，这似有招似无招的一剑，威力却是奇大，$n难以看清剑招来势",
"$N神色凝重，$w上劈下切左右横扫，挟雷霆万钧之势逼往$n，「伏魔剑」剑意表露无遗",
"$N奇诡地向$n挥出「泉鸣芙蓉」、「鹤翔紫盖」、「石廪书声」、「天柱云气」及「雁回祝融」衡山五神剑",
"$N剑随身转，续而刺出十九剑，竟然是华山「玉女十九剑」，但奇的是这十九剑便如一招，手法之快，直是匪夷所思",
"$N剑法突变，剑势伸缩不定，奔腾矫夭，逆使嵩山剑法的「天外玉龙」回攻$n",
});
string *unarmed_msg = ({
HIC"$N手臂陡然一提，对$n发起攻击，手掌离$n不到一尺，立即变掌为指，使出「少泽剑」"NOR,
HIC"$N双掌自外向里划了一个圈，双掌托在胸前，伸出右小指，一招「少冲剑」"NOR,
HIC"$N长笑一声，右手硬生生缩回，左手横斩而至，俯身斜倚，无名指弹出，一式「关冲剑」"NOR,
HIC"$N食指连动，快速无比，格开对方来势，变招奇速，如毒蛇出洞，疾从袖底穿出，大喝一声，使出「商阳剑」"NOR,
CYN"两指之间，相距只是电光般一闪，$N一翻掌，身向右移，奋起神威，右手斗然探出，中指一竖，一招「中冲剑」"NOR,
HIW"忽见$N左手小指一伸，一条气流从$P少冲穴中激射而出，指向身前$n！"NOR,
WHT"$N左斜行三步，左手小指的内力自左向右的斜攻过去，直插$n$l,在手掌离$n不到一尺之处，立即变掌为指！！"NOR,
HIY"$N长笑一声，俯身斜倚，无名指弹出，指尖已对准$n的$l发出了一缕强烈的劲风！"NOR,
HIY"$N无名指一挥，拙滞古朴的关冲剑气直射而出，端端正正地刺向$n！"NOR,
HIY"$N变招奇速，右手食指如毒蛇出洞，疾从袖底穿出，大喝一声，双手幻出无数指影！"NOR,
YEL"$N拇指一屈，食指点出，变成了「商阳剑法」，一缕剑气向$n刺出！"NOR,
YEL"$N食指连动，「商阳剑法」一剑又一剑的刺出，其轻灵迅速，快速无比！"NOR,
YEL"$N以食指运那无形剑气，却不过是手指在数寸范围内转动，对着$n一点一戳！"NOR,
HIB"$N将中指向上一炭，中冲剑气拔地而起，接着$P将手指向下一划，剑气如利刀般砍向$n！"NOR,
HIB"电光火石之间，$N一翻掌，身向右移，奋起神威，右手斗然探出，中指向$n一竖！"NOR,
HIB"$N掌托于胸前，伸出右小指，一招「少冲剑」缓缓地点向$n的周身大穴，弹指无声！"NOR,
BLU"$N小指一弹，使一招‘分花拂柳’，剑势如同柳絮一般，飘而不乱！"NOR,
BLU"$N一招「少冲剑」，剑气回转，竟从左侧绕了过来，点向$n的$l！"NOR,
BLU"$N右手小指一挥，一招「少冲剑」点点刺刺，宛如雕花刺画一般！"NOR,
HIM"$N大拇指一按，嗤嗤两指，劲道使得甚巧，初缓后急，剑气如怒潮般汹涌而至！"NOR,
HIW"$N大拇指连挥，「少商剑气」便如是一幅泼墨山水相似，纵横倚斜，寥寥数笔，却是剑路雄劲！"NOR,
WHT"$N的「少商剑法」大开大阖，气派宏伟，每一剑刺出，都有石破天惊、风雨大至之势！"NOR,
});

mapping query_action(object me, object weapon)
{
      int i, j, damage;
      i = random(100)+100;
      damage = i;
      if (!me) me = this_object();
 if (!weapon) {                    
     if (random(me->query_skill("NO.1_skill",1)) > 200 &&
              me->query_skill("force") > 160 &&
            me->query("max_force") > 3000 && 
               me->query("force") > 3000 ) 
       {
        return ([
//                 "action":unarmed_msg[random(sizeof(unarmed_msg))]+BLU"\n却见$n浑身一颤，只觉得"NOR+HIR+xue_name[random(sizeof(xue_name))]+NOR+BLU"如同针扎，真气外泻,$n立即神智迷糊..!!"NOR,
                 "action":strong_msg[random(sizeof(strong_msg))]+"\n"+unarmed_msg[random(sizeof(unarmed_msg))],
                "damage":damage*(2+random(2)),
            "damage_type": random(10)?"刺伤":"内伤", 
            "weapon": random(3)?HIW"六脉剑气"NOR:HIY"破体无形指气"NOR, 
                "dodge": -50-random(10),
                "force": i*2,
                ]);
       }
      return ([
             "action":unarmed_msg[random(sizeof(unarmed_msg))],
             "damage":damage*random(2),
            "damage_type": random(10)?"刺伤":"内伤", 
            "weapon": random(3)?HIR"一缕指风"NOR:HIB"手指"NOR, 
                "dodge": -50-random(10),
             "force": i,
             ]);
        }
     if (random(me->query_skill("NO.1_skill",1)) > 200 &&
              me->query_skill("force") > 160 &&
            me->query("max_force") > 3000 && 
               me->query("force") > 3000 ) 
       {
        return ([
//                 "action":sword_msg[random(sizeof(sword_msg))]+HIC"\n紧接着，$N朗声一笑，弹剑屈臂,$n"NOR+RED+xue_name[random(sizeof(xue_name))]+NOR+HIC"突然如同针扎，身心大乱!"NOR,
                 "action":sword_msg[random(sizeof(sword_msg))],
                "damage":damage*(2+random(2)),
                "damage_type": "刺伤",
                "dodge": -50-random(10),
                "force": i*2,
                ]);
        }
      return ([
             "action":sword_msg[random(sizeof(sword_msg))],
             "damage":damage*random(2),
             "damage_type": "刺伤",
                "dodge": -50-random(10),
             "force": i,
             ]);
}


int valid_learn(object me)
{
        if ((int)me->query("max_force") < 100)
                return notify_fail("你的内力不够怎么练剑。\n");
        if ((int)me->query("force") < 100)
                return notify_fail("你的内力不够怎么练剑。\n");
if ( ! wizardp(me))

        return notify_fail("第一神功只能由巫师学习。\n");
}
int valid_enable(string usage) 
{
return (usage == "sword") || (usage == "parry") || (usage == "unarmed") || (usage == "force") || (usage == "dodge") || (usage == "spells");
}
string perform_action_file(string action)
{
        return "/u/yxm/skill/fly-king/perform/" + action;
}
string exert_function_file(string func)
{
         return "/u/yxm/skill/fly-king/exert/" + func;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
    object weapon, weapon1;     
    string name,hitmsg;
    name = xue_name[random(sizeof(xue_name))];
    hitmsg = hit_msg[random(sizeof(hit_msg))];
    weapon = me->query_temp("weapon");
    weapon1= victim->query_temp("weapon");
       if( random(me->query_skill("NO.1_skill")) > 100) {
                victim->apply_condition("cold_poison", random(2) + 2 +
                        victim->query_condition("clod_poison"));
        }
    if(weapon1 && me->query_skill("NO.1_skill", 1) > 150 
       && me->query("max_force") > 1200 && me->query("force") > 1000 
       && me->query("combat_exp") > random(victim->query("combat_exp"))){
      message_vision(HIR"\n$N左手剑诀斜引,平搭在$n"+weapon1->name()+HIM"背脊上,劲力传出,"+weapon1->name()+MAG"登时一沉！\n"NOR, me,victim);
      if(random(me->query("str")) > victim->query("str")/2){    
      message_vision(HIR"$N招式渐见涩滞，只觉得手中"+weapon1->name()+HIR"倒似不断的在增加重量，一个把持不定，脱手飞出！\n"NOR, victim);
           weapon1->unequip();
           me->add("force",1000);
           victim->start_busy(3);
           weapon1->move(environment(victim));
}
      else{
           message_vision(HIY"$N一招使出，真力运得不足，被带着连转几个圈子，手中"+weapon1->name()+HIY"一震，险些脱手！\n"NOR, victim);
           me->add("force",1000);
           victim->start_busy(2);
           }
    }
    if(!weapon1 && random(me->query_skill("NO.1_skill", 1))> 100 
       && me->query("max_force") > 1200 && me->query("force") > 1000 
       && me->query("combat_exp") > random(victim->query("combat_exp"))){
//           message_vision(HIY"$N真气越来越顺，剑气忽缓而不疏，剑意有余而不尽,真是奥妙无穷!!\n"NOR, me);
//           message_vision(HIB"$N越斗越是心惊，许多厉害武功却发挥不出来"NOR,victim);
           victim->start_busy(3);
           me->add("force",1000);
         victim->receive_damage("kee", me->query_skill("NO.1_skill")/3+damage_bonus/3);  
         victim->receive_wound("kee", me->query_skill("NO.1_skill")/4+damage_bonus/4);  
                           if (victim->query("force") <=(damage_bonus/2+30))
                victim->set("force",0);
                else
                victim->add("force",-damage_bonus/2+30);  
                               }
}

string query_dodge_msg()
{
        return dodge_msg[random(sizeof(dodge_msg))];
}
string cast_spell_file(string spell)
{
        return "/u/yxm/skill/fly-king/cast/" + spell;
}
