// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
// By tianlin 2001.5.1
inherit F_CLEAN_UP;
#include <obstacle.h>
int telling (object me, object who);
int telling2 (object who);
string name;
int killtime(object me);
int main(object me, string arg)
{
        object ob;
        if( !arg ) {
                ob = me;
                name = ob->short(1);
        } else if (wizardp (me)) {
                ob = find_player(arg);
                if(!ob) ob = find_living(arg);
                if(!ob) ob = LOGIN_D->find_body(arg);
                if(!ob || !me->visible(ob)) return notify_fail("Ã»ÓĞÕâ¸öÈË¡£\n");
                name = ob->short(1);
        } else
           return 0;
        telling(me, ob);
        return 1;
}
int help()
{
        write(@TEXT
Ö¸Áî¸ñÊ½£ºscore2 <Ä³ÈË>

ÏÔÊ¾Ä³ÈËÆäËû×ÊÁÏ¡£ 
	±ÈÈç£º²é¿´³ıÄ§ÈÎÎñ

Ïà¹Ø°ïÖú£ºhelp wudang µÈ
TEXT
        );
        return 1;
}

int telling (object me, object who)
{
  write (name+"        [1;32m¸ö ÈË µµ °¸[2;37;0m\n");//this is by tianlin
  write ("¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô\n");
if(who->query("HellZhenPass")){
	write ("ÒÑ¾­ÏÂ¹ıÊ®°Ë²ãµØÓüÁË¡£\n");
	write ("©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤\n");
}
       
   telling2(who);
if(who->query("death")){
	write ("ÉÏ´ÎËÀÍöËğÊ§"+who->query("death/combat_exp_loss")+"ÎäÑ§¡£\n");
	write ("ÉÏ´ÎËÀÍöËğÊ§"+COMBAT_D->chinese_daoxing(who->query("death/dx_loss"))+"µÀĞĞ¡£\n");
	write ("ÉÏ´ÎËÀÍöËğÊ§"+who->query("death/skill_loss")+"¼¶¼¼ÄÜ¡£\n");
	write ("ÉÏ´ÎÊÇ±»"+who->query("kill/killer_name")+"("+who->query("kill/killer_id")+")¸øÉ±º¦ÁË¡£É±º¦Ê±¼ä"+who->query("kill/killer_date")+"\n");
	write ("©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤\n");
}
if(who->query("child")){
	write ("ÓĞ"+who->query("child")+"¸öº¢×Ó¡£\n");
	write ("©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤\n");
}
  write ("Ò»¹²³ÔÁË"+who->query("liwu/eat")+"¸öÀñÎï¡£\n");
  write ("Ò»¹²³ÔÁË"+who->query("rsg_eaten")+"¸öÈË²Î¹û¡£\n");
  write ("×î½üÓÖ³ÔÁË"+who->query("eat_biou")+"¸ö±ÌÅº¡£\n");
  write ("×î½üÓÖ³ÔÁË"+who->query("eat_jiaoli")+"¸ö½»Àæ¡£\n");
  write ("×î½üÓÖ³ÔÁË"+who->query("eat_huozao")+"¸ö»ğÔæ¡£\n");
  write ("©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤\n");
  write ("Ò»¹²½µ·üÁË"+who->query("killme/number")+"¸öÑı¡£\n");
  write ("×î½üÀÛ¼Æ½µ·üÁË"+who->query("killme_number")+"¸öÑı¡£\n");
	if(who->query_temp("ask_njiang")=="do"){
		write ("Õı×¼±¸·ÅÆú¸ÕÁìµÄÈÎÎñ£¬µ«»¹Ã»ÓĞÕ÷µÃÍ¬Òâ¡£\n");
	}else{
	if(who->query_temp("killme_applied")=="do"){
		write ("ÏÖÔÚÒÑ¾­ÁìÁËÈÎÎñ£¬Ó¦¸Ã½µÑı³ıÄ§È¥ÁË¡£\n");
		killtime(who);
	}else{
	if(who->query_temp("killme_applied")=="done"){
		write (" ¸ÕÉ±ÁËÑı¹Ö£¬ÕıµÈ×Å½±ÀøÄØ¡£\n");
	}else{
	if(who->query_temp("ask_jiang")=="do"){
		write ("¸Õ´òÌı¹ıÎåÀ×Éñ½«µÄÏûÏ¢£¬µ«»¹Ã»µÃµ½´ğ¸´¡£\n");
	}else{
	if(who->query_temp("ask_jiang")=="ok"){
		write ("ÒÑ¾­´òÌıµ½ÎåÀ×Éñ½«µÄÏûÏ¢ÁË£¬Õı×¼±¸È¥ÕÒ¡£\n");
	}else{
		write ("ÏÖÔÚÃ»ÓĞÁì³ıÄ§ÈÎÎñ¡£\n");
	}
	}
	}
	}
	}
  write ("¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô\n");
}

int telling2 (object who)
{
  int size = sizeof(obstacles);
  string *names = keys(obstacles);
  string *strs = allocate (size);
  int nb = 0;
  int i;

  for (i = 0; i < size; i++)
  {
    strs[i] = "none";
  }

  for (i = 0; i < size; i++)
  {
    if (who->query("obstacle/"+names[i])!="done")
    {
      strs[nb] = obstacles[names[i]];
      nb++;
    }
  }

  if (nb == 0)
  {
	write ("»¹Ê£"+(3-who->query("obstacle/rebirth"))+"¸ù¾ÈÃüºÁÃ«¡£\n");
	write ("©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤\n");
  }
}
int killtime(object me)
{
	int sec,min,age,time1,time2;
	string out_str;
	object old=find_living(me->query("id")+" yao");
	time2=time();
	time1 = (int)me->query_temp("killme/time1");
	age = 1800 - (time2 - time1);
	if(age>0){
	sec = age % 60;age /= 60;
	min = age % 60;age /= 60;
	out_str = (min? chinese_number(min)+"·ÖÖÓ":"")
	+ (sec? chinese_number(sec)+"Ãë":"");
		if(old){
			write("±ØĞëÔÚ" + out_str + "Ö®ÄÚ³ıµôËü¡£\n");
		}else{
			write("ÒÑ¾­ÕÒ²»µ½ÄãÒª³ıµÄÑıÄ§ÁË£¬»¹ÊÇÖØĞÂÁìÈÎÎñÈ¥°É¡£\n");
		}
	}else{
		write("ÈÎÎñÒÑ¾­³¬Ê±ÁË£¬»¹ÊÇÖØĞÂÁìÈÎÎñÈ¥°É¡£\n");
	}
	return 1;
}
