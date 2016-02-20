// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit NPC;

void create()
{
  set_name("哪吒", ({ "nezha santaizi", "nezha", "santaizi" }));
  set("title", "三坛海会之神");
  create_family("陷空山无底洞", 2, "弟子");
  set("class", "xian");
  set("long", "一位唇红齿白的美少年。\n");
  set("gender", "男性");
  set("age", 16);
  set("attitude", "heroism");
  set("rank_info/respect", "小太子");
  set("rank_info/rude", "乳臭未干的小儿");
  set("per", 40);
  set("str", 30);
  set("cor", 40);
  set("int", 40);
  set("spi", 40);
  set("cps", 40);
  set("kar", 40);
  set("max_kee", 3000);
  set("max_gin", 3000);
  set("max_sen", 3000);
  set("force", 2600);
  set("max_force", 2600);
  set("force_factor", 100);
  set("max_mana", 2700);
  set("mana", 2700);
  set("mana_factor", 80);
  set("combat_exp", 1200000);
  set_skill("spells", 180);
  set_skill("dao", 180);
  set_skill("unarmed", 170);
  set_skill("yinfeng-zhua", 170);
  set_skill("dodge", 180);
  set_skill("lingfu-steps", 170);
  set_skill("parry", 190);
  set_skill("force", 180);
  set_skill("huntian-qigong", 170);
  set_skill("spear", 170);
  set_skill("huoyun-qiang", 150);
  set_skill("blade", 170);
  set_skill("sword", 160);
  map_skill("spells", "dao");
  map_skill("unarmed", "yinfeng-zhua");
  map_skill("spear", "huoyun-qiang");
  map_skill("parry", "huoyun-qiang");
  map_skill("dodge", "lingfu-steps");
  map_skill("force", "huntian-qigong");
  set("chat_chance_combat",60);
  set("chat_msg_combat",({
  (: cast_spell, "light" :)
 }));
  setup();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
  carry_object("/d/qujing/jindou/obj/qiang")->wield();
  if ("/d/obj/fabao/huntian-ling"->in_mud())
    carry_object("/d/obj/fabao/huntian-ling");
  else
    carry_object("/d/obj/fabao/huntian-fake");
  if ("/d/obj/fabao/qiankun-quan"->in_mud())
    carry_object("/d/obj/fabao/qiankun-quan");
  else
    carry_object("/d/obj/fabao/qiankun-fake");
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
    ob->set_temp("obstacle/nezha_killed",1);
    call_out ("li_appearing",1,ob);
  }
  message_vision ("哪吒眼见不敌,虚晃一枪,乘风火轮逃回自家营中。\n",me);
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
