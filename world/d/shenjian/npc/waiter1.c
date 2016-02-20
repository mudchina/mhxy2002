// LLY@FYSY // waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("谢八", ({ "waiter" }) );
	set("gender", "男性" );
	set("age", 19);
	set("long",
		"他叫谢八，是这个客栈的小二，正在忙碌著，口中却不时嘀咕着什么。\n");
	set("combat_exp", 650000);
	set("attitude", "friendly");
	set("rank_info/respect", "小二哥");
	setup();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(4) ) {
		case 0:
			say( "谢八说道：这位" + RANK_D->query_respect(ob)
				+ "，住店吗？\n");
			break;
		case 1:
			say( "谢八用毛巾抹了抹手，口中嘀咕道：这位" + RANK_D->query_respect(ob)
				+ "也要去和三少爷比剑吗？。\n");
			break;
		case 2:
			say( "谢八小声说道：这位" + RANK_D->query_respect(ob)
				+ "看样子是有去无回的了。\n");
			break;
		case 3:
			say( "店小二说道：这位" + RANK_D->query_respect(ob)
				+ "，要打尖儿，还是住店？\n");
			break;
	}
}
