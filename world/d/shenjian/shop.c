//By tianlin@mhxy for 2001.10.10
inherit ROOM;

void create ()
{
        set ("short", "ÎïÆ·µê");
        set ("long", @LONG

    ¸Õ½øÀ´£¬ÄãµÚÒ»ÑÛ¿´µ½µÄ¾ÍÊÇÄÇºÕºÕÓĞÃûµÄÕĞÅÆ£º
[36m
                ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ
                ¡õ[m[41m[1;30m    ÎïÆ·µê    [2;37;0m[36m¡õ
                ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ
[m
ÕâÀïµÄÎïÆ·Ê®·ÖÆëÈ«,¸÷Ê½¸÷ÑùµÄ¶¼ÓĞ,ÓĞ±øÆ÷,×°±¸,µÀ¾ß
ÊÇÑùÑùÆëÈ«,¶øÇÒ¼Û¸ñÊ®·Ö±ãÒË.
LONG);

        set("exits",
        ([ //sizeof() == 4
                "south": __DIR__"road",
      ]));
      set("objects", ([
                __DIR__"npc/wupin" :1,
                ]));

      set("outdoors", "shenjian");
      set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}

