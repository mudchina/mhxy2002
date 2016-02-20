// by happ@YSZZ
inherit ROOM;

void create ()
{
  set ("short", "´óÑ§Â·");
  set ("long", @LONG

        ÕâÀïÈ«ÊÇÑ§Ï°µÄµØ·½£¬ÓĞÑ§ÎÄ£¬Ò²ÓĞÑ§ÎäµÄ£¬²»¹ıÕâ¶¼²»ÊÇ
    ÒåÎñ½ÌÓı£¬È«²¿ÒªÊÕ·ÑµÄÅ¶£¬ÄÏÃæÊÇÑ§Ï°[1;44mÀñÒÇ[mµÄ£¬±±ÃæÊÇÑ§Ï°[1;44mÄ§·¨[mµÄ¡£

LONG);

  set("exits", ([ /* sizeof() == 4 */
         "east": __DIR__"xxroad5",
         "west": __DIR__"xxroad3",
          "north": __DIR__"magic",
         "south": __DIR__"liyi",
]));

        setup();
}
