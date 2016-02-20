// mon 1/29/98

inherit NPC_SAVE;

mapping list=([]);
// notified is set as static so that it will not
// be saved or restored.
static string *notified=({});

int do_help(string arg);
void clear_enter(string id);
void allow_enter(string id);
int remain_time(int approve);
void inform_wiz (object who);
int do_clear(string arg);
int do_list();
int do_approve (string arg);
void relay_channel(object ob, string channel, string msg);


void create()
{
        set_name("ÏÉÍ¯", ({ "xian tong","tong" }));
        set("long", "");
        set("gender", "ÄĞĞÔ");
        set("age", 15);
        set("attitude", "friendly");
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("per" ,20);
        set("combat_exp", 500000);

        setup();
        carry_object("/d/obj/cloth/xianpao")->wear();
	
	if( clonep() ) CHANNEL_D->register_relay_channel("sys");
	
	reload("guest_room");
}

void init()
{       
        object ob=this_player();
	string id=ob->query("id");
	object me=this_object();
	mapping new_guest;
	int approve;
	
        ::init();
        
	if(!userp(ob)) return;

        if(wizardp(ob)) {
          add_action("do_approve","approve");
          add_action("do_clear","decline");
          add_action("do_list","list");
          add_action("do_help","help");
          call_out ("inform_wiz",1,ob);
        } else {
          approve=ob->query("banned_approved");

          if(!approve) { //first time enter here.
            approve=time(); //current time.
            if(approve<100) approve=-1;
            //this should not happen, but if happened due to
            //incorrect system clock, then set to -1.
            ob->set("banned_approved",approve);
            ob->set("startroom","/d/wiz/guest");
            ob->save();
          }
          
          if(remain_time(approve)==0) {
            allow_enter(id);
            return; 
          }   
          
          write(ob->query("name")+
            "£¬ÇëµÈºòÎ×Ê¦Åú×¼Äú½øÈë[1;32m¡¼ÃÎ»ÃÎ÷ÓÎ¡½[1;0mÊÀ½ç£¡\n");
            
          if(approve>0)  
            write("Èç¹ûÃ»ÓĞÎ×Ê¦ÔÚÏß£¬Äú½«ÔÚ"+
              chinese_number(remain_time(approve))+
              "Ğ¡Ê±ºó×Ô¶¯»ñµÃĞí¿É¡£\n");  
              
          write("ÇëÄÍĞÄµÈºò£¬Ğ»Ğ»£¡\n");
             
          if(approve==-1) return;
          
          if(undefinedp(list[id])) {    
            //add this player to list.
            new_guest=(["name":ob->query("name"),
                        "ip":query_ip_name(ob),
                        "time":approve,
                        ]);
            if(list)
              list+=([id:new_guest]);
            else
              list=([id:new_guest]);
              
            notified=({});
            me->save();                              
          }
         
        }
}

int do_help(string arg)
{
  if(arg) return 0;
  
  write("\n");
  write("Äã¿ÉÒÔÔÚÕâÀï´¦ÀíÓÉbanned_sitesÁ¬ÏßÍæ¼ÒµÄ½øÈëÇëÇó£¬²»\n");
  write("¹ÜÍæ¼ÒÄ¿Ç°ÕıÔÚÓ­¿ÍÌü»òÒÑ¾­ÍË³ö¾ù¿ÉÒÔ¡£Èç¹û²»×÷´¦Àí£¬\n");
  write("Ôò¸ÃÍæ¼Ò½«ÔÚËÄÊ®°ËĞ¡Ê±ºó×Ô¶¯»ñ×¼½øÈëÓÎÏ·¡£\n\n");
  write("approve id      ×¼ĞíÖ¸¶¨Íæ¼Ò½øÈëÓÎÏ·¡£(¼´Ê¹²»ÔÚlist\n");
  write("                ÖĞÒ²¿ÉÒÔ)\n");
  write("approve -all    ×¼ĞíËùÓĞÉêÇëÖĞÍæ¼Ò½øÈëÓÎÏ·¡£\n");
  write("decline id      ²»×¼Ö¸¶¨Íæ¼Ò½øÈëÓÎÏ·¡£Èç¹û¸ÃÍæ¼ÒÊÇ\n");
  write("                newbie£¬½«¿ÉÄÜ±»purge£»·ñÔò½«±»½û\n");
  write("                ±ÕÓÚÓ­¿ÍÌü£¬Ö±µ½ÓĞÎ×Ê¦approveÎªÖ¹¡£\n");
  write("decline -all    Í¬ÉÏ£¬²»×¼ËùÓĞÉêÇëÖĞÍæ¼Ò½øÈëÓÎÏ·¡£\n");
  write("list            ÁĞ³öËùÓĞÕıÔÚÉêÇëÖĞµÄÍæ¼Ò¡£\n");
  write("\n");
  return 1;
}

