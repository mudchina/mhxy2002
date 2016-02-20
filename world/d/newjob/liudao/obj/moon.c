inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(BLINK HIB "月亮" NOR , ({ "yue" , "moon" }) );
        set("long", BLINK HIW "一颗圆圆的月亮，闪耀着温柔的光芒。 \n" NOR);
        set("unit","个");
        setup();
}
