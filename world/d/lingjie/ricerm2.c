
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "恶魔食堂二层");
        set("long", @LONG
这里是灵界用餐的地方。屋里布置很简单, 只摆着十几张桌椅
几个人在一声不响地吃着。一个厨子在不停的忙碌着，假如你
未满十五岁，可以向他要食物和水。
LONG);
        set("exits", ([
                "down" :__DIR__"chufang",
                
        ]));

        set("objects", ([
           __DIR__"npc/shifu2" : 1,
        ]));       
	set("coor/x",60);
	set("coor/y",0);
	set("coor/z",20);
        set("no_fight", 1);
        setup();
}
int valid_leave(object me, string dir)
{
	int i;
	object *ob;
	ob = all_inventory(me);
	for(i=0; i<sizeof(ob); i++)    
        if ((dir == "down") && present("shifu", environment(me)) ){
           if(present("cocacola", environment(me)))
              return notify_fail("大师傅拦住你道：你还是先把可口可乐喝完再走吧。\n"); 
              if (ob[i]->query("food_remaining")) {
                  switch ( random(2) ){
                      case 0: return notify_fail("大师傅不高兴的伸手拦住了你说：还是先把东西吃完了再走吧。\n"); break;
                      case 1: return notify_fail("大师傅拦住你道：饮食不得带这里。\n"); break;
                      }
                  }
           }
       return ::valid_leave(me, dir);
}
