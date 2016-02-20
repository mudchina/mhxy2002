// REDGIRL.C
#include <ansi.h>
inherit NPC;
void create()
{       
        set_name("马夫", ({ "mafu" }) );
        set("title", "神剑山庄");
        set("long", "这是一个勤劳的马夫，他的工作就是照顾客人们停在这里的马。\n");
        set("age", 46);
        set("gender", "男性");
        set("attitude", "peaceful");
        set("chat_chance", 10);
        set("chat_msg", ({
         "马夫正在给食槽里拼命的添加饲料。\n",
                        }) );
        setup();
        carry_object(__DIR__"obj/zcloth")->wear();
}
