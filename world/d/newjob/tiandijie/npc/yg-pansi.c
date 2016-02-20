//created by daiyu
//2000-12-9 23:35

inherit __DIR__"yaoguai.c";


void set_skills()
{
        set("chat_chance_combat",60);
        set("chat_msg_combat", ({
        (: perform_action,"sword", "haotan" :),
        (: perform_action,"unarmed", "juehu" :),
        (: cast_spell, "wuzhishan" :),
        (: cast_spell, "ziqi" :),
        (: exert_function, "recover" :),
        }) );        
}
