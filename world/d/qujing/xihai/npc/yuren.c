#include <ansi.h>

inherit NPC;

void create()
{
  string dir;

  set_name("鱼人", ({"yu ren", "yu", "ren"}));
  set("title", "百炼成钢");
  set("gender", "男性");
  set("age", 1200+random(600));
  set("con", 20);
  set("cor", 20);
  set("int", 20);
  set("per", 20);
  set("long", "这是一个用来练功的鱼人。\n");
  set("attitude", "peaceful");
  set("combat_exp", 1200000);
  set_skill("dodge", 200);
  set_skill("parry", 200);
  set_skill("force", 200);
  set_skill("spells", 200);
  set_skill("unarmed", 200);
  set_skill("whip", 200);
  set("max_gin", 4500);
  set("max_kee", 4500);
  set("max_sen", 4500);
  set("force", 4500);
  set("max_force", 4500);
  set("mana", 4500);
  set("max_mana", 4500);
  setup();

}

void equalize_gifts (object ob, object me)
{
  ob->set("con",(me->query("spi")+me->query("con"))*1/1);
  ob->set("cor",(me->query("kar")+me->query("cor"))*1/1);
  ob->set("cps",(me->query("per")+me->query("cps"))*1/1);
  ob->set("int",(me->query("str")+me->query("int"))*1/1);
}


