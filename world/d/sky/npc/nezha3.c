// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// created 4/12/1998 by bbs
#include <ansi.h>

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
  set("max_kee", 1500);
  set("max_gin", 1500);
  set("max_sen", 1500);
  set("force", 2000);
  set("max_force", 2600);
  set("force_factor", 70);
  set("max_mana", 2500);
  set("mana", 2500);
  set("mana_factor", 70);
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
  set("chat_chance_combat",80);
  set("chat_msg_combat",({
  (: cast_spell, "light" :)
}));
  set("inquiry", ([
   "name": "我乃托塔天王三太子哪吒是也。",
   "here": "这里是斩妖台，妖孽受死吧！",
   "rumors": "玉帝敕封家严为降魔大元帅，在下为三坛海会之神，专管降妖除魔。",
   ]));
  setup();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
  carry_object("/d/qujing/jindou/obj/qiang")->wield();
}

void destruct_me (object me)
{
  destruct (me);
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
void die()
{
        object me = this_object();
        object ob = query_temp("my_killer");
      if (ob) { ob->set_temp("nezha_killed",1);
        call_out ("puti_appearing",1,ob);}         
        if( environment() ) {
        message("sound", "\n\n哪吒恶狠狠的叫道：我要到师傅那儿请来九龙神火罩来炼你！
\n\n", environment());
        message("sound", "\n哪吒念动咒语，踏着风火轮飞向乾元山金光洞去了。。。\n\n", environment
());
        }
  load_object("/obj/empty");
  me->move("/obj/empty");
  call_out ("destruct_me",3,me);

}
