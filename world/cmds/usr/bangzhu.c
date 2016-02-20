// modified by ammy,ÒÆÖ²µ½ÑýÉñÖ®ÕùÖÐ ²¢ÐÞÕý²¿·Ö¹¦ÄÜ
//By tianlin@mhxy for 2001.10.7ÐÞ¸Ä,°ÑhostÖÆ×÷µÄºÏ²¢Ò»ÏÂ
#include <mudlib.h>
#include <ansi.h>
#include <login.h>
#include "/doc/help.h"
int help(object me);

/*¶¨ÒåÆäËûÎÄµµµÄËùÔÚÄ¿Â¼*/
#define DIR "/data/bbs/"
/*¶¨Òå±¾ÎÄ¼þµÄ´æµµËùÔÚµÄÄ¿Â¼*/
#define POST DIR "post.o"
/*¶¨ÒåÍæ¼ÒregisterÎÄ¼þËùÔÚÄ¿Â¼*/
#define REGISTER DIR+"register/"
/*¶¨Òå¸÷ÖÖÁôÑÔ°åËùÔÚÄ¿Â¼*/
#define BOARD "/obj/board/"
/*boardµÄÖ÷´æÎÄ¼þ*/
#define BOARDCENTER BOARD+"center.h"
/*¶¨ÒåÄÜ¶Ô±¾ÏµÍ³½øÐÐÐÞ¸ÄµÄÎ×Ê¦µÈ¼¶*/
#define WIZLEVEL "(wizard)"
inherit ITEM;
inherit F_SAVE;
int found;
varargs void display(object ob);
void auto_load();
int search_dir(string *dirs, string arg, object me, int wildcard, int wizp);
int find_sub(mixed *filename);
void view_main();
void view_main_1();
void m_display();
void u_display();
void view6();
void view7(string arg);
void do_discard(object ob);
void do_more(string arg,string *text,int line,object ob);
void getname1(string arg);
void getname3(string arg);
void getname2(string str,string arg);
void delfile(string arg);
private void confirm_main_choice(string arg);
private void confirm_p_choice(string arg,object ob);
private void confirm_k_choice(string arg);
private void confirm_l_choice(string arg);
private void confirm_choice(string arg);
private void a(string arg, string register);
private void b(string arg, string register);
private void c(string arg, string register);
private void d(string arg, string register);
private void e(string arg, string register);
private void f(string arg, string register);
private void g(string arg, string register);
private void y(string arg, string register);
private void confirm_u_choice(string arg);
string *default_search = DEFAULT_SEARCH_PATHS;
string age_string(int time);
string hostname(object me);
int do_post(string arg,object ob);
int wizlist();
int message();
int message1();
string query_save_file()
{
        return POST;
}
void create()
{
        set("name","½­ºþ¼ÄÓï");
        mkdir(DIR);
        mkdir(REGISTER);
        restore();
        rm(BOARDCENTER);
        save();
}

int start_help(string msg,object ob)
{
        if(!ob) ob=this_object();
        do_more("d",explode(msg, "\n"),0,ob);
}
int main(object me, string arg)
{
        int i;
        string file, *search;
        string *default_search;
        int wildcard;
        if( !arg ) {
                me->set_temp("help",1);
                m_display();
                write(YEL"ÄãÏÖÔÚµÄ´òËã£º"NOR);
                input_to((:confirm_main_choice:),this_player());
                return 1;
        }
                seteuid(getuid());
        // Else, try if a command name is specified.
        seteuid(getuid());
        if( stringp(file = me->find_command(arg)) ) {
                notify_fail("ÓÐÕâ¸öÖ¸Áî´æÔÚ£¬µ«ÊÇ²¢Ã»ÓÐÏêÏ¸µÄËµÃ÷ÎÄ¼þ¡£\n");
                return file->help(me);
        }
        //Now see if it aliases to a command.
        //mon 10/27/97
        if( stringp(file =
          me->find_command(ALIAS_D->process_global_alias(arg))) ) {
                notify_fail("ÓÐÕâ¸öÖ¸Áî´æÔÚ£¬µ«ÊÇ²¢Ã»ÓÐÏêÏ¸µÄËµÃ÷ÎÄ¼þ¡£\n");
                return file->help(me);
        }

        // Search the individual search path first.
        if( pointerp(search = me->query("help_search_path")) ) {
                i = sizeof(search);
                while(i--) if( file_size(search[i] + arg)>0 ) {
                        me->start_more( read_file(search[i] + arg) );
                        return 1;
                }
        }

        // Support efun/lfun help with same name as other topics such as
        // ed() and ed command.
        // Using a "()" after the function name can prevent it being
        // interpreted as a user command with the same name. -- mon
        sscanf(arg, "%s()", arg);
        arg=replace_string(arg, "/", "");

        if(strsrch(arg,"*")>=0 || strsrch(arg,"?")>=0) wildcard=1;
        else wildcard=0;

        found=0;
        write("\n");

        // Finally, search the default search paths.
        // by snowcat feb 21 1998
        if (wizardp(me))
                default_search = DEFAULT_SEARCH_PATHS;
        else
                default_search = DEFAULT_PLAYER_SEARCH_PATHS;
        if( pointerp(default_search) ) {
          if(search_dir(default_search, arg, me, wildcard, wizardp(me))>0) {
            if(wildcard) write("ÕÒµ½"+chinese_number(found)+
              "¸öÏà¹ØÖ÷Ìâ¡£\n");
            return 1;
          }
        }

        return notify_fail("Ã»ÓÐÕë¶ÔÕâÏîÖ÷ÌâµÄËµÃ÷ÎÄ¼þ¡£\n");
}

int search_dir(string *dirs, string arg, object me, int wildcard, int wizp)
{
    int i = sizeof(dirs), j;
    mixed *filenames, *sub_dir;

    while(i--) {
      filenames=get_dir(dirs[i] + arg, -1);

      if(pointerp(filenames) && sizeof(filenames)) {
        if(!wildcard && filenames[0][1]>0) {
        //without wildcard, filenames[0] must be the only match.
        //which should be the same as "dirs[i] + arg"
          me->start_more( read_file(dirs[i] + arg) );
          return 1;
        }

        if(wildcard) {
          j=sizeof(filenames);
          while(j--) {
            if(filenames[j][1]>0) {
              write("help "+filenames[j][0]+
                (wizp?"     ("+dirs[i]+")":"")+ "\n");
              found++;
            }
          }
        }
      }

      //check sub_directories
      if(pointerp(filenames=get_dir(dirs[i], -1))) {
        if(pointerp(sub_dir=filter_array(filenames, "find_sub"))) {
          string *dirs1=({});

          j=sizeof(sub_dir);
          while(j--) {
            dirs1+=({dirs[i]+sub_dir[j][0]+"/"});
          }

          if(search_dir(dirs1, arg, me, wildcard, wizp)==1
            && !wildcard) return 1;
        }
      }
    }

    return (wildcard*found);
}

