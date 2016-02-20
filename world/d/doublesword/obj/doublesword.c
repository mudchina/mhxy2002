
#include <weapon.h>


inherit SWORD;

#include <ansi.h>

void create()
{
        set_name(HBRED"紫青双剑"NOR, ({ "doublesword","sword","jian"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "对");
  set("long",
"一对古剑,剑柄上分别刻有"+MAG"「紫郢」"NOR+"，"+HIG"「青索」"NOR+"两字.\n"
"剑身隐有紫青两色霞光流动,看起来是一对神兵利器.\n");
        set("no_drop","这么好的宝物，你去扔 ! 原来吃饱了没事干呀 !!!\n");
        set("no_give","这么好的宝物，给别人? 你入党了没有? \n");
        set("no_sell", 1);
       
         set("value", 9000);
                set("material", "blacksteel");
set("wield_msg",HIB"\n两道眩目的"HIM" 紫 "HIC"青 "HIB"剑光闪过,双剑和体,你一握在手,不由豪气顿生.\n\n"NOR);

set("unwield_msg",HIC"\n$N一声长啸,双剑瞬然不见.\n\n"NOR);
        }
        init_sword(180);
        setup();
}


