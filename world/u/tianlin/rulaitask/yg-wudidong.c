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
        set("title",HIG"ÌôÐÆÈçÀ´"HIW"µÄ"HIB"ÏÝ¿ÕÉ½ÎÞµ×¶´"NOR);
        set("nickname",HIR"ÑýÏÉ"NOR);
        set_skill("literate", 150);
        set_skill("blade", guai_value+random(6));
        set_skill("sword", guai_value+random(6));
        set_skill("kugu-blade", guai_value+random(6));
        set_skill("yaofa", guai_value+10+random(6));
        set_skill("yinfeng-zhua", guai_value+random(6));
        set_skill("huntian-qigong", guai_value+random(6));
        set_skill("qixiu-jian", guai_value+random(6));
        set_skill("lingfu-steps", guai_value+random(6));
        map_skill("spells", "yaofa");
        map_skill("unarmed", "yinfeng-zhua");
        map_skill("force", "huntian-qigong");
        map_skill("blade", "kugu-blade");
        map_skill("parry", "kugu-blade");
        map_skill("dodge", "lingfu-steps");
        map_skill("sword", "qixiu-jian");
        set("force_factor", query_skill("force")/2);
        set("mana_factor", query_skill("spells",1));
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
        (: cast_spell, "huanying" :),
        (: cast_spell, "suliao" :),
        }) );
                
        carry_object("/d/obj/armor/jinjia.c")->wear();
        carry_object("/d/obj/weapon/blade/jindao.c")->wield();
}


