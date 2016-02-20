// call.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string objname, func, param, euid;
        object obj;
        mixed *args, result;
        mixed result2, result3;
        int i;

        if( arg ) {
                if( sscanf(arg, "-%s %s", euid, arg)==2 ) {
                        if( (string)SECURITY_D->get_status(me) != "(admin)" )
                                return notify_fail("你不能设定自己的 euid。\n");
                        seteuid(euid);
                }
                else
                        seteuid( geteuid(this_player(1)) );

                if( sscanf(arg, "%s %s", objname, param)!=2 )
                        return notify_fail("指令格式：wizcheck <物件> (query(<参数>)\n");
        } else
                return notify_fail("指令格式：wizcheck <物件> (query(<参数>)\n");

        obj = present(objname, environment(me));
        if(!obj) obj = present(objname, me);
        if(!obj) obj = find_player(objname);
        if(!obj || !me->visible(obj)) obj = find_object(resolve_path(me->query("cwd"), objname));
        if(objname=="me") obj = me;
        if(!obj) return notify_fail("找不到指定的物件。\n");

        if(wizardp(obj) && wiz_level(me) < wiz_level(obj))
           return notify_fail("你不能设定等级比你高的巫师状态。\n");

        

        result = call_other(obj, "query",param);
        result2 = call_other(obj, "query_temp",param);
        result3 = call_other(obj, "query_"+param);
        tell_object(me, sprintf("%O->query(%s) = %O\n", obj, param
                , result));
        tell_object(me, sprintf("%O->query_temp(%s) = %O\n", obj, param, result2));
        tell_object(me, sprintf("%O->query_%s() = %O\n", obj, param, result3));
        return 1;
}

int help(object me)
{
write(@HELP
 
HELP
    );
    return 1;
}

