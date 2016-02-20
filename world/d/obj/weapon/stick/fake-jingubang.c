//fake-jingubang.c
//the real jingubang may be used to improve stick level.
//this one is weapon only, less powerful,
//and simply put with ao-guang for highhands...weiqi:)

#include <ansi.h>
#include <weapon.h>

inherit F_UNIQUE;
inherit STICK;

void create()
{
	set_name( HIY"½ğ¹¿°ô"NOR, ({ "xiao jin gu bang","jingubang", "bang" }) );
	set_weight(100000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "Ìõ");
		set("Can_avoid_find", 1);
		set("no_sell", 1);
		set("no_give", 1);
//		set("no_get", 1);
		set("value", 5000);
		set("material", "gold");
        set("replace_file", "/d/obj/weapon/stick/bintiegun");
		set("long", "´Ë°ôÁ½Í·ÒÔ½ğÎª¹¿£¬ÖĞ¼äÄËÒ»¶ÎÎÚÌú¡£ÉÏÖıÒ»ĞĞĞ¡×Ö£º¡°ÈçÒâ½ğ¹¿°ô£¬¶«º£°½¹ã¼àÖÆ¡±¡£\n\n\t\t\t\t[1;31m¡õ[1;33m\n\t\t\t\t¨€\n\t\t\t\t¨€\n\t\t\t\t¨€\n\t\t\t\t¨€\n\t\t\t\t¨€\n\t\t\t\t¨€\n\t\t\t\t¨€\n\t\t\t\t¨€\n\t\t\t\t¨€\n\t\t\t\t¨€\n\t\t\t\t\[1;31m¡õ[2;37;0m\n");
		set("wield_msg", "$NÒ»ÉìÊÖ£¬Á¬ºÈ¼¸Éù£º´ó£¡´ó£¡´ó£¡ÕÆÖĞºöÈ»¶àÁËÒ»Ìõ$n¡£\n");
		set("unwield_msg", "$NÒ»´µÆø£¬¼¸ÉùÇáºÈ£ºĞ¡£¡Ğ¡£¡Ğ¡£¡$nÔÚ$NÕÆÖĞ×ªÁË¼¸×ª£¬ºöÈ»²»¼ûÁË¡£\n");
	}
	init_stick(180);
	setup();
}
