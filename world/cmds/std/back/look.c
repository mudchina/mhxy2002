// the wizard part modified by vikee for xlqy 
// look.c
// "per" parts modified by none at 96/10/02

#pragma save_binary
#include <room.h>
#include <ansi.h>

inherit F_CLEAN_UP;

int look_room(object me, object env);
int look_item(object me, object obj);
int look_living(object me, object obj);
int look_room_item(object me, string arg);
string do_query(object obj);
// mon 6/6/98
string *peep_msg = ({
	"ºÃÏñÓĞÈËÌ½Í·Ì½ÄÔµØÏòÕâ±ßÕÅÍûÁË¼¸ÑÛ¡£\n",
	"$NÌ½Í·Ì½ÄÔµØÏòÕâ±ßÕÅÍûÁË¼¸ÑÛ¡£\n",
	"ÄãºöÈ»¾õµÃËÆºõÓĞË«ÑÛ¾¦ÔÚ±³ºó¶¢×ÅÄã¿´¡£\n",
	});

string *look_level_boy = ({
 BLU "Ã¼ÍáÑÛĞ±£¬ğøÍ·Ñ¢½Å£¬²»ÏóÈËÑù\n" NOR,
 BLU "ßÚÑÀßÖ×ì£¬ºÚÈç¹øµ×£¬Ææ³óÎŞ±È\n" NOR,
 BLU "ÃæÈç½ÛÆ¤£¬Í·Ö×ÈçÖí£¬ÈÃÈË²»ÏëÔÙ¿´µÚ¶şÑÛ\n" NOR,
 HIB "ÔôÃ¼ÊóÑÛ£¬Éí¸ßÈı³ß£¬ÍğÈôºï×´\n" NOR,
 HIB "·ÊÍ·´ó¶ú£¬¸¹Ô²Èç¹Ä£¬ÊÖ½Å¶Ì´Ö£¬ÁîÈË·¢Ğ¦\n" NOR,
 NOR "Ãæ¼Õ°¼Ïİ£¬Êİ¹ÇÁæØê£¬¿ÉÁ¯¿ÉÌ¾\n" NOR,
 NOR "ÉµÍ·ÉµÄÔ£¬³Õ³Õº©º©£¬¿´À´µ¹Ò²ÀÏÊµ\n" NOR,
 NOR "ÏàÃ²Æ½Æ½£¬²»»á¸øÈËÁôÏÂÊ²Ã´Ó¡Ïó\n" NOR,
 YEL "°ò´óÑüÔ²£¬ÂúÁ³ºáÈâ£¬¶ñĞÎ¶ñÏà\n" NOR,
 YEL "ÑüÔ²±³ºñ£¬ÃæÀ«¿Ú·½£¬¹Ç¸ñ²»·²\n" NOR,
 RED "Ã¼Ä¿ÇåĞã£¬¶ËÕı´ó·½£¬Ò»±íÈË²Å\n" NOR,
 RED "Ë«ÑÛ¹â»ªÓ¨Èó£¬Í¸³öÉãÈËĞÄÆÇµÄ¹âÃ¢\n" NOR,
 HIY "¾Ù¶¯ÈçĞĞÔÆÓÎË®£¬¶ÀÔÌ·çÇé£¬ÎüÒıËùÓĞÒìĞÔÄ¿¹â\n" NOR,
 HIY "Ë«Ä¿ÈçĞÇ£¬Ã¼ÉÒ´«Çé£¬Ëù¼ûÕßÎŞ²»ÎªÖ®ĞÄ¶¯\n" NOR,
 HIR "·ÛÃæÖì´½£¬Éí×Ë¿¡ÇÎ£¬¾ÙÖ¹·çÁ÷ÎŞÏŞ\n" NOR,
 HIR "·áÉñÈçÓñ£¬Ä¿ËÆÀÊĞÇ£¬ÁîÈË¹ıÄ¿ÄÑÍü\n" NOR,
 MAG "ÃæÈçÃÀÓñ£¬·Û×±Óñ×Á£¬¿¡ÃÀ²»·²\n" NOR,
 MAG "Æ®Òİ³ö³¾£¬äìÈ÷¾øÂ×\n" NOR,
 MAG "·áÉñ¿¡ÀÊ£¬³¤ÉíÓñÁ¢£¬ÍğÈçÓñÊ÷ÁÙ·ç\n" NOR,
 HIM "ÉñÇåÆøË¬£¬¹Ç¸ñÇåÆæ£¬ÍğÈôÏÉÈË\n" NOR,
 HIM "Ò»ÅÉÉñÈËÆø¶È£¬ÏÉ·çµÀ¹Ç£¬¾ÙÖ¹³ö³¾\n" NOR,
});

