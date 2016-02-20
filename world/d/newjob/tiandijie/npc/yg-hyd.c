//modified by daiyu
//2000-12-9 23:34

inherit __DIR__"yaoguai.c";

void set_skills()
{

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
        (: perform_action,"spear", "fengchan" :),
        (: perform_action,"spear", "lihuo" :),
        (: perform_action,"unarmed", "zhangxinlei" :),
        (: exert_function, "fire" :),
        (: exert_function, "recover" :),
        (: cast_spell, "niushi" :),
        (: cast_spell, "sanmei" :),
        }) );

}
