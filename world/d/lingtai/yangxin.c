// Room: /d/lingtai/yangxin.c

inherit ROOM;

void create()
{
        set("short", "[0;36mÑøĞÄÌÃ[m");
        set("long", @LONG
ÕâÊÇÒ»¼ä¾²ÊÒ£¬Õı¶Ô×ÅÃÅµÄÇ½ÉÏĞ´×ÅÒ»¸öÈô´óµÄ¾²×Ö¡£
ÑØ×ÅÇ½±ÚµÄÆÑÍÅÉÏ¾²¾²µØ×ø×ÅËÄ¸öµÀÊ¿£¬·Â·ğÔÚ±ÕÄ¿
ÑøÉñ¡£
LONG );
        set("exits", ([
                "east" : __DIR__"wuchang",
        ]));
        set("objects",([
          __DIR__"npc/guanghe" : 1,      
          __DIR__"npc/guangji" : 1,
          __DIR__"npc/guangwen" : 1,
          __DIR__"npc/guangxin" : 1,
          ]));
          
          set("no_fight",1);
          set("no_magic",1);
          setup();
}

