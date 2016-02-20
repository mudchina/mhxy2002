#include <ansi.h>
#include <dbase.h>
#include <weapon.h>

inherit SWORD;

int do_wield(string arg);
object offensive_target(object me);

void create()
{
        set_name(HIC "银狼破皇剑" NOR, ({"wolf sword" ,"jian", "sword"}) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("material", "crystal");
                set("value",90000);
                set("no_sell", "你想卖给谁？这可是无价之宝！\n");
                set("no_get", "你小子想捡孤狼的宝物？亏你想的出来！\n");
                set("long","这是孤狼在一次奇遇时偶然得到的一把宝剑，上面依稀有狼影闪动。\n");
                set("spells/fire", 100);
                set("spells/thunder",100);
                set("spells/water",100);
                set("spells/wind",100);
                set("spells/earth",100);
        }
        init_sword(5000);
       setup();
}

int init()
{
        object who = this_player();
        {
        if ( interactive(environment()) && 
        environment()->query("combat_exp") < 100000 )
        this_object()->move("/obj/empty"); 
         }
        add_action("do_wield","wield");
}

object offensive_target(object me)
{
        int sz;
        object *enemy;

        enemy = me->query_enemy();
        if( !enemy || !arrayp(enemy) ) return 0;

        sz = sizeof(enemy);
        if( sz > 4 ) sz = 4;

        if( sz > 0 ) return enemy[random(sz)];
        else return 0;
}

int do_wield (string arg)
{
  object me = this_player();
  object zhu = this_object();
  string name = zhu->query("name");
  string msg;

if(arg!="all"&&arg != "wolf sword" )
    return notify_fail("你要干什么？\n");
  msg = HIY"$N手腕轻轻一抖，随着一声狼啸，手中已多出一把"HIW"银狼破皇剑"HIY"！\n"NOR; 
  zhu->set("wield_msg",msg);
remove_call_out("shengzhuconditions");
call_out("shengzhuconditions",1,me,zhu);
  return 0;
}

void shengzhuconditions(object who,object ob)
{
     object target;
     int ap,dp,damage;
     string msg;
          
string type;
type = ob->query("armor_type");
if( who->query_temp("armor/" + type) && ob->query("equipped")!="worn")
return;
  if( who->is_fighting())
     {
        target = offensive_target(who);
  if( ! target ) return ;      
 if( ! present( target,environment(who)) ) return ;    
        msg = "\n"HIW"银狼破皇剑"HIY"霞光"HIB"四射"HIC"，"CYN"狼影"HIM"群舞"HIC"......\n"NOR;

                ap = 5000000;
                dp = target->query("combat_exp");
                        
                        
                if( random(ap + dp) > dp/2 )
                 {
                        damage = 600+random(1000);
                        damage -= (int)target->query("max_mana") / 10 + random((int)target->query("eff_sen") / 5);
                        damage -= random((int)target->query("mana_factor"));

                        if( damage > 0 ) 
                        {
                                msg += HIW "\n剑"HIY"气"HIR"纵"HIC"横"HIW"......\n"NOR; 
msg += "\n( $n"HIR"气息粗重，动作开始散乱，看来所受的伤着实不轻。"NOR" )\n"NOR;
                                target->receive_damage("kee", damage/2);
                                target->receive_wound("kee", damage/5);
                                target->start_busy(2+random(2));
                        } 
            else
                msg += HIC "\n$n不为之所动。\n" NOR;   
                }
                else
                        msg += HIC "\n$n不为之所动。\n" NOR;  

                message_vision(msg, who, target); 
        }
call_out("shengzhuconditions",7,who,ob);
}

