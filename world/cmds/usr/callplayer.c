// callplayer.c

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string file;
	file ="/log/static/CALL_PLAYER";
	seteuid(geteuid(me));
	write("CALL_PLAYER记档案里有以下记录。\n");
	write("-------------------------------------------------------------------------------------------\n");
	cat(file);
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : callplayer
 
显示CALL_PLAYER档案内容。
是为了增加本MUD的公平性。
让大家来监督巫师。

XYX.98.6.17

HELP
    );
    return 1;
}
