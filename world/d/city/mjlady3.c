//Cracked by Roath
//Aip@The.Never.Been.Place 6/16/1997
#include "ansi2.h"
//<A>// inherit F_SAVE;
inherit NPC;
inherit F_VENDOR;
#define RECORD_PLAYERS 4
#define END 286
#define START 0
#define BASIC_BET 0
#define BET_LIMIT 10000

void check_flower(mapping who);
string to_say_play();
string to_say_rule();
int do_check_Mj(string datastr,string str);
int do_check_eat(string num1,string num2,string LastDump);
int delete_last_dump(string whoId);
int do_check_win(string str,int flag);
int check_hu(string strW);
int set_mjdata(object me,int *score);
int get_tc(mapping who);
varargs int do_dump(string str,object me);
varargs int do_touch(string str,object me);
varargs int wash_mj(int amount);
varargs int do_win(string str,object me);
varargs int do_gon(string str,object me);
varargs int do_pon(string str,object me);
string check_id(string str,string kind);
string do_delete_Mj(string datastr,string str,int amount);
string show_mj(string str,int flag);
string sort_data(string str);
string show_site(string myid);
mixed do_check_num(string str,int flag);
string *do_sort_record(string type,string *keys);
string find_tin(string mymj);
//ÅÆÖ»×ÊÁÏ
string *Mjlist =({"1w","2w","3w","4w","5w","6w","7w","8w","9w","1t","2t","3t","4t","5t",
		"6t","7t","8t","9t","1s","2s","3s","4s","5s","6s","7s","8s","9s","ea",
		"so","we","no","jo","fa","ba","f1","f2","f3","f4","f5","f6","f7","f8"});
string MjE= "1w2w3w4w5w6w7w8w9w1t2t3t4t5t6t7t8t9t1s2s3s4s5s6s7s8s9seasowenojofabaf1f2f3f4f5f6f7f8";
string *MjC = ({"",
                "Ò»Íò","¶şÍò","ÈıÍò","ËÄÍò","ÎéÍò","ÁùÍò","ÆßÍò","°ËÍò","¾ÅÍò",
                "Ò»Í²","¶şÍ²","ÈıÍ²","ËÄÍ²","ÎéÍ²","ÁùÍ²","ÆßÍ²","°ËÍ²","¾ÅÍ²",
                "Ò»Ë÷","¶şË÷","ÈıË÷","ËÄË÷","ÎéË÷","ÁùË÷","ÆßË÷","°ËË÷","¾ÅË÷",
                "¶«·ç","ÄÏ·ç","Î÷·ç","±±·ç","ºìÖĞ","Çà·¢","°×°å",
                "£±´º","£²ÏÄ","£³Çï","£´¶¬","£±Ã·","£²À¼","£³Öñ","£´¾Õ","°µ¸Ü"
              });
int K;
string Tc = "";
//×ÊÁÏ
int Auto;
int Auto_Tin;
int Auto_Gon;
int Auto_Pon;
int Count;
int count;
int end;
int Goned;
int HU_F;
int NO_HU;
int NO_GON;
int Playing;
int Play;
int Times;
int Touched;
int NowPlayer;
int BetAmount=0;
string money_type;
string List ="";
string LookP ="";
string *NowPlayerId = ({ "","","","" }); //NowPlayerId[0] = ×¯¼Ò
string LastDumpId="";
string LastDump="";

mapping P1Data = ([
"Show": "color","Id": "","Name": "","Mj": "","Out": "","OutGon": "","OutPon": "",
"OutFlower": "","Auto": "","AutoTin": "","AutoGon": "","AutoPon": "","Dump": ""
               ]);
mapping P2Data = ([
"Show": "color","Id": "","Name": "","Mj": "","Out": "","OutGon": "","OutPon": "",
"OutFlower": "","Auto": "","AutoTin": "","AutoGon": "","AutoPon": "","Dump": ""
               ]);
mapping P3Data = ([
"Show": "color","Id": "","Name": "","Mj": "","Out": "","OutGon": "","OutPon": "",
"OutFlower": "","Auto": "","AutoTin": "","AutoGon": "","AutoPon": "","Dump": ""
               ]);
mapping P4Data = ([
"Show": "color","Id": "","Name": "","Mj": "","Out": "","OutGon": "","OutPon": "",
"OutFlower": "","Auto": "","AutoTin": "","AutoGon": "","AutoPon": "","Dump": ""
               ]);
mapping record=([]);
void create()
{
      set_name("Âé½«ÏÉ¹Ã",({"mj lady","lady"}));
	set("long",@LONG

  Ò»¸öÑıÑŞµÄĞ¡ÏÉ¹ÃÕıÔÚ¶¢ÖøÄã¡£
	
LONG
);
        set_weight(1);
        set("gender","Å®ĞÔ");
        set("level",35);
        set("age",18);
        set("attitude", "friendly");
        set("unit","Î»");
        set("inquiry",([
           "mj": (: to_say_play :),
           "Âé½«": (: to_say_play :),
           "Íæ·¨": (: to_say_play :),
           "play": (: to_say_play :),
           "¹æÔò": (: to_say_rule :),
           "rule": (: to_say_rule :),
           ]));
        setup();
        seteuid(getuid());
//<A>//	if( !restore() )
//<A>//        {
//<A>//        	record = ([]);
//<A>//        }
//	record = RECORD_D->query_mj_data();
}

void init()
{
   add_action("do_bet","bet");
   add_action("do_addin","addin");
   add_action("do_dump","dump");
   add_action("do_dump","dd");
   add_action("do_eat","eat");
   add_action("do_gon","gon");
   add_action("do_win","hu");
   add_action("do_help","help");
   add_action("do_look","look");
   add_action("do_look",".");
   add_action("do_look",".1");
   add_action("do_look",".2");
   add_action("do_look",".3");
   add_action("do_look",".4");
   add_action("do_look","..");
   add_action("do_touch","mo");
   add_action("do_touch","0");
   add_action("do_pon","pon");
   add_action("do_pon","p");
   add_action("do_restart","restart");
   add_action("wash_mj","start");
   add_action("do_setmj","setmj");
   add_action("show_top","top");
   add_action("do_tin","tin");
   add_action("ch","ch");
   add_action("do_showmj","showmj");
     add_action("discmds",({"tell","whisper","reply","persuade","teach","exert","exercise","study","learn","sleep","kill","steal","cast","conjure","expell","fight","hit","perform","prcatice","scribe","surrender"}));
}
 int discmds()
{
    tell_object(this_player(),"»¹ÊÇÀÏÀÏÊµÊµ´òÂé½«°É£¿£¡\n");
    return 1;
}
/*
int sort_user(string str1, string str2)
{
	int t1,t2;
	if(sscanf(str1,"%*s %*d %*d %*d %*d %d %*d\n",t1)==-1) return 0;
	if(sscanf(str2,"%*s %*d %*d %*d %*d %d %*d\n",t2)==-1) return 0;
	//return strcmp(str1[45..50],str2[45..50]);
	return t1>t2;
}
*/
/*
int sort_user(mapping str1, mapping str2)
{
	return str1["total"] < str2["total"];
}
*/

