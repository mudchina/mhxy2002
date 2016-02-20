// Room: /city/lichunyuan.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "Àö´ºÔº");
	set("long", @LONG
ÄãÒ»×ß½øÀ´£¬Ò»ÑÛ¾Í¿´µ½´óÌüµÄÇ½ÉÏ¹Ò×ÅÒ»·ù·ù´º¹¬Í¼[1;31m(tu)[2;37;0m£¬Ò»ÏÂ×Ó¾Í
Ã÷°×ÁËÕâÊÇÊ²Ã´µØ·½¡£ÌüÄÚµ½´¦ÕÅµÆ½á²Ê£¬ÏãÆøÆË±Ç¡£¼¸Ãû´ò°çµÃÑýÀïÑýÆø
µÄÅ®ÈË·ÖÕ¾Á½ÅÔ¶ÔÄã·¢³öÃÄÐ¦¡£Ö÷ÈËÎ¤´º·¼ÉÏÉÏÏÂÏÂ¡¢Ç°Ç°ºóºóÕÐºô×Å¿ÍÈË¡£
´ÓÂ¥ÉÏ´«À´ÁËÕóÕó´òÇéÂîÇÎµÄÉùÒô¡£
LONG );
	set("objects", ([
                __DIR__"npc/wei" : 1,
	]));

	set("item_desc", ([
		"tu" :
"                                      ¦¯        ¦¯          ¦¯             
                                    ©°©¦        ©¦          ©¦
      ©°¡ª¦¯©°¡ª  ¡ª©Ð¡ª¡ª¦¯        ©¦©È      ©°©¼          ©¸©´
    ¡ª©¼¦¯¡ª©¼    ¡ª¡ª¡ª¡ª¦¯  ¦¯¡ª¡ª©¼©¦  ¦¯¡ª©à©Ø¡ª  ¦¯¡ª¡ª©Ø©à


   ¦¯       ¦¯    ¦¯¦¯¦¯                 ¦¯                  ¡ð
   ©¦       ©¦    ©¦©À©à       ©°¡ª¦¯  ©°©à                  ©¦
   ©À ¦¯©Ð©´©È    ©À©¸©à©´   ¡ª©¼¦¯¡ª¡ª©¼©È          ¡ð©Ð¡ª©´©È
   ©¦   ©¼©¸©¦    ©¦  ©¦                 ©¸            ©¦  ©¦©¦
	\n"]));
	set("exits", ([
                 "northwest"  : __DIR__"wside5",
		"up"    : __DIR__"lichunyuan2",
	]));

//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

