// link
inherit ROOM;
void create()
#include <ansi.h>
{
        set("short", "厨房");
        set("long", @LONG
这里就是麦当劳餐厅的厨房了，人们都忙忙碌碌，如果你问服务员要来了
盘子之后，就可以在这里洗（xi）了。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"hguitai",
]));
	set("valid_startroom",1);
	set("coor/x",-20);
	set("coor/y",160);
	set("coor/z",0);
	setup();
}
void init()
{
        add_action("do_xi", "xi");
        add_action("do_xi", "wash");
}
int do_xi(string arg)
{
        object me,ob,ob1;
        int i;
        me = this_player();
if (!me->query_temp("工作/洗盘子")) 
return notify_fail("你还是先去给店小二打个招呼吧。\n"); 

if (!arg || arg != "panzi") 
return notify_fail("你要洗什么？\n"); 

if (!(ob = present("zang panzi", this_player()))) 
return notify_fail("你身上没有脏盘子，怎么能洗呢？。\n"); 

if ( (int)me->query("gin")<20) 
return notify_fail("你太累了，歇息一下吧。\n"); 
message_vision(CYN"$N洗了良久，终于将盘子全部洗好了。\n"NOR,me); 
i=ob->query_amount();
me->add("gin",-(10*i)); 
//me->add("kee",-10); 
destruct(ob); 
ob1=new (__DIR__ "npc/obj/panzi");
ob1->set_amount(i);
ob1->move(me); 
return 1; 
}