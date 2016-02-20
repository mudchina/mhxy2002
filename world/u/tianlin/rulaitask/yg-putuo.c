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
        set("title",HIG"挑衅如来"HIW"的"HBBLU+HIY"佛家弟子"NOR);
        set("nickname",HIY"大师"NOR);
        set_skill("literate", 150);
        set_skill("staff", guai_value+random(6));
        set_skill("sword", guai_value+random(6));
        set_skill("liangyi-sword", guai_value+random(6));
        set_skill("buddhism", guai_value+10+random(6));
        set_skill("jienan-zhi", guai_value+random(6));
        set_skill("lotusforce", guai_value+random(6));
        set_skill("lunhui-zhang", guai_value+random(6));
        set_skill("blade", guai_value+random(6));
        set_skill("cibei-dao", guai_value+random(6));
        set_skill("lotusmove", guai_value+random(6));
        map_skill("spells", "buddhism");
        map_skill("unarmed", "jienan-zhi");
        map_skill("force", "lotusforce");
        map_skill("staff", "lunhui-zhang");
        map_skill("parry", "lunhui-zhang");
        map_skill("dodge", "lotusmove");
        map_skill("blade", "cibei-dao");
        set("force_factor", query_skill("force")/2);
        set("mana_factor", query_skill("spells",1));
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: cast_spell, "bighammer" :),
                (: cast_spell, "hufa" :),
        }) );
                
        carry_object("/d/obj/armor/jinjia.c")->wear();
        carry_object("/d/obj/weapon/staff/budd_staff.c")->wield();
}


