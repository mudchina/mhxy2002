#include <ansi.h>
#include <login.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("白无常", ({ "bai wuchang","wuchang", "gargoyle" }));
        set("long","一个白衣白净面皮的使者，死白的脸上看不出任何喜怒哀乐。\n");
        set("attitude", "peaceful");
        set("per", 10);
        set("str", 25);
        set("int", 25);
        set("age", 30);
        set("title", "招魂司主");
        set("combat_exp", 120000);
        set("max_gin", 1000);
        set("max_kee", 1000);
        set("max_sen", 1000);
        set("class", "youling");
        set("force", 1500);
        set("max_force", 800);
        set("force_factor", 50);
        set("max_mana", 600);
        set("mana", 1000);
        set("mana_factor", 40);
        set_skill("ghost-steps", 100);
        set_skill("dodge", 100);
        set_skill("unarmed", 100);
        set_skill("parry", 100);
        set_skill("spells", 100);
        set_skill("gouhunshu", 100);
        set_skill("jinghun-zhang", 100);
        set_skill("force", 100);
        set_skill("tonsillit", 100);
        set_skill("stick", 100);
        set_skill("kusang-bang", 100);
        map_skill("stick", "kusang-bang");
        map_skill("parry", "kusang-bang");
        map_skill("spells", "gouhunshu");
        map_skill("dodge", "ghost-steps");
        map_skill("force", "tonsillit");
        map_skill("unarmed", "jinghun-zhang");

         set("chat_msg_combat", ({
         (: exert_function, "powerup" :),
         (: exert_function, "sheqi" :),
         (: exert_function, "recover" :),
         (: cast_spell, "gouhun" :),
        }) );
        setup();
 carry_object("/d/obj/cloth/bai")->wear();
 carry_object("/d/obj/weapon/stick/bang")->wield();
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
void die()
{
message_vision("$N化作尘烟消失了!\n",this_object());
   destruct(this_object());
} 
