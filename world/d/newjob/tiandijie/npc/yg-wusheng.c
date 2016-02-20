//modified by stey
//2000-12-9 23:34

inherit __DIR__"yaoguai.c";

void set_skills()
{

        set("chat_chance_combat", 60);
         set("chat_msg_combat", ({
        (: perform_action,"unarmed", "wanfo" :), 
        (: perform_action,"sword", "fenge" :),
        (: perform_action,"sword", "juechen" :),
        (: cast_spell, "feixian" :),
        (: cast_spell, "wanying" :),    
        (: exert_function, "huti" :),
        (: exert_function, "qiankun" :),
        }) );
}
