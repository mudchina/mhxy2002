// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */

inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
object flower;

void create()
{
       set_name("卖花女", ({"maihua nu","nu","girl"}));
       set("gender", "女性");
       set("combat_exp", 1000);
       set("age", 26);
       set("per", 14);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("unarmed", 10);
        set("vendor_goods", ([
                "flower": "/d/city/obj/flower",
        "hualan": "d/xuyi/obj/hualan",
        "rose": "/d/obj/flower/hua",
        "rose999": "/d/obj/flower/rose999",

        ]) );
       setup();

       carry_object("/d/obj/cloth/skirt")->wear();
       carry_object("/d/obj/cloth/shoes")->wear();
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
        add_action("do_buy", "buy");
}

void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
        switch( random(3) ) {  // 1/3 chance to greet.
            case 0 : command("say 现在的花可真是少呀！"); break;
        }
}

int do_buy(string what)
{
    int have_money, need_money = 30000;
    object me = this_player();
    if(what != "flower") return 0;
    if(!flower) flower = new("/d/city/obj/flower");
    if(have_money = me->can_afford(need_money)) {
        if(have_money == 2) {
            tell_object(me, "你没有足够的零钱，而银票又没人找得开。\n");
            return 1;
        }
        me->pay_money(need_money);
        message_vision("$N向卖花女买下一朵"+flower->query("name")+"。\n", me);
        flower->move(me);
        flower=0;
    }
    else
        tell_object(me, "你的钱不够。\n");
    return 1;
}

int do_list(string arg)
{
    object who = this_player();
    if(!flower) flower = new("/d/city/obj/flower");
    tell_object(who,"你可以购买下列这些东西：\n"+
flower->query("name")+"(flower)                       ：三两黄金\n"+
GRN+"竹编花篮(hualan)"+NOR+"                     ：五十两银子\n"+    
HIR+"红玫瑰"+NOR+"(rose)                         ：五十两银子\n"+
HIB+"九百九十九朵玫瑰"+NOR+"(rose999)            ：六十两银子\n" 
                );  
 return 1;
}

