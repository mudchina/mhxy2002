inherit ROOM;

void create ()
{
  set ("short", "海滩");
  set ("long", @LONG
“浮天沧海远，去世法舟轻。”天微蒙蒙亮，在海天一线
处，即有一小舟上下沉浮。须臾，只见红日喷薄而出，照
得四周云霞灿烂辉煌，小舟飘荡，仿佛驶入日中。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"haitan2",
  "southeast" : __DIR__"haitan4",
]));

        set("outdoors", "xihai");

  setup();
}

