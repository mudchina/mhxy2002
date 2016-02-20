//modified by stey
//2000-12-9 23:34

inherit __DIR__"yaoguai.c";

void set_skills()
{

        set("chat_chance_combat", 60);
         set("chat_msg_combat", ({
        (: perform_action,"sword", "quewu" :),
        (: cast_spell, "freeze" :),
        (: cast_spell, "sword" :),    
        (: cast_spell, "wanlei" :),
        (: exert_function, "hanxing" :),
        (: exert_function, "recover" :),
        }) );
}
