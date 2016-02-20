//Room: wdbl.c 武当柏林
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","武当柏林");
      set("long",@LONG
你穿行在一片茂密的柏林中，阴森郁翠，怪石嶙峋，草深没人。不时地
有兔子从你的身边飞跑而过。
LONG);
      set("objects", ([
          __DIR__"npc/yetu" : 2,
      ]));
      set("outdoors", "wudang");
      set("exits",([ /* sizeof() == 1 */
          "northdown": __DIR__"yuzhengong",
          "southup"  : __DIR__"haohanpo",
      ]));
//      set("no_clean_up", 0);
      set_temp("wayao",1);
      setup();
      replace_program(ROOM);
}
