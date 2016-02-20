//By tianlin@mhxy for 2002.1.1
//ĞŞ¸ÄºÍÌí¼ÓÈÎÎñ
#include <ansi.h>
#define TIME_TICK (time()*60)
#define TIME_TICK1 (time()*60)
int current_day_phase, current_month;
void auto_save(object *user, int size, int i);
mapping *day_phase;
int online_user();
string ppl;

string *month_time = ({
	"´ºÌìÇÄÇÄµØ×ßÀ´ÁË£¬",
	"´º·çÇáÇáµØ·÷¹ıÄãµÄÁ³ÅÓ£¬",
	"ÌìÆøÖğ½¥±äÅ¯ÁË£¬",
	"ÒÑ¾­ÊÇ³õÏÄÊ±½ÚÁË£¬",
	"ÖªÁËµÄ½ĞÉùÈÃÄã¸Ğ¾õµ½ÁËÊ¢ÏÄµÄÆøÏ¢£¬",
	"ÌìÆø±äµÃ·Ç³£ÃÆÈÈ£¬",
	"ËäÈ»ÊÇÇïÌìÁË£¬ÌìÆø»¹ÊÇÓĞĞ©ÈÈ£¬",
	"ÖĞÇï¼Ñ½Ú¿ìµ½ÁË£¬",
	"Ò»ÕóÇï·ç´µÀ´£¬¾íÆğÁËµØÉÏµÄÂäÒ¶£¬",
	"ÇïÈ¥¶¬À´£¬",
	"º®·çÁİÙı£¬",
	"¿ìµ½Äê¹ØÁË£¬",
});

string *month_desc = ({
	HIW"¡¸Â¡¶¬µÄ¡¹:"NOR,
	HIW"¡¸º®¶¬µÄ¡¹:"NOR,
	HIG"¡¸³õ´ºµÄ¡¹:"NOR,
	HIG"¡¸Ôç´º¶şÔÂµÄ¡¹:"NOR,
	HIG"¡¸Ñô´ºÈıÔÂµÄ¡¹:"NOR,
	HIC"¡¸³õÏÄµÄ¡¹:"NOR,
	HIC"¡¸Ê¢ÏÄµÄ¡¹:"NOR,
	HIR"¡¸ÖÙÏÄµÄ¡¹:"NOR,
	HIY"¡¸³õÇïµÄ¡¹:"NOR,
	HIY"¡¸Çï¸ßÆøË¬µÄ¡¹:"NOR,
	YEL"¡¸ÉîÇïµÄ¡¹:"NOR,
	WHT"¡¸³õ¶¬µÄ¡¹:"NOR,
});

int query_current_day_phase() { return current_day_phase; }
mapping *read_table(string file);
void init_day_phase();
void haojie();

