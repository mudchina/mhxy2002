//modify by ken
#include <weapon.h>
inherit SWORD;
#include <ansi.h>
inherit F_UNIQUE;

void create()
{
   set_name(HIR"天下"NOR, ({"world sword", "sword","jian"}));
   set_weight(5000);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("unit", "把");
     set("long", "名剑·天下。\n");
     set("value", 50000);
     set("material", "steel");
     set("replace_file","/d/obj/weapon/sword/qingfeng");
     set("wield_msg", HIR"$N抄起天下一挥，顿时一片红光直冲云霄。\n"NOR);
     set("unwield_msg", HIR"红光一闪，天下飞回了$N的手中。\n"NOR);
   }
   init_sword(200);
   setup();
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int pro;
        int dam;
        dam = (int) me->query("force");
        victim->receive_damage("kee",dam/20);
        victim->start_busy(1);
                switch(random(7)) {
                        case 0: return HIR "天下一下就砸到了$n的胯下，结果一下命中，疼痛超越了$n忍耐的极限，$n因此倒在地上痛苦哀嚎。\n" NOR;
                        case 1: return HIW "天下轻轻的碰了$n的胯下一下，在这重重的一击下$n倒在了地上，啊，那一定很痛。\n" NOR;
                        case 2: return HIB "天下的刀锋扫过了$n的左臂，一下把$n的左臂打断了，只剩下一些皮肉连着断骨。\n" NOR;
                        case 3: return HIC "$N运天下敲了敲$n的右臂，这一下把$n的右肘打碎了，把$n的右手打成了残疾。\n" NOR;
                        case 4: return HIR "$N顺势拿起天下戳向$n的眼睛，看来这对$n的打击太大了，因为$n的眼睛不见了。\n" NOR;
                        case 5: return RED "$N举起天下砸向$n的左腿，很容易就把$n的左腿打跛了，因此$n抱着脚不停的惨嚎。\n" NOR;
                        case 6: return RED "$N拿起天下剁向$n的右脚，一阵焦臭过后$n很惊奇的发现他的一条腿跟他说了再见。\n" NOR;
                     }        
}
