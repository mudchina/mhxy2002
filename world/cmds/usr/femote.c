// COMMAND STD femote.c
// Last modified by zeus@DJX Oct.28.1999

#include "/doc/help.h"

int help(object me);

string do_search(object me,string name,string msg,string substr,string text)
{
        if(!msg)
                return 0;

        if(strsrch(msg,substr)!=-1)
        {
                msg = replace_string(msg, "$n", "(对方)");
                msg = replace_string(msg, "$N", me->name(1));
                msg = replace_string(msg, "$P", "你");
                msg = replace_string(msg, "$p", "(他/她)");
                msg = replace_string(msg, "$S", RANK_D->query_self(me));
                msg = replace_string(msg, "$s", RANK_D->query_self_rude(me));
                msg = replace_string(msg, "$R", "(对方的尊称)");
                msg = replace_string(msg, "$r", "(对方的辱称)");
                msg = replace_string(msg, "$C", "(自己的呢称)");
                msg = replace_string(msg, "$c", "(对方的呢称)");
                return sprintf("emote 名: %s %s\n%s\n",
                                        name,text,msg);
        }
        return 0;
}

int main(object me, string arg)
{
        mapping emote;
        string *emotes, msg, str;
        int i,c;

        if( !arg || arg == "")
                return help(me);

        emotes = EMOTE_D->query_all_emote();

        msg = "查询结果\n";
        msg+= "------------------------------------------------------------\n";
        for(i=0;i<sizeof(emotes);i++)
        {
                emote = EMOTE_D->query_emote(emotes[i]);

                if(emote)
                {
                        str = do_search(me,emotes[i],emote["myself"],arg," [自己看到]");
                        if(str)
                                msg+=str;
                        str = do_search(me,emotes[i],emote["others"],arg," [其他人看到]");
                        if(str)
                                msg+=str;
                        str = do_search(me,emotes[i],emote["myself_self"],arg,"<自己> [自己看到]");
                        if(str)
                                msg+=str;
                        str = do_search(me,emotes[i],emote["others_self"],arg,"<自己> [其他人看到]");
                        if(str)
                                msg+=str;
                        str = do_search(me,emotes[i],emote["myself_target"],arg,"<他人> [自己看到]");
                        if(str)
                                msg+=str;
                        str = do_search(me,emotes[i],emote["target"],arg,"<他人> [对方己看到]");
                        if(str)
                                msg+=str;
                        str = do_search(me,emotes[i],emote["others_target"],arg,"<他人> [其他人看到]");
                        if(str)
                                msg+=str;
                }
        }
        msg+= "------------------------------------------------------------\n";
        me->start_more(msg);

    return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : femote <字符串>。

这个指令可以在所有 emote 中寻找含有所指定的字符串
的emote。

HELP
        );


return 1;
}

string short_help()
{
        return "寻找emote";
}

