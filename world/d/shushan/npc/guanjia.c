//shushan2 by yushu@SHXY 2000.12
#include <ansi.h>
inherit NPC;
void create()
{
  set_name("¹Ü¼Ò", ({ "guan jia"}) );
  set("gender", "ÄÐÐÔ");
  set("age", 40);
  set("combat_exp", 10000+random(1000));
  set("attitude", "heroism");
  set("str", 30);
  set("max_kee", 200);
  set("max_gin", 200);
  set("force", 200);
  set("max_force", 200);
  set("force_factor", random(10)+15);
  set_skill("unarmed", 30);
  set_skill("parry", 30);
  set_skill("dodge", 30);
  set_skill("blade", 30);
  setup();
  carry_object("/d/qujing/tianzhu/obj/huapao")->wear();
  carry_object("/d/qujing/tianzhu/obj/longguan")->wear();
}

