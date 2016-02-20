// created by ken 2001.3.9
inherit NPC;
inherit F_MASTER;

int do_drop(object, object);

void create()
{
   set_name("风飞白", ({ "master feng", "thip", "bqt","forsky", }));
   set("title", "魔教第二十七代教主");
   set("long", @LONG
魔教教主风飞白,传说中的武学大师.早些年曾与四大天王接下过梁子,所以特别恨天王府的人.
LONG);
   set("gender", "男性");
   set("age", 47);
   set("attitude", "friendly");
   set("rank_info/self", "帮主");
   set("rank_info/respect", "魔主");
   set("class", "evil");
   set("str",100);
   set("per",100);
   set("max_kee", 5000);
   set("max_gin", 5000);
   set("max_sen", 5000);
   set("force", 10000);
   set("max_force", 5000);
   set("force_factor", 300);
   set("max_mana", 8000);
   set("mana", 16000);
   set("mana_factor", 300);
   set("combat_exp", 8000000);
   set_skill("literate", 285);
   set_skill("spells", 285);
   set_skill("tianmo", 285);
   set_skill("unarmed", 285);
   set_skill("tigerfight", 285);
   set_skill("dodge", 285);
   set_skill("dimo-steps", 285);
   set_skill("blade", 285);
   set_skill("parry", 285);
   set_skill("force", 285);
   set_skill("evil-force", 285);
   set_skill("sword", 285);
   set_skill("nature",285);
   set_skill("tianmo-blade", 285);
// set_skill("tianxian-sword", 285);
   map_skill("spells", "tianmo");
   map_skill("unarmed", "tigerfight");
   map_skill("dodge", "dimo-steps");
   map_skill("force", "evil-force");
   map_skill("parry", "tianmo-blade");
   map_skill("blade", "tianmo-blade");
// map_skill("sword", "tianxian-sword");
   set("chat_chance_combat", 80);
   set("chat_msg_combat", ({
     (: cast_spell, "lei" :),
     (: cast_spell, "fog" :),
   }) );

   create_family("魔教", 1, "教主");

   setup();
   carry_object("/d/obj/cloth/choupao")->wear();
   carry_object("/d/obj/weapon/blade/jindao")->wield();
   carry_object("/d/mojiao/obj/long-blade");
}

void attempt_apprentice(object ob)
{
   if (!((string)ob->query("ljm/kill") =="done" )) {
     command("say 你想拜我是可以，" + RANK_D->query_rude(ob) + "连小小的四天王都杀不了,收你有何用。\n");
     write("看来不消了风飞白的气是拜不了他的。\n");
     return;
   }   
   if (((int)ob->query_skill("tianmo", 1) < 201 )) {
     command("say " + RANK_D->query_rude(ob) + "连本门最基本的魔功都修为不精,如何做我的徒第。\n");
     return;
   }

  if ((int)ob->query("combat_exp") < 2200000 ) {
     command("say 不行，" + RANK_D->query_rude(ob) + "就这点本事,做我徒第,岂不丢了我的脸。\n");
   return;
   }
   command("nod " + ob->query("id") );
   command("say 好！我就收下你。\n");

   command("recruit " + ob->query("id") );
   return;   
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                ob->set("class", "evil");
                ob->set("title", "盖世狂魔");
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

