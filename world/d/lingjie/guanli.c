// link
// Áé½ç¹ÜÀí´¦£¬Éæ¼°·¹¿¨µÄ³äÖµ


#include <ansi.h>
inherit BANK;

void reset_balance(object me);


void create()
{
	set("short", HIC"Áé½ç¹ÜÀí´¦"NOR);
	set("long", @LONG
Õâ¼äÍâ±í»ªÀöÊµÔòÄÚ²¿×°ÐÞÆÆÀÃ²»¿°µÄ·¿×Ó¾ÍÊÇÁé½ç¹ÜÀí´¦ÁË£¬³ýÁË·¿×Ó
µÄÖÊÁ¿±ÈÆäËûµØ·½ºÃµã¶ù£¬Ò²ÕÒ²»µ½Ê²Ã´ÆäËûµÄÓÅµãÁË¡£·¿¼äÖÐÑëÓÐÒ»¸ö
¸ß´óµÄ¹ñÌ¨£¬²î²»¶à±ÈÈË¶¼¸ßÁË£¬ÉÏÃæ¹Ò×ÅÒ»ÕÅ±í£¨£ó£é£ç£î£©¡£
[31m
                      Áé  ½ç  ¹Ü  Àí  ´¦
[37m
LONG
	);
	
	set("exits", ([
		"out"   	: __DIR__"shengdian3",
	]) );
        set("item_desc", ([
                "sign": @TEXT
ÕâÀïÊÇÁé½ç¹ÜÀí´¦£¬Ä¿Ç°ÎÒÃÇÌá¹©µÄ·þÎñÓÐ£º

account         ²éÕÊ¡£
deposit         ´æ¿î¡£
withdraw        È¡¿î¡£
convert         ¶Ò»»Ç®±Ò¡£

TEXT
        ]) );

	set("objects", ([//sizeof() == 1

		__DIR__"npc/guanli-officer" : 1,

			]) );


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
    string NPCNAME="¹ÜÀíÔ±";

    if(myexp<1) myexp=1;
    if(myexp>100) myexp=100;
    allowed=myexp*1000000;//each year can have 100 gold, range 100-10000. 
    if (me->query("balance") > allowed)
    {
        me->set("balance_old", me->query("balance"));
        me->set("balance", allowed);
        removed_gold = (me->query("balance_old") - me->query("balance"))/10000;
        log_file("MONEY_RESET", ctime( time() )+"£ºÓÄÖúÊÕ½ÉÁË"+me->query("name")+"("+me->query("id")+")"+removed_gold+"Á½»Æ½ð¡£\n");
        tell_object(me, GRN+NPCNAME+"ÔÚÄãµÄ¶ú±ßÇÄÉùËµµÀ£º"+RANK_D->query_respect(me)+
                "£¬Õâ¡¢ÕâÕæ²»ÖªÔõÃ´ËµÊÇºÃ£®£®£®\n"NOR);
        tell_object(me, GRN+NPCNAME+"ÔÚÄãµÄ¶ú±ßÇÄÉùËµµÀ£º"+
                "×òÈÕ°®ºóÓàÉúÅÉÈËÇ°À´²ì°¸£¬·¢¾õÄãÀÏµÄ»Æ½ðÀ´Â·£®£®£®\n"NOR);
        tell_object(me, GRN+NPCNAME+"ÔÚÄãµÄ¶ú±ßÇÄÉùËµµÀ£º"+
                "Èô²»ÊÇÔÚÏÂ°ïÄãÀÏ±ç½â£¬ÄãÀÏµÄÇ®¾ÍÈ«¶¼³ä¹«¸øåÐÒ£ÁË£®£®£®\n"NOR);
    }
    return;
}

