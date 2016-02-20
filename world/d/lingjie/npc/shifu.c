// link

inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
	set_name("灵界大师傅", ({ "shifu" }) );
	set("gender", "男性" );
	set("age", 42);
	set("long",
		"这位大师傅正忙着给灵界弟子装饭，忙着数钱。\n");
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set("per",10);
	set("vendor_goods", ([
                __DIR__"obj/rice" : 40,
                __DIR__"obj/baishi" : 20,
                __DIR__"obj/fruitbread" : 20,
                __DIR__"obj/turkey" : 30,
                __DIR__"obj/vege" : 40,
                __DIR__"obj/midvege" : 10,
                __DIR__"obj/leg" : 10,
	]) );
	set_skill("unarmed",50);
	set_skill("dodge",50);
	setup();
	carry_object("d/obj/cloth/linen")->wear();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("get_card", "newcard");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(5) ) {
		case 0:
message_vision("$N对$n说道：兄弟，要什么饭菜？\n",this_object(),ob);
			break;
		case 1:
message_vision("$N望了$n一眼，再一扫锅里的菜，委屈地道：“好像真的有点发臭了……”\n",this_object(),ob);
			break;
		case 2:
message_vision("$N热情的对$n说道：“兄弟，要不要办饭卡？输入“newcard”指令就可以了！”\n",this_object(),ob);
			break;
		case 3:
message_vision("$N热情的对$n说道：“兄弟，要不要给你的饭卡充值？去灵界管理处存款就可以了！”\n",this_object(),ob);
			break;

	}
}
int get_card()
{
	object me=this_player();
	object card;
	if (me->query("get_time")) return notify_fail("大师傅眉头一皱，说道：“你不是已经有一张饭卡了吗？，怎么还要？真是浪费钱！”\n");
	if (me->query("deposit")<100) return notify_fail("大师傅眉头一皱，说道：“你的存款太少了！要至少100块钱才行！”\n");
	card=new("/d/liwu/obj/goldcard");
	card->move(me);
	me->set("deposit",me->query("deposit")*90/100);
	me->set("get_time",time());
	message_vision(CYN"大师傅收取了$N10%的手续费，把一张有"+chinese_number(me->query("deposit")/100)+"\n元钱的饭卡塞到$N手中。\n"NOR,me);
	return 1;
}