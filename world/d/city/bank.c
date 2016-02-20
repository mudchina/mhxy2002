//changan city
//by tianlin 2001/5/1

#include <ansi.h>
inherit BANK;

void reset_balance(object me);

void create ()
{
        set ("short","Ïà¼ÇÇ®×¯" );
        set ("long", @LONG

ÕâÊÇÒ»¼ÒÀÏ×ÖºÅµÄÇ®×¯£¬ÏàÀÏ°åÊÇÉ½Î÷ÈË£¬Õâ¼ÒÇ®×¯´ÓËûµÄÒ¯Ò¯µÄÒ¯
Ò¯µÄÒ¯Ò¯µÄÒ¯Ò¯ÄÇ±²¿ªÊ¼°ìÆğ£¬Ò»Ö±´«µ½ËûÊÖÀï£¬ÉùÓş·Ç³£ºÃ£¬ÔÚÈ«
¹ú¸÷µØ¶¼ÓĞ·Öµê¡£Ëü·¢ĞĞµÄÒøÆ±Í¨ĞĞÈ«¹ú¡£Ç®×¯µÄÃÅ¿Ú¹ÒÓĞÒ»¿éÅÆ×Ó
[1;33m(paizi)[2;37;0m¡£
LONG);
        set("item_desc", ([
                "paizi": @TEXT
ÕâÀïÊÇÇ®×¯£¬Ä¿Ç°ÎÒÃÇÌá¹©µÄ·şÎñÓĞ£º

[37maccount[2;37;0m         ²éÕÊ¡£
[37mdeposit[2;37;0m         ´æ¿î¡£
[37mwithdraw[2;37;0m        È¡¿î¡£
[37mconvert[2;37;0m         ¶Ò»»Ç®±Ò¡£

TEXT
        ]) );

        set("exits", 
        ([ //sizeof() == 4
		"north" : __DIR__"baihu-w1",
                   "down" : __DIR__"basement",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/tiesuanpan" : 1,
        ]));


//        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
}

void init()
{
    reset_balance(this_player());
    ::init();
}

void reset_balance(object me)
{
    int myexp=(me->query("daoxing")+me->query("combat_exp"))/1000;
    int allowed, removed_gold;
    string myid=me->query("id");
    string NPCNAME="ÌúËãÅÌ";

    if(myexp<1) myexp=1;
    if(myexp>100) myexp=100;
    allowed=myexp*1000000;//each year can have 100 gold, range 100-10000. 
    if (me->query("balance") > allowed)
    {
	me->set("balance_old", me->query("balance"));
	me->set("balance", allowed);
	removed_gold = (me->query("balance_old") - me->query("balance"))/10000;
	log_file("MONEY_RESET", ctime( time() )+"£ºÎº´óÈËÊÕ½ÉÁË"+me->query("name")+"("+me->query("id")+")"+removed_gold+"Á½»Æ½ğ¡£\n");
	tell_object(me, GRN+NPCNAME+"ÔÚÄãµÄ¶ú±ßÇÄÉùËµµÀ£º"+RANK_D->query_respect(me)+
		"£¬Õâ¡¢ÕâÕæ²»ÖªÔõÃ´ËµÊÇºÃ£®£®£®\n"NOR);
	tell_object(me, GRN+NPCNAME+"ÔÚÄãµÄ¶ú±ßÇÄÉùËµµÀ£º"+
		"×òÈÕÎº´óÈËÅÉÈËÇ°À´²ì°¸£¬·¢¾õÄãÀÏµÄ»Æ½ğÀ´Â·£®£®£®\n"NOR);
	tell_object(me, GRN+NPCNAME+"ÔÚÄãµÄ¶ú±ßÇÄÉùËµµÀ£º"+
		"Èô²»ÊÇÔÚÏÂ°ïÄãÀÏ±ç½â£¬ÄãÀÏµÄÇ®¾ÍÈ«¶¼³ä¹«ÁË£®£®£®\n"NOR);
    }
    return;
}

