// By tianlin 2001.5.1
// tell.c

#include <ansi.h>
#include <net/dns.h>
#include "/cmds/std/block_tell.h";

inherit F_CLEAN_UP;

#define DEBUG "xjh"||"hxl"
#ifdef DEBUG
void debug(string x)
{
    object monitor;
    if (!stringp(x) || !stringp(DEBUG))     return;
    monitor=find_player(DEBUG);
    if(monitor && monitor->query("env/debug"))     tell_object(monitor,x+"\n");
}
#else
#define debug(x)
#endif

object find_player(string target)
{
    int i;
    object *str;
    str=users();
    for (i=0;i<sizeof(str);i++)
        if (str[i]->query("id")==target){
              if (!environment(str[i])) return 0;
              else
            return str[i];
         }
    return 0;
}
int help(object me);
void add_id(object me, string id);

void create() {seteuid(getuid());}

int main(object me, string arg)
{
	string target, msg, mud;
	object obj;
	string *allow;

	if( !arg || sscanf(arg, "%s %s", target, msg)!=2 ) return help(me);

	if( sscanf(target, "%s@%s", target, mud)==2 ) {
		GTELL->send_gtell(mud, target, me, msg);
		write("ÍøÂ·Ñ¶Ï¢ÒÑËÍ³ö£¬¿ÉÄÜÒªÉÔºò²ÅÄÜµÃµ½»ØÓ¦¡£\n");
		
	        // mon 7/29/98
	        add_id(me, target+"@"+mud);

		return 1;
	}

        if(!block_tell(me)) return 1;

	obj = find_player(target);
	if(!obj || !me->visible(obj)) return notify_fail("Ã»ÓĞÕâ¸öÈË¡£\n");

	// mon 7/29/98
	// when a player set no_tell, if he once initiate to tell
	// others, then his target is allowed to use tell to tell him.

	allow=obj->query_temp("allow_tell");
	if(!allow || member_array(me->query("id"), allow)==-1)
	  if( !wizardp(me) && obj->query("env/block_tell") )
	    return notify_fail(obj->name(1) + "ÑÛÏÂ²»Ïë¸úÈÎºÎÈËËµ»°¡£\n");

        if(!living(obj) || !interactive(obj)) 
	  return notify_fail(HIW+obj->name(1)+"ÏÖÔÚµÄ×´Ì¬Ã»·¨¸øÄãÈÎºÎ´ğ¸´¡£\n"NOR);
	  
	write("[41m[1;33mÄã¸æËß" + obj->name(1) + "£º" + msg + "\n" NOR);
	if(obj->query("env/reply_msg")&&obj->query("msg_on")) write(YEL+obj->name(1)+"[2;37;0m¸ø[1;31mÄã[2;37;0mµÄ[36mÁôÑÔ[2;37;0mÊÇ:"HIG+obj->query("env/reply_msg")+"¡£\n"NOR);
	else {
		tell_object(obj, sprintf( HIG "[44m[1;36m%s¸æËßÄã£º%s\n" NOR,
		me->name(1)+"("+me->query("id")+")", msg));
	debug(sprintf( YEL "%s(%s)¸æËß%s(%s)£º%s" NOR,me->name(1),me->query("id"),obj->name(1),obj->query("id"), msg));
		if (interactive(obj)&&query_idle(obj)>120) write(YEL+"µ«ÊÇ"+obj->name(1)+"ÒÑ¾­·¢´ô"HIR+chinese_number(query_idle(obj)/60)+NOR YEL"·ÖÖÓ£¬¿´À´ÄãÊÇµÃ²»µ½ÈÎºÎ´ğ¸´ÁË£¡\n"+NOR);
	     }

	obj->set_temp("reply", me->query("id"));
	
	// mon 7/29/98
	add_id(me, target);
	return 1;
}

string remote_tell(string cname, string from, string mud, string to, string msg)
{
	object ob;
	string *allow;

	if( ob = find_player(to) ) {
	        if(wizardp(ob) && ob->query("env/invisibility"))
		  return "ÏÖÔÚÕÒ²»µ½Õâ¸öÈË¡£"; //respond no such user.

		// mon 7/29/98
	    allow=ob->query_temp("allow_tell");
	    if(!allow || member_array(lower_case(from+"@"+mud), allow)==-1)
	        if( ob->query("env/block_tell") ) return
		  ob->query("name")+"ÏÖÔÚ²»ÏëºÍÈÎºÎÈËËµ»°¡£";

                if(!living(ob) || !interactive(ob)) 
	          return ob->query("name")+"ÏÖÔÚÌı²»¼ûÄãËµµÄ»°¡£\n";

		if( cname )
			tell_object(ob, sprintf(HIG "%s(%s@%s)¸æËßÄã£º%s\n" NOR,
				cname, capitalize(from), mud, msg ));
		else
			tell_object(ob, sprintf(HIG "%s@%s ¸æËßÄã£º%s\n" NOR,
				capitalize(from), mud, msg ));
		ob->set_temp("reply", from+"@"+mud);

		return ob->query("name")+"ÊÕµ½ÁËÄãµÄÏûÏ¢¡£";  
		// if succeed, return target's name.
	} else
		return "ÏÖÔÚÕÒ²»µ½Õâ¸öÈË¡£";
}

// mon 7/29/98
void add_id(object me, string id)
{
    string *allow;

    // temp array of players we allow to talk to.
    allow=me->query_temp("allow_tell");
    if(!allow) allow=({id});
    else if(sizeof(allow)<50 && member_array(id,allow)==-1)
        allow+=({id});
    me->set_temp("allow_tell", allow);
}

int help(object me)
{
	write(@HELP
Ö¸Áî¸ñÊ½£ºtell <Ä³ÈË> <Ñ¶Ï¢>

Äã¿ÉÒÔÓÃÕâ¸öÖ¸ÁîºÍÆäËûµØ·½µÄÊ¹ÓÃÕßËµ»°¡£

ÆäËûÏà¹ØÖ¸Áî£ºreply
HELP
	);
	return 1;
}
