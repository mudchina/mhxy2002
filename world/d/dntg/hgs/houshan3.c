// Room: /4world/houshan3

inherit ROOM;

void create ()
{
  set ("short", "[0;35mºóÉ½[m");
  set ("long", @LONG

»¨¹ûÉ½ºóÉ½ÖĞµÄÒ»Ğ¡¿éÆ½µØ¡£ÒªÏÂÉ½µÃ´©¹ıÄÏÃæÒ»Æ¬Ê÷´Ô¡£¶«
ÃæÃæÊÇÒ»Æ¬ÌÒÊ÷ÁÖ£¬»Æ³Î³ÎµÄâ¨ºïÌÒÏÔÈ»ÒÑ¾­ÊìÍ¸£¬Ò»Õó¹ûÏã
Æ®À´£¬Äã¿ÚË®¶¼Á÷ÁË³öÀ´¡£²»¹ıÌÒÁÖ±ßÉÏÓĞÁ½Ö»´óÂíºï£¬Âú»³
µĞÒâµØ×¢ÊÓ×ÅÄã¡£
LONG);

  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/ma-yuanshuai" : 1,
  __DIR__"npc/liu-yuanshuai" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"houshan2",
  "north" : "/d/pansi/tao_in",
  "east" : __DIR__"houshan4",
]));

  setup();
}

int valid_leave(object me, string dir)
{
	object mys, lys;
    if(dir=="east"){
        if(objectp(mys=present("ma yuanshuai", environment(me)))&&
           objectp(lys=present("liu yuanshuai", environment(me)))
           && living(mys) && living(lys) )
	return notify_fail("ÂíÁ÷¶şÔªË§×ìÀïÒ»ÕóÖ¨Ö¨ÂÒ½Ğ£¬¶ñºİºİµØ°ÑÄãÀ¹×¡ÁË¡£\n");
        if(objectp(mys=present("ma yuanshuai", environment(me)))&&living(mys))
	return notify_fail("ÂíÔªË§×ìÀïÒ»ÕóÖ¨Ö¨ÂÒ½Ğ£¬¶ñºİºİµØ°ÑÄãÀ¹×¡ÁË¡£\n");
        if(objectp(lys=present("liu yuanshuai", environment(me)))&&living(lys))
            return notify_fail("Á÷ÔªË§×ìÀïÒ»ÕóÖ¨Ö¨ÂÒ½Ğ£¬¶ñºİºİµØ°ÑÄãÀ¹×¡ÁË¡£\n");
    }
    return ::valid_leave(me, dir);
}



