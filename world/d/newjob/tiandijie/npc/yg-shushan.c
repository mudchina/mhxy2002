// bula and mon@xyj

inherit __DIR__"yaoguai.c";

// here should be this NPC specific skills.

void set_skills()
{

        set("chat_chance_combat",60);
        set("chat_msg_combat", ({
        (: perform_action,"sword", "jinsheng" :),
        (: perform_action,"sword", "fumo" :),
        (: perform_action,"sword", "duanshui" :),
        (: perform_action,"sword", "xiangsi" :),
        (: perform_action,"sword", "fengguang" :),
        (: perform_action,"sword", "wanjian" :),
        (: perform_action,"unarmed", "feilong" :),
        (: cast_spell, "fu" :),
        (: cast_spell, "jiushen" :),
        (: cast_spell, "jianshen" :),
        (: exert_function, "ningshen" :),
        (: exert_function, "huti" :),
        (: exert_function, "recover" :),
       }) );

}