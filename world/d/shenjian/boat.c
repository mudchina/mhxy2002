// LLY@FYSY
inherit ROOM;void create()

{
        set("short", "一叶孤舟");

        set("long", @LONG
风中飘来一阵阵苦涩而清冽的芳香，炉上罐子里煮的也不知是茶、还是药？
一叶孤舟，一炉弱火，一个孤独的老人。对他说来，生命中所有的悲欢离合，
想必都已成了过眼的云烟。
LONG
        );

        set("exits", ([ 
  "out" : __DIR__"river1",]));

	set("objects",([
			__DIR__"npc/yan" : 1,
       	]) );
        set("item_desc", ([
                "罐子": "一阵阵苦涩而清冽的芳香飘出，你不禁的想尝尝（drink)罐子里煮的东西！\n",
                "jar": "一阵阵苦涩而清冽的芳香飘出，你不禁的想尝尝（drink)罐子里煮的东西！\n",
                      ]) );
        set("coor/x",-1065);

	               set("coor/y",75);

	               set("coor/z",10);

set("no_magic",1);
	setup();

}



void init()
{

add_action("do_drink","drink");
}
int do_drink(string arg)
{
        object room;
        object me;
                me = this_player();
		message_vision("$N从船舱里拿出一个粗碗,将罐子里的东西倒在碗里一口就喝了下去。！\n", me);
message_vision("$N忽然发觉手指与脚尖都已完全麻木，而且正在渐渐向上蔓延，只觉得全身无力，一个倒载，掉在了河里！\n", me);
                
          room = load_object(__DIR__"sjhupan");
	      me->move(room);
              me->unconcious();
		 return 1;		
		 // return notify_fail("");		
        }
