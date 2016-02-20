// ask.c
// From ES2
// Modified by Xiang for XKX (12/15/95)
//xkiller 2001.1.20 Ôö¼ÓÁË¼¸¸öÔ¤ÉèÖ÷ÌâµÄ»Ø´ğ (²Î¼û£º/adm/daemons/inquiryd.c) 
//×¢£ºÕâ¸öÏë·¨ÊÇÊÜÏÀ¿Í2000µÄÆô·¢£¬²»¹ı²»ÊÇ¿´ËûÃÇµÄ£¬ºÇºÇ~~~~
#include <ansi.h>
string query_inquiry(object ob);
inherit F_CLEAN_UP;

string *msg_dunno = ({
	"$nÒ¡Ò¡Í·£¬ËµµÀ£ºÃ»ÌıËµ¹ı¡£\n",
	"$nÒÉ»óµØ¿´×Å$N£¬Ò¡ÁËÒ¡Í·¡£\n",
	"$nÕö´óÑÛ¾¦Íû×Å$N£¬ÏÔÈ»²»ÖªµÀ$PÔÚËµÊ²Ã´¡£\n",
	"$nËÊÁËËÊ¼ç£¬ºÜ±§Ç¸µØËµ£ºÎŞ¿É·î¸æ¡£\n",
	"$nËµµÀ£ºàÅ£®£®£®ÕâÎÒ¿É²»Çå³ş£¬Äã×îºÃÎÊÎÊ±ğÈË°É¡£\n",
	"$nÏëÁËÒ»»á¶ù£¬ËµµÀ£º¶Ô²»Æğ£¬ÄãÎÊµÄÊÂÎÒÊµÔÚÃ»ÓĞÓ¡Ïó¡£\n"
});

int main(object me, string arg)
{
	string dest, topic, msg;
	object ob;
	mapping inquiry;

	seteuid(getuid());

	if( !arg || sscanf(arg, "%s about %s", dest, topic)!=2 )
		return notify_fail("ÄãÒªÎÊË­Ê²Ã´ÊÂ£¿\n");

	if( !objectp(ob = present(dest, environment(me))) )
		return notify_fail("ÕâÀïÃ»ÓĞÕâ¸öÈË¡£\n");

	if( !ob->is_character() ) {
		message_vision("$N¶Ô×Å$n×ÔÑÔ×ÔÓï£®£®£®\n", me, ob);
		return 1;
	}

	if( !ob->query("can_speak") ) {
		message_vision("$NÏò$n´òÌıÓĞ¹Ø¡º" + topic 
			+ "¡»µÄÏûÏ¢£¬µ«ÊÇ$pÏÔÈ»Ìı²»¶®ÈË»°¡£\n", me, ob);
		return 1;
	}

	if( !INQUIRY_D->parse_inquiry(me, ob, topic) )
		message_vision("$NÏò$n´òÌıÓĞ¹Ø¡º" + topic + "¡»µÄÏûÏ¢¡£\n", me, ob);

	if( userp(ob) ) return 1;
	if( !living(ob) ) {
		message_vision("[1;37mµ«ÊÇºÜÏÔÈ»µÄ£¬$nÏÖÔÚµÄ×´¿öÃ»ÓĞ°ì·¨¸ø$NÈÎºÎ´ğ¸²¡£[2;37;0m\n",
			me, ob);
		return 1;
	}

	// by snowcat jan 23 1998
	  if ( msg = QUEST->quest_ask (me, ob, topic) ) {
		if( stringp(msg) ) {
			message_vision( CYN "$NËµµÀ£º" + msg + "\n" NOR, ob);
			return 1;
		}
	}

	if( msg = ob->query("inquiry/" + topic) ) {
		if( stringp(msg) ) {
			message_vision( CYN "$NËµµÀ£º" + msg + "\n" NOR, ob);
			return 1;
		}
	} else

	if(topic=="news")
		{
		string str;
		str=read_file("/log/NEWS");
		message_vision( CYN "$N¶ÔÄãµãÁËµãÍ·Ëµµ½,×î½üÌıÓĞÈËËµ¹ı"+str+"" NOR, ob);
		return 1;
	       }	
	if(topic=="all")
		{
		message_vision( CYN "$N¶ÔÄãÇÄÉùËµµÀ:"+query_inquiry(ob)+"!\n" NOR, ob);
		return 1;
		}
		message_vision(msg_dunno[random(sizeof(msg_dunno))], me, ob);

	return 1;
} 
      	
//´ÓnpcÉíÉÏ¶ÁÈ¡inquiry
string query_inquiry(object ob)
{
	int i=0;
	mapping inq;
	string str="", *indexs;
	
	if(mapp(inq=ob->query("inquiry")))
		{
		indexs=keys(inq);
		for(i=0;i<sizeof(indexs);i++)
			{
				str=indexs[i]+" "+str;
				}
		str="ÓĞ¹ØÓÚ "HIB+str+NOR CYN"µÄÊÂÇé,ÎÒºÜ¸ßĞË¸æËßÄã!";
		return str;
		}
	return "ÊµÔÚÊÇ¶Ô²»Æğ,ÎÒÊ²Ã´Ò²²»ÖªµÀÑ½!";
	}
int help(object me)
{
   write( @HELP
Ö¸Áî¸ñÊ½: ask <someone> about <something>

Õâ¸öÖ¸ÁîÔÚ½âÃÕÊ±ºÜÖØÒª, Í¨³£±ØĞë½åÓÉ´ËÒ»Ö¸Áî²ÅÄÜ
»ñµÃ½øÒ»²½µÄ×ÊÑ¶¡£
Ô¤ÉèµÄÑ¯ÎÊÖ÷Ìâ:
	here
	name
	news
	all
HELP
   );
   return 1;
}

