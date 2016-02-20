// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
 
// Room: some place in Î÷Å£ºØÖŞ
// uphill1.c

inherit ROOM;

void create()
{
  set ("short", "[32mÃîÒôÆÂ[m");
  set ("long", @LONG

×ßÔÚÉ½¼äĞ¡Â·£¬Á½±ßÆæ»¨Èğ²İ£¬ĞŞÖñÇÇËÉ¡£ĞŞÖñÇÇËÉ£¬ÍòÔØ³£
ÇàÆÛ¸£µØ£»Ææ»¨Èğ²İ£¬ËÄÊ±²»Ğ»ÈüÅîå­¡£ÔÚÕâÀïĞªĞª½Å£¬¿´¿´
¾°É«£¬ÎÅÎÅ»¨ÏãÒ²ÊÇºÜºÃµÄÏíÊÜ¡£
LONG);
set("exits", ([ /* sizeof() == 4 */
"north" : __DIR__"uphill2",
"southdown": __DIR__"hill",
]));

        set("no_clean_up", 0);
        set("outdoors", 1);
  set("objects", ([
                      "/d/qujing/kusong/npc/sctz" : 1,
    ]));       setup();
        replace_program(ROOM);
}


