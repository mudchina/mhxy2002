// 赛亚人族 by Calvin

inherit NPC;

void create()
{
        set_name("赛亚人", ({ "sai ya", "sai", "ya","man","woman"}));
        if(random(10)<7)
            set("gender", "男性" );
        else
            set("gender", "女性" );
        set("age", 15+random(50));
        set("long",
                "这是一种未知人种。\n");
        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :)
        }));

        set("combat_exp", 10000+random(10000000));
        set("daoxing", 10000+random(10000000));
      set("attitude", "aggressive");
        set_skill("dodge", 1000);
        set_skill("unarmed", 1000);
        setup();
//         carry_object("/obj/cloth")->wear();
}
