// nick.c
// by tianlin 2001/5/1
#include <ansi.h>

inherit F_CLEAN_UP;
string replace_color(string,int);
int help(object);
int wiz_set(string,string,string,int);

int main(object me, string arg)
{
	string dest;
	if( !arg ) return notify_fail("ÄãÒªÌæ×Ô¼ºÈ¡Ê²Ã´´ÂºÅ£¿\n");
	if(sscanf(arg,"-title %s,%s",dest,arg)==2)
	{
		if(!wizardp(me))
			return notify_fail("Õâ¸ö¹¦ÄÜÖ»ÄÜÓÉÎ×Ê¦Ê¹ÓÃ¡£\n");
		if(wiz_level(me)<wiz_level("(hufa)")&&(dest!="me"&&dest!=me->query("id")))
			return notify_fail("ÄãµÄÈ¨ÏŞ²»¹»½øĞĞÕâ¸ö²Ù×÷¡£\n");
		return wiz_set(dest,arg,"title",1)?1:notify_fail("ÃüÁîÊ§°Ü¡£\n");
	}
	if(sscanf(arg,"-name %s,%s",dest,arg)==2)
	{
		if(!wizardp(me))
			return notify_fail("Õâ¸ö¹¦ÄÜÖ»ÄÜÓÉÎ×Ê¦Ê¹ÓÃ¡£\n");
		if(wiz_level(me)<wiz_level("(hufa)")&&(dest!="me"&&dest!=me->query("id")))
			return notify_fail("ÄãµÄÈ¨ÏŞ²»¹»½øĞĞÕâ¸ö²Ù×÷¡£\n");
		return wiz_set(dest,arg,"name",0)?1:notify_fail("ÃüÁîÊ§°Ü¡£\n");
	}
	if(sscanf(arg,"-id %s,%s",dest,arg)==2)
	{
		if(wiz_level(me)<wiz_level("(admin)"))
			return notify_fail("Õâ¸ö²Ù×÷Ö»ÄÜÓÉÌìÉñÖ´ĞĞ¡£\n");
		return wiz_set(dest,arg,"id",0)?1:notify_fail("ÃüÁîÊ§°Ü¡£\n");
	} 
	if(sscanf(arg,"-nick %*s")==1)
		sscanf(arg,"-nick %s",arg);
	if(sscanf(arg,"%s,%s",dest,arg)==2)
	{
		if(wiz_level(me)<wiz_level("(apprentice)"))
			return notify_fail("Õâ¸ö²Ù×÷Ö»ÄÜÓÉĞ¡Î×ÒÔÉÏ¼¶±ğµÄÎ×Ê¦Ö´ĞĞ¡£\n");
		return wiz_set(dest,arg,"nickname",1)?1:notify_fail("ÃüÁîÊ§°Ü¡£\n");
	}
	if( strlen(replace_color(arg,0)) > 40 )
		return notify_fail("´ÂºÅÌ«³¤ÁË£¬ÇëÄãÏëÒ»¸ö¶ÌÒ»µãµÄ¡¢ÏìÁÁÒ»µãµÄ¡£\n");
	return wiz_set("me",arg,"nickname",1)?1:notify_fail("ÃüÁîÊ§°Ü¡£\n");
	write("Ok.\n");
	return 1;
}
int wiz_set(string str1,string str2,string prop,int color_flag)
{
	object ob,me;
	me=this_player(1);
	if(str1=="me")
		ob=this_player(1);
	else
		if(!objectp(ob=present(str1,environment(me))))
			if(!objectp(ob=find_player(str1)))
				if(!objectp(ob=find_living(str1)))
				{
					tell_object(me,"²»ÄÜ·¢ÏÖ²Ù×÷¶ÔÏó("+str1+")£¡\n");
					return 0;
				}
	if(wiz_level(me)<wiz_level(ob))
	{
		tell_object(me,"ÄãµÄÈ¨ÏŞ²»¹»£¡\n");
		return 0;
	}
	if((prop=="title"&&wizardp(me))||prop=="nickname")
		if(str2=="none")
		{
			ob->delete(prop);
			message_vision("$NµÄ"+prop+"±»Çå³ıÁË¡£\n",ob);
			return 1;
		}
	str2=replace_color(str2,color_flag);
	message_vision("$NµÄ"+prop+"±»Éè¶¨Îª:"+str2+"\n",ob);
	ob->set(prop,str2);
	return 1;
}
// by tianlin 2001/5/13¼ÓÈëÍ¸Ã÷É«
string replace_color(string arg,int flag)
{
	arg = replace_string(arg, "$BLK$", flag?BLK:"");
	arg = replace_string(arg, "$RED$", flag?RED:"");
	arg = replace_string(arg, "$GRN$", flag?GRN:"");
	arg = replace_string(arg, "$YEL$", flag?YEL:"");
	arg = replace_string(arg, "$BLU$", flag?BLU:"");
	arg = replace_string(arg, "$MAG$", flag?MAG:"");
	arg = replace_string(arg, "$CYN$", flag?CYN:"");
	arg = replace_string(arg, "$WHT$", flag?WHT:"");
	arg = replace_string(arg, "$HIR$", flag?HIR:"");
	arg = replace_string(arg, "$HIG$", flag?HIG:"");
	arg = replace_string(arg, "$HIY$", flag?HIY:"");
	arg = replace_string(arg, "$HIB$", flag?HIB:"");
	arg = replace_string(arg, "$HIM$", flag?HIM:"");
	arg = replace_string(arg, "$HIC$", flag?HIC:"");
	arg = replace_string(arg, "$HIW$", flag?HIW:"");
	arg = replace_string(arg, "$NOR$", flag?NOR:"");
	arg = replace_string(arg, "$BLINK$", flag?BLINK:"");
	arg = replace_string(arg, "$BRED$", flag?BRED:"");
	arg = replace_string(arg, "$BGRN$", flag?BGRN:"");
	arg = replace_string(arg, "$BYEL$", flag?BYEL:"");
	arg = replace_string(arg, "$BBLU$", flag?BBLU:"");
	arg = replace_string(arg, "$BMAG$", flag?BMAG:"");
	arg = replace_string(arg, "$BCYN$", flag?BCYN:"");
	arg = replace_string(arg, "$HBWHT$", flag?HBWHT:"");

	if(flag) arg+=NOR;
	return arg;
}

