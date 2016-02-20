// 神话世界·西游记·版本４．５０
 
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("猪头李靖", ({"li jing","li" }));
        set("title", "托塔天王");
        set("gender", "男性");
        set("long", "他就是陈塘关总兵,哪吒之父,号称「托塔天王」的李靖.\n");
        set("attitude", "peaceful");
        set("combat_exp", 1500000);
        set("age", 45);
        set("per", 30);
        set("str", 30);
        set("int", 30);
        set("cor", 30);
        set("cps", 30);
        set("con", 30);
   set("class", "xian");
  // set("rank_info/respect", "李靖");
   set("max_kee", 2500);
   set("max_sen", 2500);
   set("force", 3000);
   set("max_force", 2000);
   set("force_factor", 80);
   set("max_mana", 3000);
   set("mana", 5000);
   set("mana_factor", 100);

   set_skill("spells", 200);
   set_skill("buddhism", 200);
   set_skill("force", 160);
  set_skill("huntian-qigong", 180);
   set_skill("parry", 160);
   set_skill("dodge", 160);
   set_skill("lotusmove", 160);
   set_skill("unarmed", 160);
   set_skill("yinfeng-zhua", 160);
   set_skill("sword", 160);
   set_skill("sanqing-jian", 160);

   map_skill("spells", "buddhism");
   map_skill("force", "huntian-qigong");
   map_skill("dodge", "lotusmove");
   map_skill("unarmed", "yinfeng-zhua");
   map_skill("sword", "sanqing-jian");
  set("chat_chance_combat", 75);
  set("chat_msg_combat", ({
  (: exert_function, "zhangqi" :),
  (: cast_spell, "bighammer" :)
}));



}




