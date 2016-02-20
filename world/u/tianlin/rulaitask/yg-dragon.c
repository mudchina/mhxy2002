//BY tianlin@mhxy for 2002.1.20
#include <ansi.h>
inherit __DIR__"yaoguai.c";

void set_skills(int max_value, int level)
{
        int guai_value;
        ::set_skills(max_value, level);
        
        if (level==1) guai_value = max_value+max_value/8;
        else if (level==2) guai_value = max_value+max_value/6;
        else guai_value = max_value+max_value/4;
        set("title",HIG"挑衅如来"HIW"的"HIC"东海龙宫"NOR);
        set("nickname",HIB"怪兽"NOR);
        set_skill("literate", 150);
        set_skill("fork", guai_value+random(6));
        set_skill("hammer", guai_value+random(6));
        set_skill("fengbo-cha", guai_value+random(6));
        set_skill("seashentong", guai_value+10+random(6));
        set_skill("dragonfight", guai_value+random(6));
        set_skill("dragonforce", guai_value+random(6));
        set_skill("huntian-hammer", guai_value+random(6));
        set_skill("dragonstep", guai_value+random(6));
        map_skill("spells", "seashentong");
        map_skill("unarmed", "dragonfight");
        map_skill("force", "dragonforce");
        map_skill("fork", "fengbo-cha");
        map_skill("parry", "fengbo-cha");
        map_skill("dodge", "dragonstep");
        map_skill("hammer", "huntian-hammer");
        set("force_factor", query_skill("force")/2);
        set("mana_factor", query_skill("spells",1));
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
        (: cast_spell, "freez" :),
        (: cast_spell, "breathe" :),
        (: exert_function, "roar" :),
        (: exert_function, "shield" :),
        }) );
                
        carry_object("/d/obj/armor/jinjia.c")->wear();
        carry_object("/d/obj/weapon/fork/gangcha.c")->wield();
}



