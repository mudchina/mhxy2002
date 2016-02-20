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
   [1;35m( [1;32m1[1;35m)[0m   [1;31m¶ñÄ§[1;36m£ª[1;31mÕ½¸«[0m    0       0          0        Ëæ»ú      [36m200[33mÁ½[1;33m»Æ½ð
   [1;35m( [1;32m2[1;35m)[0m   [1;36mè¯ [1;37mÌì [1;32m°ô[0m      0       0          0        Ëæ»ú      [36m200[33mÁ½[1;33m»Æ½ð
   [1;35m( [1;32m3[1;35m)[0m   [1;32mº®[1;37m Ñ©[1;36m Œš[1;31m µ¶[0m   0       0          0        Ëæ»ú      [36m200[33mÁ½[1;33m»Æ½ð
   [1;35m( [1;32m4[1;35m)[0m   [1;31mÄõ[1;36mÁú[1;37mº®[1;32mØ°[0m      0       0          0        Ëæ»ú      [36m200[33mÁ½[1;33m»Æ½ð
   [1;35m( [1;32m5[1;35m)[0m   [1;31m»ðÑæ[1;33môá[0m        0       0          0        Ëæ»ú      [36m200[33mÁ½[1;33m»Æ½ð
   [1;35m( [1;32m6[1;35m)[0m   [1;34m¾ÅÌì[1;33mÐù¹Ç[1;32m²æ[0m    0       0          0        Ëæ»ú      [36m200[33mÁ½[1;33m»Æ½ð
   [1;35m( [1;32m7[1;35m)[0m   [1;37m¾Å¹Ç¿ªÉ½´¸[0m    0       0          0        Ëæ»ú      [36m200[33mÁ½[1;33m»Æ½ð
   [1;35m( [1;32m8[1;35m)[0m   [1;34m¾ª»ê[1;31m¶áÆÇ[1;33mïµ[0m    0       0          0        Ëæ»ú      [36m200[33mÁ½[1;33m»Æ½ð
   [1;35m( [1;32m9[1;35m)[0m   [1;35m¶·×ª[1;33m½ðÐÇ[1;36m°Ò[0m    0       0          0        Ëæ»ú      [36m200[33mÁ½[1;33m»Æ½ð
   [1;35m( [1;32m10[1;35m)[0m  [37mÀ×öª[33m°ÔÍõÇ¹[0m    0       0          0        Ëæ»ú      [36m200[33mÁ½[1;33m»Æ½ð
   [1;35m( [1;32m11[1;35m)[0m  [1;37m°¢ÃÖÍÓ[1;33mìøÕÈ[0m    0       0          0        Ëæ»ú      [36m200[33mÁ½[1;33m»Æ½ð
   [1;35m( [1;32m12[1;35m)[0m  [37m±ùÆÇº®¹â½£[0m    0       0          0        Ëæ»ú      [36m200[33mÁ½[1;33m»Æ½ð
   [1;35m( [1;32m13[1;35m)[0m  [1;31mÑªÓñÁú½î±Þ[0m    0       0          0        Ëæ»ú      [36m200[33mÁ½[1;33m»Æ½ð
   [1;35m( [1;32m14[1;35m)[0m  [1;35mÂþ[1;36mÌì[1;33m·É[1;37mÓð[0m      0       0          0        Ëæ»ú      [36m200[33mÁ½[1;33m»Æ½ð
[1;41m                                                                           [m
LONG);

  set("exits", ([ /* sizeof() == 4 */
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
                if( !(afford=me->can_afford(2000000)) )  {
                write("Äã´øµÄÇ®²»¹»¡£\n");
                return 1;
                } 
                me->pay_money(2000000);
                obj = new ("/u/tianlin/wuqi/bingqi/axe");
                obj->move(me);
                me->start_busy(4); 
                write("ÄãÏò±øÆ÷ÆÌÂòÏÂÒ»¸ö"HIR"¶ñÄ§"HIC"£ª"HIR"Õ½¸«"NOR"¡£\n");
                break;
                }
                
                case "2":
                {
                if( !(afford=me->can_afford(2000000)) )  {
                write("Äã´øµÄÇ®²»¹»¡£\n");
                return 1;
                } 
                me->pay_money(2000000);
                obj = new ("/u/tianlin/wuqi/bingqi/bang");
                obj->move(me);
                me->start_busy(4); 
                write("ÄãÏò±øÆ÷ÆÌÂòÏÂÒ»¸ö"HIC"è¯ "HIW"Ìì"HIG" °ô"NOR"¡£\n");
                break;
                }

                case "3":
                {
                if( !(afford=me->can_afford(2000000)) )  {
                write("Äã´øµÄÇ®²»¹»¡£\n");
                return 1;
                } 
                me->pay_money(2000000);
                obj = new ("/u/tianlin/wuqi/bingqi/blade");
                obj->move(me);
                me->start_busy(4); 
                write("ÄãÏò±øÆ÷ÆÌÂòÏÂÒ»¸ö"HIG"º® "HIW"Ñ© "HIC"Œš "HIR"µ¶"NOR"¡£\n");
                break;
                }
                case "4":
                {
                if( !(afford=me->can_afford(2000000)) )  {
                write("Äã´øµÄÇ®²»¹»¡£\n");
                return 1;
                } 
                me->pay_money(2000000);
                obj = new ("/u/tianlin/wuqi/bingqi/dagger");
                obj->move(me);
                me->start_busy(4); 
                write("ÄãÏò±øÆ÷ÆÌÂòÏÂÒ»¸ö"HIR"Äõ"HIC"Áú"HIW"º®"HIG"Ø°"NOR"¡£\n");
                break;
                }
                case "5":
                {
                if( !(afford=me->can_afford(2000000)) )  {
                write("Äã´øµÄÇ®²»¹»¡£\n");
                return 1;
                } 
                me->pay_money(2000000);
                obj = new ("/u/tianlin/wuqi/bingqi/feiyu");
                obj->move(me);
                me->start_busy(4); 
                write("ÄãÏò±øÆ÷ÆÌÂòÏÂÒ»¸ö"HIR"»ðÑæ"HIY"ôá"NOR"¡£\n");
                break;
                }
                case "6":
                {
                if( !(afford=me->can_afford(2000000)) )  {
                write("Äã´øµÄÇ®²»¹»¡£\n");
                return 1;
                } 
                me->pay_money(2000000);
                obj = new ("/u/tianlin/wuqi/bingqi/fork");
                obj->move(me);
                me->start_busy(4); 
                write("ÄãÏò±øÆ÷ÆÌÂòÏÂÒ»¸ö"HIB"¾ÅÌì"HIY"Ðù¹Ç"HIG"²æ"NOR"¡£\n");
                break;
                }
                case "7":
                {
                if( !(afford=me->can_afford(2000000)) )  {
                write("Äã´øµÄÇ®²»¹»¡£\n");
                return 1;
                } 
                me->pay_money(2000000);
                obj = new ("/u/tianlin/wuqi/bingqi/hammer");
                obj->move(me);
                me->start_busy(4); 
                write("ÄãÏò±øÆ÷ÆÌÂòÏÂÒ»¸ö"HIW"¾Å¹Ç¿ªÉ½´¸"NOR"¡£\n");
                break;
                }
                case "8":
                {
                if( !(afford=me->can_afford(2000000)) )  {
                write("Äã´øµÄÇ®²»¹»¡£\n");
                return 1;
                } 
                me->pay_money(2000000);
                obj = new ("/u/tianlin/wuqi/bingqi/mace");
                obj->move(me);
                me->start_busy(4); 
                write("ÄãÏò±øÆ÷ÆÌÂòÏÂÒ»¸ö"HIB "¾ª»ê"HIR"¶áÆÇ"HIY"ïµ" NOR"¡£\n");
                break;
                }
                case "9":
                {
                if( !(afford=me->can_afford(2000000)) )  {
                write("Äã´øµÄÇ®²»¹»¡£\n");
                return 1;
                } 
                me->pay_money(2000000);
                obj = new ("/u/tianlin/wuqi/bingqi/rake");
                obj->move(me);
                me->start_busy(4); 
                write("ÄãÏò±øÆ÷ÆÌÂòÏÂÒ»¸ö"HIM"¶·×ª"HIY"½ðÐÇ"HIC"°Ò"NOR"¡£\n");
                break;
                }
                case "10":
                {
                if( !(afford=me->can_afford(2000000)) )  {
                write("Äã´øµÄÇ®²»¹»¡£\n");
                return 1;
                } 
                me->pay_money(2000000);
                obj = new ("/u/tianlin/wuqi/bingqi/spear");
                obj->move(me);
                me->start_busy(4); 
                write("ÄãÏò±øÆ÷ÆÌÂòÏÂÒ»¸ö"WHT "À×öª"YEL"°ÔÍõÇ¹" NOR"¡£\n");
                break;
                }
                case "11":
                {
                if( !(afford=me->can_afford(2000000)) )  {
                write("Äã´øµÄÇ®²»¹»¡£\n");
                return 1;
                } 
                me->pay_money(2000000);
                obj = new ("/u/tianlin/wuqi/bingqi/staff");
                obj->move(me);
                me->start_busy(4); 
                write("ÄãÏò±øÆ÷ÆÌÂòÏÂÒ»¸ö"HIW "°¢ÃÖÍÓ"HIY"ìøÕÈ" NOR"¡£\n");
                break;
                }
                case "12":
                {
                if( !(afford=me->can_afford(2000000)) )  {
                write("Äã´øµÄÇ®²»¹»¡£\n");
                return 1;
                } 
                me->pay_money(2000000);
                obj = new ("/u/tianlin/wuqi/bingqi/sword");
                obj->move(me);
                me->start_busy(4); 
                write("ÄãÏò±øÆ÷ÆÌÂòÏÂÒ»¸ö"WHT "±ùÆÇº®¹â½£" NOR"¡£\n");
                break;
                }
                case "13":
                {
                if( !(afford=me->can_afford(2000000)) )  {
                write("Äã´øµÄÇ®²»¹»¡£\n");
                return 1;
                } 
                me->pay_money(2000000);
                obj = new ("/u/tianlin/wuqi/bingqi/whip");
                obj->move(me);
                me->start_busy(4); 
                write("ÄãÏò±øÆ÷ÆÌÂòÏÂÒ»¸ö"HIR "ÑªÓñÁú½î±Þ" NOR"¡£\n");
                break;
                }
                case "14":
                {
                if( !(afford=me->can_afford(2000000)) )  {
                write("Äã´øµÄÇ®²»¹»¡£\n");
                return 1;
                } 
                me->pay_money(2000000);
                obj = new ("/u/tianlin/wuqi/bingqi/yumao");
                obj->move(me);
                me->start_busy(4); 
                write("ÄãÏò±øÆ÷ÆÌÂòÏÂÒ»¸ö"HIM"Âþ"HIC"Ìì"HIY"·É"HIW"Óð"NOR"¡£\n");
                break;
                }
        }
return 1;
}

