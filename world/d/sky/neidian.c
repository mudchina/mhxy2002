// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
 
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "[33mÄÚµî[m");
  set ("long", @LONG
ÕâÀï¾ÍÊÇÓñµÛµÄ±¦×ùÁË,×ùÉÏÄÇÈËÒÂ×ÅÊ®·Ö»ªÀö,µ«ÒşÒş¸øÈËÓ¹Ë×µÄ¸Ğ¾õ,
ÓÈÆäÊÇÄÇÙÆ°ÁµÄÉñÆø,ÈÃÈË¿´×Å¾ÍÏë±âËûÒ»¶Ù.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"dadian.c",
]));


  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yudi" : 1,
]));

  setup();
}


void init()
{
    add_action("block_cmd", "", 1);
}

int block_cmd(string args)
{
string verb;
verb = query_verb();

    if (verb == "fight") return 1;
    if (verb == "pray") return 1;
    if (verb == "ji") return 1;
    if (verb == "cast") return 1;    
    return 0;
}
