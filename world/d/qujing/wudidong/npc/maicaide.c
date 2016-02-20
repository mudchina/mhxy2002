// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// waiter.c

inherit F_VENDOR_SALE;
void create()
{
        set_name("蔡大嫂", ({ "cai dasao", "cai", "dasao", "da sao" }) );
        set("title", "和蔼的");
        set("gender", "女性" );
        set("age",32);
        set("long", "蔡大嫂正对你笑着呢,手里还不停的摆弄着蔬菜。\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set("per",25);
        set("vendor_goods", ([
        "guaguoshucai" : "/d/obj/food/sucai",
         "guaguoshucai" : "/d/obj/food/sucai",
   ]));
   setup();
}
void init()
{
   object ob;
   ::init();
   if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
   add_action("do_vendor_list", "list");
}
void greeting(object ob)
{
   if( !ob || environment(ob) != environment() ) return;
   say("蔡大嫂说道：这位" + RANK_D->query_respect(ob)
     +"，请随便看，随便看,新鲜的瓜果蔬菜.\n");
}