int help(object me)
{
        write(@HELP
Ö¸Áî¸ñÊ½ : 
nick <´ÂºÅ> (ÊÊÓÃÓÚÆÕÍ¨Íæ¼Ò)
nick -title <id>,<×Ö´®>	¸øidÎª<id>µÄÍæ¼Ò¡¢NPC»òOBJECTÉè¶¨titleÊôĞÔ (ÊÊÓÃÓÚwiz)
nick -name  <id>,<×Ö´®>	¸øidÎª<id>µÄÍæ¼Ò¡¢NPC»òOBJECTÉè¶¨nameÊôĞÔ (ÊÊÓÃÓÚwiz)
nick -id    <id>,<×Ö´®>	¸øidÎª<id>µÄÍæ¼Ò¡¢NPC»òOBJECTÉè¶¨idÊôĞÔ (ÊÊÓÃÓÚwiz)
nick <id>,<´ÂºÅ>,	¸øidÎª<id>µÄÍæ¼Ò¡¢NPC»òOBJECTÉè¶¨idÊôĞÔ (ÊÊÓÃÓÚwiz)
ÈÎºÎÒ»¸öÃüÁî¶¼²»ÄÜ¶Ô¸ü¸ß¼¶±ğµÄÎ×Ê¦½øĞĞĞŞ¸Ä¡£
Èç¹ûÄãÏ£ÍûÊ¹ÓÃ ANSI µÄ¿ØÖÆ×ÖÔª¸Ä±äÑÕÉ«£¬¿ÉÒÔÓÃÒÔÏÂµÄ¿ØÖÆ×Ö´®£º

HELP +
"$BLK$ - "BLK"ºÚÉ«"NOR"		$NOR$ - »Ö¸´Õı³£ÑÕÉ«\n"+
"$RED$ - "RED"ºìÉ«"NOR"		$HIR$ - "HIR"ÁÁºìÉ«"NOR"\n"+
"$GRN$ - "GRN"ÂÌÉ«"NOR"		$HIG$ - "HIG"ÁÁÂÌÉ«"NOR"\n"+
"$YEL$ - "YEL"ÍÁ»ÆÉ«"NOR"		$HIY$ - "HIY"»ÆÉ«"NOR"\n"+
"$BLU$ - "BLU"ÉîÀ¶É«"NOR"		$HIB$ - "HIB"À¶É«"NOR"\n"+
"$MAG$ - "MAG"Ç³×ÏÉ«"NOR"		$HIM$ - "HIM"·ÛºìÉ«"NOR"\n"+
"$CYN$ - "CYN"À¶ÂÌÉ«"NOR"		$HIC$ - "HIC"ÌìÇàÉ«"NOR"\n"+
"$WHT$ - "WHT"Ç³»ÒÉ«"NOR"		$HIW$ - "HIW"°×É«"NOR"\n"+
@HELP
 
ÆäÖĞÏµÍ³×Ô¶¯»áÔÚ×Ö´®Î²¶Ë¼ÓÒ»¸ö $NOR$¡£ÌáÊ¾$BLINK$ÊÇÈÃ×Ö·ûÉÁÔ¾.
nick noneÖ¸ÁîÊÇÈ¡ÏûÍ·ÏÎ[1;33mÄ¿Ç°¼ÓÈëÍ¸Ã÷É«¼Ó·¨ÈçÏÂ:
ÔÚÇ³É«µÄÇ°Ãæ¼ÓÉÏÒ»¸öB×Ö¾ÍĞĞÁË,Àı:$BYEL$ µÈµÈ.......µ«,³ı°×É«ÒÔÍâ°×É«ÇëÓÃHBWHT[2;37;0m

HELP
        );
        return 1;
}
