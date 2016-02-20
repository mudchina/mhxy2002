inherit ROOM;

void create ()
{
  set ("short", "[1;37;41m»Ê¹¬´óÃÅ[m");
  set ("long", @LONG

»Ê¹¬´óÃÅ×¯ÑÏËàÄÂ£¬½ğ±Ú»Ô»Í£¬¹¬Ç½ÀïÃæµî¸ó¸ß´óĞÛÎ°£¬²ã
²ãµşµş£¬ÁğÁ§Íß°×ÓñŞò¸»ÀöÌÃ»Ê¡£´Ë¿Ì¹¬ÃÅ½ô±Õ£¬ÃÅÇ°ÊØÎÀ
×Å¼¸Î»½ğ¼×ÎäÊ¿¡£

LONG);

  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/weishi" : 3,
  __DIR__"npc/xuerengui" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"chaoyangmen",
  "north" : __DIR__"guangchang",
  "northeast" : __DIR__"yhy3b.c",
  "northwest" : __DIR__"yhy3a.c",
]));

  setup();
}

int valid_leave(object me, string dir)
{
        if (me->query("quest/reward"))
	return ::valid_leave(me, dir);
	if (dir == "north" ) {
        if (objectp(present("xue rengui", environment(me)))&&!wizardp(me))
	return notify_fail("Ñ¦ÈÊ¹óÌúÇ¹Ò»ºá£¬ºÈµÀ£º´ËÄË»Ê¹¬£¬½ûĞĞ£¡\n");
         if (objectp(present("wei shi", environment(me)))&&!wizardp(me))
        return notify_fail("½ğ¼×ÎÀÊ¿º°µÀ£ºÎÒ¼Ò½«¾ü²»ÔÚ£¬Ğ¡ÈË²»¸Ò·ÅÄú½øÈ¥£¡\n");
        }   
        return ::valid_leave(me, dir);
}

 

