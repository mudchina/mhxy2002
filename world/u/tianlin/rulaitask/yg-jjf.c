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
        set("title",HIG"挑衅如来"HIW"的"HIR"大唐将军府"NOR);
        set("nickname",HIC"大将军"NOR);
        set_skill("literate", 150);
        set_skill("spear", guai_value+random(6));
        set_skill("axe", guai_value+random(6));
        set_skill("bawang-qiang", guai_value+random(6));
        set_skill("baguazhou", guai_value+10+random(6));
        set_skill("changquan", guai_value+random(6));
        set_skill("lengquan-force", guai_value+random(6));
        set_skill("sanban-axe", guai_value+random(6));
        set_skill("yanxing-steps", guai_value+random(6));
        map_skill("spells", "baguazhou");
        map_skill("unarmed", "changquan");
        map_skill("force", "lengquan-force");
        map_skill("axe", "sanban-axe");
        map_skill("parry", "sanban-axe");
        map_skill("dodge", "yanxing-steps");
        map_skill("spear", "bawang-qiang");
        set("force_factor", query_skill("force")/2);
        set("mana_factor", query_skill("spells",1));
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
        (: perform_action,"axe", "sanban" :),
        (: exert_function, "jingxin" :),
        }) );
                
        carry_object("/d/obj/armor/jinjia.c")->wear();
        carry_object("/d/moon/obj/bigaxe.c")->wield();
}


