//By waiwai@mszj 2000/11/12

inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(BLINK HIR "»ð" NOR , ({ BLINK HIR "fire" NOR, "huo" }) );
        set("long", BLINK HIR "Ò»ÍÅÐÜÐÜÈ¼ÉÕµÄ»ð \n" NOR);
        set("no_get",1);
        
        setup();
}

