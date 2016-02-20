/*// weishi.h 升级到卫士, 拜师
int ask_me()
{
        string oldtitle;
        object ob, me;
        me = this_object();
        ob = this_player();
        if ((int)ob->query_skill("kurong-changong",1) < 60)
        {
                command("say 你想当卫士，再练几年功吧。\n");
                return 1;
        }
        oldtitle = ob->query("title");
        if (strsrch(oldtitle, "大理镇南王府家臣") >= 0)
        {
                ob->set_temp("fight_ok",1);
                command("say 好，既然如此想切磋，那就看你的本事如何了。\n");
                return 1;
        }
        else
        {
                command("say 只有家臣才能升卫士。\n");
                return 1;
        }
}

int accept_fight(object ob)
{
        object me  = this_object();
        if ( !ob->query_temp("fight_ok") ) return 0;

        remove_call_out("checking");
        call_out("checking", 1, me, ob);
        ob->delete_temp("fight_ok");
        return 1;
}

int checking(object me, object ob)
{
        object obj;
        int my_max_qi, his_max_qi;

        my_max_qi  = me->query("max_qi");
        his_max_qi = ob->query("max_qi");

        if (me->is_fighting()) 
        {
                call_out("checking",2, me, ob);
                return 1;
        }

        if ( !present(ob, environment()) ) return 1; 

        if (( (int)me->query("qi")*100 / my_max_qi) <= 50 ) 
        {
                command("say 青出於蓝胜於蓝，不愧是大理段家的好弟子 ! 恭喜你了 !\n");
                command("say 你的已经可以胜任大理卫士 !\n");
                upgrade_title(ob, "大理镇南王府卫士");
                return 1;
        }
        if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ) 
        {
                command("say 看来" + RANK_D->query_respect(ob) + 
                        "还得多加练习，方能在大理段家诸多弟子中出人头地 !\n");
                return 1;
        }
        return 1;  
}
void upgrade_title(object ob,string arg)
{
        string title;
        title=arg+clear_title(ob->query("title"));
        ob->set("title",title);
}
string clear_title(string arg)
{
        if (strsrch(arg, "大理镇南王府家臣") >= 0)
        {
                arg = replace_string(arg, "大理镇南王府家臣","");
        }
        return arg;
}
*/
void attempt_apprentice(object ob)
{
        if ((int)ob->query_int() < 25  )
        {
                command("say 你的条件似乎不够！");
                return;
        }
        if ((int)ob->query("combat_exp") > 500000 || (int)ob->query("age") >20 )
        {
                command("say 我怎么敢收您为徒弟呢！");
                return;
        }
        command("say 很好，很好。我水帘洞光复之日不久远矣！\n");
        command("recruit " + ob->query("id"));
                ob->set("title","水帘洞巡洞妖猴");
}
