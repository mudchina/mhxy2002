//EDIT BY LUCAS
#include <ansi.h>
inherit NPC;

void create()
{
       set_name("幽雾公主", ({"youwu gongzhu","gongzhu","youwu"}));

        set("long","西海公主幽雾，她长得：\n凝烟如霜肌带雪,映月粘露显柔姿.樱唇皓齿朱颜麝,异香霓霞熏凤裙。\n");
       set("gender", "女性");
       set("age", 20);
       set("int", 30);
       set("title", "西海公主");
       set("attitude", "peaceful");
       set("combat_exp", 1000000);
       set("rank_info/respect", "公主殿下");
       set("class","dragon");
       set("per", 40);
       set("max_kee", 1000);
       set("max_sen", 8000);
       set("force", 1000);
       set("max_force", 1000);
       set("force_factor", 50);
       set("max_mana", 1000);
       set("mana", 1000);
       set("mana_factor", 80);
       set_skill("literate", 120);
       set_skill("unarmed", 100);
       set_skill("dodge", 150);
       set_skill("force", 120);
       set_skill("parry", 130);
       set_skill("fork", 100);
       set_skill("spells", 150);
       set_skill("seashentong", 140);
       set_skill("dragonfight", 100);
       set_skill("dragonforce", 100);
       set_skill("fengbo-cha", 100);
       set_skill("dragonstep", 150);
       map_skill("spells", "seashentong");
       map_skill("unarmed", "dragonfight");
       map_skill("force", "dragonforce");
       map_skill("fork", "fengbo-cha");
       map_skill("parry", "fengbo-cha");
       map_skill("dodge", "dragonstep");

        set("chat_chance",5);
        set("chat_msg", ({
                "幽雾说道: 传说中的龙皮甲是当年蚩尤座下神龙之护身法宝，真想见识见识。\n",
                "幽雾叹道: 父王把龙皮甲和神龙法身放在龙冢里，怎么才能进去看到呢？\n",
        }) );
          set("inquiry", ([
                "龙冢" : "那是我龙宫重地……唉！你去问父王吧。\n",
                "龙皮甲" : "那是是当年蚩尤座下神龙之护身法宝，据说可以极大幅度提升内力。\n",
        ]));


    create_family("东海龙宫", 2, "水族");
        setup();

        carry_object("/d/moon/obj/luoyi")->wear();
        carry_object("/d/sea/obj/yincha")->wield();
}

