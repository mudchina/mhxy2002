inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(BLINK HIY "太阳" NOR , ({ "tai yang" , "sun" }) );
        set("long", BLINK HIR "红彤彤的太阳，散发出帜热的火焰。 \n" NOR);
        set("unit","个");
        setup();
}
