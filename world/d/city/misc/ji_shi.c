//Cracked by Roath
//by tianlin 2001/5/1ÎÒÖ»ÊÇ¼ÓÈëÁËÒ»µãÑÕÉ«±ğµÄ¶¼Ã»ÓĞ×öĞŞ¸Ä.
#include <ansi.h> 
#include <room.h> 
#include <login.h> 
  
inherit ROOM; 
  
string look_sign(); 
  
void create() 
{ 
        set("short", "³¤ °² ºÚ ÊĞ"); 

        set("long", @LONG
 
ÕâÀïÊÇ³¤°²³Ç¼¯ÊĞ¡£Âú½ÖµÄµêÆÌ¶¼¹Ò×ÅÒ»ÍÅÍÅ¡¢Ò»´Ø´ØµÄÑò½Ç·çµÆ¡£ 
Ò»Éù½ÓÒ»ÉùµÄ½ĞÂôÉùÔÚ¸÷¸ö½Ö¿Ú¡¢Ğ¡ÏïÉî´¦´Ëºô±ËÓ¦£¬Á¬Ãà²»¾ø¡£¼¯
ÊĞµÄ Èë¿Ú´¦£¬¹Ò×ÅÒ»¿éÅÆ×Ó[1;33m(sign)[2;37;0m¡£ 
LONG 
        ); 
  
        set("outdoors", "changan"); 
  
        set("item_desc", ([ 
                "sign": @TEXT 
ÔÚÕâÀïÄã¿ÉÒÔ×öÏÂÃæµÄÊÂÇé¡£ 
  
[1;37mjoin        ¿ªÊ¼×öÉúÒâ[2;37;0m 
  
TEXT 
        ]) ); 
  
        set("exits", ([ 
            "east" : "/d/city/beiyin1.c",
        ]) ); 
  
        set("no_fight", 1); 
        set("no_magic",1); 
  
/*
        set("objects", ([ 
               "/d/changan/npc/qianmian": 1, 
        ]) ); 
*/
  
        setup(); 
} 
  
void init() 
{ 
        add_action("do_join", "join"); 
        add_action("do_quit", "quit");
} 
  
int do_join(string arg) 
{ 
       string *name = ({ "Ë½ÑÎ","Ë®¹û","Ê³Æ·","³Â¾Æ","ÏÊ»¨","²İÒ©","ÃºÌ¿", 
                "¹Å¶­","Öé±¦","ÓñÆ÷","×Ö»­","Ä¾²Ä","ÖñÆ÷","ÎäÆ÷","ÌúÆ÷","Å©¾ß", 
                "ÂíÆ¥","²¼Æ¥","´ÉÆ÷","ÔÓ»õ", });
        object me; 
        string tempstr, namestr; 
  
        me = this_player(); 
  
        if(me->query_temp("working") == 1) 
                return notify_fail("ÄãÒÑ¾­ÔÚ··Âôµ±ÖĞÁË£¡\n"); 
  
        namestr = name[random(sizeof(name))]; 
        tempstr = "$N¿ªÊ¼··Âô" + namestr + "....\n";  
        message_vision(tempstr, me); 
  
        if( namestr == "Ë½ÑÎ" ) { 
                tempstr = "¹Ù±ø°Ñ$N×½ÁËÆğÀ´£º¡°··Âô" + namestr + 
                        "£¿Õâ¿ÉÊÇ¿³Í·µÄ×ïÃû£¡¡±\n"; 
                message_vision(tempstr, me); 
                if( random(10) == 0 ) {         // ´òÈë´óÀÎ 
                        me->set("startroom", START_ROOM ); 
                        me->move( __DIR__"dalao" ); 
                        set("name", "¹Ù¸®"); 
                        set("id", "guanfu"); 
                        set("channel_id","´óÌÆ¸æÊ¾");
                        CHANNEL_D->do_channel(this_object(), "chat", 
                                HIY+me->name() + "··Âô" + namestr + 
                                "£¬±»´òÈë´óÀÎ£¬µÈºòÇïºó´¦Õ¶£¡£¡£¡"NOR ); 
                } 
                else { 
                        if( random(20) == 0 ) { 
                                switch( random(9) ) { 
case 0: tempstr = "/d/city/recycle"; 
        break; 
case 1: tempstr = "/d/kaifeng/donghu"+(random(5)+1); 
        break; 
case 2: tempstr = "/d/qujing/dudi/shanlu" + ( random(10) + 1); 
        break; 
case 3: tempstr = "/d/qujing/wuzhuang/wzgmaze" + ( random(8) + 1); 
        break; 
case 4: tempstr = "/d/qujing/tianzhu/jiedao" + ( random(8) + 91); 
        break; 
case 5: tempstr = "/d/qujing/nuerguo/townc" + ( random(3) + 1); 
        break; 
case 6: tempstr = "/d/qujing/fengxian/jiedao" + ( random(14) + 1); 
        break; 
case 7: tempstr = "/d/qujing/yinwu/caopo" + ( random(5) + 1); 
        break; 
case 8: tempstr = "/d/sea/maze" + ( random(7)); 
        break; 
                                } 
                            
                                me->set("startroom", tempstr ); 
tempstr = "$NÌÍ³öºñºñÒ»µşÒøÆ±¶Ô¹Ù±øËµ£º´óÒ¯ĞĞĞĞºÃ°É£¬ÎÒ¼Ò»¹ÓĞ°ËÊ®ËêµÄÀÏÄïÄØ....\n" 
        + "¹Ù±ø½«ÒøÆ±Ò»°ÑÇÀ¹ı£¬·ÅÈë»³ÖĞ£¬Ì½ÁËÌ½Í·£¬¼ûµ½×óÓÒÎŞÈË£¬ºÈµÀ£ºÕâÃ´ÉÙ£¡\n" 
        + "¹Ù±øÒ»½Å½«$NÌßµ½¾ÅÏöÔÆÍâ£º¡°½ĞÄã··Âô" + namestr + "£¡ÏÂ»ØÔÙ×½Íù£¬¿³Í·£¡¡± \n"; 
                                message_vision(tempstr, me); 
                               me->move( tempstr ); 
                        } 
                        else {                  
                                me->set("startroom", START_ROOM ); 
tempstr = "¹Ù±øÒ»½Å°Ñ$NÌßÁË³öÀ´£º¡°½ĞÄã··Âô" + namestr 
        + "£¡ÏÂ»ØÔÙ×½Íù£¬¿³Í·£¡¡±\n"; 
                                message_vision(tempstr, me); 
                               me->move( START_ROOM ); 
                        } 
                } 
                return 1; 
        } 
  
        me->set_temp("working", 1); 
        me->set_temp("no_quit",1);
        call_out( "compelete_join", 4+random(8), me ); 
        return 1; 
} 
  
private void compelete_join(object me) 
{ 
        object ob; 
        int i, n; 
  
        if (!me) return; 
        me->delete_temp("working"); 
        if( present(me) ) { 
                message_vision("$N¿ªÕ¹ÉúÒâ£¬ÈËËäÈ»ÀÛ»µÁË£¬µ«ÊÇÊÕÒæ²»Ğ¡¡£\n", me);  
                me->add("kee", -25); 
                me->add("sen", -25); 
                me->add("potential", (me->query("combat_exp") >= 15000) ? 
                        random(4) : 8+random(10) ); 
                me->add("daoxing", (me->query("combat_exp") >= 15000) ? 

                        random(6) : 8+random(8)); 
                n = random(10* me->query("kar")) / 30; 
                if (me->query("combat_exp")>=15000)  n=random(3);
                ob = new("/obj/money/silver"); 
                ob->set_amount(n+1); 
                ob->move(me); 
                tell_object(me, "ÄãµÄÇ±ÄÜºÍµÀĞĞÔö¼ÓÁË£¡\n"); 
                tell_object(me, sprintf("Äã×¬µ½"HIW"%s"NOR"Á½Òø×Ó¡£\n", chinese_number(n+1))); 
        } 
  
        return; 
}

int do_quit(object me)
{
        me = this_player();
	if(me->query_temp("working"))
	{
	write("ÉúÒâ»¹Ã»×öÍê£¬¾ÍÏëÁï£¿\n");
	return 1;
         }
else return 0;
}
	
