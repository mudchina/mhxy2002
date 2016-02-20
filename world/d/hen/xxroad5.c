// by happ@YSZZ
inherit ROOM;

void create ()
{
  set ("short", "´óÑ§Â·");
  set ("long", @LONG

        ÕâÀïÈ«ÊÇÑ§Ï°µÄµØ·½£¬ÓĞÑ§ÎÄ£¬Ò²ÓĞÑ§ÎäµÄ£¬²»¹ıÕâ¶¼²»ÊÇ
    ÒåÎñ½ÌÓı£¬È«²¿ÒªÊÕ·ÑµÄÅ¶£¬ÄÏÃæÊÇÑ§Ï°[33mÎèµ¸[mµÄ£¬±±ÃæÊÇÑ§Ï°[1;33m»æ»­[0mµÄ¡£

LONG);

  set("exits", ([ /* sizeof() == 4 */
         "west": __DIR__"xxroad4",
          "north": __DIR__"huihua",
         "south": __DIR__"wudao",
]));

        setup();
}