int query_Play() { return Play; }
mapping query_record() { return record; }
int clear_record() { record=([ ]); this_object()->save(); return 1; }
int test_record(string id,int aa,int bb,int cc,int dd,int ee,int ff)
{
	record[id] = ([
		"name": id,
		"rounds" : aa,
		"self" : bb,
		"win" : cc,
		"lose" : dd,
		"total" : ee,
		"bad" : ff,
		]);
	return 1;
}
int do_addin()
{
        object me=this_player();
        if(!userp(me)) return 0;
        if (me->query("id")==P1Data["Id"]
        ||  me->query("id")==P2Data["Id"]
        ||  me->query("id")==P3Data["Id"]
        ||  me->query("id")==P4Data["Id"]){
            if (!Playing) message_vision("$N´óº°: [Ç·½Å°¡¡«¡«] ²»Í£µÄ¿Ş¿ŞÌäÌä.....¡£\n",me);
            else message_vision("$N¶ÔÖø´ó¼ÒËµ: ½ñÌì×ÔÃş"+(random(12)+1)+"´Î¾ÍºÃ¡£\n",me);
            return 1;
        }
       if (Playing){
                if (random(2))
                message_vision(this_object()->name()+
                "¶ÔÖø"+me->name()+"Ëµ£º ÅÆ¾ÖÕıÔÚ½øĞĞÖĞÇëµ½ÅÔ±ß×øÒ»ÏÂ...¡£\n",me);
                else  message_vision("$Nº°Öø: [ÎÒÒ²ÒªÍæÀ²¡«¡«] ²»Í£µÄ¿Ş¿ŞÌäÌä.....¡£\n",me);
                return 1;
        }
        if (BetAmount>0) {
        	switch(me->money_type())
        	{
        		case 1:
        			if(me->query("bank/past")<BetAmount*5) {
        				message_vision(this_object()->name()+
        				"¶ÔÖø"+me->name(1)+"Ëµ£º ÄãµÄÕÊ»§ÀïÃæÃ»ÓĞ×ã¹»µÄ¶Ä×Ê¡£\n",me);
        				return 1;
        			}
        			break;	
        		case 2:
        			if(me->query("bank/now")<BetAmount*5) {
        				message_vision(this_object()->name()+
        				"¶ÔÖø"+me->name(1)+"Ëµ£º ÄãµÄÕÊ»§ÀïÃæÃ»ÓĞ×ã¹»µÄ¶Ä×Ê¡£\n",me);
        				return 1;
        			}
        			break;
        		case 3:
        			if(me->query("bank/future")<BetAmount*5) {
        				message_vision(this_object()->name()+
        				"¶ÔÖø"+me->name(1)+"Ëµ£º ÄãµÄÕÊ»§ÀïÃæÃ»ÓĞ×ã¹»µÄ¶Ä×Ê¡£\n",me);
        				return 1;
        			}
        			break;
        		default:
        			break;
        	}
        }
        if (!P1Data["Id"] || P1Data["Id"]==""){
           P1Data["Id"]=me->query("id");
           NowPlayerId[Play]=me->query("id");
           message_vision("$N¼ÓÈëÁËÕâ³¡ÅÆ¾Ö¡£\n",me);
           Play++;
           Times=0;
           LookP+="ÔÚÇ°ÃæÓĞ"+me->name()+"£¬";
           return 1;
        }else if (!P2Data["Id"] || P2Data["Id"]==""){
                 P2Data["Id"]=me->query("id");
                 message_vision("$N¼ÓÈëÁËÕâ³¡ÅÆ¾Ö¡£\n",me);
                 NowPlayerId[Play]=me->query("id");
                 Play++;
                 Times=0;
                 LookP+=me->name()+"£¬";
                 return 1;
        }else if (!P3Data["Id"] || P3Data["Id"]==""){
                 P3Data["Id"]=me->query("id");
                 message_vision("$N¼ÓÈëÁËÕâ³¡ÅÆ¾Ö¡£\n",me);
                 NowPlayerId[Play]=me->query("id");
                 Play++;
                 Times=0;
                 LookP+=me->name()+"£¬";
                 return 1;
        }else if (!P4Data["Id"] || P4Data["Id"]==""){
                 P4Data["Id"]=me->query("id");
                 message_vision("$N¼ÓÈëÁËÕâ³¡ÅÆ¾Ö¡£\n",me);
                 NowPlayerId[Play]=me->query("id");
                 Play++;
                 Times=0;
                 LookP+=me->name();
                 return wash_mj(Play);
        }
        return notify_fail("ÈËÊıÒÑ×ã¡£\n");
}
int do_dump(string str,object me)
{
        int check,i;
        int *score=({ 0,0,0,0,0 });
        string ponid;
        mapping who;
        object met,user;
 
        if (!me) me=this_player();
        if (check_id(me->query("id"),"player")!="");
        else {
           command("stare "+me->query("id"));
           command("say ÕâÅÆ¾Ö¸úÄãÃ»¹ØÏµ¡£");
           return 1;
        }
        if (!Playing){
           command("kick "+me->query("id"));
           command("say ÅÆ¾Ö»¹Ã»¿ªÊ¼Çë²»ÒªÄÃÅÆÂÒ¶ª!!");
           return 1;
        }
        tell_object(me,"»»Ë­´òÅÆ:"+NowPlayerId[NowPlayer]+"\n");
        if (!str) return notify_fail("Ö¸Áî:dump <´úÂë>\n");
        if (me->query("id")!=NowPlayerId[NowPlayer]){
           command("hammer "+me->query("id"));
           command("say ÏëÍµ´òÅÆ!!×÷±×¨Ú?");
           return 1;
        }
        if (!Touched){
           command("faint "+me->query("id"));
           command("say Äã»¹Ã»ÃşÅÆ!!");
           return 1;
        }
        if (Goned==5){
           message_vision("$NËµµÀ£º´Ë¾ÖÒò"+HIR+"Îå¸ÜºÏÅÆ"+NOR+"ÇëÔÙÖØĞÂ¿ªÊ¼ start ¡£\n",this_object());
           Playing=0;
           Count++;
           if (Play>=RECORD_PLAYERS){
              for (i=0;i<Play;i++){
                  met=present(NowPlayerId[i], environment(this_object()));
                  if (!met) met=find_player(NowPlayerId[i]);
                  if (!met);
                  else{
                     score = ({ 0,0,0,0,0 });
                     set_mjdata(met,score);
                     //this_object()->save();
                  }
              }
           }
           return 1;
        }
        NO_HU=0;
        HU_F=0;
        NO_GON=0;
        if (me->query("id")==P1Data["Id"]) who=P1Data;
        else if (me->query("id")==P2Data["Id"]) who=P2Data;
        else if (me->query("id")==P3Data["Id"]) who=P3Data;
        else if (me->query("id")==P4Data["Id"]) who=P4Data;
        check=do_check_Mj(MjE,str);
        if (check==0) return notify_fail("Ã»ÓĞ["+str+"]ÕâÖÖ´úÂë¡£\n");
        check=do_check_Mj(who["Mj"],str);
        if (check==0) return notify_fail("ÄãÃ»"+do_check_num(str,0)+"ÕâÕÅÅÆ¡£\n");
        tell_object(me,"ÄãËµµÀ£º"+do_check_num(str,0)+"\n");
        tell_room(environment(this_object()),YEL+me->name()+"Ëµ£º"+do_check_num(str,0)+"¡£\n"+NOR,me);
//        command("say "+me->name()+"´ò³öÁËÒ»ÕÅ.."+do_check_num(str,0));
        message_vision("$N´ò³öÁËÒ»ÕÅ.."+do_check_num(str,3)+"\n",me);
        who["Mj"]=do_delete_Mj(who["Mj"],str,1);
        LastDump=str;
        who["Dump"]+=str;
        LastDumpId=who["Id"];
        Touched=0;
        NowPlayer++;
        NowPlayer%=Play;
        message_vision(YEL+"$NËµ£º»¹Ê£ÏÂ["HIC+(end-count-16-Goned)/2+NOR+YEL+"]ÕÅÅÆ¿ÉÃş£¬ÏÖÔÚÂÖµ½ "+HIY+capitalize(NowPlayerId[NowPlayer])+NOR+YEL+" ÃşÅÆ¡£\n"+NOR,this_object());
        if(user = present(NowPlayerId[NowPlayer], environment(this_object())))
        {
        	tell_object(user,HIW+"< ¸ÃÄãÂŞ!! >\n"+NOR);
        }
        if (Auto_Tin){
           ponid=check_id(str,"tin");
           if (ponid!=""){
              me=present(ponid, environment(this_object()));
              if (!me) me=find_player(ponid);
              if (!me) return 1;
              return do_win(str,me);
           }
        }
        if (Auto_Gon){
           ponid=check_id(str,"gon");
           if (ponid!=""){
              me=present(ponid, environment(this_object()));
              if (!me) me=find_player(ponid);
              if (!me) return 1;
              do_gon(str,me);
           }
        }
        if (Auto_Pon){
           ponid=check_id(str,"pon");
           if (ponid!=""){
              me=present(ponid, environment(this_object()));
              if (!me) me=find_player(ponid);
              if (!me) return 1;
              do_pon(str,me);
           }
        }
        if (count==(end-16-Goned)){
           Playing=0;
           Count++;
           message_vision(YEL+"$NËµ£º´Ë¾Ö"+HIC+"Á÷¾Ö"+NOR+YEL+"ÇëÔÙÖØĞÂ¿ªÊ¼ "+HIR+"start"+NOR+YEL+" ¡£\n"+NOR,this_object());
           //str="ËùÊ£ÏÂµÄÅÆÖ»ÓĞ:"+show_mj(List[count..end],2)+"\n";
           //tell_room(environment(this_object()),str);
           if (Play>=RECORD_PLAYERS){
              for (i=0;i<Play;i++){
                  met=present(NowPlayerId[i], environment(this_object()));
                  if (!met) met=find_player(NowPlayerId[i]);
                  if (met)
                  {
                     score = ({ 0,0,0,0,0 });
                     set_mjdata(met,score);
                     //this_object()->save();
                  }
              }
           }
           return 1;
        }
        if (Auto){
           if (NowPlayerId[NowPlayer]==P1Data["Id"]) who=P1Data;
           else if (NowPlayerId[NowPlayer]==P2Data["Id"]) who=P2Data;
           else if (NowPlayerId[NowPlayer]==P3Data["Id"]) who=P3Data;
           else if (NowPlayerId[NowPlayer]==P4Data["Id"]) who=P4Data;
           if (who["Auto"]=="auto"){
              me=present(NowPlayerId[NowPlayer], environment(this_object()));
              if (!me) me=find_player(NowPlayerId[NowPlayer]);
              if (!me) return 1;
              call_out("do_touch",1,"AUTO",me);
           }
        }
        return 1;
}
int do_eat(string str)
{
        int LastDumpMan,i;
        string num1,num2;
        object me=this_player();
        mapping who;
 
        if (!str || sscanf(str,"%s %s",num1,num2)!=2) return 0;
        if (check_id(me->query("id"),"player")!="");
        else {
           command("stare "+me->query("id"));
           command("say ÕâÅÆ¾Ö¸úÄãÃ»¹ØÏµ¡£");
           return 1;
        }
        if (!Playing){
           command("say ÅÆ¾Ö»¹Ã»¿ªÊ¼¡£");
           return 1;
        }
        tell_object(me,"»»Ë­ÃşÅÆ:"+NowPlayerId[NowPlayer]+"\n");
        if (me->query("id")!=NowPlayerId[NowPlayer]){
           command("hammer "+me->query("id"));
           command("say »¹Ã»ÂÖµ½Äã¡£");
           return 1;
        }
        if (!LastDump || LastDump==""){
           command("hammer "+me->query("id"));
           command("say ÃşÅÆ°É¡£");
           return 1;
        }
        if (Touched){
           command("flop "+me->query("id"));
           command("say ´òÅÆÀ²!!");
           return 1;
        }
        if (do_check_eat(num1,num2,LastDump)==0){
           command("flop "+me->name());
           command("say ÄãÑÛ¾¦»¨ÁË¨Ú!!ÕâÑùÒ²ÄÜ³Ô¡£");
           return 1;
        }
        if (num1==num2){
           command("flop "+me->name());
           command("say ÏàÍ¬µÄÅÆ²»ÄÜ³Ô£¬Ö»ÄÜÓÃÅö(pon)µÄ¡£");
           return 1;
        }
        if (me->query("id")==P1Data["Id"]) who=P1Data;
        else if (me->query("id")==P2Data["Id"]) who=P2Data;
        else if (me->query("id")==P3Data["Id"]) who=P3Data;
        else if (me->query("id")==P4Data["Id"]) who=P4Data;
        LastDumpMan=do_check_Mj(MjE,num1);
        if (LastDumpMan==0) return notify_fail("Ã»ÓĞ["+num1+"]ÕâÖÖ´úÂë¡£\n");
        LastDumpMan=do_check_Mj(MjE,num2);
        if (LastDumpMan==0) return notify_fail("Ã»ÓĞ["+num2+"]ÕâÖÖ´úÂë¡£\n");
        LastDumpMan=do_check_Mj(who["Mj"],num1);
        if (LastDumpMan==0) return notify_fail("ÄãÃ»"+do_check_num(num1,0)+"ÕâÕÅÅÆ¡£\n");
        LastDumpMan=do_check_Mj(who["Mj"],num2);
        if (LastDumpMan==0) return notify_fail("ÄãÃ»"+do_check_num(num2,0)+"ÕâÕÅÅÆ¡£\n");
 message_vision(HIG+"\n¡¾ ¡« ³Ô ¡« ¡¿"+NOR+"\n$NÄÃ³öÁËÒ»ÕÅ"+do_check_num(num1,3)+
                      "ÓëÒ»ÕÅ"+do_check_num(num2,3)+
                      "³ÔÏÂÁË"+do_check_num(LastDump,3)+"¡£\n\n",me);
        who["Out"]+=num2;
        who["Out"]+=LastDump;
        who["Out"]+=num1;
        who["Mj"]=do_delete_Mj(who["Mj"],num1,1);
        who["Mj"]=do_delete_Mj(who["Mj"],num2,1);
        Touched=1;
        NO_HU=1;
        NO_GON=1;
        i=0;
        if (who["Show"]=="´úÂë") i=3;
        if (who["Show"]=="color") i=5;
        tell_object(me,show_mj(who["Mj"],i));
        return delete_last_dump(who["Id"]);
}
int do_gon(string str,object me)
{
        int i;
        mapping who;
 
        if (!me) me=this_player();
        if (check_id(me->query("id"),"player")!="");
        else {
           command("stare "+me->query("id"));
           command("say ÕâÅÆ¾Ö¸úÄãÃ»¹ØÏµ¡£");
           return 1;
        }
        if (!Playing){
           command("say ÅÆ¾Ö»¹Ã»¿ªÊ¼!!");
           return 1;
        }
        if (LastDumpId==me->query("id") && !str){
           command("stare "+me->query("id"));
           command("say ÄÇÕÅÅÆÊÇÄã×Ô¼º´òµÄ¡£");
           return 1;
        }
        if (Touched && NowPlayerId[NowPlayer]!=me->query("id")){
           command("hammer "+me->query("id"));
           command("say ±ğÈËÃ»´òÅÆÄãÔõÃ´¸Ü¡£");
           return 1;
        }
        if (!str) str=LastDump;
 
        if (me->query("id")==P1Data["Id"]) who=P1Data;
        else if (me->query("id")==P2Data["Id"]) who=P2Data;
        else if (me->query("id")==P3Data["Id"]) who=P3Data;
        else if (me->query("id")==P4Data["Id"]) who=P4Data;
        if (who["Auto"]=="auto") return 1;
        i=do_check_Mj(who["Mj"],str);
        if (i==1){
           if (!Touched) return notify_fail("Äã»¹Ã»ÃşÅÆ¡£\n");
           i=do_check_Mj(who["OutPon"],str);
           if (!i) return notify_fail("ÄãÖ»ÓĞÒ»ÕÅ²»ÄÜ¸Ü¡£\n");
           if (NO_GON) return notify_fail("ÕâÑùÎŞ·¨¸ÜÅÆ¡£\n");
              message_vision("\n$NËµµÀ£º"+HIB+"¡¾ ¡« ¸Ü ¡« ¡¿"+NOR+"\n\n",me);
              who["Mj"]=do_delete_Mj(who["Mj"],str,1);
              sort_data(who["OutPon"]+=str);
              str=List[end..end+1];
              end-=2;
              Goned++;
              message_vision("\n$N´ÓºóÃæ²¹ÁËÒ»ÕÅÅÆ¡£\n\n",me);
              write(sprintf("Äã²¹µ½Ò»ÕÅ%s\n",do_check_num(str,0)));
              i=0;
              if (who["Show"]=="´úÂë") i=3;
              if (who["Show"]=="color") i=5;
              who["Mj"]+=str;
              check_flower(who);
              tell_object(me,show_mj(who["Mj"],i));
              Touched=1;
              return 1;
        }
        if (i < 3) return notify_fail("ÄãÊÖÖĞÒªÓĞÈıÕÅ"+do_check_num(str,0)+"²ÅÄÜ¸Ü¡£\n");
        if (!Touched){
           if (str!=LastDump) return notify_fail("ÕâÑùÎŞ·¨¸Ü¡£\n");
        }
        else if (i < 4) return notify_fail("ÄãÊÖÖĞÒªÓĞËÄÕÅ"+do_check_num(str,0)+"²ÅÄÜ°µ¸Ü¡£\n");
        for (i=0;i<Play;i++) {
            if (NowPlayerId[NowPlayer]==me->query("id")) break;
            NowPlayer++;
            NowPlayer%=Play;
        }
        who["Mj"]=do_delete_Mj(who["Mj"],str,3);
        who["AutoGon"]=do_delete_Mj(who["AutoGon"],str,1);
        if (Touched && NowPlayerId[NowPlayer]==me->query("id")){
           NO_HU=0;
           if(random(2)) message_vision("\n$NÁ³ÉÏÂ¶³öĞ°¶ñµÄĞ¦ÈİËµ£º²»ºÃÒâË¼..ÎÒ°µ¸Ü..hehe...\n\n",me);
           else message_vision("\n$NÃæÎŞ±íÇéµÄËµ£ºÕâ´Î°µ¸Ü´ó¸Å»á¸ÜËÀÒ»¶ÑÈË¡£\n\n",me);
           who["Mj"]=do_delete_Mj(who["Mj"],str,1);
           for (i=0;i<4;i++) who["Out"]+="xx";
           for (i=0;i<4;i++) who["OutGon"]+=str;
        }else{
           NO_HU=1;
           message_vision("\n$N´ó½Ğ£º"+do_check_num(str,0)+"¡«"+HIW+"¡¾ ¡« ¸Ü ¡« ¡¿"+NOR+"\n\n",me);
           for (i=0;i<4;i++) who["Out"]+=str;
        }
        str=List[end..end+1];
        end-=2;
        Goned++;
        message_vision("$N´ÓºóÃæ²¹ÁËÒ»ÕÅÅÆ¡£\n",me);
        tell_object(me,"Äã²¹µ½Ò»ÕÅ"+do_check_num(str,0)+"\n");
        who["Mj"]+=str;
        check_flower(who);
        i=0;
        if (who["Show"]=="´úÂë") i=3;
        if (who["Show"]=="color") i=5;
        tell_object(me,show_mj(who["Mj"],i));
        if (Touched) return 1;
        Touched=1;
        return delete_last_dump(who["Id"]);
}
varargs int do_win(string str,object me)
{
        int i,j,money,b=0,bb=0;
        int *score=({0,0,0,0,0});
        string Mj="";
        mapping who;
        object met;
 
        if (!me) me=this_player();
        if (check_id(me->query("id"),"player")!="");
        else {
           command("stare "+me->query("id"));
           command("say ÕâÅÆ¾Ö¸úÄãÃ»¹ØÏµ¡£");
           return 1;
        }
        if (!Playing){
           command("say ÅÆ¾Ö»¹Ã»¿ªÊ¼...");
           return 1;
        }
        if ( NO_HU ) return notify_fail("ÕâÑù²»ÄÜºúÅÆ¡£\n");
        if (LastDump==""&&Touched) message_vision("\n$N´ó½Ğ£º"+HIW+"¡¾ Ìì ¡«¡« ºú ¡«¡«¡¿"+NOR+"\n\n",me);
        else{
             tell_room(environment(this_object()),"\n"+me->name()+"´ó½Ğ£º"+HIW+"¡¾ ÎÒ¡«ºú¡«À²¡« ¡¿"+NOR+"\n\n",me);
             tell_object(me,"\nÄã´ó½Ğ£º"+HIW+"ÎÒ¡«ºú¡«À²¡«"+NOR+"\n\n");
        }
        if (Touched&&NowPlayerId[NowPlayer]==me->query("id"))
           message_vision("$NËµµÀ£ººú¼Ò"+me->name()+HIG+"×ÔÃş"+NOR+"¡«¡«¡«¡«¡«¡«¡«"+HIR+"³Ôºì"+NOR+"¡«¡«¡«¡«¡«\n",this_object());
        else if ( LastDumpId==me->query("id") ) {
        	command("slap "+me->query("id"));
        	//return notify_fail("ÄãÒªºúÄã×Ô¼º´òµÄÅÆ??\n");
        	command("say ÄãÒªºúÄã×Ô¼º´òµÄÅÆ??");
        	return 1;
        }
        else command("say "+me->name()+"ºúÁË");
        if (me->query("id")==P1Data["Id"]) who=P1Data;
        else if (me->query("id")==P2Data["Id"]) who=P2Data;
        else if (me->query("id")==P3Data["Id"]) who=P3Data;
        else if (me->query("id")==P4Data["Id"]) who=P4Data;
        if (sizeof(who["OutFlower"]) ==16) i=1;
        else if (sizeof(who["OutFlower"]) ==14&&sizeof(P1Data["OutFlower"]+P2Data["OutFlower"]+P3Data["OutFlower"]+P4Data["OutFlower"])==16) i=1;
        if (!HU_F) i=0;
        if (i){
           Mj+="ºú¼ÒµÄ»¨ÅÆÊÇ:\n";
           Mj+=show_mj(who["OutFlower"],1);
           if (NowPlayerId[NowPlayer]==who["Id"]) Mj+="ºú¼Ò»¨ÅÆ×ÔÃş\n";
           else{
             if (sizeof(P1Data["OutFlower"])==2) LastDumpId=P1Data["Id"];
             else if (sizeof(P2Data["OutFlower"])==2) LastDumpId=P2Data["Id"];
             else if (sizeof(P3Data["OutFlower"])==2) LastDumpId=P3Data["Id"];
             else if (sizeof(P4Data["OutFlower"])==2) LastDumpId=P4Data["Id"];
             Mj+="\n»¨ÅÆ·ÅÇ¹Õß:"+HIB+LastDumpId+NOR+"\n";
           }
        }else{
          Mj+="ºú¼ÒµÄÅÆÊÇ:\n";
          if (who["OutGon"]!=""){
             Mj+="°µ¸ÜµÄÓĞ:\n";
             Mj+=show_mj(who["OutGon"],0);
          }
          Mj+=who["Id"]+":ÊÖÖĞµÄÅÆÓĞ:\n";
          if (!Touched){
             who["Mj"]+=LastDump;
             who["Mj"]=sort_data(who["Mj"]);
             Mj+=show_mj(who["Mj"],0);
             Mj+="ËùºúµÄÅÆÊÇ:"+HIR+do_check_num(LastDump,0)+NOR;
             Mj+="\n·ÅÇ¹Õß:"+HIB+LastDumpId+NOR+"\n";
          }else{
             Mj+=show_mj(who["Mj"],0);
             if (str) Mj+="Ëù×ÔÃşµÄÅÆÊÇ:"+HIR+do_check_num(str,0)+NOR+"\n";
          }
        }
        Playing=0;
        tell_room(environment(this_object()),Mj);
        Tc="";
//        message_vision("CheckWin=["+who["Mj"]+"] \n",this_object());
        if (do_check_win(who["Mj"],0)==1||i==1){
//ËãÌ¨///////////////////////////////////
        mixed MjT = ([
"@1" : ({ "×¯¼Ò", 1 }),"@2" : ({ "×ÔÃş", 1 }),"@3" : ({ "»¨ÅÆ", 1 }),"@4" : ({ "ÃÅÇå", 1 }),
"@5" : ({ "¶«·ç", 1 }),"@6" : ({ "ÄÏ·ç", 1 }),"@7" : ({ "Î÷·ç", 1 }),"@8" : ({ "±±·ç", 1 }),
"@9" : ({ "ºìÖĞ", 1 }),"@0" : ({ "Çà·¢", 1 }),"@a" : ({ "°×°å", 1 }),"@G" : ({ "Ò»±­¿Ú", 1 }),
"@b" : ({ "º£µ×ÃşÔÂ", 1 }),"@c" : ({ "º£µ×ÀÌÓã", 1 }),"@d" : ({ "Æ½ºú", 2 }),"@e" : ({ "¶«·ç¶«", 2 }),
"@f" : ({ "ÄÏ·çÄÏ", 2 }),"@g" : ({ "Î÷·çÎ÷", 2 }),"@h" : ({ "±±·ç±±", 2 }),"@i" : ({ "È«ÇóÈË", 2 }),
"@j" : ({ "Èı°µ¿Ì", 2 }),"@H" : ({ "¶ş±­¿Ú", 2 }),"@k" : ({ "Èı¸Ü×Ó", 2 }),"@B" : ({ "´ºÏÄÇï¶¬", 2 }),
"@C" : ({ "Ã·À¼¾ÕÖñ", 2 }),"@l" : ({ "ÃÅÇå×ÔÃş", 3 }),"@m" : ({ "ÅöÅöºú", 4 }),"@n" : ({ "»ìÒ»É«", 4 }),
"@o" : ({ "Ğ¡ÈıÔª", 4 }),"@p" : ({ "ËÄ°µ¿Ì", 6 }),"@q" : ({ "ÇåÒ»É«", 8 }),"@r" : ({ "×ÖÒ»É«", 8 }),
"@s" : ({ "Æß¶Ô×Ó", 8 }),"@t" : ({ "´óÈıÔª", 8 }),"@u" : ({ "Îå°µ¿Ì", 8 }),"@F" : ({ "Ğ¡ËÄÏ²", 8 }),
"@D" : ({ "ÆßÇÀÒ»", 8 }),"@E" : ({ "ÂÌÒ»É«", 16 }),"@v" : ({ "´óËÄÏ²", 16 }),"@w" : ({ "Ììºú", 16 }),
"@x" : ({ "µØºú", 16 }),"@y" : ({ "ÈËºú", 16 }),"@z" : ({ "¹úÊ¿ÎŞË«", 16 }),"@A" : ({ "°ËÏÉ¹ıº£", 16 }),
"@J" : ({ "ÇåÀÏÍ·", 8 }),"@I" : ({ "»ìÀÏÍ·", 4 }),
]);//H
           get_tc(who);
////////////////
           str="\t\t\t¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô\n";
           for (i=0;i<sizeof(Tc);i+=2){
              str+=sprintf("\t\t\t%-12s%8s Ì¨\n",MjT[Tc[i..i+1]][0],chinese_number(MjT[Tc[i..i+1]][1]));
              j+=MjT[Tc[i..i+1]][1];
           }
           if (Count){
              if(NowPlayerId[0]==who["Id"]) //±¾ÈË×¯¼Ò
              {
              	str+=sprintf("\t\t\t%-12s%8s Ì¨\n","Á¬"+chinese_number(Count)+"À­"+chinese_number(Count),chinese_number(Count*2));
              	j+=Count*2;
              } else
              {
              	b=1+Count*2;
              }
           }
           str+=sprintf("\t\t\t»ù±¾Ì¨            Èı Ì¨\n\t\t\t%20s\n","×ÜÌ¨Êı:"+chinese_number(j+3)+" Ì¨");
           str+="\t\t\t¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô\n";
           if(b!=0 && (Touched || LastDumpId==NowPlayerId[0]))
           {
           	str+="×¯¼ÒÊÇ "+NowPlayerId[0]+" Áí¼Æ\n";
           	str+=sprintf("\t\t\t%-12s%8s Ì¨\n","×¯¼Ò","Ò»");
           	str+=sprintf("\t\t\t%-12s%8s Ì¨\n","Á¬"+chinese_number(Count)+"À­"+chinese_number(Count),chinese_number(Count*2));
           }
           tell_room(environment(this_player()),str);
/////////////
           if(!Touched)
           {
              if (Play>=RECORD_PLAYERS)
              {
                 met=present(LastDumpId, environment(this_object()));
                 if (!met) met=find_player(LastDumpId);
                 if(met)
                 {
		    // ({ ×ÔÃş,ºúÅÆ,·ÅÇ¹,Ì¨Êı<·ÅÇ¹Îª¸ºµÄ>,·¸¹æ })
                    score = ({ 0,0,1,-j-3-b,0 });
                    set_mjdata(met,score);
                    //this_object()->save();
	                switch(met->money_type())
	        	{
	        		case 1:
					money = met->query("bank/past");
	        			if(money<(j+3+b)*BetAmount) {
	        				message_vision("$NÒòÎª¸¶²»³öÇ®À´ºÜ²»ºÃÒâË¼µÄ¿´Öø$nÉµĞ¦¡£\n",met,me);
	        			}
	        			else {
	        				met->add("bank/past",(-BetAmount*(j+3+b)));
	        			        me->add("bank/past",(BetAmount*(j+3+b)));
	        			        message_vision("$NºÜ²»·şÆøµÄ×ªÕÊ"+BetAmount*(j+3+b)+"¸ø$n¡£\n",met,me);
	        			     }
	        			break;	
	        		case 2:
					money = met->query("bank/now");
	        			if(money<(j+3+b)*BetAmount) {
	        				message_vision("$NÒòÎª¸¶²»³öÇ®À´ºÜ²»ºÃÒâË¼µÄ¿´Öø$nÉµĞ¦¡£\n",met,me);
	        			}
	        			else {
	        				met->add("bank/now",(-BetAmount*(j+3+b)));
	        			        me->add("bank/now",(BetAmount*(j+3+b)));
	        			        message_vision("$NºÜ²»·şÆøµÄ×ªÕÊ"+BetAmount*(j+3+b)+"¸ø$n¡£\n",met,me);
	        			     }
	        			break;	
	        		case 3:
					money = met->query("bank/future");
	        			if(money<(j+3+b)*BetAmount) {
	        				message_vision("$NÒòÎª¸¶²»³öÇ®À´ºÜ²»ºÃÒâË¼µÄ¿´Öø$nÉµĞ¦¡£\n",met,me);
	        			}
	        			else {
	        				met->add("bank/future",(-BetAmount*(j+3+b)));
	        			        me->add("bank/future",(BetAmount*(j+3+b)));
	        			        message_vision("$NºÜ²»·şÆøµÄ×ªÕÊ"+BetAmount*(j+3+b)+"¸ø$n¡£\n",met,me);
	        			     }
	        			break;
	        		default:
	        			break;
	        	}
                 }
                 
		 score = ({ 0,1,0,j+3+b,0}); // ({ ×ÔÃş,ºúÅÆ,·ÅÇ¹,Ì¨Êı<·ÅÇ¹Îª¸ºµÄ>,·¸¹æ })
                 set_mjdata(me,score);
		                  
                 for (i=0;i<Play;i++)
                 {
                     if(NowPlayerId[i]==LastDumpId) continue;
                     if(NowPlayerId[i]==me->query("id")) continue;
                     met=present(NowPlayerId[i], environment(this_object()));
                     if (!met) met=find_player(NowPlayerId[i]);
                     if (!met);
                     else
                     {
                        score = ({ 0,0,0,0,0 });  // ({ ×ÔÃş,ºúÅÆ,·ÅÇ¹,Ì¨Êı<·ÅÇ¹Îª¸ºµÄ>,·¸¹æ })
                        set_mjdata(met,score);
                        //this_object()->save();
                     }
                 }
                 
              }
           }
           else
           { //×ÔÃş
              if (Play>=RECORD_PLAYERS )
              {
              	 CHANNEL_D->do_channel( this_object(), "game", sprintf("¹§Ï²³¬¼¶Íæ¼Ò%s×ÔÃşÀ²!! ¶ÀÓ® %d Ì¨!!\n",
					me->name_id(1), (j+3)*(Play-1)+b));
		 score = ({ 1,0,0,(j+3)*(Play-1)+b,0 });  // ({ ×ÔÃş,ºúÅÆ,·ÅÇ¹,Ì¨Êı<·ÅÇ¹Îª¸ºµÄ>,·¸¹æ })
                 set_mjdata(me,score);
                 for(i=0;i<Play;i++)
                 {
                     if(NowPlayerId[i]==me->query("id")) continue;
                     met=present(NowPlayerId[i], environment(this_object()));
                     if(!met) met=find_player(NowPlayerId[i]);
                     if(met)
                     {
			if(Count && NowPlayerId[0]==NowPlayerId[i]) bb = b;
			else bb=0;
			score = ({ 0,0,0,-j-3-bb,0 });  // ({ ×ÔÃş,ºúÅÆ,·ÅÇ¹,Ì¨Êı<ÊäÎª¸ºµÄ>,·¸¹æ })
                        set_mjdata(met,score);
			if(BetAmount>0) switch(met->money_type()) {
	        		case 1:
					money = met->query("bank/past");
	        			if(money<(j+3+bb)*BetAmount) {
	        				message_vision("$NÒòÎª¸¶²»³öÇ®À´ºÜ²»ºÃÒâË¼µÄ¿´Öø$nÉµĞ¦¡£\n",met,me);
	        			}
	        			else {
	        				met->add("bank/past",(-BetAmount*(j+3+bb)));
	        			        me->add("bank/past",(BetAmount*(j+3+bb)));
	        			        message_vision("$NºÜ²»·şÆøµÄ×ªÕÊ"+BetAmount*(j+3+bb)+"¸ø$n¡£\n",met,me);
	        			     }
	        			break;	
	        		case 2:
					money = met->query("bank/now");
	        			if(money<(j+3+bb)*BetAmount) {
	        				message_vision("$NÒòÎª¸¶²»³öÇ®À´ºÜ²»ºÃÒâË¼µÄ¿´Öø$nÉµĞ¦¡£\n",met,me);
	        			}
	        			else {
	        				met->add("bank/now",(-BetAmount*(j+3+bb)));
	        			        me->add("bank/now",(BetAmount*(j+3+bb)));
	        			        message_vision("$NºÜ²»·şÆøµÄ×ªÕÊ"+BetAmount*(j+3+bb)+"¸ø$n¡£\n",met,me);
	        			     }
	        			break;	
	        		case 3:
					money = met->query("bank/future");
	        			if(money<(j+3)*BetAmount) {
	        				message_vision("$NÒòÎª¸¶²»³öÇ®À´ºÜ²»ºÃÒâË¼µÄ¿´Öø$nÉµĞ¦¡£\n",met,me);
	        			}
	        			else {
	        				met->add("bank/future",(-BetAmount*(j+3+bb)));
	        			        me->add("bank/future",(BetAmount*(j+3+bb)));
	        			        message_vision("$NºÜ²»·şÆøµÄ×ªÕÊ"+BetAmount*(j+3+bb)+"¸ø$n¡£\n",met,me);
	        			     }
	        			break;
	        		default:
	        			break;
	        	}
                        //this_object()->save();
                     } //else
                 } //for
              } // player==4
           }
         if(NowPlayerId[0]==who["Id"]) Count++; //Á¬×¯
         else
         {
           Times++;
           Count=0;
         }
        }else{
           command("sigh "+who["Id"]);
           message_vision(YEL+"$NËµ£ºÍæ¼Ò ["+HIY+who["Id"]+NOR+YEL+"] "+HIR+" ÑÔÕ§ ¡« ¹ÅÔÂ ¡«¡«"+NOR+YEL+"¡£\n"+NOR,this_object());
           Times++;
           Count=0;
           if (Play>=RECORD_PLAYERS){
              if (NowPlayerId[NowPlayer]==who["Id"]&&Touched){
                 if (who["Out"]==""&&who["OutPon"]==""){
                    j=12;
                 }else {
                    j=9;
                 }
              }else{
                 if (who["Out"]==""&&who["OutPon"]==""){
                    j=4;
                 }else{
                    j=3;
                 }
              }
////////////////
              str="\t\t\t¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô\n";
              str+=sprintf("\t\t\t%-12s%8s Ì¨\n","ÑÔÕ§¹ÅÔÂ",chinese_number(j));
              str+=sprintf("\t\t\t%-12s%8s Ì¨\n","µ¹¿Û×ÜÌ¨Êı:",chinese_number(j));
              str+="\t\t\t¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô\n";
              tell_room(environment(this_player()),str);
/////////////
	      score = ({ 0,0,0,-j,1 });  // ({ ×ÔÃş,ºúÅÆ,·ÅÇ¹,Ì¨Êı<·ÅÇ¹Îª¸ºµÄ>,·¸¹æ })
              set_mjdata(me,score);
	      if(BetAmount>0) switch(me->money_type())
	        	{
	        		case 1:
					money = me->query("bank/past");
        				me->add("bank/past",(-BetAmount*j));
        			        message_vision("$nÃ»ÊÕÁË$N"+BetAmount*j+"µÄ´æ¿î¡£\n",me,this_object());
	        			break;	
	        		case 2:
					money = me->query("bank/now");
        				me->add("bank/now",(-BetAmount*j));
        			        message_vision("$nÃ»ÊÕÁË$N"+BetAmount*j+"µÄ´æ¿î¡£\n",me,this_object());
	        			break;	
	        		case 3:
					money = me->query("bank/future");
        				me->add("bank/future",(-BetAmount*j));
        			        message_vision("$nÃ»ÊÕÁË$N"+BetAmount*j+"µÄ´æ¿î¡£\n",me,this_object());
	        			break;	
	        		default:
	        			break;
	        	}
              for (i=0;i<Play;i++){
              	  if(NowPlayerId[i]==me->query("id")) continue;
                  met=present(NowPlayerId[i], environment(this_object()));
                  if (!met) met=find_player(NowPlayerId[i]);
                  if (!met);
                  else{
              	     score = ({ 0,0,0,0,0 });  // ({ ×ÔÃş,ºúÅÆ,·ÅÇ¹,Ì¨Êı<·ÅÇ¹Îª¸ºµÄ>,·¸¹æ })
                     set_mjdata(met,score);
                     //this_object()->save();
                  }
              }
           }
        }
        if(Play >= RECORD_PLAYERS)
        {
	        Mj="\n[0;1;36;46m¡¡";
	        for (i=0; i<33; i++) Mj+="¡¡";
	        Mj+="[1;36;46m¡¡[0m\n";
	        Mj+="[1;36;46m¡¡[0;36m¡¡    "+HIW+"Ó¢[0mÎÄÃû×Ö  [1mÒÑ[0mÍæ¾ÖÊı  [1m×Ü[0mÕ½¼£  [1m×Ô[0mÃş´ÎÊı  [1m·Å[0mÇ¹´ÎÊı  [1m·¸[0m¹æ´ÎÊı     [1;36;46m¡¡[0m\n";
	        for (i=0;i<Play;i++){
	            Mj+=sprintf("[1;36;46m¡¡[0;36m¡¡[1;37m%12s  [33m%8d  [35m%6d  [32m%8d  [34m%8d  [34m%8d    [1;36;46m¡¡[0m\n",
	                         NowPlayerId[i],record[NowPlayerId[i]]["rounds"],record[NowPlayerId[i]]["total"],record[NowPlayerId[i]]["self"],record[NowPlayerId[i]]["lose"],record[NowPlayerId[i]]["bad"]);
	        }
	        Mj+="[1;36;46m¡¡";
	        for (i=0; i<33; i++) Mj+="¡¡";
	        Mj+="[46m£Ü[0m\n";
	        tell_room(environment(this_object()),Mj);
        }
 //       RECORD_D->set_mj_data(record);
        return wash_mj(Play);
}
int do_check_win(string str,int flag)
{
        int size=strlen(str),i,check;
        int t,k,W,T,S,Sp;
        string tempW="",tempT="",tempS="",tempB="";
        string Special="1w9w1s9s1t9teasowenojofaba";
 
        K=0;
        if (size > 33 && !flag){
           if (do_check_Mj(str,"ea")&&do_check_Mj(str,"so")&&do_check_Mj(str,"we")&&do_check_Mj(str,"no")&&
               do_check_Mj(str,"jo")&&do_check_Mj(str,"fa")&&do_check_Mj(str,"ba")&&
               do_check_Mj(str,"1w")&&do_check_Mj(str,"9w")&&do_check_Mj(str,"1s")&&
               do_check_Mj(str,"9s")&&do_check_Mj(str,"1t")&&do_check_Mj(str,"9t"))
           {
                  //ÏÈÉ¾µô13Ö»±ßÅÆ
                  for (i=0;i<sizeof(Special);i+=2) {
                      if (do_check_Mj(str,Special[i..i+1])){
                         str=do_delete_Mj(str,Special[i..i+1],1);
                      }
                  }
                  //²é»¹ÓĞÃ»13Ã´ÖĞµÄÅÆÖ»
                  for (i=0;i<sizeof(Special);i+=2) {
                      if (do_check_Mj(str,Special[i..i+1])){
                         Sp++;
                      }
                  }
                  if (Sp==1){
                     for (i=0;i<sizeof(Special);i+=2) {
                         if (do_check_Mj(str,Special[i..i+1])){
                            str=do_delete_Mj(str,Special[i..i+1],1);
                            t++;
                          Tc+="@z";//13Ã´
                         }
                     }
                  }
                  else if (Sp==2){
                    for (i=0;i<sizeof(str);i+=2){
                         if (do_check_Mj(str,str[i..i+1])==2){
                            str=do_delete_Mj(str,str[i..i+1],1);
                            Sp=0;
                            t++;
                         }
                    }
                    if (Sp!=0){
                       if (str[0..1]+1==str[2..3]){
                          str=do_delete_Mj(str,str[6..7],1);
                          t++;
                       }else{
                          str=do_delete_Mj(str,str[0..1],1);
                          t++;
                       }
                    }
                  }
           }else{
              for (i=0;i<sizeof(str);i+=2){
                   if (do_check_Mj(str,str[i..i+1])==2) Sp++;
                   else if (do_check_Mj(str,str[i..i+1])==3) check++;
                   else if (do_check_Mj(str,str[i..i+1])==4) Sp++;
              }
              if (Sp==14&&check==3){
                  for (i=0;i<sizeof(str);i+=2){
                      if (do_check_Mj(str,str[i..i+1])==2){
                         str=do_delete_Mj(str,str[i..i+1],2);
                         i=-2;
                      }
                      else if (do_check_Mj(str,str[i..i+1])==4){
                              str=do_delete_Mj(str,str[i..i+1],4);
                              i=-2;
                      }
                      else if (do_check_Mj(str,str[i..i+1])==3) t++;
                  }
                  t=1;
                  Tc+="@s";//7¶Ô×Ó
              }
           }
        }
        while(size--){
              size--;
          if (do_check_num(str[size..size+1],1) < 10) tempW+=str[size..size+1];
          else if (do_check_num(str[size..size+1],1) < 19) tempT+=str[size..size+1];
          else if (do_check_num(str[size..size+1],1) < 28) tempS+=str[size..size+1];
          else tempB+=str[size..size+1];
        }
        if (tempB!=""){
           for (i=0;i<strlen(tempB);i+=2){//
               check=do_check_Mj(tempB,tempB[i..i+1]);
               if (check==1) return 0;
               else if (check==2){
                       tempB=do_delete_Mj(tempB,tempB[i..i+1],2);
                       t++;
                       i=-2;
               }else if (check==3){
                        tempB=do_delete_Mj(tempB,tempB[i..i+1],3);
                        K++;
                        i=-2;
               }
           }//
        }
        if (tempW!="") W=check_hu(tempW);
        if (tempT!="") T=check_hu(tempT);
        if (tempS!="") S=check_hu(tempS);
        if(!flag)
        {
	        if (K==3) Tc+="@j";//Èı°µ¿Ì
	        else if (K==4) Tc+="@p";//ËÄ°µ¿Ì
	        else if (K==5) Tc+="@u";//Îå°µ¿Ì
        }
        if (W+T+S+t==1) return 1;
        return 0;
}
int check_hu(string strW)
{
        int i,j,check;
        int k,t;
        int A,B,C,D,E,F;
        for (i=0;i<sizeof(strW);i+=2) {//ÔÙ°ÑË³×ÓÉ¾µô
        A=do_check_num(strW[i..i+1],2);
        B=do_check_num(strW[i+2..i+3],2);
        C=do_check_num(strW[i+4..i+5],2);
        D=do_check_num(strW[i+6..i+7],2);
        E=do_check_num(strW[i+8..i+9],2);
        F=do_check_num(strW[i+10..i+11],2);
        if (sizeof(strW) > 11 &&do_check_num(strW[i-2..i-1],2)!=A&&A+1==B&&B==C&&C+1==D&&D==E&&E+1==F
           ||do_check_num(strW[i-2..i-1],2)!=A&&A==B&&B+1==C&&C==D&&D+1==E&&E==F){
              if (A==B&&B+1==C&&C==D&&D+1==E&&E==F){
                 if (do_check_Mj(Tc,"@G")==1){
                    Tc=do_delete_Mj(Tc,"@H",1);
                    Tc+="@H";
                 }else        Tc+="@G";
              }
              for (j=0;j<6;j++) {  //É¾µôË³×Ó1 22 33 4 && 22 33 44
                  strW=do_delete_Mj(strW,strW[i..i+1],1);
              }
           i=-2;
        }
        else if (A+1==B&&B==C&&C==D&&D==E&&E+1==F){
              for (j=0;j<2;j++) {  //É¾µôË³×Ó1 2 2 2 2 3
                  strW=do_delete_Mj(strW,strW[i..i+1],1);
              }
              strW=do_delete_Mj(strW,strW[i+6..i+7],1);
           i=-2;
           }
        else if (sizeof(strW) > 9 && A+1==B&&B==C&&C==D&&D+1==E){
              //É¾µôË³×Ó12223ÖĞµÄ1 2 3
                  strW=do_delete_Mj(strW,strW[i..i+1],1);
                  strW=do_delete_Mj(strW,strW[i..i+1],1);
                  strW=do_delete_Mj(strW,strW[i+4..i+5],1);
           i=-2;
        }
        else if (sizeof(strW) > 9 && A==B&&B+1==C&&C+1==D&&D+1==E){
             for (j=0;j<3;j++) {   //É¾µôË³×Ó11234ÖĞµÄ2 3 4
                 strW=do_delete_Mj(strW,strW[i+4..i+5],1);
             }
           i=-2;
        }
        else if (sizeof(strW) > 5 && A+1==B&&B+1==C){
             for (j=0;j<3;j++) {   //É¾µôË³×Ó123ÖĞµÄ1 2 3
                 strW=do_delete_Mj(strW,strW[i..i+1],1);
             }
           i=-2;
        }
        }
 
        if (sizeof(strW) > 5){
           for (i=0;i<sizeof(strW);i+=2) {//ÔÙ°Ñ¿ÌÉ¾µô
               check=do_check_Mj(strW,strW[i..i+1]);
               if (check==3){
                  K++;
                  strW=do_delete_Mj(strW,strW[i..i+1],3);
                  i=-2;
                  }
              }
           }
           for (i=0;i<sizeof(strW);i+=2) {//ÔÙ°Ñ¶ÔÉ¾µô
               check=do_check_Mj(strW,strW[i..i+1]);
               if (check==2){
                  t++;
                  strW=do_delete_Mj(strW,strW[i..i+1],2);
                  i=-2;
               }
           }
           if (strW!="") return 99;
           return t;
}
int do_touch(string str,object me)
{
        int i,check;
        mapping who;
 
        if (!me) me=this_player();
        if (check_id(me->query("id"),"player")!="");
        else {
           command("stare "+me->query("id"));
           command("say ÕâÅÆ¾Ö¸úÄãÃ»¹ØÏµ¡£");
           return 1;
        }
        if (!Playing){
           command("say ÅÆ¾Ö»¹Ã»¿ªÊ¼ÄãÒªÃşÅÆÈ¥²ØÆğÀ´¨Ú~~");
           return 1;
        }
        tell_object(me,"»»Ë­ÃşÅÆ:"+NowPlayerId[NowPlayer]+"\n");
        if (me->query("id")!=NowPlayerId[NowPlayer]){
           command("hammer "+me->query("id"));
           command("say ÏëÍµÅÆ!!Ã»ÄÇÃ´ÈİÒ×~~");
           return 1;
        }
        if (Touched){
           command("flop "+me->query("id"));
           command("say ´òÅÆÀ²!!");
           return 1;
        }
        NO_HU=0;
        NO_GON=0;
        if (me->query("id")==P1Data["Id"]) who=P1Data;
        else if (me->query("id")==P2Data["Id"]) who=P2Data;
        else if (me->query("id")==P3Data["Id"]) who=P3Data;
        else if (me->query("id")==P4Data["Id"]) who=P4Data;
        if (who["Auto"]=="auto"){
           if (str=="AUTO");
           else{
             write("Éè¶¨×Ô¶¯ÌıÅÆºó¡¢²»¿É×Ô¼ºÃşÅÆ¡£\n");
              return 1;
            }
        }
        Touched=1;
        str=List[count..count+1];
        count+=2;
        tell_room(environment(this_object()),me->name()+"ÃşÁËÒ»ÕÅÅÆ¡£\n",me);
        tell_object(me,"ÄãÃşÁËÒ»ÕÅÅÆ¡£\n");
        tell_object(me,"ÄãÃşµ½Ò»ÕÅ.."+do_check_num(str,3)+"\n");
        if (who["Auto"]=="auto"){
           if (do_check_num(str,1) > 34){
              for (i=0;i<1;i++){
                   who["OutFlower"]+=str;
                   HU_F=1;
                   tell_room(environment(this_object()),YEL+me->name()+"Ëµ£º"+HIB+"»¨ÅÆ"+NOR+YEL+"²¹»¨!!¡£\n\n"+NOR+me->name()+"ÍùºóÃæ²¹ÁËÒ»ÕÅÅÆ¡£\n",me);
                   tell_object(me,"ÄãËµ£º"+HIB+"»¨ÅÆ"+NOR+"²¹»¨!!¡£\n\nÄãÍùºóÃæ²¹ÁËÒ»ÕÅÅÆ¡£\n");
                   str=List[end..end+1];
                   end-=2;
                   tell_object(me,"ÄãÃşµ½ÁËÒ»ÕÅ"+do_check_num(str,3)+"\n");
                   if (do_check_num(str,1) > 34) i--;
              }
           }
           check=do_check_Mj(who["AutoTin"],str);
           if (check!=0){
              who["Mj"]+=str;
              who["Mj"]=sort_data(who["Mj"]);
              return do_win(str,me);
           }
           call_out("do_dump",0,str,me);
        }
        who["Mj"]+=str;
        check_flower(who);
        i=0;
        if (who["Show"]=="´úÂë") i=3;
        if (who["Show"]=="color") i=5;
        tell_object(me,show_mj(who["Mj"],i));
        return 1;
}
int do_pon(string str,object me)
{
        int i;
        mapping who;
 
        if (!me) me=this_player();
        if (check_id(me->query("id"),"player")!="");
        else {
           command("stare "+me->query("id"));
           command("say ÕâÅÆ¾Ö¸úÄãÃ»¹ØÏµ¡£");
           return 1;
        }
        if (!Playing){
           command("die "+me->query("id"));
           command("say ÅÆ¾Ö»¹Ã»¿ªÊ¼!!ÅöÄãµÄÍ·À²!!");
           return 1;
        }
        if (Touched){
           command("hammer "+me->query("id"));
           command("say ±ğÈËÃ»´òÅÆÄãÔõÃ´Åö¡£");
           return 1;
        }
        if (LastDumpId==me->query("id")){
           command("stare "+me->query("id"));
           command("say ÄÇÕÅÅÆÊÇÄã×Ô¼º´òµÄ!¡£");
           return 1;
        }
        if (!str) str=LastDump;
        else if (str!=LastDump) return notify_fail("ÄÇÕÅ"+do_check_num(str,0)+"ÒÑ¾­¹ıÆÚÁË¡£\n");
        if (me->query("id")==P1Data["Id"]) who=P1Data;
        else if (me->query("id")==P2Data["Id"]) who=P2Data;
        else if (me->query("id")==P3Data["Id"]) who=P3Data;
        else if (me->query("id")==P4Data["Id"]) who=P4Data;
        if (who["Auto"]=="auto") return 1;
        i=do_check_Mj(who["Mj"],str);
        if (i==0) return notify_fail("ÄãÃ»"+do_check_num(str,0)+"ÕâÕÅÅÆÒªÔõÃ´Åö¡£\n");
        if (i < 2) return notify_fail("ÄãÊÖÖĞÒªÓĞÁ½ÕÅ"+do_check_num(str,0)+"²ÅÄÜÅö¡£\n");
        message_vision("\n$N´ó½Ğ£º"+do_check_num(str,0)+"¡«"+HIW+"¡¾ ¡« Åö ¡« ¡¿"+NOR+"\n\n",me);
        for (i=0;i<Play;i++) {
            if (NowPlayerId[NowPlayer]==me->query("id")) break;
            NowPlayer++;
            NowPlayer%=Play;
        }
        for (i=0;i<3;i++) who["OutPon"]+=str;
        who["Mj"]=do_delete_Mj(who["Mj"],str,2);
        who["AutoPon"]=do_delete_Mj(who["AutoPon"],str,1);
        NO_HU=1;
        NO_GON=1;
        Touched=1;
        i=0;
        if (who["Show"]=="´úÂë") i=3;
        if (who["Show"]=="color") i=5;
        tell_object(me,show_mj(who["Mj"],i));
        return delete_last_dump(who["Id"]);
}
//¼ì²éÄ¿Ç°ÅÆ¾ÖÊÇ·ñÕı³£. return 0 (²»Õı³£,¿Érestart) return 1(Õı³£)
int check_player()
{
	object user;
	if(Play<2) return 0;
	else {
		if(Play > 3)
		{
			if(user = present(P4Data["Id"], environment(this_object())))
			{
				if(user->query_temp("netdead")) return 0;
				if(query_idle(user)>180) return 0;
				if(user->is_inactive()) return 0;
			}
			else return 0;
		}
		if(Play > 2)
		{
			if(user = present(P3Data["Id"], environment(this_object())))
			{
				if(user->query_temp("netdead")) return 0;
				if(query_idle(user)>180) return 0;
				if(user->is_inactive()) return 0;
			}
			else return 0;
		}
		if(user = present(P2Data["Id"], environment(this_object())))
		{
			if(user->query_temp("netdead")) return 0;
			if(query_idle(user)>180) return 0;
			if(user->is_inactive()) return 0;
		}
		else return 0;
		if(user = present(P1Data["Id"], environment(this_object())))
		{
			if(user->query_temp("netdead")) return 0;
			if(query_idle(user)>180) return 0;
			if(user->is_inactive()) return 0;
		}
		else return 0;
		
	}
	return 1;
}

