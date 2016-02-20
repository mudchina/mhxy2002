// bula and mon@xyj

inherit __DIR__"yaoguai.c";

// here should be this NPC specific skills.

void set_skills()
{

        set("chat_chance_combat",60);
        set("chat_msg_combat", ({
        (: perform_action,"sword", "chaofeng" :),
        (: perform_action,"blade", "yaowu" :),
        (: cast_spell, "tuntian" :),
        (: cast_spell, "juanbi" :),
        (: exert_function, "recover" :),
        (: exert_function, "mohu" :),
       }) );

}
