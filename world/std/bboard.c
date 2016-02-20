//Creat by waiwai@2000/12/22 ÖØĞÂ½¨Á¢.
//By waiwai@2001/03/06 ÉèÖÃ½ûÖ¹,Ôö¼ÓÉ«²ÊÖ§³Ö.
//ÉèÖÃµÄÍæ¼Ò°æÖ÷¿ÉÒÔÈÎÒâµÄÉ¾³ıÁôÑÔ°åµÄÌû×Ó
//µ«ÊÇÎ×Ê¦¼ÓÁËËøµÄÌû×ÓÊÇ²»ÄÜ±»É¾³ıµÄ
//¼ÓÈëÍæ¼Ò°æÖ÷¿ÉÒÔ°ÑÖ°Î»×ªÈÎ¸ø±ğÈË¡£
//¼ÓÈëÍæ¼Ò°æÖ÷¿ÉÒÔ·ÅÆú×Ô¼ºµÄ°æÖ÷Ö°Î»¡£
// ¼ÓÈë×ªĞÅ¹¦ÄÜ
//Last modified by waiwai@2001/06/28
#include <ansi.h>
#include <mudlib.h>
#include <command.h>

#define BOARD_CAPACITY query("capacity")
#define MAILBOX "/obj/mailbox"

inherit ITEM;
inherit F_SAVE;
string query_master();

void setup()
{
       string loc;

       if( stringp(loc = query("location")) ) move(loc);
       set("no_get", 1);

       restore();
}

void init()
{
       add_action("do_post", "post");
       add_action("do_read", "read");
       add_action("do_discard", "discard");
       add_action("do_appoint","banzhu");
       add_action("do_demit","bamian");
       add_action("do_lock", "lockb");
       add_action("do_unlock", "unlockb");
       add_action("do_forward", "zhuanxin");
}

string query_save_file()
{
       string id;

       if( !stringp(id = query("board_id")) ) return 0;
       return DATA_DIR + "board/" + id;
}

string query_master()
{
       if( query("master") )
               return query("master");
       else
               return "ÉĞÎ´ÈÎÃü";
}

string short()
{
       mapping *notes;
       int i, unread, last_read_time;

       notes = query("notes");
       if( !pointerp(notes) || !sizeof(notes) )
               return ::short() + " ["CYN" Ã»ÓĞÈÎºÎÁôÑÔ   "CYN"±¾°å°æÖ÷£º"HIY+query_master()+NOR" ]";

       if( this_player() ) {
               last_read_time = (int)this_player()->query("board_last_read/" + (string)query("board_id"));
               for(unread = 0, i=sizeof(notes)-1; i>=0; i--, unread ++)
                       if( notes[i]["time"] <= last_read_time ) break;
       }
       if( unread )
return sprintf("%s"NOR" ["HIR" %d"NOR+CYN" ÕÅÁôÑÔ£¬"HIC"%d"NOR+CYN" ÕÅÎ´¶Á   "CYN
"±¾°å°æÖ÷£º"HIY+query_master()+NOR" ]", ::short(), sizeof(notes), unread);
       else
    return sprintf("%s"NOR" [ "HIR"%d"NOR+CYN" ÕÅÁôÑÔ   "CYN"±¾°å°æÖ÷£º"HIY+query_master()+NOR
" ]", ::short(), sizeof(notes));
}

string long()
{
  mapping *notes;
  int i, last_time_read;
  string msg, myid;

  notes = query("notes");
  msg=sprintf(HBBLU HIY" ±¾°æ°æÖ÷£º%-10s                                        %-20s \n"NOR,
               query_master(),query("name"));
  msg+="[1;44mĞòºÅ   ¶ÁÈ¡      Áô ÑÔ Ê± ¼ä       ÁôÑÔÈË                    Áô  ÑÔ  Ö÷  Ìâ       [m\n";

  if( !pointerp(notes) || !sizeof(notes) ) return query("long");

  last_time_read = this_player()->query("board_last_read/" + (string)query("board_id"));

  for(i=sizeof(notes)-1; i>=0; i--)
    msg += sprintf("[%3d] %4s  [%s] %-20s Ö÷Ìâ¡ú %s\n",
      i+1, ( notes[i]["time"] > last_time_read ? HIR"(Î´¶Á)"NOR: WHT"(ÒÑ¶Á)"NOR),
BJTIME_CMD->chinese_time(7, ctime(notes[i]["time"])),
notes[i]["author"], notes[i]["title"]);
  msg+="[1;44mĞòºÅ   ¶ÁÈ¡      Áô ÑÔ Ê± ¼ä       ÁôÑÔÈË                    Áô  ÑÔ  Ö÷  Ìâ       [m\n";
msg+=HBBLU HIY" »¶Ó­¹âÁÙ"+INTERMUD_NAME+"                        ±¾Õ¾µØÖ·£º211.97.194.141 6666     \n"NOR;

  return msg;
}

