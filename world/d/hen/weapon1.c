// by happ@YSZZ
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "×óÊÖÎäÆ÷ÉÌµê");
  set ("long", @LONG

[37m         [32;47m     ¨y¨y¨y¨y¨y¨y¨y¨y¨y¨y¨y¨y¨y¨y¨y¨y¨y¨y¨y¨y      [1;37;40m¨†
[37m         [1;31;47m     [37;42m £×£Å£Á£Ð£Ï£Î£Ó  £Ó£Ô£Ï£Ò£Å  ×óÊÖÎäÆ÷µê [31;47m      [37;40m¨†
[37m         [32;47m     [37;42m¨{¨{¨{¨{¨{¨{¨{¨{¨{¨{¨{¨{¨{¨{¨{¨{¨{¨{¨{¨{[1;47m      [40m¨†
[37m      [1m   ¨Š[47m¡ö¡ö¡ö[33;46mùÝùùùùùùùÞùùùùùùùÞùùùùùùùÞùùùùùùùß[37;47m¡ö¡ö¡ö¨Š[m
[37m      [1m   ¨Š[47m¡ö¡ö¡ö[33;46mùàùùùùùùùáùùùùùùùáùùùùùùùáùùùùùùùâ[37;47m¡ö¡ö¡ö¨Š[m
[37m      [1m   ¨Š[47m¡ö¡ö¡ö[33;44m©¦      ©¦      ©¦      ©¦      ©¦[37;47m¡ö¡ö¡ö¨Š[m
[37m      [1m   ¨Š[47m¡ö¡ö¡ö[33;44m©À©¤©¤©¤©à©¤©¤©¤ùø©¤©¤©¤©à©¤©¤©¤©È[37;47m¡ö¡ö¡ö¨Š[m
[37m      [1m   ¨Š[47m¡ö¡ö¡ö[33;44m©¦©n©n©n©¦©n©n©n©¦©n©n©n©¦©n©n©n©¦[37;47m¡ö¡ö¡ö¨Š[m
[37m      [1m   ¨Š[47m¡ö¡ö¡ö[32;43m©¦¡ù¡ù¡ù©¦¡ù¡ù¡ù©¦¡ù¡ù¡ù©¦¡ù¡ù¡ù©¦[37;47m¡ö¡ö¡ö¨Š[m
[1;33m      ¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰[m
[37m  [1;41m [NO]  [Æ÷¾ßÃû]  [ÌåÁ¦]  [·¨Á¦]  [ËÙ¶È]  [¹¥»÷]  [·ÀÓù]  [ËÙ¶È]  [ÊÛ  ¼Û][m
   ( 1)  ´óÄ¾°ô        0       0       0       5       0       0      1000
   ( 2)  ½ðÊô°âÊÖ      0       0       0      10       0       0      1500
   ( 3)  Ä¾¶Ü          0       0       0       0      10       0      2000
   ( 4)  ²»Ðâ¸Ö¶Ü     60       0       0       0      25       0      5000
   ( 5)  °×½ðÖ®¶Ü     80       0       0      10      40       0     15000
   ( 6)  Ä§·¨¶Ü       80     100       0      20      60       0     80000
   ( 7)  »Æ½ðÊ¥¶Ü    300     300     300      30     100       0    150000
   [1;41m                                                                       [m 
LONG);

  set("exits", ([ /* sizeof() == 4 */
         "south": __DIR__"miscshop",
]));

        setup();
}
void init()
{
        object ob = this_player();
        ob->command_function("cls");
        add_action("do_buy","buy");
}

int do_buy(string arg)
{
        object ob = this_player();

        if(!present("zhandou ji",ob)) return 0;


        switch(arg)
        {
                case "1":
                {
                if( ob->query("hen/money") < 1000 )
                        {
                        write("ÄãµÄÇ®²»¹»ÓÃÀ­£¡\n");
                        return 1;
                        }
                if( ob->query("hen/inventory/damugun") )
                        {
                        write("ÄãÒÑ¾­ÓÐÍ¬ÑùµÄ×°±¸ÁË£¡\n");
                        return 1;
                        }
                ob->add("hen/money", -1000);
                ob->set("hen/attack",ob->query("hen/attack")+5);
                write(HIC"ÄãÂòÏÂÁËÒ»¸ö´óÄ¾¹÷¡££¨¹¥»÷¼Ó£µµã£©\n"NOR);
                ob->set("hen/inventory/damugun",1);
                break;
                }

                case "2":
                {
                if( ob->query("hen/money") < 1500 )
                        {
                        write("ÄãµÄÇ®²»¹»ÓÃÀ­£¡\n");
                        return 1;
                        }
                if( ob->query("hen/inventory/jinshubanshou") )
                        {
                        write("ÄãÒÑ¾­ÓÐÍ¬ÑùµÄ×°±¸ÁË£¡\n");
                        return 1;
                        }
                ob->add("hen/money", -1500);
                ob->set("hen/attack",ob->query("hen/attack")+10);
                write(HIC"ÄãÂòÏÂÁËÒ»¸ö½ðÊô°âÊÖ¡££¨¹¥»÷¼Ó£±£°µã£©\n"NOR);
                ob->set("hen/inventory/jinshoubanshou",1);
                break;
                }

                case "3":
                {
                if( ob->query("hen/money") < 2000 )
                        {
                        write("ÄãµÄÇ®²»¹»ÓÃÀ­£¡\n");
                        return 1;
                        }
                if( ob->query("hen/inventory/mudun") )
                        {
                        write("ÄãÒÑ¾­ÓÐÍ¬ÑùµÄ×°±¸ÁË£¡\n");
                        return 1;
                        }
                ob->add("hen/money", -2000);
                ob->set("hen/defence",ob->query("hen/defence")+10);
                write(HIC"ÄãÂòÏÂÁËÒ»¸öÄ¾¶Ü¡££¨·ÀÓù¼Ó£±£°µã£©\n"NOR);
                ob->set("hen/inventory/mudun",1);
                break;
                }


                case "4":
                {
                if( ob->query("hen/money") < 5000 )
                        {
                        write("ÄãµÄÇ®²»¹»ÓÃÁË£¡\n");
                        return 1;
                        }
                if( ob->query("hen/inventory/gttoukui") )
                        {
                        write("ÄãÒÑ¾­ÓÐÍ¬ÑùµÄ×°±¸ÁË£¡\n");
                        return 1;
                        }
                ob->add("hen/money", -5000);
                ob->set("hen/defence",ob->query("hen/defence")+25);
                ob->set("hen/life",ob->query("hen/life")+60);
                write(HIC"ÄãÂòÏÂÁËÒ»¸ö¸ÖÌúÍ·¿ø¡££¨·ÀÓù+25,ÌåÁ¦+60£©\n"NOR);
                ob->set("hen/inventory/gttoukui",1);
                break;
                }


                case "5":
                {
                if( ob->query("hen/money") < 15000 )
                        {
                        write("ÄãµÄÇ®²»¹»ÓÃÁË£¡\n");
                        return 1;
                        }
                if( ob->query("hen/inventory/baijindun") )
                        {
                        write("ÄãÒÑ¾­ÓÐÍ¬ÑùµÄ×°±¸ÁË£¡\n");
                        return 1;
                        }
                ob->add("hen/money", -15000);
                ob->add("hen/defence",ob->query("hen/defence")+40);
                ob->set("hen/life",ob->query("hen/life")+80);
                ob->set("hen/attack",ob->query("hen/attack")+10);
                write(HIC"ÄãÂòÏÂÁËÒ»¸ö°×½ðÖ®¶Ü¡££¨·ÀÓù+40,ÌåÁ¦+80,½ø¹¥+10£©\n"NOR);
                ob->set("hen/inventory/baijindun",1);
                break;
                }

                case "6":
                {
                if( ob->query("hen/money") < 80000 )
                        {
                        write("ÄãµÄÇ®²»¹»ÓÃÁË£¡\n");
                        return 1;
                        }
                if( ob->query("hen/inventory/mofadun") )
                        {
                        write("ÄãÒÑ¾­ÓÐÍ¬ÑùµÄ×°±¸ÁË£¡\n");
                        return 1;
                        }
                ob->add("hen/money", -80000);
                ob->add("hen/defence",ob->query("hen/defence")+60);
                ob->set("hen/life",ob->query("hen/life")+80);
                ob->set("hen/fali",ob->query("hen/fali")+100);
                ob->set("hen/attack",ob->query("hen/attack")+20);
                write(HIC"ÄãÂòÏÂÁËÒ»¸öÄ§·¨¶Ü¡££¨·ÀÓù+60,ÌåÁ¦+80,·¨Á¦+100,½ø¹¥+20£©\n"NOR);
                ob->set("hen/inventory/mofadun",1);
                break;
                }

                case "7":
                {
                if( ob->query("hen/money") < 150000 )
                        {
                        write("ÄãµÄÇ®²»¹»ÓÃÁË£¡\n");
                        return 1;
                        }
                if( ob->query("hen/inventory/hjdun") )
                        {
                        write("ÄãÒÑ¾­ÓÐÍ¬ÑùµÄ×°±¸ÁË£¡\n");
                        return 1;
                        }
                ob->add("hen/money", -150000);
                ob->add("hen/defence",ob->query("hen/defence")+100);
                ob->set("hen/life",ob->query("hen/life")+300);
                ob->set("hen/fali",ob->query("hen/fali")+300);
                ob->set("hen/attack",ob->query("hen/attack")+30);
                ob->set("hen/speed",ob->query("hen/speed")+30);
                write(HIC"ÄãÂòÏÂÁËÒ»¸öÄ§·¨¶Ü¡££¨·ÀÓù+60,ÌåÁ¦+80,·¨Á¦+100,½ø¹¥+30\n"NOR);
                ob->set("hen/inventory/hjdun",1);
                break;
                }


        }
        return 1;
}
