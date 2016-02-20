#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit ARMOR;

int do_wear(string arg);
int do_remove(string arg);
object offensive_target(object me);

void create()
{
        set_name(HIY ""BLINK"孤狼金蚕衣" NOR, ({"swagger armor" ,"armor", "yi"}) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "crystal");
                set("value",90000);
                set("no_sell", "你想卖给谁？这可是无价之宝！\n");
                set("no_get", "你小子想捡孤狼的宝物？亏你想的出来！\n");
                set("long","这是孤狼用水晶和金蚕丝费时三天三夜织成的一件宝甲，薄如蝉翼，幽香沁人。\n");
               set("armor_prop/armor", 20000);
                set("armor_prop/dodge", 100);
                set("armor_prop/personality", 15);

                set("spells/fire", 100);
                set("spells/thunder",100);
                set("spells/water",100);
                set("spells/wind",100);
                set("spells/earth",100);
        }
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
        add_action("do_wear","wear");
        add_action("do_remove", "remove");

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

int do_wear (string arg)
{
  object me = this_player();
  object zhu = this_object();
  string name = zhu->query("name");
  string msg;

if(arg!="all"&&arg != "swagger armor" )
    return notify_fail("你要什么？\n");
  msg = HIW"$N穿上一件金光闪闪的"+name+""HIW"，顿时飞沙走石！山崩地裂！周围的人无不变色！\n"NOR; 
  zhu->set("wear_msg",msg);
remove_call_out("shengzhuconditions");
call_out("shengzhuconditions",1,me,zhu);
  return 0;
}

int do_remove (string arg)
{
  object me = this_player();
  object zhu = this_object();
  string name = zhu->query("name");
  string msg;

if ( arg!= "all" && arg != "swagger armor")
    return notify_fail("你要脱掉什么？\n");

  msg = HIW"$N将"+name+""HIW"轻轻地脱了下来，周围的人都松了口气，一切都恢复了平静……\n"NOR; 
  zhu->set("unequip_msg",msg);
remove_call_out("shengzhuconditions");
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
        msg = HIW"$N喃喃的念了几句咒语，突然双手一举，凄厉的喊道：天上的众神啊，请现身！我以孤狼的名义请求你们助我除敌！！\n
"HIY"只听空中一连串的声音答道：灵山如来！南海观音！东海敖广！蜀山剑圣！方寸菩提！雪山明王！......\n
"HIY"                          陷空玉鼠！火云飞虎！阴曹地藏！月宫嫦娥！五庄镇元！将军白发！......\n"NOR;

                ap = 5000000;
                dp = target->query("combat_exp");
                        
                        
                if( random(ap + dp) > dp/2 )
                 {
                        damage = 600+random(1000);
                        damage -= (int)target->query("max_mana") / 10 + random((int)target->query("eff_sen") / 5);
                        damage -= random((int)target->query("mana_factor"));

                        if( damage > 0 ) 
                        {
                                msg += HIC "众神一齐施法打下，结果$n"HIC"躲避不及，被观音和如来一起抬着个大力降魔杵砸了个正着，又被镇元的三味真火烧得皮焦骨烂......\n
被雪山明王的长鼻卷的死去活来，被菩提的电母打得皮破血流，还被剑圣的万剑穿个透心凉，又被熬广打中了两个舍身技......\n"NOR; 
msg +=GRN "(  $n"RED"已经陷入半昏迷状态，随时都可能摔倒晕去。"GRN"  )\n"NOR;
msg +=GRN "(  $n"RED"心智已经完全迷失，随时都有可能背过气去。"GRN"  )\n"NOR;

                                target->receive_damage("sen", damage*8/5);
                                target->receive_wound("sen", damage*2/3);
                                target->receive_damage("kee", damage*8/5);
                                target->receive_wound("kee", damage/2);
                                target->start_busy(10);
                        } 
            else
                msg += HIC "\n$n一个懒驴打滚，狼狈不堪的躲了过去。\n" NOR;   
                }
                else
                        msg += HIC "\n$n一个懒驴打滚，狼狈不堪的躲了过去。\n" NOR;  

                message_vision(msg, who, target); 
        }
call_out("shengzhuconditions",7,who,ob);
}

