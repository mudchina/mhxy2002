// by happ@YSZZ
inherit ROOM;
#include <hen.h>

void create ()
{
  set ("short", "Ê³Æ·µê");
  set ("long", @LONG

[1;37m©°¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª©´
[1;31m  ¡ª[37;41m ±àºÅ [31;40m¡ª[37;41m ÉÌ      Æ· [31;40m¡ª¡ª[37;41m Ð§            ÄÜ [31;40m¡ª¡ª[37;41m ¼Û     ¸ñ [31;40m¡ª
[37m     [1;35m[[37m 1[35m]     [36mºÃ³ÔµÄÊ³Îï      [37mÌåÁ¦»Ö¸´50            [33m50           
[37m     [1;35m[[37m 2[35m]     [36mÃÀÎ¶µÄÁãÊ³      [37mÌåÁ¦»Ö¸´100           [33m120          
[37m     [1;35m[[37m 3[35m]     [36mºÃÓÃ´ó²¹Íè      [37mÌåÁ¦»Ö¸´500           [33m500          
[37m     [1;35m[[37m 4[35m]     [36mÕä¹óµÄÁéÖ¥      [37mÌåÁ¦»Ö¸´1000          [33m1000          
[37m     [1;35m[[37m 5[35m]     [36mÇ§ÄêÈË²ÎÍõ      [37m·¨Á¦»Ö¸´500           [33m800          
[37m     [1;35m[[37m 6[35m]     [36mÌìÉ½Ñ©Á«        [37m·¨Á¦ÌåÁ¦×î´ó          [33m10000         
[1;37m©¸¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª©¼
LONG);

  set("exits", ([ /* sizeof() == 4 */
         "west": __DIR__"road3",
]));

        setup();
}

void init()
{
        add_action("do_buy","buy");
}

int do_buy(string arg)
{
        object ob = this_player();

        switch(arg)
        {
                case "1":
                {
                if( ob->query("hen/money") < 50 )
                        {
                        write("ÄãÖ»ÓÐ"+ob->query("hen/money")+"ÔªÁË¡£\n");
                        return 1;
                        }
                cat(BUYFOOD);
                ob->add("hen/inventory/food",1);
                ob->add("hen/money",-50);
                write("ÄãÂòÁËÒ»·ÝÊ³Îï¡£\n");
                break;
                }
                
                case "2":
                {
                if( ob->query("hen/money") < 120 )
                        {
                        write("ÄãÖ»ÓÐ"+ob->query("hen/money")+"ÔªÁË¡£\n");
                        return 1;
                        }
                if( random(2) == 0 )
                cat(BUYLS1);
                cat(BUYLS2);
                ob->add("hen/inventory/lingshi",1);
                ob->add("hen/money",-120);
                write("ÄãÂòÏÂÁËÒ»·ÝÁãÊ³¡£\n");
                break;
                }

                case "3":
                {
                if( ob->query("hen/money") < 500 )
                        {
                        write("ÄãÖ»ÓÐ"+ob->query("hen/money")+"ÔªÁË¡£\n");
                        return 1;
                        }
                cat(BUYDABU);
                ob->add("hen/inventory/dabu",1);
                ob->add("hen/money",-500);
                write("ÄãÂòÁËÒ»¿Å´ó²¹Íè¡£\n");
                break;
                }

                case "4":
                {
                if( ob->query("hen/money") < 1000 )
                        {
                        write("ÄãÖ»ÓÐ"+ob->query("hen/money")+"ÔªÁË¡£\n");
                        return 1;
                        }
                write("ÄãÂòÁËÒ»¿ÅÁéÖ¥¡£\n");
                ob->add("hen/inventory/lingzhi",1);
                ob->add("hen/money",-1000);
                break;
                }
               
                case "5":
                {
                if( ob->query("hen/money") < 800 )
                        {
                        write("ÄãÖ»ÓÐ"+ob->query("hen/money")+"ÔªÁË¡£\n");
                        return 1;
                        }                write("ÄãÂòÁËÒ»¿ÅÈË²Î¡£\n");
                ob->add("hen/inventory/renshen",1);
                ob->add("hen/money",-800);
                break;
                }
                case "6":
                {
                if( ob->query("hen/money") < 10000 )
                        {
                        write("ÄãÖ»ÓÐ"+ob->query("hen/money")+"ÔªÁË¡£\n");
                        return 1;
                        }
                write("ÄãÂòÁËÒ»¿ÅÑ©Á«¡£\n");
                ob->add("hen/inventory/xuelian",1);
                ob->add("hen/money",-1000);
                break;
                }
        }
return 1;
}

