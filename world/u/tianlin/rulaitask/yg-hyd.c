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
        set("title",HIG"ÌôÐÆÈçÀ´"HIW"µÄ"NOR+RED"¿ÝËÉ½§»ðÔÆ¶´"NOR);
        set("nickname",HIY"³¤ÀÏ"NOR);
        set_skill("literate", 150);
        set_skill("spear", guai_value+random(6));
        set_skill("stick", guai_value+random(6));
        set_skill("huoyun-qiang", guai_value+random(6));
        set_skill("pingtian-dafa", guai_value+10+random(6));
        set_skill("moyun-shou", guai_value+random(6));
        set_skill("huomoforce", guai_value+random(6));
        set_skill("dali-bang", guai_value+random(6));
        set_skill("moshenbu", guai_value+random(6));
        map_skill("spells", "pingtian-dafa");
        map_skill("unarmed", "moyun-shou");
        map_skill("force", "huomoforce");
        map_skill("stick", "dali-bang");
        map_skill("parry", "dali-bang");
        map_skill("dodge", "moshenbu");
        map_skill("spear", "huoyun-qiang");
        set("force_factor", query_skill("force")/2);
        set("mana_factor", query_skill("spells",1));
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
        (: cast_spell, "sanmei" :),
        }) );
                
        carry_object("/d/obj/armor/jinjia.c")->wear();
        carry_object("/d/sea/obj/dragonstick.c")->wield();
}



