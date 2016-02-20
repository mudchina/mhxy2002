#include <ansi.h> 

inherit SSERVER;

int perform(object me, object target)
{
object weapon;
int dqi,ap,dp,dd1,dd2,dd3,dd4,dd5,dd6;
int dforce,dmana,dsen,damage,aa,a,dam;
      string str;
if( !target ) target = offensive_target(me);

if( !target
|| !target->is_character()
|| target->is_corpse() || target==me)
return notify_fail("你要对谁施展这一招"HIR"「"HIC"梦里寻他"HIR"」"NOR"？\n"); 

if(!me->is_fighting())
return notify_fail("「梦里寻他」只能在战斗中使用！\n");
                if(me->query("family/family_name")!="盘丝洞")
return notify_fail("你根本就入不了梦！\n");

if(environment(target)!= environment(me))
return notify_fail("你攻击的人不在这里！\n");
 if((int)me->query("force") < 600 )
return notify_fail("你的内力不够！\n");
if((int)me->query("mana") < 1000 )
return notify_fail("你的法力不够！\n");
if((int)me->query("kee") < 600 )
return notify_fail("你的气血不足，没法子施用外功！\n");
if((int)me->query("sen") < 600 )
return notify_fail("你的精神不佳，没法子施用外功！\n");
if((int)me->query_skill("pansi-dafa", 1) < 150)
return notify_fail("你的盘丝大法级别还不够，使用这一招会有困难！\n");
if((int)me->query_skill("lanhua-shou", 1) < 60)
return notify_fail("你的兰花手级别还不够，使用这一招会有困难！\n");
if((int)me->query_skill("chixin-jian", 1) < 60)
return notify_fail("你的痴心情长剑级别还不够，使用这一招会有困难！\n");
if((int)me->query_skill("yueying-wubu", 1) < 80)
return notify_fail("你的月影舞步级别还不够，使用这一招会有困难！\n");
if((int)me->query_skill("qingxia-jian", 1) < 150)
return notify_fail("你的青霞剑级别还不够，使用这一招会有困难！\n");
if((int)me->query_skill("jiuyin-xinjing", 1) < 130)
return notify_fail("你的九阴心经级别还不够，使用这一招会有困难！\n");
a=random(5)+1;
weapon=me->query_temp("weapon");
me->delete("env/brief_message");
message_vision(BLU"\n$N思念起心上人，进入了忘我的境界，慢慢进入了梦乡。\n"NOR+
WHT"$N人在梦中，攻势却丝毫未减，娇嗔一声飞上天空。”\n "NOR, me);

dd1=me->query_skill("chixin-jian", 1);
dd2=me->query_skill("jiuyin-xinjing", 1);
dd3=me->query_skill("qingxia-jian", 1);
dd4=me->query_skill("lanhua-shou", 1);
dd5=me->query_skill("yueying-wubu", 1);
dd6=me->query_skill("pansi-dafa", 1);
ap = me->query("combat_exp");
dp = target->query("combat_exp");
dqi= me->query("kee");
dsen= me->query("sen");
dmana= me->query("mana");
a=7;
// a=random(a)+1;
// aa=0;
if(random(ap+dp) > dp )
{
if ( dd1 > 5 ) {
message_vision(HIG"\n手中的宝剑渐渐的发出耀眼的亮光\n"+
HIC"宝剑脱手而出，看似柔情似水，却暗藏杀机万千！\n"NOR,target,me);
(int)damage=random(dd1*4)+random(dd6/2*8)+random(me->query("kee")/20);
if(damage<1) damage=dd2+random(dd2);
//target->receive_damage("sen", damage, me);
//COMBAT_D->report_sen_status(target);
target->receive_wound("kee", damage, me);
COMBAT_D->report_status(target);
} a = a +1;}else { aa = 5;} if ( a > 6 ) {
message_vision(HIM"\n$N刚想喘息一下，不料眼前又是一亮\n"+
HIR"$N只觉得一阵巨痛，胸口再次中剑！\n"NOR,target,me);
(int)damage=random(dd3*4)+random(dd6/2*8)+random(me->query("kee")/20);
if(damage<1) damage=dd2+random(dd2);
     me->add("force",-400);
     me->add("mana",-400);
//target->receive_damage("sen", damage, me);
//COMBAT_D->report_sen_status(target);
target->receive_wound("kee", damage, me);
COMBAT_D->report_status(target);
    if (target->query("kee")<0 || (!living(target) && target->query("kee")<0))
{str=target->name()+"被"+me->name()+"用盘丝杀手裥"HIC"「梦里寻他」"NOR+HIM"刺穿心脏，一命呜呼了！";
 message("channel:rumor",HIM"【谣言】某人："+str+"\n"NOR,users());
                       }
                }
                me->start_busy(1+random(2));
        return 1;
}
