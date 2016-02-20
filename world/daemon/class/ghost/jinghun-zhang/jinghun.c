//By tianlin@mhxy for 2001.12.31制作
//此pfm绝对没有任何bug
//比如说对方死了后在地府连续死亡,还有像使出pfm离开此地,再用别的招,等等.....
//此pfm没有设上用招时所用的内力,因为这是6连级,不用设还能好用点,这不是什么大问题
//请不要更改作者名字谢谢!
//如果有人发现此招有bug来信告诉我tianlin-mhxy@163.com谢谢。

#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
        string str;//谣言的变量
        object weapon;
                
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail(HIY"你要对谁施展这一招"HIC"「"HIB"惊魂"HIR"夺魄"HIC"」"HIY"？\n"NOR);

        if(!me->is_fighting())
                return notify_fail(""HIC"「"HIB"惊魂"HIR"夺魄"HIC+HIY"」只能在战斗中使用！\n"NOR);

        if( (int)me->query_temp("jinghun") ) 
        return notify_fail(HIW"你这一绝招还没有完全用完,不能再使用。\n"NOR);

        if((int)me->query("max_force") < 500 )
                return notify_fail(YEL"你的内力火候还不行！\n"NOR);

        if((int)me->query("force") < 500 )
 	         return notify_fail(CYN"你的内力不足！\n"NOR);

        if((int)me->query("kee") < 500 )
                return notify_fail(HIR"你的气血不足，没法子施用外功！\n"NOR);

        if((int)me->query("sen") < 500 )
                return notify_fail(HIC"你的精神不足，没法子施用外功！\n"NOR);

        if((int)me->query_skill("jinghun-zhang", 1) < 100)
                return notify_fail("你的惊魂掌级别还不够，使用不出来惊魂夺魄的奥妙之处！\n");
	 if(me->query_temp("last_jinghun")+8>time())
	         return notify_fail(HIB"惊魂"HIR"夺魄"NOR+CYN"乃绝世武功,多使就不灵了。\n"NOR);

        me->delete("env/brief_message");
        target->delete("env/brief_message");

	 if (! present(target,environment(me))) return 1;
        message_vision(HBBLU+HIR"\n$N左手虚晃，右手虚中有实的，向$n的下三路照去，$N击向$n双腿！\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        message_vision(HBRED+HIW"\n$N双掌微分，左手暴长出一掌一掌又一掌，$n一声惨叫打向$n的百慧穴！\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                     if (target->query("eff_kee")<0 || !living(target))  
                       {str=NOR+CYN+target->name()+HIM"被"NOR+YEL+me->name()+HIM"用冥界绝学"HIC"“"HIR"惊魂"HIB"夺魄"HIC"”"HIM"给杀死了,据说"NOR+CYN+target->name()+HIM"到了阴间还恐惧这一招！";
	                message("channel:rumor",HIM"【谣言】某人："+str+"\n"NOR,users());
	               }
        me->set_temp("jinghun", 1);
        call_out("remove_jinghun",3,me);
        me->start_busy(1);
        target->start_busy(1);
        me->set_temp("no_move",1);
        call_out("remove_no_move",3,me);
        remove_call_out("perform");
        call_out("perform2", 3, me, target);    
        return 1;
}

int perform2(object me, object target)
{
        string str;//谣言的变量
        object weapon;
        if(!living(target) || !target || environment(me)->query("no_fight")
           ){
           message_vision(CYN"$N的对手已经不能再战斗了,你狠不下心来再使用绝招!\n"NOR,me);
                return 1;
                }
	if( environment(target) != environment(me) ) {
		tell_object(me, BLINK+HIR"你的对手已经离开这里了。\n"NOR);
		return 1;
	}
        if( (int)me->query("force", 1) < 300 )
                return notify_fail("你发现自己内力已经不够用的了,不能再作攻击！\n");     
        message_vision(HBBLU+HIY"\n$N右手在$n头部划过，随后一招张牙舞爪犹如厉鬼上身，向$n面部抓去！\n"NOR,me,target);
        message_vision(BLINK+HIC"\n\t\t\t\t惊\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        message_vision(HBRED+HIC"\n$N将双手深深插入脚下的土地，双手猛的拔除，张口一吹，一股暴尘劲土向$n迎面打来！\n"NOR,me,target);
        message_vision(BLINK+HIY"\n\t\t\t\t魂\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        message_vision(HBBLU+HIC"\n$N身子动摇西慌，随即跨出数步，$N的双手忽掌忽爪抓向$n的腰部！\n"NOR,me,target);
        message_vision(BLINK+HIR"\n\t\t\t\t夺\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        message_vision(HBBLU+HIR"\n$N右手在$n右半身划过，随即左手向$n拍来，$n躲闪不即眼看就要中招，$N随后就是一击！\n"NOR,me,target);
        message_vision(BLINK+HIB"\n\t\t\t\t魄\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                     if (target->query("eff_kee")<0 || !living(target))  
                       {str=NOR+CYN+target->name()+HIM"被"NOR+YEL+me->name()+HIM"用冥界绝学"HIC"“"HIR"惊魂"HIB"夺魄"HIC"”"HIM"给杀死了,据说"NOR+CYN+target->name()+HIM"到了阴间还恐惧这一招！";
	                message("channel:rumor",HIM"【谣言】某人："+str+"\n"NOR,users());
	               }
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
                me->start_busy(1+random(2));
	         me->receive_damage("kee", 50);
	         me->receive_damage("sen", 50);
                target->start_busy(1+random(2));
                me->delete_temp("jinghun");
                me->set_temp("last_jinghun",time());
        return 1;
}
void remove_no_move(object me) {
  if (me) me->delete_temp("no_move");
}
void remove_jinghun(object me) {
  if (me) me->delete_temp("jinghun");
}

