//by tianlin 2001/5/1
//find.c
#include <skill.h>
#include <ansi.h>

inherit F_CLEAN_UP;

void fail(object me);
void find_result(object me, object env, string target);

mapping maps=([]);
void create() 
{ 
   string filename=__DIR__"find.map";
   string buf, *buf1;
   string dir, name;
   int size, i;

   maps=([]);

   buf=read_file(filename);
   if(!buf) return; //no data available.

   buf1=explode(buf,"\n");
   size=sizeof(buf1);
   if(!size) return;

   for(i=0;i<size;i++) {
     if(sscanf(buf1[i],"%s %s",dir,name)==2) {
       name=replace_string(name," ","");
       if(strlen(dir)>2 && strlen(name)>2) {
         maps+=([dir:name]);
       }
     }
   }
}

int main(object me, string target)
{
    	object ob, env=environment(me);
        int mana_cost;

//        if (me->is_busy() || me->is_fighting() )
//	  return notify_fail("ÄãÏÖÔÚÕıÃ¦×ÅÄØ¡£\n");

        if(env->query("no_fight") || env->query("no_magic") )
	  return notify_fail("°²È«ÇøÄÚ²»ÄÜÓÃÌìÑÛÍ¨¡£\n");

        if( !target) return notify_fail("ÄãÏëÓÃÌìÑÛÍ¨²éË­£¿\n");
	
	if((int)me->query("daoxing")<5000)
         	return notify_fail("ÄãµÄµÀĞĞ²»¹»£¬ÓÃ²»ÁËÌìÑÛÍ¨¡£\n");

        if((int)me->query("sen") < 100||
	  (int)me->query("sen")*100/(int)me->query("max_sen")<50 )
  	return notify_fail("ÄãÏÖÔÚÍ·ÔÎÄÔÕÍ£¬¿ÖÅÂÁ¬×Ô¼ºÔÚÄÄÀï¶¼²»Çå³ş£¡\n");

//	mana_cost=-(100-(int)me->query_skill("spells"))/4-40;
//	mana_cost=-100+(int)me->query_skill("spells")/10;
//      if(mana_cost > -50) mana_cost=-50;

        mana_cost=-60;

        if((int)me->query("mana")+mana_cost <= 30 )  
	  return notify_fail("ÄãµÄ·¨Á¦²»¹»£¬ÓÃ²»ÁËÌìÑÛÍ¨¡£\n");

        me->add("mana", mana_cost);
	
	message_vision(HIY
	"$NÄîÁË¸öÖä£¬¶ÔÌì´óºğ£ºÓñ»ÊÀÏ¶ù£¬°³¼±ÕĞ[1;37m¡°Ç§ÀïÑÛºÎÔÚ¡±[2;37;0m[1;33mÈçÓĞ²»´Ó£¬±Ø´òÉÏÁéÏö±¦µî£¡\n"
	NOR,me);

	call_out("find_result",2+random(3),me,env,target);
	return 1;

}

void fail(object me)
{
	tell_object(me,"Ç§ÀïÑÛ¸æËßÄã£ºÆæ¹Ö£¬ÕÒ²»µ½Õâ¸öÈË£®£®£®\n");
	return;
}

void find_result(object me, object env, string target)
{
        object ob, where, bang;
	string fail, msg, filename, filename1, answer;
	int len;

        if(!me) return;
	if(environment(me)!=env) return;

	message_vision(HIY
	"Ö»ÌıºÙºÙ¼¸Éù¼éĞ¦£¬²»Öª´ÓÄÄÀï×ê³öÀ´Ò»¸ö¼â×ìºïÈùµÄ¼Ò»ï£¬ÔÚ$N¶ú±ßµÍÉùËµÁË¼¸¾ä»°¡£\n" NOR, me);
        
	ob = find_player(target);
	if( !ob ) ob = find_living(target);

	if (!ob || (ob->query("env/invisibility") && wizardp(ob) )) 
	  return fail(me);
	where = environment(ob);
	if (!where) return fail(me);
		//here is modified by vikee
        if(present("jin gu bang", ob) ){
	  tell_object(me,
		  "[37mÇ§ÀïÑÛ¸æËßÄã£ºÈËÊÇÕÒµ½ÁË£¬µ«ÊÇËµ²»µÃ£¬²»ÄÜËµ£®£®£®\n"+
		  "ÄÇ¼Ò»ï´ø×Åºï×Ó¸øËûµÄ[2;37;0m[1;33m½ğ¹¿°ô¡£[2;37;0m\n");
          return;
        }
	//added by weiqi, need better solution later...

	answer=MISC_D->find_place(where);
	if(!answer || sizeof(answer)<2) return fail(me);

	tell_object(me,"Ç§ÀïÑÛ¸æËßÄã£º"+(string)ob->name()+
	  "("+(string)ob->query("id")+")"+
	  "ÔÚ"+answer+"¡£\n");

        message_vision("$N¡°°¡¡«¡«Çï¡«¡«¡±Ò»Éù´òÁË¸öÅçÌç£¬²»ÓÉÖåÁËÖåÃ¼¡£\n",
	  ob);
        msg="Äã¼±Ã¦ÆşÖ¸ËãÈ¥£¬";
        if(ob->query("daoxing")>me->query("daoxing")/3)
	  msg+="ËÆºõ"+me->name()+"("+me->query("id")+")"+
	       "ÕıÔÚÌ½ÌıÄãµÄĞĞ×Ù¡£\n";
        else
	  msg+="ĞÄÖĞÈ´Ö»ÊÇÒ»Æ¬Ã£È»¡£\n";
        tell_object(ob, msg);

	return;
}

int help(object me)
{
        write(@HELP
Ö¸Áî¸ñÊ½ : find <Ä³ÈË>

ÌìÑÛÍ¨£ºÓÃÀ´·¢ÏÖ±ğÈËËùÔÚµØ¡£
HELP
        );
        return 1;
}
