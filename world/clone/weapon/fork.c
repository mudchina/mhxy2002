
#include <weapon.h>

inherit FORK;

void create()
{
        set_name("[1;32;44mÑÖÍõ¼û¶¼ÅÂ[m", ({ "fork" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("no_drop",1);
                set("no_put",1);
//                set("no_give",1);
                               set("unit", "±ú");
                set("value", 1000);
                set("material", "iron");
                set("long", "Ò»±ú·æÀûµÄ¸Ö²æ¡£\n");
                set("wield_msg", "$N³­ÆğÒ»±ú$n£¬»¹ÄÃÒÂ·ş²ÁÁË²Á²æ¼â¡£\n");
        }
        init_fork(190);
        setup();

}
