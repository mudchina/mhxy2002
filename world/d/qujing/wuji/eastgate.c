//by tianlin 2001.8.5

inherit ROOM;

void create ()
{
  set ("short", "¶«ÃÅ");
  set ("long", @LONG

ÕâÊÇÎÚ¼¦¹úµÄ¶«ÃÅ³ÇÂ¥£¬ÇàÊ¯Öş³ÉÁ½²ãÂ¥Ì¨¼á¹ÌÒì³££¬Î¡¶ë
¿íÀ«µÄ¹°ĞĞ³ÇÃÅÉÏ·½ïÎ×Å[1;31m¡¸ÎÚ¼¦¹ú¡¹[2;37;0mÈı¸öºìÆá´ó×Ö¡£ 
LONG);

  set("exits", ([ /* sizeof() == 2 */
    "east" : __DIR__"street2",
    "west" : __DIR__"estreet",
  ]));
  set("outdoors", __DIR__"");

  setup();
}

int valid_leave (object who, string dir)
{
  if (dir != "west" && !interactive(who))
    return 0;
  return ::valid_leave(who, dir);
}