int do_restart(string str)
{
        object me=this_player();
        if (me->query("id")=="guest") return 0;
        if (str!="mj"){
           if (check_id(me->query("id"),"player")!="");
           else if(!check_player());
           else 
           {
              command("stare "+me->query("id"));
              command("say ÕâÅÆ¾Ö¸úÄãÃ»¹ØÏµ¡£");
              return 1;
           }
        }
        message_vision("$N°ÑÅÆ¾ÖÖØĞÂÉè¶¨¡£\n",me);
        message_vision(YEL+"$NËµ£º$n½«ÅÆ¾ÖÖØĞÂÉè¶¨, ÇëÓÃ"+HIR+" addin "+NOR+YEL+"¼ÓÈëÅÆ¾Ö¡£\n"+NOR,this_object(),this_player());
        NowPlayerId[0]="";
        NowPlayerId[1]="";
        NowPlayerId[2]="";
        NowPlayerId[3]="";
        P1Data["Id"]="";
        P2Data["Id"]="";
        P3Data["Id"]="";
        P4Data["Id"]="";
        Count=0;
        LookP ="";
        Play=START;
        Times=START;
        end=END;
        count=START;
        Playing=START;
        return 1;
}
int wash_mj(int amount)
{
        int i,x;
        string str,countstr="";
        object me;
        mixed *X,MjE_Data = ([
"1w" : 0,"2w" : 0,"3w" : 0,"4w" : 0,"5w" : 0,"6w" : 0,"7w" : 0,"8w" : 0,"9w" : 0,
"1s" : 0,"2s" : 0,"3s" : 0,"4s" : 0,"5s" : 0,"6s" : 0,"7s" : 0,"8s" : 0,"9s" : 0,
"1t" : 0,"2t" : 0,"3t" : 0,"4t" : 0,"5t" : 0,"6t" : 0,"7t" : 0,"8t" : 0,"9t" : 0,
"ea" : 0,"so" : 0,"we" : 0,"no" : 0,"jo" : 0,"fa" : 0,"ba" : 0,
"f1" : 0,"f2" : 0,"f3" : 0,"f4" : 0,"f5" : 0,"f6" : 0,"f7" : 0,"f8" : 0
                            ]);
        if (!Play){
           command("say Ã»ÓĞÍæ¼ÒÒªÎÒ°×Ï´ÅÆ!!ÃÅ¶¼Ã»ÓĞ¡£");
           return 1;
        }
        if (Playing){
           command("say ÅÆ¾ÖÕıÔÚ½øĞĞÖĞ¡£");
           return 1;
        }
        command("say ÎÒ°ïÃ¦Ï´ÅÆ£¬µÈµÈË­ºúÒª³Ôºìà¸..:)");
        if (Play<RECORD_PLAYERS) command("say Íæ¼Ò²»×ãÓĞĞ§ÈËÊıËùÒÔ²»¼Æ·Ö¡£");
        P1Data["Mj"]="";
        P1Data["OutGon"]="";
        P1Data["Out"]="";
        P1Data["OutPon"]="";
        P1Data["OutFlower"]="";
        P1Data["Auto"]="";
        P1Data["AutoTin"]="";
        P1Data["AutoGon"]="";
        P1Data["AutoPon"]="";
        P1Data["Dump"]="";
 
        P2Data["Mj"]="";
        P2Data["OutGon"]="";
        P2Data["Out"]="";
        P2Data["OutPon"]="";
        P2Data["OutFlower"]="";
        P2Data["Auto"]="";
        P2Data["AutoTin"]="";
        P2Data["AutoGon"]="";
        P2Data["AutoPon"]="";
        P2Data["Dump"]="";
 
        P3Data["Mj"]="";
        P3Data["OutGon"]="";
        P3Data["Out"]="";
        P3Data["OutPon"]="";
        P3Data["OutFlower"]="";
        P3Data["Auto"]="";
        P3Data["AutoTin"]="";
        P3Data["AutoGon"]="";
        P3Data["AutoPon"]="";
        P3Data["Dump"]="";
 
        P4Data["Mj"]="";
        P4Data["OutGon"]="";
        P4Data["Out"]="";
        P4Data["OutPon"]="";
        P4Data["OutFlower"]="";
        P4Data["Auto"]="";
        P4Data["AutoTin"]="";
        P4Data["AutoGon"]="";
        P4Data["AutoPon"]="";
        P4Data["Dump"]="";
 
        end=END;
        NO_HU=START;
        NO_GON=START;
        count=START;
        Playing=START;
        List="";
        NowPlayer=START;
        Touched=START;
        Auto=START;
        Auto_Tin=START;
        Auto_Gon=START;
        Auto_Pon=START;
        Goned=START;
        LastDump="";
        LastDumpId="";
        X = keys(MjE_Data);
        for (i=0;i<144;i++){
            x = random(sizeof(X));
            if (X[x]=="f1"||X[x]=="f2"||X[x]=="f3"||X[x]=="f4"||
                X[x]=="f5"||X[x]=="f6"||X[x]=="f7"||X[x]=="f8"){
                if (MjE_Data[X[x]] < 1){
                   MjE_Data[X[x]] = MjE_Data[X[x]] + 1;
                   List += X[x];
                } else i--;
            }else{
               if (MjE_Data[X[x]] < 4){
                  MjE_Data[X[x]] = MjE_Data[X[x]] + 1;
                  List += X[x];
               } else i--;
           }
        }
 
//        for (i=0;i<sizeof(X);i++) printf("%s=%d ",X[i],MjE_Data[X[i]]);
        message_vision("\n$NºÜ¿ìµÄ°Ñ×ÀÉÏµÄÅÆÕûÀíºÃ¡£\n\n",this_object());
        command("say àÅ!!ºÃÁË¿ÉÒÔ¿ªÊ¼ÁË!!");
        if (Count) countstr="[Á¬×¯"+chinese_number(Count)+"]";
        if (!Times);
        else{
          if (Count);
          else {
            str=NowPlayerId[0];
            if (Play>1) NowPlayerId[0]=NowPlayerId[1];
            if (Play>2) NowPlayerId[1]=NowPlayerId[2];
            if (Play>3) NowPlayerId[2]=NowPlayerId[3];
            NowPlayerId[Play-1]=str;
          }
        }
        if (Times/Play == 4) Times=0;
        if (Times/Play == 3) str=HIW+"±±·ç"+NOR;
        if (Times/Play == 2) str=HIY+"Î÷·ç"+NOR;
        if (Times/Play == 1) str=HIR+"ÄÏ·ç"+NOR;
        if (Times/Play == 0) str=HIG+"¶«·ç"+NOR;
        i=Times;
        i%=Play;
        i++;
        message_vision("["+str+chinese_number(i)+"]ÅÆ¾Ö¿ªÊ¼:\n×¯¼Ò "+HIY+NowPlayerId[0]+" "+HIR+countstr+NOR+"\nÖÀ³ö÷»×Ó"+
                       "["+HIG+chinese_number(i=3+random(16))+NOR+ "]µã¡£\n",this_object());
        //Íæ¼ÒÈ¡ÅÆÒ»´ÎÈ¡16Ö»:Q
        if (Play>0) P1Data["Mj"]=List[0..31];
        if (Play>1) P2Data["Mj"]=List[32..63];
        if (Play>2) P3Data["Mj"]=List[64..95];
        if (Play>3) P4Data["Mj"]=List[96..127];
        count=(Play*2*16);
        if (Play>0) check_flower(P1Data);
        if (Play>1) check_flower(P2Data);
        if (Play>2) check_flower(P3Data);
        if (Play>3) check_flower(P4Data);
        Playing=1;
        if(Play>3)
	{
		for(i=0;i<Play;i++)
		{
			if(me=present(NowPlayerId[i], environment(this_object())))
			{
				tell_object(me,show_site(NowPlayerId[i]));
			}
		}
        }
        message_vision(YEL+"$NËµ£º×¯¼Ò "+HIY+NowPlayerId[0]+NOR+YEL+" Çë¿ªÃÅÅÆ¡£\n"+NOR,this_object());
        return 1;
}
int do_setmj(string str)
{
        int check;
        string numstr;
        mapping who;
        object me=this_player();
 
        if (me->query("id")==P1Data["Id"]) who=P1Data;
        else if (me->query("id")==P2Data["Id"]) who=P2Data;
        else if (me->query("id")==P3Data["Id"]) who=P3Data;
        else if (me->query("id")==P4Data["Id"]) who=P4Data;
        else return 0;
        if (!str){
           numstr=this_object()->name()+"¶ÔÖøÄãËµ: ÄãÄ¿Ç°µÄÉè¶¨ÓĞ:\n";
          if (who["AutoTin"]!="") numstr+="Óöµ½"+HIB+show_mj(who["AutoTin"],2)+NOR+"»á×Ô¶¯"+HIB+"[ºúÅÆ]"+NOR+"¡£\n";
          if (who["AutoGon"]!="") numstr+="Óöµ½"+HIY+show_mj(who["AutoGon"],2)+NOR+"»á×Ô¶¯"+HIY+"[¸ÜÅÆ]"+NOR+"¡£\n";
          if (who["AutoPon"]!="") numstr+="Óöµ½"+HIG+show_mj(who["AutoPon"],2)+NOR+"»á×Ô¶¯"+HIG+"[ÅöÅÆ]"+NOR+"¡£\n";
          if (who["Show"]=="´úÂë")    numstr+="ÏÔÊ¾·½Ê½Îª"+HIY+"[´úÂë]"+NOR+"·½Ê½¡£\n";
          if (who["Show"]=="color")   numstr+="ÏÔÊ¾·½Ê½Îª"+HIG+"[²ÊÉ«]"+NOR+"¡£\n";
          if (who["Auto"]=="auto")    numstr+="ÄãÉè¶¨"+HIR+"[×Ô¶¯ÌıÅÆ]"+NOR+"¡£\n";
          if (who["AutoTin"]==""&&who["AutoGon"]==""&&who["AutoPon"]==""&&who["Show"]==""&&who["Auto"]=="") numstr+="ÄãÃ»ÓĞÈÎºÎÉè¶¨¡£\n";
           tell_room(environment(me),this_object()->name()+"ÔÚ"+me->name()+"¶ú±ßËµÁËÒ»Ğ©»°¡£\n",me);
           tell_object(me,numstr);
           return 1;
        }
        if (sscanf(str,"%s %s",str,numstr)!=2) return notify_fail("Ö¸Áî:setmj <tin>&<gon>&<pon> <´úÂë>\n");
        if (str=="tin"){
           if (numstr=="none"){
              who["AutoTin"]="";
              return notify_fail("ÄãÈ¡Ïû×Ô¶¯ºúÅÆÉè¶¨¡£\n");
           }
           if(member_array(numstr,Mjlist)==-1) return notify_fail("Ã»ÓĞ["+numstr+"]ÕâÖÖÅÆ¡£\n");
           check=do_check_Mj(MjE,numstr);
           if (check!=1) return notify_fail("Ã»ÓĞ["+numstr+"]ÕâÖÖÅÆ¡£\n");
           check=do_check_Mj(who["AutoTin"],numstr);
           if (check){
              who["AutoTin"]=do_delete_Mj(who["AutoTin"],numstr,1);
              return notify_fail("Äã"+HIR+"É¾µôÁË"+NOR+"Óöµ½"+do_check_num(numstr,0)+"»á×Ô¶¯ºúÅÆµÄÉè¶¨¡£\n");
           }
           who["AutoTin"]+=numstr;
           Auto_Tin=1;
           write("ÄãÉè¶¨Óöµ½"+do_check_num(numstr,0)+"Ê±»á×Ô¶¯ºúÅÆ¡£\n");
           return 1;
        }
        else if (str=="gon"){
           if (numstr=="none"){
              who["AutoGon"]="";
              return notify_fail("ÄãÈ¡Ïû×Ô¶¯¸ÜÅÆÉè¶¨¡£\n");
           }
           if(member_array(numstr,Mjlist)==-1) return notify_fail("Ã»ÓĞ["+numstr+"]ÕâÖÖÅÆ¡£\n");
           check=do_check_Mj(who["Mj"],numstr);
           if (check==0) return notify_fail("ÄãÃ»"+do_check_num(numstr,0)+"ÕâÕÅÅÆ¡£\n");
           if (check < 3) return notify_fail("ÄãÊÖÖĞÒªÓĞÈıÕÅ"+do_check_num(numstr,0)+"²ÅÄÜÉè¶¨¸Ü´ËÅÆ¡£\n");
           check=do_check_Mj(who["AutoGon"],numstr);
           if (check){
              who["AutoGon"]=do_delete_Mj(who["AutoGon"],numstr,1);
              return notify_fail("Äã"+HIR+"É¾µôÁË"+NOR+"Óöµ½"+do_check_num(numstr,0)+"»á×Ô¶¯¸ÜÅÆµÄÉè¶¨¡£\n");
           }
           who["AutoGon"]+=numstr;
           Auto_Gon=1;
           write("ÄãÉè¶¨Óöµ½"+do_check_num(numstr,0)+"Ê±»á×Ô¶¯¸ÜÅÆ¡£\n");
           return 1;
        }
        else if (str=="pon"){
           if (numstr=="none"){
              who["AutoPon"]="";
              return notify_fail("ÄãÈ¡Ïû×Ô¶¯ÅöÅÆÉè¶¨¡£\n");
           }
           if(member_array(numstr,Mjlist)==-1) return notify_fail("Ã»ÓĞ["+numstr+"]ÕâÖÖÅÆ¡£\n");
           check=do_check_Mj(who["Mj"],numstr);
           if (check==0) return notify_fail("ÄãÃ»"+do_check_num(numstr,0)+"ÕâÕÅÅÆ¡£\n");
           if (check < 2) return notify_fail("ÄãÊÖÖĞÒªÓĞÁ½ÕÅ"+do_check_num(numstr,0)+"²ÅÄÜÉè¶¨Åö´ËÅÆ¡£\n");
           check=do_check_Mj(who["AutoPon"],numstr);
           if (check){
              who["AutoPon"]=do_delete_Mj(who["AutoPon"],numstr,1);
              return notify_fail("Äã"+HIR+"É¾µôÁË"+NOR+"Óöµ½"+do_check_num(numstr,0)+"»á×Ô¶¯ÅöÅÆµÄÉè¶¨¡£\n");
           }
           who["AutoPon"]+=numstr;
           Auto_Pon=1;
           write("ÄãÉè¶¨Óöµ½"+do_check_num(numstr,0)+"Ê±»á×Ô¶¯ÅöÅÆ¡£\n");
           return 1;
        }
        else if (str=="show"){
           if (numstr=="none"||numstr=="1"){
              who["Show"]="";
              return notify_fail("ÄãÈ¡ÏûÏÔÊ¾Éè¶¨¡£\n");
           }
 
           if (numstr=="´úÂë"||numstr=="3"){
              numstr="´úÂë";
              write("ÄãÉè¶¨Ö»ÏÔÊ¾´úÂë¡£\n");
           }
           else if (numstr=="color"||numstr=="2"){
                numstr="color";
                 write("ÄãÉè¶¨²ÊÉ«ÏÔÊ¾¡£\n");
           }
           else return 1;
           who["Show"]=numstr;
           return 1;
        }
        else if (str=="auto"){
           if (numstr=="none"){
              return notify_fail("²»ÄÜÈ¡Ïû×Ô¶¯ÌıÅÆ£¬ÒªÊÇÉè¶¨´íÎóµÈÖøÕ©ºú°É!!:>¡£\n");
           }
           if (who["AutoTin"]=="") return notify_fail("ÇëÏÈÉè¶¨ÒªÌıµÄÅÆ¡£\n");
           if (!Touched) return notify_fail("ÇëÏÈÃşÅÆÔÙ×ö´ËÉè¶¨¡£\n");
           if (numstr=="tin") write("ÄãÉè¶¨×Ô¶¯ÌıÅÆ¡£\n");
           else return 1;
           message_vision("\n$N´ó½ĞÒ»Éù£º"+HIW+" ¡« ÎÒ ¡« Ìı ¡« ÅÆ ¡« À² ¡«¡«"+NOR+"\n\n",me);
           Auto=1;
           who["Auto"]="auto";
           return 1;
        }
        else return notify_fail("Ã»ÓĞÕâÖÖÉè¶¨¡£\n");
}
int do_check_eat(string num1,string num2,string LastDump)
{
        int A,B,C;
        A=do_check_num(num1,1);
        B=do_check_num(num2,1);
        C=do_check_num(LastDump,1);
        if (A<10){
           if (B>10||C>10) return 0;
        }
        else if (A<19&&A>10){
                if (B>19||C>19&&B<10||C<10) return 0;
        }
        else if (A<28&&A>19){
                if (B<19||C<19) return 0;
        }
        A=do_check_num(num1,2);
        B=do_check_num(num2,2);
        C=do_check_num(LastDump,2);
 
        if (A > 9 || B > 9 || C > 9) return 0;
        if ((A+B)%2!=0){
           if (A > B){
               if (C==(A+1) || C==(A-2)) return 1;
           }else{
               if (C==(B+1) || C==(B-2)) return 1;
           }
           return 0;
        }else{
            if (A > B){
              if (C==(A-1) || C==(B+1)) return 1;
             }else{
              if (C==(B-1) || C==(A+1)) return 1;
             }
            return 0;
        }
}
string show_mj(string str,int flag)
{
        string Mj="",Mj1="";
        int size=strlen(str)+2,a,b;
        if (!str||str=="") return "";
        if (flag!=3)
        {
           if (flag==2)
           {
           	while(size--){
              		size--;
             		Mj+=do_check_num(str[size..size+1],3)+".";
           	}
           	Mj1=Mj;
           }
           else{
 	     while(size--){
                size--;
                Mj+=do_check_num(str[size..size+1],0);
             }
             size=strlen(Mj);
             Mj1="©°";
             for (a=0;a<(size/2)-1;a++){
                 if (a%2==0) Mj1+="©¤";
                 else Mj1+="©Ğ";
             }
             Mj1+="©´\n©¦";
 
             for (a=0;a<size-1;a++){
                 if (flag==5 || flag==6){
                    if (Mj[a+2..a+3]=="Íò") Mj1+=HIR;
                    else if (Mj[a+2..a+3]=="Í²") Mj1+=HIC;
                    else if (Mj[a+2..a+3]=="Ë÷") Mj1+=HIG;
                    else if (Mj[a+2..a+3]=="·ç") Mj1+=HIM;
                    else if (Mj[a+2..a+3]=="ÖĞ") Mj1+=HIR;
                    else if (Mj[a+2..a+3]=="·¢") Mj1+=HIG;
                    else if (Mj[a+2..a+3]=="°å") Mj1+=HIW;
                    else if (Mj[a+2..a+3]=="´º"
                         ||  Mj[a+2..a+3]=="ÏÄ"
                         ||  Mj[a+2..a+3]=="Çï"
                         ||  Mj[a+2..a+3]=="¶¬") Mj1+=HIR;
                    else if (Mj[a+2..a+3]=="Ã·"
                         ||  Mj[a+2..a+3]=="À¼"
                         ||  Mj[a+2..a+3]=="Öñ"
                         ||  Mj[a+2..a+3]=="¾Õ") Mj1+="[1;30m";
                 }
                 Mj1+=Mj[a..a+1];
                 a++;a++;a++;
                 Mj1+=NOR+"©¦";
             }
             Mj1+="\n©¦";
             for (a=2;a<size;a++){
                 if (flag==5 || flag==6){
                         if (Mj[a..a+1]=="Íò") Mj1+=RED;
                    else if (Mj[a..a+1]=="Ë÷") Mj1+=GRN;
                    else if (Mj[a..a+1]=="Í²") Mj1+=CYN;
                    else if (Mj[a..a+1]=="·ç") Mj1+=MAG;
                    else if (Mj[a..a+1]=="ÖĞ") Mj1+=HIR;
                    else if (Mj[a..a+1]=="·¢") Mj1+=HIG;
                    else if (Mj[a..a+1]=="°×") Mj1+=HIW;
                    else if (Mj[a..a+1]=="´º") Mj1+=HIG;
                    else if (Mj[a..a+1]=="ÏÄ") Mj1+=HIB;
                    else if (Mj[a..a+1]=="Çï") Mj1+=HIY;
                    else if (Mj[a..a+1]=="¶¬") Mj1+=HIW;
                    else if (Mj[a..a+1]=="Ã·") Mj1+=HIW;
                    else if (Mj[a..a+1]=="À¼") Mj1+=HIR;
                    else if (Mj[a..a+1]=="Öñ") Mj1+=HIG;
                    else if (Mj[a..a+1]=="¾Õ") Mj1+=HIY;
                 }
                 Mj1+=Mj[a..a+1];
                 a++;a++;a++;
                 Mj1+=NOR+"©¦";
             }
             Mj1+="\n©¸";
             for (a=(size/2)-1;a>0;a--){
                 if (a%2!=0){
                    if (flag==0 || flag==5) Mj1+=str[a-1..a];
                    else Mj1+="©¤";
                 }
                 else Mj1+="©Ø";
             }
             Mj1+="©¼\n";
           }
           return Mj1;
        }else{
            size*=2;
            for (a=(size/2)-1;a>0;a--){
                if (a%2!=0) Mj1+=str[a-1..a];
                else Mj1+=" ";
           }
           Mj1+="\n";
        }
        return Mj1;
}
string check_id(string str,string kind)
{
        int check,i;
        if (!str) return "";
        if (kind=="tin"){
           check=NowPlayer;
           for (i=0;i<Play-1;i++) {
           if (NowPlayerId[check]==P1Data["Id"] && do_check_Mj(P1Data["AutoTin"],str)!=0) return P1Data["Id"];
           if (NowPlayerId[check]==P2Data["Id"] && do_check_Mj(P2Data["AutoTin"],str)!=0) return P2Data["Id"];
           if (NowPlayerId[check]==P3Data["Id"] && do_check_Mj(P3Data["AutoTin"],str)!=0) return P3Data["Id"];
           if (NowPlayerId[check]==P4Data["Id"] && do_check_Mj(P4Data["AutoTin"],str)!=0) return P4Data["Id"];
               check++;
               check%=Play;
           }
           return "";
        }
        if (kind=="gon"){
           check=do_check_Mj(P1Data["AutoGon"],str);
           if (check!=0){
              check=do_check_Mj(P1Data["Mj"],str);
              if (check < 3) return "";
              else return P1Data["Id"];
           }
           check=do_check_Mj(P2Data["AutoGon"],str);
           if (check!=0){
              check=do_check_Mj(P2Data["Mj"],str);
              if (check < 3) return "";
              else return P2Data["Id"];
           }
           check=do_check_Mj(P3Data["AutoGon"],str);
           if (check!=0){
              check=do_check_Mj(P3Data["Mj"],str);
              if (check < 3) return "";
              else return P3Data["Id"];
           }
           check=do_check_Mj(P4Data["AutoGon"],str);
           if (check!=0){
              check=do_check_Mj(P4Data["Mj"],str);
              if (check < 3) return "";
              else return P4Data["Id"];
           }
           return "";
        }
        if (kind=="pon"){
           check=do_check_Mj(P1Data["AutoPon"],str);
           if (check!=0){
              check=do_check_Mj(P1Data["Mj"],str);
              if (check < 2) return "";
              else return P1Data["Id"];
           }
           check=do_check_Mj(P2Data["AutoPon"],str);
           if (check!=0){
              check=do_check_Mj(P2Data["Mj"],str);
              if (check < 2) return "";
              else return P2Data["Id"];
           }
           check=do_check_Mj(P3Data["AutoPon"],str);
           if (check!=0){
              check=do_check_Mj(P3Data["Mj"],str);
              if (check < 2) return "";
              else return P3Data["Id"];
           }
           check=do_check_Mj(P4Data["AutoPon"],str);
           if (check!=0){
              check=do_check_Mj(P4Data["Mj"],str);
              if (check < 2) return "";
              else return P4Data["Id"];
           }
           return "";
        }
        if (kind=="player"){
           for (i=0;i<Play;i++) {
               if (NowPlayerId[i]==str) check=1;
           }
        if (check) return "Y";
        return "";
        }
}
int delete_last_dump(string whoId)
{
        mapping who;
        if (LastDumpId==P1Data["Id"]) who=P1Data;
        else if (LastDumpId==P2Data["Id"]) who=P2Data;
        else if (LastDumpId==P3Data["Id"]) who=P3Data;
        else if (LastDumpId==P4Data["Id"]) who=P4Data;
        if (who["Dump"]!="") who["Dump"]=do_delete_Mj(who["Dump"],LastDump,1);
        return 1;
}
//°ÑÓ¢ÎÄ×Ö×ªÎª´úÂë or ÖĞÎÄ flag 1 ¾ÍÊÇ×ªÎª´úÂë flag 2 ×ªÎª1..9,flag 3 ÎªÖĞÎÄ¼ÓÉÏÑÕÉ«
mixed do_check_num(string str,int flag)
{
        int number;
 
        if (!str) return MjC[0];
        sscanf(str,"%d%s",number,str);
        if (number == 0){
        // MjE= "1w2w3w4w5w6w7w8w9w1t2t3t4t5t6t7t8t9t1s2s3s4s5s6s7s8s9seasowenojofabaf1f2f3f4f5f6f7f8";
        //       0         0         0         0         0         0   4     0
        if(str=="xx") number=43;
        else if(str!=""){
        	number = strsrch( MjE, str );
        	number = (number / 2)+1;
       	}
/*        if (str=="ea") number=28;
        else if (str=="so") number=29;
        else if (str=="we") number=30;
        else if (str=="no") number=31;
        else if (str=="jo") number=32;
        else if (str=="fa") number=33;
        else if (str=="ba") number=34;
        else if (str=="f1") number=35;
        else if (str=="f2") number=36;
        else if (str=="f3") number=37;
        else if (str=="f4") number=38;
        else if (str=="f5") number=39;
        else if (str=="f6") number=40;
        else if (str=="f7") number=41;
        else if (str=="f8") number=42;
        else if (str=="xx") number=43;
*/
        }else{
          if (str=="w") number=0+number;
          else if (str=="t") number=9+number;
          else if (str=="s") number=18+number;
          if (flag==2){
             number%=9;
             if (number==0) number=9;
          }
        }
        if (!flag)
        {
        	if(number>=sizeof(MjC)) return MjC[0];
        	return MjC[number];
        }
        else if(flag==3) {
        	if(str=="w") return HIR+MjC[number]+NOR;
        	else if(str=="t") return HIC+MjC[number]+NOR;
        	else if(str=="s") return HIG+MjC[number]+NOR;
        	else if(str=="jo") return HIR+MjC[number]+NOR;
        	else if(str=="fa") return HIG+MjC[number]+NOR;
        	else if(str=="ba") return HIW+MjC[number]+NOR;
        	else return HIM+MjC[number]+NOR;
        }
        else return number;
}
void check_flower(mapping who)
{
        string newstr = "",str=who["Mj"],temp,temp1;
        int i = strlen(str),j;
 
        while(i--){
              i--;
           temp=str[i..i+1];
           if (temp=="f1"||temp=="f2"||temp=="f3"||temp=="f4"||
               temp=="f5"||temp=="f6"||temp=="f7"||temp=="f8"){
              if (Playing){
                 tell_room(environment(this_object()),YEL+this_player()->name()+"Ëµ£º"+HIC+"»¨ÅÆ"+NOR+YEL+"²¹»¨!!¡£\n\n"+NOR+this_player()->name()+"ÍùºóÃæ²¹ÁËÒ»ÕÅÅÆ¡£\n",this_player());
                 tell_object(this_player(),"ÄãËµ£º"+HIC+"»¨ÅÆ"+NOR+"²¹»¨!!¡£\n\nÄãÍùºóÃæ²¹ÁËÒ»ÕÅÅÆ¡£\n");
                 tell_object(this_player(),"ÄãÃşµ½ÁËÒ»ÕÅ"+do_check_num(List[end..end+1],0)+"\n");
              }
              HU_F=1;
              who["OutFlower"]+=temp;
              str[i..i+1]=List[end..end+1];
              end-=2;
              i+=2;
              continue;
           }
           else newstr+=temp;
        }
        who["Mj"]=sort_data(newstr);
}
//¼ÆËã datastr ÖĞÓĞ¼¸¸östr
int do_check_Mj(string datastr,string str)
{
/*	string *temp;
	int i;
	datastr="  "+datastr+"  ";
	temp = explode(datastr,str);
	return (sizeof(temp)-1);
*/
        int size=strlen(datastr),check=0;
 
        while(size--){
              size--;
          if (datastr[size..size+1]==str) check++;
        }
        return check;
}
string do_delete_Mj(string datastr,string str,int amount)//°ÑÄ³ÅÆÈ¥µô
{
        int size=strlen(datastr),check;
        string temp="";
 	if(strsrch(datastr,str)==-1) return datastr;
        while(size--){
              size--;
          if (datastr[size..size+1]==str && amount>0) amount--;
          else temp+=datastr[size..size+1];
        }
        size=strlen(temp);
        datastr=temp;
        temp="";
        while(size--){
              size--;
              temp+=datastr[size..size+1];
        }
        return temp;

//	temp=replace_string(datastr, str, "", amount);
//	return temp;
}
string sort_data(string str)
{
        int i = strlen(str),a,b,c,d;
 
        string newstr="",temp="";
        for (a=-1;a<i;a++){
            a++;
            for (b=a+2;b<i;b++){
                b++;
                c=do_check_num(str[a..a+1],1);
                d=do_check_num(str[b-1..b],1);
                if (c < d){
                   temp=str[a..a+1];
                   str[a..a+1]=str[b-1..b];
                   str[b-1..b]=temp;
                }
            }
        }
        return str;
}
int do_look(string arg)
{
        int i,l;
        object me=this_player();
        string Mj="",p1o="",p2o="",p3o="",p4o="",verb;
        mapping who;
 	verb = query_verb();
        if (verb==".")  arg="mj";
        if (verb=="..") arg="chicken";
        if (verb==".1") arg="1p";
        if (verb==".2") arg="2p";
        if (verb==".3") arg="3p";
        if (verb==".4") arg="4p";
        if (verb==".0") arg="all";
        if (me->query("id")==P1Data["Id"]) who=P1Data;
        else if (me->query("id")==P2Data["Id"]) who=P2Data;
        else if (me->query("id")==P3Data["Id"]) who=P3Data;
        else if (me->query("id")==P4Data["Id"]) who=P4Data;
        else if(arg=="mj") {
                if (!Playing){
           		write("ÅÆ¾Ö»¹Ã»¿ªÊ¼!!\n");
           		return 1;
        	}
              i=5;
              Mj+="¶«¼Ò:"+NowPlayerId[0]+"\t ÄÏ¼Ò:"+NowPlayerId[1]+"\t Î÷¼Ò:"+NowPlayerId[2]+"\t ±±¼Ò:"+NowPlayerId[3]+"\n";
              Mj+=P1Data["Id"]+":°Ú\ÔÚÍâÃæµÄÅÆÓĞ:\n";
              Mj+=show_mj(P1Data["Out"]+P1Data["OutPon"]+P1Data["OutFlower"],i+1);

              Mj+=P2Data["Id"]+":°Ú\ÔÚÍâÃæµÄÅÆÓĞ:\n";
              Mj+=show_mj(P2Data["Out"]+P2Data["OutPon"]+P2Data["OutFlower"],i+1);

              Mj+=P3Data["Id"]+":°Ú\ÔÚÍâÃæµÄÅÆÓĞ:\n";
              Mj+=show_mj(P3Data["Out"]+P3Data["OutPon"]+P3Data["OutFlower"],i+1);

              Mj+=P4Data["Id"]+":°Ú\ÔÚÍâÃæµÄÅÆÓĞ:\n";
              Mj+=show_mj(P4Data["Out"]+P4Data["OutPon"]+P4Data["OutFlower"],i+1);

              Mj+=P1Data["Id"]+":´ò¹ıµÄÅÆÓĞ:";
              Mj+=show_mj(P1Data["Dump"],2)+"\n";

              Mj+=P2Data["Id"]+":´ò¹ıµÄÅÆÓĞ:";
              Mj+=show_mj(P2Data["Dump"],2)+"\n";

              Mj+=P3Data["Id"]+":´ò¹ıµÄÅÆÓĞ:";
              Mj+=show_mj(P3Data["Dump"],2)+"\n";

              Mj+=P4Data["Id"]+":´ò¹ıµÄÅÆÓĞ:";
              Mj+=show_mj(P4Data["Dump"],2)+"\n";
              write(Mj);
              return 1;
        }
        else return 0;
        if (who["Auto"]=="auto") l=1;
        if (arg=="1p"||arg=="2p"||arg=="3p"||arg=="4p"||arg=="all"||arg=="chicken"||arg=="end"||arg=="dump"||arg=="mj");
        else return 0;
        if (arg=="1p") who=P1Data;
        if (arg=="2p") who=P2Data;
        if (arg=="3p") who=P3Data;
        if (arg=="4p") who=P4Data;
        if (arg=="1p"||arg=="2p"||arg=="3p"||arg=="4p"){
           i=0;
           if (who["Show"]=="´úÂë") i=3;
           if (who["Show"]=="color") i=5;
           if (!Playing||check_id(me->query("id"),"player")==""||l==1){
              if (who["OutGon"]!=""){
                 Mj+=who["Id"]+":°µ¸ÜµÄÅÆÓĞ:\n";
                 Mj+=show_mj(who["OutGon"],i+1);
              }
              Mj+=who["Id"]+":ÊÖÖĞµÄÅÆÓĞ:\n";
              Mj+=show_mj(who["Mj"],i);
           }
           Mj+=who["Id"]+":°Ú\ÔÚÍâÃæµÄÅÆÓĞ:\n";
           Mj+=show_mj(who["Out"]+who["OutPon"]+who["OutFlower"],i+1);
           Mj+=who["Id"]+":´ò¹ıµÄÅÆ:\n";
           Mj+=show_mj(who["Dump"],2);
        }
        else if (arg=="mj") {
           if (!Playing) return 0;
           if (who["OutGon"]!=""){
              Mj+="ÄãµÄ°µ¸ÜµÄÅÆÓĞ:\n";
              Mj+=show_mj(who["OutGon"],1);
           }
           if (who["Show"]=="´úÂë") i=3;
           if (who["Show"]=="color") i=5;
           Mj+="Äã°Ú\ÔÚÍâÃæµÄÅÆÓĞ:\n";
           Mj+=show_mj(who["Out"]+who["OutPon"]+who["OutFlower"],i+1);
           Mj+="ÄãÊÖÖĞµÄÅÆÓĞ:\n";
           Mj+=show_mj(who["Mj"],i);
           Mj+="ÄãµÄÉè¶¨ÓĞ:";
        }else if (arg=="all") {
              i=0;
              if (who["Show"]=="´úÂë") i=3;
              if (who["Show"]=="color") i=5;
              Mj+=show_site(who["Id"]);
              Mj+=P1Data["Id"]+":°Ú\ÔÚÍâÃæµÄÅÆÓĞ:\n";
              Mj+=show_mj(P1Data["Out"]+P1Data["OutPon"]+P1Data["OutFlower"],i+1);
              Mj+=P1Data["Id"]+":´ò¹ıµÄÅÆÓĞ:\n";
              Mj+=show_mj(P1Data["Dump"],2)+"\n";
              Mj+=P2Data["Id"]+":°Ú\ÔÚÍâÃæµÄÅÆÓĞ:\n";
              Mj+=show_mj(P2Data["Out"]+P2Data["OutPon"]+P2Data["OutFlower"],i+1);
              Mj+=P2Data["Id"]+":´ò¹ıµÄÅÆÓĞ:\n";
              Mj+=show_mj(P2Data["Dump"],2)+"\n";
              Mj+=P3Data["Id"]+":°Ú\ÔÚÍâÃæµÄÅÆÓĞ:\n";
              Mj+=show_mj(P3Data["Out"]+P3Data["OutPon"]+P3Data["OutFlower"],i+1);
              Mj+=P3Data["Id"]+":´ò¹ıµÄÅÆÓĞ:\n";
              Mj+=show_mj(P3Data["Dump"],2)+"\n";
              Mj+=P4Data["Id"]+":°Ú\ÔÚÍâÃæµÄÅÆÓĞ:\n";
              Mj+=show_mj(P4Data["Out"]+P4Data["OutPon"]+P4Data["OutFlower"],i+1);
              Mj+=P4Data["Id"]+":´ò¹ıµÄÅÆÓĞ:\n";
              Mj+=show_mj(P4Data["Dump"],2)+"\n";
        }else if (arg=="chicken"){
                 if (Playing){
                    Mj=LookP+"ÕıÈÏÕæµÄÔÚ´òÅÆ\n";
                    Mj+="»¹Ê£ÏÂ"+sprintf("%d",(end-count-16-Goned)/2)+"Ö»ÅÆ¾ÍÁ÷¾ÖÁË¡£\n";
                    if (LastDump!="") Mj+=LastDumpId+"¸Õ¸Õ´ò³öÁË"+show_mj(LastDump,2)+"\n";
                    Mj += "×¯¼Ò: "+NowPlayerId[0];
                    if (Count) Mj+= "[Á¬×¯"+chinese_number(Count)+"]\n";
                    else Mj+="\n";
                    p1o=show_mj(P1Data["Out"]+P1Data["OutPon"]+P1Data["OutFlower"],2);
                    p2o=show_mj(P2Data["Out"]+P2Data["OutPon"]+P2Data["OutFlower"],2);
                    p3o=show_mj(P3Data["Out"]+P3Data["OutPon"]+P3Data["OutFlower"],2);
                    p4o=show_mj(P4Data["Out"]+P4Data["OutPon"]+P4Data["OutFlower"],2);
                    if(NowPlayer==0) Mj+=HIY;
                    Mj+="¶«¼Ò["+NowPlayerId[0]+"]:"+NOR+p1o+"\n";
                    if(NowPlayer==1) Mj+=HIY;
                    Mj+="ÄÏ¼Ò["+NowPlayerId[1]+"]:"+NOR+p2o+"\n";
                    if(NowPlayer==2) Mj+=HIY;
                    Mj+="Î÷¼Ò["+NowPlayerId[2]+"]:"+NOR+p3o+"\n";
                    if(NowPlayer==3) Mj+=HIY;
                    Mj+="±±¼Ò["+NowPlayerId[3]+"]:"+NOR+p4o+"\n";
              
                    Mj+=sprintf("[%10s]´ò¹ıµÄÅÆÓĞ:",P1Data["Id"]);
                    Mj+=show_mj(P1Data["Dump"],2)+"\n";

                    Mj+=sprintf("[%10s]´ò¹ıµÄÅÆÓĞ:",P2Data["Id"]);
                    Mj+=show_mj(P2Data["Dump"],2)+"\n";

                    Mj+=sprintf("[%10s]´ò¹ıµÄÅÆÓĞ:",P3Data["Id"]);
                    Mj+=show_mj(P3Data["Dump"],2)+"\n";

                    Mj+=sprintf("[%10s]´ò¹ıµÄÅÆÓĞ:",P4Data["Id"]);
                    Mj+=show_mj(P4Data["Dump"],2)+"\n";
                 }
                 else if (NowPlayerId[0]!="") Mj=LookP+"ÕıÔÚµÈÈË´òÅÆ";
                 else Mj=LookP+"Ò»Î»¿É°®µÄÂé½«Î÷Ê©ÕıµÈÈË¼ÓÈë(addin)ÅÆ¾Ö¡£";
        }else if (arg=="end"){
           Mj+="»¹ÓĞ"+chinese_number((end-count-16-Goned)/2)+"Ö»ÅÆ¾ÍÁ÷¾ÖÁË\n";
        }else if (arg=="dump"){
           Mj+=LastDumpId+"¸Õ¸Õ´ò³öÁË"+show_mj(LastDump,2)+"\n";
        }
        else return 0;
        if (arg=="mj"){
          if (who["AutoTin"]!="") Mj+="Óöµ½"+show_mj(who["AutoTin"],2)+"»á×Ô¶¯ºúÅÆ¡¢";
          if (who["AutoGon"]!="") Mj+="Óöµ½"+show_mj(who["AutoGon"],2)+"»á×Ô¶¯¸ÜÅÆ¡¢";
          if (who["AutoPon"]!="") Mj+="Óöµ½"+show_mj(who["AutoPon"],2)+"»á×Ô¶¯ÅöÅÆ¡£";
          if (who["Show"]=="´úÂë")    Mj+="ÏÔÊ¾·½Ê½Îª´úÂë·½Ê½¡£";
          if (who["Show"]=="color")   Mj+="ÏÔÊ¾·½Ê½Îª²ÊÉ«¡£";
          if (who["Auto"]=="auto")    Mj+="ÄãÉè¶¨×Ô¶¯ÌıÅÆ¡£";
          if (who["AutoTin"]==""&&who["AutoGon"]==""&&who["AutoPon"]==""&&who["Show"]==""&&who["Auto"]=="") Mj+="ÄãÃ»ÓĞÈÎºÎÉè¶¨¡£\n";
        }
        write(sprintf("%s\n",Mj));
        return 1;
}
int do_tin(string str)
{
	string out,temp;
	int check;
	object me;
	mapping who;
	me=this_player();
/*
write(@HELP_TIN

ÇëÊ¹ÓÃ setmj À´Éè¶¨×Ô¶¯ÌıÅÆ¡£
--------------------------------------------------------------------
1: setmj tin 1w        Éè¶¨»á×Ô¶¯ºúÒ»Íò(1w)¡£
2: setmj auto tin      Éè¶¨×Ô¶¯ÌıÅÆ¡£
3: setmj tin none      È¡Ïû»á×Ô¶¯ºúÅÆÉè¶¨¡£

·¶Àı:
     ÃşÅÆÖ®ºó·¢ÏÖ´òµôÈıÍòÖ®ºó¿ÉÒÔÌı¶şÍò¼°ÎåÍò£¬×Ô¶¯ÌıÅÆ²½ÖèÈçÏÂ:
     1. setmj tin 2w     (Éè¶¨Ìı¶şÍò)
     2. setmj tin 5w     (Éè¶¨ÌıÎåÍò)
     3. setmj auto tin   (Éè¶¨×Ô¶¯Ãş´ò)
     4. dump 3w          (´òµô·ÏÅÆ¿ªÊ¼×Ô¶¯ÌıÅÆ)
     
   <PS. Èç¹ûÉè¶¨µ±ÖĞ´ò´íÁË, Çë´ò setmj tin none ÖØĞÂÉè¶¨ÒªÌıµÄÅÆ¡£>

   Ïë²éÑ¯¸üÏêÏ¸µÄsetmj ÓÃ·¨Çë´ò help setmj ¡£
--------------------------------------------------------------------
HELP_TIN);
*/
        if (!Playing)
        {
           write("ÅÆ¾Ö»¹Ã»¿ªÊ¼¡£\n");
           return 1;
        }
	if (check_id(me->query("id"),"player")!="");
        else
        {
           write("Õâ³¡ÅÆ¾ÖÓëÄãÎŞ¹Ø¡£\n");
           return 1;
        }
        if (me->query("id")!=NowPlayerId[NowPlayer])
        {
        	write("»¹Ã»ÂÖµ½Äã¡£\n");
           return 1;
        }
        if (!Touched){
		write("ÇëÏÈÃşÅÆ¡£\n");
		return 1;
        }

        if (me->query("id")==P1Data["Id"]) who=P1Data;
        else if (me->query("id")==P2Data["Id"]) who=P2Data;
        else if (me->query("id")==P3Data["Id"]) who=P3Data;
        else if (me->query("id")==P4Data["Id"]) who=P4Data;
        else return 1;
	if(who["Auto"]=="auto")
	{
		write("ÄãÒÑ¾­¿ªÊ¼×Ô¶¯ÌıÅÆÁË¡£\n");
		return 1;
	}
        if(!str)
        {
        	write("tin <·ÏÅÆ´úºÅ>¡£\n");
		return 1;	
        } else {
        	check=do_check_Mj(MjE,str);
        	if (check==0) return notify_fail("Ã»ÓĞ["+str+"]ÕâÖÖ´úÂë¡£\n");
        	check=do_check_Mj(who["Mj"],str);
        	if (check==0) return notify_fail("ÄãÃ»"+do_check_num(str,0)+"ÕâÕÅÅÆ¡£\n");
        }
        temp=do_delete_Mj(who["Mj"],str,1);
	out=find_tin(temp);
        if(out=="ERROR") write("¿´²»¶®ÄãÕâÂÒÆß°ËÔãµÄÅÆ¡£\n");
        else if(out!="")
        {
        	//out=show_mj(out,3);
        	write("¿ÉÒÔÌıµÄÅÆÓĞ:["+out+"]\n");
                who["AutoTin"]=out;
           	Auto_Tin=1;
           	message_vision("\n$N´ó½ĞÒ»Éù£º"+HIW+" ¡« ÎÒ ¡« Ìı ¡« ÅÆ ¡« À² ¡«¡«"+NOR+"\n\n",me);
           	Auto=1;
           	who["Auto"]="auto";
           	call_out("do_dump",0,str,me);
        }
        else write("ÄãÄ¿Ç°»¹²»ÄÜÌıÅÆ¡£\n");

        return 1;
}
int do_help(string str)
{
        if (str=="setmj"){
write(@HELP

                       »ù  ±¾  Éè  ¶¨
            setmj ¿ÉÓÃµÄÓĞ×Ô¶¯ºú¡¢¸Ü¡¢Åö¡¢Ìı¡¢ÏÔÊ½·½·¨¡£
--------------------------------------------------------------------
Àı×Ó1: setmj pon 1w        Éè¶¨»á×Ô¶¯Åö1w µ±±ğÈË´ò³öÒ»ÍòÊ±»á×Ô¶¯ÅöÒ»Íò¡£
       setmj gon 1w                                         ×Ô¶¯¸ÜÒ»Íò¡£
       setmj tin 1w        (¿É¶à´ÎÉè¶¨ÒÔ±ãºú¶à¸öÅÆ)         ×Ô¶¯ºúÒ»Íò¡£
Àı×Ó2: setmj show ´úÂë     Éè¶¨ÎªÖ»ÏÔÊ¾´úÂë¡£
       setmj show color    Éè¶¨Îª²ÊÉ«ÏÔÊ¾¡£
Àı×Ó3: setmj tin none      È¡Ïû»á×Ô¶¯ºúÅÆÉè¶¨¡£
       setmj gon none
       setmj pon none
Àı×Ó4: setmj auto tin      Éè¶¨×Ô¶¯ÌıÅÆ¡£
--------------------------------------------------------------------
HELP);
        return 1;
        }
        return 0;
}
string to_say_play()
{
return @HELP

        Ö¸  Áî    Àı          ×Ó                             Ëµ    Ã÷
    ©°©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©´
    ©¦  bet       bet 100 Éè¶¨Ã¿Ì¨Îª100»õ±Ò                  Éè¶¨¶Ä×¢ ©¦
    ©¦  addin     ----------                                 ¼ÓÈëÅÅ¾Ö ©¦
    ©¦  look      l mj»ò.¿´×Ô¼ºÅÆ,l 1p»ò.1¿´Íæ¼Ò1µÄÅÆ                 ©¦
    ©¦            l all»ò..¿´È«²¿,l end¿´Á÷¾Öl dump¡£        ¿´ÅÆ     ©¦
    ©¦  mo(0)     ----------                                 ÃşÅÆ     ©¦
    ©¦  dump(dd)  dump <´úÂë>¡£                              ´òÅÆ     ©¦
    ©¦  eat       eat <´úÂë1> <´úÂë2>¡£                      ³ÔÅÆ     ©¦
    ©¦  pon(p)    ----------                                 ÅöÅÆ     ©¦
    ©¦  gon       gon »ò gon <´úÂë>(°µ¸ÜÓÃ)¡£                ¸ÜÅÆ     ©¦
    ©¦  hu                                                   ºúÅÆ     ©¦
    ©¦  setmj     help setmj¡£                               Éè¶¨²ÎÊı ©¦
    ©¦  start     ----------                                 ÅÆ¾Ö¿ªÊ¼ ©¦
    ©¦  restart   restart »ò restart mj¡£                    ÖØĞÂ¿ªÊ¼ ©¦
    ©¦  showmj    showmj <id> ÈÃÆäËûÈË¿´×Ô¼ºµÄÅÆ             ÏÖÅÆ     ©¦
    ©¦  top       top                                        ²é×ÊÁÏ   ©¦
    ©¸©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¼
HELP;
    //    return 1;
}
string to_say_rule()
{
return @HELP
 
¡¡¡¡Ã¿ºú¾ÍÓĞµ×Ì¨£³£¬ÔÚ¼ÓÉÏËùµÃµÄÌ¨¾ÍÊÇ×ÜÌ¨£¬ÒªÊÇ×ÔÃş¾Í£ª£³£¬Ïàµ±ÓÚÈıÒ»µÄËã·¨¡£
·ÅÇ¹¾ÍÓÉ×ÜÕ½¼¨ÄÇ¿ÛµôËùÊ§µÄÌ¨Êı¡£ºúÕßÔò¼ÓÉÏÈ¥¡£
 
HELP;
    //    return 1;
}

