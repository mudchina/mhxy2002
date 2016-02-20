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
        set("title",HIG"ÌôÐÆÈçÀ´"HIW"µÄ"HIB"Òõ²ÜµØ¸®"NOR);
        set("nickname",HIM"ÓÄÚ¤¶ñ¹í"NOR);
        set_skill("literate", 150);
        set_skill("whip", guai_value+random(6));
        set_skill("stick", guai_value+random(6));
        set_skill("hellfire-whip", guai_value+random(6));
        set_skill("gouhunshu", guai_value+10+random(6));
        set_skill("jinghun-zhang", guai_value+random(6));
        set_skill("tonsillit", guai_value+random(6));
        set_skill("kusang-bang", guai_value+random(6));
        set_skill("ghost-steps", guai_value+random(6));
        map_skill("spells", "gouhunshu");
        map_skill("unarmed", "jinghun-zhang");
        map_skill("force", "tonsillit");
        map_skill("whip", "hellfire-whip");
        map_skill("parry", "hellfire-whip");
        map_skill("dodge", "ghost-steps");
        map_skill("stick", "kusang-bang");
        set("force_factor", query_skill("force")/2);
        set("mana_factor", query_skill("spells",1));
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
        (: perform_action,"whip", "three" :),
        (: cast_spell, "gouhun" :),
        (: exert_function, "sheqi" :),
        }) );
                
        carry_object("/d/obj/armor/jinjia.c")->wear();
        carry_object("/d/obj/weapon/whip/tielian.c")->wield();
}



