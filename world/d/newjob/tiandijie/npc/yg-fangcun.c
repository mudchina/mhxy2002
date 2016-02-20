// bula and mon@xyj

inherit __DIR__"yaoguai.c";

// here should be this NPC specific skills.

void set_skills()
{

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
        (: perform_action,"stick", "pili" :),
        (: perform_action,"stick","qiankun" :),
        (: cast_spell, "thunder" :),
        (: cast_spell, "light" :),
        (: cast_spell, "dingshen" :),
        (: exert_function, "recover" :),
        (: exert_function, "jldl" :),
        }) );

}
