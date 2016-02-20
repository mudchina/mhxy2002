// bula and mon@xyj

inherit __DIR__"yaoguai.c";

void set_skills()
{
        set("chat_chance_combat",60);
        set("chat_msg_combat", ({
        (: cast_spell, "freez" :),
        (: cast_spell, "dragonfire" :),
        (: cast_spell, "water" :),
        (: perform_action,"unarmed", "leidong" :),
        (: perform_action,"hammer", "break" :),
        (: exert_function, "roar" :),
        (: exert_function, "recover" :),
        }) );
}
