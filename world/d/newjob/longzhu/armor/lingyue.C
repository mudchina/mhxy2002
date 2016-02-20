
#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIW "灵月圣衣" NOR, ({ "lingyue cloth", "cloth","lingyue" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "灵月仙界特有的仙节树脂制成的衣服。\n");
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 50);
                set("armor_prop/personality", 5);
                set("dodge", 200);
        }
        setup();
}
