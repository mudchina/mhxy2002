/* <SecCrypt CPL V3R05> */

inherit ROOM;

void check_trigger();
void on_board();
void arrive();
void close_passage();
int do_yell(string arg);
void reset();

void create()
{
    set("short", "阿克伦");
    set("long", @LONG

              |    |    |
             )_)  )_)  )_)
            )___))___))___)\
           )____)____)_____)\\
         _____|____|____|____\\\__
---------\                   /---------
  ^^^^^ ^^^^^ ^^^^  ^^^^^^^  ^^^^^    ^^^
         ^^^^     ^^^     ^^^    ^^^    ^^^
这里就是亚斯波德洛斯平原上的河流---阿克伦河了
也就是所谓的冥河或是黄泉
LONG );
    set("exits", ([
    ]));
    set("item_desc", ([
        "boat" : "一叶扁舟，也许喊(yell)一声船家就能听见。\n",
    ])); 
 set("objects", ([ 
	"/d/mingjie/npc/jialu":1,
        ]));

    set("no_clean_up", 0);
    setup();
}

void init()
{
    add_action("do_yell", "yell");
}

void check_trigger()
{
    object room;

    if(!query("exits/enter") ) {
        if( !(room = find_object(__DIR__"duchuan")) )
            room = load_object(__DIR__"duchuan");
        if( room = find_object(__DIR__"duchuan") ) {
            if((int)room->query("yell_trigger")==0 ) {
                room->set("yell_trigger", 1);
                set("exits/enter", __DIR__"duchuan");
                room->set("exits/out", __FILE__);
                message("vision", "一叶扁舟缓缓地驶了过来，天间星加路将一块踏脚"
                    "板搭上海滩，以便乘客\n上下。\n", this_object() );
                message("vision", "天间星加路将一块踏脚板搭上海滩，形成一个向上"
                    "的阶梯。\n", room);
                remove_call_out("on_board");
                call_out("on_board", 15);
            }
            else
                message("vision", "只听得海面上隐隐传来：“别急嘛，"
                    "这儿正忙着呐……”\n",this_object() );
        }
        else
            message("vision", "ERROR: boat not found\n", this_object() );
    }
    else 
        message("vision", "天间星加路说道：正等着你呢，上来吧。\n",
            this_object() );
}


void on_board()
{
    object room;

    if( !query("exits/enter") ) return;

    message("vision", "天间星加路把踏脚板收了起来，竹篙一点，扁舟向波涛中驶去。\n",
        this_object() );

    if( room = find_object(__DIR__"duchuan") )
    {
        room->delete("exits/out");
        message("vision", "天间星加路把踏脚板收起来，说了一声“坐稳喽”，"
            "竹篙一点，扁舟向\n波涛中驶去。\n", room );
    }
    delete("exits/enter");

    remove_call_out("arrive");
    call_out("arrive", 20);
}

void arrive()
{
    object room;
    if( room = find_object(__DIR__"duchuan") )
    {
        room->set("exits/out", "/d/mingjie/yi");
        message("vision", "天间星加路说“到啦，上岸吧”，随即把一块踏脚板"
            "搭上海滩。\n",room );
    }
    remove_call_out("close_passage");
    call_out("close_passage", 20);
}

void close_passage()
{
    object room;
    if( room = find_object(__DIR__"duchuan") ) {
        room->delete("exits/out");
        message("vision","天间星加路把踏脚板收起来，把扁舟驶向波涛中。\n", room);
        room->delete("yell_trigger"); 
    }
}

int do_yell(string arg)
{
    string dir;

    if( !arg || arg=="" ) return notify_fail("你要吆喝什么？\n");

    if( arg=="boat" ) arg = "船家";
    if( (int)this_player()->query("age") < 16 )
        message_vision("$N使出吃奶的力气喊了一声：“" + arg + "”\n",
            this_player());
    else if( (int)this_player()->query("force") > 500 )
        message_vision("$N吸了口气，一声“" + arg + "”，声音中正平和地远远传"
            "了出去。\n", this_player());
    else
        message_vision("$N鼓足中气，长啸一声：“" + arg + "！”\n",
            this_player());
    if( arg=="船家")
    {
        check_trigger();
        return 1;
    }
    else
        message_vision("江面上远远传来一阵回声：“" + arg +
            "～～～”\n", this_player());
    return 1;
}

void reset()
{
    object room;

    ::reset();
    if( room = find_object(__DIR__"duchuan") )
        room->delete("yell_trigger"); 
}

