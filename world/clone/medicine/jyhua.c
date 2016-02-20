//jyhua.c

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name(  HIY"½ð[1;37mÒø[32m»¨[36mÂ¶[m" NOR, ({"jinyinhua lu", "lu"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "ÕâÊÇÒ»Æ¿ÌØÖÆµÄ½ðÒø»¨Â¶£¬º¦ÅÂÈÈµÄÈËÒ»°ã¶¼»áÓÐËæÉíÐ¯´øÕâÖÖÒ©Æ·¡£¡£\n");
                set("base_unit", "Æ¿");
                set("unit","Æ¿");
                set("value", 5000);
                set("weight", 50);
                set("only_do_effect", 1);/*
                set("mixture", ([
                        "herb"      : ([ "jyhua"  : 1, ]),
                        "neili"     : 80,
                        "jing"      : 35,
                        "time"      : 1,
                        "min_level" : 50,
                        "medical"   : 80,
                               ]));*/
        }
        setup();
}

int do_eat(string arg)
{
        mapping my;
         object me=this_player();

        if( !arg || arg != "jinyinhua lu" )
        {
                write("ÄãÒªÓÃÊ²Ã´Ò©£¿\n");
                return 1;
        }
        if (time() - me->query_temp("last_eat/jyhua") < 20)
        {
                write("Äã¸Õ·þÓÃ¹ýÒ©£¬ÐèÒ©ÐÔ·¢»ÓÍêÐ§ÓÃÒÔºó²ÅÄÜ¼ÌÐø·þÓÃ¡£\n");
                return 1;
        }

        my = me->query_entire_dbase();

        
        if ( !(me->query_condition("ill_zhongshu")) )
        {
                write("ÄãÏÖÔÚÃ»ÓÐÖÐÊî£¬ÎÞÐè·þÓÃ" + name() + "¡£\n");
                return 1;
        }

        me->set_temp("last_eat/jyhua", time());

        message_vision(HIW "$N" HIW "Ä¨ÁËµã" + name() +"ÔÚÌ«ÑôÑ¨ÉÏ"
                       HIW "£¬¶ÙÊ±¸Ð¶¯ÇåË¬¶àÁË¡£\n" NOR, me);

        me->apply_condition("ill_zhongshu", 0);
        
        me->receive_curing("kee", 30);
        me->receive_heal("kee", 30);

        me->start_busy(1);
        destruct(this_object());
        return 1;
}
