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
        set("title",HIG"挑衅如来"HIW"的"HBRED+HIW"西域雪山"HIY"妖王"NOR);
        set("nickname",HIW"天魔解体"NOR);
        set_skill("literate", 150);
        set_skill("blade", guai_value+random(6));
        set_skill("sword", guai_value+random(6));
        set_skill("bingpo-blade", guai_value+random(6));
        set_skill("dengxian-dafa", guai_value+10+random(6));
        set_skill("cuixin-zhang", guai_value+random(6));
        set_skill("ningxie-force", guai_value+random(6));
        set_skill("bainiao-jian", guai_value+random(6));
        set_skill("throwing", guai_value+random(6));
        set_skill("unarmed", guai_value+random(6));
        set_skill("xiaoyaoyou", guai_value+random(6));
        map_skill("spells", "dengxian-dafa");
        map_skill("unarmed", "cuixin-zhang");
        map_skill("force", "ningxie-force");
        map_skill("sword", "bainiao-jian");
        map_skill("parry", "bainiao-jian");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("blade", "bingpo-blade");
        set("force_factor", query_skill("force")/2);
        set("mana_factor", query_skill("spells",1));
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: cast_spell, "escape" :),
                (: cast_spell, "hufa" :),
        }) );
                
        carry_object("/d/obj/armor/jinjia.c")->wear();
        carry_object("/d/obj/weapon/blade/iceblade.c")->wield();
}


