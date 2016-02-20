//by tianlin 2001/5/1
//The sourse code is crack from the DHXY. copyright was keep by DHXY.
//We must respect the wizard's 

#include <ansi.h>
#include <net/dns.h>
#include <net/macros.h>
inherit F_DBASE;

mapping channels = ([
   "ftp":  ([      "msg_speak": HIM "【FTP】"HIG"%s："HIG"%s\n" NOR, "wiz_only": 1 ]),
   "sys":   ([   "msg_speak": HIG "【系统】"HIG"%s："HIG"%s\n" NOR, "wiz_only": 1 ]),//by tianlin 修改
   "wiz":   ([   "msg_speak":HIY "【"NOR+WHT"巫师"HIY"】"HIY"%s："HIY"%s\n" NOR,
          	 "msg_emote": HIY "【"NOR+WHT"巫师"HIY"】"HIY"%s\n" NOR,
          	 "wiz_only": 1
            ]),
   "gwiz":  ([  "msg_speak": HIG "【网际巫师】%s："HIG"%s\n" NOR,
                "msg_emote": HIG "【网际巫师】%s\n" NOR,
          	"wiz_only": 1, "intermud": GWIZ, "channel": "CREATOR",
          	"filter": 1,
          	"intermud_emote": 1 
             ]),
   "xyj":   ([   "msg_speak": HIR "【西游记】%s："HIR"%s\n" NOR,
          "msg_emote": HIR "【西游记】%s\n" NOR,
          "intermud": GCHANNEL, "channel": "xyj",
          "filter": (:$1["MUDLIB"]=="A Journey to the West" :) ]),
          
    //只有mudlib的名字是A Journey to the West才能参与连通
  
   "es":   ([   "msg_speak": HIG "【潭际闲聊】%s："HIG"%s\n" NOR,
          	"msg_emote": HIG "【潭际闲聊】%s\n" NOR,
          "intermud": GCHANNEL, "channel": "es",
          "filter": 1 ]), 
   //类似es2的LPMUD都能参与连通
   
   "sldh": ([      "msg_speak": HIC "【水陆大会】"HIC"%s："HIC"%s\n" NOR,
                   "msg_emote": HIC "【水陆大会】"HIC"%s\n" NOR,
           ]),
      
   "chat": ([      "msg_speak": HIC "【闲聊】%s："HIC"%s\n" NOR,
                   "msg_emote": HIC "【闲聊】%s\n" NOR,
                   ]),

//by tianlin 2001.7.1加入拍卖   
"bill":  ([      "msg_speak": HIC "【拍卖】%s："HIC"%s\n" NOR,
                   "msg_emote": HIC "【拍卖】%s\n" NOR,
                    ]),
   //added by vikee           
   "tonggao":   ([   "msg_speak": NOR "【"HIR"通告"NOR"】"HIY"%s："HIY"%s\n" NOR,
        	    "msg_emote": NOR "【"HIR"通告"NOR"】%s\n" NOR,
   	       "notice_only" : 1,
         ]),
   "rumor":([   "msg_speak": HIM "【谣言】%s："HIM"%s\n" NOR,
          	"msg_emote": HIM "【谣言】%s\n" NOR,
          "anonymous": "某人"
        ]),
     //this segment code is gettd from dhxy's program
     "jh":   ([     "msg_speak": HIG "【江湖同盟】"+NOR+HIG+"%s："HIG"%s\n" NOR,
                    "msg_emote": HIG "【江湖同盟】"+NOR+HIG+"%s\n" NOR,
                    "msg_color": NOR+HIG,
                    "intermud": GCHANNEL,
                    "intermud_emote": 1,
                    "channel": "jh",
                    "filter": 1,
                    "omit_address": 0,

        	]),        
    "party":([      "msg_speak": HIG "【门派】%s："HIG"%s\n" NOR,
                     "msg_emote": HIG "【门派】%s" NOR,
                        "party_only": 1
                ]),
    "lover"	:([ "msg_speak": HIM "【情意绵绵】%s："HIM"%s\n" NOR,
				"msg_emote": HIM "【情意绵绵】%s\n" NOR,
				"lover_only":1
		]),
    ]);
