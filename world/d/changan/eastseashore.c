//by tianlin@mhxy.2001.7.4Á¬½ÓµöÓãÌ¨
//By tianlin@mhxy for 2002.1.20.¼ÓÈëÌîº£ÈÎÎñ
#include <ansi.h>
inherit ROOM;

void check_trigger();
void on_board();
void arrive();
void close_passage();
int do_zuo(string arg);
int do_dive();
void reset();


void create ()
{
  set ("short", "¶«º£Ö®±õ");
  set ("long", @LONG

ÃæÇ°±ãÊÇ¶«º££¬Ã£Ã£´óº£Íû²»µ½±ß¼Ê¡£º£ÃæÉÏ²¨ÌÎĞÚÓ¿£¬¼¸ÕÉ
¸ßµÄÀËÍ·´ËÆğ±Ë·ü£¬ÏóÊÇÒªÍÌÃğÒ»ÇĞ¸ÒÓÚµ½º£ÉÏµÄ¶«Î÷¡£Ò²Ğí
ÕâÀï±ãÊÇÂ·µÄ¾¡Í·£¬ÃæÇ°µÄ´óº£¶ÔÒ»¸ö·²ÈËÀ´ËµÊÇ²»¿ÉÓâÔ½µÄ¡£
Àë°¶²»Ô¶´¦Æ¯×ÅÒ»Ö»Ä¾·¤[1;31m(mufa)[2;37;0m

LONG);
  set("objects", ([
   __DIR__"npc/jingwei":1,
"/d/obj/weapon/throwing/shi.c" : 1,
  ]));
  set("item_desc", ([ /* sizeof() == 1 */
  "mufa" : "Ò»Ö»Ä¾·¤£¬ÒÔ¼¸¸ù´óÔ²Ä¾À¦³É¡£Äã²»½ûÏë×ø(zuo)ÉÏÈ¥ÊÔÒ»ÊÔ¡£
",
]));
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"seashore2",
  "up" : __DIR__"fish",
]));
  set("outdoors", 1);

  setup();
}

void init()
{
    add_action("do_zuo", "zuo");
    add_action("do_zuo", "sit");
    add_action("do_dive", "dive");
}

void check_trigger()
{
    object room;

    if(!query("exits/enter") ) {
        if( !(room = find_object(__DIR__"mufa")) )
            room = load_object(__DIR__"mufa");
        if( room = find_object(__DIR__"mufa") ) {
            if((int)room->query("zuo_trigger")==0 ) {
                room->set("zuo_trigger", 1);
                set("exits/enter", __DIR__"mufa");
                room->set("exits/out", __FILE__);
                message("vision", "Ò»Ö»Ä¾·¤´Óº£ÉÏÆ¯ÁË¹ıÀ´¡£\n", this_object() );
                message("vision", "Ä¾·¤Ò»Õğ£¬ÏÔÈ»ÊÇ¸éÇ³ÁË¡£\n", room);
                remove_call_out("on_board");
                call_out("on_board", 15);
            }
            else
                message("vision", "Ä¾·¤ÕıÆ¯Ïò°¶±ß£¬¿´Ñù×Ó»¹µÃÄÍĞÄµØµÈµÈ¡£\n",this_object() );
        }
        else
            message("vision", "ERROR: mufa not found\n", this_object() );
    }
    else 
        message("vision", "Ä¾·¤ÒÑ¾­¿¿°¶ÁË£¬ËæÊ±¶¼¿ÉÉÏÈ¥¡£\n",
            this_object() );
}


void on_board()
{
    object room;

    if( !query("exits/enter") ) return;

    message("vision", "Ò»¸öÀËÍ·´òÀ´£¬Ä¾·¤Ïòº£ÉÏÆ¯È¥¡£\n",
        this_object() );

    if( room = find_object(__DIR__"mufa") )
    {
        room->delete("exits/out");
        message("vision", "ÖÜÎ§ÊÇ°×Ã£Ã£µÄÒ»Æ¬ÍôÑó£¬ÒÑ¾­¿´²»µ½ÈÎºÎÂ½µØµÄ¼£ÏóÁË...\n", room );
    }
    delete("exits/enter");

    remove_call_out("arrive");
    call_out("arrive", 20);
}

void arrive()
{
    object room;
    if( room = find_object(__DIR__"mufa") )
    {
        room->set("exits/out", __DIR__"aolaiws");
        message("vision", "Ä¾·¤Ò»Õğ£¬¸éÇ³ÁË¡£ÏÔÈ»ÊÇµ½Â½µØÁË£¬¸Ï½ôÉÏÈ¥°É¡£\n",room );
    }
    remove_call_out("close_passage");
    call_out("close_passage", 20);
}

void close_passage()
{
    object room;
    if( room = find_object(__DIR__"mufa") ) {
        room->delete("exits/out");
        message("vision","Ò»¸öÀËÍ·´òÀ´£¬Ä¾·¤Ïòº£ÉÏÆ¯È¥¡£\n", room);
room->set("zuo_trigger", 0);
    }
}

int do_zuo(string arg)
{
    string dir;

    if( (arg=="mufa") || (arg=="Ä¾·¤")){ 
        message_vision("$NÊÔ×ÅÏë×øÉÏÄ¾·¤¡£\n", this_player());
        check_trigger();
        return 1;
    }
    else return notify_fail("ÄãÒª×øÉÏÊ²Ã´£¿\n");
}

int do_dive()
{       object me, zhou;
    object ridee;
        me=this_player();
   ridee=me->ride();



	    if(( !(zhou=present("bishui zhou", me))
		||(string)zhou->query("unit")!="ÕÅ")
		&& (string)me->query("family/family_name")!="Áú¹¬"
		&& (string)me->query("family/family_name")!="¶«º£Áú¹¬")

		return notify_fail("ÄãÒ»¸öÃÍ×ÓÔúµ½Ë®Àï£®£®£®\n"+
		  "\nµ«Ã»¶à»á¶ù¾Í±»±ïµÃ°ëËÀ£¬Ö»ºÃ¸Ï½ôÅÀÉÏ°¶À´¡£\n");

   if (ridee && ridee->query("under_water")) {
     message_vision(HIY"$NÒ»ÅÄ$nµÄÍ·£¬Á¬ÈË´øÂíÔ¾ÈëË®ÖĞ¡£\n"NOR,me,ridee);
     ridee->move("/d/sea/under1");
  }

      else  message_vision(HIY "$NÒ»¸öÃÍ×ÓÔúµ½Ë®ÖĞ£¬È»ºó²»¼ûÁË£®\n" NOR, me);
                me->move("/d/sea/under1");
                me->start_busy(1); //Éè¶¨1¸öbusy¿ÉÒÔÈÃÍæ¼Ò¿ìËÙxiudao
		message_vision("$NÇ±ÁË¹ıÀ´¡£\n",me);
                return 1;
}

void reset()
{
    object room;

    ::reset();
    if( room = find_object(__DIR__"mufa") )
        room->delete("zuo_trigger"); 
}
