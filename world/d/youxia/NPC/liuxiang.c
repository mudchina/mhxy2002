
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 //created 23-06-2001 海上飘(piao)

//yegucheng.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
string give_map(object me);
int do_yes(string arg);


void create()
{
       set_name("楚留香", ({ "chu liuxiang", "chu", "liuxiang" }) );

       set("long", "楚留香乃是当代绝顶高手之一，人称“盗帅”．．\n");
      set("faith",4000);
       set("gender", "男性");
     set("title", HIW "盗帅留香"NOR);
   set("class", "youxia");
       set("age", 34);
       set("attitude", "friendly");
        create_family("江湖浪子", 1, "绿");
       set("per", 30);
   set("int", 30);
   set("str", 30);
   set("cps", 30);
       set("max_kee", 2000);
       set("max_gin", 1100);
       set("max_sen", 2000);
       set("force", 8000);
       set("max_force", 3000);
       set("force_factor", 160);
       set("max_mana", 3000);
       set("mana", 8000);
       set("mana_factor", 100);
       set("combat_exp", 5000000);
       set("daoxing", 2000000);
        set("eff_dx", 250000);
        set("nkgain", 400);
            set("chat_chance", 10);
        set("chat_msg", ({
            "楚留香说道：亏我和西门吹雪还是挚友，这小子有好事竟然瞒着我．．．
听说这万梅山庄的后山有处瀑布后面藏有钱财，最重要的有三件绝世防具，今晚我就动手试一下！\n",
(: random_move :),
(: random_move :),
(: random_move :),
(: random_move :),
(: random_move :)
   }) );

       set_skill("unarmed", 250);
       set_skill("tanzhishentong", 250);
       set_skill("dodge", 250);
       set_skill("piaoxiang",250);
     
       
         map_skill("unarmed", "tanzhishentong");
         
       map_skill("dodge", "piaoxiang");
   

        set("inquiry", ([
        "血海飘香" : (: give_map :),

]) );

setup();
       
        carry_object("/d/youxia/obj/flsword");
        carry_object("/d/youxia/obj/wushicloth")->wear();
}


void attempt_apprentice(object ob)
{
   if ( (string)ob->query("family/family_name")=="江湖浪子") {
   if (((int)ob->query("combat_exp") < 1000000 )) {
   command("say 这位"+ RANK_D->query_respect(ob) + "你武功低微．．．．还是几年后再来找我吧。\n");
   return;
   }
        command("smile");
   command("say 很好，原来这位"  + RANK_D->query_respect(ob) +"是游侠儿的徒弟，好吧，本城主就收你为徒！\n");
        command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，他日必定有成。\n");
       command("recruit " + ob->query("id") );
       ob->set("title", HIW"楚留香真传弟子"NOR);
  return;
   }
   command("shake");
   command("say " + RANK_D->query_respect(ob) + "既然已经派入他门,还是另寻他人吧！\n");
        return;
}
void init()
{
      ::init();
//      re_rank(this_player())
      add_action("do_fuming","fuming");
      add_action("do_yes", "yes");
}


string give_map(object me)
{
        me=this_player();
        me->set_temp("need_map", 1);
        return ""HIW"〖血海飘香〗"HIC"是我毕生武功的精华,你想要吗(yes)？"NOR"\n";
}


int do_yes(string arg)
{
        object me;

        me=this_player();
        
        if(me->query_temp("need_map")) 
        {
                message_vision("$N答道：想要！\n\n", me);

               if(me->query("family/family_name") != "江湖浪子" )
                return notify_fail("楚留香说道：想骗本门派的秘籍，没门！\n");

                if( query("no_map") == 0 )
                {
                        message_vision("楚留香说道：好！那我给你这本秘籍吧！\n", me);
                        me->set_temp("need_map", 0);

                        carry_object("/d/youxia/obj/piaoxiang");
                        command("give book to " + me->query("id"));
                        set("no_map", 1);
                        call_out("regenerate", 480);
                }
                else
                {
                        message_vision("楚留香说道：我本来想给你一本的，但是刚才被人要走了。\n", me);
                }

                return 1;
        }
        return 0;
}

int regenerate()
{
        set("no_map", 0);
        return 1;
}



