//Cracked by Roath
#include <room.h>
#include <ansi.h>
#include <mudlib.h>
inherit ROOM;
void create()
{
set("short","Âé½«¹İ");
set("long", @LONG
ÕâÊÇÒ»¼ä×¨ÃÅÈÃÍæ¼ÒÃÇĞİÏ¢µÄÓéÀÖ³¡Ëù£¬µ±ÄãÔÚÎªÄãµÄ½ÇÉ«
ĞÁ¿à¶Í  Ê±£¬±ğÍüÁËĞİÏ¢ÊÇÎªÁË×ß¸ü³¤Ô¶µÄÂ·£¬ÕÒÈşÎåºÃÓÑÒ»Í¬
À´´ò¸ö¼¸È¦°É£¬²»¹ı¿É±ğ³ÁÃÔÔÚ¶Ä²©ÖĞà¸¡«¡«¡«¡«ÏêÏ¸µÄ¹æÔòÇë
¿´¿´²¼¸æÀ¸[1;36m£¨£â£ï£á£ò£ä£©[2;37;0m
LONG
);
set("light",1);
set("no_fight", 1);
set("no_magic", 1);
      set("freeze",1);
set("no_spells", 1);
set("exits",([
        "down": "/d/city/clubpoem",
]));
set("objects",([
  __DIR__"mjlady3":1,
]));
set("item_desc",([
"board":"
 Ò»°ã»ù±¾µÄ²Ù×÷£º£º  Ã¿ÖÖÅÆ¶¼ÓĞÆä´úÂë¡¡Àı£ºÒ»Íò£­£¾1w ÆßË÷£­£¾7s
 ¼ÓÈëÅÆ¾Ö   £º"HIY"addin"NOR"        ¿ªÊ¼ÅÆ¾Ö   £º"HIY"start"NOR" 
 ÃşÅÆ       £º"HIY"mo"NOR"           ÖØ¿ªÅÆ¾Ö   £º"HIY"restart"NOR" 
 ¿´Íæ¼Ò1µÄÅÆ£º"HIY".1"NOR"           ¿´Íæ¼Ò2µÄÅÆ£º"HIY".2"NOR" 
 ¿´Íæ¼Ò3µÄÅÆ£º"HIY".3 "NOR"          ¿´Íæ¼Ò4µÄÅÆ£º"HIY".4"NOR" 
 ¿´×Ô¼ºµÄÅÆ £º"HIY"."NOR"
 ¶ªÅÆ       £º"HIY"dump xx"NOR"      ³Ô         £º"HIY"eat xx xx "NOR"        
 Åö         £º"HIY"pon"NOR"          ¸Ü         £º"HIY"gon "NOR"              
 ºú         £º"HIY"hu"NOR"           Ìı         £º"HIY"tin xx  "NOR"          
 xxÎª´úÂë Àı£º"HIY"eat 2w 3w"NOR" 
",
]));
setup();
}