int find_sub(mixed *filename)
{
    return (filename[1]==-2);
}

void view_main()
{
     object me;
     string name,select;
     me = this_player();
     select = me->query_temp("select");
     write(CLR"\n");
     if(select== "main") name = BRED HIY"ÓÃ»§Ö¸ÄÏ"NOR;
     else if( select== "intro") name = "ÓÎÏ·¸Å¿ö";
     else if( select== "depart") name = "ÃÅÅÉ½éÉÜ";
     else if( select== "map") name = "µØÐÎÖ¸ÄÏ";
     else if( select== "user") name = "¸öÈËÉè¶¨Çø";
     else if( select== "board") name = "ÖØÒª²¼¸æÀ¸";
     else if( select== "post") name = "½­ºþ¼ÄÓï";
     else if( select== "leaveword") name= "ÆäËüÁôÑÔ°å";
     else if( select== "culture" ) name="Ä«Ôµ";
     else if( select== "other" ) name="ÆäËü";
     else if( select== "xyz" ) name="ÏµÍ³Éè¶¨Çø";
     write(BBLU HIY"·ÖÀàÑ¡µ¥"NOR"                     " HIR"¡¼ "+HIG+BRED+CHINESE_MUD_NAME+NOR+HIR" ¡½""                  "BBLU HIY"Ñ¡µ¥["+select+"]\n"NOR);     
     write("Ä¿Ç°Ñ¡Ôñ£º[ "+name+" ]\n");
     write(HIG"¡ò"NOR CYN"©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥"HIR"©§"BLINK BBLU HIR" ¹«¸æ°æ "NOR HIR"©§"NOR CYN"©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥"NOR HIG"¡ò\n"NOR);
     auto_load();
     write(HIG"¡ò"NOR CYN"©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥"NOR HIG"¡ò	\n"NOR);  
     write("\n");
}
void view_main_1()
{
     int i,ppl_cnt;
     object *usr;
     usr = users();
     ppl_cnt=0;
     for(i=0; i<sizeof(usr); i++)
       {
          ppl_cnt++;
       }
     write("\n");   
     write(YEL"_.-*```*-.__.-*```*-.__.-*```*-.__.-*```*-.__.-*```*-.__.-*```*-.__.-*\n"NOR);
     write("\n");     
     write(BCYN RED"±±¾©Ê±¼ä: "+MAG+ctime(time())+"    "NOR+BCYN RED"ÔÚÏßÍæ¼Ò: "+MAG+ppl_cnt+"    "NOR+BCYN RED"ÓÃ»§µÈ¼¶: "+MAG+wizhood(this_player())+"\n"NOR,);
     write("                                         [4;53m[1;31mBy tianlin@mhxy for 2001.10.7[2;37;0m\n");
}
void view_main_k()
{
     object me;
     string name,select;
     me = this_player();
     select = me->query_temp("select");
     write(CLR"\n");
     if(select== "main") name = BRED HIY"ÓÃ»§Ö¸ÄÏ"NOR;
     else if( select== "intro") name = "ÓÎÏ·¸Å¿ö";
     else if( select== "depart") name = "ÃÅÅÉ½éÉÜ";
     else if( select== "map") name = "µØÐÎÖ¸ÄÏ";
     else if( select== "user") name = "¸öÈËÉè¶¨Çø";
     else if( select== "board") name = "ÖØÒª²¼¸æÀ¸";
     else if( select== "post") name = "½­ºþ¼ÄÓï";
     write(BBLU HIY"·ÖÀàÑ¡µ¥"NOR"                     " HIR"¡¼ "+HIG+BRED+CHINESE_MUD_NAME+NOR+HIR" ¡½""                  "BBLU HIY"Ñ¡µ¥["+select+"]\n"NOR);     
     write("Ä¿Ç°Ñ¡Ôñ£º[ "+name+" ]\n");
     write(HIG"¡ò"NOR CYN"©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥"HIR"©§"BLINK BBLU HIR" ¹«¸æ°æ "NOR HIR"©§"NOR CYN"©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥"NOR HIG"¡ò\n"NOR);
     auto_load();
     write(HIG"¡ò"NOR CYN"©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥"NOR HIG"¡ò	\n"NOR);  
     write("\n");
}

void m_display()
 {
     this_player()->set_temp("select","main");
     view_main();
     write("                        "HIY"("NOR+HIR"I"NOR+HIY")"NOR"ntro  ¡¡¡¼  "BGRN HIW"ÓÎÏ·¸Å¿ö"NOR"  ¡½\n");
     write("                        "HIY"("NOR+HIR"D"NOR+HIY")"NOR"epart ¡¡¡¼  "BRED HIW"ÃÅÅÉ½éÉÜ"NOR"  ¡½\n");
     write("                        "HIY"("NOR+HIR"M"NOR+HIY")"NOR"ap    ¡¡¡¼  "BCYN HIW"µØÐÎÖ¸ÄÏ"NOR"  ¡½\n");
     write("                        "HIY"("NOR+HIR"U"NOR+HIY")"NOR"ser     ¡¼ "BBLU HIW"¸öÈËÉè¶¨Çø"NOR" ¡½\n");
     write("                        "HIY"("NOR+HIR"C"NOR+HIY")"NOR"ulture  ¡¼   "BMAG HIW"Ä«  Ôµ"NOR"   ¡½\n");
     write("                        "HIY"("NOR+HIR"B"NOR+HIY")"NOR"board ¡¡¡¼ "BYEL HIW"ÖØÒª²¼¸æÀ¸"NOR" ¡½\n");
     write("                        "HIY"("NOR+HIR"L"NOR+HIY")"NOR"eaveword¡¼ "HBGRN HIW"ÆäËüÁôÑÔ°å"NOR" ¡½\n");
     write("                        "HIY"("NOR+HIR"O"NOR+HIY")"NOR"ther    ¡¼    "HBRED HIC"Æä Ëü"NOR"   ¡½\n");
     write("                        "HIY"("NOR+HIR"X"NOR+HIY")"NOR"yz      ¡¼ "HBRED WHT"ÏµÍ³Éè¶¨Çø"NOR" ¡½\n");
     write("                        "HIY"("NOR+HIR"P"NOR+HIY")"NOR"BBS     ¡¼  "HBRED HIY"½­ºþ¼ÄÓï"NOR"  ¡½\n");
     write("                        "HIY"("NOR+HIR"G"NOR+HIY")"NOR"oodbye¡¡¡¼  "HBWHT RED"ÖØ¹é½­ºþ"NOR"  ¡½\n");
     view_main_1();
}

