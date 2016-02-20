//by swagger
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("老鸨", ({ "lao bao", "lao", "bao" }) );
        set("gender", "女性" );
        set("title", HIR"翠花楼"NOR);
        set("age", 40);
        set("long", 
            "这老鸨就是翠花楼的老板娘了，别看她现在老了，\n据说当年她可是这儿的头号花魁。\n");
        set("str", 25);
        set("dex", 25);
        set("con", 25);
        set("int", 25);
        set("per", 18);
        set("shen_type", 1);

        set_skill("force", 20);
        set("combat_exp", 200);

        set("max_kee", 300);
        set("max_sen", 100);
        set("force", 500);
        set("max_force", 500);

        set("attitude", "friendly");
        set("inquiry", ([
            "name" : "老娘我就是这儿的老板娘。",
            "翠花楼" : "翠花楼可是闻名天下的好去处。",
            "here" : "这儿就是闻名天下的翠花楼了，要不要找个小姐?",
       ]) );

        setup();
        setup();
        set("chat_chance", 8);
        set("chat_msg", ({
                "老鸨着急的说：别看我现在老，当年我可是这儿的头号花魁。\n",
                "老鸨对你说道：我这儿的小姐都是我精心挑选的，要不要给你找一个！\n",
        }) );
        carry_object("/obj/loginload/shoes")->wear();
        carry_object("/obj/loginload/skirt")->wear();
}
void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("wenhou");
                call_out("wenhou", 1, ob);
        }
}

void wenhou(object me)
{
    command("look " + me->query("id"));

    if (me->query("class") =="bonze") {
       command("say 呦，" + RANK_D->query_respect(me) 
                +"也来光顾翠花楼啊。");
       command("say 这位大师，用不用老娘我亲自接待你啊？");
       command("grin");
    }
    if (me->query("gender")=="女性")
 {
       command("say 哎!我这儿可没有男妓，你来干嘛??");
       command("kick " + me->query("id"));
    }
    command("say 楼上楼下的姑娘们快下来啊，有客人来了！");
    }

