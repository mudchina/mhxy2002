
#include <login.h>;
inherit F_CLEAN_UP;
object make_body(object ob);
void create()
{
        seteuid(getuid());
}

int main(object me, string arg)
{
        object ob,link_ob,user;
        if(!arg)
                return notify_fail("用法:xokip ID\n");
        ob=find_player(arg);
        if(!ob)
        {
        ob = new(LOGIN_OB);
        ob->set("id",arg);
        if( !ob->restore() )
                return notify_fail("没有这个玩家。\n");
        else
                {
            if( objectp(user = make_body(ob)) ) 
     if( user->restore() )  {    
            reset_eval_cost();
            user->set_temp("link_ob", ob);
        ob->set_temp("body_ob", user);
        user->set_encoding(ob->query_encoding());       
           user->delete("ok_ip");
           tell_object(me, "玩家" + ob->query("id") + "("+ob->query("name")
                + ")的okip已经删除\n");
         log_file( "changepw.log", sprintf("%s %s(%s)删除了%s(%s)的okip\n",
                ctime(time()), me->query("name"), me->query("id"),
                ob->query("name"), ob->query("id")));
           ob->save();
           user->save();
           destruct(ob);
           destruct(user);
           return 1;
        }
        }
        }
        link_ob=ob;
        if(link_ob)
        {
                link_ob->delete("ok_ip");
                link_ob->save();
        tell_object(me, "玩家" + ob->query("id") + "("+ob->query("name")
                        + "的okip已经删除\n");
                return 1;
        }
        else
                return notify_fail("错误。无法进行修改。\n");
        return 1;
}

object make_body(object ob)
{
        string err;
        object user;
        int n;

        if(!ob->query("body")) {
          return 0;
        }
        user = new(ob->query("body"));
        if(!user) {
                write("现在可能有人正在修改玩家物件的程式，无法进行复制。\n");
                write(err+"\n");
                return 0;
        }
        seteuid(ob->query("id"));
        export_uid(user);
        export_uid(ob);
        seteuid(getuid());

        user->set("id", ob->query("id"));
        user->set_name( ob->query("name"), ({ ob->query("id")}) );
        return user;
}


int help(object me)
{
        write(@HELP
指令格式 : xokip ID

这个指令可以删除玩家的okip

HELP
    );
    return 1;
}

