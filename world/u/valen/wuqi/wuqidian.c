//By tianlin@mhxy for 2001.9.18
//ÔÚÖÆ×÷´ËÉÌµêÊ±,ÎÒÏëÒªÊÇºÍËûÃÇÒ»Ñù¶¼ÉèÔÚnpcÉíÉÏÈ¥Âò¶«Î÷,ÓÐµã²»´óºÃ,
//(1)ÊÇnpcÈÝÒ×±»É±º¦,ÒªÊÇÄã¸ønpcÉèÉÏno_dieÒ²ÐÐ,²»¹ýÒ²²»ÔõÃ´µØ,»¹Ã»ÓÐÐÂ
//ÏÊ¸Ð,(2)ÊÇÉèÔÚROOMÀïÃæµÄ»°,ÒÔÉÏµÄÎÊÌâ¾Í½â¾öÁË,¶øÇÒROOM»¹ºÜ»ªÀö,ÎÒ×ÔÈÎ
//Îª²»´í,´ó¼Ò¿ÉÒÔÄ£·ÂµÄ×÷Ò»ÏÂ,Çë²»Òª¸Ä×÷ÕßµÄÃû×Ö..Ð»Ð»!!!(xixi)
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", NOR"±øÆ÷"HIC"¡ï"NOR"ÉÌµê");
  set ("long", @LONG

[37m         [32;47m     ¨y¨y¨y¨y¨y¨y¨y¨y¨y¨y¨y¨y¨y¨y¨y¨y¨y¨y¨y¨y      [1;37;40m¨†
[37m         [1;31;47m     [37;42m            [1;35mÎå[5m[1;36m¡ï[0m[37;42m[1;35m¼¶±øÆ÷×¨Âôµê[0m[37;42m            [31;47m      [37;40m¨†
[37m         [32;47m     [37;42m¨{¨{¨{¨{¨{¨{¨{¨{¨{¨{¨{¨{¨{¨{¨{¨{¨{¨{¨{¨{[1;47m      [40m¨†
[37m      [1m   ¨Š[47m¡ö¡ö¡ö[33;46mùÝùùùùùùùÞùùùùùùùÞùùùùùùùÞùùùùùùùß[37;47m¡ö¡ö¡ö¨Š[m
[37m      [1m   ¨Š[47m¡ö¡ö¡ö[33;46mùàùùùùùùùáùùùùùùùáùùùùùùùáùùùùùùùâ[37;47m¡ö¡ö¡ö¨Š[m
[37m      [1m   ¨Š[47m¡ö¡ö¡ö[33;44m©¦      ©¦      ©¦      ©¦      ©¦[37;47m¡ö¡ö¡ö¨Š[m
[37m      [1m   ¨Š[47m¡ö¡ö¡ö[33;44m©À©¤©¤©¤©à©¤©¤©¤ùø©¤©¤©¤©à©¤©¤©¤©È[37;47m¡ö¡ö¡ö¨Š[m
[37m      [1m   ¨Š[47m¡ö¡ö¡ö[33;44m©¦©n©n©n©¦©n©n©n©¦©n©n©n©¦©n©n©n©¦[37;47m¡ö¡ö¡ö¨Š[m
[37m      [1m   ¨Š[47m¡ö¡ö¡ö[32;43m©¦¡ù¡ù¡ù©¦¡ù¡ù¡ù©¦¡ù¡ù¡ù©¦¡ù¡ù¡ù©¦[37;47m¡ö¡ö¡ö¨Š[m
[1;33m      ¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰[m
[37m  [1;41m [NO]  [±øÆ÷Ãû]   [¼Ó·¨Á¦]  [ÖØÁ¿]  [¹¥»÷Á¦]   [¼ÓÇá¹¦]  [ÊÛ  ¼Û][m
   ( 1)  ÇàÍ­½£       50       0         20        0        6000
   ( 2)  ÇçÀ×½£       80       0         30        0        10000
   ( 3)  ²õÒíµ¶      100       0         40        0        15000
   ( 4)  ÍüÇé½£      100       0         35        0        15000
   ( 5)  Ê¨Í·±¦µ¶    150       0         60        0        35000
   ( 6)  ÍÀÁúµ¶      200       0         100       0        50000
   ( 7)  »Æ½ðÊ¥ÕÈ    300       300       100       0        150000
[1;41m                                                                           [m
LONG);

  set("exits", ([ /* sizeof() == 4 */
        // "enter": __DIR__"road3",
         "east": __DIR__"daojudian",
]));

        setup();
}

void init()
{
        add_action("do_buy","buy");
}

int do_buy(string arg)
{
        object obj;
        object me=this_player();
        int afford;
        if(me->is_busy())
                return notify_fail(CYN"ÄãÏÖÔÚÕýÃ¦×ÅÄØ¡£\n"NOR);
        switch(arg)
        {
                case "1":
                {
                if( !(afford=me->can_afford(20000)) )  {
                write("Äã´øµÄÇ®²»¹»¡£\n");
                return 1;
                } 
                me->pay_money(20000);
                obj = new ("/u/tianlin/wuqi/daoju/dan");
                obj->move(me);
                me->start_busy(4); 
                write("ÄãÏòµÀ¾ßµêÂòÏÂÒ»¸ö"HIG"±Ù¹ÈÍè"NOR"¡£\n");
                break;
                }
                
                case "2":
                {
                if( !(afford=me->can_afford(50000)) )  {
                write("Äã´øµÄÇ®²»¹»¡£\n");
                return 1;
                } 
                me->pay_money(50000);
                obj = new ("/u/tianlin/wuqi/daoju/xieyao");
                obj->move(me);
                me->start_busy(4); 
                write("ÄãÏòµÀ¾ßµêÂòÏÂÒ»Æ¿"HIC"ÐºÒ©"NOR"¡£\n");
                break;
                }

                case "3":
                {
                if( !(afford=me->can_afford(100000)) )  {
                write("Äã´øµÄÇ®²»¹»¡£\n");
                return 1;
                } 
                me->pay_money(10000);
                obj = new ("/u/tianlin/wuqi/daoju/xianyao");
                obj->move(me);
                me->start_busy(4); 
                write("ÄãÏòµÀ¾ßµêÂòÏÂÒ»°ü"HIY"ÏÉÒ©"NOR"¡£\n");
                break;
                }

                case "4":
                {
                if( !(afford=me->can_afford(100000)) )  {
                write("Äã´øµÄÇ®²»¹»¡£\n");
                return 1;
                } 
                me->pay_money(10000);
                obj = new ("/u/tianlin/wuqi/daoju/shenyao");
                obj->move(me);
                me->start_busy(4); 
                write("ÄãÏòµÀ¾ßµêÂòÏÂÒ»°ü"HIR"ÉñÒ©"NOR"¡£\n");
                break;
                }
 
                case "5":
                {
                if( !(afford=me->can_afford(500000)) )  {
                write("Äã´øµÄÇ®²»¹»¡£\n");
                return 1;
                } 
                me->pay_money(500000);
                obj = new ("/u/tianlin/wuqi/daoju/renshen");
                obj->move(me);
                me->start_busy(4); 
                write("ÄãÏòµÀ¾ßµêÂòÏÂÒ»¿Å"YEL"Ç§ÄêÈË²ÎÍõ"NOR"¡£\n");
                break;
                }

                case "6":
                {
                if( !(afford=me->can_afford(700000)) )  {
                write("Äã´øµÄÇ®²»¹»¡£\n");
                return 1;
                } 
                me->pay_money(700000);
                obj = new ("/u/tianlin/wuqi/daoju/bag");
                obj->move(me);
                me->start_busy(4); 
                write("ÄãÏòµÀ¾ßµêÂòÏÂÒ»¸ö"HIW"°Ù±¦´ü"NOR"¡£\n");
                break;
                }

                case "7":
                {
                if( !(afford=me->can_afford(200000)) )  {
                write("Äã´øµÄÇ®²»¹»¡£\n");
                return 1;
                } 
                me->pay_money(200000);
                obj = new ("/u/tianlin/wuqi/daoju/bi");
                obj->move(me);
                me->start_busy(4); 
                write("ÄãÏòµÀ¾ßµêÂòÏÂÒ»¿é"HIY"¼ÍÄî±Ò"NOR"¡£\n");
                break;
                }

                case "8":
                {
                if( !(afford=me->can_afford(90000)) )  {
                write("Äã´øµÄÇ®²»¹»¡£\n");
                return 1;
                } 
                me->pay_money(90000);
                obj = new ("/u/tianlin/wuqi/daoju/shaqi");
                obj->move(me);
                me->start_busy(4); 
                write("ÄãÏòµÀ¾ßµêÂòÏÂÒ»Á£"RED"É±ÆøÍè"NOR"¡£\n");
                break;
                }

                case "9":
                {
                if( !(afford=me->can_afford(150000)) )  {
                write("Äã´øµÄÇ®²»¹»¡£\n");
                return 1;
                } 
                me->pay_money(150000);
                obj = new ("/u/tianlin/wuqi/daoju/taowang");
                obj->move(me);
                me->start_busy(4); 
                write("ÄãÏòµÀ¾ßµêÂòÏÂÒ»¿Å"HIM"°ÙÄêâ¨ºïÌÒÍõ"NOR"¡£\n");
                break;
                }

                case "10":
                {
                if( !(afford=me->can_afford(2000000)) )  {
                write("Äã´øµÄÇ®²»¹»¡£\n");
                return 1;
                } 
                me->pay_money(2000000);
                obj = new ("/u/tianlin/wuqi/daoju/xuelian");
                obj->move(me);
                me->start_busy(4); 
                write("ÄãÏòµÀ¾ßµêÂòÏÂÒ»¿Å"HIC"ÌìÉ½Ñ©Á«"NOR"¡£\n");
                break;
                }

                case "11":
                {
                if( !(afford=me->can_afford(1000000)) )  {
                write("Äã´øµÄÇ®²»¹»¡£\n");
                return 1;
                } 
                me->pay_money(1000000);
                obj = new ("/u/tianlin/wuqi/daoju/lingzhi");
                obj->move(me);
                me->start_busy(4); 
                write("ÄãÏòµÀ¾ßµêÂòÏÂÒ»¿Å"HIR"ÍòÄêÁéÖ¥"NOR"¡£\n");
                break;
                }
        }
return 1;
}

