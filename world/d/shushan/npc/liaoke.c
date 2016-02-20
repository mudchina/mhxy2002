//shushan2 by yushu 2000.12
inherit NPC;
void create()
{
	set_name("聊客", ({ "liaoke", "ke"}));
	if(random(10)<7)
	    set("gender", "男性" );
	else
	    set("gender", "女性" );
	set("age", 15+random(50));
	set("long",
		"无事不做专门聊天的人。\n");
	set("chat_chance", 40);
       set("combat_exp", 600+random(400));
	set("attitude", "friendly");
	set_skill("dodge", 10);
	set_skill("unarmed", 10);
	setup();
	carry_object("/obj/cloth")->wear();
	add_money("silver", 3+random(20));
}

