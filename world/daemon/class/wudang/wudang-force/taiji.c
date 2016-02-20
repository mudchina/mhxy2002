// 太极拳PFM
// snowman
#include <ansi.h>

int check_fight(object me);
int remove_effect(object me);
int exert(object me)
{
        if( !me->is_fighting() || !living(me))
                return notify_fail("「太极」只能在战斗中的使用。\n");

        if(objectp(me->query_temp("weapon")) )
                return notify_fail("你必须空手才能运用「太极」！\n");
        if(me->query_temp("taiji"))        
                return notify_fail("「太极」之意绵绵不绝，你已经在发挥它的威力了。\n");  
        if((int)me->query_skill("taiji-quan", 1) < 100 )
                return notify_fail("你的太极拳不够娴熟，还不能领会「太极」之诀窍。\n");

        if( (int)me->query("force", 1) < 1200 )
                return notify_fail("你的内力修为太弱，发挥不出「太极」的优势。\n");                
        if(userp(me) && (int)me->query_skill("wudang-force", 1) < 100 )
                return notify_fail("你的太极神功等级不够高，发挥不出「太极」的威力。\n");

        if(userp(me) && me->query_skill_mapped("force") != "wudang-force")
                return notify_fail("你的内功不对，根本不能发挥出「太极」的优势。\n");                                                                                     
        if (userp(me) && me->query_skill_mapped("parry") != "taiji-quan")
                return notify_fail("太极拳的「太极」诀窍必须在激发招架的情况下才能使用。\n");
        message_vision("$N缓缓移动，双手下垂，手背向外，手指微舒，两足分开平行，接着两臂慢慢提起至胸前，左臂半环，
掌与面对成阴掌，右掌翻过成阳掌，但见$P双手圆转，每一招都含着太极式的阴阳变化，精微奥妙！\n",me);
        tell_object(me, CYN"\n你默运神功，双手自然挥动，与万物合一，将太极拳"RED"「拳意」"CYN"发挥得淋漓尽致！\n\n"NOR);
        me->start_busy(1);
        me->set_temp("taiji", 1);
        me->add_temp("apply/parry", me->query_skill("taiji-quan", 1)/3);
        me->add_temp("apply/dodge", me->query_skill("taiji-quan", 1)/3);
        me->add_temp("apply/attack", me->query_skill("taiji-quan", 1)/3);
        me->add_temp("apply/defense", me->query_skill("taiji-quan", 1)/3);
        me->add_temp("apply/armor", me->query_skill("taiji-quan", 1)/3);

        check_fight(me);
        return 1;
}

int check_fight(object me)
{
        object *enemy, target;
        int sz;        

        if (!me || !me->query_temp("taiji")) return 0;

        if(me->is_ghost() || !living(me)){
           me->add_temp("apply/parry", -me->query_skill("taiji-quan", 1)/3);
           me->add_temp("apply/dodge", -me->query_skill("taiji-quan", 1)/3);
           me->add_temp("apply/attack", -me->query_skill("taiji-quan", 1)/3);
           me->add_temp("apply/defense", -me->query_skill("taiji-quan", 1)/3);
           me->add_temp("apply/armor", -me->query_skill("taiji-quan", 1)/3);           
           
           me->delete_temp("taiji");
           return 0;
           }        
        
        enemy = me->query_enemy();
        if( !enemy || !arrayp(enemy) ) remove_effect(me);
        sz = sizeof(enemy);
        if( sz > 4 ) sz = 4;
        if( sz > 0 ) target = enemy[random(sz)];
        else remove_effect(me);

        if(!me->is_fighting()){
                if(!me->query_temp("stopped")){
                    me->set_temp("stopped", 1);
                    call_out("check_fight", 2, me);
                    }
                else remove_effect(me);
                }
        else if (userp(me) && (me->query_skill_mapped("unarmed") != "taiji-quan" 
                || me->query_skill_mapped("parry") != "taiji-quan"
                || me->query_temp("weapon"))){
                  message_vision(HIY"$N使完一式太极拳，突然变招，竟然是完全不同的招数！\n"NOR,me);
                  target->start_busy(3);
                  me->start_busy(1);
                  me->add_temp("apply/parry", -me->query_skill("taiji-quan", 1)/3);
           me->add_temp("apply/dodge", -me->query_skill("taiji-quan", 1)/3);
           me->add_temp("apply/attack", -me->query_skill("taiji-quan", 1)/3);
           me->add_temp("apply/defense", -me->query_skill("taiji-quan", 1)/3);
           me->add_temp("apply/armor", -me->query_skill("taiji-quan", 1)/3);           

           me->delete_temp("taiji");
                  }   
       else if( me->query("force") <= 10 || !target || me->query("force_factor")) remove_effect(me);
       else call_out("check_fight", 1, me);
       return 1;
}       

int remove_effect(object me)
{
   string msg;
   msg = "/daemon/class/wudang/taiji-quan"->query_skill_name(me->query_skill("taiji-quan", 1));
   message_vision(CYN "\n$N使到"+msg+"而合太极，双手抱了个太极式的圆圈，神定气闲的站在当地。\n\n"NOR, me);
   me->add_temp("apply/parry", -me->query_skill("taiji-quan", 1)/3);
   me->add_temp("apply/dodge", -me->query_skill("taiji-quan", 1)/3);
   me->add_temp("apply/attack", -me->query_skill("taiji-quan", 1)/3);
           me->add_temp("apply/defense", -me->query_skill("taiji-quan", 1)/3);
           me->add_temp("apply/armor", -me->query_skill("taiji-quan", 1)/3);           

   me->delete_temp("taiji");
   me->delete_temp("stopped");
   remove_call_out("check_fight"); 
   return 0;
}
