// Room: /d/wiz/init.c
// by tianlin 2001.5.1
#include <ansi.h>
inherit ROOM;

void show_gift(object me);
string _show_gift(object me);
void do_finish(object me);
void get_start(object me);

string start_room="/d/city/kezhan";
string *index=({
	"str","con","int","spi",
	"cps","per","cor","kar",
	});
mapping giftn=([
	"str":"Ìå¸ñ",
	"con":"¸ù¹Ç",
	"int":"ÎòĞÔ",
	"spi":"ÁéĞÔ",
	"cps":"¶¨Á¦",
	"per":"ÈİÃ²",
	"kar":"¸£Ôµ",
	"cor":"µ¨Ê¶",
	]);
mapping gift=([
	"str":20,
	"con":20,
	"int":25,
	"spi":25,
	"cps":20,
	"per":20,
	"kar":20,
	"cor":20,
	]);

void create()
{
	set("short", "\n»¶Ó­¹âÁÙÃÎ»ÃÎ÷ÓÎ£¡");
	set("no_fight",1);
	set("no_magic",1);
	
	setup();
}

void init()
{
    object me=this_player();
    
    if(!userp(me)) return;
    if(!wizardp(me) &&
	    ((int)me->query("combat_exp")>0 ||
	     (int)me->query("daoxing")>0 ||
	     (int)me->query("no_gift")==0 )) {
	me->move(start_room);
	return;
    }  
    add_action("do_block","",1);
    add_action("get_start1","start");
    if(me->query("no_gift")) {
      me->set_temp("gifts",copy(gift));
      me->set_temp("gift_left",0);
      call_out("get_start0",0,me);
    }
}

void get_start0(object me)
{
    if(!me) return;
    
    me->command("start");
}

