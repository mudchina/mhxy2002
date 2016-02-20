#include <ansi.h>
inherit ROOM;
int do_zhujia(string arg);

 void create()
{
        set("short", HIY"铸甲房"NOR);
        set("long", @LONG
这是一个很平常普通的铸甲房！四周都是乱七八糟的铜皮铁块，人们
把捡来的矿石在这儿炼化以后铸造成各种盔甲。
LONG
        );

        set("exits", ([
                "north" : "/d/qujing/baoxiang/xi4",
                "east" : __DIR__"zhujian",
                "south" : __DIR__"zhubang",
        ]));
        set("no_fight",1);
        set("no_beg",1);
        set("no_steal",1);
        setup();
}

void init()
{
        add_action("do_zhujia","zhujia"); 
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
        int b1;
        me=this_player();
        b1 = this_player()->query("work/zhujia");
        if (!(ob = present("tong kuang", this_player())) &&
             !(ob = present("tie kuang", this_player())) &&
             !(ob = present("ying kuang", this_player())) &&
             !(ob = present("jing kuang", this_player())) &&
             !(ob = present("xuantie kuang", this_player())) &&
             !(ob = present("han tie", this_player())) )
                return notify_fail("你身上没有矿石，如何铸甲？\n");
                 
        if ( (int)me->query("sen")<200)
                return notify_fail("你的精力不足，无法铸甲。\n");

        if( me->is_busy() )
                return notify_fail("你现在很忙！不能铸甲！\n");

        if ( (int)me->query("kee")<200)
                return notify_fail("你的体力不足，无法铸甲。\n");

        if ( (int)me->query("force")<300)
                return notify_fail("你的内力不足，无法铸甲。\n");

        message_vision(HIY"$N先将矿石放进炉中炼化成块状状。\n"NOR,me); 
        message_vision(HIY"接着$N再拿出一个大锤开始铸甲。\n"NOR,me); 
        message_vision(HIY"不一会儿！一具好看的盔甲摆在了$N的面前。\n"NOR,me); 
//        me->add("combat_exp",50+random(50));
//        me->add("potential",50+random(50));
//        me->add("daoxing",50+random(50));
        me->add("sen",-150);
        me->add("kee",-150);
        me->add("force",-200);
        me->start_busy(3); 

        if ( ob->query("name") ==YEL"铜矿石"NOR )
        {
        destruct(ob);             
        ob1=new(__DIR__"hujia/jia");
        ob1->set_name(YEL + this_player()->name()+"打造的铜甲"+NOR,({"tong jia","jia"}));
        ob1->set("armor_prop/armor", 10);
        ob1->move(me);
        me->add("work/zhujia", 1);       
        return 1;
        }
        if ( ob->query("name") ==CYN"铁矿石"NOR )
        {
        destruct(ob);             
        if ( b1 < 100 ) 
        {
        me->add("work/zhujia",1);
        return notify_fail("由于你铸甲之技太低，盔甲根本不能用！\n");
        }
        ob1=new(__DIR__"hujia/jia");
        ob1->set_name(CYN + this_player()->name()+"打造的铁甲"+NOR,({"tie jia","jia"}));
        ob1->set("armor_prop/armor", 30);
        ob1->set("value", 0);
        ob1->set("no_get", 1);
        ob1->set("no_sell", 1);
        ob1->set("no_put", 1);
        ob1->set("no_give", 1);
        ob1->set("no_drop", 1);
        ob1->set("value", 0);
        ob1->move(me);
        me->add("work/zhujia", 1);       
        return 1;
        }
        if ( ob->query("name") ==HIW"银矿石"NOR )
        {
        destruct(ob);             
        if ( b1 < 300 )
        {
        me->add("work/zhujia",1);
        return notify_fail("由于你铸甲之技太低，盔甲根本不能用！\n");
        }
        ob1=new(__DIR__"hujia/jia");
        ob1->set_name(HIW + this_player()->name()+"打造的银甲"+NOR,({"ying jia","jia"}));
        ob1->set("armor_prop/armor", 60);
        ob1->set("value", 0);
        ob1->set("no_get", 1);
        ob1->set("no_sell", 1);
        ob1->set("no_put", 1);
        ob1->set("no_give", 1);
        ob1->set("no_drop", 1);
        ob1->move(me);
        me->add("work/zhujia", 1);       
        return 1;
        }
        if ( ob->query("name") ==HIY"金矿石"NOR )
        {
        destruct(ob);             
        if ( b1 < 500 )
        {
        me->add("work/zhujia",1);
        return notify_fail("由于你铸甲之技太低，盔甲根本不能用！\n");
        }
        ob1=new(__DIR__"hujia/jia");
        ob1->set_name(HIY + this_player()->name()+"打造的金甲"+NOR,({"jing jia","jia"}));
        ob1->set("armor_prop/armor", 80);
        ob1->set("value", 0);
        ob1->set("no_get", 1);
        ob1->set("no_sell", 1);
        ob1->set("no_put", 1);
        ob1->set("no_give", 1);
        ob1->set("no_drop", 1);
        ob1->move(me);
        me->add("work/zhujia", 1);       
        return 1;
        }
        if ( ob->query("name") ==WHT"玄铁矿石"NOR )
        {
        destruct(ob);             
        if ( b1 < 700 )
        {
        me->add("work/zhujia",1);
        return notify_fail("由于你铸甲之技太低，盔甲根本不能用！\n");
        }
        ob1=new(__DIR__"hujia/jia");
        ob1->set_name(WHT + this_player()->name()+"打造的玄铁甲"+NOR,({"xuantie jia","jia"}));
        ob1->set("armor_prop/armor", 100);
        ob1->set("value", 0);
        ob1->set("no_get", 1);
        ob1->set("no_put", 1);
        ob1->set("no_give", 1);
        ob1->set("no_drop", 1);
        ob1->move(me);
        me->add("work/zhujia", 1);       
        return 1;
        }
        else
        if ( ob->query("name") ==HIG"寒铁矿石"NOR )
        {
        destruct(ob);             
        if ( b1 < 1000 )
        {
        me->add("work/zhujia",1);
        return notify_fail("由于你铸甲之技太低，盔甲根本不能用！\n");
        }
        ob1=new(__DIR__"hujia/jia");
        ob1->set_name(HIG + this_player()->name()+"打造的寒铁甲"+NOR,({"hantie jia","jia"}));
        ob1->set("armor_prop/armor", 150);
        ob1->set("value", 0);
        ob1->set("no_get", 1);
        ob1->set("no_put", 1);
        ob1->set("no_give", 1);
        ob1->set("no_drop", 1);
        ob1->move(me);
        me->add("work/zhujia", 1);       
        return 1;
        }
        else
        if ( ob->query("name") ==HIR"千年寒铁"NOR )
        {
        destruct(ob);             
        if ( b1 < 3000 )
        {
        me->add("work/zhujia",1);
        return notify_fail("由于你铸甲之技太低，盔甲根本不能用！\n");
        }
        ob1=new(__DIR__"hujia/jia");
        ob1->set_name(HIR + this_player()->name()+"打造的千年寒铁甲"+NOR,({"hantie jia","jia"}));
        ob1->set("armor_prop/armor", 200);
        ob1->set("value", 0);
        ob1->set("no_get", 1);
        ob1->set("no_put", 1);
        ob1->set("no_give", 1);
        ob1->set("no_drop", 1);
        ob1->move(me);
        me->add("work/zhujia", 1);       
        return 1;
        }
} 

int do_quit(string arg)
{
        write(this_player()->query("name")+"，安心的铸甲吧！\n");
        return 1;
}
