#include <ansi.h>

inherit NPC;

void create()
{
   set_name("护法", ({ "hufa" }) );
   set("long", "这是一位方寸山三星洞专门培养来保护初入门弟子的护法也有护山之则。\n");
   set("attitude", "friendly");

   set("max_gin", 1000);
   set("max_kee", 1000);
   set("max_sen", 1000);
   set("max_force", 1000);
  set("force",2000);
  set("force_factor",50);
   set("max_mana", 1000);
   set("mana",3000);
   set("mana_factor",75);
   set("str", 30);
   set("cor", 30);
   set("cps", 25);

   set("combat_exp", 200000);
/*
   set("chat_chance", 15);
   set("chat_msg_combat", ({
     name() + "喝道：孽障！竟敢对？\n"
   }) );
*/
   set_skill("stick", 100);
   set_skill("parry", 100);
   set_skill("qianjun-bang",100);
   set_skill("dodge", 100);
   set_skill("jindouyun",100);
   set_skill("spells",100);
   set_skill("dao",100);
   
   map_skill("stick","qianjun-bang");
   map_skill("parry","qianjun-bang");
   map_skill("dodge","jindouyun");
   map_skill("spells","dao");
   
   set("chat_chance_combat", 40);
   set("chat_msg_combat", ({
      (: perform_action, "stick.qiankun" :),
      (: cast_spell, "light" :),
      (: cast_spell, "dingshen" :),
      (: cast_spell, "thunder" :)
        }) );

   setup();

   carry_object("/d/obj/armor/tianjia")->wear();
   carry_object("/d/lingtai/obj/bang")->wield();
}

int heal_up()
{
   if( environment() && !is_fighting() ) {
     call_out("leave", 1);
     return 1;
   }
   return ::heal_up() + 1;
}

void leave()
{
   message("vision",
     HIY + name() + "说道：阁下现在已经安全，在下就此告辞！\n\n"
     + name() + "化成一道金光，冲上天际消失不见了。\n" NOR, environment(),
     this_object() );
   destruct(this_object());
}

void invocation(object who)
{
   int i;
   object *enemy;

   message_vision(HIB "\n$N发出一声长啸求援！\n" NOR, who);
   message_vision(HIB "\n$N应声而来！\n" NOR, this_object());
   enemy = who->query_enemy();
   i = sizeof(enemy);
   while(i--) {
     if( enemy[i] && living(enemy[i]) ) {
        kill_ob(enemy[i]);
        enemy[i]->kill_ob(this_object());
     }
   }
  set("possessed",who);
   who->remove_all_killer();
   set_leader(who);
}

void set_hushan()
{
  set("max_force",3000);
  set("force",6000);
  set("max_mana",3000);
  set("mana",6000);
  set("force_factor",150);
  set("mana_factor",150);
  set("combat_exp",1500000);
  
  set_skill("spells",200);
  set_skill("dao",200);
  set_skill("stick",160);
  set_skill("qianjun-bang",180);
  set_skill("jindouyun",190);
  set_skill("dodge",170);
   command("say 大胆妖孽，竟敢来到方寸山上！");
  set("guard",1);
}

void die()
{
  object killer;

  if(objectp(killer=query_temp("last_damage_from")))
    if(query("guard")){
      command("sigh");
      command("say 不是我不努力，实在是力有未及呀！");
      killer->set_temp("success_hufa",1);
    }
  message_vision("$N化作尘烟消失了!\n",this_object());
   destruct(this_object());
}
