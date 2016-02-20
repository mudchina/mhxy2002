// worker.c


inherit NPC;


void create()

{

        set_name("厨师", ({ "cook" }) );

        set("gender", "男性" );

        set("age", 42);

        set("long", "这是一个胖胖的的厨师. \n");


       set("combat_exp", 100000);

        set("attitude", "heroism");

        set_skill("unarmed", 30);

        set_skill("parry", 30);

	set_skill("dodge", 30);

	set_skill("sword",30);

        set("chat_chance", 35);

        set("chat_msg",
        ({
 "厨师辛苦地做了个菜。\n",
              }) );


	setup();

	add_money("silver", 300);

        carry_object(__DIR__"obj/zcloth")->wear();}
