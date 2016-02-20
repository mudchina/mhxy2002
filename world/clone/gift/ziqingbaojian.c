//yitianjian.c
#include <weapon.h>

inherit SWORD;

void create()
{
    set_name("[1;36m×ÏÇà±¦½£[2;37;0m", ({ "ziqing baojian", "baojian","jian","sword" }) );
    set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        	set("unit", "±ú");
        	set("value", 50000);
//        	set("no_drop", "1");
              set("no_sell", "1");
        	set("material", "iron");
        	set("long", "ÕâÊÇÌìÏÂµÚÒ»ÀûÆ÷£¬ÓĞ¡°ÒĞÌì²»³ö£¬Ë­ÓëÕù·æ¡±Ö®Ëµ¡£\n");
        	set("wield_msg","Ö±Èç½ÃÁúÍÌË®£¬³¤ºç¹ÚÈÕÒ»°ã£¬$nÒÑÔÚ$NÊÖÖĞ£¬ÌìµØÎªÖ®±äÉ«¡£\n");
        	set("unwield_msg", "$N½«$n²å»ØÑü¼ä£¬»ª¹â¶ÙÁ²£¬ÌìµØ¼äÖ»ÎÅÁúÃù¡£\n");
	}
        init_sword(90);
	setup();
}
