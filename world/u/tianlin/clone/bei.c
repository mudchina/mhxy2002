//by angela@mhxy 2001.12.25
#include <ansi.h>
#include <armor.h>
inherit NECK;

void create()
{
      set_name(HIY"咖啡杯"NOR, ({"kafei bei", "bei"}));
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("value", 2000);
                set("long", HIY"这是"HIW"冰　舞　飞　雪"HIY"的咖啡杯"BLINK""HIC"
         _..,----,.._
      .-;'-.,____,.-';
     (( |            |
      `))            ;
       ` \          /
      .-' `,.____.,' '-.
     (     '------'     )
      `-=..________..--'
 \n"NOR);
                set("no_sell", 1);
                set("material", "steel");
                set("armor_prop/spells", 5);
                set("armor_prop/armor", 1);
                set("armor_prop/intelligence", 10);
                set("no_drop","这么好的宝物扔了多可惜呀！\n");
                set("no_sell", 1);
        }
        setup();
}

 