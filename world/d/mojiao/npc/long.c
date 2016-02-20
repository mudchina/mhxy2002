// modify by ken 2001.3.9
inherit NPC;
inherit F_MASTER;

void create()
{
   set_name("龙乘云", ({ "master long", "long", "yun","chengyun", }));
   set("title", "魔教副教主");
   set("long", @LONG
龙乘云是地魔老人的得意门生，也是风飞白的师第，其一身武学及才华不下于其师兄
现任副教主之职，负责教内的大小事务.
LONG);
   set("gender", "男性");
   set("age", 37);
   set("attitude", "friendly");
   set("rank_info/self", "帮主");
   set("rank_info/respect", "副教主");
   set("class", "evil");
   set("str",100);
   set("per",100);
   set("max_kee", 5000);
   set("max_gin", 5000);
   set("max_sen", 5000);
   set("force", 10000);
   set("max_force", 4500);
   set("force_factor", 300);
   set("max_mana", 8000);
   set("mana", 16000);
   set("mana_factor", 300);
   set("combat_exp", 8000000);
   set_skill("literate", 220);
   set_skill("spells", 250);
   set_skill("tianmo", 250);
   set_skill("unarmed", 320);
   set_skill("tigerfight", 320);
   set_skill("dodge", 300);
   set_skill("dimo-steps", 300);
   set_skill("blade", 330);
   set_skill("parry", 300);
   set_skill("force", 280);
   set_skill("evil-force", 280);
   set_skill("sword", 270);
   set_skill("nature",270);
   set_skill("tianmo-blade", 330);
   set_skill("tianxian-sword", 290);
   map_skill("spells", "tianmo");
   map_skill("unarmed", "tigerfight");
   map_skill("dodge", "dimo-steps");
   map_skill("force", "evil-force");
   map_skill("parry", "tianmo-blade");
   map_skill("blade", "tianmo-blade");
   map_skill("sword", "tianxian-sword");
   set("chat_chance_combat", 80);
   set("chat_msg_combat", ({
     (: cast_spell, "lei" :),
//   (: cast_spell, "fog" :),
   }) );

   create_family("魔教", 1, "副教主");

   setup();
   carry_object("/d/obj/cloth/choupao")->wear();
   carry_object("/d/obj/weapon/blade/jindao")->wield();
   carry_object("/d/mojiao/obj/long-blade");
}

void attempt_apprentice(object ob)
{
/*
   if (!((string)ob->query("ljm/kill") =="done" )) {
     command("say 你想拜我是可以，" + RANK_D->query_rude(ob) + "连小小的四天王都杀不了,收你有何用。\n");
     write("看来不消了风飞白的气是拜不了他的。\n");
     return;
   }   
   if (((int)ob->query_skill("tianmo", 1) < 201 )) {
     command("say " + RANK_D->query_rude(ob) + "连本门最基本的魔功都修为不精,如何做我的徒第。\n");
     return;
   }
*/
   if ((int)ob->query("combat_exp") < 1000000 ) {
     command("say 你个" + RANK_D->query_rude(ob) + "别来气我了。\n");
   return;
   }
   command("nod " + ob->query("id") );
   command("say 不错，你既能谦虚好学，又能关爱同门，我就收下你这个徒第。\n");

   command("recruit " + ob->query("id") );
   return;   
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                ob->set("class", "evil");
                ob->set("title", "魔教护法");
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
