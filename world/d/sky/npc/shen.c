/* <SecCrypt CPL V3R05> */

// created 12/18/1997 by snowcat

inherit NPC;

void create()
{
  set_name("巨灵神", ({ "juling shen","shen" }));
  set("title", "先锋大将");
  set("gender", "男性" );
  set("long","托塔李天王帐下先锋大将，膀阔腰圆，力大无穷。\n");
  set("age",40);
  set("title", "先锋大将");
        set("str", 100);
        set("int", 20);
        set("con", 30);
        set("spi", 20);
        set("per", 45);
        set("class", "xian");
        set("attitude", "aggressive");
        set("bellicosity", 5000);
        set("combat_exp", 950000);
        set("max_kee", 1200);
        set("max_sen", 1000);
        set("force",1400);
        set("max_force",1400);
        set("force_factor", 60);
        set("mana", 1500);
        set("max_mana", 800);
        set("mana_factor", 40);

        set("eff_dx", 400000);
        set("nkgain", 400);

        set("mana_factor", 40);
        set_skill("unarmed",150);
        set_skill("dodge",100);
        set_skill("parry",170);
        set_skill("axe", 170);
        set_skill("force", 100);
        set_skill("spells", 100);
        set_skill("changquan", 150);
        set_skill("sanban-axe", 150);
        set_skill("baguazhou", 100);
        set_skill("moshenbu", 100);
        set_skill("lengquan-force", 150);
   map_skill("unarmed", "changquan");
   map_skill("force", "lengquan-force");
   map_skill("spells", "baguazhou");
   map_skill("axe", "sanban-axe");
   map_skill("parry", "sanban-axe");
   map_skill("dodge", "moshenbu");
  set("chat_chance_combat",90);
  set("chat_msg_combat", ({
  (: perform_action, "sanban" :),
}));
        setup();
        carry_object("/d/obj/armor/tongjia")->wear();
   carry_object("/d/obj/weapon/axe/huafu")->wield();
}
void destruct_me (object me)
{
  destruct (me);
}

void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");

  if (ob)
  {
    ob->set_temp("obstacle/shen_killed",1);
    call_out ("li_appearing",1,ob);
  }
  message_vision ("巨灵神倒拖着斧子,败回自家营中。\n",me);
  load_object("/obj/empty");
  me->move("/obj/empty");
  call_out ("destruct_me",3,me);
}

void li_appearing (object who)
{
  object li = new ("/d/sky/npc/li");

  li->announce_success (who);
  destruct (li);
}

void unconcious ()
{
  die ();
}

int accept_fight(object ob)
{
  ob->apply_condition("killer", 100);
  kill_ob(ob);
  return 1;
}

void kill_ob (object ob)
{
  object me = this_object();

  set_temp("my_killer",ob);
  ::kill_ob(ob);
}
