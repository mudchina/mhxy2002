// zhujia.c 铸甲房
// 星星lywin 2000/9/2 

#include <ansi.h>
inherit ROOM;
int do_zhujia(string arg);

 void create()
{
        set("short", "龙泉酒店素食房");
        set("long", @LONG
这是一间龙泉酒店素食房！四周都是乱七八糟的素食，人们
把种出的的蔬菜在这儿烧好以后就是各种上好的菜。
LONG
        );

        set("exits", ([
                "west" : __DIR__"jiujia",
                "east" : __DIR__"shaocaiyu",
        ]));
        set("no_fight",1);
        set("no_beg",1);
        set("no_steal",1);
        setup();
}

void init()
{
        add_action("do_zhujia","shaocai"); 
        add_action("do_quit","quit");
        add_action("do_quit","exit");
        add_action("do_quit","exercise");
        add_action("do_quit","dazuo");
        add_action("do_quit","exert");
        add_action("do_quit","learn"); 
        add_action("do_quit","yun");
        add_action("do_quit","xue");
        add_action("do_quit","respirate");
        add_action("do_quit","tuna"); 
        add_action("do_quit","fight");
        add_action("do_quit","hit");
        add_action("do_quit","kill");
        add_action("do_quit","perform");
        add_action("do_quit","persuade");
        add_action("do_quit","quanjia");
        add_action("do_quit","practice");
        add_action("do_quit","lian"); 
        add_action("do_quit","study");
        add_action("do_quit","du");
        add_action("do_quit","teach");
        add_action("do_quit","jiao");
}

