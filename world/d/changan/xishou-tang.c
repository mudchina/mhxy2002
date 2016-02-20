#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","Ï´ÊÖ³Ø");
        set("long", @LONG
ÕâÀïÊÇ±øÂíÕ÷Õ½»ØÀ´½ÓÊÜÏ´ÀñµÄµØ·½£¬ÒÔÇóÏ´È¥É±ÄõÖ®Æø¡£
²¼ÖÃµÃºÜ¼òµ¥£¬ÖĞ¼äÒ»¸öË®³Ø£¬³ØÖĞÃ°³öôÁôÁË®Æû¡£Ïë´ÓĞÂ×÷ÈË£¬
Íü¼ÇÒÑÍùµÄ¶÷¶÷Ô¹Ô¹£¬Ö»ĞèÔÚÕâÀïÏ´ÊÖ[2;37;0m[5m[1;31m(xi)[2;37;0m,¾Í¿ÉÒÔ½µµôÉ±Æø£¬
ÍüµôËùÓĞ³ğ¼Ò¡£
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : "/d/changan/nanchengkou",
]));
	set("no_fight",1);
	set("no_magic",1);
	set("NONPC",1);
        
	setup();
}

void init()
{
	add_action("do_xi", "xi");
}

int do_xi()
{
	this_player()->remove_all_killer();
	message_vision(HIY"$N¹òµ¹ÔÚµØ£¬¾ö¶¨Íü¼ÇÒÔÇ°ËùÓĞµÄ³ğ¼Ò¡£\n"NOR,this_player());
	this_player()->set("bellicosity",0);
	message_vision(HIW"Äã¾õµÃÄãµÄÉ±ÄõÖ®ÆøÈ«¶¼ÏûÊ§ÁË£¡\n"NOR,this_player());
	return 1;

}
