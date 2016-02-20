//ÆåÔ·

#include <ansi.h>
inherit  ROOM;

string look_string();

void  create  ()
{
    set  ("short",  "ÆåÔ·");
    set  ("long", 
"ÆåÔ·¹²·ÖËÄ¸ö´ó¼ä£¬ÊÇÊÖÌ¸ĞİÆÜµÄºÃµØ·½¡£ÕâÀïµÄÄÏ±±ºÍÎ÷Èı¸ö·½
Ïò¸÷ÓĞÒ»¼äÆåÊÒ£¬ÔÚÃ¿¸öÆåÊÒµÄÃÅÍâ¶¼Ìù×Å"HIY"ÇëÎğ´òÈÅÆå¾Ö"NOR"µÄ
ÅÆ×Ó£¬ÔÚ·¿¼äÖĞÑëµÄÖù×ÓÉÏ»¹Ìù×ÅÒ»ÕÅÏÂÆåÖ¸ÄÏ(help)¡£
");

  set("no_dazuo",1);set("no_kill",1);set("no_fight",1);
         set("no_steal",1);
         set("no_magic", "1");
         set("no_perform", "1");
         set("pingan",1);
         set("no_beg",1); 	
    set("item_desc", ([
    "help" : ( : look_string : ),
    ]));

    set("exits",  ([
    "east"  :  __DIR__"qiyuan2",
    "south"  :  __DIR__"qiyuan3",
    "north"  :  __DIR__"qiyuan4",
    "west" : "/d/city/clubpoem",
    ]));

     set("objects",  ([
    __DIR__"cch"  :  1,
    ]));
   setup();
}

string look_string()
{
	string  msg  =  "[5m[1;32m»¶Ó­[2;37;0m[1;31mÄú[2;37;0mÀ´ÏÂ[1;36mÏóÆå£¡[2;37;0m\n"  +
"
¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª
[1;36mÖĞ¹úÏóÆå[2;37;0m£¨cchess£©
¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª
ÏÂ×Ó   £º[1;33mmove[2;37;0m [37m<ºá×ù±ê> <×İ×ù±ê>[2;37;0m [1;33mto[2;37;0m [37m<ºá×ù±ê> <×İ×ù±ê>[2;37;0m
ÖØÏÂ      £º[1;33mreset[2;37;0m
¶Á³ö²Ğ¾Ö  £º[1;33mdeploy[2;37;0m
¼ÇÂ¼²Ğ¾Ö  £º[1;33mcsave[2;37;0m
ÖÀ÷»      £º[1;33mtoss[2;37;0m
»Ø¹Ë      £º[1;33mreview[2;37;0m
ÈÏÊä   £º[1;33mlose[2;37;0m


";
	return  msg;
}

int valid_leave(object me, string dir)
{
        object room;
        mapping exit;

        exit = environment(me)->query("exits");

        if ( dir == "south" || dir == "north" || dir == "west" ) {
                if( !( room = find_object(exit[dir])) )
                       room = load_object(exit[dir]);
	        if( room->query_temp("action")  ==  1 )
                       return notify_fail("ÄÇ¼äÆåÊÒÒÑ¾­ÓĞÈË¿ªÊ¼ÏÂÆåÁË£¬ÇëÎğ´òÈÅ\n");
                }

        return ::valid_leave(me, dir);
}