int do_zhujia(object ob)
{
        object me,ob1;
        int b1,b2;
        me=this_player();
        b1 = this_player()->query("work/penlen");
        
        if (!(ob = present("big cabbage", this_player())) &&
             !(ob = present("carrot", this_player())) &&
             !(ob = present("small cabbage", this_player())) &&
             !(ob = present("bai he", this_player())) &&
             !(ob = present("mao sun", this_player())) &&
             !(ob = present("ya li", this_player())) &&
             !(ob = present("tao zi", this_player())) &&
             !(ob = present("xi gua", this_player())) )
                return notify_fail("你身上没有材料，如何做菜？\n");
                 
        if ( (int)me->query("jing")<100)
                return notify_fail("你的精力不足，无法做菜。\n");

        if( me->is_busy() )
                return notify_fail("你现在很忙！不能做菜！\n");

        if ( (int)me->query("qi")<100)
                return notify_fail("你的体力不足，无法做菜。\n");

        if ( (int)me->query("neili")<150)
                return notify_fail("你的内力不足，无法做菜。\n");

        message_vision(HIY"$N先将蔬菜放进锅中炒了起来。\n"NOR,me); 
        message_vision(HIY"接着$N再拿出各种调料开始烧菜。\n"NOR,me); 
        message_vision(HIY"不一会儿！一盘烧好的小菜摆在了$N的面前。\n"NOR,me); 
        message_vision(HIY"$N的经验和潜能增加了。\n"NOR,me); 
        me->add("combat_exp",30+random(20));
        me->add("potential",15+random(5));
        me->add("jing",-20);
        me->add("qi",-20);
        me->add("neili",-20);
        me->start_busy(5); 

        if ( ob->query("name") =="大青菜" )
        {
        destruct(ob);             
        ob1=new(__DIR__"eat/cai1");
        ob1->set_name(GRN + this_player()->name()+"烧的炒青菜"+NOR,({"cai1"}));
//        b2 = ob1->query("armor_prop/armor");
//        b2 = b1/10;
//        if ( b2 < 10) b2 = 10;
//        if ( b2 > 30) b2 = 30;
//        ob1->set("armor_prop/armor", b2);
        ob1->set("value", 2000);
        ob1->move(me);
        me->add("work/penlen", 1);       
        return 1;
        }
        if ( ob->query("name") =="胡萝卜" )
        {
        destruct(ob);             
        if ( b1 < 20 ) 
        {
        me->add("work/penlen",1);
        message_vision(HIY"由于你烹饪技术太低，菜根本不能吃！\n"NOR,me); 
        return notify_fail("由于你烹饪技术太低，菜根本不能吃！\n");
        }
        ob1=new(__DIR__"eat/cai1");
        ob1->set_name(CYN + this_player()->name()+"烧的东北炒萝卜"+NOR,({"cai2",}));
//        b2 = ob1->query("armor_prop/armor");
//        b2 = b1/8;
//        if ( b2 < 20) b2 = 20;
//        if ( b2 > 50) b2 = 50;
//        ob1->set("armor_prop/armor", b2);
        ob1->set("value", 5000);
        ob1->move(me);
        me->add("work/penlen", 1);       
        return 1;
        }
        if ( ob->query("name") =="小白菜" )
        {
        destruct(ob);             
        if ( b1 < 100 )
        {
        me->add("work/penlen",1);
        message_vision(HIY"由于你烹饪技术太低，菜根本不能吃！\n"NOR,me); 
        return notify_fail("由于你烹饪技术太低，菜根本不能吃！\n");
        }
        ob1=new(__DIR__"eat/cai1");
        ob1->set_name(HIW + this_player()->name()+"烧的炒白菜"+NOR,({"cai3"}));
//        b2 = ob1->query("armor_prop/armor");
//        b2 = b1/6;
//        if ( b2 < 30) b2 = 30;
//        if ( b2 > 80) b2 = 80;
//        ob1->set("armor_prop/armor", b2);
        ob1->set("value", 8000);
        ob1->move(me);
        me->add("work/penlen", 1);       
        return 1;
        }
        if ( ob->query("name") =="百合" )
        {
        destruct(ob);             
        if ( b1 < 220 )
        {
        me->add("work/penlen",1);
        message_vision(HIY"由于你烹饪技术太低，菜根本不能吃！\n"NOR,me); 
        return notify_fail("由于你烹饪技术太低，菜根本不能吃！\n");
        }
        ob1=new(__DIR__"eat/cai1");
        ob1->set_name(HIY + this_player()->name()+"炒的绿叶百合"+NOR,({"cai4",}));
//        b2 = ob1->query("armor_prop/armor");
//        b2 = b1/5;
//        if ( b2 < 50) b2 = 50;
//        if ( b2 > 150) b2 = 150;
//        ob1->set("armor_prop/armor", b2);
        ob1->set("value", 30000);
        ob1->move(me);
        me->add("work/penlen", 1);       
        return 1;
        }
        if ( ob->query("name") ==GRN"毛笋"NOR )
        {
        destruct(ob);             
        if ( b1 < 300 )
        {
        me->add("work/penlen",1);
        message_vision(HIY"由于你烹饪技术太低，菜根本不能吃！\n"NOR,me); 
        return notify_fail("由于你烹饪技术太低，菜根本不能吃！\n");
        }
        ob1=new(__DIR__"eat/cai1");
        ob1->set_name(WHT + this_player()->name()+"炒的四川毛笋"+NOR,({"cai5",}));
//        b2 = ob1->query("armor_prop/armor");
//        b2 = b1/4;
//        if ( b2 < 80) b2 = 80;
//        if ( b2 > 200) b2 =200;
//        ob1->set("armor_prop/armor", b2);
        ob1->set("value", 60000);
        ob1->move(me);
        me->add("work/penlen", 1);       
        return 1;
        }
        else
        if ( ob->query("name") ==HIY"鸭梨"NOR )
        {
        destruct(ob);             
        if ( b1 < 400 )
        {
        me->add("work/penlen",1);
        message_vision(HIY"由于你烹饪技术太低，菜根本不能吃！\n"NOR,me); 
        return notify_fail("由于你烹饪技术太低，菜根本不能吃！\n");
        }
        ob1=new(__DIR__"eat/cai1");
        ob1->set_name(HIG + this_player()->name()+"做的鸭梨拼盘"+NOR,({"cai6"}));
//        b2 = ob1->query("armor_prop/armor");
//        b2 = b1/3;
//        if ( b2 < 120) b2 = 120;
///        if ( b2 > 400) b2 = 400;
//        ob1->set("armor_prop/armor", b2);
        ob1->set("value", 80000);
        ob1->move(me);
        me->add("work/penlen", 1);       
        return 1;
        }
        else
        if ( ob->query("name") ==GRN"西瓜"NOR )
        {
        destruct(ob);             
        if ( b1 < 500 )
        {
        me->add("work/penlen",1);
        message_vision(HIY"由于你烹饪技术太低，菜根本不能吃！\n"NOR,me); 
        return notify_fail("由于你烹饪技术太低，菜根本不能吃！\n");
        }
        ob1=new(__DIR__"eat/cai1");
        ob1->set_name(HIR + this_player()->name()+"做的西瓜拼盘"+NOR,({"cai7"}));
//        b2 = ob1->query("armor_prop/armor");
//        b2 = b1/2;
//        if ( b2 < 200) b2 = 200;
//        if ( b2 > 600) b2 = 600;
//        ob1->set("armor_prop/armor", b2);
        ob1->set("value", 90000);
        ob1->move(me);
        me->add("work/penlen", 1);       
        return 1;
        }
        else
        if ( ob->query("name") ==HIM"桃子"NOR )
        {
        destruct(ob);             
        if ( b1 < 500 )
        {
        me->add("work/penlen",1);
        message_vision(HIY"由于你烹饪技术太低，菜根本不能吃！\n"NOR,me); 
        return notify_fail("由于你烹饪技术太低，菜根本不能吃！\n");
        }
        ob1=new(__DIR__"eat/cai1");
        ob1->set_name(HIR + this_player()->name()+"做的桃子拼盘"+NOR,({"cai8"}));
//        b2 = ob1->query("armor_prop/armor");
//        b2 = b1/2;
//        if ( b2 < 200) b2 = 200;
//        if ( b2 > 600) b2 = 600;
//        ob1->set("armor_prop/armor", b2);
        ob1->set("value", 100000);
        ob1->move(me);
        me->add("work/penlen", 1);       
        return 1;
        }
} 

int do_quit(string arg)
{
        write(this_player()->query("name")+"，安心的烧菜吧！\n");
        return 1;
}
