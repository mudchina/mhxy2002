// jiangli.c
// ½±Àø·¢ÏÖbugµÄÍæ¼Ò
// By tianlin 2001.5.1

inherit F_CLEAN_UP;
#include <ansi.h>

int main(object me,string arg)
{
	string id,reason,present;
	object player,gold;
	int i;
	
	if( !arg || arg=="" || sscanf(arg, "%s for %s", id, reason)!=2)
		return notify_fail("Ö¸Áî¸ñÊ½£ºjiangli <Íæ¼Òid> for <¼òÒª½éÉÜbug>\n");

	player = find_player(id);
	if (!player) return notify_fail("Ã»ÓĞÕâ¸öÈË\n");
	if (wizardp(player)) return notify_fail("²»ÄÜ½±ÀøÎ×Ê¦\n");
	i=random(3);
	switch (i)
	{
		case 0:
			player->add("combat_exp", 40000);
			present="ÊµÕ½¾­Ñé ËÄÍò";
			break;
		case 1:
			player->add("potential",20000);
			present="Ç±ÄÜ Á½Íò";
			break;
		case 2:
			player->add("daoxing",30000);
			present="µÀĞĞ ÈıÊ®Äê";
			break;
	}
	tell_object(player,HBRED""+me->query("name")+"½±Àø¸øÄã"+present+"£¡\n"NOR);
	write(HBRED"Äã½±Àø"+player->query("name")+present+"£¡\n"NOR);
		message("channel:rumor",HIM"¡¾Ò¥ÑÔ¡¿Ä³ÈË£º"+"¾İËµ[2;37;0m[37m<Ä³ÈË>[1;35m·¢ÏÖÁËÓÎÏ·ÖĞµÄBUG,µÃµ½ÁËÓµÓĞµÄ½±Àø¡£\n"NOR,users());//this is by tianlin

	log_file("jiangli",
		sprintf("%s(%s) ½±Àø %s(%s) %s ÒòÎª %s  on %s\n",
		me->name(1),
		geteuid(me),
		player->name(1),
		geteuid(player),
		present,
		reason,
		ctime(time()) ));
		
	
	return 1;
}

int help(object me)
{
	write(@HELP
Ö¸Áî¸ñÊ½ : jiangli <Íæ¼Òid> for <¼òÒª½éÉÜbug>

±¾ÃüÁî¸øÓë·¢ÏÖĞ¡bug(³ÌĞò´íÎó--³ÌĞòÊ§Îó,ÇÒÃ»Ôì³É¾Ş´óËğÊ§µÄ)
µÄplayerÒÔ½±Àø.×¢ÒâÇëÉ÷ÓÃ±¾ÃüÁî,Èç¹ûbugÎÊÌâ²»Ã÷È·,¾­ÇëÊ¾ÌÖ
ÂÛÔÙ¾ö¶¨
Àı×Ó	jiangli tryid for ·¢ÏÖtree´íÎó
HELP	);
	return 1;
}