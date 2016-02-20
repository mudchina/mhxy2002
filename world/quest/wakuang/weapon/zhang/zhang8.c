#include <weapon.h>
#include <ansi.h>

inherit STAFF;
inherit F_UNIQUE;

void create()
{
        set_name(HIY"普度众生禅杖"NOR,({ "puduzhongsheng chanzhang", "chanzhang", "staff", "zhang" }) );
        set_weight(50000);
if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 0);
                set("rigidity", 9);
                set("no_give", "这是你的心血啊怎么能轻易送人呢?\n");
                set("sharpness", 9); 
                set("unique", 1);
                set("no_get", 1);
                set("material", "steel");
                set("weapon_prop/dodge", -5);
                set("weapon_prop/parry", 5);
                set("treasure",1);
                set("wield_force", 300);
                set("wield_maxforce", 700);
                set("wield_str", 22);
                set("wield_msg", HIY"\n$N呼的抽出一把普度众生禅杖，四周焚音漫漫，周围的人禁不住对你膜拜。\n\n"NOR);
                set("long", "无欲无念，佛由心生，佛由心拜，普度众生。\n");                
                set("unwield_msg", HIY "$N将普度众生禅杖放下，焚音立停，四周恢复了正常。\n" NOR);                
}
        init_staff(160);
        setup();
}
