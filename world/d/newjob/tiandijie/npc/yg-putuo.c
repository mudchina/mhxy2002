// bula and mon@xyj

inherit __DIR__"yaoguai.c";

// here should be this NPC specific skills.
void set_skills()
{

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
        (: perform_action,"staff", "pudu" :),
        (: perform_action,"staff", "diyu" :),
        (: perform_action,"unarmed", "storm" :),
        (: exert_function, "recover" :),
        (: cast_spell, "jiangang" :),
        (: cast_spell, "lianhua" :),
        (: cast_spell, "bighammer" :),
        }) );
}
