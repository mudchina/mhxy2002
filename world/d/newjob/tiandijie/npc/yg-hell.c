// bula and mon@xyj

inherit __DIR__"yaoguai.c";

// here should be this NPC specific skills.

void set_skills()
{

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
        (: perform_action,"unarmed", "zhua" :),
        (: perform_action,"whip", "lunhui" :),
        (: perform_action,"whip", "biluo" :),
        (: cast_spell, "gouhun" :),
        (: cast_spell, "inferno" :),
        (: cast_spell, "curse" :),
        (: exert_function, "recover" :),
        (: exert_function, "sheqi" :),
        }) );

}
