// This is the basic equip for players just login.
inherit ITEM;
#include <ansi.h>
mapping default_dirs = ([
        "north":                "北",
        "south":                "南",
        "east":                 "东",
        "west":                 "西",
        "northup":              "北边",
        "southup":              "南边",
        "eastup":               "东边",
        "westup":               "西边",
        "northdown":    "北边",
        "southdown":    "南边",
        "eastdown":             "东边",
        "westdown":             "西边",
        "northeast":    "东北",
        "northwest":    "西北",
        "southeast":    "东南",
        "southwest":    "西南",
        "up":                   "上",
        "down":                 "下",
        "out":                  "外",
        "enter":                "里",
]);

// inherit ITEM;

void create()
{
        set_name("手雷",({"shoulei","lei"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
//                set("no_drop", 0);
//                set("no_get",0);                
                set("unit","个");
                set("material","steel");
        }
        setup();
}
void init()
{
        add_action("do_tou","reng");
}
int do_tou(string str)
{
        string room;
        object me,here,o_room;
        me=this_player();
        if(!str)        return notify_fail("你要投向哪个方向？\n");

        here=environment(me);

        if(!here->query("exits/"+str))      return notify_fail("没有这个方向！\n");

        room=here->query("exits/"+str);

        if(!o_room=find_object(room))
                o_room=load_object(room);
         message_vision(RED"$N将枚手雷朝着"+default_dirs[str]+"投了过去！\n"NOR,me);
        tell_object(o_room,RED"一枚冒着火花的手雷不知被谁扔了过来！\n"NOR);
        this_object()->set("long","正滋滋冒烟的手雷，眼看就要爆炸啦！\n");
        this_object()->set("name",RED"冒烟的手雷"NOR);
        this_object()->set("no_get",1);
        this_object()->move(o_room);
        call_out("do_zha",3);
        return 1;
}
int do_zha()
{
        object *inv,room,other;
        string *list,s_room;
        mapping exit;
        int i;
        room=environment(this_object());
        inv=all_inventory(room);
        tell_object(room,RED"只听见“轰”的一声巨响！\n"NOR);
        if(sizeof(inv)>0)       {
                for(i=0;i<sizeof(inv);i++)      {
        if(inv[i]->is_character())      {
                if(userp(inv[i])&&inv[i]->query("id")!="leon") 
                        message("channel:rumor", YEL +"【谣言】"+ "某人："+inv[i]->query("name")+"被手雷炸死了。\n"NOR,users());
                inv[i]->die();
        }
                }
        }
        if(room->query("leon_flag/shoulei")==0)       {
        room->set("short",NOR YEL"弹痕累累的"YEL+room->query("short"));
        room->set("leon_flag/shoulei",1);
        }
        exit=room->query("exits");
        list=keys(exit);
        for(i=0;i<sizeof(list);i++)     {
        s_room=room->query("exits/"+list[i]);
        if(!other=find_object(s_room))  other=load_object(s_room);
        tell_object(other,RED"附近突然传来猛烈的爆炸声！\n"NOR);
        }
        destruct(this_object());
        return 1;
}