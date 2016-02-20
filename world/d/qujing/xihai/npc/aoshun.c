//by tianlin 2001.7.27
inherit NPC;
#include <ansi.h>
int ask_zhong();

void create()
{
       set_name("°½Ë³", ({"ao shun", "ao","shun","longwang","wang","aoshun"}));
       set("gender", "ÄÐÐÔ");
       set("age", 30);
       set("long","°½Ë³ÄËÎ÷º£ÁúÍõ£¬ÄË¶«º£ÁúÍõ°½¹ãÖ®µÜ¡£\n");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("age", 65);
       set("title", "Î÷º£ÁúÍõ");
       set("class","dragon");
       set("attitude", "peaceful");
       set("shen_type", 1);
       set("combat_exp", 1200000);
       set("rank_info/respect", "±ÝÏÂ");
       set("per", 20);
       set("str", 30);
       set("max_kee", 3000);
       set("max_gin", 400);
       set("max_sen", 800);
       set("force", 3000);
       set("max_force", 1500);
       set("force_factor", 120);
       set("max_mana", 800);
       set("mana", 1600);
       set("mana_factor", 40);

       set("combat_exp", 1200000);
       set_skill("unarmed", 200);
       set_skill("dodge", 150);
       set_skill("force", 180);
       set_skill("parry", 180);
       set_skill("fork", 150);
       set_skill("spells", 150);
       set_skill("seashentong", 150);
       set_skill("dragonfight", 200);
       set_skill("dragonforce", 150);
       set_skill("fengbo-cha", 180);
       set_skill("dragonstep", 150);
       map_skill("spells", "seashentong");
       map_skill("unarmed", "dragonfight");
       map_skill("force", "dragonforce");
       map_skill("fork", "fengbo-cha");
       map_skill("parry", "fengbo-cha");
       map_skill("dodge", "dragonstep");
         set("inquiry", ([
     "ÁúÚ£": (: ask_zhong:),
        ]));


setup();
        carry_object("/d/obj/cloth/longpao")->wear();
}


int ask_zhong()
{
        object me;
        me=this_player(); 
            if(me->query("xinguan/heishui")!="done") { 
            command("disagree");
            command("say ÄãÊÇÊ²Ã´ÈË£¬¾¹¸Ò´òÎÒÁú×åÊ¥µØµÄÖ÷Òâ£¡\n");
          return 1;
            }
            else
            {
               if(!me->query_temp("ÁúÚ£")){
                 command("shake");
                 command("say ÁúÚ£ÊÇÎÒÎ÷º£Áú×å°²Ï¢Ö®Ëù,"+RANK_D->query_respect(me)+"²»µÃÈëÄÚ");
                 command("say ËäÈ»"+RANK_D->query_respect(me)+"ÓÚÎÒÎ÷º£ÓÐËù¶÷µÂ,Ð¡ÁúÒ²²»¸Ò»µÁË×æ×ÚÒÅÃü.");
                 return 1;
               }
               command("consider");
               command("say ¼ÈÈ»¡­¡­¼ÈÈ»"+RANK_D->query_respect(me)+"ÒªÈ¥£¬ÄÇ¡­¡­¾ÍÈ¥°É¡£\n");
               message_vision(HIG"°½Ë³´óÐäÒ»ÕÐ£¬$N»èºõºõµØµ½ÁËÒ»¸öÄ°ÉúµÄµØ·½¡£\n"NOR,me);
               me->move("/d/qujing/xihai/zhong");
          return 1;
            }
      return 1;
}


int accept_object(object me,object ob)
{       object who;
        me=this_object();
        who=this_player();

        if (ob->query("id")=="letter" ){
        if(who->query("xinguan/heishui")=="done") { 
                command("hoho");
                command("say "+RANK_D->query_respect(who)+"ÓÖÀ´ÁËÃ´£¿\n");
                command("say ÄÇÄõÐóÖ®ÊÂ¶àÐ»"+RANK_D->query_respect(who)+"´úÎªÕÚÑÚ£¬Ð¡Áú²»Ê¤¸Ð¼¤¡£\n");
                command("say "+RANK_D->query_respect(who)+"½ñ´Î¹âÁÙº®Éá£¬ÓÐºÎ¹ó¸É£¿\n");
                call_out("destroy", 1, ob);
                who->set_temp("ÁúÚ£",1);
                return 1;
        }       
        if( who->query_temp("heshen")) {
                call_out("read", 2);
                return 1;
        }
        command("heng");
        command("say ÎÞÆ¾ÎÞ¾Ý£¬Äã²»ÊÇÔÚÔ©Í÷ÈË°É¡£\n");
        command("say ÀÏ·òÒÑ¾­ÖªµÀÁË£¬"+RANK_D->query_respect(who)+ "Çë»Ø°É¡£\n");
        call_out("destroy", 1, ob);
        return 1;
        }
}

void read()
{
        object who;
        who = this_player();
        
    message_vision ("°½Ë³µãµãÍ·,ÄÃÆðÐÅÌû,¿´ÁËÆðÀ´¡£\n",who);  

        call_out("say",2);
}

void say()
{
        object who;
        who = this_player();
        
    message_vision ("°½Ë³Ò¡Í·Ì¾µÀ£º¡°¼ÒÃÅ²»ÐÒ£¬³ö´Ë°ÜÀà£¡¡±\n",who);  
        call_out("cry",2);
}
void cry()
{
        object who;
        who = this_player();
        
        command("cry");
        call_out("man",2);
}
void man()
{
        object who;
        who = this_player();
        
        command("say " +RANK_D->query_respect(who)+ "Çë¾ÈÐ¡ÉñÒ»Ãü£¬ÇÐÎð¸æÖªÓñµÛ£¡\n");
        call_out("zuo",2);
}
void zuo(object me,object ob)
{
        object who;
        who = this_player();
        
        command("say " +RANK_D->query_respect(who)+"ÇÒÁîÈ®×ÓÄ¦°º£¬Í¬ÍùºÚË®ÇÜ´ËÑýÄõ¡£\n");
        who->set_temp("ÍõÃü",1);
                call_out("destroy", 1, ob);
}
void destroy(object ob)
{
        destruct(ob);
        return;
}


void announce_success (object who) 
{
  int i;

  if (who->query("combat_exp") < 10000)
    return;
  if (who->query("obstacle/heishui") == "done") || who->query("obstacle/shushan") != "done")
    return; 
   if(!who->query_temp("fight"))
    return;
   if(!who->query_temp("killlong"))
    return;
  i = random(1000);
  who->add("obstacle/number",1);
  who->set("obstacle/heishui","done");
  who->add("daoxing",i+4000); 
  command("chat "+who->query("name")+"ºÚË®ÊÕÄõÁú£¬³¤ºÓµ´ÑýÄ§£¡");
message("channel:chat",HIY"¡¾¹ý¹ØÕ¶½«¡¿¹ÛÒôÆÐÈø(guanyin pusa)£º"+who->query("name")+"´³¹ýÎ÷ÐÐÈ¡¾­[1;37mµÚÈýÊ®¾Å¹Ø£¡\n"NOR,users());//this is by tianlin 2001.5.8
  tell_object (who,"ÄãÓ®µÃÁË"+chinese_number(4)+"Äê"+
               chinese_number(i/4)+"Ìì"+
               chinese_number((i-(i/4)*4)*3)+"Ê±³½µÄµÀÐÐ£¡\n");
  who->save(); 
}


