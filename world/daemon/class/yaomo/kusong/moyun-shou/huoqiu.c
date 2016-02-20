//by tianlin 2001.7.5修改
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
#include "/u/tianlin/eff_msg.h";
int check_pfm(object me, object target, object ob);
int perform(object me, object target)
{
      object ob, tar;
if( !target ) target = offensive_target(me);
if( !target
||      !target->is_character()
||      !me->is_fighting(target) )
return notify_fail(""HIR"「火球」"NOR"攻击只能对战斗中的对手使用。\n");

        if(me->query("family/family_name") != "火云洞" )
                return notify_fail("你是哪儿偷学来的武功，也想使用！\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("你必须空手才能使用「火球」！\n"); 

message_vision(HIR"\n$N厉声大喝，掌力加盛，火焰中突然生出一个斗大的"RED"火球"HIR"，在空中骨碌碌的迅速转动！\n\n"NOR,me);
me->start_busy(1);
me->set_temp("pfm_chousui", 1);
if(random(me->query_kar()) > 15)
      check_pfm(me, target, ob);
else call_out("check_pfm", 6, me, target, ob);
       return 1;
}
int check_armor(object target)
{
object *inv;
int i, j;
inv = all_inventory(target);
j=0;
for(i=0; i<sizeof(inv); i++)
if( (string)inv[i]->query("equipped")=="worn" ) j++;
return j;
}

int check_pfm(object me, object target, object ob)
{
string msg, *limbs;
int i, force, ap, dp, damage, p;
object *inv;
if(!me) return 0;
i = (int)me->query_skill("moyun-shou", 1);
force = (int)me->query("force");
damage = (i+me->query("force_factor"))*2;
me->delete_temp("pfm_chousui");
me->start_busy(1);

        if(!living(me) || me->is_ghost()) return 1;
        if( me->query_skill("moyun-shou", 1) < 150 ){
                tell_object(me, "你发现自己的手法还不够娴熟，无法使用「火球」进行攻击。\n");
                return 1;
                }
        if (me->query_skill_mapped("unarmed") != "moyun-shou"
                          ){
                tell_object(me,"你必须用摩云手才能使用「火球」进行攻击。\n");
                return 1;
                }
        if( (int)me->query("max_force") < 1800) {
                tell_object(me,"你发现自己内力实在太弱，无法驱动「火墙」进行攻击。\n");
                return 1;
                }
        if(me->query("force") < 1000){
                tell_object(me,"你发现自己现在真气实在太弱，举不起「火墙」进行攻击。\n");       
                return 1;
                }
        if(!living(target) || !target || environment(me)->query("no_fight")
           ){
           message_vision(HIY"$N衣袖再拂，将抬起的"HIR"火球"HIY"压回火焰之中。\n"NOR,me);
                return 1;
                }
        me->add("force", -1000);
ap = me->query("combat_exp")/1000 * i * me->query_str();
dp = target->query("combat_exp")/1000 * target->query_skill("parry",1) /20* target->query_con();
if (ap < 1) ap = 1;
if (dp < 1) dp = 1;

message_vision(HIW"\n此时$N脸上已无半点血色，一口口鲜血不住向"RED"火球"WHT"中吐去 !!\n"NOR,me);
msg = HIR"\n火势一盛，嗤嗤两声轻响，爆出几朵火花，"HIW"火球"HIR"陡然变大向$n疾冲过来！\n"NOR;

if(ap > random(dp/5)){
inv = all_inventory(target);
               if(check_armor(target) >= 1){     
               if(me->query("force") > target->query("force")*2){ 
               if(me->query_str() > random(target->query_str())){
me->start_busy(3);
target->start_busy(2);
msg += HIY"猛烈间火球温度飙升，火花迸射，炸开了$p的护具！\n" NOR;
for(i=0; i<sizeof(inv); i++)
if((string)inv[i]->query("equipped")=="worn" && !inv[i]->query("unique")){
inv[i]->unequip();
inv[i]->move(environment(target));
inv[i]->set("name", "粉碎的" + inv[i]->query("name"));
inv[i]->delete("value");
inv[i]->set("armor_prop", 0);
}
target->reset_action();
damage = damage * 3;
if (damage > 4000) damage = 4000;
damage = damage - target->query_temp("apply/armor");
target->receive_damage("kee", damage, me);   
target->receive_wound("kee", damage/4, me);  
p = (int)target->query("kee")*100/(int)target->query("max_kee");
msg += damage_msg(damage, "砸伤");
msg += "( $n"+eff_status_msg(p)+" )\n";
me->start_busy(2);
target->start_busy(1);    
                             }
                             else {
me->start_busy(3);
target->start_busy(3);
msg += HIY"只见火球猛然升温，火花四溅，热力直透$p的护具！\n" NOR;
for(i=0; i<sizeof(inv); i++)
if((string)inv[i]->query("equipped")=="worn" && !inv[i]->query("unique")){
inv[i]->set("name", "碎裂的" + inv[i]->query("name"));
inv[i]->set("value", 49);
if(inv[i]->query("armor_prop/armor"))
inv[i]->set("armor_prop/armor", inv[i]->query("armor_prop/armor")/2);
}
target->reset_action();
damage = damage * 3;
if (damage > 3500) damage = 3500;
damage = damage - target->query_temp("apply/armor");
target->receive_damage("kee", damage, me); 
target->receive_wound("kee", damage/4, me);  
p = (int)target->query("kee")*100/(int)target->query("max_kee");
msg += damage_msg(damage, "砸伤");
msg += "( $n"+eff_status_msg(p)+" )\n";
me->start_busy(2);
target->start_busy(1);    
                             }
                             }
                             else {
me->start_busy(3);
target->start_busy(3);
msg += HIY"火球急速滚动，火光四溅，掀起阵阵火焰撞向$p怀里！\n" NOR;                  
damage = damage * 2;
if (damage > 2500) damage = 2500;
target->receive_damage("kee", damage, me);
target->receive_wound("kee", damage/6, me);   
p = (int)target->query("kee")*100/(int)target->query("max_kee");
msg += damage_msg(damage, "砸伤");
msg += "( $n"+eff_status_msg(p)+" )\n";
me->start_busy(2);
target->start_busy(1);    
                             }
                           }
                             else {
//target has no armor, so, hehe...
damage = damage*2 + random(damage);
if (damage > 3000) damage = 3000;
if(force > target->query("force")*2) damage = damage*2;
target->receive_damage("kee", damage, me);   
target->receive_wound("kee", damage/2, me);  
p = (int)target->query("kee")*100/(int)target->query("max_kee");
msg += damage_msg(damage, "砸伤");
msg += "( $n"+eff_status_msg(p)+" )\n";
me->start_busy(2);
target->start_busy(1);    
                             }
                           }
                             else {
me->start_busy(2);
msg += HIY"\n$p眼看就要被打中，冒死一个“铁板桥”，全身自膝盖处向后倒去，堪堪避过$w"HIY"！\n" NOR;
                             }
message_vision(msg, me, target);
limbs = target->query("limbs");
msg = replace_string(msg, "$l", limbs[random(sizeof(limbs))]);
msg = replace_string(msg, "$w", RED"火球"NOR);    
if(!target->is_killing(me->query("id"))) target->kill_ob(me);
        if (target->query_temp("weapon")) {
        msg = CYN "\n\n$N窥破$n招式的破绽，随手一掌妙到毫颠。\n"NOR;
                message_vision(msg, me, target);
                target->query_temp("weapon")->move(environment(target));}
return 1;
}

