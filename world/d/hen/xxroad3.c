// by happ@YSZZ
inherit ROOM;

void create ()
{
  set ("short", "´óÑ§Â·");
  set ("long", @LONG

        ÕâÀïÈ«ÊÇÑ§Ï°µÄµØ·½£¬ÓĞÑ§ÎÄ£¬Ò²ÓĞÑ§ÎäµÄ£¬²»¹ıÕâ¶¼²»ÊÇ
    ÒåÎñ½ÌÓı£¬È«²¿ÒªÊÕ·ÑµÄÅ¶£¬ÄÏÃæÊÇÑ§Ï°[1;35m¸ñ¶·[mµÄ£¬±±ÃæÊÇÑ§Ï°[1;35m½£Êõ[mµÄ¡£

LONG);

  set("exits", ([ /* sizeof() == 4 */
         "east": __DIR__"xxroad4",
         "west": __DIR__"xxroad2",
          "north": __DIR__"jianshu",
         "south": __DIR__"gedou",
]));

        setup();
}
