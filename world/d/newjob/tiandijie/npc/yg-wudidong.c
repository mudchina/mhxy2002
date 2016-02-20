// bula and mon@xyj

inherit __DIR__"yaoguai.c";

// here should be this NPC specific skills.

void set_skills()
{

        set("chat_chance_combat",60);
        set("chat_msg_combat", ({
        (: perform_action,"blade", "diyu" :),
        (: perform_action,"sword", "zxzx" :),
        (: cast_spell, "bite" :),
        (: cast_spell, "suliao" :),
        (: exert_function, "recover" :),
        (: exert_function, "zhangqi" :),
        }) );

}
