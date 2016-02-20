// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "天蓬元帅府大堂");
  set ("long", @LONG

帅府内灯笼高悬，正中放着一把肥大的特号躺椅。屋后有一个案台，
上面放着一个澡盆大的金饭盆，边上有一水桶大小的银酒壶。西边有
一门，通向帅府外。西边是元帅府的厨房。

LONG);

  set("exits", ([
        "west" : __DIR__"tianpeng",
        "east" : __DIR__"zchufang",
        "up" : __DIR__"zzoulang",
      ]));
  set("objects", ([
        __DIR__"npc/yingbin" : 1,
      ]));

  setup();
}
int valid_leave(object me, string dir)
{
    if((string)me->query("family/family_name")=="元帅府") return 1;
   if((string)me->query("family/family_name")=="天蓬帅府") return 1;


    if (dir == "east" ) {

        return notify_fail("那里只有天蓬帅府的弟子才能进去白吃白喝！\n");
    }

return 1;
}


