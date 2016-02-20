#include <ansi.h>

inherit NPC;

void create()
{
  set_name(HIR"»ğ÷è÷ë"NOR, ({"huo qilin", "qilin"}));
  set("under_water",1);
  set("race", "Ò°ÊŞ");
  set("age", 20);
  set("long", "Ò»Í·Ë«íø·Å¹â£¬»ëÉíÉÁË¸ÕóÕó»ğ¹âµÄÁéÊÛ¡£\n");
  set("combat_exp", 1000000);
  set("daoxing", 1100000);

  set("limbs", ({ "Í·²¿", "ÉíÌå", "Ç°½Å", "áá½Å", "Î²°Í" }) );
  set("verbs", ({ "bite"}));

  set("max_kee", 800);
  set("kee", 800);
  set("max_sen", 900);
  set("sen", 900);

  set_skill("dodge", 150);
  set_skill("parry", 150);
  set_skill("unarmed", 150);

  set("ride/msg", "Æï");
  set("ride/dodge", 60);

  set_temp("apply/dodge", 100);
  set_temp("apply/attack", 100);
  set_temp("apply/armor", 100);

  setup();
}

ÿ

