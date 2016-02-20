// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
 
// Room: some place in Î÷Å£ºØÖŞ
// inside2.c

inherit ROOM;

void create ()
{
  set ("short", "[0;36mºóÀÈ[m");
  set ("long", @LONG

ËäÖ»ÊÇÒ»Ç½Ö®¸ô£¬Ç°ÌÃµÄĞú»©È´Ò»µãÒ²Ìı²»¼ûÁË¡£×óÓÒ¶¼ÊÇÖñ
ÁÖ£¬Î¢·ç´µ¹ı£¬ÁÖÖĞ·¢³ö»©»©µÄÏìÉù¡£ÀÈ±ßµÄÄ¾ÖùÏÔµÃÏàµ±³Â
¾É£¬È´Ò»³¾²»È¾£¬Ò²ĞíÓĞÈËÊ±³£´òÉ¨¡£ÍäÍäÇúÇúµÄÄ¾ÀÈÍ¨ÏòÖñ
ÁÖÉî´¦¡£
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"houlang3",
  "southeast" : __DIR__"houlang1",
]));

  setup();
}
