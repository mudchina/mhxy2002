// by happ@YSZZ 

inherit NPC;

void create()
{
       set_name("店小二", ({"xiao er","xiaoer","xiao","waiter","er"}));
       set("gender", "男性");
       set("combat_exp", 1000);
       set("age", 26);
       set("per", 14);
       set("attitude", "friendly");
       set_skill("unarmed", 10);

       setup();

       carry_object("/d/obj/cloth/linen")->wear();
       add_money("silver", 1);

}


void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_list", "list");
        add_action("do_buy","buy");
}

void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
        say( name()+"笑咪咪地说道：这位" +RANK_D->query_respect(ob)
                                + "，星空战斗鸡可有趣了，买一只吧！\n");
}

int do_list()
{
        write("你可以购买下列这些东西：\n");
        write("星空战斗鸡(zhandou ji)        ：十两黄金\n");
        return 1;
}

int do_buy(string arg)
{
        object ob = this_player();
        object gold;

        object hen = new(__DIR__"hen");

        gold = present("gold_money",ob);

        if( present("zhandou ji",ob) )
                return notify_fail("你不是有星空战斗鸡吗？\n");

                
        if( !gold)
                return notify_fail("你身上没有金子。\n");

        if( gold->query_amount() < 10 )
                return notify_fail("你的钱不够！\n");
        if( !arg || arg !="zhandou ji")
                return notify_fail("你要买什么?\n");
        hen->set("owner",ob->query("id") );
        hen->init_data(ob);
        hen->move(ob);
        write("你向小二买了一个星空战斗鸡。\n");
        gold->add_amount(-10);
        return 1;
}
        
        
