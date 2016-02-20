//Cracked by Roath
// create by snowcat.c 4/8/1997
// room: /d/westway/jiayu.c

inherit ROOM;

void create ()
{
  string dir;
  set ("short", "¼ÎÓø¹Ø");
  set ("long", @LONG

Ò»×ùĞÛÎ°µÄ¹Ø¿Ú×øÂäÔÚÈºÉ½Ö®ÖĞ£¬¼ÎÓø¹ØÊÇ³¤³Ç×îÎ÷µÄ¹Ø¿Ú£¬
ÕòÊØ´óÌÆ¹úµÄÎ÷Óò´óÃÅ¡£¹ØÍâÏòÎ÷±ãÊÇÍ¨ÏòÎ÷Óò¸÷¹úµÄ¼èÄÑ
µÀÂ·£¬Ö»¼ûÎ÷ÃæÒ»Æ¬Ã£Ã£´óÎíÈçº£Ò»°ã»Ğ»Ğã±ã±Ê²Ã´Ò²¿´²»
¼û¡£¹ØÄÚÏò¶«Í¨Ïò´óÌÆ¹ú¸÷µØ£¬ÄÏ±ßÓĞÒ»¸öĞ¡Ğ¡³ö¿ÚÓë·ä»ğ
Ì¨ÏàÁ¬¡£

LONG);

/*
  dir = __DIR__;
  dir[strlen(dir)-8] = 0;
*/
  dir = "/d/qujing/";
  set("exits", ([
        "east"      : __DIR__"shizhan",
 "north"      : "/d/zhuxian/xiaolu8",
              "west"      : "/d/qujing/guanwai",
        "southup"   : __DIR__"fenghuo",
      ]));
  set("objects", ([
                __DIR__"npc/wujiang": 2 ]) );

  set("outdoors", __DIR__);

  setup();
}

int valid_leave (object me, string dir)
{
  	if (dir == "west"){
    		message_vision ("[1;37m$NÏòÎ÷Ò»Ô¾£¬³å½øÃ£Ã£´óÎíÖĞ£¡[2;37;0m\n",me);
  	}
	if (dir == "southup" ) {
  	if (objectp(present("wu jiang", environment(me))))
        return notify_fail("±ß¹ØÊØ½«ÈÂµ½£ºÄÇ²»ÊÇÄã¸ÃÈ¥µÄµØ·½£¡\n");
        }
  return 1;
}


