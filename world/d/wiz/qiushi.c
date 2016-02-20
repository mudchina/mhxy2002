// qiushi.c ÕâÊÇÓÃÀ´³Í·£Íæ¼ÒÆÆ»µ¼ÍÂÉµÄ
//player prison
//idea@yqyl

#include <ansi.h>
void takeout(object who);

inherit ROOM;

void wizchannel(string result);

void create()
{
        set("short",HIW"ÇôÊÒ"NOR);
        set("long", @LONG

ÕâÀïÊÇ×¨ÃÅÓÃÀ´¹ØÑºÇô½ûÁ÷Ã¥µÄµØ·½£¬½øÁËÕâÀï¾ÍÖ»ÄÜÀÏÀÏÊµÊµ
µÄ´ô×Å¡£ËÄÖÜºÚÆáÆáµÄÒ»Æ¬¡£¾ÙÄ¿Ô¶Ì÷ÈÔ¿´²»µ½ÈÎºÎÊÂÎï¡£Â£¶ú
ÇãÌıÈ´Ìı²»µ½ÈÎºÎÉùÏì¡£

LONG );
	set("objects", ([
	//	__DIR__"npc/yuzu":1
		__DIR__"npc/zhongkui":1
	]) );
	set("no_fight", 1);
	set("no_magic",1);
	set("no_kill",1);

        set("valid_startroom", 1);
        set("alternative_unc",1);
        set("channel_id", "ÇôÊÒ");
        setup();

  call_other("/obj/board/heiban_b", "???");

        remove_call_out("check_in");
        call_out("check_in",60);
}


void init()
{
        object me;
        int mudage;
        string ttime,temp;
        
        me = this_player();
	if (userp(me))
        if( !wizardp(me) )
        {
        	if (me->query("startroom")!="/d/wiz/qiushi")
        	{
        	ttime=ctime(time())[8..strlen(ctime(time()))];

        	me->add("qiushi/times",1);
		me->add("qiushi/totaltime",me->query("qiushi/howlong"));
		me->set("qiushi/inage",me->query("mud_age"));
        	me->set("startroom","/d/wiz/qiushi");
        	temp = me->query("qiushi/temp");
        	me->delete("qiushi/temp");
        	if (temp) {
        	me->set("qiushi/note",ttime+"  "+temp);}
        	else { me->set("qiushi/note",sprintf("%s  %s(%s)½øÈëÇôÊÒ£¬Ô­Òò²»Ïê¡£\n",
        		ttime,me->query("name"),me->query("id")));
        		}
        	
        	me->save();
        	
        	wizchannel(me->query("qiushi/note"));
        	log_file("qiujin",me->query("qiushi/note"));
        	}
		add_action("block_cmd","",1);  

        	message("vision",
        	HIY "Ö»ÌıÌúÃÅ¿ïµØÒ»Ïì£¬Ò»¸ö¼Ò»ï±»ÈÓÁË½øÀ´£¡\n\n" NOR, environment(me), me);
        	tell_object( me, HIR "ÒòÎªÄãµÄËù×öËùÎª¶Ô±¾MUDÔì³ÉÁË²»Á¼Ó°Ïì£¬"
        		+"ËùÒÔ¹ØÄãÀ´ÕâÀï£¬ÈÃÄãºÃºÃ·´Ê¡·´Ê¡£¡\n\n" NOR);
        }
        
}

int block_cmd1()
{
	string verb = query_verb();
	if (verb=="quit") return 0;
	tell_object( this_player(),"\n\n¶Ô²»Æğ£¬ÄãÊÜµ½ÁË×îÑÏÀ÷µÄÇô½û£¬ÄãÏÖÔÚÖ»ÄÜÂıÂı×øÀÎ£¬»òÕßÍË³ö" NOR);
	return 1;
}

int block_cmd()
{
  	string verb = query_verb();
  	if (verb=="say") return 0; 
  	if (verb=="help") return 0;
  	if (verb=="who") return 0;
  	if (verb=="look") return 0;
  	if (verb=="quit") return 0;
  	if (verb=="skills") return 0;
  	if (verb=="score") return 0;
  	if (verb=="hp") return 0;
  	if (verb=="exert") return 0;
  	tell_object( this_player(),"È°Äã»¹ÊÇ¾²Ë¼¹ı´í°É£¬²»ÒªÔÙ¶¯Ê²Ã´»µÖ÷ÒâÁË£¬ÔÚÕâÀïÊÇÊ²Ã´¶¼×ö²»ÁË£¡\n\n" NOR);
  	return 1;
}

void check_in()
{
	object *criminal = all_inventory(this_object()),yuzu;
	int i,howlong,inage,mudage;
	string cname,result,old,ttime;
	
	remove_call_out("check_in");

	for(i=0; i<sizeof(criminal); i++)
	{
		if (userp(criminal[i]) && !wizardp (criminal[i]))
		{	
			if (criminal[i]->query("food")<50 || criminal[i]->query("water")<50)
			{
				tell_object(criminal[i],"×ÜËã¿ÉÒÔ³Ô·¹ÁË£¬Óü×äÈÓÀ´Ò»ÍëÊ£·¹£¬"+
					"±»ÄãÀÇÍÌ»¢ÑÊµÄ¸É¹ØÁË¡£\n");
				criminal[i]->set("food",150);
				criminal[i]->set("water",150);
			}
			
			howlong = criminal[i]->query("qiushi/howlong");
			inage = criminal[i]->query("qiushi/inage");
			mudage = criminal[i]->query("mud_age");
			
			if (howlong)
			{
				if( (inage+howlong*60)<mudage )
				{
					ttime=ctime(time())[8..strlen(ctime(time()))];
					
					cname = criminal[i]->query("name") + "("+criminal[i]->query("id")+")";
					
					result = sprintf("%s  %s·şĞÌÆÚÂú(%d·ÖÖÓ)£¬×Ô¶¯ÊÍ·Å¡£\n",
							ttime,cname,howlong);
							
					old=criminal[i]->query("qiushi/note")+result;
					criminal[i]->set("qiushi/note",old);
					log_file("qiujin",result);
		
					wizchannel(result);
					takeout(criminal[i]);
				}
			}
		}
	}
	
	call_out("check_in",60);
}

void takeout(object who)
{
	who->move("/d/city/kezhan");
	who->set("startroom", "/d/city/kezhan");
	who->save();
	message_vision("$N±»´ÓÀÎ·¿ÀïÃæ·ÅÁË³öÀ´¡£\n",who);
	message("system","\n\n  [1;32m "+who->name(1)+"³öÓüÁË, Ï£ÍûËûÄÜ¸Ä¹ı×ÔĞÂ, ÏÂ´Î²»ÒªÔÙ·¸·¨ÁË¡£[0m\n\n",users());

}


void wizchannel(string result)
{
	CHANNEL_D->do_channel(this_object(),"wiz",result);
}

void alternative_unc(object who)
{
	if (userp(who))	who->die();
}