//clear one player enter xyj.
void clear_enter(string id)
{
  object me=this_object();
  object who;
  int online,objp=wizardp(this_player());
   
    who=find_player(id);
    if(who) { //player online now.
      if(!present(who)) {
        if(objp) write(id+"Ä¿Ç°²»ÔÚÓ­¿ÍÌü¡£\n");
        return;
      }  
      online=1;
    } else { //player not online now.     
      who=new(USER_OB);
      who->set("id",id);
      if(!who->restore()) {
        if(objp) write("Ã»ÓĞ"+id+"Õâ¸öÍæ¼Ò»òÎÄ¼ş³ö´í¡£\n");
	destruct(who);

  if(!undefinedp(list[id])) {
    map_delete(list,id);
    me->save();
  } 
        return;
      }  
      online=0;
    }
  
  if(who->query("banned_approved")!=0) {
    who->set("banned_approved",-1);
    who->save(1);
    if(objp)
      tell_object(this_player(),"Äú²»Åú×¼"+who->query("name")+"½øÈë[1;32m¡¼ÃÎ»ÃÎ÷ÓÎ¡½[1;0mÊÀ½ç£¡\n");
    if(objp)
      log_file("banned_approve","["+ctime(time())+"]"+
        this_player()->query("id")+" declines "+who->query("id")+
	" to enter.\n");
    else
      log_file("banned_approve","["+ctime(time())+"]"+
        who->query("id")+
	" is declined to enter.\n");
	
  } else {
    if(objp) write("Íæ¼Ò"+id+"²»ÔÚ´ıÅú×¼Ö®ÁĞ¡£\n");
  }    
  
  if(online==1) {
  } else {
    destruct(who);
  } 
  
  if(!undefinedp(list[id])) {
    map_delete(list,id);
    me->save();
  } 
}

//allow one player enter xyj.
void allow_enter(string id)
{
  object me=this_object();
  object who;
  int online,objp=wizardp(this_player());
   
    who=find_player(id);
    if(who) { //player online now.
      if(!present(who)) {
        if(objp) write(id+"ÏÖÔÚ²»ÔÚÓ­¿ÍÌü¡£\n");
        return;
      }  
      online=1;
    } else { //player not online now.     
      who=new(USER_OB);
      who->set("id",id);
      if(!who->restore()) {
        if(objp) write("Ã»ÓĞ"+id+"Õâ¸öÍæ¼Ò»òÎÄ¼ş³ö´í¡£\n");
	destruct(who);

  if(!undefinedp(list[id])) {
    map_delete(list,id);
    me->save();
  } 
        return;
      }  
      online=0;
    }
   
  if(who->query("banned_approved")!=0) {
    who->set("banned_approved",1);
    who->set("startroom","/d/city/kezhan");
    who->save(1);
    if(objp)
      tell_object (this_player(),"ÄúÅú×¼"+who->query("name")+"½øÈë[1;32m¡¼ÃÎ»ÃÎ÷ÓÎ¡½[1;0mÊÀ½ç£¡\n");
    if(objp)
      log_file("banned_approve","["+ctime(time())+"]"+
        this_player()->query("id")+" allows "+who->query("id")+
	" to enter.\n");
    else
      log_file("banned_approve","["+ctime(time())+"]"+
        who->query("id")+
	" is allowed to enter.\n");
  } else {
    if(objp) write("Íæ¼Ò"+id+"²»ÔÚ´ıÅú×¼Ö®ÁĞ¡£\n");
  }    
  
  if(online==1) {
    who->move("/d/city/kezhan");
    tell_object (who,"»¶Ó­Äú½øÈë[1;32m¡¼ÃÎ»ÃÎ÷ÓÎ¡½[1;0mÊÀ½ç£¡\n");
  } else {
    destruct(who);
  } 
  
  if(!undefinedp(list[id])) {
    map_delete(list,id);
    me->save();
  } 
}

