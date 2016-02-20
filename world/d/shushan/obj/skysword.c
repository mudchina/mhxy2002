//jueshi.c by yushu 2000.11
#include <weapon.h>
#include <ansi.h> 
inherit F_UNIQUE;
inherit SWORD;
void create()
{
        set_name(RED"天剑"NOR, ({"sky sword", "sword", "jian"}));
        set_weight(50000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
              set("unit", "把");
              set("long", "一把淡绿色的细剑，看起来非常的华丽．\n");
              set("no_sell", 1); 
              set("no_give", 1);
              set("no_drop", 1);
              set("no_put", 1);
              set("value", 30000); 
              set("replace_file", "/d/obj/weapon/sword/qinghong");
              set("material", "gold");
              set("wield_msg", "$N「唰」地一声抽出一把$n握在手中．\n");
              set("unwield_msg", "$N将手中的$n插入腰间，嘴角露出一丝笑意．\n");
              set("weapon_prop/int", 2);

        }
        init_sword(150); 
        set("is_monitored",1);
        setup();
}

void announce(object who)
{
    if(!this_object()) return;
    if(!who) return;
    CHANNEL_D->do_channel(this_object(), "rumor", 
            "听说"+who->query("name")+"得到了"+name()+"！\n");
}
void init()
{
    call_out("self_dest",1200+random(600),this_object());
    remove_call_out("announce");
    call_out("announce",random(10),this_player());
}


