//by tianlin 2001.7.31

#include <ansi.h> 
inherit NPC;
string ask_kill();
string ask_cancel();
void create()
{
   set_name("猪小戒", ({"zhu xiaojie", "zhu", "xiaojie"}));
   set("title", HIC"霹雳"NOR+HIW"天下"NOR);
   set("long","他是猪八戒的养子,学了一身本领。\n");
   set("gender", "男性" );
   set("age", 43);
   set("per", 112);//no rongmao description.
   set("str", 50);
   set("class", "tianpeng");
   set("attitude", "peaceful");
   create_family("天蓬帅府", 1, "祖师");
  set("combat_exp", 3200000);
  set("daoxing", 3056000);

  set("max_kee", 3500);
  set("max_sen", 3500);
  set("max_force", 4700);
  set("max_mana", 2600);
  set("mana", 5000);
  set("force", 6000);
  set("force_factor", 160);
  set("mana_factor", 120);
  set_skill("unarmed", 200);
  set_skill("dodge", 200);
  set_skill("parry", 200);
  set_skill("rake", 200);
  set_skill("force", 200);
  set_skill("stick", 100);
  set_skill("sword", 140);
  set_skill("spells", 200);
  set_skill("fofa", 200);
  set_skill("literate", 160);
  set_skill("tianpeng-zhang", 200);
  set_skill("bajie-force", 200);
  set_skill("chaos-steps", 200);
  set_skill("skyriver-rake", 200);
  map_skill("force", "bajie-force");
  map_skill("spells", "fofa");
  map_skill("rake", "skyriver-rake");
  map_skill("unarmed", "tianpeng-zhang");
  map_skill("parry", "skyriver-rake");
  map_skill("dodge", "chaos-steps");

        set("eff_dx", -200000);
        set("nkgain", 400);

    set("inquiry", ([
     "除妖" : (:ask_kill:),
     "kill" : (:ask_kill:),
   "cancel": (:ask_cancel:),
    ]));
   setup();
   carry_object("/d/obj/armor/yinjia")->wear();
   carry_object("/d/kaifeng/obj/jingangpa")->wield();
}
string ask_cancel()
{
    object me=this_player();
if((int)me->query_temp("m_mieyao"))
{
      me->add("daoxing",-2000);
      me->delete_temp("m_mieyao");
      me->delete("secmieyao");
      me->delete("secmieyao/type");
      me->delete("secmieyao/location");
      me->delete("secmieyao/place");
      me->delete("secmieyao/name");
      me->delete("secmieyao/id");
     return ("没用的东西！");
}
else
{
     return ("你有任务吗？！");
}
}

void attempt_apprentice(object ob)
{
   if( (int)ob->query("str") < 20 ){
     command("kick " + ob->query("id"));
     command("say 你的力量太小了。\n");
     return;
   }

   if( (string)ob->query("family/family_name")=="天蓬帅府" ){
     if( (int)ob->query("family/generation") < 2  ){
        command("say 不敢，不敢。我该拜" + RANK_D->query_respect(ob) + "您为师才是。\n");
     }
     else if( (int)ob->query("family/generation") ==2  ){
        command("say 你这个" + RANK_D->query_rude(ob) + "别来消遣你爷爷我了！\n");
     }
     else if( (int)ob->query("family/generation") ==3  ){
        command(":D");
        command("say 你这个" + RANK_D->query_rude(ob) + "是不是被师父赶出来了？你爷爷我今天心情好，就收留你吧...\n");
        command("recruit " + ob->query("id") );
     }
     else {
        if( (int)ob->query("combat_exp") >= 500000 ){
          command(":D ");
          command("say 好，" + RANK_D->query_respect(ob) + "好好跟我干，将来有你的好处！\n");
          command("recruit " + ob->query("id") );
        }
        else {
          command("say 你还是先找别人练着吧。\n");
        }
     }
   }

   else{
     command("hmm");
     command("say 这位" + RANK_D->query_respect(ob) + "，你还是找别人先练练吧。\n");
   }

   return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "tianpeng");
}

void init()
{       
   object ob=this_player();

   ::init();
   if ( ((string)ob->query("gender")=="男性") && ((int)ob->query("str") < 20) && (random(3) > 1) )
        {
                        remove_call_out("greeting");
                        call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;

        switch( random(1) ) {
                case 0:
     command("kick " + ob->query("id"));
     command("say 尖嘴猴腮！");
     command("laugh");
     break;
   }
}

string ask_kill()
{
   object me=this_player();
   
   if(me->query("family/family_name")!="天蓬帅府")
      return ("你不是本门中人!");

   command("pat "+me->query("id"));
   command("say 有志气！");
   return "/d/obj/mieyao"->query_yao(me);
}
 


