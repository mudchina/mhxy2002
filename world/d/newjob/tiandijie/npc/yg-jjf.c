// bula and mon@xyj

inherit __DIR__"yaoguai.c";

// here should be this NPC specific skills.

void set_skills()
{
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
        (: perform_action,"axe", "sanban" :),
        (: perform_action,"spear", "qiangjian" :),
        (: perform_action,"unarmed", "zhiqi" :),
//        (: cast_spell, "gouhun" :),
        (: exert_function, "jingxin" :),
        (: exert_function, "recover" :),
        }) );

}
