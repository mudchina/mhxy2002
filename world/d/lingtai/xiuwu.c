// Room: /d/lingtai/xiuwu.c

inherit ROOM;

void create()
{
        set("short", "[0;33mĞŞÎäÌÃ[m");
        set("long", @LONG
ÕâÊÇÒ»¼ä½Ï´óµÄ¾²ÊÒ£¬Õı¶Ô×ÅÃÅµÄÇ½ÉÏĞ´×ÅÒ»¸öÈô´óµÄÎä×Ö¡£
·¿ÖĞÓĞËÄ¸öµÀÊ¿£¬ÕıÊÖ³ÖÄ¾ÕÈ£¬·Â·ğÔÚ±È»®Ê²Ã´¡£
LONG );
        set("exits", ([
                "west" : __DIR__"wuchang",
        ]));
        set("objects",([
          __DIR__"npc/guangjing" : 1,      
          __DIR__"npc/guangguan" : 1,
          __DIR__"npc/guangming" : 1,
          __DIR__"npc/guangzhi" : 1,
          ]));
          
          set("no_fight",1);
          set("no_magic",1);
        setup();
}