int show_top(string arg)
{
        string output="",*user_data=({}),*record_key=({});
        int i;
        object me;
        me=this_player();
        if (sizeof(record) < 1)
           return notify_fail("Ä¿Ç°Ã»ÓĞÕ½¼¨¼ÇÂ¼¡£\n");
	if(!arg)
	{
		record_key = keys(record);
		user_data = do_sort_record("total",record_key);
		output  = "ÅÅ Ãû        Íæ    ¼Ò           ¾ÖÊı ×ÔÃş ºúÅÆ ·ÅÇ¹ Õ½¼¨·Ö ·¸¹æ\n";
		output += "===== ========================= ==== ==== ==== ==== ====== ====\n";
		for(i=0;i<sizeof(user_data);i++)
		{
			output+=sprintf("%-5d %-24s %4d %4d %4d %4d %6d %4d\n",
				i+1,
				record[user_data[i]]["name"],
				record[user_data[i]]["rounds"],
				record[user_data[i]]["self"],
				record[user_data[i]]["win"],
				record[user_data[i]]["lose"],
				record[user_data[i]]["total"],
				record[user_data[i]]["bad"]
				);
		}
		me->start_more(output);
		return 1;
	}
	record_key = keys(record);
	user_data = do_sort_record("total",record_key);
	if(member_array(arg,user_data)!=-1)
	{
		output  = "ÅÅ Ãû        Íæ    ¼Ò           ¾ÖÊı ×ÔÃş ºúÅÆ ·ÅÇ¹ Õ½¼¨·Ö ·¸¹æ\n";
		output += "===== ========================= ==== ==== ==== ==== ====== ====\n";
		for(i=0;i<sizeof(user_data);i++)
		{
			if(user_data[i]!=arg) continue;
			output+=sprintf("%-5d %-24s %4d %4d %4d %4d %6d %4d\n",
				i+1,
				record[user_data[i]]["name"],
				record[user_data[i]]["rounds"],
				record[user_data[i]]["self"],
				record[user_data[i]]["win"],
				record[user_data[i]]["lose"],
				record[user_data[i]]["total"],
				record[user_data[i]]["bad"]
				);
		}
		me->start_more(output);
		return 1;
	}
	else
	{
		write("²éÎŞ´ËÍæ¼ÒÕ½¼¨¼ÇÂ¼¡£\n");
		return 1;
	}
//	else return notify_fail("Õ½¼¨¼ÇÂ¼±íÕıÔÚĞŞ¸ÄÖĞ¡£\n");
	return 1;
}
/*
int show_top(string str)
{
        string output="",*user_key,*lists;
        mapping *user_data=({ });
        int i;
        object me;
        me=this_player();
        if (sizeof(record) < 1)
           return notify_fail("Ä¿Ç°Ã»ÓĞÕ½¼¨¼ÇÂ¼¡£\n");
//	for(i=0;i<sizeof(record_key);i++)
//	{       // [0..23]name [25..28]rounds [30..33]self [35..38]win [40..43]lose [45..50]total [52..55]bad
//		user_data
//	}
//
	lists = keys(record);
	for(i=0;i<sizeof(lists);i++)
	{
		user_data += ({ record[lists[i]] });
	}
	user_data = sort_array(user_data, "sort_user", this_object());
	output  = "       Íæ    ¼Ò           ¾ÖÊı ×ÔÃş ºúÅÆ ·ÅÇ¹ Õ½¼¨·Ö ·¸¹æ\n";
	output += "========================= ==== ==== ==== ==== ====== ====\n";
	for(i=0;i<sizeof(user_data);i++)
	{
		output+=sprintf("%-24s %4d %4d %4d %4d %6d %4d\n",
			user_data[i]["name"],
			user_data[i]["rounds"],
			user_data[i]["self"],
			user_data[i]["win"],
			user_data[i]["lose"],
			user_data[i]["total"],
			user_data[i]["bad"]
			);
	}
	me->start_more(output);
	return 1;	
}
*/
// score ¸ñÊ½: ({ 0×ÔÃş,1ºúÅÆ,2·ÅÇ¹,3Ì¨Êı<·ÅÇ¹Îª¸ºµÄ>,4·¸¹æ })
int set_mjdata(object me,int *score)
{
	if(!me ) return 0;
	message_vision("$NÁ¢¿Ì½«$nµÄ³É¼¨¼ÇÂ¼ÏÂÀ´¡£\n",this_object(),me);
	if(undefinedp(record[getuid(me)]))
	{
		record[getuid(me)] = ([
		"name": me->name_id(1),
		"rounds" : 1,
		"self" : score[0],
		"win" : score[1],
		"lose" : score[2],
		"total" : score[3],
		"bad" : score[4],
		]);
	}
	else
	{
		record[getuid(me)]["rounds"]++;
		record[getuid(me)]["self"]+=score[0];
		record[getuid(me)]["win"]+=score[1];
		record[getuid(me)]["lose"]+=score[2];
		record[getuid(me)]["total"]+=score[3];
		record[getuid(me)]["bad"]+=score[4];
		
	}
        return 1;
}

