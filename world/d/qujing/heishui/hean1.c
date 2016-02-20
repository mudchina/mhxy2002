//EDIT BY LUCAS
inherit ROOM;
int do_yell(string arg);

void create ()
{
  set ("short", "河岸");
  set ("long", @LONG
站在滔滔江水边，远望无边逝水，正所谓“逝者如斯夫，不舍
昼夜”，人生百年，也如此滔滔江水，奔流到海不复还。远处
岸边不远处停着停着一艘小船，你可以试着叫(yell)一下。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "southeast" : __DIR__"hean2",
]));

        set("outdoors", "heishui");

  setup();
}

void init()
{
        add_action("do_yell","yell");
}

int do_yell(string arg)
{
        object me=this_player();

        if( !arg || arg != "boat" ) {
                return notify_fail("你要叫什么东西?\n");
        }

        message_vision("$N吸了口气，大叫一声“船家”。\n",this_player());
        message_vision("江上小船慢慢飘了过来，砰地一声，靠岸了。\n", this_player());
        set("exits/enter", __DIR__"boat");
        remove_call_out("close");
        call_out("close", 5, this_object());

        return 1;
}

void close(object room)
{
        message("vision","江水拍打小船，小船慢慢向江上飘走了。\n", room);
        room->delete("exits/enter");
}