string *look_level_girl = ({
  BLU "³óÈçÎŞÑÎ£¬×´ÈçÒ¹²æ\n" NOR,
  BLU "Íá±ÇĞ±ÑÛ£¬Á³É«»Ò°Ü£¬Ö±Èç¹í¹ÖÒ»°ã\n" NOR,
  BLU "°Ë×ÖÃ¼£¬Èı½ÇÑÛ£¬¼¦Æ¤»Æ·¢£¬ÈÃÈËÒ»¼û¾ÍÏëÍÂ\n" NOR,
  HIB "ÑÛĞ¡Èç¶¹£¬Ã¼Ã«Ï¡Êè£¬ÊÖÈçºï×¦£¬²»³ÉÈËÑù\n" NOR,
  HIB "Ò»×ì´ó±©ÑÀ£¬ÈÃÈËÒ»¿´¾ÍÃ»ºÃ¸Ğ\n" NOR,
  NOR "ÂúÁ³¸í´ñ£¬Æ¤É«´ÖºÚ£¬³óÂª²»¿°\n" NOR,
  NOR "¸É»Æ¿İÊİ£¬Á³É«À°»Æ£¬ºÁÎŞÅ®ÈËÎ¶\n" NOR,
  YEL "Éí²ÄÊİĞ¡£¬¼¡·ôÎŞ¹â£¬Á½ÑÛÎŞÉñ\n" NOR,
  YEL "Ëä²»±êÖÂ£¬µ¹Ò²°×¾»£¬ÓĞĞ©¶¯ÈËÖ®´¦\n" NOR,
  RED "¼¡·ôÎ¢·á£¬ÑÅµ­ÎÂÍğ£¬ÇåĞÂ¿ÉÈË\n" NOR,
  RED "ÏÊÑŞåûÃÄ£¬¼¡·ôÓ¨Í¸£¬ÒıÈËåÚË¼\n" NOR,
  HIR "½¿Ğ¡Ááçç£¬ÍğÈç·ÉÑàÔÙÊÀ£¬³ş³ş¶¯ÈË\n" NOR,
  HIR "ÈùÄıĞÂÀó£¬¼¡·ôÊ¤Ñ©£¬Ä¿ÈôÇïË®\n" NOR,
  HIW "·ÛÄÛ°×ÖÁ£¬ÈçÉÖÒ©ÁıÑÌ£¬ÎíÀï¿´»¨\n" NOR,
  HIW "·áĞØÏ¸Ñü£¬Ñıæ¬¶à×Ë£¬ÈÃÈËÒ»¿´¾ÍĞÄÌø²»ÒÑ\n" NOR,
  MAG "½¿Èô´º»¨£¬ÃÄÈçÇïÔÂ£¬ÕæµÄÄÜ³ÁÓãÂäÑã\n" NOR,
  MAG "Ã¼Ä¿Èç»­£¬¼¡·ôÊ¤Ñ©£¬Õæ¿ÉÎ½±ÕÔÂĞß»¨\n" NOR,
  MAG "ÆøÖÊÃÀÈçÀ¼£¬²Å»ªğ¥±ÈÉ½£¬ÁîÈË¼ûÖ®ÍüË×\n" NOR,
  HIM "²ÓÈôÃ÷Ï¼£¬±¦ÈóÈçÓñ£¬»ĞÈçÉñåúÏÉ×Ó\n" NOR,
  HIM "ÃÀÈôÌìÏÉ£¬²»Õ´Ò»Ë¿ÑÌ³¾\n" NOR,
  HIM "ÍğÈç"+HIW+"Óñµñ±ùËÜ"+HIM+"£¬ËÆÃÎËÆ»Ã£¬ÒÑ²»ÔÙÊÇ·²¼äÈËÎï\n" NOR,
});

string *per_msg_kid1 = ({
        CYN "ÔÂÃ¼ĞÇÑÛ£¬ÁéÆøÊ®×ã¡£\n" NOR,
        CYN "»úÁé»îÆÃ£¬ÉñÌ¬·Ç·²¡£\n" NOR,
        CYN "ÃæÈôÇïÔÂ£¬É«ÈçÏş»¨¡£\n" NOR,
});

