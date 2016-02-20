//By tianlin@mhxy for 2001.9.25

#include <command.h>
#include <dbase.h>
#include <origin.h>
#include <ansi.h>

inherit NPC;

void create()
{
        set_name(YEL"大黄牛"NOR, ({ "cow" }));
        set("long","一头大黄牛。\n");
        set("race", "野兽");
        set("age", 5);
        set("int", 30);
        set("ridable", "1");
        set("kee", 300);
        set("max_kee", 300);
        set("sen", 100);
        set("max_sen", 100);
        set("combat_exp",50000);
        set("attitude", "peaceful");

        set("limbs", ({ "头部", "腹部", "尾巴","后腿","前腿" }) );
        set("verbs", ({ "bite","hoof" }) );
        set_temp("apply/attack", 50);
        set_temp("apply/armor", 15);
        set_temp("apply/damage", 25);

        setup();
}