int get_tc(mapping who)
{
        int size,i,check;
        string str,tempW="",tempT="",tempS="",tempB="";
        str=who["Mj"]+who["Out"]+who["OutPon"]+who["OutGon"];
        //×¯¼Ò
        if (NowPlayerId[0]==who["Id"]) Tc+="@1";
        //ÃÅÇå&×ÔÃş
        if (who["Out"]==""&&who["OutPon"]==""&&Touched) Tc+="@l";
        else if (who["Out"]==""&&who["OutPon"]=="") Tc+="@4";
        else if (Touched) Tc+="@2";
        //È«ÇóÈË
        if (strlen(who["Mj"]) < 5) Tc+="@i";
        size=strlen(str);
        while(size--){
              size--;
          if (do_check_num(str[size..size+1],1) < 10) tempW+=str[size..size+1];
          else if (do_check_num(str[size..size+1],1) < 19) tempT+=str[size..size+1];
          else if (do_check_num(str[size..size+1],1) < 28) tempS+=str[size..size+1];
          else tempB+=str[size..size+1];
        }
        //·çÅÆ
        if (Times/Play == 0 && NowPlayerId[0]==who["Id"]&&do_check_Mj(tempB,"ea")>2) Tc+="@e";
        else if (Times/Play == 0 && do_check_Mj(tempB,"ea") > 2
             ||  NowPlayerId[0]==who["Id"]&&do_check_Mj(tempB,"ea")>2) Tc+="@5";
        if (Times/Play == 1 &&NowPlayerId[1]==who["Id"]&&do_check_Mj(tempB,"so")>2) Tc+="@f";
        else if (Times/Play == 1 && do_check_Mj(tempB,"so") > 2
             ||  NowPlayerId[1]==who["Id"]&&do_check_Mj(tempB,"so")>2) Tc+="@6";
        if (Times/Play == 2 &&NowPlayerId[2]==who["Id"]&&do_check_Mj(tempB,"we")>2) Tc+="@g";
        else if (Times/Play == 2 && do_check_Mj(tempB,"we") > 2
             ||  NowPlayerId[2]==who["Id"]&&do_check_Mj(tempB,"we")>2) Tc+="@7";
        if (Times/Play == 3 && NowPlayerId[3]==who["Id"]&&do_check_Mj(tempB,"no")>2) Tc+="@h";
        else if (Times/Play == 3 && do_check_Mj(tempB,"no") > 2
             ||  NowPlayerId[3]==who["Id"]&&do_check_Mj(tempB,"no")>2) Tc+="@8";
        //»¨ÅÆ
        if (sizeof(who["OutFlower"]) ==16) Tc+="@A";//°ËÏÉ¹ıº£
        else if (sizeof(who["OutFlower"]) ==14&&sizeof(P1Data["OutFlower"]+P2Data["OutFlower"]+P3Data["OutFlower"]+P4Data["OutFlower"])==16) Tc+="@D";//ÆßÇÀÒ»
        else if (do_check_Mj(who["OutFlower"],"f1")==1&&do_check_Mj(who["OutFlower"],"f2")==1
        &&  do_check_Mj(who["OutFlower"],"f3")==1&&do_check_Mj(who["OutFlower"],"f4")==1) Tc+="@B";//´ºÏÄÇï¶¬
        else if (do_check_Mj(who["OutFlower"],"f5")==1&&do_check_Mj(who["OutFlower"],"f6")==1
        &&  do_check_Mj(who["OutFlower"],"f7")==1&&do_check_Mj(who["OutFlower"],"f8")==1) Tc+="@C";//Ã·À¼¾ÕÖñ
        else if (NowPlayerId[0]==who["Id"]&&do_check_Mj(who["OutFlower"],"f1")==1
        ||  NowPlayerId[0]==who["Id"]&&do_check_Mj(who["OutFlower"],"f5")==1
        ||  NowPlayerId[1]==who["Id"]&&do_check_Mj(who["OutFlower"],"f2")==1
        ||  NowPlayerId[1]==who["Id"]&&do_check_Mj(who["OutFlower"],"f6")==1
        ||  NowPlayerId[2]==who["Id"]&&do_check_Mj(who["OutFlower"],"f3")==1
        ||  NowPlayerId[2]==who["Id"]&&do_check_Mj(who["OutFlower"],"f7")==1
        ||  NowPlayerId[3]==who["Id"]&&do_check_Mj(who["OutFlower"],"f4")==1
        ||  NowPlayerId[3]==who["Id"]&&do_check_Mj(who["OutFlower"],"f8")==1) Tc+="@3";
        //ÇåÒ»É«¸ú×ÖÒ»É«
        if (tempW!=""&&tempT==""&&tempS==""&&tempB=="") Tc+="@q";
        else if (tempW==""&&tempT!=""&&tempS==""&&tempB=="") Tc+="@q";
        else if (tempW==""&&tempT==""&&tempS!=""&&tempB=="") Tc+="@q";
        else if (tempW==""&&tempT==""&&tempS==""&&tempB!="") Tc+="@r";
        //»ìÒ»É«
        if (tempW!=""&&tempT==""&&tempS==""&&tempB!="") Tc+="@n";
        else if (tempW==""&&tempT!=""&&tempS==""&&tempB!="") Tc+="@n";
        //ÂÌÒ»É«
        else if (tempW==""&&tempT==""&&tempS!=""&&tempB!=""){
             if (do_check_Mj(tempB,"fa")==3&&sizeof(tempB)==6
             ||  do_check_Mj(tempB,"fa")==2&&sizeof(tempB)==4
             && do_check_Mj(tempS,"1s")==0&& do_check_Mj(tempS,"5s")==0
             && do_check_Mj(tempS,"7s")==0&& do_check_Mj(tempS,"9s")==0) Tc+="@E";
             else Tc+="@n";
        }
        //´óÈıÔª
        if (do_check_Mj(tempB,"jo") > 2
        &&  do_check_Mj(tempB,"fa") > 2
        &&  do_check_Mj(tempB,"ba") > 2) Tc+="@t";
        //Ğ¡ÈıÔª
        else if (do_check_Mj(tempB,"jo") > 1
        &&  do_check_Mj(tempB,"fa") > 1
        &&  do_check_Mj(tempB,"ba") > 1) Tc+="@o";
        else if (do_check_Mj(tempB,"jo") > 2) Tc+="@9";
        else if (do_check_Mj(tempB,"fa") > 2) Tc+="@0";
        else if (do_check_Mj(tempB,"ba") > 2) Tc+="@a";
        //´óËÄÏ²
        if (do_check_Mj(tempB,"ea") > 2
        &&  do_check_Mj(tempB,"so") > 2
        &&  do_check_Mj(tempB,"we") > 2
        &&  do_check_Mj(tempB,"no") > 2) Tc+="@v";
        //Ğ¡ËÄÏ²
        else if (do_check_Mj(tempB,"ea") > 1
        &&  do_check_Mj(tempB,"so") > 1
        &&  do_check_Mj(tempB,"we") > 1
        &&  do_check_Mj(tempB,"no") > 1) Tc+="@F";
 
        for (i=0;i<sizeof(str);i+=2){
            if (str[i..i+1]=="xx") continue;
            if (do_check_Mj(str,str[i..i+1])==3) check++;
            else if (do_check_Mj(str,str[i..i+1])==4) check++;
        }
        //ÅöÅöºú
        if (check>14){
           if (who["Out"]==""&&who["OutPon"]==""&&do_check_Mj(Tc,"@u")==0) Tc+="@m@u";
           else  Tc+="@m";
        }
        check=0;
        for (i=0;i<sizeof(str);i+=2){
            if (do_check_num(str[i..i+1],1)!=1&&do_check_num(str[i..i+1],1)>8) check++;

        }
        if (check=0&&tempB!="") Tc+="@I";//»ìÀÏÍ·
        else if (check=0&&tempB="") Tc+="@J";//ÇåÀÏÍ·
        //Æ½ºú
        if (tempB==""&&who["OutFlower"]==""&&check==0&&sizeof(who["AutoTin"])>3) Tc+="@d";
        //ºÓµ×ÃşÔÂ
        if (count==((end-16-(Goned*2))-2)&&Touched) Tc+="@b";
        //ÀÌÓã
        if (count==((end-16-(Goned*2))-2)&&!Touched) Tc+="@c";
        //Ììºú
        if (LastDump==""&&count==(Play*2*16)+2) Tc+="@w";
        //µØºú&ÈËºú
        write(sprintf("%d > %d\n",count,((Play*2*16)+(Play*2))));
        if (count < ((Play*2*16)+(Play*2))
        &&P1Data["Out"]==""&&P1Data["PonOut"]==""
        &&P2Data["Out"]==""&&P2Data["PonOut"]==""
        &&P3Data["Out"]==""&&P3Data["PonOut"]==""
        &&P4Data["Out"]==""&&P4Data["PonOut"]==""){
           if (Touched) Tc+="@x";
           else Tc+="@y";
        }
        return 1;
}
int ch(string str)
{
        object me=this_player();
        mapping who;
        if (me->query("id")==P1Data["Id"]) who=P1Data;
        else if (me->query("id")==P2Data["Id"]) who=P2Data;
        else if (me->query("id")==P3Data["Id"]) who=P3Data;
        else if (me->query("id")==P4Data["Id"]) who=P4Data;
        if(!str) return 0;
        if(!wizardp(me)) return 0;
        write("Äã°ÑÅÆ"+who["Mj"]+"»»³É"+str+" ok.\n");
        str=sort_data(str);
        who["Mj"]=str;
        return 1;
}
int do_bet(string arg)
{
	int bet_amount;
        if(Playing){
		if(!arg) {
			if(BetAmount<=0) command("say Ä¿Ç°Õâ³¡±ÈÈü²¢Î´Éè¶¨¶Ä×¢£¬´¿ÇĞ´èÅÆ¼¼¡£");
     //   		else command("say Ä¿Ç°µÄ¶Ä×¢ÊÇÃ¿Ì¨ "+price_string(BetAmount,this_player()->money_type())+"¡£");
		}
		else {
           		command("say ÅÆ¾Ö¿ªÊ¼Ö®ºó¾Í²»ÄÜ»»¶Ä×¢½ğ¶îÁË¡£");
           	}
           return 1;
        }
        if(!arg){
        	if(BetAmount<=0) command("say Ä¿Ç°²¢Î´Éè¶¨¶Ä×¢£¬´¿Á·¹¦\·ò¡£");
     //   	else command("say ÏÈÇ°Éè¶¨µÄ¶Ä×¢ÊÇÃ¿Ì¨ "+price_string(BetAmount,this_player()->money_type())+"¡£");
        	return 1;
        }
	if(sscanf(arg,"%d",bet_amount)!=1) {
		write("Éè¶¨¶Ä×¢·½·¨Îª: bet <½ğ¶î> , Èô´¿ÓéÀÖÇëÓÃ bet 0\n");
		return 1;
	}
	if(bet_amount < BASIC_BET ){
//		command("say ¶Ä×¢²»¿ÉÒÔĞ¡ÓÚ"+price_string(BASIC_BET,this_player()->money_type())+"¡£");
		return 1;
	}
	if(bet_amount > BET_LIMIT ){
//		command("say ¶Ä×¢²»¿ÉÒÔ´óÓÚ"+price_string(BET_LIMIT,this_player()->money_type())+"¡£");
		return 1;
	}
	if(Play>0) {
		command("say ÒªÉè¶¨¶Ä×¢±ØĞëÔÚ»¹Ã»ÓĞÈË¼ÓÈëÅÆ×À(addin)Ç°Éè¶¨¡£");
		return 1;
	}
	BetAmount = bet_amount;
  //      message_vision("$NÇë$n½«±¾¾ÖµÄ¶Ä×¢Éè¶¨ÎªÃ¿Ì¨ "+price_string(BetAmount,this_player()->money_type())+"¡£\n",this_player(),this_object());
        return 1;
}

