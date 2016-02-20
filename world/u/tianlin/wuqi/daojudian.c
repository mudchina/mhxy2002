//By tianlin@mhxy for 2001.9.18
//ÔÚÖÆ×÷´ËÉÌµêÊ±,ÎÒÏëÒªÊÇºÍËûÃÇÒ»Ñù¶¼ÉèÔÚnpcÉíÉÏÈ¥Âò¶«Î÷,ÓÐµã²»´óºÃ,
//(1)ÊÇnpcÈÝÒ×±»É±º¦,ÒªÊÇÄã¸ønpcÉèÉÏno_dieÒ²ÐÐ,²»¹ýÒ²²»ÔõÃ´µØ,»¹Ã»ÓÐÐÂ
//ÏÊ¸Ð,(2)ÊÇÉèÔÚROOMÀïÃæµÄ»°,ÒÔÉÏµÄÎÊÌâ¾Í½â¾öÁË,¶øÇÒROOM»¹ºÜ»ªÀö,ÎÒ×ÔÈÎ
//Îª²»´í,´ó¼Ò¿ÉÒÔÄ£·ÂµÄ×÷Ò»ÏÂ,Çë²»Òª¸Ä×÷ÕßµÄÃû×Ö..Ð»Ð»!!!(xixi)

//BY tianlin@mhxy for 2002.3.5,ÐÞ¸ÄÒ»´¦´øÒøÆ±bugµÄbug
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", HIB"µÀ¾ßµê"NOR);
  set ("long", @LONG

[1;33m©³©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©·
[1;31m  ¡ª[37;41m ±àºÅ [31;40m¡ª[37;41m ÉÌ      Æ· [31;40m¡ª¡ª[37;41m Ð§            ÄÜ [31;40m¡ª¡ª[37;41m ¼Û     ¸ñ [31;40m¡ª
[37m     [1;35m[[32m 1[35m]     [32m±Ù¹ÈÍè          [37m½«Ê³ÎïºÍÒûË®¼Óµ½Æ¿¾±[2;37;0m       [36m2[33mÁ½[1;33m»Æ½ð           
[37m     [1;35m[[32m 2[35m]     [36mÐºÒ©            [37m½«Ê³ÎïºÍÒûË®½µÎª0[2;37;0m          [36m5[33mÁ½[1;33m»Æ½ð          
[37m     [1;35m[[32m 3[35m]     [33mÏÉÒ©            [37mÖ»Òª³ÔÒ»°ü¾ÍÄÜ»Ö¸´ÆøÑªÉÏÏÞ[2;37;0m [36m10[33mÁ½[1;33m»Æ½ð          
[37m     [1;35m[[32m 4[35m]     [31mÉñÒ©            [37mÖ»Òª³ÔÒ»°ü¾ÍÄÜ»Ö¸´¾«ÉñÉÏÏÞ[2;37;0m [36m10[33mÁ½[1;33m»Æ½ð          
[37m     [1;35m[[32m 5[35m][2;37;0m     [33mÇ§ÄêÈË²ÎÍõ      [1;37m»Ö¸´ÆøÑªºÍ¾«Éñ500µã[2;37;0m        [36m50[33mÁ½[1;33m»Æ½ð          
[37m     [1;35m[[32m 6[35m]     [37m°Ù±¦´ü          [37m¿ÉÒÔÎÞÏÞµÄ×°¶«Î÷[2;37;0m           [36m70[33mÁ½[1;33m»Æ½ð         
[37m     [1;35m[[32m 7[35m]     [33m¼ÍÄî±Ò          [37m¼Ó10µãÎòÐÔ[2;37;0m                 [36m20[33mÁ½[1;33m»Æ½ð         
[37m     [1;35m[[32m 8[35m][2;37;0m     [31mÉ±ÆøÍè          [1;37m¼ÓÉ±Æø100µã[2;37;0m                [36m20[33mÁ½[1;33m»Æ½ð         
[37m     [1;35m[[32m 9[35m]     [35m°ÙÄêâ¨ºïÌÒÍõ    [37m¼Ó10µãÄÚÁ¦ºÍ10µã·¨Á¦×î´óÖµ[2;37;0m [36m30[33mÁ½[1;33m»Æ½ð         
[37m     [1;35m[[32m10[35m]     [36mÌìÉ½Ñ©Á«        [37m»Ö¸´ÄÚÁ¦ºÍ·¨Á¦×î´óÖµ[2;37;0m       [36m200[33mÁ½[1;33m»Æ½ð         
[37m     [1;35m[[32m11[35m]     [31mÍòÄêÁéÖ¥        [37m¼Ó·¨Á¦×î´óÖµ20µã[2;37;0m           [36m100[33mÁ½[1;33m»Æ½ð         
[1;33m©»©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¿[2;37;0m
LONG);

  set("exits", ([ /* sizeof() == 4 */
        // "enter": __DIR__"road3",
         "out": "/d/city/bingqipu",
         "west": __DIR__"wuqidian",
//"east": __DIR__"kuijiadian",
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
                else if( afford == 2 )
                return 1;
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
                else if( afford == 2 )
                return 1;
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
                else if( afford == 2 )
                return 1;
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
                else if( afford == 2 )
                return 1; 
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
                else if( afford == 2 )
                return 1;
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
                else if( afford == 2 )
                return 1;
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
                else if( afford == 2 )
                return 1;
                me->pay_money(200000);
                obj = new ("/u/tianlin/wuqi/daoju/bi");
                obj->move(me);
                me->start_busy(4); 
                write("ÄãÏòµÀ¾ßµêÂòÏÂÒ»¿é"HIY"¼ÍÄî±Ò"NOR"¡£\n");
                break;
                }

                case "8":
                {
                if( !(afford=me->can_afford(200000)) )  {
                write("Äã´øµÄÇ®²»¹»¡£\n");
                return 1;
                } 
                else if( afford == 2 )
                return 1;
                me->pay_money(200000);
                obj = new ("/u/tianlin/wuqi/daoju/shaqi");
                obj->move(me);
                me->start_busy(4); 
                write("ÄãÏòµÀ¾ßµêÂòÏÂÒ»Á£"RED"É±ÆøÍè"NOR"¡£\n");
                break;
                }

                case "9":
                {
                if( !(afford=me->can_afford(500000)) )  {
                write("Äã´øµÄÇ®²»¹»¡£\n");
                return 1;
                } 
                else if( afford == 2 )
                return 1;
                me->pay_money(500000);
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
                else if( afford == 2 )
                return 1;
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
                else if( afford == 2 )
                return 1;
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

