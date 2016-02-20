//【蜀山派】mhxy-yushu 2001/2
inherit F_VENDOR_SALE;
void create()
{
        reload("shushan_daboss");   
        set_name("张巧手", ({"zhang qiaozhou", "laoban","boss"}));
        set("age", 42);
        set("gender", "男性");
        set("long","打铁铺的老板，笑眯眯的看着你。\n");
	 set("title", "打铁铺老板");
        set("attitude", "peaceful");
        set("combat_exp", 10000);
        set("shen_type", 1);
	 set("max_force", 200);
	 set("force", 200);
	 set("force_factor", 5);
        set_skill("unarmed", 30);
        set_skill("dodge", 40);
        set_skill("parry", 30);
        set("vendor_goods", ([
               "staff": "/d/shushan/obj/qingyichan",
            "shenzhen": "/d/shushan/obj/shenzhen",
        ]) );
        setup();
        carry_object("/d/obj/cloth/choupao")->wear();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
		call_out("greeting",1,ob);
        }
        add_action("do_vendor_list", "list");
}
void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
        switch( random(1) ) {
                case 0:
                        say( name()+"说道：这位" +
RANK_D->query_respect(ob)
                                + "，要买些什么东西？\n");
                        break;
        }
}

