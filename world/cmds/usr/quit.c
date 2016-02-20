//By tianlin@mhxy for 2002.1.19

#include <ansi.h>
#include <command.h>

inherit F_DBASE;
inherit F_CLEAN_UP;

int do_drop(object me, object obj);

void create() 
{
	seteuid(getuid());
	set("name", "ÀëÏßÖ¸Áî");
	set("id", "quit");
}

// if force_quit==1, then don't check whether allow quit.
// used by quit after disconnected or idled too long.
// mon 7/5/98
int main(object me, string arg, int force_quit)
{
	int i,addexp,addmana,addforce,adddx,addqn;
	object *inv, link_ob;
       addexp=me->query("combat_exp")-me->query_temp("combat_exp");
       addmana=me->query("max_mana")-me->query_temp("max_mana");
       addforce=me->query("max_force")-me->query_temp("max_force");
       adddx=me->query("daoxing")-me->query_temp("daoxing");
       addqn=me->query("potential")-me->query_temp("potential");
	link_ob = me->query_temp("link_ob");

	if(!force_quit) {
	if ( me->query_temp("no_move") )
		return notify_fail("Äã±»¶¨×¡ÁË£¬ÄÄÀïÍËµÃ³öÓÎÏ·£¡\n");

        if(!me->query_temp("suicide_countdown")) {
	  if( me->is_busy() )
		return notify_fail("( ÄãÉÏÒ»¸ö¶¯×÷»¹Ã»ÓĞÍê³É£¬²»ÄÜÍË³ö¡£)\n");
        } //to allow halt suicide :D by mon 9/9/97

        if( !wizardp(me) && environment(me) && 
	  environment(me)->query("no_quit") && link_ob )
                        return notify_fail("ÕâÀï²»×¼ÍË³öÓÎÏ·¡£\n");
	}

	if( !wizardp(me) && (!link_ob || (
	    link_ob && !link_ob->is_character()) ) ) {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
			if( !inv[i]->query_autoload() )
//since drop commands when quit is a little different from normal drop commands
//the do_drop is revised here. wuliao@xyj Feb 1997
				do_drop(me, inv[i]);
	}

	// We might be called on a link_dead player, so check this.
	if( link_ob ) {

		// Are we possessing in others body ?
		if( link_ob->is_character() ) {
			write("ÄãµÄ»êÆÇ»Øµ½" + link_ob->name(1) + "µÄÉíÉÏ¡£\n");
			exec(link_ob, me);
			link_ob->setup();
			return 1;
		}

		link_ob->set("last_on", time());
		link_ob->set("last_from", query_ip_name(me));
		link_ob->save();
		destruct(link_ob);
	}

	write("[37mÄãÀúÁËÌ«¶àµÄ½­ºş·ç·çÓêÓêÖÕÓÚÓĞĞ©ÀÛÁË¡£½­ºşÈË,×ÜÊÇÔÚÈËÀÏÖ®Ç°ĞÄÒ²¾ÍÀÏÁË,
Ôø¾­ß³ßå¹ıµÄ´ó½­ÄÏ±±,ÏÖÔÚ¿´¹ıÈ¥¾¹ÊÇÒ»Æ¬²×Ã£¡£Äã²»½û³¤Ğ¦ÈıÉù£ºĞÖµÜÃÇÎÒ
»¹»á»ØÀ´µÄ£¬È»ºó±ãâêÈ»ÈôÊ§,÷öÈ»ÀëÈ¥ ......£¡[2;37;0m\n");
	me->set("quit_time",time());
	if(!wizardp(me) || !me->query("env/invisibility"))
	message("system", me->name() + "Àë¿ªÓÎÏ·¡£\n", environment(me), me);

        CHANNEL_D->do_channel(this_object(), "sys",
                me->name() + "(" + capitalize(me->query("id")) + ")" + "Àë¿ªÓÎÏ·ÁË¡£\n¡¾"HIW"ÏµÍ³"HIG"¡¿("HIM+me->name()+HIG")£º"HIR"ÎäÑ§Ôö¼Ó"HIC+addexp+HIR"µã,·¨Á¦Ôö¼Ó"HIC+addmana+HIR"µã,ÄÚÁ¦Ôö¼Ó"HIC+addforce+HIR"µã,µÀĞĞÔö¼Ó"HIC+adddx+HIR"µã,Ç±ÄÜÔö¼Ó"HIC+addqn+HIR"µã\n");

        if( addexp > 100000 )
log_file("static/addexp",sprintf("%12s %8sÔö¼Ó %8d µã¾­ÑéÖµ %s \n",  
        me->name(),me->query("id"),addexp,ctime(time())));

        if( addmana > 1000 )
log_file("static/addmana",sprintf("%12s %8sÔö¼Ó %5dµã×î´ó·¨Á¦ %s \n",  
        me->name(),me->query("id"),addmana,ctime(time())));   

       if( addforce > 1000 )
 log_file("static/addforce",sprintf("%12s %8sÔö¼Ó %5d µã×î´óÄÚÁ¦ %s \n", 
        me->name(),me->query("id"),addforce,ctime(time())));

       if( adddx > 100000 )
 log_file("static/adddx",sprintf("%12s %8sÔö¼Ó %5d µãµÀĞĞ %s \n", 
        me->name(),me->query("id"),adddx,ctime(time())));

       if( addqn > 100000 )
 log_file("static/addqn",sprintf("%12s %8sÔö¼Ó %5d µãÇ±ÄÜ %s \n", 
        me->name(),me->query("id"),addqn,ctime(time())));

	me->save();
	destruct(me);

	return 1;
}

int do_drop(object me, object obj)
{
    	//if obj is a self-made fabao, save first...
        //if( obj->query("series_no") && obj->query("fabao") ) obj->save();
           
        if( obj->query("no_drop") ){
                destruct(obj);
                return 0;
        }
        if (obj->move(environment(me))) {
                if( obj->is_character() )
                        message_vision("$N½«$n´Ó±³ÉÏ·ÅÁËÏÂÀ´£¬ÌÉÔÚµØÉÏ¡£\n", me, obj);
                else {
                        message_vision( sprintf("$N¶ªÏÂÒ»%s$n¡£\n",     obj->query("unit")), me, obj );
                        if( !obj->query("value") && !obj->value() ) {
                                tell_object(me,"ÒòÎªÕâÑù¶«Î÷²¢²»ÖµÇ®£¬ËùÒÔÈËÃÇ²¢²»»á×¢Òâµ½ËüµÄ´æÔÚ¡£\n");
                                destruct(obj);
                        }
                }
                return 1;
        }
        return 0;
}

int help(object me)
{
	write(@HELP
Ö¸Áî¸ñÊ½ : quit

µ±ÄãÏëÔİÊ±Àë¿ªÊ±, ¿ÉÀûÓÃ´ËÒ»Ö¸Áî¡£
HELP
    );
    return 1;
}
