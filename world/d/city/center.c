//changan city
//by tianlin@mhxy 2001/9/3
//Éè¶¨Ò»µãÄÑ¶È,±ÈÈçËµ¿ÉÒÔ¼ÓÉÏclimbµÄÒªÇó,Ê²Ã´dodge 100²ÅÄÜÅÀ...µÈµÈ
//»òÕßÊÇwx<¶àÉÙ²»ÄÜÅÀÒ»ÀàµÄ,ÎÒÉèÉÏÕâÃ´¸ö¶«Î÷Ö÷ÒªÊÇÎªÁËºÃÍæ,ÓĞµãĞÂÏÊ¸Ğ
//ÎÒÔÚ´Î¾ÍÖ»ÉèÒ»¸öwxµÄÒªÇó°É,´ó¼Ò¿ÉÒÔ²Î¿¼Õâ×öÒ»ÏÂĞŞ¸Ä,µ«Çë²»Òª¸Ã×÷ÕßµÄÃû×Ö
//Ğ»Ğ»!!!!!!
inherit ROOM;
#include <room.h>
#include <ansi.h>

void create ()
{
  set ("short","Ê®×Ö½ÖÍ·");
        set ("long", @LONG

ÕâÀï±ãÊÇ³¤°²³ÇµÄÖĞĞÄ£¬ËÄÌõ´ó½Ö½»»ãÓÚ´Ë¡£Ò»×ùÎ¡¶ë¸ß´óµÄÖÓÂ¥ËÊ
Á¢ÓÚÇ°£¬ºÜÊÇÓĞĞ©ÆøÊÆ¡£Ã¿µ½Çå³¿£¬ÏìÁÁµÄÖÓÉù±ã»á°é×Åµ­µ­ÎíÆø´«
Ïò³¤°²³ÇµÄ´ó½ÖĞ¡Ïï¡£Â·¿Ú³µË®ÂíÁú£¬À´ÍùÈË³±²»¶Ï¡£Â·±ß²»ÖªÊ²Ã´
Ê±ºòÖÖÁËÒ»¿Å[1;32m´óéÅÊ÷[2;37;0m[1;33m(tree)[2;37;0m£¬ÅÌ¸ù´í½Ú£¬ÒÑ¾­ºÜÓĞÒ»¶ÎÀúÊ·ÁË¡£
LONG);
set("item_desc", ([ /* sizeof() == 2 */
  "tree" : "Ò»¿Ã¸ß´óÎŞ±ÈµÄ´óÊ÷,Äã¿ÉÒÔÉÏÈ¥¿´¿´"HIG"(climb tree)"NOR"\n",
  "up": HIY"Ê÷ÉÏÔÆÎíçÔÈÆ£¬Ê²Ã´Ò²¿´²»Çå³ş¡£\n"NOR,
]));

        set("exits", 
        ([ //sizeof() == 4
//		"enter" : "/d/biwu/biwu.c",
		"south" : __DIR__"zhuque-s1",
              "north" : __DIR__"xuanwu-n0",
"up" : "/d/liwu/happyjie",
               "west" : __DIR__"baihu-w1",
               "east" : __DIR__"qinglong-e1",
               "down" : __DIR__"droproom",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/libai" : 1,
                __DIR__"npc/paimaishi" : 1,
               // __DIR__"npc/vikee" : 1,
              "/d/qujing/wuzhuang/npc/zhangguolao": 1,
                "/u/tianlin/table" : 1,
                "/u/tianlin/bei":1,
        ]));

       set("outdoors", "changan");
	set("no_clean_up", 0);
       setup();
	//replace_program(ROOM);
       }
void init()
{
	add_action("do_climb", "climb");
}

int do_climb(string arg)
{
	object me=this_player();
	
	if( !arg || (arg!="tree" && arg!="Ê÷") )
		return notify_fail(HIG"ÄãÒªÅÀÊ²Ã´£¿\n"NOR);
	if(me->is_busy())
		return notify_fail(YEL"ÄãºÜÃ¦£¬ÅÀÊ²Ã´Ñ½£¡\n"NOR);
       if(me->query("combat_exp")<20000)
              return notify_fail(HIC"¾ÍÆ¾ÄãÏÖÔÚµÄ±¾ÊÂÒ²ÏëÅÀÉÏÈ¥.\n»¹ÊÇÔÚÁ·Á½Äê°É!\n"NOR);
	message_vision(HIY"$NÂıÂıµÄÍùÊ÷¶¥ÅÀÈ¥,Ò»²½Ò»²½Ğ¡ĞÄÇ°½ø... \n"NOR, me);
	me->start_busy(3);

	if( (int)me->query("kee") < 500 || (int)me->query("sen") < 500) {
		call_out("faila", 3, me);
		return 1;
	}

	call_out("success", 3, me);
	return 1;
}
int success(object me)
{
	message_vision(CYN"$NÔ½ÅÀÔ½¸ß£¬Í»È»¿´¼ûÒ»×ù·¿×Ó ... \n"NOR, me);
	me->move("/d/city/jiuguan1");
	message_vision(WHT"$NÂıÂıµÄÅÀÁËÉÏÀ´¡£\n"NOR, me);
	return 1;
}

/*
int valid_leave (object who, string dir)
{
  if (dir == "up")
    return notify_fail (HIR"Äã¿´ÁË¿´,×ßÊÇ×ß²»ÉÏÈ¥µÄ,Ö»ÓĞÅÀÉÏÈ¥»¹ÓĞµã¿ÉÄÜĞÔ¡£\n"NOR);
  return ::valid_leave(who,dir);
}
*/



