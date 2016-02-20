// zhujia.c 铸甲房
// 星星lywin 2000/9/2 

#include <ansi.h>
inherit ROOM;
int do_zhujia(string arg);

 void create()
{
        set("short", "龙泉酒店造酒房");
        set("long", @LONG
这是一间龙泉酒店造酒房！四周都是乱七八糟的造酒原料，人们
把在这用各种材料造酒。
LONG
        );

//        set("exits", ([
//                "west" : "/d/xiangyang/tiejiangpu",
//        ]));
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
        
        if (!(ob = present("liewu1", this_player())) &&
             !(ob = present("liewu2", this_player())) &&
             !(ob = present("liewu3", this_player())) &&
             !(ob = present("liewu4", this_player())) &&
             !(ob = present("liewu5", this_player())) &&
             !(ob = present("liewu6", this_player())) &&
             !(ob = present("liewu7", this_player())) &&
             !(ob = present("liewu8", this_player())) )
                return notify_fail("你身上没有材料，如何做菜？\n");
                 
        if ( (int)me->query("jing")<100)
                return notify_fail("你的精力不足，无法做菜。\n");

        if( me->is_busy() )
                return notify_fail("你现在很忙！不能做菜！\n");

        if ( (int)me->query("qi")<100)
                return notify_fail("你的体力不足，无法做菜。\n");

        if ( (int)me->query("neili")<150)
                return notify_fail("你的内力不足，无法做菜。\n");

        message_vision(HIY"$N先将野味放进锅中炒了起来。\n"NOR,me); 
        message_vision(HIY"接着$N再拿出各种调料开始烧菜。\n"NOR,me); 
        message_vision(HIY"不一会儿！一盘烧好的野味摆在了$N的面前。\n"NOR,me); 
        message_vision(HIY"$N的经验和潜能增加了。\n"NOR,me); 
        me->add("combat_exp",40+random(20));
        me->add("potential",25+random(5));
        me->add("jing",-30);
        me->add("qi",-30);
        me->add("neili",-30);
        me->start_busy(5); 

        if ( ob->query("name") =="免肉" )
        {
        destruct(ob);             
        ob1=new(__DIR__"eat/cai3");
        ob1->set_name(GRN + this_player()->name()+"烧的红烧免肉"+NOR,({"cai1"}));
        ob1->set("value", 2000);
        ob1->move(me);
        me->add("work/penlen", 1);       
        return 1;
        }
        if ( ob->query("name") =="鸡肉" )
        {
        destruct(ob);             
        if ( b1 < 20 ) 
        {
        me->add("work/penlen",1);
        message_vision(HIY"由于你烹饪技术太低，菜根本不能吃！\n"NOR,me); 
        return notify_fail("由于你烹饪技术太低，菜根本不能吃！\n");
        }
        ob1=new(__DIR__"eat/cai2");
        ob1->set_name(CYN + this_player()->name()+"烧的烤鸡腿"+NOR,({"cai2",}));
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
        if ( ob->query("name") =="鸭肉" )
        {
        destruct(ob);             
        if ( b1 < 100 )
        {
        me->add("work/penlen",1);
        message_vision(HIY"由于你烹饪技术太低，菜根本不能吃！\n"NOR,me); 
        return notify_fail("由于你烹饪技术太低，菜根本不能吃！\n");
        }
        ob1=new(__DIR__"eat/cai2");
        ob1->set_name(HIW + this_player()->name()+"烧的火踵神仙鸭"+NOR,({"cai3"}));
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
        if ( ob->query("name") =="猪肉" )
        {
        destruct(ob);             
        if ( b1 < 220 )
        {
        me->add("work/penlen",1);
        message_vision(HIY"由于你烹饪技术太低，菜根本不能吃！\n"NOR,me); 
        return notify_fail("由于你烹饪技术太低，菜根本不能吃！\n");
        }
        ob1=new(__DIR__"eat/cai2");
        ob1->set_name(HIY + this_player()->name()+"炒的片皮乳猪"+NOR,({"cai4",}));
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
        if ( ob->query("name") ==RED"羊肉"NOR )
        {
        destruct(ob);             
        if ( b1 < 300 )
        {
        me->add("work/penlen",1);
        message_vision(HIY"由于你烹饪技术太低，菜根本不能吃！\n"NOR,me); 
        return notify_fail("由于你烹饪技术太低，菜根本不能吃！\n");
        }
        ob1=new(__DIR__"eat/cai2");
        ob1->set_name(WHT + this_player()->name()+"炒锅巴肉片"+NOR,({"cai5",}));
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
        if ( ob->query("name") ==HIC"牛肉"NOR )
        {
        destruct(ob);             
        if ( b1 < 400 )
        {
        me->add("work/penlen",1);
        message_vision(HIY"由于你烹饪技术太低，菜根本不能吃！\n"NOR,me); 
        return notify_fail("由于你烹饪技术太低，菜根本不能吃！\n");
        }
        ob1=new(__DIR__"eat/cai2");
        ob1->set_name(HIG + this_player()->name()+"做的原笼粉蒸牛肉"+NOR,({"cai6"}));
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
        if ( ob->query("name") ==CYN"蛇肉"NOR )
        {
        destruct(ob);             
        if ( b1 < 500 )
        {
        me->add("work/penlen",1);
        message_vision(HIY"由于你烹饪技术太低，菜根本不能吃！\n"NOR,me); 
        return notify_fail("由于你烹饪技术太低，菜根本不能吃！\n");
        }
        ob1=new(__DIR__"eat/cai2");
        ob1->set_name(HIR + this_player()->name()+"做的抓炒里脊"+NOR,({"cai7"}));
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
        if ( ob->query("name") ==HIM"熊肉"NOR )
        {
        destruct(ob);             
        if ( b1 < 500 )
        {
        me->add("work/penlen",1);
        message_vision(HIY"由于你烹饪技术太低，菜根本不能吃！\n"NOR,me); 
        return notify_fail("由于你烹饪技术太低，菜根本不能吃！\n");
        }
        ob1=new(__DIR__"eat/cai2");
        ob1->set_name(HIM + this_player()->name()+"做的熊掌"+NOR,({"cai8"}));
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
