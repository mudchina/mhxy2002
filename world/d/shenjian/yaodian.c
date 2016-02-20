//By tianlin@mhxy for 2001.10.10
inherit ROOM;

void create ()
{
        set ("short", "药店");
        set ("long", @LONG

这里的物品十分齐全,各式各样的都有,有兵器,装备,道具
是样样齐全,而且价格十分便宜.
LONG);

        set("exits",
        ([ //sizeof() == 4
                "north": __DIR__"cunkou",
      ]));
      set("objects", ([
                __DIR__"npc/yaoren" :1,
                ]));

      set("outdoors", "shenjian");
      set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}

