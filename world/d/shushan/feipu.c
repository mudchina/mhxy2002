//Cracked by Roath
//【蜀山剑派】dhxy-evil 2000.7.5
//by yushu 修改 2001.2
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short","飞瀑");
        set("long",@LONG

在你面前是飞流直下三千尺的瀑布，见到这么长的瀑布，
你不由想去试试挥剑(huijian)断水！
LONG
        );

        set("exits", ([
                "east" : __DIR__"jby",
        ]));

        setup();
}

void init()
{
        add_action("do_huijian", "huijian");
}

int do_huijian(string arg)
{
        object room, ob;
        object me = this_player();
        int sk = me->query_skill("songhe-sword",1);
        if(me->is_busy() )
          return notify_fail("你现在忙着呢，哪有功夫挥剑断水...\n");
        if(me->query("family/family_name") != "蜀山派")
        {
        tell_object(me,"你感觉到力不从心。\n"); 
        return 1;
        }
        if(me->query("combat_exp") < 1000000)
        {
        tell_object(me,"你的武学不够。\n");     
        return 1;
        }
        if(me->query("daoxing") < 800000)
        {
        tell_object(me,"你的道行不够。\n");     
        return 1;
        }
        if(me->query("kee") < 100)
        {
        tell_object(me,"你还是先休息一会儿吧。\n");     
        return 1;
        }
        if (!objectp(ob = me->query_temp("weapon"))
        || (string)ob->query("skill_type") != "sword")
                return notify_fail("你必须先找一把剑才能挥剑断水。\n");

        message_vision("$N挥剑去断水，结果弄得个“挥剑断水水更流，全身湿透汗也流”。\n",me);
        me->add("kee",-100);
        if(me->query("shushan/duanshui_perform")) 
        {
        tell_object(me,"你似乎不能在这里悟到什么了。\n");       
        return 1;
        }
        if((int)me->query_skill("songhe-sword", 1) > 149){
        tell_object(me,HIW"你似乎对挥剑断水有所领悟！\n你感觉到你的蜀山剑法在不断进步！\n"NOR);
        me->improve_skill("songhe-sword", 50+random(100));
        me->add("shushan/duanshui",1);
        me->start_busy(2);
        }
        if(me->query("shushan/duanshui",1) > 500)
        {
        me->set("shushan/duanshui_perform",1);
        tell_object(me,HIY"你在不知不觉间悟到了一招「断水无痕」。\n"NOR);
        me->delete("shushan/duanshui");
        }
        return 1;
}             
