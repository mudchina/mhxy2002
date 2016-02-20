#include <weapon.h>
#include <ansi.h>

inherit STICK;
inherit F_UNIQUE;

void create()
{
        set_name(HIC"倚天青龙棍"NOR,({ "yitian gun", "yitian", "stick", "bang" }) );
        set_weight(20000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 1);
                set("rigidity", 9);
                set("sharpness", 9);
                set("no_give", "这是你的心血啊怎么能轻易送人呢?\n");
                set("unique", 1);
                set("no_get", 1);
                set("material", "steel");
                set("weapon_prop/dodge", -5);
                set("weapon_prop/parry", 5);
                set("treasure",1);
                set("wield_force", 300);
                set("wield_maxforce", 700);
                set("wield_str", 22);
                set("wield_msg", HIY"$N“呼”的一声抽出倚天青龙棍挽了个棍花，但见寒芒吞吐，电闪星飞。\n$N不由得从心底升起一股凌云豪气。\n"NOR);
                set("long", "这是一根六尺长棍，棍身上金丝镶着‘倚天’两个篆文。\n整个棍身隐隐发出一层青气。\n");                
                set("unwield_msg", HIY "倚天青龙棍幻作一道血光，「呼」地飞入腰间。\n" NOR);                
}
        init_stick(120);
        setup();
}
