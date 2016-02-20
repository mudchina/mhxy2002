// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
 
// Room: some place in Î÷Å£ºØÖŞ
// cave1.c

inherit ROOM;

void create()
{
  set ("short", "[0;33m¶´¿Ú[m");
  set ("long", @LONG

ºÃ²»ÈİÒ×´ÓÃÜÁÖÖĞ×ßÁË³öÀ´£¬ÑÛÇ°Ò»ÏÂÁÁÁËÆğÀ´£®Ç°·½Ò»¸öĞ¡
É½¶´£¬¶´¿Ú»¹ÓĞ²»ÉÙÑª¼££®Ò»ÕóÉ½·ç´µ¹ı£¬´øÀ´¹ÉÁîÈËÓûÅ»µÄ
ĞÈÆø£®£®£®°¡£¡£¡£¿ÄÑµÀÓĞÒ°ÊŞ£¿
LONG);
set("exits", ([ /* sizeof() == 4 */
"east" : __DIR__"forrest",
"west": __DIR__"cave2",
]));
set("objects", ([
                __DIR__"npc/oldwolf.c": 1 ]) );

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        if ( dir == "west" && objectp(present("wolf", environment(me)))) 
        return notify_fail("ÀÏÀÇÃÍµÄÌøµ½ÄãÇ°ÃæÀ¹×¡Äã£¡\n");

        return ::valid_leave(me, dir);
}