string query_save_file() { return DATA_DIR + "obj/past_mj1"; }

string *do_sort_record(string type,string *keys)
{
	string *temp_keys,*result=({});
	int i=0,j,max_value,mark;
	temp_keys=keys;
	while(i<sizeof(keys) )
	{
		max_value=-99999;
		mark=0;
		for(j=0;j<sizeof(temp_keys);j++) //ÕÒ×î´óÖµ
		{
			if(record[temp_keys[j]][type]>max_value)
			{
			 max_value=record[temp_keys[j]][type];
			 mark=j;
			}
			
		}
		if(sizeof(temp_keys)>0)
		{
			result+=({temp_keys[mark]});
			temp_keys-=({temp_keys[mark]});
		}
		i++;
	}
	return result;
}
int do_showmj(string str)
{
	int i;
        object me,target;
        string Mj="",p1o="",p2o="",p3o="",p4o="",myname;
        mapping who;
        me=this_player();
        if (check_id(me->query("id"),"player")!="");
        else {
           command("slap "+me->query("id"));
           command("say ÕâÅÆ¾Ö¸úÄãÃ»¹ØÏµ¡£");
           return 1;
        }
        if (!Playing){
           command("say ÅÆ¾Ö»¹Ã»¿ªÊ¼!!");
           return 1;
        }
        if(!str) {
           write("Òª¸ø±ğÈË¿´ÅÆÇë´ò showmj <id>\n");
           return 1;
        }
        if (me->query("id")==P1Data["Id"]) who=P1Data;
        else if (me->query("id")==P2Data["Id"]) who=P2Data;
        else if (me->query("id")==P3Data["Id"]) who=P3Data;
        else if (me->query("id")==P4Data["Id"]) who=P4Data;
        else return 0;
        if(!target=present(str, environment(me))){
        	write("ÕâÀïÃ»ÓĞÕâ¸öÈË¿ÉÒÔ°ïÄã¿´ÅÆ¡£\n");
        	return 1;
        }
        if(target == me) {
        	write("×Ô¼ºÒª¿´×Ô¼ºµÄÅÆÖ»Òª°´ . ¾Í¿ÉÒÔÁË¡£\n");
        	return 1;
        }
        myname=me->name(1);
        if (who["OutGon"]!=""){
            Mj+=myname+"°µ¸ÜµÄÅÆÓĞ:\n";
            Mj+=show_mj(who["OutGon"],1);
        }
        if (who["Show"]=="´úÂë") i=3;
        if (who["Show"]=="color") i=5;
        Mj+=myname+"°Ú\ÔÚÍâÃæµÄÅÆÓĞ:\n";
        Mj+=show_mj(who["Out"]+who["OutPon"]+who["OutFlower"],i+1);
        Mj+=myname+"ÊÖÖĞµÄÅÆÓĞ:\n";
        Mj+=show_mj(who["Mj"],i);
        Mj+=myname+"µÄÉè¶¨ÓĞ:";
        if (who["AutoTin"]!="") Mj+="Óöµ½"+show_mj(who["AutoTin"],2)+"»á×Ô¶¯ºúÅÆ¡¢";
        if (who["AutoGon"]!="") Mj+="Óöµ½"+show_mj(who["AutoGon"],2)+"»á×Ô¶¯¸ÜÅÆ¡¢";
        if (who["AutoPon"]!="") Mj+="Óöµ½"+show_mj(who["AutoPon"],2)+"»á×Ô¶¯ÅöÅÆ¡£";
        if (who["Show"]=="´úÂë")    Mj+="ÏÔÊ¾·½Ê½Îª´úÂë·½Ê½¡£";
        if (who["Show"]=="color")   Mj+="ÏÔÊ¾·½Ê½Îª²ÊÉ«¡£";
        if (who["Auto"]=="auto")    Mj+=myname+"ÒÑ¾­Éè¶¨×Ô¶¯ÌıÅÆ¡£";
        if (who["AutoTin"]==""&&who["AutoGon"]==""&&who["AutoPon"]==""&&who["Show"]==""&&who["Auto"]=="") Mj+="ÄãÃ»ÓĞÈÎºÎÉè¶¨¡£\n";
	message_vision("$N°ÑÊÖÖĞµÄÅÆÄÃ¸ø$n¿´ÁËÒ»ÏÂ¡£\n",me,target);
	tell_object(target,sprintf("%s\n",Mj));
        return 1;
}
//×Ô¶¯ÕÒ¿ÉÌıµÄÅÆ
string find_tin(string mymj)
{
	string *cards=({}),temp,testcard,oldcard,Wmj="",Smj="",Tmj="",Bmj="";
	int *cardnum=({}),*cardd=({}),tempnum,checknum,i,j;
	if(!mymj) return "";
	oldcard = mymj;
	//mymj = sort_data(mymj);
	//×ª´úºÅÎª±àÂë.È»ºóÑ°ÕÒÓĞ¹ØÁªµÄÅÆ±àºÅ
	while(strlen(mymj)>1)
	{
		temp = mymj[0..1];
		mymj = mymj[2..];
//		message_vision("temp=["+temp+"] mymj=["+mymj+"]\n",this_object());
		tempnum=do_check_num(temp,1);
		if(tempnum<1 || tempnum >34) //ÎŞÒâÒåµÄÅÆ
		{
			return "";
		}
		else if(tempnum>=28 && tempnum <=34) //×ÖÅÆ
		{
			if(member_array(tempnum,cardnum)==-1) cardnum+=({tempnum});
			Bmj+=temp;
		}
		else
		{
			if(tempnum<10) Wmj+=temp;
			else if(tempnum<19) Tmj+=temp;
			else Smj+=temp;
			checknum=tempnum%9;
			if(checknum==1) // 1
			{
				if(member_array(tempnum+1,cardnum)==-1) cardnum+=({tempnum+1});
			}
			else if(checknum==0) // 9
			{
				if(member_array(tempnum-1,cardnum)==-1) cardnum+=({tempnum-1});
			}
			else
			{
				if(member_array(tempnum-1,cardnum)==-1) cardnum+=({tempnum-1});
				if(member_array(tempnum+1,cardnum)==-1) cardnum+=({tempnum+1});
			}
			if(member_array(tempnum,cardnum)==-1) cardnum+=({tempnum});
		}
	}
//	message_vision("Wmj=["+Wmj+"] Tmj=["+Tmj+"] Smj=["+Smj+"] Bmj=["+Bmj+"]\n",this_object());
	for(i=0;i<sizeof(cardnum);i++)
	{
		if(cardnum[i]>=28 && cardnum[i]<=34) //×ÖÅÆ
		{
			if(sizeof(Bmj)>0 && sizeof(Bmj)%6 == 0) continue;
		}
		 else if(cardnum[i]<=9) //Íò
		{
			if(sizeof(Wmj)>0 && sizeof(Wmj)%6 == 0) continue;
		}
		 else if(cardnum[i]<=18) //Í²
		{
			if(sizeof(Tmj)>0 && sizeof(Tmj)%6 == 0) continue;
		}
		 else if(cardnum[i]<=27) //Ë÷
		{
			if(sizeof(Smj)>0 && sizeof(Smj)%6 == 0) continue;
		}
	
		cardd+=({cardnum[i]});
	}
	if(sizeof(cardd)>11) return "ERROR";
	for(i=0;i<sizeof(cardd);i++)
	{
		testcard = MjE[((cardd[i]-1)*2)..((cardd[i]-1)*2)+1];
		temp = oldcard+testcard;
		temp = sort_data(temp);
		j=do_check_win(temp,1);
		if(j==1) cards+=({testcard});
	}
	temp = "";
	for(i=0;i<sizeof(cards);i++)
	{
		temp+=cards[i];
	}
	return temp;
}

