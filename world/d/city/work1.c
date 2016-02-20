inherit ROOM;

void create()
{
          set("short", "Ìú½³ÆÌ");
        set("long", @LONG

  ³¤°²³Ç×î´óµÄÌú½³ÆÌ,ÔÚÕâÀï¿ÉÒÔÌıµ½"¶£,¶£,µ±,µ±"
µØÇÃ´òÉù[1;31m(ask zhang about job)[2;37;0m ¡£
LONG
        );
  set("no_fight", 1);
        set("freeze",1);
  set("no_magic", 1);
        set("if_bed",1);

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/work" : 1,
        ]));
        set("exits", ([
                  "north" : __DIR__"dongmen",
        ]));

        setup();
}

int valid_leave(object me, string dir)
{
        me->delete_temp("rent_paid");
        return ::valid_leave(me, dir);
}