int get_start1(string arg)
{
    object me=this_player();
    write("\n\n»¶Ó­¹âÁÙÃÎ»ÃÎ÷ÓÎ£¡\n");
    write(@LONG

ÔÚ¿ªÊ¼ÄãµÄÎ÷ÓÎÀú³ÌÖ®Ç°£¬Ê×ÏÈÒªÎª×Ô¼ºËù´´ÔìµÄÈËÎïÑ¡ÔñÒ»¸öºÏÊÊ
µÄÌì¸³£¬ÒòÎªÕâ½«¶ÔÄã½ñºóµÄ·¢Õ¹ÓĞÖØ´óµÄÓ°Ïì¡£ÃÎ»ÃÎ÷ÓÎÖĞµÄÈËÎïÌì
¸³¹²ÓĞËÄÏî[1;33m£¨Ïê¼û help gifts £©[2;37;0m£¬Ã¿ÏîÓÉÒ»¸öÊ®µ½ÈıÊ®Ö®¼äµÄÕûÊı
À´±íÊ¾£¬Ò»°ãÊıÖµÔ½´óÔ½ºÃ£¬µ«¸÷ÏîµÄ×ÜºÍÊÇ¹Ì¶¨²»±äµÄ¡£
LONG
	);
    get_start(me);
    return 1;
}

void get_start(object me)
{
    if(!me) return;
    show_gift(me);
    input_to("get_input",me);
}

void get_input(string arg, object me)
{
    int ind;

    if(!me) return;
    if(!arg || sscanf(arg,"%d",ind)!=1 || ind<0
	    || (ind>3 && ind!=9)) {
	get_start(me);
	return;
    }
    if(ind<8) {
	write("ÇëÊäÈë"+giftn[index[ind]]+"µÄĞÂÈ¡Öµ[10-30]£º");
	input_to("get_number",me,ind);
	return;
    } else {
	write("ÄãÈ·¶¨½ÓÊÜµ±Ç°µÄÌì¸³ÉèÖÃÂğ£¿[y/n]");
	input_to("get_finish",me);
	return;
    }
}

void get_finish(string arg, object me)
{
    if(!me) return;
    if(!arg) {
	write("ÄãÈ·¶¨½ÓÊÜµ±Ç°µÄÌì¸³ÉèÖÃÂğ£¿[y/n]");
	input_to("get_finish",me);
	return;
    }
    if(arg[0..0]=="y" || arg[0..0]=="Y") {
	do_finish(me);
	return;
    }
    if(arg[0..0]=="n" || arg[0..0]=="N") {
	get_start(me);
	return;
    }
    write("ÄãÈ·¶¨½ÓÊÜµ±Ç°µÄÌì¸³ÉèÖÃÂğ£¿[y/n]");
    input_to("get_finish",me);
    return;
}

void show_gift(object me)
{
    write(_show_gift(me));
}

string _show_gift(object me)
{
    mapping my;
    string result;
    int left;

    if(!me) return "";
    my=me->query_temp("gifts");
    left=me->query_temp("gift_left");
    if(!my) return "";
    
    result=("\n");
    result+="©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤\n";
    result+=sprintf(
//	    " 0. ¶¨Á¦£º[%d]        1. ÈİÃ²£º[%d]\n"+
//            " 2. µ¨Ê¶£º[%d]        3. ¸£Ôµ£º[%d]\n"
//	    +" 4. Ìå¸ñ£º[%d]        5. ¸ù¹Ç£º[%d]\n"+
//	     " 6. ÎòĞÔ£º[%d]        7. ÁéĞÔ£º[%d]\n"
	    " 0. Ìå¸ñ£º[%d]        1. ¸ù¹Ç£º[%d]\n"+
	    " 2. ÎòĞÔ£º[%d]        3. ÁéĞÔ£º[%d]\n"
	     ,
//	    my["cps"],my["per"],my["cor"],my["kar"],
	    my["str"],my["con"],my["int"],my["spi"]
	    );
    result+="©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤\n";
    if(left)
      result+="ÄãÏÖÓĞ"+chinese_number(left)+"µãÌì¸³»¹Ã»ÓĞ·ÖÅä¡£\n";
    result+="ÇëÑ¡ÔñÄãÏëÖØĞÂÉèÖÃÄÄÒ»ÏîÌì¸³µÄÈ¡Öµ[0-3]£¬\n"+
	"Ñ¡Ôñ[9]Ôò½ÓÊÜµ±Ç°µÄÉèÖÃ£º";
    return result;
}

void do_finish(object me)
{
    mapping gt;
    int i, left, ok;
    string *key;
    object env;
    
    if(!me) return;
    left=me->query_temp("gift_left");
    if(left>0) {
	write("Äã×Ü¹²¿ÉÓĞ 90 µãÌì¸³£¬ÏÖÔÚ»¹ÓĞÊ£Óà"+chinese_number(left)
	    +"µãÌì¸³Ã»ÓĞ·ÖÅä¡£\n");
	write("ÄãÊÇ·ñÏë¼ÌĞø·ÖÅäÕâĞ©Ê£ÓàµãÊı£¿[y/n]");
	input_to("continue_finish",me);    
	get_start(me);
	return;
    } else if(left<0) {
        write("Sth wrong, let wiz know.\n");
        return;
    }   

    gt=me->query_temp("gifts");
    if(!gt || !mapp(gt)) {
	write("Something wrong.\n");
	return;
    }
    if((int)(gt["str"]+gt["con"]+gt["int"]+gt["spi"])>90) {
	write("ÄãµÄ"+giftn["str"]+"¡¢"+
		giftn["con"]+"¡¢"+
		giftn["int"]+"¼°"+
		giftn["spi"]+"Ö®ºÍ²»ÄÜ¶àÓÚ 90 ¡£\n");
	get_start(me);
	return;
    }

/*
    if((int)(gt["cps"]+gt["per"]+gt["kar"]+gt["cor"])>80) {
	write("ÄãµÄ"+giftn["cps"]+"¡¢"+
		giftn["per"]+"¡¢"+
		giftn["kar"]+"¼°"+
		giftn["cor"]+"Ö®ºÍ²»ÄÜ¶àÓÚ 80 ¡£\n");
	get_start(me);
	return;
    }
  */  
    
    ok=0;
    while(!ok) {
	gt["cps"]=10+random(21);
	if(me->query("gender")=="ÄĞĞÔ")
	  gt["per"]=10+random(21);
	else
	  gt["per"]=15+random(16);  
	gt["kar"]=10+random(21);
	gt["cor"]=80-gt["cps"]-gt["per"]-gt["kar"];
	if(gt["cor"]>=10 && gt["cor"]<=30) ok=1;
    }
    
    key=keys(giftn);
    i=sizeof(key);
    while(i--) {
	if(undefinedp(gt[key[i]])) {
	    write("Sth wrong, tell wizard.\n");
	    return;
	}
	me->set(key[i],gt[key[i]]);
    }
    me->delete("no_gift");
    me->flush_buffer(); // clear receive message buffer.
    tell_object(me,"\n\n\n[1;36mºÃ£¡×£ÄãÎ÷ÌìÈ¡¾­Ôç³ÉÕı¹û£¡[2;37;0m\n\n\n");
    tell_object(me,
	"[1;32mÖ»¼ûÑÛÇ°Ï¼¹âÒ»ÉÁ£¬ÄãÒÑ¾­À´µ½ÁËÒ»¸öÄ°ÉúµÄÊÀ½ç[2;37;0m[37m£¨[5m[1;31mLook[2;37;0m [1;33mOr [5m[1;31mHelP[2;37;0m[37m£©[2;37;0m[1;32m£®£®£®\n\n"NOR);

    if (("/adm/daemons/band"
       ->create_char_banned(query_ip_number(me)) == 1 ||
       "/adm/daemons/band"->is_banned(query_ip_number(me)) == 1) 
	    && !wizardp(me)) {
	    me->move("/d/wiz/guest");
	    log_file( "ALLCONT", sprintf("from banned site\n"));
	    return;
    } 
    env=load_object(start_room);
    tell_object(env,({"\n¶ä¶äÏéÔÆºöÈ»Ó¿ÏÖÔÚÌì¼Ê¡£\n\n",
		"\nÌì±ßÒ»¿ÅÁ÷ĞÇÙ¿µØ»®¹ı£®£®£®\n\n",
		"ºöÌıÔ¶´¦¾ªÌì¶¯µØÒ»Éù¾ŞÏì£¬Ëæ¼´Ò»µÀ½ğ¹âÉÁ¹ı£®£®£®\n"})
	    [random(3)]);
    me->move(env,1);
    me->save();
    return;
}
    
void continue_finish(string arg, object me)
{
    if(!me) return;
    if(!arg) {
	write("ÄãÊÇ·ñÏë¼ÌĞø·ÖÅäÕâĞ©Ê£ÓàµãÊı£¿[y/n]");
	input_to("continue_finish",me);    
	return;
    }
    if(arg[0..0]=="y" || arg[0..0]=="Y") {
	get_start(me);
	return;
    }
    if(arg[0..0]=="n" || arg[0..0]=="N") {
	me->set_temp("gift_left",0);
	do_finish(me);
	return;
    }
	write("ÄãÊÇ·ñÏë¼ÌĞø·ÖÅäÕâĞ©Ê£ÓàµãÊı£¿[y/n]");
	input_to("continue_finish",me);    
    return;
}
void get_number(string arg, object me, int ind)
{
    mapping gt;
    int value, old_value;
    string name;
    
    if(!me) return;
    if(!arg || sscanf(arg,"%d",value)!=1) {
	write("ÇëÊäÈë"+giftn[index[ind]]+"µÄĞÂÈ¡Öµ[10-30]£º");
	input_to("get_number",me,ind);
	return;
    }
    if(value<10 || value>30) {
	write("ÊıÖµÓ¦½éÓÚ 10 ºÍ 30 Ö®¼ä¡£\n");
	write("ÇëÊäÈë"+giftn[index[ind]]+"µÄĞÂÈ¡Öµ[10-30]£º");
	input_to("get_number",me,ind);
	return;
    }
   
    gt=me->query_temp("gifts");
    if(!gt || !mapp(gt)) {
	write("Something wrong.\n");
	return;
    }
    
    name=index[ind];
    old_value=gt[name];
    gt[name]=value;
    
    if((int)(gt["str"]+gt["con"]+gt["int"]+gt["spi"])>90) {
	gt[name]=old_value;
	write("ÄãµÄ"+giftn["str"]+"¡¢"+
		giftn["con"]+"¡¢"+
		giftn["int"]+"¼°"+
		giftn["spi"]+"Ö®ºÍ²»ÄÜ¶àÓÚ 90 ¡£\n");
	write("ÇëÊäÈë"+giftn[index[ind]]+"µÄĞÂÈ¡Öµ[10-30]£º");
	input_to("get_number",me,ind);
	return;
    }
/*
    if((int)(gt["cps"]+gt["per"]+gt["kar"]+gt["cor"])>80) {
	gt[name]=old_value;
	write("ÄãµÄ"+giftn["cps"]+"¡¢"+
		giftn["per"]+"¡¢"+
		giftn["kar"]+"¼°"+
		giftn["cor"]+"Ö®ºÍ²»ÄÜ¶àÓÚ 80 ¡£\n");
	write("ÇëÊäÈë"+giftn[index[ind]]+"µÄĞÂÈ¡Öµ[10-30]£º");
	input_to("get_number",me,ind);
	return;
    }
*/    
    me->add_temp("gift_left",old_value-value);
    me->set_temp("gifts",gt);
    write("Äã½«"+giftn[name]+"ÉèÎª"+chinese_number(value)+"¡£\n");

    get_start(me);
}


int do_block(string arg)
{
    object me=this_player();
    string verb=query_verb();

    if(!userp(me) || wizardp(me)) return 0;
    if(verb=="look" ||
       verb=="help" ||
       verb=="story" ||
       verb=="say") return 0;
       
    return 1;
}