string show_site(string myid)
{
	string out="",face="",up="",down="",face_mark=" ",up_mark=" ",down_mark=" ",myid_mark=" ";
	if(!myid) return "\n";
	if(sizeof(NowPlayerId)>0 && myid==NowPlayerId[0])
	{
		if(Play>1) down = NowPlayerId[1];
		if(Play>2) face = NowPlayerId[2];
		if(Play>3) up = NowPlayerId[3];
	} 
	 else if(sizeof(NowPlayerId)>1 && myid==NowPlayerId[1])
	{
		if(Play>2) down = NowPlayerId[2];
		if(Play>3) face = NowPlayerId[3];
		up = NowPlayerId[0];
	}
	 else if(sizeof(NowPlayerId)>2 && myid==NowPlayerId[2])
	{
		if(Play>3) down = NowPlayerId[3];
		face = NowPlayerId[0];
		up = NowPlayerId[1];
	}
	 else if(sizeof(NowPlayerId)>3 && myid==NowPlayerId[3])
	{
		down = NowPlayerId[0];
		face = NowPlayerId[1];
		up = NowPlayerId[2];
	}
	else 
	{
			if(Play>0) myid = NowPlayerId[0];
			if(Play>1) down = NowPlayerId[1];
			if(Play>2) face = NowPlayerId[2];
			if(Play>3) up = NowPlayerId[3];
	}
	if(NowPlayerId[NowPlayer]==face) face_mark="*";
	else if(NowPlayerId[NowPlayer]==up) up_mark="*";
	else if(NowPlayerId[NowPlayer]==down) down_mark="*";
	else if(NowPlayerId[NowPlayer]==myid) myid_mark="*";
//                     face
//               ©°©¤©¤©¤©¤©¤©´
//               ©¦  ¡¡¡¡¡¡  ©¦
//               ©¦¡¡      ¡¡©¦
//             up©¦¡¡  ¡ß  ¡¡©¦down
//               ©¦¡¡      ¡¡©¦
//               ©¦  ¡¡¡¡¡¡  ©¦
//               ©¸©¤©¤©¤©¤©¤©¼
//                    myid

	out = sprintf("             %13s\n",face_mark+face);
	out += "               ©°©¤©¤©¤©¤©¤©´\n";
	out += "               ©¦  ¡¡¡¡¡¡  ©¦\n";
	out += "               ©¦¡¡      ¡¡©¦\n";
	out += sprintf("  %13s©¦¡¡  ¡ß  ¡¡©¦%-13s\n",up_mark+up,down_mark+down);
	out += "               ©¦¡¡      ¡¡©¦\n";
	out += "               ©¦  ¡¡¡¡¡¡  ©¦\n";
	out += "               ©¸©¤©¤©¤©¤©¤©¼\n";
	out += sprintf("             %13s\n\n",myid_mark+myid);
	return out;
}