string *per_msg_kid2 = ({
        CYN "Â¡¶î´óÑÛ£¬Á³É«ºìÈó¡£\n" NOR,
        CYN "ÅÖÅÖà½à½£¬¶ºÈËÏ²»¶¡£\n" NOR,
        CYN "Ï¸Æ¤ÄÛÈâ£¬¿Ú³İÁæÀş¡£\n" NOR,
});

string *per_msg_kid3 = ({
        CYN "Éí²Äïó°«£¬ÉµÀïÉµÆø¡£\n" NOR,
        CYN "·Ê·ÊÅÖÅÖ£¬Ğ¡±ÇĞ¡ÑÛ¡£\n" NOR,
        CYN "´ôÍ·´ôÄÔ£¬±¿ÊÖ±¿½Å¡£\n" NOR,
});

string *per_msg_kid4 = ({
        CYN "ÅîÍ·¹¸½Å£¬Á³»Æ¼¡Êİ¡£\n" NOR,
        CYN "ÉñÈçÄ¾¼¦£¬ÃæÓĞ²¡É«¡£\n" NOR,
        CYN "Îå¹Ù²»Õû£¬ËÄÖ«²»½à¡£\n" NOR,
});

string *pos_msg_yao1 = ({
        HIB "Á³ÉÏÒşÒş·º³öÒ»¹ÉÉ·Æø¡£\n" NOR,
        CYN "ÉñÈçÄ¾¼¦£¬ÃæÓĞ²¡É«¡£\n" NOR,
        CYN "Îå¹Ù²»Õû£¬ËÄÖ«²»½à¡£\n" NOR,
});

string *pos_msg_yao2 = ({
        HIB "ÉíÉÏÎ§ÈÆ×ÅÒ»ÕóºÚÎí¡£\n" NOR,
        CYN "ÉñÈçÄ¾¼¦£¬ÃæÓĞ²¡É«¡£\n" NOR,
        CYN "Îå¹Ù²»Õû£¬ËÄÖ«²»½à¡£\n" NOR,
});

string *pos_msg_yao3 = ({
        HIB "ÉíÉÏÎ§ÈÆ×ÅÒ»ÍÅºÚÔÆ¡£\n" NOR,
        CYN "ÉñÈçÄ¾¼¦£¬ÃæÓĞ²¡É«¡£\n" NOR,
        CYN "Îå¹Ù²»Õû£¬ËÄÖ«²»½à¡£\n" NOR,
});

string *pos_msg_yao4 = ({
        HIB "Õû¸öÁıÕÖÔÚÒ»ÍÅÑıÆøÖ®ÖĞ¡£\n" NOR,
        CYN "ÉñÈçÄ¾¼¦£¬ÃæÓĞ²¡É«¡£\n" NOR,
        CYN "Îå¹Ù²»Õû£¬ËÄÖ«²»½à¡£\n" NOR,
});

string *pos_msg_xian1 = ({
        HIY "Á³ÉÏÏÔ³öÒ»¹ÉÏéºÍÖ®Æø¡£\n" NOR,
        CYN "ÉñÈçÄ¾¼¦£¬ÃæÓĞ²¡É«¡£\n" NOR,
        CYN "Îå¹Ù²»Õû£¬ËÄÖ«²»½à¡£\n" NOR,
});

string *pos_msg_xian2 = ({
        HIY "ÉíÉÏÎ§ÈÆ×ÅÒ»ÍÅÈğÆø¡£\n" NOR,
        CYN "ÉñÈçÄ¾¼¦£¬ÃæÓĞ²¡É«¡£\n" NOR,
        CYN "Îå¹Ù²»Õû£¬ËÄÖ«²»½à¡£\n" NOR,
});

string *pos_msg_xian3 = ({
        HIY "Éí±ßÎ§ÈÆ×ÅÒ»¶äÏéÔÆ¡£\n" NOR,
        CYN "ÉñÈçÄ¾¼¦£¬ÃæÓĞ²¡É«¡£\n" NOR,
        CYN "Îå¹Ù²»Õû£¬ËÄÖ«²»½à¡£\n" NOR,
});

