//master2.c
//modify by ken
inherit NPC;
inherit F_MASTER;
string expell_me(object me);
void create()
{
  set_name("赋太炎", ({ "master fu", "fu", "mo", "tianmo", "ren", "master", "shifu" }));
  set("title", "天魔堂总管");
  set("gender", "男性");
  set("age", 33);
  set("str", 30);
  set("per", 30);
  set("int", 40);
  set("cor", 90);
  set("cps", 90);
  set("long", "他就是这天魔堂的总管，也是地魔老人的爱徒。\n");
  set("combat_exp", 2400000);
  set_skill("literate", 180);
  set_skill("blade", 190);
  set_skill("force", 180);
  set_skill("dodge", 185);
  set_skill("parry", 200);
  set_skill("spells", 190);
  set_skill("unarmed", 180);
  set_skill("huolong-zhang", 180);
  set_skill("dimo-steps", 190);
  set_skill("tianmo-blade", 200);
  set_skill("evil-force", 190);
  set_skill("unarmed", 180);
set_skill("tigerfight", 190);
  set_skill("tianmo",200);
  map_skill("unarmed", "tigerfight");
  map_skill("force", "evil-force");
  map_skill("spells", "tianmo");
  map_skill("blade", "tianmo-blade");
  map_skill("parry", "tianmo-blade");
  map_skill("dodge", "dimo-steps");
  set("max_sen", 5500);
  set("max_kee", 5500);
  set("force", 5000);
  set("max_force", 5500);
  set("force_factor", 280);
  set("max_mana",5500);
  set("mana",7000);
  set("mana_factor",300);
  set("inquiry", ([
                   "离教": (: expell_me :),
                   "leave": (: expell_me :),
                   ]) );

  create_family("魔教", 1, "堂主");
  set("chat_chance_combat", 60);
  set("chat_msg_combat", ({
                (: perform_action, "blade", "tiandirenmo" :),
  }) );

  setup();
  carry_object("/d/mojiao/obj/fireblade")->wield();
  carry_object("/d/mojiao/obj/pifeng")->wear();
}


string expell_me(object me)
{
  me=this_player();
  if((string)me->query("family/family_name")=="魔教")
    {
      me->set_temp("betray_mojiao", 1);
      command("hmm");
      command("say 难道本教曾亏待了你？");
      return ("国有国法，家有家规:若是判离师门就必须受罚，你可愿意(agree)？");
    }
  return ("老夫不知！");
}
void init()
{
  add_action("do_agree", "agree");
}
int do_agree(string arg)
{
  if(this_player()->query_temp("betray_mojiao"))
    {
      message_vision("$N答道：在下愿意离教。\n\n", this_player());
      command("say 好！既然这里池小，容不了您这条巨龙，那你就另谋高就吧！");
      this_player()->add("betray/count", 1);
      this_player()->add("betray/mojiao", 1);
//    this_player()->set("combat_exp", this_player()->query("combat_exp")*90/100);
      this_player()->delete_skill("tianmo");
      this_player()->delete_skill("tianxian-sword");            
      this_player()->delete_skill("tianmo-blade");
      this_player()->delete_skill("evil-force");
      if(this_player()->query("JZD_eat")) {this_player()->add("max_mana",-300);}
      else {this_player()->add("max_mana",-random(200));}
      if(this_player()->query("jion_mj"))             {this_player()->set("combat_exp",this_player()->query("combat_exp")*60/100);}
      else {this_player()->set("combat_exp", this_player()->query("combat_exp")*90/100);}
      this_player()->delete("family");
      this_player()->delete("class");
      this_player()->set("title", "魔教叛徒");
      this_player()->set_temp("betray_mojiao", 0);
      this_player()->save();
      return 1;
    }
  return 0;
}

