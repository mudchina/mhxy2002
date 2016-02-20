//edit by lucas

inherit ROOM;
int do_open(string arg);
void create ()
{
  set ("short", "木船");
  set ("long", @LONG

这是一艘破破烂烂的木船，船身窄小，只怕坐三个人也成问题。
小船栓在波涛汹涌的黑水岸边，被日月奔流不止的江水冲的遥
遥晃晃。看起来是很平常的船，但你好象总觉得有什么不对似
的，船底有块木板(board)似乎有问题。 
LONG);

        set("item_desc", ([
 "board" : "这是一块木板，虚掩在船板上，好象可以移开。\n", 
        ]) );

        set("outdoors", "heishui");

        setup();
}

void init()
{
        add_action("do_open","open");
}

int do_open(string arg)
{
            object me, zhou;
        me=this_player();

        if( !arg || arg != "board" ) {
                return notify_fail("你要打开什么?\n");
        }
    if( !(zhou=present("bishui zhou", me)))
         {
             message_vision("木板忽然移开，$N一不小心落入水中，呛了几口水，又狼狈不堪地爬出来。。\n",this_player());  
     me->add("kee",-100);  
     me->add("sen",-100); 
     return 1;
         }
         else
         {
     message_vision("$N使劲一揪，把木板揭开，现出一个黑黝黝的洞口。\n",this_player());
        message_vision("$N一不小心，乎地掉了下去。\n", this_player()); 
   me->move("/d/qujing/heishui/hedi1");        return 1;
         }
}

