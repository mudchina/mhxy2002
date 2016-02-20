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
        set("title",HIG"挑衅如来"HIW"的"HIC"万剑之尊蜀山"NOR);
        set("nickname",HIR"剑魔"NOR);
        set_skill("literate", 150);
        set_skill("yujianshu", guai_value+random(6));
        set_skill("sword", guai_value+random(6));
        set_skill("songhe-sword", guai_value+random(6));
        set_skill("xianfeng-spells", guai_value+10+random(6));
        set_skill("fumozhang", guai_value+random(6));
        set_skill("shushan-force", guai_value+random(6));
        set_skill("canxin-jian", guai_value+random(6));
        set_skill("zuixian-steps", guai_value+random(6));
        map_skill("spells", "xianfeng-spells");
        map_skill("unarmed", "fumozhang");
        map_skill("force", "shushan-force");
        map_skill("parry", "songhe-sword");
        map_skill("dodge", "zuixian-steps");
        map_skill("sword", "songhe-sword");
        set("force_factor", query_skill("force")/2);
        set("mana_factor", query_skill("spells",1));
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
        (: cast_spell, "jianshen" :),
        (: cast_spell, "fu" :),
        }) );
                
        carry_object("/d/obj/armor/jinjia.c")->wear();
        carry_object("/d/obj/weapon/sword/qingfeng.c")->wield();
}


