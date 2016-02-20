//by tianlin 2001.5.1
//未做完!
#include <ansi.h>
#include <armor.h>
inherit NECK;

void create()
{
      set_name(HIY"隐身勋章"NOR, ({"yinshen zhang", "zhang"}));
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("value", 2000);
                set("long", HIY"这个是隐身用的勋章! \n"NOR);
                set("no_sell", 1);
                set("material", "steel");
                set("armor_prop/spells", 5);
                set("armor_prop/armor", 1);
                set("armor_prop/intelligence", 10);
                set("env/invisibility", 1);
                set("no_drop","这么好的宝物，扔了多可惜呀！\n");
                set("no_sell", 1);
        }
        setup();
}
int query_autoload() { return 1; }

 