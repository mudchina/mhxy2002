
#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit F_UNIQUE;
inherit NECK;

int do_wear(string arg);
int do_remove(string arg);
int do_amalgamation();
object offensive_target(object me);

void create()
{
        set_name(HIR "»ğÁéÖé" NOR, ({"huo lingzhu", "huozhu"}) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¿Å");
                set("material", "crystal");
set("no_steal",1);
                set("value",10000);
                set("no_drop", "Èç´Ë±¦¹óµÄ±¦ÎïÔÙÊÀÄÑÇó°¡¡£\n");
                set("no_give", "ÕâÖÖÏ¡ÊÀÖ®±¦ÔõÃ´ÄÜÇáÒ×ËÍÈËÄØ?\n");
                set("no_sell", "Âô?ÕâÖÖÏ¡ÊÀÖ®±¦Ë­ÂòµÃÆğ°¡!\n");
                set("long","´«ËµÖĞµÄÎåĞĞ±¦ÖéÖ®Ò»£¬ÅåÖ®¿É±Ü»ğÉÕ£¬²¢¿É·¢³ö»ğÏµ·¨Êõ¡£\nÎªÆíÓêËù±ØĞèÖ®Îï¡£");
                set("replace_file", "/d/obj/flower/rose");
                set("bb",1);
                set("armor_prop/armor", 1);
                set("spells/fire", 1);
        }
        setup();
}

int init()
{
        add_action("do_wear","wear");
        add_action("do_remove", "remove");
        //·ç»ğÀ×ÍÁË®ËÄÖéºÏ±Ú
        add_action("do_amalgamation", "wuzhuhebi");
        return 1;
}

// This function selects a random target for offensive spells/functions.
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

if (arg == "all") arg ="huozhu";
if (arg != "huozhu" &&  arg != "huo lingzhu" )
    return notify_fail("ÄãÒªÅå´øÊ²Ã´£¿\n");
  msg = "$N´÷ÉÏÒ»¿Å"+name+"£¬ºì¹âÕÕÁÁÁËÌì¼Ê¡£\n"; 
  zhu->set("wear_msg",msg);
remove_call_out("conditionhuozhu");
call_out("conditionhuozhu",1,me,zhu);
  return 0;
}

int do_remove (string arg)
{
  object me = this_player();
  object zhu = this_object();
  string name = zhu->query("name");
  string msg;

  if (arg!= "all" && arg != "huozhu" && arg != "huo lingzhu")
    return notify_fail("ÄãÒªÕªµôÊ²Ã´£¿\n");

  msg = "$N½«"+name+"ÇáÇáµØÕªÏÂÀ´¡­¡­\n"; 
  zhu->set("unequip_msg",msg);
  remove_call_out("conditionhuozhu");
  return 0;
}

void conditionhuozhu(object who,object ob)
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

        msg = HIR"»ğÁéÖéÃÍÈ»ºì¹âËÄÉä£¬°ë¿ÕÖĞ¸¡ÏÖ³öÒ»¸ö³àºìµÄ»ğÉñ×£ÈÚ£¬Ö»¼û×£ÈÚË«ÊÖÒ»È¦£¬\n
Ò»¸öË¶´óµÄ»ğÇò³å×Å$n·ÉÈ¥£¡\n"NOR;
//divid by 10;

                ap = 2000000;
                dp = target->query("combat_exp");
                        
                        
                if( random(ap + dp) > dp )
                 {
                        damage = 500+random(300);
                        damage -= (int)target->query("max_mana") / 10 + random((int)target->query("eff_sen") / 5);
                        damage -= random((int)target->query("mana_factor"));

                        if( damage > 0 ) 
                        {
                                msg += HIC "½á¹û$n¶ã±Ü²»¼°£¬±»»ğÇò×²¸öÕı×Å£¡Ğë·¢¾¡½¹¡£\n" NOR;

                                target->receive_damage("sen", damage*4/5);
                                target->receive_wound("sen", damage/3);
                                target->receive_damage("kee", damage*4/5);
                                target->receive_wound("kee", damage/4);
                        } 
            else
//here, cast failed and the target's mana_factor will be added to the previous
//damage to hurt yourself:(...note damage<0.
                msg += HIC "\nË­Öª$nºÁÎŞ·´Ó¦¡£\n" NOR;   
                }
                else
                        msg += "µ«ÊÇ±»$n¶ã¿ªÁË¡£\n";

                message_vision(msg, who, target); 
        }
