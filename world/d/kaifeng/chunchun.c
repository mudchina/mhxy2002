//By tianlin@mhxy for 2001.9.18²¿·ÖĞŞ¸Ä
inherit ROOM;

void create ()
{
  set ("short", "´º´¼²èÕ»");
  set ("long", @LONG
²èÕ»Àï°ÚÁË¼¸ÕÅºìÄ¾×À×Ó£¬Î§×Å×À×Ó·ÅÁË¼¸Ìõ³¤µÊ¡£´Ë´¦´°Ã÷¼¸¾»£¬
ÂúÎİÆ®×Å²èÏã¡£ÀïÇ½ÊÇ¹ñÌ¨£¬ÉÏÃæ·ÅÂúÁË´óĞ¡²»Í¬µÄ²èÍ²²è¹Ş¡£¶«±ß
ÃÅÁ±Í¨Ïò½ÖÍ·¡£µêÆÌÇ°¹ÒÁËÒ»¸öĞ¡Ğ¡µÄÕĞÅÆ[1;33m£¨paizi£©[2;37;0m¡£
LONG);

  set("objects", ([ /* sizeof() == 1 */
   __DIR__"npc/chaniang" : 1,
    __DIR__"npc/xiaoer" : 1,
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "paizi" : "±¾µê¼±Ğè¹¤×÷ÈËÔ±£¬ÓĞÒâÕßÇëÏò²èÄï×Ó´òÌı[¹¤×÷]µÄÊÂ¡£
             °ïÖúÌáÊ¾:[1;32m1.[1;33mask xiao er about job[2;37;0m
                      [1;32m2.[1;33mask guan shi about panzi[2;37;0m 
                      [1;32m3.[1;33mGo ³ø·¿ xi ÔàÅÌ×Ó[2;37;0m
                      [1;32m4.[1;33mgive panzi to xiao er[2;37;0m 
                      [1;32m5.[1;33m½üÆÚ²»ÕĞ¹¤[2;37;0m
",
]));
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"shun5",
  "west" : __DIR__"sleeproom",
 "north" : __DIR__"chufang",
]));
  set("pingan", 1);
  set("no_dazuo",1);set("no_kill",1);set("no_fight",1);
  set("no_dazuo", 1);
  set("no_kill", 1);
  set("valid_startroom", 1);

  setup();
//  replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
        object *inv,kicker;
        int sizeinv,n,tt;
        
        if (dir =="west")
        {
                if ( me->query("PKS") >= 3)
                return notify_fail("ÄãÉ±¹ıÌ«¶àµÄÍæ¼Ò£¡Õâ¶ù²»»¶Ó­Äã£¡\n");        
        
                inv=all_inventory(me);
                sizeinv=sizeof(inv);
        
                while (sizeinv--)
                {
                        if (inv[sizeinv]->is_character())  
                                return notify_fail("ÄãÏë½øÈ¥¹ÕÂôÈË¿Ú£¿\n");
                
                }
                
        }

        return ::valid_leave(me, dir);
}

