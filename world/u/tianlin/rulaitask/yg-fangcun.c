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
        set("title",HIG"挑衅如来"HIW"的"HIM"斜月三星洞"NOR);
        set("nickname",HIY"健将"NOR);
        set_skill("literate", 150);
        set_skill("stick", guai_value+random(6));
        set_skill("sword", guai_value+random(6));
        set_skill("liangyi-sword", guai_value+random(6));
        set_skill("dao", guai_value+10+random(6));
        set_skill("puti-zhi", guai_value+random(6));
        set_skill("wuxiangforce", guai_value+random(6));
        set_skill("qianjun-bang", guai_value+random(6));
        set_skill("jindouyun", guai_value+random(6));
        map_skill("spells", "dao");
        map_skill("unarmed", "puti-zhi");
        map_skill("force", "wuxiangforce");
        map_skill("stick", "qianjun-bang");
        map_skill("parry", "qianjun-bang");
        map_skill("dodge", "jindouyun");
        map_skill("sword", "liangyi-sword");
        set("force_factor", query_skill("force")/2);
        set("mana_factor", query_skill("spells",1));
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "stick","qiankun" :),
                (: cast_spell, "hufa" :),
        }) );
                
        carry_object("/d/obj/armor/jinjia.c")->wear();
        carry_object("/d/sea/obj/dragonstick.c")->wield();
}