void create()
{
	string get_month, get_day;
	mixed *local;
	local = localtime(TIME_TICK1);
        get_day = CHINESE_D->chinese_number(local[3]);
	get_month = CHINESE_D->chinese_number(local[4]);
	switch(get_month)
	{
		//spring weather
		case "Èı":
		case "ËÄ":
		case "Îå":
		     switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/spring_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/spring_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/spring_wind");
			   break;
		     }
		     break;
		//summer weather
		case "Áù":
		case "Æß":
		case "°Ë":
		     switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/summer_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/summer_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/summer_wind");
			   break;
		     }
		     break;
		//autumn weather
		case "¾Å":
		case "Ê®":
		case "Ê®Ò»":
		     switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/autumn_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/autumn_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/autumn_wind");
			   break;
		     }
		     break;
		//winter weather
                case "Áã":
		case "¶ş":
		     switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/winter_rain");
			   break;
			case 1:		
			   day_phase = read_table("/adm/etc/nature/winter_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/winter_wind");
			   break;
		     }
		case "Ò»":
		        if(get_day=="Ò»")
		      { day_phase = read_table("/adm/etc/nature/spring");break;}
		      else switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/winter_rain");
			   break;
			case 1:		
			   day_phase = read_table("/adm/etc/nature/winter_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/winter_wind");
			   break;
		     }
		        
		     break;
		default:
		     day_phase = read_table("/adm/etc/nature/day_phase");
	}


	init_day_phase();
}
void auto_save(object *user, int size, int i)
{
    int j;
    for(j=i;j<i+5;j++) {
	if(j>=size) return;
	if(!user[j]) continue;
	if(!environment(user[j])) continue; // skip those still in login.
	if(user[j]->save())
	    tell_object(user[j], RED"¡¾"CYN"µµ°¸´¢´æ"RED"¡¿: "HIY"ÄúµÄµµ°¸ÒÑ¾­×Ô¶¯´æ´¢¡£\n"NOR);//by tianlin 2001.7.4ĞŞ¸Ä
    }
    
    call_out("auto_save", 10, user, size, i+5);
}
void resetage()
{
	 if ("/cmds/wiz/resetage"->main())
	// message("channel:sys",HIG"\n¡¾"HIW"ÏµÍ³"HIG"¡¿£º¼ì²éÄêÁäÒÑ¾­Íê³É.\n "NOR,users());
        call_out("resetage", 10);
}
void init_day_phase()
{
	mixed *local;
	int i, t;

	// Get minutes of today.
	local = localtime(TIME_TICK1);
	t = local[2] * 60 + local[1];           // hour * 60 + minutes

	// Find the day phase for now.
	for( i=0; i < sizeof(day_phase); i++)
		if( t >= day_phase[i]["length"] )
			t -= (int)day_phase[i]["length"];
		else
			break;
        if(random(10)<=7) "/adm/daemons/moneyd"->move_money(1);
        else if(random(10)<=7) "/adm/daemons/moneyd"->move_money(150);

	current_day_phase = (i==0? sizeof(day_phase)-1: i - 1);
	current_month = local[4];

	// MUD ÔËĞĞÊ±¼ä¾ÃÁË£¬Ê±¼ä»áÓĞÆ«²î£¬ÕâÀïÊÇµ÷Õû³ÌĞò£¬Ã¿Ğ¡Ê±Ö´ĞĞÒ»´Î
	remove_call_out("init_day_phase");
	call_out("init_day_phase", 3600);

	// Since in our time scale, 1 minute == 1 second in RL, so we don't need
	// any conversion before using this number as call_out dalay, if you 
	// changed the time scale, be sure to convert it.
	remove_call_out("update_day_phase");	

	// Since in our time scale, 1 minute == 1 second in RL, so we don't need
	// any conversion before using this number as call_out dalay, if you
	// changed the time scale, be sure to convert it.

	call_out("update_day_phase",
	(int)day_phase[(current_day_phase+1) % sizeof(day_phase)]["length"] - t);
}

void update_day_phase()
{
	int i,j;
	object *inusers,envroom;
	string str;
	remove_call_out("update_day_phase");

	current_day_phase = (++current_day_phase) % sizeof(day_phase);
	if( !undefinedp(day_phase[current_day_phase]["event_fun"]) )
		call_other(this_object(), day_phase[current_day_phase]["event_fun"]);
        i=0;
        // here is modified by vikee 2001-2-15 13:15
        str=HIG"¨d¨g"NOR+YEL"´°Íâ"HIG"¨d¨g:"NOR+day_phase[current_day_phase]["time_msg"];
        inusers=users();
        for (i;i<(j=sizeof(inusers));i++)
        {
            envroom=environment(inusers[i]);
            if (envroom)
           {
            if ( intp(envroom->query("outdoors")))
             {
               if (envroom->query("outdoors")<1)
             	tell_object(inusers[i],str+"\n");
               else 
               tell_object(inusers[i],day_phase[current_day_phase]["time_msg"]+"\n");
             }
            else
             {
             	tell_object(inusers[i],day_phase[current_day_phase]["time_msg"]+"\n");
             }
          }     
       }
       call_out("update_day_phase", day_phase[current_day_phase]["length"]);

}

