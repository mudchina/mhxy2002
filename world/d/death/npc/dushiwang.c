//puti.c
//inherit NPC;
inherit "/d/dntg/hell/wang.c";
#include <ansi.h>
inherit F_MASTER;

void create()
{
       set_name("¶¼ÊÐÍõ", ({"dushi wang", "wang", "dushi"}));
       set("title", HIB"Òõ¼ä"HIY"Ê®ÍõÖ®"NOR);
       set("gender", "ÄÐÐÔ");
	set("class", "youling");
       set("age", 100);
       set("attitude", "friendly");
       set("shen_type", 1);
       set("per", 30);
        set("int", 30+random(5));
       set("max_kee", 1000);
       set("max_gin", 1000);
       set("max_sen", 1000);
       set("force", 1150);
       set("max_force", 1000);
       set("force_factor", 35);
       set("max_mana", 1000);
       set("mana", 1000);
       set("mana_factor", 40);
  set("combat_exp", 1500000);
  set("daoxing", 2500000);

       set_skill("unarmed", 140);
       set_skill("dodge", 140);
       set_skill("parry", 140);
        set_skill("spells", 140);
        set_skill("force", 140);
        set_skill("gouhunshu", 100);
        set_skill("tonsillit", 100);
        map_skill("force", "tonsillit");
        map_skill("spells", "gouhunshu");

create_family("ÑÖÂÞµØ¸®", 1, "ÄãºÃ");
setup();

        carry_object("/d/obj/cloth/mangpao")->wear();
}

ÿ
