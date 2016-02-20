//modified by vikee for xlqy
//2000-11-24 8:30
//By tianlin@mhxy for 2002.3.6È«Ãæ½µµÍeat huaµÄ½±Àø,²¢ÇÒÈ¥µômoon eat huaµÄÓÅÔ½Ìõ¼ş
#include <ansi.h>

#include <dbase.h>
#include <armor.h>

inherit NECK;
#include <flowers.h>

string chinese_daoxing(int);
void create() {
    set_name(flowers[random(sizeof(flowers))], ({ "flower"}));
  set_weight(100);
  set("unit", "¶ä");
  set("armor_prop/armor", 1);
  set("armor_prop/personality", 2);
  setup();
}

void init() {
    add_action("do_eat","eat");
}

int do_eat(string arg) {
  object me=this_player();
   int qn=0;
  int score=query("score");
  if (!arg) return 0;
//if (me->query("family/family_name")=="ÔÂ¹¬")
//score=score/2;
//added by vikee if the player belong to moon,get the double reward
  if (this_object()!=present(arg,me)) return 0;
   message_vision(HIC"$N³ÔÏÂÒ»¶ä"+query("name")+HIC"£¬Ö»¾õµÃÏãÆøÆË±Ç£¬³İ¼Õ·Ò·¼¡£\n"NOR,me);
  if (query("target")==me && score>0) {
    me->add("daoxing",score/2);
  qn=score*(20+random(10))/100;
  //as followed added by vikee, when the potential is higher than 1000,do not added.
  if (me->query("potential")-me->query("learned_points")<1000) 
  me->add("potential",qn/2);
  
  tell_object(me,HIC"ÄãµÃµ½ÁË"+chinese_daoxing(score)+"µÀĞĞ£¬"+qn+"µãÇ±ÄÜ¡£\n"NOR);
  message("system",YEL"[2;37;0m[36m¡¼[2;37;0m[33m°Ù»¨ÏÉ¹È[2;37;0m[36m¡½[2;37;0m[33m°Ù»¨ÏÉ×Ó[2;37;0m[36m(Baihua xianzi)£º[2;37;0m[33m"+me->query("name")+"[2;37;0m[36mÓë»¨ÏÉ×ÓÇĞ´èÎäÒÕ£¬µÃµ½[2;37;0m[33m"+chinese_daoxing(score)+"[2;37;0m[36mµÀĞĞºÍ[2;37;0m[33m"+chinese_number(qn)+"[2;37;0m[36mµãÇ±ÄÜ![2;37;0m\n"NOR,users());
  log_file("baihuagu",me->query("id")+" got "+score+" daoxing "+qn+" pots on "+ctime(time())+".\n");
  }
  destruct(this_object());
  return 1;
}
string chinese_daoxing(int gain) {
            int year,day,hour;
             string str;

             year=gain/1000;
             day=(gain-year*1000)/4;
             hour=(gain-year*1000-day*4)*3;
             str="";
             if(year) str=str+chinese_number(year)+"Äê";
             if(day) str=str+chinese_number(day)+"Ìì";
             if(hour) str=str+chinese_number(hour)+"Ê±³½";
             return str;
}