string *pos_msg_xian4 = ({
        HIY "Õû¸öÁıÕÖÔÚ"HIW"Æß"HIR"²Ê"HIM"Ïé"HIC"ÔÆ"HIY"Ö®ÖĞ¡£\n" NOR,
        CYN "ÉñÈçÄ¾¼¦£¬ÃæÓĞ²¡É«¡£\n" NOR,
        CYN "Îå¹Ù²»Õû£¬ËÄÖ«²»½à¡£\n" NOR,
});

// snowcat 12/20/97
string ride_suffix (object me)
{
  string ridemsg = 0;
  object ridee = 0;

  ridee = me->ride();
  if (ridee)
    ridemsg = ridee->query("ride/msg")+"ÔÚ"+ridee->name()+"ÉÏ";
  return ridemsg;
}

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object obj;
	int result;

	if( !arg ) result = look_room(me, environment(me));
	else if( (obj = present(arg, me)) || (obj = present(arg, environment(me)))) {
		if( obj->is_character() ) result = look_living(me, obj);
		else result = look_item(me, obj);
	} else result = look_room_item(me, arg);

	return result;
}

int look_room(object me, object env)
{
	int i;
	object *inv;
	mapping exits;
	string str, str1="", str2="", *dirs;
	string ridemsg = "";

	if( !env ) {
		write("ÄãµÄËÄÖÜ»ÒÃÉÃÉµØÒ»Æ¬£¬Ê²Ã´Ò²Ã»ÓĞ¡£\n");
		return 1;
	}
	  str = sprintf( "%s  %s\n    %s%s",
     env->query("short")?(env->query("outdoors")?""HIC"¡º[2;37;0m"HIW+(string)env->query("short")+NOR+HIC"[36m¡»[2;37;0m"NOR:CYN"¡º[1;30m[4;53m"+(string)env->query("short")+NOR CYN"¡»"NOR): "",
     wizardp(me)?NOR HIR+" ©¤©¤   "NOR MAG+file_name(env)+NOR: "",
     env->query("long")? env->query("long"): "\n",
     env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );

	if( mapp(exits = env->query("exits")) ) {
		dirs = keys(exits);
		for(i=0; i<sizeof(dirs); i++)
			if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
				dirs[i] = 0;
		dirs -= ({ 0 });
		if (env->query("no_look") && !wizardp(me))
			str += CYN"    ÕâÀïµÄ³öÂ·¿´²»Çå³ş¡£\n"NOR;
		else if( sizeof(dirs)==0 )
			str += HIB"    ÕâÀïÃ»ÓĞÈÎºÎÃ÷ÏÔµÄ³öÂ·¡£\n"NOR;
		else if( sizeof(dirs)==1 ) {
			str += "    ÕâÀïÎ¨Ò»µÄ³ö¿ÚÊÇ" + BOLD + dirs[0] + NOR;
			if (env->query("no_look"))
			    	str += "<¿´²»¼û>";
			str += "¡£\n";

		} else {
			str += sprintf("    ÕâÀïÃ÷ÏÔµÄ³ö¿ÚÊÇ " + BOLD + "%s" + NOR + " ºÍ " + BOLD + "%s" + NOR,
				implode(dirs[0..sizeof(dirs)-2], "¡¢"), dirs[sizeof(dirs)-1]);
			if (env->query("no_look"))
			    	str += " <¿´²»¼û>";
			str += "¡£\n";
		} 
	}
//	str += env->door_description();

	inv = all_inventory(env);
	i=sizeof(inv);
	str2 = "";
	while(i--) {
	    	str1 = "";
		if( !me->visible(inv[i]) ) continue;
		if( inv[i]==me ) continue;
		if (env->query("no_look"))
		{
		    	str1 += "  " + "Ä£ºıµÄÓ°×Ó";
			if (! wizardp(me))
			{
			    	str1 += "\n";
				str += str1;
			    	continue;
			}
		}
		if (ridemsg = ride_suffix(inv[i]))
			str1 += "  " + inv[i]->short() + " <"+ridemsg +
			  ">";
		else	
			str1 += "  " + inv[i]->short();
		if (env->query("no_look"))
		    	str1 += " <¿´²»¼û>";
	    	str1 += "\n";
		str2 = str1 + str2;
	}
	write(str+str2);

	return 1;
}

