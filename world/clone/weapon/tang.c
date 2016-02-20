
#include <weapon.h>
inherit SWORD;

void create()
{
        set_name("[1;32;5;43mÌÆÌ«×Ú[m", ({ "sword" }));
        set_weight(6000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "±ú");
                set("long", "ÕâÊÇÒ»±ú¾«¹¤ÖÆ³ÉµÄ¸Ö½££¬ÕâÖÖ½£ÔÚ½«ÁìÖ®¼ä·Ç³£Á÷ĞĞ¡£\
n");
                set("value", 2000000);
                set("material", "gold");
                set("wield_msg", "$N¡¸à§¡¹µÄÒ»Éù³é³öÒ»±ú$nÎÕÔÚÊÖÖĞ¡£\n");
                set("unwield_msg", "$N½«ÊÖÖĞµÄ$n²å»Ø½£ÇÊ¡£\n");
        }
        init_sword(700);
        setup();
}
