//by tianlin 2001.8.7

inherit ROOM;

void create ()
{
        set ("short", "山路");
        set ("long", @LONG

你抬头看见雅典娜神庙在阳光发出金色的光芒，禁不住虔诚地向雅典
娜女神祷告！再回头时发现十二宫已经隐没在云海之中。

LONG);


        set("exits", ([
        "up"    :       __DIR__"palace",
            "down"  :       __DIR__"topalace2",
        ]));

  set("objects", ([
                __DIR__"npc/huang": 1 ]) );

  // set("outdoors", __DIR__);//by tianlin 2001.8.7.因为我本来,设上那些函数就是为了让他们进来就出不去了,所以设上这句话(snicker)

  setup();
}

int valid_leave (object me, string dir)
{
        if (dir == "up" ) {
        if (objectp(present("huang", environment(me))))
        return notify_fail("出招吧! 青铜圣斗士！\n");
        }
        if (dir == "down" ) {
        if (objectp(present("huang", environment(me))))
        return notify_fail("出招吧! 青铜圣斗士！\n");
        }
  return 1;
}