void auto_load()
{
    if(random(10) > 5)
    wizlist();
    else if( random(20) >  10)
    message();
    else
    message1();
}
int message1()
{
       object me;
      int i;
      me = this_player();
      i = me->query("MKS")+me->query("PKS");
      write(HIC"\n      "+HIW+me->name()+NOR HIY"´óÏÀ"+HIG": ÄãÐÐ×ß½­ºþÒÑ¾­ "+BBLU MAG+age_string((int)me->query("mud_age"))+NOR+HIG" Ö®¾Ã!!\n");
      write(HIG"                ÔÚÄã½­ºþÉúÑÄµÄÈÕÈÕÒ¹Ò¹Àï, ÄãÒÑ¾­ÀÛ»ýÁË "+BYEL HIR+me->query("combat_exp")+NOR" \n");
      write(HIG"                µã¾­Ñé, ¹²»÷µ¹ "+HBRED HIW+chinese_number(i)+HIG" ¸ö¶ÔÊÖ,Ç°Í¾²»¿ÉÏÞÁ¿!\n"NOR);
    
}
string age_string(int time)
{
        int month, day, hour, min, sec;

        sec = time % 60;
        time /= 60;
        min = time % 60;
        time /= 60;
        hour = time % 24;
        time /= 24;
        day = time % 30;
        month = time / 30;
        return (month?month + "ÔÂ":"") + (day?day + "Ìì":"") +
        (hour?hour + "Ð¡Ê±":"") + min + "·Ö";
}
int message()
{
 write(HIR"   ¡ñ    £¨ ¡ñ £©  £¨¡ñ£©      ¡ñ£©     ¡ñ     £¨¡ñ£©   ¡õ¡ñ¡õ   £¨¡ñ\n"NOR);
 write(HIB" £¼£ü£¾   ©¸£ü©¼    £¨£¨£¨   £¨£ü     £¨£ü£©   ¡¡£ü£©     £ü      £¨¡õ\n"NOR);
 write(HIY"  £¯£Ü    £¼  ¡õ   £¨         £¯ £©    £¨¡õ     £¨ £Ü   ¡õ  ¡õ    £¼£©£©\n"NOR);
 write(HIC""+this_player()->name()+",ÍæÀÛÁË°É£¿À´,ÎÒÃÇÒ»Æð×öÔË¶¯---×óÈýÈ¦£¬ÓÒÈýÈ¦£¬²±×ÓÅ¤Å¤£¬Æ¨¹ÉÅ¤Å¤...\n"NOR);
}

int wizlist()
{
        string *wizlist,*list,wiz_name,wiz_level,str,str0,str1,str2,str3,str4;
        int i,s0,s1,s2,s3,s4;
        str0="",str1="",str2="",str3="",str4="";
        s0=0;s1=0;s2=0;s3=0;s4=0;
        list = sort_array(SECURITY_D->query_wizlist(),1);
        wizlist = explode(read_file(WIZLIST), "\n");
        for(i=0; i<sizeof(wizlist); i++)  {
        sscanf(wizlist[i], "%s %s", wiz_name, wiz_level);
                switch(wiz_level)
                {
                        case "(elder)":
                                str0 += (s0?"\t":"")+wiz_name;
                                s0++;
                                if(s0%6==0) str0 += "\n \t\t ";
                                break;
                        case "(apprentice)":
                                str1 += (s1?"\t":"")+wiz_name;
                                s1++;
                                if(s1%6==0) str1 += "\n \t\t ";
                                break;
                        case "(wizard)":
                                str2 += (s2?"\t":"")+wiz_name;
                                s2++;
                                if(s2%6==0) str2 += "\n \t\t ";
                                break;
                        case "(arch)":
                                str3 += (s3?"\t":"")+wiz_name;
                                s3++;
                                if(s3%6==0) str3 += "\n \t\t ";
                                break;
                         case "(admin)":
                                str4 += (s4?"\t":"")+wiz_name;
                                s4++;
                                if(s4%6==0) str4 += "\n \t\t";
                                break;
                }
        }
        write(HIR"   ¡Ë¡ºÖ´ÐÐ¹Ù¡»(elder)     : "NOR+str0+"\n");
        write(HIY"   ¡Ë¡ºÉ¢  ÏÉ¡»(apprentice): "NOR+str1+"\n");
        write(HIG"   "BLINK+HIR"¡Ì"NOR+HIG"¡ºÎ×  Ê¦¡»(wizard)    : "NOR+str2+"\n");
        write(HIC"   "BLINK+HIR"¡Ì"NOR+HIC"¡º´ó  Éñ¡»(arch)      : "NOR+str3+"\n");
        write(HIW"   "BLINK+HIR"¡Ì"NOR+HIW"¡ºÌì  Éñ¡»(admin)     : "NOR+str4+"\n");
}

private void confirm_main_choice(string arg)
{
        this_player()->delete_temp("memer");
        switch(arg[0]){
                case 'p':
                this_player()->set_temp("select","post");
                this_player()->set_temp("memer","post/page");
                display();
                return ;
                break;
                case 'd':
                this_player()->set_temp("select","depart");
                display();
                return;
                break;
                case 'i':
                this_player()->set_temp("select","intro");
                display();
                return;
                break;
                case 'm':
                this_player()->set_temp("select","map");
                display();
                return;
                break;
                case 'o':
                this_player()->set_temp("select","other");
                display();
                return;
                break;
                case 'b':
                this_player()->set_temp("select","board");
                display();
                return;
                break;
                case 'c':
                this_player()->set_temp("select","culture");
                display();
                return;
                break;
                case 'x':
                this_player()->set_temp("select","xyz");
                display();
                return;
                break;
                case 'l':
                this_player()->set_temp("select","leaveword");
                display();
                return;
                break;
                case 'u':
                this_player()->set_temp("select","user");
                u_display();
                write(YEL"\rÇëÊäÈëÄúµÄÑ¡Ôñ:"NOR);
                input_to((:confirm_u_choice:),this_player());
                return;
                break;
                case 'g':
                this_player()->delete_temp("select");
                this_player()->delete_temp("help");
                return;
        }
        m_display();
        write(YEL"ÇëÊäÈëÄúµÄÑ¡Ôñ:"NOR);
        input_to((:confirm_main_choice:),this_player());
        return;
}
/*ÁôÑÔ°å³ÌÐò*/
void view1()
{
        write(HIC"  (P)"NOR"·¢±í "HIC"(D)"NOR"É¾³ý "HIC"(U)"NOR"ÉÏ·­ "HIC"(O)"NOR"ÏÂ·­"
        HIC" (B)"NOR"·µ»Ø "HIC"(E)"NOR"½øÈë "HIC"(K)"NOR"ÉÏÒÆ "HIC"(J)"NOR"ÏÂÒÆ\n");
        write(HIR"¡õ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡õ\n"NOR);
        return;
}
string view_msg(int flag,object ob)
{
        object me=this_player();
        string memer=me->query_temp("memer");
        mapping *notes=ob->query("notes");
        string file;
        int i,k,b,f;
        file="";
        k=sizeof(notes)-1;
        if(!sizeof(notes)) return "Ã»ÓÐÈÎºÎÁôÑÔ¡£\n";
        if(flag<0) flag=k;
        if(flag>k) flag=0;
        me->set(memer,flag);
        b=flag-7;f=flag+7;
        if(b<0) {f=f-b;b=0;}
        if(f>k) {b=b-f+k;f=k;}
        if(b<0) b=0;
        if(f>k) f=k;
        f++;
        for(i=b;i<f;i++)
        file += sprintf("%s["NOR+HIW +BRED"%3d"NOR"%s]  %-30s %12s (%s)\n"NOR,
                        (i==flag)?BRED +HIW:"",
                        i+1, (i==flag)?BRED +HIW:"",notes[i]["title"], notes[i]["author"],
                        ctime(notes[i]["time"])[0..15] );
        return file;
}

