// ip.c by happ

inherit F_CLEAN_UP;

int main(object me,string arg)
{

        string from;
        if( ! arg ) return notify_fail("请输入一个ip地址\n");

        from="/adm/daemons/ipd"->seek_ip_address(arg);
        tell_object(me,"你输入的" +arg+ "来自 "+from+" \n");
        return 1;
}
