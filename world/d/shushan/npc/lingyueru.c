//Cracked by Roath

// ludongbin.c...weiqi, 98.02.24.

string give_book();

inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("林月如", ({ "lin yueru", "lin", "yueru" }));
        set("title","蜀山派弟子");
        set("long", 
"刁蛮少女贵千金，比武招亲动芳心。\n");
        set("gender", "女性");
        set("age", 16);
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 40);
        set("con", 30);
        set("per", 30);
        set("kee", 2200);
        set("max_kee", 2200);
        set("sen", 1600);
        set("max_sen", 1600);
        set("force", 3000);
        set("max_force", 3000);
        set("mana", 3000);
        set("max_mana", 3000);
        set("force_factor", 60);
        set("mana_factor", 60);

        set("combat_exp", 1800000);
        set("daoxing", 2500000);

        set_skill("force", 150);
        set_skill("dodge", 160);
        set_skill("parry", 140);
        set_skill("whip", 180);
        set_skill("sword", 180);
        set_skill("canxin-jian", 202);
        set_skill("shushan-force", 201);
        set_skill("xianfeng-spells",120);
        set_skill("literate", 80);
        set_skill("yirubian",200);
        set_skill("taoism", 100);
        set_skill("zuixian-steps", 220);
        set_skill("xianfeng-spells",120);
        map_skill("spells", "xianfeng-spells");
        map_skill("force", "shushan-force");
        map_skill("dodge", "zuixian-steps");
        map_skill("parry", "canxin-jian");
        map_skill("sword", "canxin-jian");
        map_skill("whip", "snowwhip");
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
                (: perform_action, "sword","xiangsi" :),
                (: exert_function, "huti" :),
        }) );

        set("inquiry", ([
                "道德经" : (: give_book :),              
                "jing" : (: give_book :),
        ]) );

        set("no_book", 0);

        setup();
        create_family("蜀山派", 5, "未入门弟子");
        carry_object("/d/obj/cloth/xianpao")->wear();
        carry_object("/d/obj/weapon/sword/changjian")->wield();
}

void attempt_apprentice(object me)
{
me =this_player();
if ( !((string)me->query("gender")=="女性"))
                {
        command("shake");
        command("say 我只收女徒，这位" +
 RANK_D->query_respect(me) + "还是另请高就吧。\n");
           return ;
}
if (me->query("nyj/shushan") != "done")
{
command("say 我现在还在担心着灵儿妹子……");
return 0;
}
command("pat"+me->query("id"));
command("say 既然" + RANK_D->query_respect(me) +"心向蜀山，那我只好收你为徒。\n");
command("recruit" + me->query("id") );
        return ;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "xiake");
}

string give_book()
{
        object me = this_player();

        if( query("no_book") == 0 )
        {
                carry_object("/d/shushan/obj/jing");
                     command("give jing to " + me->query("id"));
                set("no_book", 1);
                //return "林月如说道：好！既然是有心人，那我就给你吧。\n";
                return "好！既然是有心人，那我就给你吧。\n";
        }
        else
        {
                //return "林月如说道：太不巧了，我已经送人了。\n";
                return "太不巧了，我已经送人了。\n";
        }

}

