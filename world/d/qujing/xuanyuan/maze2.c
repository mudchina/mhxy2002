#include <ansi.h>

inherit ROOM;

void init();
void reset_path(object);
int check_out(object);

void create ()
{
        set ("short", "[33m±¦¿âÃÅ¿Ú[m");
        set ("long", @LONG

ÄãÒÑ¾­¿´µ½»Æ³Î³ÎµÄ½ğ×Ó£¬°×»¨»¨µÄÒø×Ó£¬¹âÃ¢ËÄÉäµÄÒ¹Ã÷Öé£¬
¾§Ó¨ÌŞÍ¸µÄ×êÊ¯£¬Êı²»ÇåµÄÕäÖéÂêè§¡­¡­¾ÍÔÚÇ°Ãæ£¬Ã»¶àÔ¶ÁË£¬·Â
·ğÉìÊÖ¿É¼°¡ª¡ªÄãÊÜ²»ÁËÁË£¬²»ÓÉµÄ¼Ó¿ìÁË½Å²½¡£

LONG);
        set("exits", 
        ([
                "north" : __DIR__"maze1",
                "south" : __DIR__"maze1",
                "west" : __DIR__"maze11",
                "east" : __DIR__"maze4",
                "northeast" : __DIR__"maze3",
        ]));
        
        set("objects", 
        ([

        ]));

        setup();
}

void init()
{       
        object me=this_player();

        add_action("do_hujiu", "hujiu");

        if( me->query_temp("xmaze2") == 0 )
        {
                me->set_temp("xmaze2", 1);
        }
        else if( me->query_temp("xmaze2") == 1 )
        {
                reset_path(me);
        }
        
        if( check_out(me) ) me->move(__DIR__"baozang0");
}

void reset_path(object me)
{
        me = this_player();

        if( me->query_temp("xmaze1") ) me->delete_temp("xmaze1");
        if( me->query_temp("xmaze2") ) me->delete_temp("xmaze2");
        if( me->query_temp("xmaze3") ) me->delete_temp("xmaze3");
        if( me->query_temp("xmaze4") ) me->delete_temp("xmaze4");
        if( me->query_temp("xmaze5") ) me->delete_temp("xmaze5");
        if( me->query_temp("xmaze6") ) me->delete_temp("xmaze6");
        if( me->query_temp("xmaze7") ) me->delete_temp("xmaze7");
        if( me->query_temp("xmaze8") ) me->delete_temp("xmaze8");
        if( me->query_temp("xmaze9") ) me->delete_temp("xmaze9");
        if( me->query_temp("xmaze10") ) me->delete_temp("xmaze10");
        if( me->query_temp("xmaze11") ) me->delete_temp("xmaze11");
        if( me->query_temp("xmaze12") ) me->delete_temp("xmaze12");
        return;
}

int check_out(object me)
{
        me = this_player();

        if ( me->query_temp("xmaze1") != 1 ) return 0;
        if ( me->query_temp("xmaze2") != 1 ) return 0;
        if ( me->query_temp("xmaze3") != 1 ) return 0;
        if ( me->query_temp("xmaze4") != 1 ) return 0;
        if ( me->query_temp("xmaze5") != 1 ) return 0;
        if ( me->query_temp("xmaze6") != 1 ) return 0;
        if ( me->query_temp("xmaze7") != 1 ) return 0;
        if ( me->query_temp("xmaze8") != 1 ) return 0;
        if ( me->query_temp("xmaze9") != 1 ) return 0;
        if ( me->query_temp("xmaze10") != 1 ) return 0;
        if ( me->query_temp("xmaze11") != 1 ) return 0;
        if ( me->query_temp("xmaze12") != 1 ) return 0;
        if( me->query_temp("xmaze1") ) me->delete_temp("xmaze1");
        if( me->query_temp("xmaze2") ) me->delete_temp("xmaze2");
        if( me->query_temp("xmaze3") ) me->delete_temp("xmaze3");
        if( me->query_temp("xmaze4") ) me->delete_temp("xmaze4");
        if( me->query_temp("xmaze5") ) me->delete_temp("xmaze5");
        if( me->query_temp("xmaze6") ) me->delete_temp("xmaze6");
        if( me->query_temp("xmaze7") ) me->delete_temp("xmaze7");
        if( me->query_temp("xmaze8") ) me->delete_temp("xmaze8");
        if( me->query_temp("xmaze9") ) me->delete_temp("xmaze9");
        if( me->query_temp("xmaze10") ) me->delete_temp("xmaze10");
        if( me->query_temp("xmaze11") ) me->delete_temp("xmaze11");
        if( me->query_temp("xmaze12") ) me->delete_temp("xmaze12");
        return 1;
}
int do_hujiu(string arg)
{
        if( (!arg) || !((arg == "½ğºü¾ÈÎÒ") || (arg == "jinfox help me!")))
        return notify_fail( HIW "Äã½ĞÆÆÁËÉ¤×Ó£¬¿ÉÊÇÊ²Ã´Ò²Ã»ÓĞ·¢Éú£¡\n" NOR );
        else
        {
           message_vision( HIB "½ğºü²»Öª´ÓÄÄ¶ùÃ°ÁË³öÀ´,À­×Å$NµÄÊÖ¾Í×ßÁË!\n" NOR ,this_player());
           this_player()->move("/d/qujing/xuanyuan/yongdao2");
           tell_object(this_player(), HIB "½ğºü´ø×ÅÄã×ó»ÎÓÒ×ê¾Í³öÁËÃÔ¹¬¡£\n" NOR );
        }
        return 1;
}