int look_item(object me, object obj)
{
	mixed *inv;

//	write(obj->long());
	me->start_more(obj->long());
	
	//added by weiqi for self-made fabao
	if( obj->query("series_no") && obj->query("fabao") ) 
	    write(obj->show_status());
	
	inv = all_inventory(obj);
	if( sizeof(inv) ) {
		inv = map_array(inv, "inventory_look", this_object() );
		message("vision", sprintf("ÀïÃæÓĞ£º\n  %s\n",
			implode(inv, "\n  ") ), me);
	}
	return 1;
}
string pos_status_msg(int position)
{ 
  // beeby 7/14/2000
  if (position>0)
  {
     if (position<100)
	return (pos_msg_xian1[0]);
     else if (position<500)
         return (pos_msg_xian2[0]);
     else if (position<1000)
        return (pos_msg_xian3[0]);
     else
        return (pos_msg_xian4[0]);
  } else
    {
     if (position>-100)
        return (pos_msg_yao1[0]);
     else if (position>-500)
         return (pos_msg_yao2[0]);
     else if (position>-1000)
        return (pos_msg_yao3[0]);
     else
        return (pos_msg_yao4[0]);
    }
}
string per_status_msg(int age, int per, string gender)
{
   // added by snowcat
   if (age < 14) {
     if ( per>=25 )
        return ( per_msg_kid1[random(sizeof(per_msg_kid1))]);
     else if ( per>=20 )
        return ( per_msg_kid2[random(sizeof(per_msg_kid2))]);
     else if ( per>=15 )
        return ( per_msg_kid3[random(sizeof(per_msg_kid3))]);
     else    return ( per_msg_kid4[random(sizeof(per_msg_kid4))]);
     }
		
	if ( gender == "ÄĞĞÔ" ) {
		if ( per>=10&&per<=30 )
			return ( look_level_boy[per-10]);
		else if (per>30)
		       return ( look_level_boy[20]);
		else return "³¤µÃÔõÑùÄãÃ»Ê²Ã´¸ÅÄî¡£\n";

		}
		
	if ( gender == "Å®ĞÔ" ) {
		if ( per>=10&&per<=29 )
			return ( look_level_girl[per-10]);
		else if (per>29)
		       return ( look_level_girl[20]);
		else return "³¤µÃÔõÑùÄãÃ»Ê²Ã´¸ÅÄî¡£\n";

                }
	else return "";
//	else return "³¤µÃÔõÑùÄãÃ»Ê²Ã´¸ÅÄî¡£\n";
}

