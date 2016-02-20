//By tianlin@mhxy for 2002.2.25

inherit NPC;
#include <ansi.h>

void create()
{
       set_name("雷公", ({"lei gong", "lei", "gong"}));
       set("long", "一个耳朵很长的怪人，手中持一对铁罄。\n");
       set("gender", "男性");
       set("age", 70);
       set("title", HIY"天宫"HIR"上仙"NOR);
       set("attitude", "friendly");
       set("per", 30);
       set("max_kee",8000);
       set("max_sen", 8000);
       set("force", 5000);
       set("max_force", 5000);
       set("force_factor", 80);
       set("max_mana", 1200);
       set("mana", 2300);
       set("mana_factor", 20);
       set("combat_exp", 1200000);

       set("eff_dx", 250000);
       set("nkgain", 400);
       set("class","taoist");
       set_skill("literate", 90);
       set_skill("unarmed", 120);
       set_skill("dodge", 120);
       set_skill("parry", 120);
       set_skill("stick", 120);
       set_skill("spells", 120);
       set_skill("dao", 120);
       set_skill("puti-zhi", 120);
       set_skill("wuxiangforce", 120);
       set_skill("force", 120);
       set_skill("qianjun-bang", 120);
       set_skill("jindouyun", 120);
       map_skill("spells", "dao");
       map_skill("unarmed", "puti-zhi");
       map_skill("force", "wuxiangforce");
       map_skill("stick", "qianjun-bang");
       map_skill("parry", "qianjun-bang");
       map_skill("dodge", "jindouyun");
       set("chat_chance_combat", 40);
       set("chat_msg_combat", ({
                (: cast_spell, "thunder" :),
                "雷公怒道：又是来抢我的雷灵珠的。\n"
        }) );

        set("inquiry", ([
           "雷灵珠" : "此乃我的宝贝．",
]) );

setup();
carry_object("/d/obj/cloth/xianpao")->wear();
carry_object("/d/obj/baowu/leizhu")->wear();
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
                if (inv[i]->query("id")=="leizhu" || inv[i]->query("id")=="lei lingzhu")
                {
                   inv[i]->move(me);
                   message_vision("$N头顶冒出一颗绿色的珠子，$n赶忙一把抓到怀里。\n",this_object(),me);
            message("channel:rumor",HIG+"【小道消息】某人：听说"HIY+me->query("name")+HIG"拿到传说中的"HIB"雷灵珠"HIG"了！\n"+NOR,users());
         }
        }
  }
 ::die();
}

