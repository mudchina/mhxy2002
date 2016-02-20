// Lly@FYSY
inherit ITEM;
void create()
{
	set_name("Ä¾ÅÆ", ({ "Ä¾ÅÆ","´óÄ¾ÅÆ", "mupai", "tablet" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "¸ö");
                set("long", "ÄãÏÆ¿ªÄ¾ÅÆÉÏµÄºÚ²¼£¬Â¶³öÒ»¿éØÒ£¬ºÍÎå¸ö½ğ¹â²ÓÁÇµÄ×Ö:
                          
                          [37;41m*[33m   Ìì ÏÂ µÚ Ò» ½£[37;41m   *[0m
                         
Ğ»ÍõËïËµµÀ£º¡°ÕâÊÇ×Ô¹ÅÒÔÀ´£¬½­ºşÖĞ´ÓÀ´Ã»ÓĞÈËµÃµ½¹ıµÄÈÙÓş£¬Ğ»¼ÒµÄ×ÓËï£¬Ò»Ö±¶¼¶ÔËüºÜÕäÏ§£¬Ò²ºÜ²ÑÀ¢¡£
ÒòÎªÏÖÔÚĞ»¼ÒµÄ×ÓËï¾ÍÃ»ÓĞÒ»¸öÄÜÅäµÃÉÏÕâÎå¸ö×Ö¡£¡±\n");
		set("value", 70);
		set("material", "wood");
		set("no_shown",1);
		set("no_get",1);
		set("no_drop",1);
		
	}
}
