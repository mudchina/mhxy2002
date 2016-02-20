//Room: huixianqiao.c 会仙桥
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","会仙桥");
      set("long",@LONG
这里地势稍平，一道山涧缓缓流过，一座窄窄的木桥横在涧上，只溶一人
经过。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "north"    : __DIR__"chaotiangong",
          "south"    : __DIR__"toutiangate",
      ]));
      set("outdoors", "wudang");
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
