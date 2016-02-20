inherit NPC;
void create()
{
        set_name("老人", ({ "old man", "man" }) );
          set("title", "满脸风霜的");
        set("gender", "男性");
        set("age", 74);
        set("long",
"这是一个满脸风霜的老人，但他双目有神，太阳穴高高隆起！\n"
               ); 

        set("attitude", "peaceful");
        set("combat_exp", 1500000);
        set("chat_chance", 1);
        set("chat_msg", ({
                "老人叹道:好久没有人和老夫坐下来下这盘残棋了。\n",
        }) );
        set("force", 4000);
        set("max_force", 2200);
        set("force_factor", 50);
        set_skill("dodge", 500);
              set_skill("literate", 500);

             
	        setup();
	carry_object("/d/obj/cloth/linen")->wear();
}
