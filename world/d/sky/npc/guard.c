// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// tian-bing.c
 
inherit NPC;
 
void create()
{
 
      set_name("护殿天兵", ({"bing"}));
        set("gender", "男性" );
        set("long","一个身批金甲,手执大锤的天兵。\n正狠巴巴的瞪着你．\n");
        set("attitude","aggressive");
        set("age", 19+random(15));
        set("str", 25);
        set("int", 20);
        set("per", 15+random(10));
        set("combat_exp", 1000000);
   set("max_kee", 2000);
   set("max_sen", 2000);
   set("force",2000);
   set("max_force",1500);
  set("force_factor", 150);
   set("mana",2000);
   set("max_mana", 1500);
   set("mana_factor", 150);
  set_skill("force",150);
  set_skill("lotusforce",150);
  set_skill("unarmed",150);
  set_skill("dodge",150);
  set_skill("parry",150);
  set_skill("spells",150);
  set_skill("dao",150);
  set_skill("huntian-hammer",150);
  set_skill("lotusmove",150);
  set_skill("jienan-zhi",150);
  map_skill("spells","dao");
  map_skill("parry","huntian-hammer");
  map_skill("hammer","huntian-hammer");
  map_skill("unarmed","jienan-zhi");
  map_skill("force","lotusforce");
  map_skill("dodge","lotusmove");
 // set("chat_chance_combat",50);
 // set("chat_msg_combat", ({
 // (: cast_spell, "light" :),
 // }));
        setup();
                carry_object("/d/obj/weapon/hammer/bahammer")->wield();
        carry_object("/d/obj/armor/jinjia")->wear();
}
 
