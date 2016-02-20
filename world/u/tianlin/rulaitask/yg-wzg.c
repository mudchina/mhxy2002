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
        set("title",HIG"挑衅如来"HIW"的"NOR+MAG"万寿山五庄观"NOR);
        set("nickname",HIR"仙童"NOR);
        set_skill("literate", 150);
        set_skill("hammer", guai_value+random(6));
        set_skill("sword", guai_value+random(6));
        set_skill("kaishan-chui", guai_value+random(6));
        set_skill("taiyi", guai_value+10+random(6));
        set_skill("wuxing-quan", guai_value+random(6));
        set_skill("zhenyuan-force", guai_value+random(6));
        set_skill("sanqing-jian", guai_value+random(6));
        set_skill("baguazhen", guai_value+random(6));
        map_skill("spells", "taiyi");
        map_skill("unarmed", "wuxing-quan");
        map_skill("force", "zhenyuan-force");
        map_skill("sword", "sanqing-jian");
        map_skill("parry", "sanqing-jian");
        map_skill("dodge", "baguazhen");
        map_skill("hammer", "kaishan-chui");
        set("force_factor", query_skill("force")/2);
        set("mana_factor", query_skill("spells",1));
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
        (: cast_spell, "hufa" :),
        (: cast_spell, "zhenhuo" :),
        (: cast_spell, "baxian" :),
        }) );
                
        carry_object("/d/obj/armor/jinjia.c")->wear();
        carry_object("/d/obj/weapon/sword/qingfeng.c")->wield();
}