void event_morning()
{
	object badguy;
	object room;
        if (random(12) == 1)
        {
		if(objectp(room=load_object("/d/city/changan/center")) && 
		objectp(badguy = new("/quest/weiguo/japan/japan4")))
	        	badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
  message("channel:chat", HIY"¡¾ÌìÍ¢¼±±¨¡¿"HIR + "ÔÚ³¤°²³ÇÖĞ·¢ÏÖÑı¹Ö£¡\n"NOR,users() );
	}
        if (random(12) == 2)
        {
		if(objectp(room=load_object("/d/qujing/tianzhu/shizi")) && 
		objectp(badguy = new("/quest/weiguo/japan/japan4")))
	            badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
  message("channel:chat", HIY"¡¾ÌìÍ¢¼±±¨¡¿"HIM + "ÔÚÌìóÃ¹úÖĞ·¢ÏÖÑı¹Ö£¡\n"NOR,users() );
	}
        if (random(12) == 3)
        {
		if(objectp(room=load_object("/d/qujing/nuerguo/towna2")) && 
		objectp(badguy = new("/quest/weiguo/japan/japan4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
 message("channel:chat", HIY"¡¾ÌìÍ¢¼±±¨¡¿"HIM + "ÔÚÅ®¶ù¹úÖĞ·¢ÏÖÑı¹Ö£¡\n"NOR,users() );
	}
        if (random(12) == 4)
        {
		if(objectp(room=load_object("/d/qujing/biqiu/jie3")) && 
		objectp(badguy = new("/quest/weiguo/japan/japan4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
  message("channel:chat", HIB"¡¾ÌìÍ¢¼±±¨¡¿"GRN + "ÔÚ±ÈÇğ¹úÖĞ·¢ÏÖÑı¹Ö£¡\n"NOR,users() );
	}
        if (random(12) == 5)
        {
		if(objectp(room=load_object("/d/kaifeng/guting1")) && 
		objectp(badguy = new("/quest/weiguo/japan/japan4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
message("channel:chat", HIB"¡¾ÌìÍ¢¼±±¨¡¿"GRN + "ÔÚ¿ª·â³ÇÖĞ·¢ÏÖÑı¹Ö£¡\n"NOR,users() );
	}
        if (random(12) == 6)
        {
		if(objectp(room=load_object("/d/qujing/baoxiang/gongmen")) && 
		objectp(badguy = new("/quest/weiguo/japan/japan4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
message("channel:chat", HIB"¡¾ÌìÍ¢¼±±¨¡¿"GRN + "ÔÚ±¦Ïó¹úÖĞ·¢ÏÖÑı¹Ö£¡\n"NOR,users() );
	}
        if (random(12) == 7)
        {
		if(objectp(room=load_object("/d/qujing/chechi/gongmen")) && 
		objectp(badguy = new("/quest/weiguo/japan/japan4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
  message("channel:chat", HIG"¡¾ÌìÍ¢¼±±¨¡¿"CYN + "ÔÚ³µ³Ù¹úÖĞ·¢ÏÖÑı¹Ö£¡\n"NOR,users() );
	}
        if (random(12) == 8)
        {
		if(objectp(room=load_object("/d/qujing/zhuzi/gulou")) && 
		objectp(badguy = new("/quest/weiguo/japan/japan4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
  message("channel:chat", HIG"¡¾ÌìÍ¢¼±±¨¡¿"CYN + "ÔÚÖì×Ï¹úÖĞÖĞ·¢ÏÖÑı¹Ö£¡\n"NOR,users() );
	}
        if (random(12) == 9)
        {
		if(objectp(room=load_object("/d/qujing/qinfa/zhongshi")) && 
		objectp(badguy = new("/quest/weiguo/japan/japan4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
  message("channel:chat", HIG"¡¾ÌìÍ¢¼±±¨¡¿"CYN + "ÔÚÇÕ·¨¹úÖĞ·¢ÏÖÑı¹Ö£¡\n"NOR,users() );
	}
        if (random(12) == 10)
        {
		if(objectp(room=load_object("/d/qujing/fengxian/shikou")) && 
objectp(badguy = new("/quest/weiguo/japan/japan4")))
		badguy->move(room);
 badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
  message("channel:chat", HIR"¡¾ÌìÍ¢¼±±¨¡¿"BLU + "ÔÚ·ïÏÉ¿¤ÖĞ·¢ÏÖÑı¹Ö£¡\n"NOR,users() );
	}
        if (random(12) == 11)
        {
		if(objectp(room=load_object("/d/qujing/yuhua/xiaojie7")) && 
		objectp(badguy = new("/quest/weiguo/japan/japan4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
  message("channel:chat", HIR"¡¾ÌìÍ¢¼±±¨¡¿"BLU + "ÔÚÓñ»ªÏØÖĞ·¢ÏÖÑı¹Ö£¡\n"NOR,users() );
	}
        if (random(12) == 12)
        {
		if(objectp(room=load_object("/d/qujing/jinping/xiaojie7")) && 
		objectp(badguy = new("/quest/weiguo/japan/japan4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
  message("channel:chat", HIR"¡¾ÌìÍ¢¼±±¨¡¿"BLU + "ÔÚ½ğÆ½¸®ÖĞ·¢ÏÖÑı¹Ö£¡\n"NOR,users() );
	}
        if (random(16) == 1)
        {
		if(objectp(room=load_object("/d/qujing/wuzhuang/guangchang")) && 
		objectp(badguy = new("/quest/weiguo/japan/japan4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                message("channel:chat", HIR"¡¾ÌìÍ¥¸æ¼±¡¿"HIW + "Ñı¹Ö´ó¾ü¹¥´òÎå×¯¹Û£¡\n"NOR,users() );
	}
        if (random(16) == 2)
        {
		if(objectp(room=load_object("/d/moon/ontop2")) && 
		objectp(badguy = new("/quest/weiguo/japan/japan4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
  message("channel:chat", HIR"¡¾ÌìÍ¥¸æ¼±¡¿"HIW + "Ñı¹Ö´ó¾üÔÚÀ¥ÂØÉ½ÔÂ¹¬£¡É±ÎÒ°ÙĞÕ!!\n"NOR,users() );
	}
        if (random(16) == 4)
        {
		if(objectp(room=load_object("/d/lingtai/inside1")) && 
		objectp(badguy = new("/quest/weiguo/japan/japan4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
               message("channel:chat", HIR"¡¾ÌìÍ¥¸æ¼±¡¿"HIW + "Ñı¹Ö´ó¾ü½ø¾üÁéÌ¨·½´çÉ½£¡·½´çÉ½¸æ¼±!!\n"NOR,users() );
	}
        if (random(16) == 7)
        {
		if(objectp(room=load_object("/d/jjf/pavillion")) && 
		objectp(badguy = new("/quest/weiguo/japan/japan4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
  message("channel:chat", HIR"¡¾ÌìÍ¥¸æ¼±¡¿"HIW + "Ñı¹ÖµÄ²¿¶ÓÉ±ÈëÁË´óÌÆ½«¾ü¸®£¡½«¾ü¸®¸æÎ£!!\n"NOR,users() );
	}
}

void event_night()
{
	object badguy;
	object room;
        if (random(12) == 1)
        {
		if(objectp(room=load_object("/d/city/qinglong-e1")) && 
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"¡¾¹Ù¸®Í¨¸æ¡¿"HIR + "³¤°²³ÇÖĞ½ñÒ¹ÓĞ·ÉÔôºáĞĞ£¬Á¼Ãñ°ÙĞÕÇë±ÕÃÅ²»³ö£¬ÇĞÄª×ÔÎó£¡\n"NOR,users() );
	}
        if (random(12) == 2)
        {
		if(objectp(room=load_object("/d/kaifeng/yao3")) && 
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"¡¾¹Ù¸®Í¨¸æ¡¿"HIR + "¿ª·â³ÇÖĞ½ñÒ¹ÓĞ·ÉÔôºáĞĞ£¬Á¼Ãñ°ÙĞÕÇë±ÕÃÅ²»³ö£¬ÇĞÄª×ÔÎó£¡\n"NOR,users() );
	}
        if (random(12) == 3)
        {
		if(objectp(room=load_object("/d/qujing/qinfa/jiedao1")) && 
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"¡¾¹Ù¸®Í¨¸æ¡¿"HIR + "ÇÕ·¨¹úÖĞ½ñÒ¹ÓĞ·ÉÔôºáĞĞ£¬Á¼Ãñ°ÙĞÕÇë±ÕÃÅ²»³ö£¬ÇĞÄª×ÔÎó£¡\n"NOR,users() );
	}
        if (random(12) == 4)
        {
		if(objectp(room=load_object("/d/qujing/fengxian/jiedao7")) && 
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"¡¾¹Ù¸®Í¨¸æ¡¿"HIR + "·ïÏÉ¿¤ÖĞ½ñÒ¹ÓĞ·ÉÔôºáĞĞ£¬Á¼Ãñ°ÙĞÕÇë±ÕÃÅ²»³ö£¬ÇĞÄª×ÔÎó£¡\n"NOR,users() );
	}
        if (random(12) == 5)
        {
		if(objectp(room=load_object("/d/qujing/zhuzi/zhuzi5")) && 
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"¡¾¹Ù¸®Í¨¸æ¡¿"HIR + "Öì×Ï¹úÖĞ½ñÒ¹ÓĞ·ÉÔôºáĞĞ£¬Á¼Ãñ°ÙĞÕÇë±ÕÃÅ²»³ö£¬ÇĞÄª×ÔÎó£¡\n"NOR,users() );
	}
        if (random(12) == 6)
        {
		if(objectp(room=load_object("/d/qujing/jisaiguo/east1")) && 
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"¡¾¹Ù¸®Í¨¸æ¡¿"HIR + "¼ÀÈü¹úÖĞ½ñÒ¹ÓĞ·ÉÔôºáĞĞ£¬Á¼Ãñ°ÙĞÕÇë±ÕÃÅ²»³ö£¬ÇĞÄª×ÔÎó£¡\n"NOR,users() );
	}
        if (random(12) == 7)
        {
		if(objectp(room=load_object("/d/qujing/baoxiang/bei3")) && 
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"¡¾¹Ù¸®Í¨¸æ¡¿"HIR + "±¦Ïó¹úÖĞ½ñÒ¹ÓĞ·ÉÔôºáĞĞ£¬Á¼Ãñ°ÙĞÕÇë±ÕÃÅ²»³ö£¬ÇĞÄª×ÔÎó£¡\n"NOR,users() );
	}
        if (random(12) == 8)
        {
		if(objectp(room=load_object("/d/qujing/wuji/estreet2")) && 
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"¡¾¹Ù¸®Í¨¸æ¡¿"HIR + "ÎÚ¼¦¹úÖĞ½ñÒ¹ÓĞ·ÉÔôºáĞĞ£¬Á¼Ãñ°ÙĞÕÇë±ÕÃÅ²»³ö£¬ÇĞÄª×ÔÎó£¡\n"NOR,users() );
	}
        if (random(12) == 9)
        {
		if(objectp(room=load_object("/d/qujing/chechi/jieshi6")) && 
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"¡¾¹Ù¸®Í¨¸æ¡¿"HIR + "³µ³Ù¹úÖĞ½ñÒ¹ÓĞ·ÉÔôºáĞĞ£¬Á¼Ãñ°ÙĞÕÇë±ÕÃÅ²»³ö£¬ÇĞÄª×ÔÎó£¡\n"NOR,users() );
	}
        if (random(12) == 10)
        {
		if(objectp(room=load_object("/d/qujing/nuerguo/towna3")) && 
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"¡¾¹Ù¸®Í¨¸æ¡¿"HIR + "Å®¶ù¹úÖĞ½ñÒ¹ÓĞ·ÉÔôºáĞĞ£¬Á¼Ãñ°ÙĞÕÇë±ÕÃÅ²»³ö£¬ÇĞÄª×ÔÎó£¡\n"NOR,users() );
	}
        if (random(12) == 11)
        {
		if(objectp(room=load_object("/d/qujing/tianzhu/jiedao14")) && 
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"¡¾¹Ù¸®Í¨¸æ¡¿"HIR + "ÌìóÃ¹úÖĞ½ñÒ¹ÓĞ·ÉÔôºáĞĞ£¬Á¼Ãñ°ÙĞÕÇë±ÕÃÅ²»³ö£¬ÇĞÄª×ÔÎó£¡\n"NOR,users() );
	}
        if (random(12) == 12)
        {
		if(objectp(room=load_object("/d/qujing/jinping/xiaojie1")) && 
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"¡¾¹Ù¸®Í¨¸æ¡¿"HIR + "½ğÆ½¸®ÖĞ½ñÒ¹ÓĞ·ÉÔôºáĞĞ£¬Á¼Ãñ°ÙĞÕÇë±ÕÃÅ²»³ö£¬ÇĞÄª×ÔÎó£¡\n"NOR,users() );
	}

}

void event_afternoon()
{
	object *ob_list;
	int i;
	ob_list = children("/quest/weiguo/japan/japan1");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$NËµµÀ£ºÌìÒªºÚÁË£¬³·±ø£¡\n",ob_list[i]);
			destruct(ob_list[i]);
                }
	ob_list = children("/quest/weiguo/japan/japan2");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$NËµµÀ£ºÌìÒªºÚÁË£¬³·±ø£¡\n",ob_list[i]);
			destruct(ob_list[i]);
                }
	ob_list = children("/quest/weiguo/japan/japan3");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$NËµµÀ£ºÌìÒªºÚÁË£¬³·±ø£¡\n",ob_list[i]);
			destruct(ob_list[i]);
                }
	ob_list = children("/quest/weiguo/japan/japan4");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$NËµµÀ£ºÌìÒªºÚÁË£¬¶«Î÷Ò²µ½ÊÖÁË£¬ÎÒÉÁ£¡\n",ob_list[i]);
			destruct(ob_list[i]);
                }
	ob_list = children("/quest/weiguo/jinbing/jin1");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$NËµµÀ£ºÌìÒªºÚÁË£¬³·±ø£¡\n",ob_list[i]);
			destruct(ob_list[i]);
                }
	ob_list = children("/quest/weiguo/jinbing/jin2");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$NËµµÀ£ºÌìÒªºÚÁË£¬³·±ø£¡\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/jinbing/jin3");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$NËµµÀ£ºÌìÒªºÚÁË£¬³·±ø£¡\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/jinbing/jin4");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$NËµµÀ£ºÌìÒªºÚÁË£¬¶«Î÷Ò²µ½ÊÖÁË£¬ÎÒÉÁ£¡\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/menggu/mengu1");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$NËµµÀ£ºÌìÒªºÚÁË£¬³·±ø£¡\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/menggu/mengu2");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$NËµµÀ£ºÌìÒªºÚÁË£¬³·±ø£¡\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/menggu/mengu3");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$NËµµÀ£ºÌìÒªºÚÁË£¬³·±ø£¡\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/menggu/mengu4");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$NËµµÀ£ºÌìÒªºÚÁË£¬¶«Î÷Ò²µ½ÊÖÁË£¬ÎÒÉÁ£¡\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/xixiabing/xixia1");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$NËµµÀ£ºÌìÒªºÚÁË£¬³·±ø£¡\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/xixiabing/xixia2");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$NËµµÀ£ºÌìÒªºÚÁË£¬³·±ø£¡\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/xixiabing/xixia3");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$NËµµÀ£ºÌìÒªºÚÁË£¬³·±ø£¡\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/xixiabing/xixia4");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$NËµµÀ£ºÌìÒªºÚÁË£¬¶«Î÷Ò²µ½ÊÖÁË£¬ÎÒÉÁ£¡\n",ob_list[i]);
			destruct(ob_list[i]);
                }
}

void event_dawn()
{
	object *ob_list;
	int i;
	ob_list = children("/quest/feizei/feizei");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
			message_vision("$NĞ¦µÀ£ºÌìÁÁÁË£¬¶«Î÷Ò²µ½ÊÖÁË£¬ÎÒÉÁ£¡\n",ob_list[i]);
			destruct(ob_list[i]);
                }
	ob_list = children("/d/city/npc/badguy");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
			message_vision(HIB"$N"HIB"½ĞµÀ£º²»ºÃ£¬ÌìÏşÒ²£¬³¶ºô¡«¡«¡«¡«\n"NOR,ob_list[i]);
			destruct(ob_list[i]);
                }
}



void event_midnight()
{       
	object badguy;
	object room;
	string get_month, get_day;
	mixed *local;
	local = localtime(TIME_TICK1);
	get_day = CHINESE_D->chinese_number(local[3]);
	get_month = CHINESE_D->chinese_number(local[4]);
	if(!random(10))
	{
		if(objectp(room=load_object("/d/city/center")) && 
		objectp(badguy = new("/d/city/npc/badguy")))
		badguy->move(room);
	       badguy->command("chat [1;31m·ç¸ß·Å»ğÌì£¬ÔÂºÚÉ±ÈËÒ¹ £¡£¡£¡[0m");
	}

	switch(get_month)
	{
		//spring weather
		case "Èı":
		case "ËÄ":
		case "Îå":
		     switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/spring_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/spring_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/spring_wind");
			   break;
		     }
		     break;
		//summer weather
		case "Áù":
		case "Æß":
		case "°Ë":
		     switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/summer_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/summer_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/summer_wind");
			   break;
		     }
		     break;
		//autumn weather
		case "¾Å":
		case "Ê®":
		case "Ê®Ò»":
		     switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/autumn_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/autumn_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/autumn_wind");
			   break;
		     }
		     break;
		//winter weather
                case "Áã":
		case "¶ş":
		     switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/winter_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/winter_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/winter_wind");
			   break;
		     }
		     
		     case "Ò»":
		        if(get_day=="Ò»")
		      { day_phase = read_table("/adm/etc/nature/spring");break;}
		      else switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/winter_rain");
			   break;
			case 1:		
			   day_phase = read_table("/adm/etc/nature/winter_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/winter_wind");
			   break;
		     }
		     break;
		default:
		     day_phase = read_table("/adm/etc/nature/day_phase");
	}


}

// This is called everyday noon by update_day_phase, defined in the
// "event_fun" field in /adm/etc/nature/day_phase

int online_user()
{ int i,ppl_cnt;
object *usr = users();
for(i=0; i<sizeof(usr); i++) {
		if( !environment(usr[i]) ) continue;
		ppl_cnt++;
	}
	return ppl_cnt;
}
void event_sunrise()
{
            int avg_num,record_num,online_num,total_num,times;
//	     int i;
            string avg_temp,total_temp,times_temp;
            object *user=users();
//	     object *ob_list;
//	     ob_list = children("/d/city/npc/badguy");
//          for(i=0; i<sizeof(ob_list); i++) 
            online_num = online_user();
            times = atoi(read_file(__DIR__"record_times",1));
            times++;
            record_num = atoi(read_file(__DIR__"total_num",1));
            total_num = online_num + record_num;
            avg_num = total_num / times;
            total_temp = sprintf("%d",total_num);
            times_temp = sprintf("%d",times);
            avg_temp = sprintf("%d",avg_num);
            write_file(__DIR__"total_num",total_temp,1);
            write_file(__DIR__"record_times",times_temp,1);
            write_file(__DIR__"avguser",avg_temp,1);
/*          if(environment(ob_list[i]))
		{
	     message_vision(HIB"$N"HIB"½ĞµÀ£º²»ºÃ£¬ÌìÏşÒ²£¬³¶ºô¡«¡«¡«¡«\n"NOR,ob_list[i]);
	     destruct(ob_list[i]);
              }
*/          
	     remove_call_out("auto_save");
	     call_out("auto_save", 10, user, sizeof(user), 0);
}
void event_evening()
{
        object area,who;
        mixed file,dir;
        int amount,i;
          dir=get_dir("/data/city/");
       if(!dir) return; 
 	
	for(i=0;i<sizeof(dir);i++)
      if( sscanf(dir[i], "%s.o", file) ) {
      area=new("/obj/area1.c");
      area->create(file);
      if(area->query("no_use"))
   {
      destruct(area);

      continue;
    } 

     if(area->query("owner"))  
{
amount=area->query("people")*(area->query("farm")+area->query("trade"))*area->query("tax")/1000;
if(amount <=0) return;

    who=find_player(area->query("owner"));
    if(who) {
	who->add("balance",amount);
	if(!who->save()) {
	    log_file("city_log","Failed to return "+amount+
		    " coin to "+area->query("owner")+"\n");
	    return;
	}
	log_file("city_log","pay "+amount+" to "+area->query("owner")+"\n");
 tell_object(who,area->query("short")+"Ë°ÊÕ"+MONEY_D->money_str(amount)+",ÒÑ¾­´æÈëÄãµÄ»§Í·¡£\n");

    } else {
	who=new(USER_OB);
	who->set("id",area->query("owner"));
	if(!who->restore()) {
	    log_file("city_log","Failed to return "+amount+
		    " coin to "+area->query("owner")+"\n");
	    destruct(who);
	    return;
	} else {
	    who->add("balance",amount);
	    if(!who->save(1)) { // save(1) will not erase autoload.
		log_file("city_log","Failed to return "+amount+
			" coin to "+area->query("owner")+"\n");
		destruct(who);
		return;
	    } 
	    log_file("city_log","pay "+amount+" to "+area->query("owner")+"\n");
	    destruct(who);
	    }
    }

}
}
        return;
}
void event_noon()
{
	object *ob;
	int i, skill;

	ob = users();
	for(i=0; i<sizeof(ob); i++) {
		if( !environment(ob[i]) ) continue;
		if( !environment(ob[i])->query("outdoors") ) continue;
		if( !ob[i]->query("mana") ) continue;
		if( !(skill = ob[i]->query_skill("spells", 1) )) {
			tell_object(ob[i], "Äã¾õµÃÒ»ÕóÔÎÑ££¬ºÃÏñÓĞÒ»¹ÉÄÜÁ¿´ÓÉíÉÏ±»ÈËÎü×ßÁË¡£\n");
			ob[i]->set("mana", 0);
			ob[i]->receive_damage("sen", 0);
		} else if( skill < 25 ) {
			tell_object(ob[i], "Ëæ×ÅÌ«ÑôÉıµ½Ìì¿ÕµÄÕıÖĞÑë£¬Äã¾õµÃÄãµÄ·¨Á¦¿ªÊ¼ÏûÊ§ÁË¡£\n");
			ob[i]->set("mana", (int)ob[i]->query("mana") * skill / 25 );
		}
	}
}

string outdoor_room_description()
{
	return "    " + sprintf(
		day_phase[current_day_phase]["desc_msg"],
                month_desc[current_month]) + "¡£\n";
}

string game_time()
{
	return CHINESE_D->chinese_date(TIME_TICK1);
}

mapping *read_table(string file)
{
	string *line, *field, *format;
	mapping *data;
	int i, rn, fn;

	line = explode(read_file(file), "\n");
	data = ({});
	for(i=0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]=='#' ) continue;
		if( !pointerp(field) ) {
			field = explode( line[i], ":" );
			continue;
		}
		if( !pointerp(format) ) {
			format = explode( line[i], ":" );
			continue;
		}
		break;
	}

	for( rn = 0, fn = 0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]=='#' ) continue;
		if( !fn ) data += ({ allocate_mapping(sizeof(field)) });
		sscanf( line[i], format[fn], data[rn][field[fn]] );
		fn = (++fn) % sizeof(field);
		if( !fn ) ++rn;
	}
	return data;
}

mapping *query_day_phase() { return day_phase; }