int look_living(object me, object obj)
{
	string str, limb_status, ridemsg, pro;
	mixed *inv;
	mapping my_fam, fam;
// added for bian by mon.
	mapping ofamily;
	string ogender,orace;
	int oage;
 
	if(obj->query_temp("d_mana")>0) 
	{
		ofamily=obj->query_temp("family");
		ogender=obj->query_temp("gender");
		orace=obj->query_temp("race");
		oage=obj->query_temp("age");
	} 
	else 
	{
		ofamily=obj->query("family");
		ogender=obj->query("gender");
		orace=obj->query("race");
		oage=obj->query("age");
//fake_age is set as the age when player ²»¶éÂÖ»Ø¡£
//so later on, he/she always looks like the age of that time:)
//but need a "look" to activate all the relatived settings...weiqi
//only when one is not in the status of "bian", check his/her
//fake_age. mon 9/4/97
/*
		if(obj->query("life/live_forever") ) 
		{ 
			//set the fake_age if not set...
			if( obj->query("fake_age") ) obj->set("fake_age", oage);

			if( oage>obj->query("fake_age") ) 
			{
			//if "age" is less than fake_age, reset fake_age.
			//mon 9/4/97
				oage=obj->query("fake_age");
			}
			else if( oage<obj->query("fake_age") ) 
			{
				obj->set("fake_age", oage);
			}
		}
	*/



     if(obj->query("life/live_forever") )
       {
          if (!obj->query("fake_age")) obj->set("fake_age",oage);
         if (oage > obj->query("fake_age")) oage=obj->query("fake_age");       }
     if (obj->query_condition("makeup"))
     if (obj->query("fake_age_x"))
         oage=obj->query("fake_age_x");
//done with fake_age
     }
	if( me!=obj && obj->visible(me) && environment(me) &&
	    !environment(me)->query("no_look") )
		message("vision", me->name() + "Õı¶¢×ÅÄã¿´£¬²»ÖªµÀ´òĞ©Ê²Ã´Ö÷Òâ¡£\n", obj);

	str = obj->long();

	str = replace_string(str, "$n", me->name());
	str = replace_string(str, "$N", obj->name());
    str = replace_string(str, "$C", RANK_D->query_respect(obj));
    str = replace_string(str, "$c", RANK_D->query_rude(obj));
	str = replace_string(str, "$R", RANK_D->query_respect(me));
	str = replace_string(str, "$r", RANK_D->query_rude(me));


	pro = (obj==me) ? gender_self(ogender) : gender_pronoun(ogender);

        if(obj->query_temp("d_mana")==0 || obj->query_temp("is_character")) {
	
	if( orace=="ÈËÀà"
	&&	intp(oage) )
		if(oage<10) {
			str += sprintf("%s¿´ÆğÀ´ÏÔÈ»»¹²»µ½Ê®Ëê¡£\n", pro);
		}
		else{
			str += sprintf("%sÊÇÒ»Î»%s¶àËêµÄ%s¡£\n", pro, chinese_number(oage / 10 * 10),RANK_D->query_respect(obj));
		}

	//check about wife and husband
	if((obj->parse_command_id_list())[0]==me->query("couple/id") ) {
		if( (string)me->query("gender")=="Å®ĞÔ" ){
		str += sprintf("%sÊÇÄãµÄÕÉ·ò¡£\n", pro);
		}
		else{
			str += sprintf("%sÊÇÄãµÄÆŞ×Ó¡£\n", pro);
		}
	}
	// If we both has family, check if we have any relations.
	if( obj!=me
	&&	mapp(fam = ofamily)
	&&	mapp(my_fam = me->query("family")) 
	&&	fam["family_name"] == my_fam["family_name"] ) {
	
		if( fam["generation"]==my_fam["generation"] ) {
			if( ogender == "ÄĞĞÔ" )
				str += sprintf( pro + "ÊÇÄãµÄ%s%s¡£\n",
					my_fam["master_id"] == fam["master_id"] ? "": "Í¬ÃÅ",
					my_fam["enter_time"] > fam["enter_time"] ? "Ê¦ĞÖ": "Ê¦µÜ");
			else
				str += sprintf( pro + "ÊÇÄãµÄ%s%s¡£\n",
					my_fam["master_id"] == fam["master_id"] ? "": "Í¬ÃÅ",
					my_fam["enter_time"] > fam["enter_time"] ? "Ê¦½ã": "Ê¦ÃÃ");
		} else if( fam["generation"] < my_fam["generation"] ) {
			if( member_array(my_fam["master_id"],
			    obj->parse_command_id_list())>-1  )
				str += pro + "ÊÇÄãµÄÊ¦¸¸¡£\n";
			else if( my_fam["generation"] - fam["generation"] > 1 )
				str += pro + "ÊÇÄãµÄÍ¬ÃÅ³¤±²¡£\n";
			else if( fam["enter_time"] < my_fam["enter_time"] )
				str += pro + "ÊÇÄãµÄÊ¦²®¡£\n";
			else
				str += pro + "ÊÇÄãµÄÊ¦Êå¡£\n";
		} else {
			if( fam["generation"] - my_fam["generation"] > 1 )
				str += pro + "ÊÇÄãµÄÍ¬ÃÅÍí±²¡£\n";
			else if( fam["master_id"] == me->query("id") )
				str += pro + "ÊÇÄãµÄµÜ×Ó¡£\n";
			else
				str += pro + "ÊÇÄãµÄÊ¦Ö¶¡£\n";
		}
	}

/*	if( obj->query("max_kee") )
		str += pro + COMBAT_D->eff_status_msg((int)obj->query("eff_kee") * 100 / (int)obj->query("max_kee")) + "\n";
*/

//here, if per>=100, no rong-mao description, it'll be necessary sometimes.
//return special looking first if he/she has one.

	if( obj->query("looking") ){
		str += pro + (string)obj->query("looking") + "\n";
	} else {
	  string looking= per_status_msg((int)obj->query("age"),
	         (int)obj->query_per(), ogender);
              if( strlen(looking)>1 && obj->query("per") < 100 )
        	         str += pro + looking;
	}
	
	ridemsg = ride_suffix(obj);
	if (ridemsg)
		str += pro + "Õı" + ridemsg + "¡£\n";
		
	inv = all_inventory(obj);
	if( sizeof(inv) ) {
		inv = map_array(inv, "inventory_look", this_object(), obj->is_corpse()? 0 : 1 );
		inv -= ({ 0 });
		if( sizeof(inv) )
			str += sprintf( obj->is_corpse() ? "%sµÄÒÅÎïÓĞ£º\n%s\n" : "Ö»¼û%s£º\n%s\n",
				pro, implode(inv, "\n") );
	}
        
	}

        me->start_more(str);

	if( obj!=me 
	&&	living(obj)
	&&	random((int)obj->query("bellicosity")/10) > (int)me->query_per() ) {
		write( obj->name() + "Í»È»×ª¹ıÍ·À´µÉÄãÒ»ÑÛ¡£\n");
		COMBAT_D->auto_fight(obj, me, "berserk");
		return 1;
	}

//this part is  taken from attack.c
//mon 1/22/98
/*
	if( obj!=me 
	&& living(obj)
	&& userp(obj)
        && random((int)obj->query("bellicosity")/40) > (int)obj->query("cps") ) 
	  COMBAT_D->auto_fight(obj, me, "berserk");
*/

	return 1;
}

