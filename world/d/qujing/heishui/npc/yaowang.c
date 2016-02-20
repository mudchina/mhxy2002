//EDIT BYE LUCAS
inherit NPC;

void create()
{
  set_name("鼋龙", ({ "yuan long", "long"}));
  set("title", "黑水妖龙");   
  set("long", "一位身着金甲，手提钢鞭的鼋龙。\n");
  set("gender", "男性");
  set("age", 50); 
  set("attitude", "heroism");
  set("per", 10);
  set("max_kee", 2500);
  set("max_gin", 1000);
  set("max_sen", 2000);
  set("force", 5000);
  set("max_force", 2500);
  set("force_factor", 100);
  set("max_mana", 3000);
  set("mana", 6000);
  set("mana_factor", 180);
  set("combat_exp", 2500000);
  set_skill("spells", 180);
  set_skill("seashentong", 180);
  set_skill("unarmed", 150);
  set_skill("mace", 150);
  set_skill("dragonfight", 150);
  set_skill("dodge", 160);
  set_skill("dragonstep", 160);
  set_skill("wusi-mace", 170);
  set_skill("parry", 160);
  set_skill("force", 150);
  set_skill("dragonforce", 150);
  map_skill("spells", "seashentong");
  map_skill("unarmed", "dragon-step");
  map_skill("dodge", "dragonstep");
  map_skill("force", "dragonforce");
  map_skill("mace", "wusi-mace");
        set("chat_msg_combat", ({
                (: cast_spell, "breathe" :),
        }) );

  setup();
  carry_object("/d/obj/armor/jinjia")->wear();
  carry_object("/d/obj/weapon/mace/copperjian.c")->wield();
}

int accept_fight (object ob)
{
  ob->apply_condition ("killer",100);
  kill_ob (ob);
  return 1;
}

void kill_ob (object ob)
{
  set_temp("no_return",1);
  set_temp("my_killer",ob);
  ::kill_ob(ob);
}

void unconcious()
{
  object ob = query_temp("my_killer");
  object me = this_object();

  if (ob)
  {
    ob->set_temp("killlong",1);
    call_out ("aoshun_appearing",1,ob);
  }
  message_vision ("\n$N惨叫一声，倒在地上，现了原形，原来是一条黑身鼋龙。\n",
                  me);
  message_vision ("摩昂大喝一声：孽畜，跟我回去见父王。说完拱手为礼，押解鼋龙自水路回归西海。\n\n",
                  me);
  load_object("/obj/empty");
  me->move("/obj/empty");
  call_out ("destruct_me",3,me);
}

void aoshun_appearing (object who)
{
  object aoshun = new ("/d/qujing/xihai/npc/aoshun");

  aoshun->announce_success (who);
  destruct (aoshun); 
}

void destruct_me(object me)
{
  destruct(me);
}

void die()
{
  unconcious();
}

