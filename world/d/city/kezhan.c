//By tianlin@mhxy for 2001.5.1
inherit ROOM;
#include <ansi.h>

int block_cmd(string);
void create ()
{
  set ("short",YEL"ÄÏ³Ç¿ÍÕ»"NOR);
  set ("long", @LONG

   [1;32m[1;35m*[2;37;0m[1;32m/. [2;37;0m   [1;35m.   .    [1;36m*     [1;35m .   [1;36m*         [1;33m×£[2;37;0m
  .[1;32m\[1;35m*[2;37;0m [2;37;0m   [1;35m.    [1;33m[][2;37;0m           [1;36m*[2;37;0m [35m.__         [1;33mÄã[2;37;0m
? [1;32m[1;35m*[2;37;0m[1;32m/ .[2;37;0m  [1;35m.[1;31m./\~~~~~~~~~~~~'[31m\. [2;37;0m[35m| [31m¡ô[2;37;0m         [1;33m¿ì[2;37;0m
   [1;32m\[1;35m*[2;37;0m   [1;31m,/,.\,...........,\.[2;37;0m[35m| [31m¡ô[2;37;0m [1;35m.       [1;33mÀÖ[2;37;0m
   [1;31m||[2;37;0m  [1;35m..[1;30m¨†[2;37;0m[1;34m#[2;37;0m  [1;30m¨†[2;37;0m[1;34mÌï  Ìï[2;37;0m [1;30m¨†[2;37;0m[1;30m | [1;30m¨†[2;37;0m[31m¡ô[2;37;0m          [1;33m£¡[2;37;0m 
   [1;31m||[2;37;0m [1;32m &&[1;30m¨†[2;37;0m   [1;30m¨†[2;37;0m       [1;30m¨†[2;37;0m[1;30m'|'[1;30m¨†[2;37;0m [1;36mo [2;37;0m [1;35m..[2;37;0m  
   [1;31m||[2;37;0m [1;32m##[1;36m¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ş¨{¨z¨y¨x[2;37;0m

Èç¹ûÄúÏ²»¶ÕâÀï,Çë×ª¸æ¸øÄúµÄÅóÓÑ¡£

Õâ¼Ò¿ÍÕ»½ô¿¿³¤°²³ÇÖĞĞÄ£¬ËùÒÔÉúÒâ·Ç³£ĞËÂ¡¡£¼æÖ®¼ÛÇ®µÍÁ®£¬¸üÊÇ
³ÉÁËÍâµØÓÎ¿ÍÂä½ÅµÄÊ×Ñ¡¡£Â¶Ìì°ÚÁËÆß°ËÕÅ×À×Ó£¬Èı½Ì¾ÅÁ÷ÈËµÈÔÚ´Ë
½ø½ø³ö³ö£¬ÂçÒï²»¾ø£¬¼¸¸öÅÜÌÃµÄĞ¡¶şÀ´À´»Ø»ØÕĞ´ı×ÅËÄ·½À´¿Í¡£¶ş
Â¥ÉÏÊÇÑÅÌü£¬ºóÃæÊÇ¿Í·¿¡£
LONG);
  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"sleep",
  "west" : __DIR__"zhuque-s1",
  "north" : "/d/city/misc/idleroom",
  "enter" : "/d/hen/room",
  "up": "/d/wiz/entrance",
   "south": "/d/city/chatroom",
]));
  set("chat_room",1);
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/xiaoer" : 1,
  __DIR__"npc/huangfeihong" : 1,
  "/d/ourhome/npc/bigeye" : 1,
   "/u/tianlin/npc/wukong3" : 1,
  ]));
  set("no_time",1);

   set("no_time", 1);
  set("no_fight", 1);
  set("no_magic", 1);
        set("freeze",1);
  set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));
  set("valid_startroom", 1);
  setup();
  call_other("/obj/board/nancheng_b", "???");
}

void init()
{
    add_action("block_cmd", "", 1);
       add_action("do_exert", "exert");
}

int block_cmd(string args)
{
string verb;
verb = query_verb();

    // if (verb == "bian") return 1; // by mon 7/15
    if (verb == "xiudao") return 1;
    if(! wizardp (this_player())) 
    if (verb == "who") return 1;//by tianlin 2001.9.18
    return 0;
}

int valid_leave(object me, string dir)
{
        object ob = this_player();
        object mbox,*inv;
        inv = all_inventory(me);
        if ( sizeof(inv)&& dir == "north" ) return notify_fail("µêĞ¡¶ş²»»³ºÃÒâµÄ¶ÔÄãËµ£ºÕâÎ»¿Í¹Ù£¬½ø·¢´ôÊÒÇ°Çë½«ÉíÉÏµÄÎï¼şÇå¿Õ¡£\n");

        if ( !me->query_temp("rent_paid") && dir == "east" )
        return notify_fail("µêĞ¡¶şÂúÁ³¶ÑĞ¦µØµ²×¡ÁËÄã£º¶Ô²»Æğ£¬ºóÃæÊÇ¿ÍÈËµÄÎÔ·¿£¬²»ÊÇ±¾µêµÄ¿ÍÈË£¬²»±ã´òÈÅ¡£\n");
        if( mbox = me->query_temp("mbox_ob") ) {
                tell_object(me, "Äã½«ĞÅÏä½»»Ø¸øÓÊ²î¡£\n");
                destruct(mbox);
        }
        if (dir == "enter"){
                message_vision ("[36m¡¾[2;37;0m[1;36mÏµÍ³¾«Áé[2;37;0m[36m¡¿[2;37;0m[36m(monitord): [2;37;0m[1;31mÈÈÁÒ»¶Ó­$NÀ´µ½¶·¼¦ÊÒ.\n"NOR,me);
        }
        return ::valid_leave(me, dir);
}
int do_exert(string arg)
{
    tell_object(this_player(), "°²È«ÇøÄÚ½ûÖ¹ÔË¶¯¡£\n");
    return 1;
}

