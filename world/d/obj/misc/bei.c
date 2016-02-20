//create by guoth

#include <ansi.h>

inherit ITEM;

void create()
{
   set_name( HIG "※"+HIC+"巫师纪念碑"+HIG+"※" NOR , ({ "jinian bei" }) );
   set_weight(200000);
   set("long", @LONG
这是为西游记的创世英雄们树立的纪念碑
以下是他们的名字：

            ☆:  ( elva   )
            ☆: 小    鸟 (tianlin )
            ☆: 水 中 月 (lovechao)
            ☆: 麦克小狼 ( pkyou  )
            ☆: 飞天霹雳 (  momo  )
            ☆: 无    缘 (stygian )
            ☆: 小    雪 (xiaoxue )

         希望您也能成为里边其中的一员
LONG);
       if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "座");
                set("material", "stone");
                set("value", 2000);
                set("no_get", 1);
                set("amount",30);
        }
 
            setup();
}

