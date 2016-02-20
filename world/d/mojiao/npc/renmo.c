//master2.c
//modify by ken
inherit NPC;
inherit F_MASTER;
void create()
{
  set_name("人魔老人", ({ "lao ren", "tian", "mo", "tianmo", "ren", "master", "shifu" }));
  set("title", "人魔堂堂主");
  set("gender", "男性");
  set("age", 53);
  set("str", 30);
  set("per", 30);
  set("int", 40);
  set("cor", 90);
  set("cps", 90);
  set("long", "人魔老人是现任教主的师叔，也是教中三大堂主之一。\n");
  set("combat_exp", 2400000);
  set_skill("literate", 170);
  set_skill("blade", 180);
  set_skill("force", 180);
  set_skill("dodge", 200);
  set_skill("parry", 180);
  set_skill("spells", 180);
  set_skill("unarmed", 180);
  set_skill("huolong-zhang", 180);
  set_skill("dimo-steps", 190);
  set_skill("tianmo-blade", 180);
  set_skill("evil-force", 180);
  set_skill("unarmed", 180);
  set_skill("tigerfight", 190);
  set_skill("tianmo",180);
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
  create_family("魔教", 1, "堂主");
  set("chat_chance_combat", 60);
  set("chat_msg_combat", ({
                (: perform_action, "blade", "tiandirenmo" :),
  }) );

  setup();
  carry_object("/d/mojiao/obj/fireblade")->wield();
  carry_object("/d/mojiao/obj/armor")->wear();
}


