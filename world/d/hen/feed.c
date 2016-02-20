// by happ@YSZZ

#include <hen.h>
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "Î¹Ê³");
  set ("long", @LONG

        ÔÚÕâÄã¿ÉÒÔÓÃ[1;33m feed[m Ö¸ÁîÎ¹ÑøÄãµÄÐ¡¼¦¡£
 
        [1;33m feed 1 £º[m³Ô·¹          [1;33mfeed 2 £º [m³ÔÁãÊ³  
        [1;33m feed 3 £º[m²¹Íè          [1;33mfeed 4 £º [m³ÔÁéÖ¥
        [1;33m feed 5 £º[mÈË²Î          [1;33mfeed 6 £º [m³ÔÑ©Á«

LONG);

  set("exits", ([ /* sizeof() == 4 */
         "west": __DIR__"road1",
]));

        setup();
}

void init()
{
        add_action("do_feed","feed");
}

int do_feed(string arg)
{
        object ob = this_player();

        if( ! present("zhandou ji",ob) )   return 0;
        ob->command_function("cls");


        switch(arg)
        {
                case "1":
                {
                if( ob->query("hen/inventory/food")  < 1 )
                        return notify_fail("ÄãµÄÊ³Îï²»¹»ÁË£¬¿ìÈ¥Âò°É£¡\n");
                switch(random(3))
                {
                case 1:
                cat(EAT);
                break;
                case 0:
                cat(DRINK);
                break;
                case 2:
                cat(MILK);
                break;
                }
                ob->add("hen/life",50);
                break;
                }

                case "2":
                {
                if( ob->query("hen/inventory/lingshi")  < 1 )
                        return notify_fail("ÄãµÄÁãÊ³²»¹»ÁË£¬¿ìÈ¥Âò°É£¡\n");

                cat(FOOD);

                ob->add("hen/life",100);

                ob->query("hen/happy") < 95 ?
                ob->add("hen/happy",5+random(3)) :
                ob->set("hen/happy",100);
                ob->add("hen/weight",1);
                break;
                }

                case "3":
                {
                if( ob->query("hen/inventory/dabu")  < 1 )
                return notify_fail("ÄãµÄ´ó²¹²»¹»ÁË£¬¿ìÈ¥Âò°É£¡\n");

                cat(EATDABU);
                ob->add("hen/life",500);
                break;
                }

                case "4":
                {
                if( ob->query("hen/inventory/lingzhi")  < 1 )
                        return notify_fail("ÄãµÄÁéÖ¥Ã»ÓÐÁË£¬¿ìÈ¥Âò°É£¡\n");

                write(HIC"Äã¼ÓÁË 1000 µãµÄÉúÃüÁ¦£¡\n"NOR);

                ob->add("hen/life",1000);
                break;
                }

                case "5":
                { 
                       if( ob->query("hen/inventory/renshen")  < 1 )
                        return notify_fail("ÄãµÄÈË²Î²»¹»ÁË£¬¿ìÈ¥Âò°É£¡\n");

                write(HIC"Äã¼ÓÁË 500 µãµÄ·¨Á¦£¡\n"NOR);

                ob->query("hen/fali") + 500 > ob->query("max_fali") ?
                ob->set("hen/fali",ob->query("max_fali")) :
                ob->add("hen/fali",1000);

                break;
                }
                
                case "6":
                {
                if( ob->query("hen/inventory/xuelian")  < 1 )
                        return notify_fail("ÄãµÄÑ©Á«²»¹»ÁË£¬¿ìÈ¥Âò°É£¡\n");

                write(HIC"ÄãµÄ·¨Á¦¼Óµ½ÁË×î´ó£¡\n"NOR);
                ob->set("hen/fali",ob->query("hen/max_fali"));
                break;
                }
        }

        ob->command_function("shape");

        return 1;
}
