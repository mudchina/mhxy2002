//By tianlin@mhxy and elva@mhxy for 2001.9.25

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("张翠山", ({ "zhang cuishan", "zhang" }));
        set("nickname", HIC"武"NOR+HIY"当五"NOR+HIW"侠"NOR);
        set("long",
                "他就是张三丰的最聪明的弟子、武当七侠之五的张翠山。\n"
                "身穿一件干干净净的青布长衫。\n"
                "他不过二十出头年纪，潇洒英俊，一副白马王子派头。\n");
        set("gender", "男性");
        set("age", 25);
        set("attitude", "peaceful");
        set("class", "wudang");
        set("shen_type", 1);
        set("str", 28);
        set("int", 30);
        set("con", 28);
        set("dex", 28);

        set("max_kee", 3000);
        set("max_sen", 2500);
        set("force", 2100);
        set("max_force", 2100);
        set("mana", 2000);
        set("max_mana", 2000);
        set("force_factor", 90);
        set("mana_factor", 90);
        set("combat_exp", 500000);
        set("daoxing", 1200000);
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "sword.ren" :),
        }) );
        set_skill("force", 140);
        set_skill("wudang-force", 140);
        set_skill("dodge", 140);
        set_skill("tiyunzong", 140);
        set_skill("unarmed", 140);
        set_skill("taiji-quan", 140);
        set_skill("parry", 140);
        set_skill("sword", 140);
        set_skill("spells", 140);
        set_skill("wudang-xianfa", 140);
        set_skill("liangyi-jian", 140);
        set_skill("taiji-jian", 140);
        set_skill("literate", 150);

        map_skill("force", "wudang-force");
        map_skill("spells", "wudang-xianfa");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "liangyi-jian");
        map_skill("sword", "liangyi-jian");
	set("chat_chance", 20);
        set("chat_msg", ({
            "张翠山恶狠狠地说道：没有两把刷子，我敢来解剑岩？\n",
            "张翠山仰天叹道：哪个巫师帮我找到素素，我请鸭庄一顿。\n"
        }));

        create_family("武当派", 2, "弟子");

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang1/obj/bluecloth")->wear();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting",2 , ob);
        }
}

void greeting(object ob)
{
        if( (string)ob->query("class")=="yaomo")
        {
            say(CYN"\n\n张翠山脸现怒容：“邪魔外道，吃了豹子胆了，敢强闯武当！”\n\n");
            message_vision("张翠山居高临下，起手一掌，$N只得硬接，身子晃了一下。\n",ob);
            message_vision("对方右手长剑随即递出，$N无法招架，退了一步。\n\n\n"NOR,ob);
            ob->move("/d/wudang1/slxl2");
        }
}

void attempt_apprentice(object ob)
{
        if (ob->query_int() < 30)
        {
                command("say 你的资质将来到不了铁划银钩的境界，收你也是白搭。\n");
                return;
        }
        command("say 好吧，我就收下你了。");
        command("recruit " + ob->query("id"));
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "wudang");
                ob->set("title", "[1;33m武当派[1;37m第[1;36m三[1;37m代弟子[2;37;0m");
}
