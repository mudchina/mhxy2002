// gangjian.c

#include <weapon.h>
inherit DAGGER;

void create()
{
        set_name("[1;32m×æÄ¸ÂÌ×êÊ¯[m", ({"diamon" }));
        set_weight(6000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "°Ñ");
                set("long", "ÕâÊÇÒ»Á£Ç§ÄêÄÑ¼ûµÃ×æÄ¸ÂÌ±¦Ê¯,£\n");
                set("value", 2000);
                set("material", "steel");
                set("wield_msg", "$N´Ó¶µÀïÌÍ³öÒ»°Ñ$nÎÕÔÚÊÖÖĞ¡£\n");
                set("unwield_msg", "$N½«ÊÖÖĞµÄ$n·Å»á¶µÀï¡£\n");
        }
        init_dagger(25,0);
        setup();
}