call_out("conditionhuozhu",7,who,ob);
}

int do_amalgamation()
{
        //Îå¿Å±¦Öé
        object wind,water,thunder,earth;
        object who = this_player();
        object shengzhu;

        if(who->is_fighting())
           return notify_fail("ÄãÕı´òÕÌÄØ£¡ÏëËÀ°¡£¡\n");
        if(who->is_busy())
           return notify_fail("ÄãÕıÃ¦×ÅÄØ!\n");
        if(!wind = present("fengzhu",who))
           return notify_fail("Äã»¹È±ÉÙ"+HIG "·çÁéÖé" NOR +"ÄØ!ÔõÃ´ÎåÖéºÏ±ÚÄØ?\n");
        if(!thunder = present("leizhu",who))
           return notify_fail("Äã»¹È±ÉÙ"+HIB "À×ÁéÖé" NOR +"ÄØ!ÔõÃ´ÎåÖéºÏ±ÚÄØ?\n");
        if(!earth = present("tuzhu",who))
           return notify_fail("Äã»¹È±ÉÙ"+HIY "ÍÁÁéÖé" NOR +"ÄØ!ÔõÃ´ÎåÖéºÏ±ÚÄØ?\n");
        if(!water = present("shuizhu",who))
           return notify_fail("Äã»¹È±ÉÙ"+HIW "Ë®ÁéÖé" NOR +"ÄØ!ÔõÃ´ÎåÖéºÏ±ÚÄØ?\n");
if ((water->query("equipped")!="worn") && (wind->query("equipped")!="worn") && (thunder->query("equipped")!="worn") && (earth->query("equipped")!="worn") && (this_object()->query("equipped")!="worn"))
{        
        message_vision("$N°ÑÎå¿Å±¦Öé·ÅÔÚÒ»Æğ¡£Ö»¼ûÎå¿Å±¦ÖéÈ½È½ÉıÆğ£¬Ò»Ê±±¦¹â´óÊ¢£¬Ö±³åÔÆÏö£¡\n
¶íÇê£¬"+HIG "·çÁéÖé" NOR+"·ÉÖÁ¶«·½·Å³öÈáºÍÂÌ¹â£»"+HIR "»ğÁéÖé" NOR +"·ÉÖÁÄÏ·½·¢³ö×ÆÄ¿ºì¹â£»"+HIB "À×ÁéÖé" NOR +"·ÉÖÁÎ÷·½ºöÃ÷ºö°µ£¬\n
ÉÁ³öÓÄÓÄÀ¶¹â£»"+HIW "Ë®ÁéÖé" NOR +"È´Í¨ÌåÓ¨°×£¬·ÉÖÁ±±·½£»"+HIY "ÍÁÁéÖé" NOR +"Ö±³åÌìñ·£¬ĞºÏÂÍòÀï»Æ¹â¡£\n
ÓÖ´ıÆ¬¿Ì£¬ÎåÖéºôµÄÒ»°µ£¬$NÊÖÖĞÈ´¶àÁËÒ»¿ÅË¶´óµÄÍ¸Ã÷±¦Öé£¬²»Ê±·¢³öÎå²ÊºÁ¹â¡£\n",who);

       //message("channel:rumor",RED+"¡¾Ò¥ÑÔ¡¿Ä³ÈË£º"+who->query("name")+"ÄÃµ½Ê¥ÁéÖéÁË£¡\n"+NOR,users() );
          message("system",HIC"¡¼"HIW"¾»ĞëÀÏ×æ"HIC"¡½"HIY+who->query("name")+HIG"ÄÃµ½ÁË[1;37mÊ¥ÁéÖé£¡[2;37;0m\n"NOR,users());    

        
         shengzhu = new("/d/shushan/zhenyaota/obj/shengzhu");
        shengzhu->move(who);
        destruct(wind);
        destruct(water);
        destruct(earth);
        destruct(thunder);
        destruct(this_object());
        return 1;
}
return notify_fail("±¦Öé±ØĞëÕªÏÂ²ÅÄÜºÏèµ£¡\n");
}
