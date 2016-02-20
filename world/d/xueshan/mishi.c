// By tianlin 2001.5.1
// Room: /d/xueshan/mishi.c

inherit ROOM;

void create()
{
  set("short", "密室");
  set("long", @LONG

这里是雪山的孔雀明王练功的地方。可是现在明王已经不在了。
听说他在灵山之颠修行思过。
可以试试这里的穿梭点。到灵山之颠。
LONG
    );
        set("item_desc", ([ /* sizeof() == 2 */
  "table" : "桌上都是灰，什么也看不清。
",
  "牌位" : "牌位上写着：雪山之祖 孔雀明王之位。
",
]));
        set("exits", ([ /* sizeof() == 1 */
"out" : "/d/xueshan/eroad3",
"chuansuo" :"/d/qujing/lingshan/windows",
]));

           if ("/d/xueshan/obj/pingreal.c"->in_mud())
        set("objects", ([ /* sizeof() == 1 */
  "/d/xueshan/obj/pingfake.c" : 1,
  ]));
else
          set("objects", ([ /* sizeof() == 1 */
    "/d/xueshan/obj/pingreal.c" : 1,
  ]));

          set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