private void confirm_p_choice(string arg,object ob)
{
        object me=this_player();
        int k=atoi(arg);
        int p,num;
        string memer=me->query_temp("memer");
        mapping *notes;
        if(k>0)
        {
                me->set(memer,k-1);
                display(ob);
        }
        switch(arg)
        {
                case "p":
                do_post(0,ob);
                return;
                break;
                case "b":
                main(this_player(),0);
                return;
                case "j":
                me->set(memer,me->query(memer)+1);
                display(ob);
                return;
                break;
                case "k":
                me->set(memer,me->query(memer)-1);
                display(ob);
                return;
                break;
                case "u":
                me->set(memer,me->query(memer)-15);
                display(ob);
                return;
                break;
                case "o":
                me->set(memer,me->query(memer)+15);
                display(ob);
                return;
                break;
                case "d":
                do_discard(ob);
                display(ob);
                return;
                break;
                break;
                case "e":
                num=this_player()->query(memer);
                notes=ob->query("notes");
                if( !pointerp(notes) || !sizeof(notes) )
                {
                        write("ÁôÑÔ°åÉÏÄ¿Ç°Ã»ÓÐÈÎºÎÁôÑÔ¡£\n");
                        display(ob);
                        return;
                }
                if(  num+1 > sizeof(notes) )
                {
                        write("Ã»ÓÐÕâÕÅÁôÑÔ¡£\n");
                        display(ob);
                        return;
                }
                printf("["BBLU"%3d"NOR"] %-30s %s (%s)\n",
                num + 1, notes[num]["title"], notes[num]["author"],
                ctime(notes[num]["time"])[0..9]);
                start_help(notes[num]["msg"],ob);
                return;
                break;
        }
        display(ob);
        return;
}
int edi(function callback)
{
        write(HIC"    ÊéÐ´½áÊøÓÃ'.'£¬È¡ÏûÊäÈëÓÃ '^q'£¬Ê¹ÓÃÄÚ½¨ÁÐ±à¼­Æ÷ÓÃ '^e'¡£\n"NOR);

write(HIG"©°©¤©¤¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª©´\n©¦"NOR);

         input_to("input_lines", "", callback);

         return 1;

}


void input_lines(string line, string text, function callback)
{
        if( line=="." ) {
                write(HIG"©¸©¤©¤¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª©¼\n"NOR);
                (*callback)(text);
                return;
        } else if( line=="^q" ) {
                write("ÊäÈëÈ¡Ïû¡£\n");
                main(this_player(),0);
        } else if( line=="^e" ) {
        } else  {
                line=replace_string(line,";",";\n");
                text += line + "\n";
        }
        write(HIG"©¦"NOR);
        input_to("input_lines", text, callback);
}
void done_post(mapping note,object ob,string text)
{
        mapping *notes;
        if(strlen(text)<20)
        {
                write(HIC"±¾ÎÄ±»ÈÏÎªÊÇ¹àË®ÎÄÕÂ£¬²»Óè·¢±í¡£\n"NOR);
                display(ob);
                return;
        }
        text=replace_string(text,";","\n");
        note["msg"] = text;
        notes = ob->query("notes");
        if( !pointerp(notes) || !sizeof(notes) )
                notes = ({ note });
        else
                notes += ({ note });
        ob->set("notes", notes);
        write("ÁôÑÔÍê±Ï¡£\n");
        ob->save();
        display(ob);
        return;
}

string hostname(object me)
{
        me = this_player();

        if( me->query_host_name() )
        {
                if( me->query("env/hostname") )
                return me->query("env/hostname")+me->query_host_name();
                return me->query_host_name();
        }

        else
        {
                if( me->query("env/hostname") )
                return me->query("env/hostname")+".yszz.net";
                return me->query("id")+".yszz.net";
        }
}

int do_post(string arg,object ob)
{
        mapping note;
        if(!arg||arg=="")
        {
                write(HIY"\nÇëÖ¸¶¨Ò»¸ö±êÌâ:"NOR"(¡°Q¡±¼üÈ¡Ïû)");
                input_to((:do_post:),ob);
                return 1;
        }
        if(arg=="q"||arg=="Q")
        {
                display(ob);
                return 1;
        }
        note = allocate_mapping(5);
        note["title"] = arg;
        note["author"] = this_player()->query("name")+
    "("+capitalize(this_player()->query("id"))+")";
//      note["authorid"] =this_player()->query("id");
        note["ip"] = hostname(this_player());
        note["time"] = time();
        edi((: done_post,note,ob:));
        return 1;
}

void do_discard(object ob)
{
        mapping note,*notes;
        int num;
        string memer=this_player()->query_temp("memer");
        num=this_player()->query(memer)+1;
        notes = ob->query("notes");

        if( !arrayp(notes) ||!sizeof(notes)||num < 1 || num > sizeof(notes))
        {
                write("Ã»ÓÐÕâÕÅÁôÑÔ¡£\n");
                return;
        }
        num--;
   if( notes[num]["author"] !=
     (string) this_player(1)->query("name")+
     "("+capitalize(this_player(1)->query("id"))+")"
   && (string)SECURITY_D->get_status(this_player(1)) !="(arch)"
   &&   (string)SECURITY_D->get_status(this_player(1)) != "(admin)"
   &&  this_object()->query("master") != this_player(1)->query("id")
)
        {
                write("Õâ¸öÁôÑÔ²»ÊÇÄãÐ´µÄ¡£\n");
                return;
        }
   if (num >0)
             notes = notes[0..num-1] + notes[num+1..sizeof(notes)-1];
        else
          notes =notes[num+1..sizeof(notes)-1];

        ob->set("notes", notes);
        ob->save();
        write("É¾³ýµÚ " + (num+1) + " ºÅÁôÑÔ....Ok¡£\n");
        return;
}



