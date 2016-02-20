// by happ@YSZZ
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "Í·²¿ÎäÆ÷ÉÌµê");
  set ("long", @LONG

[37m         [32;47m     ¨y¨y¨y¨y¨y¨y¨y¨y¨y¨y¨y¨y¨y¨y¨y¨y¨y¨y¨y¨y      [1;37;40m¨†
[37m         [1;31;47m     [37;42m £×£Å£Á£Ð£Ï£Î£Ó  £Ó£Ô£Ï£Ò£Å  Í·²¿ÎäÆ÷µê [31;47m      [37;40m¨†
[37m         [32;47m     [37;42m¨{¨{¨{¨{¨{¨{¨{¨{¨{¨{¨{¨{¨{¨{¨{¨{¨{¨{¨{¨{[1;47m      [40m¨†
[37m      [1m   ¨Š[47m¡ö¡ö¡ö[33;46mùÝùùùùùùùÞùùùùùùùÞùùùùùùùÞùùùùùùùß[37;47m¡ö¡ö¡ö¨Š[m
[37m      [1m   ¨Š[47m¡ö¡ö¡ö[33;46mùàùùùùùùùáùùùùùùùáùùùùùùùáùùùùùùùâ[37;47m¡ö¡ö¡ö¨Š[m
[37m      [1m   ¨Š[47m¡ö¡ö¡ö[33;44m©¦      ©¦      ©¦      ©¦      ©¦[37;47m¡ö¡ö¡ö¨Š[m
[37m      [1m   ¨Š[47m¡ö¡ö¡ö[33;44m©À©¤©¤©¤©à©¤©¤©¤ùø©¤©¤©¤©à©¤©¤©¤©È[37;47m¡ö¡ö¡ö¨Š[m
[37m      [1m   ¨Š[47m¡ö¡ö¡ö[33;44m©¦©n©n©n©¦©n©n©n©¦©n©n©n©¦©n©n©n©¦[37;47m¡ö¡ö¡ö¨Š[m
[37m      [1m   ¨Š[47m¡ö¡ö¡ö[32;43m©¦¡ù¡ù¡ù©¦¡ù¡ù¡ù©¦¡ù¡ù¡ù©¦¡ù¡ù¡ù©¦[37;47m¡ö¡ö¡ö¨Š[m
[1;33m      ¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰[m
[37m  [1;41m [NO]  [Æ÷¾ßÃû]  [ÌåÁ¦]  [·¨Á¦]  [ËÙ¶È]  [¹¥»÷]  [·ÀÓù]  [ËÙ¶È]  [ÊÛ  ¼Û][m
[37m  [1m ( 1)  ËÜ½ºÃ±×Ó      0       0       0       0       5       0       500
[37m  [1m ( 2)  Å£Æ¤Ð¡Ã±      0       0       0       0      10       0      3500
[37m  [1m ( 3)    °²È«Ã±     60       0       0       0      20       0      5000
[37m  [1m ( 4)  ¸ÖÌúÍ·¿ø    150      50       0       0      30       0     10000
[37m  [1m ( 5)  Ä§·¨·¢¹¿    100     150       0       0      25       0     50000
[37m  [1m ( 6)  »Æ½ðÊ¥¿ø    300     300     300       0     100       0    300000
  [1;41m                                                                         [m
LONG);

  set("exits", ([ /* sizeof() == 4 */
         "east": __DIR__"road3",
         "north":__DIR__"weapon1",
         "south":__DIR__"weapon2",
         "west":__DIR__"weapon3",
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
                if( ob->query("hen/money") < 500 )
                        {
          write("ÄãµÄÇ®²»¹»ÓÃÁË£¬Äã»¹ÓÐ "+ob->query("hen/money")+"  ÔªÇ®¡£\n");
          return 1;
                        }
                if( ob->query("hen/inventory/slcap") )
                        {
          write("ÄãÒÑ¾­ÂòÁËÍ¬ÑùµÄ×°±¸ÁË¡£\n");
          return 1;
                        }
                ob->add("hen/money", -500);
                ob->add("hen/defence",5);
                write(HIC"ÄãÂòÏÂÁËÒ»¸öËÜÁÏÃ±×Ó¡££¨·ÀÓù¼Ó£µµã£©\n"NOR);
                ob->set("hen/inventory/slcap",1);
                break;
                }

                case "2":
                {
                if( ob->query("hen/money") < 3500 )
                        {
          write("ÄãµÄÇ®²»¹»ÓÃÁË£¬Äã»¹ÓÐ "+ob->query("hen/money")+"  ÔªÇ®¡£\n");
          return 1;
                        }
                if( ob->query("hen/inventory/npcap") )
                        {
          write("ÄãÒÑ¾­ÂòÁËÍ¬ÑùµÄ×°±¸ÁË¡£\n");
          return 1;
                        }
                ob->add("hen/money", -3500);
                ob->set("hen/defence",10);
                write(HIC"ÄãÂòÏÂÁËÒ»¸öÅ£Æ¤Ð¡Ã±¡££¨·ÀÓù¼Ó£±£°µã£©\n"NOR);
                ob->set("hen/inventory/npcap",1);
                break;
                }

                case "3":
                {
                if( ob->query("hen/money") < 5000 )
                        {
          write("ÄãµÄÇ®²»¹»ÓÃÁË£¬Äã»¹ÓÐ "+ob->query("hen/money")+"  ÔªÇ®¡£\n");
          return 1;
                        }
                if( ob->query("hen/inventory/aqcap") )
                        {
          write("ÄãÒÑ¾­ÂòÁËÍ¬ÑùµÄ×°±¸ÁË¡£\n");
          return 1;
                        }
                ob->add("hen/money", -5000);
                ob->set("hen/defence",20);
                ob->set("hen/life",ob->query("hen/life")+60);
                write(HIC"ÄãÂòÏÂÁËÒ»¸ö°²È«Ã±¡££¨·ÀÓù¼Ó£²£°µã£¬ÌåÁ¦¼Ó£¶£°£©\n"NOR);
                ob->set("hen/inventory/aqcap",1);
                break;
                }


                case "4":
                {
                if( ob->query("hen/money") < 10000 )
                        {
          write("ÄãµÄÇ®²»¹»ÓÃÁË£¬Äã»¹ÓÐ "+ob->query("hen/money")+"  ÔªÇ®¡£\n");
          return 1;
                        }
                if( ob->query("hen/inventory/gttoukui") )
                        {
          write("ÄãÒÑ¾­ÂòÁËÍ¬ÑùµÄ×°±¸ÁË¡£\n");
          return 1;
                        }

                ob->add("hen/money", -10000);
                ob->set("hen/defence",30);
                ob->set("hen/life",ob->query("hen/life")+150);
                ob->set("hen/fali",ob->query("hen/fali")+50);
                write(HIC"ÄãÂòÏÂÁËÒ»¸ö¸ÖÌúÍ·¿ø¡££¨·ÀÓù+30,ÌåÁ¦+150,·¨Á¦+50£©\n"NOR);
                ob->set("hen/inventory/gttoukui",1);
                break;
                }


                case "5":
                {
                if( ob->query("hen/money") < 50000 )
                        {
          write("ÄãµÄÇ®²»¹»ÓÃÁË£¬Äã»¹ÓÐ "+ob->query("hen/money")+"  ÔªÇ®¡£\n");
          return 1;
                        }
                if( ob->query("hen/inventory/mpfg") )
                        {
          write("ÄãÒÑ¾­ÂòÁËÍ¬ÑùµÄ×°±¸ÁË¡£\n");
          return 1;
                        }
                ob->add("hen/money", -50000);
                ob->set("hen/defence",25);
                ob->set("hen/life",ob->query("hen/life")+100);
                ob->set("hen/fali",ob->query("hen/fali")+60);
                write(HIC"ÄãÂòÏÂÁËÒ»¸öÄ§·¨·¢¹¿¡££¨·ÀÓù+25,ÌåÁ¦+100,·¨Á¦+150£©\n"NOR);
                ob->set("hen/inventory/mpfg",1);
                break;
                }

                case "6":
                {
                if( ob->query("hen/money") < 300000 )
                        {
          write("ÄãµÄÇ®²»¹»ÓÃÁË£¬Äã»¹ÓÐ "+ob->query("hen/money")+"  ÔªÇ®¡£\n");
          return 1;
                        }
                if( ob->query("hen/inventory/hjsk") )
                        {
          write("ÄãÒÑ¾­ÂòÁËÍ¬ÑùµÄ×°±¸ÁË¡£\n");
          return 1;
                        }

                ob->add("hen/money", -300000);
                ob->set("hen/defence",300);
                ob->set("hen/life",ob->query("hen/life")+300);
                ob->set("hen/fali",ob->query("hen/fali")+300);
                ob->set("hen/speed",ob->query("hen/speed")+300);
                write(HIC"ÄãÂòÏÂÁËÒ»¸ö»Æ½ðÊ¥¿ø¡££¨·ÀÓù+100,ÌåÁ¦+300,·¨Á¦+350,ËÙ¶È+300£©\n"NOR);
                ob->set("hen/inventory/hjsk",1);
                break;
                }
        }
        return 1;
}
