// REDGIRL.C
#include <ansi.h>
inherit NPC;
void create()
{       
        set_name("侍女", ({ "shinu" }) );
        set("title", "神剑山庄");
        set("long", "这是一个美丽清纯的少女。\n");
        set("age", 16);
        set("gender", "女性");
        set("attitude", "peaceful");
        set("chat_chance", 10);
        set("chat_msg", ({
         "侍女冲着你笑了笑，露出两个迷人的小酒窝。\n",
	(: random_move :),
                        }) );
        setup();
        carry_object(__DIR__"obj/ncloth")->wear();
}
