//modified by stey
//2000-12-9 23:34

inherit __DIR__"yaoguai.c";

void set_skills()
{

        set("chat_chance_combat", 60);
         set("chat_msg_combat", ({
        (: perform_action,"blade", "tulong" :), 
        (: perform_action,"sword", "pili" :),
        (: cast_spell, "zhui" :),
        (: cast_spell, "sishi" :),        
        }) );
}
