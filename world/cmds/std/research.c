#include <skill.h>;
inherit F_CLEAN_UP;
void create() { seteuid(getuid()); }
int main(object me, string arg)
{
        int sen_cost;  
int my_skill;
        int pot,i;
int amount,qlearned,qskill;
        int bimprove=1;
   
        if( me->is_fighting() )
 return notify_fail("在战斗中搞研究？\n");
   
        if(!arg) return notify_fail("指令格式: research <技能>\n");
   
        if( !(int)my_skill=me->query_skill(arg,1) )
             
return notify_fail("你对此项技能一无所知，如何搞研究？\n");
   
        if(my_skill<180)
return notify_fail("你这门武功这么差劲，搞什么研究！\n");
   
        if( !SKILL_D(arg)->valid_learn(me) ) return 0;


     pot = (int)me->query("potential") - (int) me->query("learned_points");
   
 if(pot>50)pot=50;
if(pot<=0)return notify_fail("你的潜能已经发挥到极限了，没有办法再成长了。\n");
   
 sen_cost = 150*pot/(int)me->query_int();
        if((int)me->query("sen") < sen_cost)
{
        me->set("sen",0);
return notify_fail("你现在太累了，结果什麽也没有研究出来。\n");
        }

if( (string)SKILL_D(arg)->type()=="martial"
&&my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp"))
return notify_fail("也许是武学不够，结果什麽也没有研究出来。\n");

amount=0;
for(i=0;i<pot;i++)
        amount += random(me->query_int())+1;
        amount +=amount*my_skill/200;
        qlearned=me->query_learned()[arg]+amount;
        qskill=(my_skill+1)*(my_skill+1);
        me->add("learned_points",2*pot);
me->receive_damage("sen", sen_cost );
       if(qlearned>2*qskill&&random(me->query_int())>32)bimprove=0;
       if(qlearned>2*qskill && me->query_int()<34 && !random(40))bimprove=0;
        me->improve_skill(arg, amount,bimprove);
write("你对"+to_chinese(arg)+"作了一番彻底的研究！\n");
return 1;
}
int help(object me)
{
   write( @HELP
指令格式: research <技能>

这一指令让你每次用100点潜能对某项技能作深入的研究。
HELP
);
   return 1;
}



