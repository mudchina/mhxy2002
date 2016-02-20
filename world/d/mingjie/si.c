// /d/guzhanchang/pomiao.c
inherit ROOM;
void create ()
{
  set ("short", "第四狱");
  set ("long", @LONG

                             .-""-. 
                            (___/\ \ 
          ,                 (|^ ^ ) ) 
         /(                _)_\=_/  ( 
   ,..__/ `\          ____(_/_ ` \   ) 
    `\    _/        _/---._/(_)_  `\ ( 
      '--\ `-.__..-'    /.    (_), |  ) 
          `._        ___\_____.'_| |__/ 
             `~----"`   `-.........' 
 这里就是冥界第四狱----黑暗的沼泽，不满及愤怒的罪人在这里互相沉沦
  
LONG);
 
  set("item_desc", ([ /* sizeof() == 1 */
  "mufa" : "一只木筏，以几根大圆木捆成。你不禁想坐(zuo)上去试一试。
",
]));
                    
set("exits", ([
            "eastup": __DIR__"san",
    
        ]));

  set("objects", ([ 
	"/d/mingjie/npc/likaao":1,

        ]));

        setup();
}

void init()
{
    add_action("do_zuo", "zuo");
    add_action("do_zuo", "sit");
}

void check_trigger()
{
    object room;

    if(!query("exits/enter") ) {
        if( !(room = find_object(__DIR__"mufa")) )
            room = load_object(__DIR__"mufa");
        if( room = find_object(__DIR__"mufa") ) {
            if((int)room->query("zuo_trigger")==0 ) {
                room->set("zuo_trigger", 1);
                set("exits/enter", __DIR__"mufa");
                room->set("exits/out", __FILE__);
                message("vision", "一只鬼筏从突然出现在你眼前。\n", this_object() );
                message("vision", "鬼筏一震，显然是搁浅了。\n", room);
                remove_call_out("on_board");
                call_out("on_board", 15);
            }
            else
                message("vision", "鬼筏正漂向岸边，看样子还得耐心地等等。\n",this_object() );
        }
        else
            message("vision", "ERROR: mufa not found\n", this_object() );
    }
    else 
        message("vision", "鬼筏已经靠岸了，随时都可上去。\n",
            this_object() );
}


void on_board()
{
    object room;

    if( !query("exits/enter") ) return;

    message("vision", "一个浪头打来，鬼筏向海上漂去。\n",
        this_object() );

    if( room = find_object(__DIR__"mufa") )
    {
        room->delete("exits/out");
        message("vision", "到处都是黑色，黑色的天，黑色的水，一个黑色的世界...\n", room );
    }
    delete("exits/enter");

    remove_call_out("arrive");
    call_out("arrive", 20);
}

void arrive()
{
    object room;
    if( room = find_object(__DIR__"mufa") )
    {
        room->set("exits/out", __DIR__"wu");
        message("vision", "鬼筏一震，搁浅了。显然是到陆地了，赶紧上去吧。\n",room );
    }
    remove_call_out("close_passage");
    call_out("close_passage", 20);
}

void close_passage()
{
    object room;
    if( room = find_object(__DIR__"mufa") ) {
        room->delete("exits/out");
        message("vision","一个浪头打来，鬼筏向海上漂去。\n", room);
room->set("zuo_trigger", 0);
    }
}

int do_zuo(string arg)
{
    string dir;

    if( (arg=="mufa") || (arg=="鬼筏")){ 
        message_vision("$N试着想坐上鬼筏。\n", this_player());
        check_trigger();
        return 1;
    }
    else return notify_fail("你要坐上什么？\n");
}

void reset()
{
    object room;

    ::reset();
    if( room = find_object(__DIR__"mufa") )
        room->delete("zuo_trigger"); 
}

