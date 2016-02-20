#include <ansi.h>

inherit NPC;

void create()
{
   set_name("韦陀尊者", ({ "zunzhe" }) );
   set("long", "这是大名鼎鼎的韦陀尊者，佛门降魔尊者。因为和观音菩萨有过夫妻缘分，
故而协助菩萨开设普陀派，并充当护法尊者。\n");
   set("attitude", "friendly");

   set("max_gin", 1000);
   set("max_kee", 1000);
   set("max_sen", 1000);
   set("max_force", 1000);
   set("force", 1000);
   set("force_factor", 5);
   set("max_mana", 1000);
   set("mana", 1000);
   set("mana_factor", 10);
   set("str", 30);
   set("cor", 30);
   set("cps", 25);

   set("combat_exp", 500000);

   set_skill("staff", 100);
   set_skill("parry", 100);
   set_skill("lunhui-zhang",100);
   set_skill("dodge", 100);
   set_skill("lotusmove",100);
   set_skill("spells",100);
   set_skill("buddhism",100);
   
   map_skill("staff","lunhui-zhang");
   map_skill("parry","lunhui-zhang");
   map_skill("dodge","lotusmove");
   map_skill("spells","buddhism");
   
   set("chat_chance_combat", 40);
   set("chat_msg_combat", ({
      (: cast_spell, "bighammer" :),
      (: cast_spell, "yinshen" :),
        }) );

   setup();

   carry_object("/d/obj/armor/tianjia")->wear();
   carry_object("/d/nanhai/obj/budd_staff")->wield();
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

   message_vision(HIB "\n$N发出一声长求援！\n" NOR, who);       
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

void die()
{
    object ob = this_object();
    object *inv;
    int i;

    inv = all_inventory(ob);
    for(i=0; i<sizeof(inv); i++)
    {
        destruct(inv[i]);
     }
    return ::die();
}
