//FY3@linxue
#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "比武大会接待使"NOR, ({ "waiter" }) );
        set("gender", "男性" );
        set("age", 22);
        set("int", 30);
        set("long","负责接待前来的武林人士的接待使。\n");
        set("attitude", "peaceful");
        set_skill("unarmed", 300);
        set_skill("changquan", 300);
        set_skill("literate", 300);
        set_skill("force", 300);
        set_skill("dodge",300);
        set_skill("parry",300);
        map_skill("unarmed", "changquan");
        set("combat_exp", 9000000);
        setup();
        carry_object("/d/city/obj/cloth")->wear();
        carry_object("/d/obj/weapon/sword/changjian")->wield();
}

void die()
{
}
