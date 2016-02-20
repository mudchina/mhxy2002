// LLY@FYSY 
// worker.c


inherit NPC;


void create()

{

        set_name("谢五", ({ "xiewu" }) );

        set("gender", "男性" );
        set("title", "神剑山庄帐房先生");


       set("age", 32);

        set("long", "这是一个胖胖的先生，他是庄外谢家村客栈小二谢八的哥哥。\n自从谢掌柜调离帐房后，就由他来管理帐房了. \n");


       set("combat_exp", 1000000);

        set("attitude", "friendly");

        set_skill("unarmed", 130);

        set_skill("parry", 130);

	set_skill("dodge", 130);

	set_skill("sword",130);

        set("chat_chance", 15);

        set("chat_msg",
        ({
 "谢五打了个哈哈，又拿起手中的旱烟抽了起来。\n", 
             "谢五打了打算盘，口中嘀咕着什么。\n", 
        }) );


	setup();

	   carry_object(__DIR__"obj/zcloth")->wear();
}
