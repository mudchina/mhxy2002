// bula and mon@xyj

inherit __DIR__"yaoguai.c";

// here should be this NPC specific skills.

void set_skills()
{

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
        (: perform_action,"sword", "staff" :),
        (: perform_action,"sword", "zouxiao" :),
        (: cast_spell, "zhenhuo" :),
        (: exert_function, "recover" :),
        }) );
}
