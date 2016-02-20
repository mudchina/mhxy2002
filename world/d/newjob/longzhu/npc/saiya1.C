// 赛亚人族 by Calvin

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("赛亚人", ({"sai ya","sai","ya"}));
        set("gender", "男性" );
        set("age", 16);
set("long","这是一位未知人类。\n");
       set("max_kee", 10000);
       set("max_gin", 1000);
       set("max_sen", 10000);
       set("force", 6000);
       set("max_force", 6000);
       set("force_factor", 1000);
       set("max_mana", 6000);
       set("mana", 6000);
       set("mana_factor", 1000);
       set("daoxing", 100000000);
       set("combat_exp", 100000000);
        set_skill("dodge", 1000);
        set_skill("parry", 1000);
        set_skill("spells", 1000);  
        setup();
        carry_object("/d/longzhu/obj/6");
            carry_object("/d/longzhu/armor/skirt")->wear();
}

void die()
{
 int i;
 object me,*inv;
 if(objectp(me=query_temp("last_damage_from") ))
        {
            inv = all_inventory(this_object());
            for(i=0; i<sizeof(inv); i++)
            {
                if (inv[i]->query("id")=="6" || inv[i]->query("id")=="qing longzhu")
                {
                   inv[i]->move(me);

                   message_vision("$N掉下一枚纯青色的珠子，$n赶忙一把抓到怀里。\n",this_object(),me);
            message("channel:rumor",HIG+"【"HIW"龙珠传说"HIG"】"HIC"孙悟空"HIW"：据说"+me->query("name")+"在赛亚星球附近得到了"HIG"青龙珠"HIW"。\n"+NOR,users());
         }
        }
  }
 ::die();
}
