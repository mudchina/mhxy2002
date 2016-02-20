// by happ@YSZZ
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "½Å²¿ÎäÆ÷ÉÌµê");
  set ("long", @LONG

[37m         [32;47m     ¨y¨y¨y¨y¨y¨y¨y¨y¨y¨y¨y¨y¨y¨y¨y¨y¨y¨y¨y¨y      [1;37;40m¨†
[37m         [1;31;47m     [37;42m £×£Å£Á£Ð£Ï£Î£Ó  £Ó£Ô£Ï£Ò£Å  ½Å²¿ÎäÆ÷µê [31;47m      [37;40m¨†
[37m         [32;47m     [37;42m¨{¨{¨{¨{¨{¨{¨{¨{¨{¨{¨{¨{¨{¨{¨{¨{¨{¨{¨{¨{[1;47m      [40m¨†
[37m      [1m   ¨Š[47m¡ö¡ö¡ö[33;46mùÝùùùùùùùÞùùùùùùùÞùùùùùùùÞùùùùùùùß[37;47m¡ö¡ö¡ö¨Š[m
[37m      [1m   ¨Š[47m¡ö¡ö¡ö[33;46mùàùùùùùùùáùùùùùùùáùùùùùùùáùùùùùùùâ[37;47m¡ö¡ö¡ö¨Š[m
[37m      [1m   ¨Š[47m¡ö¡ö¡ö[33;44m©¦      ©¦      ©¦      ©¦      ©¦[37;47m¡ö¡ö¡ö¨Š[m
[37m      [1m   ¨Š[47m¡ö¡ö¡ö[33;44m©À©¤©¤©¤©à©¤©¤©¤ùø©¤©¤©¤©à©¤©¤©¤©È[37;47m¡ö¡ö¡ö¨Š[m
[37m      [1m   ¨Š[47m¡ö¡ö¡ö[33;44m©¦©n©n©n©¦©n©n©n©¦©n©n©n©¦©n©n©n©¦[37;47m¡ö¡ö¡ö¨Š[m
[37m      [1m   ¨Š[47m¡ö¡ö¡ö[32;43m©¦¡ù¡ù¡ù©¦¡ù¡ù¡ù©¦¡ù¡ù¡ù©¦¡ù¡ù¡ù©¦[37;47m¡ö¡ö¡ö¨Š[m
[1;33m      ¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰[m
[37m  [1;41m [NO]  [Æ÷¾ßÃû]  [ÌåÁ¦]  [·¨Á¦]  [ËÙ¶È]  [¹¥»÷]  [·ÀÓù]  [ËÙ¶È]  [ÊÛ  ¼Û][m
   ( 1)  ËÜ½ºÍÏÐ¬      0       0       0       0       0      10       800
   ( 2)  ¶«ÑóÄ¾åì      0       0       0      15       0      10      1000
   ( 3)  ÌØ¼¶ÓêÐ¬      0       0       0       0      10      10      1500
   ( 4)  NIKEÔË¶¯Ð¬   70       0       0       0      10      40      8000
   ( 5)  öùÓãÆ¤Ñ¥     80      20       0      10      25      20     12000
   ( 6)  ·ÉÌìÄ§Ñ¥    100     100       0      30      50      60     25000
   ( 7)  »Æ½ðÊ¥Ñ¥    300     300     300      50     100     100    150000
[1;41m                                                                           [m
LONG);

  set("exits", ([ /* sizeof() == 4 */
         "east": __DIR__"miscshop",
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
                if( ob->query("hen/money") < 800 )
                        {
                        write("ÄãµÄÇ®²»¹»ÓÃÀ­£¡\n");
                        return 1;
                        }
                if( ob->query("hen/inventory/sltx") )
                        {
                        write("ÄãÒÑ¾­ÓÐÍ¬ÑùµÄ×°±¸ÁË£¡\n");
                        return 1;
                        }
                ob->add("hen/money", -800);
                ob->add("hen/speed",10);
                write(HIC"ÄãÂòÏÂÁËÒ»¸öËÜÁÏÍÏÐ¬¡££¨ËÙ¶È¼Ó£±£°£©\n"NOR);
                ob->set("hen/inventory/sltx",1);
                break;
                }

                case "2":
                {
                if( ob->query("hen/money") < 1000 )
                        {
                        write("ÄãµÄÇ®²»¹»ÓÃÀ­£¡\n");
                        return 1;
                        }
                if( ob->query("hen/inventory/dymj") )
                        {
                        write("ÄãÒÑ¾­ÓÐÍ¬ÑùµÄ×°±¸ÁË£¡\n");
                        return 1;
                        }
                ob->add("hen/money", -1000);
                ob->set("hen/attack",ob->query("hen/attack")+15);
                ob->add("hen/speed",10);
                write(HIC"ÄãÂòÏÂÁËÒ»¸ö¶«ÑóÄ¾åì£¨¹¥»÷+15,ËÙ¶È+10£©\n"NOR);
                ob->set("hen/inventory/dymj",1);
                break;
                }

                case "3":
                {
                if( ob->query("hen/money") < 1500 )
                        {
                        write("ÄãµÄÇ®²»¹»ÓÃÀ­£¡\n");
                        return 1;
                        }
                if( ob->query("hen/inventory/tjyx") )
                        {
                        write("ÄãÒÑ¾­ÓÐÍ¬ÑùµÄ×°±¸ÁË£¡\n");
                        return 1;
                        }
                ob->add("hen/money", -1500);
                ob->set("hen/speed",10);
                ob->add("hen/defence",10);
                write(HIC"ÄãÂòÏÂÁËÒ»¸öÌØ¼¶ÓêÐ¬¡££¨ËÙ¶È+10,·ÀÓù+10£©\n"NOR);
                ob->set("hen/inventory/tjyx",1);
                break;
                }


                case "4":
                {
                if( ob->query("hen/money") < 8000 )
                        {
                        write("ÄãµÄÇ®²»¹»ÓÃÁË£¡\n");
                        return 1;
                        }
                if( ob->query("hen/inventory/nike") )
                        {
                        write("ÄãÒÑ¾­ÓÐÍ¬ÑùµÄ×°±¸ÁË£¡\n");
                        return 1;
                        }
                ob->add("hen/money", -8000);
                ob->set("hen/defence",ob->query("hen/defence")+10);
                ob->set("hen/life",ob->query("hen/life")+70);
                ob->add("hen/speed",40);
                write(HIC"ÄãÂòÏÂÁËÒ»¸öNIKEÔË¶¯Ð¬.£¨ËÙ¶È+40,ÌåÁ¦+70,·ÀÓù+10£©\n"NOR);
                ob->set("hen/inventory/nike",1);
                break;
                }


                case "5":
                {
                if( ob->query("hen/money") < 12000 )
                        {
                        write("ÄãµÄÇ®²»¹»ÓÃÁË£¡\n");
                        return 1;
                        }
                if( ob->query("hen/inventory/eypx") )
                        {
                        write("ÄãÒÑ¾­ÓÐÍ¬ÑùµÄ×°±¸ÁË£¡\n");
                        return 1;
                        }
                ob->add("hen/money", -12000);
                ob->add("hen/attack",10);
                ob->add("hen/life",80);
                ob->add("hen/fali",20);
                ob->add("hen/speed",10);
                ob->add("hen/defence",25);
                write(HIC"ÄãÂòÏÂÁËÒ»¸ööùÓãÆ¤Ñ¥¡££¨ÌåÁ¦+80,½ø¹¥+10,ËÙ¶È+10,·ÀÓù+25,·¨Á¦+20£©\n"NOR);
                ob->set("hen/inventory/eypx",1);
                break;
                }

                case "6":
                {
                if( ob->query("hen/money") < 25000 )
                        {
                        write("ÄãµÄÇ®²»¹»ÓÃÁË£¡\n");
                        return 1;
                        }
                if( ob->query("hen/inventory/ftmx") )
                        {
                        write("ÄãÒÑ¾­ÓÐÍ¬ÑùµÄ×°±¸ÁË£¡\n");
                        return 1;
                        }
                ob->add("hen/money", -25000);
                ob->add("hen/attack",30);
                ob->add("hen/life",100);
                ob->add("hen/fali",100);
                ob->add("hen/speed",60);
                ob->add("hen/defence",50);
                write(HIC"ÄãÂòÏÂÁËÒ»¸ööùÓãÆ¤Ñ¥¡££¨ÌåÁ¦+100,½ø¹¥+30,ËÙ¶È+60,·ÀÓù+50,·¨Á¦+100\n"NOR);
                ob->set("hen/inventory/ftmx",1);
                break;
                }

                case "7":
                {
                if( ob->query("hen/money") < 150000 )
                        {
                        write("ÄãµÄÇ®²»¹»ÓÃÁË£¡\n");
                        return 1;
                        }
                if( ob->query("hen/inventory/hjsx") )
                        {
                        write("ÄãÒÑ¾­ÓÐÍ¬ÑùµÄ×°±¸ÁË£¡\n");
                        return 1;
                        }
                ob->add("hen/money", -150000);
                ob->add("hen/defence",ob->query("hen/defence")+100);
                ob->set("hen/life",ob->query("hen/life")+300);
                ob->set("hen/fali",ob->query("hen/fali")+300);
                ob->set("hen/attack",ob->query("hen/attack")+50);
                ob->set("hen/speed",ob->query("hen/speed")+300);
                write(HIC"ÄãÂòÏÂÁËÒ»¸ö»Æ½ðÊ¥Ñ¥¡££¨·ÀÓù+100,ÌåÁ¦+300,·¨Á¦+300,½ø¹¥+50,ËÙ¶È+300\n"NOR);
                ob->set("hen/inventory/hjsx",1);
                break;
                }


        }
        return 1;
}