varargs void view2(int line,string *text,object ob,int i)
{
        int w=line;
        if(i) w=w+17;
        write( "©À¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª©É\n"NOR);
        printf("©¦ ×ÜÐÐÊý:"HIR+"%5d "NOR+"ËùÔÚÐÐÊý:"HIR+"%5d "+HIC"(T"NOR"x"HIC")"NOR"·­µ½xÐÐ "HIC"(U)"NOR"ÏòÉÏ "
        HIC"(D)"NOR"ÏòÏÂ "HIC"(R)"NOR"»ØÎÄ "HIC"(B)"NOR"·µ»Ø  ©¦\n",sizeof(text),w);
        write( "©¸¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª©¼\n"NOR);
        write(YEL"ÄúµÄÑ¡Ôñ£º"NOR);
        input_to((:do_more:),text,line,ob);
        return;
}
void do_more(string cmd,string *text,int line,object ob)
{
        int i,j,num;
        mapping *notes;
        string t=this_player()->query_temp("select");
        string memer=this_player()->query_temp("memer");
        if(!ob) ob=this_object();
        if(cmd[0]=='t')
        {
                j=atoi(cmd[1..<0]);
                if(j)
                {
                        line=j;
                        cmd="u";
                }
        }
        else if(j=atoi(cmd))
        {
                line=j;
                cmd="u";
        }
        switch(cmd) {
        case "d":
                if(line+17>=sizeof(text)) line=sizeof(text)-17;
                if(line<0) line=0;
                if(line<sizeof(text))
                {
                        write("©°¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª©´\n");
                        for(i=line + 17; line<sizeof(text) && line<i; line++)
                        write("©¦"+text[line] + "\n");
                        if( line>=sizeof(text) )
                        write("©À¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª È«  ÎÄ  Íê ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª©É\n");
                }
                view2(line,text,ob);
                return;
                break;
        case "u":
                if(line>=sizeof(text)) line=sizeof(text);
                line = line - 17;
                if(line<0) line=0;
                write("©°¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª©´\n");
                for(i=line + 17;line<sizeof(text)&&line < i;line++)
                write("©¦"+text[line]+"\n");
                if( line>=sizeof(text) )
                write("©À¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª È«  ÎÄ  Íê ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª©É\n");
                view2(line-17,text,ob,1);
                return;
                break;
        case "b":
                return display(ob);
                break;
        case "r":
                if(t=="post")
                {
                        num=this_player()->query(memer);
                        notes=ob->query("notes");
                        do_post("[»ØÎÄ]"+notes[num]["title"],ob);
                }
                return;
        }
        view2(line,text,ob);
        return;
}
int register()
{
        object me;
        me = this_player();
        if(!me->query("register")) {
                write(CLR"\n");
                write(HIW"¡¾Ê¹ÓÃÕßÉè¶¨¡¿        "HIY"¡¾"+MUD_NAME+"×¢²áµ¥¡¿\n"NOR);
                write("\n");
                write(YEL"Ä¿Ç°Ñ¡Ôñ£º\n\n"NOR);
                write(HIW"    ÄúµÄ´úºÅ     : "NOR);
                input_to((:a:),this_player());
                return 1;
        }
        write("ÄãÒÑ¾­ÌîÐ´¹ý×¢²áµ¥¡£\n");
        input_to("confirm_u_choice",this_player());
        return 1;
}
private void a(string arg, string register)
{
        register = "´úºÅ     : "+arg+"\n";
        this_player()->add_temp("register",register);
        write(HIW"    ÄúµÄêÇ³Æ     : "NOR);
        input_to((:b:),this_player(),register);
}
private void b(string arg, string register)
{
        register = "êÇ³Æ     : "+arg+"\n";
        this_player()->add_temp("register",register);
        write(HIW"    ÕæÊµÐÕÃû     : "NOR);
        input_to((:c:),this_player());
}
private void c(string arg, string register)
{
        register = "ÐÕÃû     : "+arg+"\n";
        this_player()->add_temp("register",register);
        write(HIW"    ÁªÏµµØÖ·     : "NOR);
        input_to((:d:),this_player());
}
private void d(string arg, string register)
{
        register = "ÁªÏµµØÖ·     : "+arg+"\n";
        this_player()->add_temp("register",register);
        write(HIW"    ¹¤×÷µ¥Î»/Ñ§Ð£: "NOR);
        input_to((:e:),this_player());
}
private void e(string arg, string register)
{
        register = "¹¤×÷µ¥Î»/Ñ§Ð£: "+arg+"\n";
        this_player()->add_temp("register",register);
        write(HIW"    µç×ÓÐÅÏä: "NOR);
        input_to((:f:),this_player());
}
private void f(string arg, string register)
{
        register = "µç×ÓÐÅÏä: "+arg+"\n";
        this_player()->add_temp("register",register);
        write(HIW"    ÁªÏµµç»°: "NOR);
        input_to((:g:),this_player());
}
private void g(string arg, string register)
{
        register = "ÁªÏµµç»°: "+arg+"\n";
        this_player()->add_temp("register",register);
        write(HIW"\n\n\n\n\n\nÒÔÉÏ×ÊÁÏÊÇ·ñÕýÈ·(Y/N)£¿(Q)È¡Ïû×¢²á [N]:"NOR);
        input_to((:y:),this_player());
}
private void y(string arg, string register)
{
        string table;
        if(arg=="") {
                this_player()->delete_temp("register");
                register();
                return ;
        }
        switch(arg[0]){
        case 'n':
                this_player()->delete_temp("register");
                register();
                return ;
                break;
        case 'y':
                this_player()->set("register",1);
                table =  this_player()->query_temp("register");
                this_player()->delete_temp("register");
                write_file(REGISTER+this_player()->query("id"),table,1);
                write("¡óÉèÖÃÒ»ÇÐÕýÈ·¡£\n");
                input_to("confirm_u_choice",this_player());
                return;
                break;
        case 'q':
                this_player()->delete_temp("register");
                u_display();
                write(YEL"\rÇëÊäÈëÄúµÄÑ¡Ôñ:"NOR);
                input_to((:confirm_u_choice:),this_player());
                return ;
                break;
        default:
                this_player()->delete_temp("register");
                register();
                return ;
                break;
        }
        return ;
}
int pager()
{
        object me;
        me = this_player();
        if(me->query_temp("call_on")) {
                write("´ò¿ª Pager ÆµµÀ\n");
                me->delete_temp("call_on");
        } else {
                write("¹Ø±Õ Pager ÆµµÀ\n");
                me->set_temp("call_on",1);
        }
        return 1;
}
int cloak()
{
        object me;
        me = this_player();
        if(!wizardp(me))
        {
                u_display();
                write(YEL"\rÇëÊäÈëÄúµÄÑ¡Ôñ:"NOR);
                input_to((:confirm_u_choice:),this_player());
                return 1;
        }
        if(me->query("env/invisibility"))
        {
                write("ÎÒÒªÖØÏÖ½­ºþ...\n");
                me->delete("env/invisibility");
        } else {
                write("¹þ¹þ£¡ÎÒÒþÐÎÆðÀ´ÁË¡£\n");
                me->set("env/invisibility",5);
        }
        return 1;
}
int lock()
{
        object me,ob;
        me = this_player();
        ob = me->query_temp("link_ob");
        write(HIW"¡ø ÇëÊäÈëÃÜÂë£¬ÒÔ½â³ýÓ©Ä»Ëø¶¨£º"NOR);
        input_to("get_old_pass", 1, ob);
        return 1;
}
private void confirm_u_choice(string arg)
{
        this_player()->set_temp("help_u",1);
        if(arg=="") {
                u_display();
                write(YEL "\rÇëÖØÐÂÊäÈëÄúµÄÑ¡Ôñ:"NOR);
                input_to((:confirm_u_choice:),this_player());
                return ;
        }
        switch(arg[0]){
        case 'r':
                register();
                return ;
                break;
        case 'p':
                pager();
                write(YEL "\rÇëÖØÐÂÊäÈëÄúµÄÑ¡Ôñ:"NOR);
                input_to((:confirm_u_choice:),this_player());
                return ;
                break;
        case 'c':
                cloak();
                write(YEL "\rÇëÖØÐÂÊäÈëÄúµÄÑ¡Ôñ:"NOR);
                input_to((:confirm_u_choice:),this_player());
                return ;
                break;
        case 'l':
                lock();
                return ;
                break;
        case 'f':
        case 'h':
        case 'g':
                m_display();
                write(YEL "\rÇëÊäÈëÄúµÄÑ¡Ôñ:"NOR);
                this_player()->delete_temp("help_u");
                input_to((:confirm_main_choice:),this_player());
                return ;
                break;
        default:
                u_display();
                write(YEL"\rÇëÊäÈëÄúµÄÑ¡Ôñ:"NOR);
                input_to((:confirm_u_choice:),this_player());
                return ;
        }
        return;
}
void u_display()
{
        view_main();
        write("                       "HIC"(£É)"NOR"nfo        ¸öÈË×ÊÁÏ\n");
        write("                       "HIC"(£Ë)"NOR"ill        ÍêÈ«×ÔÉ±ÊÖ²á\n");
        if (wizardp(this_player()))
        write("                       "HIC"(£Ã)"NOR"loak       ÒþÉíÊõ\n");
        write("                       "HIC"(£Ì)"NOR"ockScreen  Ëø¶¨Ó©Ä»\n");
        write("                       "HIC"(£Ò)"NOR"egister    ÌîÐ´¡¶×¢²áÉêÇëµ¥¡·\n");
        write("                       "HIC"(£Ð)"NOR"ager       ÇÐ»»ºô½ÐÆ÷\n");
        write("                       "HIC"(£Ç)"NOR"return     ·µ»ØÖ÷²Ëµ¥\n");
        view_main_1();
}
void get_old_pass(string pass, object ob)
{
        string old_pass;
        old_pass = ob->query("password");
        if( crypt(pass, old_pass)!=old_pass ) {
                lock();
                return ;
        }
        u_display();
        write(YEL"\rÇëÊäÈëÄúµÄÑ¡Ôñ:"NOR);
        input_to((:confirm_u_choice:),this_player());
        return ;
}
string find_file()
{
        string str=this_player()->query_temp("select");
        str=DIR+str+".h";
        return str;
}
void getname1(string arg)
{
        int k;
        if(!arg||arg=="")
        {
                write(HIC"ÇëÊäÈëÁ´½ÓÃû³Æ£º"NOR);
                input_to("getname1");
                return;
        }
        if(arg=="q"||arg=="Q")
        {
                display();
                return;
        }
        k=strlen(arg);
        if(k<2||k>16)
        {
                write(HIG"Á´½ÓÃû³Æ×ÖÊý±ØÐëÔÚ2µ½16¸ö×ÖÔªÖ®¼ä£¡\n"NOR);
                write(HIC"ÇëÊäÈëÁ´½ÓÃû³Æ£º"NOR);
                input_to("getname1");
                return;
        }
        write(HIG"ÇëÊäÈëÁ´½Óµµ°¸£º"NOR);
        input_to("getname2",arg);
        return;
}
void getname2(string str,string arg)
{
        string file=read_file(find_file()),msg,t;
        string *text,*w;
        if(str=="q"||str=="Q")
        {
                display();
                return;
        }
        if(file_size(str)<0)
        {
                write(HIY"Ã»ÓÐÕâ¸öµµ°¸£¡\n"NOR);
                write(HIG"ÇëÊäÈëÁ´½Óµµ°¸£º"NOR);
                input_to("getname2",arg);
                return;
        }
        if(!file) file="";
        file+=arg+"==@=="+str+"\n";
        text=explode(file,"\n");
        file="";
        while(sizeof(text))
        {
                msg=text[0];
                text-=({msg});
                w=explode(msg,"==@==");
                t=replace_string(find_file(),".h","");
                t=t+"/"+w[1]+".h";
                if(file_size(w[1])<0&&file_size(t)<0)
                continue;
                file+=msg+"\n";
        }
        write_file(find_file(),file,1);
        write("OK!\n");
        display();
        return;
}
void view7(string arg)
{
        int k;
        string file=read_file(find_file()),*text;
        if(!arg)
        {
                write(HIC"ÇëÑ¡ÔñÒªÐÞ¸ÄµÄÑ¡Ïî£º(Q¼üÈ¡Ïû)"NOR);
                input_to("view7");
                return;
        }
        if(arg=="q"||arg=="Q")
        {
                display();
                return;
        }
        if(!k=atoi(arg))
        {
                view7(0);
                return;
        }
        text=explode(file,"\n");
        if(k>sizeof(text))
        {
                view7(0);
                return;
        }
        k--;
        write(YEL"ÄúÒªÐÞ¸Ä(1)Ãû³Æ»òÕß(2)Á´½Ó£¿"NOR);
        input_to("view8",text[k],k);
        return;
}
void view8(string arg,string str,int k)
{
        string *w=explode(str,"==@==");
        switch(arg) {
                case "1":
                write(HIC"ÇëÊäÈëÃû³Æ:"NOR);
                input_to("view9",str,k,1);
                return;
                case "2":
                if(file_size(w[1])<0&&strsrch(w[1],"subdir")>-1)
                {
                        write(HIG"ÕâÊÇÒ»¸öÄ¿Â¼,²»ÊÇÁ´½ÓÎÄµµ!\n"NOR);
                        view7(0);
                        return;
                }
                write(HIC"ÇëÊäÈëÁ´½ÓÎÄµµ:"NOR);
                input_to("view9",str,k,0);
                return;
        }
        view7(0);
        return;
}
void view9(string arg,string str,int i,int j)
{
        string file=read_file(find_file()),
        *text=explode(file,"\n"),
        *w=explode(str,"==@==");
        if(j) w[0]=arg;
        else {
                if(file_size(arg)<0)
                {
                        write(HIR"Ã»ÓÐÕâ¸öÎÄµµ!\n"NOR);
                        view8("2",str,i);
                        return;
                }
                w[1]=arg;
        }
        text[i]=implode(w,"==@==");
        file=implode(text,"\n");
        write_file(find_file(),file,1);
        write("OK!\n");
        display();
        return;
}
void view3()
{
        string file,*text,str=find_file(),*w,msg,*t;
        int i,j;
        file=read_file(str);
        if(!file)
        {
                write("×ÊÁÏ²É¼¯ÖÐ......\n");
                return;
        }
        text=explode(file,"\n");
        if(!j=sizeof(text))
        {
                write("×ÊÁÏ²É¼¯ÖÐ......\n");
                return;
        }
        t=({});
        file="";
        i=0;
        while(sizeof(text))
        {
                w=explode(text[0],"==@==");
                file+=sprintf(HIC" ("BBLU +HIG"%2d"NOR +HIC")"HIW"¡¾%|16s¡¿"NOR,i+1,w[0]);
                if(i%3==2) file+="\n";
                text-=({text[0]});
                i++;
        }
        file+="\n";
        write(file);
        return;
}
void view4()
{
        string file,*w,*text,str=find_file();
        int i,j,k,v;
        file=read_file(str);
        if(!file)
        {
                write("×ÊÁÏ²É¼¯ÖÐ......\n");
                return;
        }
        text=explode(file,"\n");
        if(!j=sizeof(text))
        {
                write("×ÊÁÏ²É¼¯ÖÐ......\n");
                return;
        }
        for(file="",i=0;i<j;i++)
        {
                w=explode(text[i],"==@==");
                file+=sprintf(HIC" (%2d)"HIW"¡¾%|16s¡¿%s"NOR,i+1,w[0],w[1]);
                if(i%2==1) file+="\n";
        }
        file+="\n";
        write(file);
        return;
}
void view5(string arg)
{
        int k=atoi(arg),i,j;
        string *w,*text,file,t=this_player()->query_temp("select");
        file=find_file();
        file=read_file(file);
        if(!file) {
                write(HIR"Ã»ÓÐÁ´½ÓÎÄ¼þ!\n"NOR);
                display();
                return;
        }
        if(arg=="q"||arg=="Q")
        {
                write(HIC"·µ»Ø£¡\n"NOR);
                display();
                return;
        }
        if(!k)
        {
                write(HIG"ÇëÊäÈëÄãÒª²é¿´µÄÄÚÈÝ:"NOR);
                input_to("view5");
                return;
        }
        text=explode(file,"\n");
        if(j=sizeof(text)<k-1)
        {
                write(HIG"Ã»ÓÐÕâ¸öÎÄ¼þ!\n"NOR);
                write(HIG"ÇëÊäÈëÄãÒª²é¿´µÄÄÚÈÝ:"NOR);
                input_to("view5");
                return;
        }
        k--;
        w=explode(text[k],"==@==");
        file=read_file(w[1]);
        if(file) {
                start_help(file,this_object());
                return;
        }
        t=t+"/"+w[1];
        if(file_size(DIR+t+".h")<0)
        {
                write(HIG"Ã»ÓÐÕâ¸öÎÄ¼þ!\n"NOR);
                write(HIG"ÇëÊäÈëÄãÒª²é¿´µÄÄÚÈÝ:"NOR);
                input_to("view5");
                return;
        }
        this_player()->set_temp("select",t);
        display();
        return;
}
void delfile(string arg)
{
        int k=atoi(arg),v;
        string *text,*w,str=find_file(),file=read_file(str),t;
        if(arg=="q"||arg=="Q")
        {
                display();
                return;
        }
        if(k<1)
        {
                write(HIC"ÄãÒªÉ¾³ýµÚ¼¸ºÅÁ´½Ó:"NOR);
                input_to("delfile");
                return;
        }
        text=explode(file,"\n");
        if(v=sizeof(text)<k)
        {
                write(HIG"Ã»ÓÐÕâ¸öÁ´½Ó!\n");
                write(HIC"ÄãÒªÉ¾³ýµÚ¼¸ºÅÁ´½Ó:"NOR);
                input_to("delfile");
                return;
        }
        --k;
        w=explode(text[k],"==@==");
        text-=({text[k]});
        file=implode(text,"\n");
        write_file(str,file,1);
        t=replace_string(find_file(),".h","");
        t=t+"/"+w[1]+".h";
        if(rm(t))
        {
        }
        write("OK!\n");
        display();
        return;
}
varargs void display(object ob)
{
        int i;
        object me=this_player();
        string v,t=me->query_temp("select");
        if(!ob) ob=this_object();
        if(v=me->query_temp("memer"))
        {
                i=me->query(v);
                view_main_k();
                view1();
                write(view_msg(i,ob));
                view_main_1();
                write(YEL "\rÇëÊäÈëÄúµÄÑ¡Ôñ:"NOR);
                input_to((:confirm_p_choice:),ob);
                return;
        }
        if(t=="leaveword")
        {
                view6();
                write(YEL "\rÇëÊäÈëÄúµÄÑ¡Ôñ:"NOR);
                input_to((:confirm_l_choice:),this_player());
                return;
        }
        view_main();
        view3();
        view_main_1();
        write(BRED +HIC"(B)"NOR +BRED"·µ»Ø "NOR);
        if(wiz_level(WIZLEVEL)<=wiz_level(me))
        write(BRED +HIC"  (A)"NOR+BRED"¼ÓÈë "HIC+BRED"(C)"NOR+BRED"ÐÞ¸Ä "HIC+BRED"(D)"NOR
        +BRED"É¾³ý "HIC+BRED"(S)"NOR+BRED"²é¿´ "HIC+BRED"(M)"NOR+BRED"ÐÂ½¨"NOR);
        write("\n");
        write(YEL "\rÇëÊäÈëÄúµÄÑ¡Ôñ:"NOR);
        input_to((:confirm_choice:),this_player());
}
private void confirm_choice(string arg)
{
        object me=this_player();
        string t=me->query_temp("select");
        string *text;
        int k=atoi(arg);
        int p;
        if(k>0)
        {
                view5(arg);
                return;
        }
        switch(arg)
        {
                case "b":
                text=explode(t,"/");
                if(sizeof(text)<2)
                {
                        main(me,0);
                        return;
                }
                text-=({text[sizeof(text)-1]});
                t=implode(text,"/");
                me->set_temp("select",t);
                display();
                return;
                break;
                case "c":
                view7(0);
                return;
                break;
                case "a":
                if(wiz_level(me)<wiz_level(WIZLEVEL))
                {
                        write(HIR"ÄãµÄÈ¨ÏÞ²»×ã£¬²»ÄÜÐÞ¸ÄÕâÀïµÄµµ°¸£¡\n");
                        return;
                }
                write(HIC"ÇëÊäÈëÁ´½ÓÃû³Æ£º"NOR);
                input_to("getname1");
                return;
                break;
                case "d":
                if(wiz_level(me)<wiz_level(WIZLEVEL))
                {
                        write(HIR"ÄãµÄÈ¨ÏÞ²»×ã£¬²»ÄÜÐÞ¸ÄÕâÀïµÄµµ°¸£¡\n");
                        return;
                }
                write(HIC"ÄãÒªÉ¾³ýµÚ¼¸ºÅÁ´½Ó:"NOR"(¡°Q¡±È¡Ïû)");
                input_to("delfile");
                return;
                break;
                case "s":
                view_main();
                view4();
                view_main_1();
                write(BRED +HIC"(B)"NOR +BRED"·µ»Ø "NOR);
                if(wiz_level(WIZLEVEL)<=wiz_level(me))
                write(BRED +HIC"  (A)"NOR+BRED"¼ÓÈë "HIC+BRED"(C)"NOR+BRED"ÐÞ¸Ä "HIC+BRED"(D)"NOR
                +BRED"É¾³ý "HIC+BRED"(S)"NOR+BRED"²é¿´ "HIC+BRED"(M)"NOR+BRED"ÐÂ½¨"NOR);
                write("\n");
                write(YEL "\rÇëÊäÈëÄúµÄÑ¡Ôñ:"NOR);
                input_to((:confirm_choice:),me);
                return;
                break;
                case "m":
                if(wiz_level(me)<wiz_level(WIZLEVEL))
                {
                        write(HIR"ÄãµÄÈ¨ÏÞ²»×ã£¬²»ÄÜÐÞ¸ÄÕâÀïµÄµµ°¸£¡\n");
                        return;
                }
                write(HIC"ÇëÊäÈëÄ¿Â¼Ãû³Æ£º"NOR);
                input_to("getname3");
                return;
        }
        display();
        return;
}
void view6()
{
        int i,j,k;
        string *file,name,str="",msg;
        object ob;
        view_main();
        this_player()->delete_temp("memer");
        if(file_size(BOARDCENTER)>-1)
        {
                str=read_file(BOARDCENTER);
                write(str);
        }
        else {
                file=get_dir(BOARD+"*.c");
                for(i=0;i<sizeof(file);i++)
                {
                        if(!ob=find_object(BOARD+file[i]))
                        ob=load_object(BOARD+file[i]);
                        if(!ob||!ob->query("board_id"))
                        continue;
                        name=ob->query("name");
                        name=replace_string(name,"ÁôÑÔ°å","");
                        name=replace_string(name,"ÁôÑÔ²¾","");
                        name=replace_string(name,"ÁôÑÔ²á","");
                        name=replace_string(name,"µÜ×Ó","");
                        name=replace_string(name,"±¨¸æ","");
                        name=replace_string(name,"ÁôÑÔ","");
                        if(strlen(name)>16)
                        name=name[0..15];
                        destruct(ob);
                        msg=sprintf(" ¡º"HIC +BBLU+"%2d"NOR+"¡»"+HIW+"¡¾%|16s¡¿"NOR,i+1,name);
                        str+=msg;
                        write(msg);
                        ++j;
                        if(j==3)
                        {
                                j=0;
                                write("\n");
                                str+="\n";
                        }
                }  if(j==3) {
                        write("\n");
                        str+="\n";
                }
                str+=sprintf(" ¡º"HIC +BBLU+"%2s"NOR+"¡»"+HIW+"¡¾%|16s¡¿\n"NOR,"B","·µ»ØÖ÷²Ëµ¥");
                printf(" ¡º"HIC +BBLU+"%2s"NOR+"¡»"+HIW+"¡¾%|16s¡¿\n"NOR,"B","·µ»ØÖ÷²Ëµ¥");
                write_file(BOARDCENTER,str,1);
        }
        view_main_1();
        input_to((:confirm_k_choice:),this_player());
        return;
}
private void confirm_k_choice(string arg)
{
        int k=atoi(arg);
        string *file=get_dir(BOARD+"*.c"),dir;
        object ob;
        if(arg=="b")
        {
                main(this_player(),0);
                return;
        }
        else if(!k)
        {
                write(HIC"ÇëÊäÈëÄúµÄÑ¡Ôñ:"NOR);
                input_to((:confirm_k_choice:),this_player());
                return;
        }
        --k;
        dir=BOARD+file[k];
        if(!ob=find_object(dir))
        ob=load_object(dir);
        if(!ob||!ob->query("board_id"))
        {
                write(HIC"Ã»ÓÐÕâ¸öÁôÑÔ°å!\nÇëÊäÈëÄúµÄÑ¡Ôñ:"NOR);
                input_to((:confirm_k_choice:),this_player());
                return;
        }
        ob->restore();
        this_player()->set_temp("memer","post/"+file[k]);
        display(ob);
        return;
}
void getname3(string arg)
{
        int k;
        string dir,t=this_player()->query_temp("select"),
        *text,msg,*w,file=read_file(find_file());
        if(!file) file="";
        if(!arg||arg=="")
        {
                write(HIC"ÇëÊäÈëÄ¿Â¼Ãû³Æ£º"NOR);
                input_to("getname3");
                return;
        }
        if(arg=="q"||arg=="Q")
        {
                display();
                return;
        }
        k=strlen(arg);
        if(k<2||k>16)
        {
                write(HIG"Ä¿Â¼Ãû³Æ×ÖÊý±ØÐëÔÚ2µ½16¸ö×ÖÔªÖ®¼ä£¡\n"NOR);
                write(HIC"ÇëÊäÈëÄ¿Â¼Ãû³Æ£º"NOR);
                input_to("getname3");
                return;
        }
        dir=replace_string(find_file(),".h","");
        mkdir(dir);
        for(k=0;;k++)
        {
                t="subdir"+k;
                msg=dir+"/"+t+".h";
                if(file&&strsrch(file,t)<0)
                rm(msg);
                if(file_size(msg)>-1)
                continue;
                break;
        }
        file+=arg+"==@=="+t+"\n";
        text=explode(file,"\n");
        file="";
        write_file(msg,"",1);
        while(sizeof(text))
        {
                msg=text[0];
                text-=({msg});
                w=explode(msg,"==@==");
                t=replace_string(find_file(),".h","");
                t=t+"/"+w[1]+".h";
                if(file_size(w[1])<0&&file_size(t)<0)
                continue;
                file+=msg+"\n";
        }
        write_file(find_file(),file,1);
        write("OK!\n");
        display();
        return;
}

int help(object me)
{
write(@HELP
Ö¸Áî¸ñÊ½ : bangzhu
 
[36mÕâ¸öÖ¸ÁîÈÃÄã³¹µ×ÁË½âÃÎ»ÃÎ÷ÓÎ
Õâ¸ö[1;32mMUDLIB[2;37;0m[36mÏµÍ³,±¾ÏµÍ³ÓÐ´óÁ¿µÄ
½éÉÜºÍËµÃ÷,ÏêÇéÇëÓÃ[2;37;0m[1;36m[5mhelp[2;37;0m[36m»ò[1;36m[5mbangzhu[2;37;0m
[36mµÈµÈ.......[2;37;0m
[4;53m[1;31mBy tianlin@mhxy for 2001.10.7[2;37;0m
HELP
    );
    return 1;
}

