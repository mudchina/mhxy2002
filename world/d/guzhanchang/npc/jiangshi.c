inherit NPC;
#include <ansi.h>
int big_blowing();
void create()
{
 set_name("僵尸", ({ "jiang shi", "shi" }) );
 set("gender", "雄性");
 set("age", 1500);
 set("long",
"这是古战场的僵尸 ！\n");
 set("str", 48);
 set("cor", 52);
 set("cps", 22);
 set("max_kee", 15000);
 set("max_gin", 15000);
 set("max_sen", 15000);
 set("force",4500);
 set("max_force",4500);
 set("mana",4500);
 set("max_mana",4500);
 set("force_factor",50);
 set_skill("parry",300);
 set_skill("dodge",300);
        set_skill("lingfu-steps",300);
 set_skill("unarmed",200);
 set_skill("yinfeng-zhua",300);
 map_skill("unarmed","yinfeng-zhua");
 map_skill("parry","yinfeng-zhua");
        map_skill("dodge","lingfu-steps");
 set("attitude", "aggressive");
 set("combat_exp", 2000000+random(2000000));
 setup();
  carry_object("/d/guzhanchang/obj/yundan");
}