int remain_time(int approve)
{ 
  int hour=48-(time()-approve)/3600;

  if(approve<0) //i.e., approve==-1
    return approve;  //not auto approve.
  else if(approve==1 || approve==0 || hour<=0)
    return 0; //approved.
  else
    return hour;  //remaining hours to get auto permission.
}  

void inform_wiz (object who)
{
  tell_object (who,who->query("name")+
    "£¬Äã¿ÉÒÔÊ¹ÓÃhelpÀ´²é¿´¿ÉÓÃÖ¸Áî¡£\n");
}

//do not auto permission entry of a player.
//this player must be later explicitly "approved" to enter.
int do_clear(string arg)
{
  object who;
  object me = this_player();
  object where = this_object ();
  string *key;
  int size, i;

  if (!arg)
    return notify_fail ("²»Åú×¼Ë­£¿\n");
    
  if(arg=="-all") { //decline all pending players.
    key=keys(list);
    size=sizeof(key);
    if(size>0) {
      for(i=0;i<size;i++)
        clear_enter(key[i]); 
    }
  } else {  //decline only one player. 
    if (arg == me->query("id")) {
      write("²»Åú×¼Äú×Ô¼º£¿\n");
      return 1;
    }
    clear_enter(arg);
  }
  
  return 1;
}

//list all pending players in memory.
int do_list()
{
   int i, size;
   string *key;
   
   key=keys(list);
   size=sizeof(key);
   if(size>0) {
     write("µÈ´ıÅú×¼½øÈëÓÎÏ·µÄÍæ¼ÒÓĞ£º\n");
     for(i=0;i<size;i++) {
       int j=remain_time(list[key[i]]["time"]);
       
       write(list[key[i]]["name"]+"("+
         key[i]+")ÓÉ"+
         list[key[i]]["ip"]+
         "Á¬Ïß£¬");
       if(j>0)
         write("½«ÓÚ"+j+"Ğ¡Ê±ºó×Ô¶¯»ñ×¼½øÈëÓÎÏ·¡£\n");
       else if(j==0) {//should not happen.           
         write("×Ô¶¯»ñ×¼½øÈëÓÎÏ·¡£\n");
         allow_enter(key[i]);
       } else //j<0
         write("±ØĞë¾­Î×Ê¦Åú×¼²ÅÄÜ½øÈëÓÎÏ·¡£\n");
     }
   } else
     write("Ä¿Ç°Ã»ÓĞµÈ´ıÅú×¼½øÈëÓÎÏ·µÄÍæ¼Ò¡£\n");
     
   return 1;
}

int do_approve (string arg)
{
  object who;
  object me = this_player();
  object where = this_object ();
  string *key;
  int size, i;

  if (!arg)
    return notify_fail ("Åú×¼Ë­£¿\n");
    
  if(arg=="-all") { //allow all pending players.
    key=keys(list);
    size=sizeof(key);
    if(size>0) {
      for(i=0;i<size;i++)
        allow_enter(key[i]); 
    }
  } else {  //allow only one player. 
    if (arg == me->query("id")) {
      write("Åú×¼Äú×Ô¼º£¿\n");
      return 1;
    }
    allow_enter(arg);
  }
  
  return 1;
}

void relay_channel(object ob, string channel, string msg)
{
	string id, wizid;
	object wiz;
	int size;

        size=sizeof(list);
        if(!size) return;
        
	if( !ob || (channel != "sys") ) return;
	
	id=ob->query("id");
	if(id!="logind") return;

	// Don't process our own speech.
	if( ob==this_object() ) return;
	
	if(sscanf(msg,"%*s(%s)ÓÉ%*sÁ¬Ïß½øÈë¡£",wizid)!=3) return;
	
	wizid=lower_case(wizid);
	if(!(wiz=find_player(wizid))) return;
	if(!wizardp(wiz)) return;
	
	if(member_array(wizid,notified)==-1) { //not notified yet.
	  //notify login wiz about pending players in the guest room.
	  tell_object(wiz,"ÏÖÔÚÓĞ"+chinese_number(size)+
	    "Î»Íæ¼ÒÔÚÓ­¿ÍÌüµÈºòÅú×¼£¬ÇëÄú´¦Àí¡£(/d/wiz/guest)\n");
          notified+=({wizid});
        } //each wiz will only be notified once.
}