string inventory_look(object obj, int flag)
{
	string str;
	str = obj->short();
	if( obj->query("equipped") )
		str = HIC "  ¡õ" NOR + do_query(obj);
	else if( !flag )
		str = "    " + str;
	else return 0;
	return str;
}


int look_room_item(object me, string arg)
{
	object env;
	mapping item, exits;

	if( !objectp(env = environment(me)) )
		return notify_fail("ÕâÀïÖ»ÓĞ»ÒÃÉÃÉµØÒ»Æ¬£¬Ê²Ã´Ò²Ã»ÓĞ¡£\n");

	if( mapp(item = env->query("item_desc")) && !undefinedp(item[arg]) ) {
		if( stringp(item[arg]) )
			write(item[arg]);
		else if( functionp(item[arg]) )
			write((string)(*item[arg])(me));
			
		return 1;
	}
    	if (env->query("no_look"))
  		return notify_fail("ÄãÊ²Ã´Ò²¿´²»¼û¡£\n");
	if( mapp(exits = env->query("exits")) && exits[arg] && !undefinedp(exits[arg]) ) {
		if( (objectp(exits[arg]) && env=exits[arg]) ||
		    objectp(env = load_object(exits[arg])) ) {
			look_room(me, env);
			if(!me->query("env/invisibility") && random(3)==0
				&& env!=environment(me) ) {
			    string msg=peep_msg[random(sizeof(peep_msg))];
			    msg=replace_string(msg,"$N",me->name());
			    tell_room(env, msg);
			}
		} else {
		  return notify_fail("[34mÄãÊ²Ã´Ò²¿´²»¼û¡£[2;37;0m\n");
		}
		return 1;
	}
	return notify_fail("[36mÄãÒª¿´Ê²Ã´£¿[2;37;0m\n");
}
string do_query(object obj)
{
        string str,units;

        units =obj->query("unit");
        str = obj->short();
        if (obj->query("armor_type"))
        switch( obj->query("armor_type") ) {
                case "cloth":
                case "armor":
                        str = "Éí´©Ò»"+ units + str;
                        break;
                case "boots":
                        str = "½ÅÉÏ´©×ÅÒ»" + units + str;
                        break;
                case "head":
                case "neck":
                case "wrists":
                case "finger":
                case "hands":
                        str ="´÷×ÅÒ»"+ units + str;
                        break;
                case "waist":
                        str = "Ñü¼ä°óµÃÓĞÒ»"+units+str;
                        break;
                case "flower":
                        str = "Í·ÉÏ´÷×ÅÒ»"+units+str;
                        break;
                default:
                        str = "×°±¸×Å"+str; 
                        }
        else
        if( obj->wield() )
                if (obj->query("skill_type")=="throwing")
                str ="ÉíÉÏ´ø×Å"+str;
                else
                str ="ÊÖ³ÖÒ»" + units + str;
        return str;     
}
int help (object me)
{
	write(@HELP
Ö¸Áî¸ñÊ½: look [<ÎïÆ·>|<ÉúÎï>|<·½Ïò>]
 
Õâ¸öÖ¸ÁîÈÃÄã²é¿´ÄãËùÔÚµÄ»·¾³¡¢Ä³¼şÎïÆ·¡¢ÉúÎï¡¢»òÊÇ·½Ïò¡£
 
HELP
);
	return 1;
}
