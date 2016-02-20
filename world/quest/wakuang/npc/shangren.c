// tang.c 唐老板 

#include <ansi.h>

inherit NPC;
//inherit F_DEALER;

//int redeem(string arg);

void create()
{
	set_name("唐男", ({ "tang nan", "tang" }));
	set("title", "商行老板");
	set("shen_type", 0);

	set("gender", "男性");
	set_max_encumbrance(100000000);
	set("age", 35);
	set("str", 100);
	set("long",
		"据说唐男是四川唐家的后代。\n");
	set("no_get_from", 1);

	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_temp("apply/attack", 130);
	set_temp("apply/attack", 130);
	set_temp("apply/damage", 115);

	set("combat_exp", 9000000);
	set("attitude", "friendly");
	
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

/*void init()
{
	add_action("do_sell", "sell");
	add_action("do_value", "value");
}
*/
void die()
{
	message_vision("\n$N死了。\n", this_object());
	destruct(this_object());
}
