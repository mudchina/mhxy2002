//EDIT BY LUCAS
inherit ROOM;

void create ()
{
  set ("short", "河岸");
  set ("long", @LONG
黑水滔滔，近观不照人身影，远望难寻树木形。滚滚一地黑，
滔滔千里灰。即使是在岸边几寸深的河边，也难以见到水下
的鹅卵石。河岸周围方圆十里，鸟兽绝迹，藐无生灵。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "southeast" : __DIR__"hean4",
  "west" : __DIR__"hean2",
]));

        set("outdoors", "heishui");

  setup();
}