string party;
string couple_id;

void create()
{
   seteuid(getuid());  
        set("channel_id", "频道精灵");
}

varargs int do_channel(object me, string verb, string arg, int emote,int allow_chat)
{
   object *ob, couple;
   string *tuned_ch, who, arg1;
   int time,count,count1,last_chat,len;

        if(sizeof(verb)>0)
           if( verb[sizeof(verb)-1] == '*' ) {
     emote = 1;
     verb = verb[0..<2];
   }


   if( !mapp(channels) || undefinedp(channels[verb]) )
     return 0;
//By tianlin@mhxy for 2001.12.15
	 if( !wizardp(me) )
        if( userp(me)) 
        if(me->query("mud_age") < 3600)
           return notify_fail("对不起，本站不支持新手聊天,请1个小时后使用！\n");
	if(  !allow_chat ) {  
     time=time();
     if(me->query("channel/chat_block") &&
       (time-me->query("channel/chat_block"))<0 )
        return notify_fail("你的公用频道被暂时关闭了。\n");
              
         count=me->query("channel/chat_count");
		// if the channel arg contains too many lines,
		// then count more than once. -- mon 8/16/98
		count1=sizeof(explode(" "+arg,"\n"))/3+1;
		// if arg too long, also counts more.
		count1+=sizeof(arg)/200;
		count+=count1;
		last_chat=me->query("channel/last_chat");
                  if (count>2) {
		  count=0;
		  me->set("channel/last_chat",time);
                if( userp(me)) 
	         if( !wizardp(me) )//我设这句话为了给wiz刷屏,xixi,haaa,ah,ya,hoho,grin
		   if (time==last_chat || count1>2) {
		    me->set("channel/chat_block",time+180);
		    return notify_fail("因为一次讲话太多，你的公用频道被暂时关闭了。\n");
		  } 
//by tianlin@mhxy for 2001.8.22修改因为监控精灵经常关闭,所以cut了这句话.
	        } 
		me->set("channel/chat_count",count);  
                
        if ((int)me->query("chblk_es") && verb == "es")
		return notify_fail("对不起！你的网际闲聊频道被关闭了！\n");
	if ((int)me->query("chblk_rumor") && verb == "rumor")
		return notify_fail("对不起！你的谣言频道被关闭了！\n");
	if ((int)me->query("chblk_chat") && verb == "chat")
		return notify_fail("对不起！你的闲聊频道被关闭了！\n");
	if ((int)me->query("chblk_sldh") && verb == "sldh")
		return notify_fail("对不起！你的水陆大会频道被关闭了！\n");
	if ((int)me->query("chblk_xyj") && verb == "xyj")
		return notify_fail("对不起！你的网际闲聊频道被关闭了！\n");
	if ((int)me->query("chblk_jh") && verb == "jh")
		return notify_fail("对不起！你的江湖同盟频道被关闭了！\n");
       if (!stringp(arg) || arg == "") {
		arg = "...";
		if (emote) arg = "嘴里嘀嘀咕咕的不知道在说些什么。";
	}

                if(channels[verb]["wiz_only"] && !wizardp(me)&&userp(me) )
                   return 0; 
                if(channels[verb]["party_only"] && !me->query("family/family_name"))
                   return notify_fail("你还是先加入一个门派再说吧。\n");
                if(channels[verb]["notice_only"] && !wizardp(me))
                return notify_fail("只有管理员才能发通知。\n");
                if (verb=="lover"||verb=="lover*") {
                	
		        if (!me->query("couple/id")) 
			      return notify_fail("你现在还没有伴侣，要跟谁说悄悄话呢？！\n");
		        if(!(couple=find_player(me->query("couple/id"))))
			      return notify_fail("你的伴侣目前不在线上。\n");
			      couple_id=me->query("id");
	        }  
                if (channels[verb]["party_only"]){
                party = me->query("family/family_name");
                channels[verb]["msg_speak"] = HIG "【"HIW+party+HIG"】%s：%s\n" NOR;
                channels[verb]["msg_emote"] = HIG "【"HIW+party+HIG"】%s\n" NOR;
            }
     
    // check if this channel support emote message. 
    if( emote && undefinedp(channels[verb]["msg_emote"])  ) {
        write("对不起，这个频道不支持 emote 。\n");
        return 1;
    }
     tuned_ch = me->query("channels");
     if( !pointerp(tuned_ch) )
        me->set("channels", ({ verb }) );
     else if( member_array(verb, tuned_ch)==-1 )
        me->set("channels", tuned_ch + ({ verb }) );

     if( emote &&me->is_character()&& !channels[verb]["intermud_emote"]) {
        string vb, emote_arg;

        if( nullp(arg) ) return 0;
        if( sscanf(arg, "%s %s", vb, emote_arg)!= 2 ) {
          vb = arg;
          emote_arg = "";
        }
   if( arg == me->query_temp("last_channel_msg") )
		return notify_fail("用公共频道说话请不要重复相同的讯息。\n");
     if( channels[verb]["anonymous"] )
           arg = EMOTE_D->do_emote(me, vb, emote_arg, 1, 1);
               else {
		   arg = EMOTE_D->do_emote(me, vb, emote_arg, 1, 0,
                       !undefinedp(channels[verb]["intermud"]));
                   if(!arg) {
                      string id, site;
                      if(sscanf(emote_arg, "%s@%s", id, site)==2) {
			int age=me->query("mud_age");
			// prevent login  newbie to flood channels.
			if(!wizardp(me)) {
			    if(age<3600) return notify_fail(
				    "");
			    else if(age<86400) {
				if((int)me->query("sen")<30) return 
				    notify_fail
					("");
				me->add("sen",-5);
			    }
			}

			"/adm/daemons/network/services/gemote_q"->
			send_msg(channels[verb]["channel"], me,
			vb, id, site, channels[verb]["filter"]);
                        return 1;
		      }
                   }
                }

     if( !arg ) return 0;
     }
   }
   if( channels[verb]["anonymous"] ) {
		who = channels[verb]["anonymous"];
		if (userp(me)) {
		    if((int)me->query("sen")<50) return
			notify_fail("你已经没有精神散布谣言了。\n");
		    me->add("sen",-5);
                  do_channel( this_object(), "sys", 
		    sprintf("谣言：%s(%s)。", me->name(1),me->query("id")));
		}
	}
	else if( userp(me) || !stringp(who = me->query("channel_id")) ) {
		who = me->query("name");
		if(me->query("id")) 
		  who=who+"(" + capitalize(me->query("id")) + ")";
             }



   ob = filter_array( users(), "filter_listener", this_object(), channels[verb] );


   len=strlen(arg);
   while(len>1 && arg[len-1]=='\n')
       arg=arg[0..((len--)-2)];

        if(userp(me)) arg1=replace_string(arg, "$N", me->name());
        else arg1=arg;

   if( emote ) {
     if( channels[verb]["intermud_emote"] ) arg1 = who + " " + arg;

     message( "channel:" + verb,
        sprintf( channels[verb]["msg_emote"], arg1 ), ob );
   } else
     message( "channel:" + verb,
        sprintf( channels[verb]["msg_speak"], who, arg1 ), ob );
   if( arrayp(channels[verb]["extra_listener"]) ) {
     channels[verb]["extra_listener"] -= ({ 0 });
     if( sizeof(channels[verb]["extra_listener"]) )
        channels[verb]["extra_listener"]->relay_channel(me, verb, arg);
   }
   
   if( !undefinedp(channels[verb]["intermud"])
   &&   base_name(me) != channels[verb]["intermud"] ) {
          if(userp(me)) {
          	 int age=me->query("mud_age");
            arg=replace_string(arg, "$N", me->name()+"("+
                capitalize(me->query("id"))+"@"+Mud_name()+")",1);
            arg=replace_string(arg, "$N", me->name());

      
         if(!wizardp(me)) {
	      if(age<3600) return notify_fail("");
	      else if(age<86400) {
		if((int)me->query("sen")<30) return 
		    notify_fail
			("");
		me->add("sen",-5);
	      }
	    }
          }
     channels[verb]["intermud"]->send_msg(
     channels[verb]["channel"], me->query("id"), 
                   me->name(1), arg, emote, channels[verb]["filter"] );
        }

   if (userp(me) && !wizardp(me)) {
		if (stringp(me->query_temp("last_channel_msg"))
			&& (strsrch(arg, me->query_temp("last_channel_msg")) >= 0
			|| strsrch(me->query_temp("last_channel_msg"), arg) >= 0))
			
			me->add_temp("channel_repeat", 1);
			
		else me->delete_temp("channel_repeat");
		
               if (me->query_temp("channel_repeat") > 4 ) {
               	       if(verb!="sys")
               	       {
			me->set("chblk_"+verb, 1);
			switch (verb) {
					case "chat": verb = "闲聊"; break;
					case "rumor": verb = "谣言"; break;
					case "sldh": verb = "水陆大会"; break;
					case "es": verb = "网际闲聊"; break;
					case "xyj": verb = "网际西游"; break;
					case "jh": verb = "江湖同盟"; break;
					default: verb = "交谈";
			}
			
			
			do_channel(this_object(), "rumor",
				"由于讲话太罗嗦，" + me->name(1) + "("+capitalize(me->query("id"))+")的" + verb + "频道被关闭了。");
		}}
			
		me->set_temp("last_channel_msg", arg);
		
		if (me->add_temp("channel_count", 1) > 1) {
			me->delete_temp("channel_count");
			if (me->query_temp("last_channel_time") == uptime()) {
				me->set("chblk_"+verb, 1);
				switch (verb) {
					case "chat": verb = "闲聊"; break;
					case "rumor": verb = "谣言"; break;
					case "sldh": verb = "水陆大会"; break;
					case "es": verb = "网际闲聊"; break;
					case "xyj": verb = "网际西游"; break;
					case "jh": verb = "江湖同盟"; break;
					default: verb = "交谈";
				}
				do_channel(this_object(), "rumor",
					"由于讲话太多太快，" + me->name(1) + "("+capitalize(me->query("id"))+")的" + verb + "频道被关闭了。");
			}
			me->set_temp("last_channel_time", uptime());
		}
	}

   return 1;
}



int filter_listener(object ppl, mapping ch)
{
   // Don't bother those in the login limbo.
   if( !environment(ppl) ) return 0;
   if( ch["wiz_only"] ) return wizardp(ppl);
   //只有本门能看。
   if( ch["party_only"] )  
   {   
        if ( !wizardp(ppl) && party != ppl->query("family/family_name") ) return 0;
   }
   //只有夫妻能看
   if( ch["lover_only"])
   {
   	if ( !wizardp(ppl) && couple_id !=ppl->query("couple/id") 
   	&& couple_id !=ppl->query("id")  ) return 0;
   }	
   return 1;
}

void register_relay_channel(string channel)
{
   object ob;

   ob = previous_object();
   if( undefinedp(channels[channel]) || !ob) return;
   if( arrayp(channels[channel]["extra_listener"]) ) {
     if( member_array(ob, channels[channel]["extra_listener"]) >=0 ) return;
     channels[channel]["extra_listener"] += ({ ob });
   } else
     channels[channel]["extra_listener"] = ({ ob });
}


