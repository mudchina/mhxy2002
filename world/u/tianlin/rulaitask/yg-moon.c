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
        set("title",HIG"挑衅如来"HIW"的"NOR+MAG"昆仑山月宫"NOR);
        set("nickname",HIM"魔女"NOR);
        set("gender", "女性");
        set_skill("literate", 150);
        set_skill("whip", guai_value+random(6));
        set_skill("sword", guai_value+random(6));
        set_skill("jueqingbian", guai_value+random(6));
        set_skill("moonshentong", guai_value+10+random(6));
        set_skill("baihua-zhang", guai_value+random(6));
        set_skill("moonforce", guai_value+random(6));
        set_skill("snowsword", guai_value+random(6));
        set_skill("moondance", guai_value+random(6));
        map_skill("spells", "moonshentong");
        map_skill("unarmed", "baihua-zhang");
        map_skill("force", "moonforce");
        map_skill("sword", "snowsword");
        map_skill("parry", "snowsword");
        map_skill("dodge", "moondance");
        map_skill("whip", "jueqingbian");
        set("force_factor", query_skill("force")/2);
        set("mana_factor", query_skill("spells",1));
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
        (: cast_spell, "arrow" :),
        }) );
                
        carry_object("/d/obj/armor/jinjia.c")->wear();
        carry_object("/d/obj/weapon/sword/qingfeng.c")->wield();
}



