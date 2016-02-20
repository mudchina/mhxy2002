// modify by ken 2001.3.9
inherit NPC;
inherit F_MASTER;

void create()
{
   set_name("萧中云", ({ "master xiao", "xiao", "yun","zhongyun", }));
   set("title", "魔教镇教明王");
   set("long", @LONG
这萧中云乃是上代教主的师兄，也是剑魔无恨的师傅，一身的武学深不可测
在教中地位极为尊贵，连天地人三魔也对其客气的很，也是无恨最为信赖的
人。
LONG);
   set("gender", "男性");
   set("age", 87);
   set("attitude", "friendly");
   set("rank_info/self", "明王");
   set("rank_info/respect", "明王");
   set("class", "evil");
   set("str",100);
   set("per",100);
   set("max_kee", 7000);
   set("max_gin", 7000);
   set("max_sen", 7000);
   set("force", 10000);
   set("max_force", 7000);
   set("force_factor", 300);
   set("max_mana", 8000);
   set("mana", 16000);
   set("mana_factor", 300);
   set("combat_exp", 9000000);
   set_skill("literate", 320);
   set_skill("spells", 320);
   set_skill("tianmo", 320);
   set_skill("unarmed", 320);
   set_skill("tigerfight", 320);
   set_skill("dodge", 320);
   set_skill("dimo-steps", 320);
   set_skill("blade", 350);
   set_skill("parry", 320);
   set_skill("force", 300);
   set_skill("evil-force", 300);
   set_skill("sword", 300);
   set_skill("nature",300);
   set_skill("tianmo-blade", 350);
   set_skill("tianxian-sword", 300);
   map_skill("spells", "tianmo");
   map_skill("unarmed", "tigerfight");
   map_skill("dodge", "dimo-steps");
   map_skill("force", "evil-force");
   map_skill("parry", "tianmo-blade");
   map_skill("blade", "tianmo-blade");
   map_skill("sword", "tianxian-sword");
   set("chat_chance_combat", 20);
   set("chat_msg_combat", ({
    (: perform_action, "blade", "tiandirenmo" :),
  }) );


   create_family("魔教", 1, "镇教明王");

   setup();
   carry_object("/d/obj/cloth/choupao")->wear();
   carry_object("/d/mojiao/obj/fireblade")->wield();
// carry_object("/u/ken/obj/long-blade");
}

void attempt_apprentice(object ob)
{

   if (!((string)ob->query("zap/kill") =="done" )) {
     command("say 老夫早就不收徒了。\n");
     write("看起来明王是不愿收徒弟。\n");
     return;
   }   
   if (((int)ob->query_skill("tianmo", 1) < 201 )) {
     command("say " + RANK_D->query_rude(ob) + "连本门最基本的魔功都修为不精,如何做我的徒第。\n");
     return;
   }

   if ((int)ob->query("combat_exp") < 4000000 ) {
     command("say 算了吧，老夫不收徒第。\n");
   return;
   }
   command("nod " + ob->query("id") );
   command("say 没想道这辈子还能收到这么一个可造之才。\n");

   command("recruit " + ob->query("id") );
   return;   
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                ob->set("class", "evil");
                ob->set("title", "魔教大护法");
        }
}


void init()
{
     object me;
   
     ::init();
    add_action("do_exercise",({"bian"}));
     if( interactive(me = this_player()) && !is_fighting() ) {
     call_out("greeting", 0, me);
}
}

void greeting(object me)
{
      int mykar=me->query_kar();
      if( random(mykar) > 100) return;
      else
 {
      me->delete_temp("spellslevel");
      me->delete_temp("d_mana");
      me->delete_temp("apply/name");
      me->delete_temp("apply/id");
      me->delete_temp("apply/short");
      me->delete_temp("apply/long"); 
      return;
    }
}
int do_exercise(string arg)
{
    write("你喃喃念了几句咒语,好象想变什么，但什么也没发生。\n");
    return 1;
}
