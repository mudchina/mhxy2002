// bula and mon@xyj

inherit __DIR__"yaoguai.c";

// here should be this NPC specific skills.

void set_skills()
{

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
        (: perform_action,"unarmed", "flower" :),
        (: perform_action,"sword", "huifeng" :),
        (: cast_spell, "arrow" :),
        (: cast_spell, "shiyue" :),
        (: cast_spell, "mihun" :),
        (: exert_function, "recover" :),
        }) );

}