//By waiwai@2001/03/05 changed.
int do_appoint(string arg)
{
       object me = this_player();

  if( (string)SECURITY_D->get_status(this_player(1)) != "(admin)"
   && (string)SECURITY_D->get_status(this_player(1)) !="(arch)"
 //  && me->query("id")!="gslxz"
 //  && me->query("id")!="waiwai"
 //  && me->query("id")!="suannai"
 && query("master")!=this_player(1)->query("id"))
   return notify_fail("ÄãÃ»ÓĞÎ¯ÈÎ°æÖ÷µÄÈ¨Àû!\n");
   
   if( wizardp(me) ) {
   if( !arg)
       return notify_fail("ÄãÒªÎ¯ÈÎË­Îª±¾°æ°æÖ÷£¿\n");
} else {
   if( !arg)
       return notify_fail("ÄãÒª½«±¾°æ°æÖ÷Ö°Î»×ªÈÎ¸øË­£¿\n");
}
   if( !present(arg,environment(me) ) )
       return notify_fail("ÄãÒªÈÎÃüµÄÍæ¼Ò²»ÔÚÕâ¸öµØ·½£¡\n");

//    if(this_object()->query("master") )
//                return notify_fail("Õâ¸ö°æÒÑ¾­ÓĞ°æÖ÷ÁË£¡\n");

   if( ! wizardp(me) && userp(me) ) {

}
   this_object()->set("master",arg);

   if( wizardp(me) ) 
   message("system",HIR"¡¾°æÖ÷¹«¸æ¡¿"+me->query("name")+"ÈÎÃü "HIG+arg+HIR" Îª "HIW+this_object()->name()+HIR" °æÖ÷£¡\n"NOR,users());
else
   message("system",HIR"¡¾°æÖ÷¹«¸æ¡¿ÏÖÈÎ"+this_object()->name()+HIR"°æÖ÷"+me->query("name")+"½«°æÖ÷Ö°Î»×ªÈÎ¸ø"+arg+"£¡\n"NOR,users());

    log_file("static/zhuanren",sprintf("%s(%s)½«%s°æÖ÷Ö°Î»×ªÈÎ¸ø%s Ê±¼äÔÚ: (%s) \n",
me->name(1),geteuid(me),this_object()->name(),arg,
COLOR_D->clean_color(BJTIME_CMD->chinese_time(7, ctime(time()) )  ))); 

   save();      
 return 1;
}

//By waiwai@2001/03/05 changed.
int do_demit()
{
       object me = this_player();

  if( (string)SECURITY_D->get_status(this_player(1)) != "(admin)"
   && (string)SECURITY_D->get_status(this_player(1)) !="(arch)"
 //  && me->query("id")!="gslxz"
 //  && me->query("id")!="waiwai"
 //  && me->query("id")!="suannai"
&& query("master")!=this_player(1)->query("id"))

   return notify_fail("ÄãÃ»ÓĞ°ÕÃâ°æÖ÷µÄÈ¨Àû!\n");

   if(!this_object()->query("master") )
               return notify_fail("Õâ¸ö°æ±¾À´¾ÍÃ»ÓĞ°æÖ÷£¡\n"); 

   if( wizardp(me) ) 
   message("system",HIR"¡¾°æÖ÷¹«¸æ¡¿"+me->query("name")+"°ÕÃâÁË "HIW+this_object()->name()+HIR" °æÖ÷ "+                   this_object()->query("master") +" £¡\n"NOR,users());
else
   message("system",HIR"¡¾°æÖ÷¹«¸æ¡¿"+me->query("name")+"·ÅÆúÁË "HIW+this_object()->name()+HIR" °æÖ÷µÄÖ°Î» £¡\n"NOR,users());

   this_object()->delete("master");
   save();
 return 1;
}

void done_post(object me, mapping note, string text)
{
            mapping m;
       mapping *notes;
       int i;
       string msg="";

       note["time"] = time();

      if (me->query("signature")) {
               note["msg"]=COLOR_D->replace_color(text+HIB"\n
©¤©¤©¤©¤ ¸ö ©¤©¤ ĞÔ ©¤©¤ Ç© ©¤©¤ Ãû ©¤©¤©¤©¤\n\n"NOR+me->query("signature"),1);
       }
       else note["msg"]=COLOR_D->replace_color(text,1);  

       notes = query("notes");
       if( !pointerp(notes) || !sizeof(notes) )
               notes = ({ note });
       else
               notes += ({ note });

       if( sizeof(notes) > BOARD_CAPACITY )
               notes = notes[BOARD_CAPACITY / 4 .. BOARD_CAPACITY];//×Ô¶¯É¾³ıÊıÄ¿Îª1/4.

       set("notes", notes);
       save();
  for(i=sizeof(notes)-1; i>=0; i--)

       note["msg"] = HIG"À´×Ô "+HIR + ::short() + HIY+"  ÄÚÈİÈçÏÂ:\n\n" NOR+ text;
//       this_player()->edit( (: done_post, this_player(), note :));
//       "/obj/board/post_b"->done_post(me, note);
       restore();
       tell_object(me, HIC"ÁôÑÔÍê±Ï¡£\n"NOR);
message("channel:sys", HIW"¡¾ÏµÍ³¡¿"+me->name()+"("+me->query("id")+")¸Õ¸ÕÔÚ"HIG+::short()+HIW
"·¢±íÁËÒ»¸öÌû×Ó¡£\n\n"NOR, users());

       return;
}

int do_post(string arg)
{
       mapping note;
       object me;
       me = this_player();

  //By waiwai@2001/02/26 ÉèÖÃ½ûÖ¹(post_limit²ÎÊıÒÔºó½«Öğ½¥Ìæ»»Îªwiz_board)
  if(!wizardp(me) && environment(me)->query("post_limit"))
     return notify_fail("Ö»ÓĞÎ×Ê¦²Å¿ÉÒÔÔÚÕâÀïÁôÑÔ¡£\n");

  if(!wizardp(me) && environment(me)->query("wiz_board"))
     return notify_fail("Ö»ÓĞÎ×Ê¦²Å¿ÉÒÔÔÚÕâÀïÁôÑÔ¡£\n");

  if(!arg) return notify_fail("ÁôÑÔÇëÖ¸¶¨Ò»¸ö±êÌâ¡£\n");
  if(strlen(arg) > 20 ) return notify_fail("±êÌâ¹ı³¤£¡\n");

  if( me->query("no_board") && !wizardp(me)) //By waiwai@2001/06/28
        return notify_fail("ÄãÒÑ¾­±»°ş¶áÁËÔÚÈÎºÎÁôÑÔ°åÁôÑÔµÄ×Ê¸ñ¡£\n");

   //By waiwai@2001/03/06 ÉèÖÃ½ûÖ¹
   if((int)me->query_skill("literate",1) < 30 && !wizardp(me))
 return notify_fail("ÄãµÄ¶ÁÊéÊ¶×ÖĞ¡ÓÚ30,Ã»ÓĞÔÚÕâ¸ö°æÁôÑÔµÄÈ¨Àû¡£\n");

   if ( time() - me->query_temp("last_time/post") < 600 && !wizardp(me))
 return notify_fail("ÄãÖ»ÄÜÔÚÉÏ´ÎÁôÑÔ10·ÖÖÓÒÔºó²Å¿ÉÒÔÔÙÁôÑÔ¡£\n");

      me->set_temp("last_time/post",time());

      note = allocate_mapping(4);
      note["title"] = arg;
note["author"] = this_player()->query("name")+
"("+capitalize(this_player()->query("id"))+")";//By waiwai@2001/03/05 changed.
       this_player()->edit( (: done_post, this_player(), note :));
       return 1;
}

int do_read(string arg)
{
       int num;
       mapping *notes, last_read_time;
       string myid;

       last_read_time = this_player()->query("board_last_read");
       myid = query("board_id");
       notes = query("notes");

       if( !pointerp(notes) || !sizeof(notes) )
               return notify_fail("ÁôÑÔ°åÉÏÄ¿Ç°Ã»ÓĞÈÎºÎÁôÑÔ¡£\n");

       if( !arg ) return notify_fail("Ö¸Áî¸ñÊ½£ºread <ÁôÑÔ±àºÅ|new|next>\n");
       if( arg=="new" || arg=="next" ) {
               if( !mapp(last_read_time) || undefinedp(last_read_time[myid]) )
                       num = 1;
               else
                       for(num = 1; num<=sizeof(notes); num++)
                               if( notes[num-1]["time"] > last_read_time[myid] ) break;

       } else if( !sscanf(arg, "%d", num) )
               return notify_fail("ÄãÒª¶ÁµÚ¼¸ÕÅÁôÑÔ£¿\n");

       if( num < 1 || num > sizeof(notes) )
               return notify_fail("ÒÑ¾­Ã»ÓĞÎ´¶ÁµÄ¸üĞÂÁôÑÔ¡£\n");
       num--;
       this_player()->start_more( sprintf("\n\n%s\n"HIM"ÁôÑÔÖ÷Ìâ£º %s\n"HIY"Áô ÑÔ ÈË£º %s\n"
HIW"ÁôÑÔÊ±¼ä£º %s\n"NOR WHT
       "©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥\n"NOR,
               BBLU HIG+query("name")+NOR HIG" µÚ "HIR+chinese_number(num + 1)+HIG" ºÅÁôÑÔ"NOR, 
               notes[num]["title"], notes[num]["author"],
BJTIME_CMD->chinese_time(1, ctime(notes[num]["time"])))
               + notes[num]["msg"]+NOR
       WHT"©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥"HIY"["HIC"ÃÎ»ÃÎ÷ÓÎ"HIY"] \n"NOR, );

       if( !mapp(last_read_time) )
               this_player()->set("board_last_read", ([ myid: notes[num]["time"] ]) );
       else 
               if( undefinedp(last_read_time[myid]) || notes[num]["time"] > last_read_time[myid] )
                       last_read_time[myid] = notes[num]["time"];

       return 1;
}

//By waiwai@2001/03/05 changed.
int do_discard(string arg)
{
mapping *notes;
int num;
object me = this_player();
int n_start,n_end=0;
if( !arg || (sscanf(arg, "%d to %d", n_start,n_end)!=2 
  && sscanf(arg,"%d",n_start)!=1))
return notify_fail("Ö¸Áî¸ñÊ½£ºdiscard <ÁôÑÔ±àºÅ>\n");
notes = query("notes");
if (n_end==0) n_end=n_start;
if( !arrayp(notes) || n_start < 1 || n_end > sizeof(notes) )
return notify_fail("Ã»ÓĞÕâÕÅÁôÑÔ¡£\n");
num=n_end;
while(num>=n_start) {
num--;
if( notes[num]["author"] != 
 (string) this_player(1)->query("name")+
 "("+capitalize(this_player(1)->query("id"))+")"
&& query("master")!=this_player(1)->query("id")
//&& me->query("id")!="gslxz"
//&& me->query("id")!="waiwai"
//&& me->query("id")!="suannai"
&& (string)SECURITY_D->get_status(this_player(1)) != "(admin)" ) {
      write(sprintf("µÚ"HIR"%d"NOR"ºÅÁôÑÔ²»ÊÇÄãĞ´µÄ,ÄãÓÖ²»ÊÇ°æÖ÷¡£\n",num));
return 1;
}
}

       if(notes[num]["lock"]){
               return notify_fail("ÕâÕÅÁôÑÔ±»¼ÓËøÁË,ÇëÏÈ½âËø "HIR"(unlockb) \n"NOR);
       }

if (n_start >1)
            notes = notes[0..num-1] + notes[n_end..sizeof(notes)-1];
       else
         notes =notes[n_end..sizeof(notes)-1];
set("notes", notes);
save();
write("É¾³ıµÚ " HIR+ (n_start) +NOR " ºÅµ½µÚ "HIR+(n_end)+NOR" ºÅÁôÑÔ....Ok¡£\n");
log_file("static/POSTING", COLOR_D->clean_color(BJTIME_CMD->chinese_time(7,ctime( time()) ))+": "
               +me->query("name")+"("+me->query("id")+")"
+" É¾³ıÁË"+::short()+"µÄµÚ"+(n_start)+"µ½"+(n_end)+"ºÅÁôÑÔ¡£\n");
 CHANNEL_D->do_channel(this_object(),"sys",this_player(1)->name()+"("+this_player(1)->query("id")+")"+" É¾³ıÁË"+::short()+"µÄµÚ"+(n_start)+"µ½"+(n_end)+"ºÅÁôÑÔ¡£\n",);
   write("É¾³ıµÚ " + (num+1) + " ºÅÁôÑÔ....Ok¡£\n");

return 1;
}

//By waiwai@2001/04/25 added.
int do_lock(string arg)
{
       mapping *notes;
       int num;
       
       if( !arg || sscanf(arg, "%d", num)!=1 )
               return notify_fail("Ö¸Áî¸ñÊ½£ºlockb <ÁôÑÔ±àºÅ>\n");
       notes = query("notes");
       if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
               return notify_fail("Ã»ÓĞÕâÕÅÁôÑÔ¡£\n");
       num--;
       if(notes[num]["lock"]){
               return notify_fail("ÕâÕÅÁôÑÔÒÑ¾­¼ÓËøÁË¡£\n");
       }
       if( !wizardp( this_player(1)) ) return notify_fail("ÄãÃ»È¨¼ÓËø¡£\n");
       notes[num]["lock"]=1;
       set("notes", notes);
       save();
       write("¼ÓËø...µÚ " HIR+ (num+1) +NOR " ºÅÁôÑÔ....³É¹¦¡£\n");
       return 1;

}

//By waiwai@2001/04/25 added.
int do_unlock(string arg)
{
       mapping *notes;
       int num;
       
       if( !arg || sscanf(arg, "%d", num)!=1 )
               return notify_fail("Ö¸Áî¸ñÊ½£ºunlockb <ÁôÑÔ±àºÅ>\n");
       notes = query("notes");
       if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
               return notify_fail("Ã»ÓĞÕâÕÅÁôÑÔ¡£\n");
       num--;
       if(!notes[num]["lock"]){
               return notify_fail("ÕâÕÅÁôÑÔÃ»ÓĞ¼ÓËø¡£\n");
       }
       if( !wizardp( this_player(1)) ) return notify_fail("ÄãÃ»È¨½âËø¡£\n");
       notes[num]["lock"]=0;
       set("notes", notes);
       save();
       write("½âËø...µÚ " HIR+ (num+1) +NOR " ºÅÁôÑÔ....Ok¡£\n");
       return 1;
}

//By waiwai@2001/05/01 added.
int do_forward(string arg)
{
       mapping *notes;
       mapping m;
       int num;
       string dest;
       object me;
       me = this_player();
       
if((int)me->query_skill("literate",1) < 30 && !wizardp(me))
 return notify_fail("ÄãµÄ¶ÁÊéÊ¶×ÖĞ¡ÓÚ30,»¹Ã»ÓĞ×ªĞÅµÄÈ¨Àû¡£\n");

        if ( time() - me->query_temp("last_time/zhuanxin") < 1800 && !wizardp(me))
 return notify_fail("ÄãÖ»ÄÜÔÚÉÏ´Î×ªĞÅ30·ÖÖÓÒÔºó²Å¿ÉÒÔÔÙ´Î×ªĞÅ¡£\n");

       me->set_temp("last_time/zhuanxin",time());

       if( !arg || sscanf(arg, "%d %s", num, dest)!=2 )
            return notify_fail("ÄãÒª½«ÄÄÒ»ÕÅÁôÑÔ×ª¼Ä¸ø±ğÈË£¿"HIR"( ¸ñÊ½£ºzhuanxin ÁôÑÔ±àºÅ ¶Ô·½id )\n"NOR);

       notes = query("notes");
       if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
               return notify_fail("Ã»ÓĞÕâÕÅÁôÑÔ¡£\n");
       num--;

       m = ([]);
       m["title"] = notes[num]["title"];
       m["text"] = notes[num]["msg"];
       m["time"] = notes[num]["time"];
       m["from"] = "/ĞÅÏ¢À´Ô´£º"+::short()+",×ª¼Ä×Ô" + this_player()->query("name")+"("+this_player()->query("id")+")";
       m["to"] = dest;
       MAILBOX->send_mail( dest, m );
       write("OK!\n");
   //By waiwai@2001/06/05 Ôö¼Ó¼à¿ØÒÔ¼°log.
    log_file("static/zhuanxin",sprintf("%s(%s)ÓÃ×ª·¢ĞÅ¼ş¹¦ÄÜ×ª·¢"+::short()+"
Ö÷ÌâÎª"+m["title"]+"µÄÁôÑÔ¸ø"+m["to"]+"  Ê±¼äÔÚ: (%s) \n",
me->name(1),geteuid(me),COLOR_D->clean_color(BJTIME_CMD->chinese_time(7, ctime(time()))) ) ); 
message("channel:sys", HIW"¡¾ÌìÉñÖ®ÑÛ¡¿"+me->name()+"("+me->query("id")+")ÕıÔÚ×ª·¢"HIG+::short()+HIW"Ö÷ÌâÎª
\t\t\t  "HIR+m["title"]+HIW" µÄÁôÑÔ¸ø"HIY+m["to"]+"\n"NOR, users());

       return 1;
}


