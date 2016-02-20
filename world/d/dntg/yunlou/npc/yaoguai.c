//By tianlin@mhxy for 2001/5/1

inherit NPC;

#include <ansi.h>
#include "/d/dntg/yunlou/npc/yaoguai_reward.c";

string _invocation(object who, int level);
int exp_reward, pot_reward;
int other_kee=0, other_sen=0;
int announced=0;

string *death_msg= ({
"$NºÈµÀ£ºÄõÐó£¬ÓëÎÒ»ØÌìÉÏÁì×ïÈ¥°É£¡\n$nÑÛ¼ûÎÞÄÎ£¬Ö»ºÃ»¯³É¹ÉÇàÑÌ¸½µ½ÁË$NµÄÊÖÖÐ¡£\n\n",
"$nÒ»¿´²»ÊÇ$NµÄ¶ÔÊÖ£¬Ö»µÃ¾ÍµØÒ»¹ö£¬±ä»ØÔ­ÐÎ£¬´òÁË¼¸¸ö×ª£¬ÀÏÀÏÊµÊµµØ×ß¿ªÁË¡£\n\n",
"$n´ó½ÐÒ»Éù¡°ÎÒ·þÁË£¬ÎÒ·þÁË£¬ÎÒÍ¶½µ¡£¡£¡±¹Ô¹ÔµØ·üÔÚ$N½ÅÏÂ²»¶¯ÁË¡£\n$NÊÖÒ»»Ó£¬$nÈçÃÉ´óÉâ£¬Ñ±·þµØ×ß¿ªÁË¡£\n\n",
"$NºÈµÀ£ºÄõÐó£¬ÓëÎÒ»ØÌìÉÏÁì×ïÈ¥°É£¡\n$nÎÞ¿ÉÄÎºÎ£¬»¯×öÒ»µÀÇà¹â£¬Ö±³åÔÆÏöÈ¥ÁË£®£®£®\n\n",
});
string *dirs1 = ({
"/d/city",
"/d/jjf",
"/d/westway",
"/d/kaifeng",
"/d/lingtai",
"/d/moon",
"/d/gao",
//"/d/dntg/hgs", 
"/d/sea", 
"/d/nanhai", 
"/d/eastway",
"/d/ourhome/honglou", 
});

string *dirs2 = ({
"/d/shushan",
"/d/pansi",
"/d/xueshan",
"/d/qujing/wuzhuang", 
"/d/qujing/baotou", 
"/d/qujing/baoxiang", 
"/d/qujing/bibotan",
"/d/qujing/biqiu",
"/d/qujing/chechi",
"/d/qujing/dudi",
"/d/qujing/fengxian",
"/d/qujing/firemount",
"/d/qujing/jilei",
"/d/qujing/jindou",
"/d/qujing/jingjiling",
"/d/qujing/jinping",
"/d/qujing/jisaiguo",
"/d/qujing/maoying",
"/d/qujing/nuerguo",
"/d/qujing/pingding",
"/d/qujing/pansi",
"/d/qujing/tongtian",
"/d/qujing/qilin",
"/d/qujing/qinfa",
"/d/qujing/qinglong",
"/d/qujing/tianzhu",
"/d/qujing/wudidong",
"/d/qujing/wuji",
"/d/qujing/xiaoxitian",
"/d/qujing/yinwu",
"/d/qujing/yuhua",
"/d/qujing/zhujie",
"/d/qujing/zhuzi",
"/d/penglai",
});

string *dirs3 = ({
"/d/death",  
"/d/meishan",
"/d/qujing/lingshan",
"/d/dntg/sky",
});

string *names1 = ({
  "Ì¡","ta",
  "Â¹","lu",
  "âµ","huan",
  "¹·","gou",
  "Öí","zhu",
  "ºï","hou",
  "áô","fei",
  "òþ","mang",
});

string *names2 = ({
  "Í·","tou",
  "Î²","wei",
  "½Å","jiao",
  "×¦","zhua",
  "×ì","zui",
  "ÑÀ","ya",
});

string *names3 = ({
  "»¢","hu",
  "Ê¨","shi",
  "±ª","bao",
  "ÐÜ","xiong",
  "î¼","pi",
  "ÀÇ","lang",
  "±·","bei",
  "²ò","chai",
});

string *names4 = ({
	"ºüÀê","huli",
	"ºÚÐÜ","heixiong",
	"¹·ÐÜ","gouxiong",
	"°×ÐÜ","baixiong",
	"Ð«×Ó","xiezi",
	"ó¸òÜ","chanchu",
	"òÚò¼","wugong",
	"ÍÁ±î","tubie",
	"·É»È","feihuang",
	"»È³æ","huangchong",
	"´óÇà³æ","daqingchong",
	"³ô³æ","chouchong",
	"ÌøÔé","tiaozao",
	"Ê­×Ó","shizi",
	"ÀÏ»¢","laohu",
	"Ê¨×Ó","shizi",
	"»ÆÊ¨","huangshi",
	"ºÚÊ¨","heishi",
	"°×Ê¨","baishi",
	"Ò°ÍÃ","yetu",
	"»¨±ª","huabao",
	"É½±ª","shanbao",
	"²Ý±ª","caobao",
	"É½Ñò","shanyang",
	"Âíºï","mahou",
	"â¨ºï","mihou",
	"Ô³ºï","yuanhou",
	"»ÒÀÇ","huilang",
	"Ò°Öí","yezhu",
	"Ö©Öë","zhizhu",
	"ÂíÂ¹","malu",
	"°×Â¹","bailu",
	"»ÒÂ¹","huilu",
	"ºÚÂ¹","heilu",
	"É½¼¦","shanji",
	"Ò°¼¦","yeji",
	"ïô¼¦","zhiji",
	"´Ìâ¬","ciwei",
	"»¨ºüÀê","huahuli",
	"°×ºüÀê","baihuli",
	"»ÒºüÀê","huihuli",
	"ÐÉÐÉ","xingxing",
	"áôáô","feifei",
	"°×Âí","baima",
	"ºìÂí","hongma",
	"ºÚÂí","heima",
	"°×Ã¨","baimao",
	"»¨Ã¨","huamao",
	"ºÚÃ¨","heimao",
	"Ò°Ã¨","yemao",
	"Ò°Âí","yema",
	"Ò°Â¿","yelu",
	"°×ÍÃ","baitu",
	"»ÒÍÃ","huitu",
	"Ë®Å£","shuiniu",
	"êóÅ£","maoniu",
	"Ò°Å£","yeniu",
	"°×Êó","baishu",
	"»ÒÊó","huishu",
	"ºÚÂìÒÏ","heimayi",
	"ÂìÒÏ","mayi",
	"°×ÒÏ","baiyi",
	"É½ÀÏÊó","shanlaoshu",
	"»¨Éß","huashe",
	"ÇàÉß","qingshe",
	"°×Éß","baishe",
	"»Ò°ßÉß","huibanshe",
	"¾Þòþ","jumang",
	"Ë®Éß","shuishe",
	"º£Àê","haili",
	"ºÓÀê","heli",
});

int yaoguai_type=0;

int random_place(object me, string* dirs);
void _leave();
void leave();
void leave2();

void setname1()
{
        int i,j,k;
	string name, *id;

	i=(random(sizeof(names1)/2))*2;
	j=(random(sizeof(names2)/2))*2;
	k=(random(sizeof(names3)/2))*2;

	name=names1[i]+names2[j]+names3[k];
	id=({names1[i+1]+names2[j+1]+" "+
	    names3[k+1], names3[k+1]});

	set_name(name,id);

	set("race", "Ò°ÊÞ");
	if (random(2) > 0 ) {
	  set("gender", "ÐÛÐÔ");
	} else {
	  set("gender", "´ÆÐÔ");
	}
	yaoguai_type=1;
}

void setname2()
{
    int i, j;
    string name, *id;
    i=(random(sizeof(names4)/2))*2;
    j=random(2);
    
    name=names4[i]+(j?"¾«":"¹Ö");
    id=({names4[i+1]+" "+(j?"jing":"guai"),
	    (j?"jing":"guai")});

    set("race", "Ò°ÊÞ");
    set("gender",(j?"´ÆÐÔ":"ÐÛÐÔ"));
    set_name(name,id);
    yaoguai_type=2;
}

int cast_chance(int level) 
{
    return 5+level/2;
}

void create()
{
        if(random(2)==0)
	    setname1();
	else
	    setname2();

	set("chat_chance", 5);
	set("chat_msg", ({
	     (: random_move :)
	}) );

	set("chat_chance_combat", 5);

	set("age", 20+random(80));
	set("class", "yao");
	set("combat_exp", 3000);
	set("attitude", "heroism");
	set_skill("unarmed", 10);
	set_skill("jinghun-zhang", 10);
	map_skill("unarmed", "jinghun-zhang");
	set_skill("dodge", 10);
	set_skill("ghost-steps", 10);
	map_skill("dodge", "ghost-steps");
	set_temp("apply/armor", 25);
	
	set("limbs", ({
	       "Í·²¿", "¾±²¿", "ÐØ¿Ú", "ºóÐÄ", "×ó¼ç", "ÓÒ¼ç", "×ó±Û",
	       "ÓÒ±Û", "×ó×¦", "ÓÒ×¦", "Ñü¼ä", "Ð¡¸¹", "Ç°ÍÈ", "ºóÍÈ",
	       "Ç°×¦", "ºó×¦" }) );

        setup();
}

// here should be this NPC specific skills.
void set_skills(int j, int level)
{
        object me=this_object();
	object weapon;

	me->set_skill("unarmed", j);
	me->set_skill("dodge", j);
	me->set_skill("parry", j);
	me->set_skill("force", j);
	me->set_skill("spells", j);
 
	me->set_skill("staff", j+random(15));
	me->set_skill("lunhui-zhang", j+random(15));
	me->set_skill("lotusmove", j+random(15));
	me->set_skill("buddhism", j+random(15));
	me->set_skill("jienan-zhi", j+random(15));
	me->set_skill("lotusforce", j+random(15));
	me->map_skill("force", "lotusforce");
	me->map_skill("staff", "lunhui-zhang");
        me->map_skill("parry", "lunhui-zhang");
	me->map_skill("spells", "buddhism");
	me->map_skill("dodge", "lotusmove");
	me->map_skill("unarmed", "jienan-zhi");

//	set("chat_chance_combat", 10+2*level);
	set("chat_msg_combat", ({
	(: cast_spell, "bighammer" :),
	}) );

	weapon=new("/d/obj/weapon/staff/budd_staff");
	weapon->move(me);
	carry_object("/d/obj/cloth/shoupiqun")->wear();
	command("wield all");
}

void copy_status(object me,object ob, int lv)
{
        int j, lvl,k,m;
        object qm=new("/d/changan/npc/qianmian.c");
	int base=20;

	lvl=lv+base-2;

        if(qm) {
            mapping skill=ob->query_skills();
            int i=sizeof(skill);
            int *level, max_level;
	    int max_sen, max_kee;

	    if(i>0) {
		level=values(skill);
		max_level=level[0];
		while(i--) { // find out victim's maximum level
		    if(level[i]>max_level)
			max_level=level[i];
		}
	        max_level=max_level*lvl/base;

	    } else max_level=1;

	    qm->copy_status(this_object(), ob, lvl);
            destruct(qm);

	    k=(query("daoxing")+query("combat_exp"))/2;
	    for(m=1;m<300;m=m+10) {
		if(m*m*m/10>k) break;
	    }
	    m=m*lvl/base/3;
	    if(max_level<m) max_level=m;

	    // skill level will be set to the maximum level
	    // of the player.
	    set_skills(max_level, lv);
	    
	    max_sen=query("max_sen")/2;
	    max_kee=query("max_kee")/2;
	    add("eff_sen",max_sen);
	    add("eff_kee",max_kee);
	    add("sen",max_sen);
	    add("kee",max_kee);
	    add("max_sen",max_sen);
	    add("max_kee",max_kee);

	} else { // sth goes wrong.
	    leave();
	    return;
	}

	if((query("daoxing")+query("combat_exp"))/2
		>1000000)
	  add("force",query("force")); // double force.
	                               // because players have fabao.
	                             // mana is doubled when copying.
        set("force_factor", query_skill("force")/2);
        set("mana_factor", query("max_mana")/30+1);
	
	set("daoxing",(query("daoxing")*2+query("combat_exp"))/3);
}

int random_place(object me, string* dirs)
{
        int  i, j, k;
        object  newob;
        mixed*  file, exit;

        if( !sizeof(dirs) )  return 1;

        i = random(sizeof(dirs));    // pick up one directory

        file = get_dir( dirs[i]+"/*.c", -1 );
        if( !sizeof(file) )             return 1;

	for(k=0;k<30;k++) { // try 20 times
           j = random(sizeof(file));
           if( file[j][1] > 0 ) {
             newob=load_object(dirs[i]+"/"+file[j][0]);
             if (newob) {  
               if(newob->query("no_fight") ||
		       newob->query("no_magic") ||
		       newob->query("no_mieyao") ||
		       !(exit=newob->query("exits")) ||
		       sizeof(exit)<1)
		   continue;

               if(me->move(newob)) {
		   message_vision("$N×ßÁË¹ýÀ´¡£\n",me);
		   return 1;
	       }
	     }
	   }
	}

        return 0;
}

void _leave()
{
    object me=this_object();
    
    // if in fighting, then don't disappear.
    if(me->is_fighting() || me->is_busy())
	return;
    leave();
}

void leave()
{
      if(this_object()) { 
        if(environment())
          message("vision",HIB + name() + 
		  "Éí×ÓÒ»»Î£¬±ä³ÉÒ»¹ÉÇàÑÌÉ¢È¥ÁË¡£\n" NOR,environment());
	this_object()->move("/obj/empty");
	call_out("leave2",5);
      }
      return;
}

void leave2()
{
    if(this_object()) {
	destruct(this_object());
    }
}

string invocation(object who, int level)
{
        object me=this_object();

        copy_status(me,who, level-2);
	
	return _invocation(who, level);
}

string _invocation(object who, int level)
{       object me=this_object(), env;
        string *dirs; 
        int exp, i, lvl;
	string where, long;
	
	dirs=dirs1;

        set("owner", who->query("id"));
        set("owner_ob", who);

	if(yaoguai_type==1) {
        long="Ò»Í·"+name()+"£¬ÐÞÁ·ÁËÓÐ"+
	  chinese_number((query("daoxing")/1000/10)*10)+
	  "¶àÄêµÀÐÐ¡£Ëü";
        if(random(2)==0) {
	  set("long",long+"Í¨ÌåÍ¸³öÒ»Ë¿ÏÉÆø¡£\n");
        } else {
	  set("long",long+"»ìÉíÉÏÏÂÑýÆø±ÆÈË¡£\n");
        }
	} else if(yaoguai_type==2) {
	    int dx=query("daoxing");
	    long="Ò»Ö»"+query("name")[0..<3]+
		"£¬ÔÚ"+({"ÉîÉ½ÖÐ","ÃÜÁÖÖÐ","Ò°Íâ",
			"²ÝÔ­ÉÏ","Ò°ÁÖÖÐ","¸ßÉ½ÖÐ",
			"Ã§ÁÖÖÐ","Ã§Ô­ÉÏ","Éî¹ÈÖÐ",
			})[random(9)]+
	        "¼³È¡"+({"ÈÕÔÂ","ÌìµØ","ÍòÎï"})[random(3)]+
		    "¾«»ª£¬ÆÄÓÐÁËÐ©µÀÐÐ¡£\n";
            set("long",long);
	    
	    if(dx>=10000000)
		long=HBRED HIY" Íò Äê "NOR;
	    else if(dx>=1000000)
		long=HBRED HIW" Ç§ Äê "NOR;
	    else if(dx>=100000)
		long=HBBLU HIY" °Ù Äê "NOR;
	    else if(dx>10000)
		long=HBBLU HIW"Ê®Äê"NOR;
	    else
		long=HBBLU HIR"Ð¡Ð¡"NOR;
	    
        set("title",long);
//  if (!random(3)) set("title","Ã×¹ú¹í×Ó")
	}

	lvl=level;
	
	// choose npc type.
	i=random(1000);
	if(i<10) {
	    set("type","aggressive");
	} else if(i<20) {
	    set("type","blocker");
	} else if(i<220) {
	    set("type","aggressive_on_owner");
	} else if(i<320) {
	    set("type","aggressive_on_owner1");
	} else 
	    set("type","normal");
	
	if(random(10)==0) {
	    set("env/wimpy",40);
	    if(lvl<9) lvl=lvl+1; // as more difficult to kill.
	} else {
	    set("env/wimpy",1);
	}

	// determine reward
	exp=(who->query("combat_exp")+
		who->query("daoxing"))/2;
	if(exp<30000) {
	    exp_reward=500+exp/60;
	    pot_reward=200+exp/300;
	} else if(exp<300000) {
	    exp_reward=1000+exp/600;
	    pot_reward=300+exp/6000;
	    dirs=dirs+dirs2;
	} else if(exp<3000000) {
	    exp_reward=1500+exp/6000;
	    pot_reward=350+exp/20000;
	    dirs=dirs+dirs2;
	} else {
	    exp_reward=2000;
	    pot_reward=500;
	    dirs=dirs+dirs2+dirs3;
	}

	pot_reward=pot_reward*(lvl+1)/10;
	exp_reward=exp_reward*(lvl+1)/10;

	me->set("stay_time", time()+1800);

	if(!random_place(me, dirs)) {
	    leave();
	    return 0;
	}
	
	env=environment(me);
	where=me->query("name")+"("+
	    capitalize(me->query("id"))+")";
	if(env)
	  where+="ÔÚ"+MISC_D->find_place(env);
	return where;
}

int accept_object (object who, object ob)
{
  object me;
  me = this_object();

  if ((! ob) ||
       ob->value() < 100000)
  {
    message_vision ("$NÒ»µÉÑÛ£º¾ÍÕâµã¶«Î÷£¿²»Ïë»îÁË£¿£¿£¿\n", me);
    return 1;
  }
  who->set_temp("mieyao/allow_to_go", 1);
  message_vision ("$NºÙºÙºÙ¼¸Éù¹ÖÐ¦£ºËãÄã×ßÔË£¬¿ì¹ö£¡"
	  +"¿É±ðÈÃÎÒÔÙ¿´¼ûÄã£¡\n",me);
  return 1;
}

void check_room()
{
    object me=this_object();
    object env=environment(me);
    
    if(!living(me)) return;
    if(env && (env->query("no_fight") ||
		env->query("no_magic"))) {
	random_move();
    }
}

void init()
{
    object me=this_object();
    object who=this_player();
    string type;
    int t=query("stay_time");

    ::init();
    
    // if overtime too long, then destroy. mon 7/14/99
    if(t && time()>(t+3600)) {
	remove_call_out("leave");
	call_out("leave",1);
	return;
    }

    if(t && time()>t) {
	remove_call_out("_leave");
	call_out("_leave",30);
    }
    
    if(!userp(this_player())) return;
    if(!living(this_object())) return;
    
    type=query("type");
    switch (type) {
	case "aggressive": {
	    object leader=query_leader();
	    int exp, myexp;
	    if(leader && present(leader, environment(me))) {
		if(!is_fighting()) kill_ob(leader);
		break;
	    }
	    exp=(who->query("combat_exp")+
		    who->query("daoxing"))/2;
	    myexp=(query("combat_exp")+
		    query("daoxing"))/2;
	    if(exp>myexp*3 || exp<myexp)
		break;

	    set_leader(who);
	    message_vision("$N¶¢×Å$n£¬²öµÃÖ±Á÷¿ÚË®£ººÙºÙ£®£®£®\n",
		    this_object(), who);
	    kill_ob(who);
	    break;
	}
	case "aggressive_on_owner1":
	    if(query("owner")==this_player()->
		    query("id")) {
		if(!announced) {
		  message_vision("$N¿´¼û$n£¬´ó½ÐÒ»Éù£º¹þ¹þ£¬ËÍÉÏÃÅÀ´µÄÈâ£¡\n",
			this_object(), who);
		  announced=1;
		}
		kill_ob(this_player());
		if(random(4)>0)
		    set_leader(who);
		else
		    set_leader(0);
		this_player()->kill_ob(this_object());
	    }
	    break;
	case "aggressive_on_owner":
	    if(query("owner")==this_player()->
		    query("id")) {
		if(!announced) {
		  message_vision("$N¿´¼û$n£¬´ó½ÐÒ»Éù£º¹þ¹þ£¬ËÍÉÏÃÅÀ´µÄÈâ£¡\n",
			this_object(), who);
		  announced=1;
		}
		kill_ob(this_player());
		this_player()->kill_ob(this_object());
	    }
	    break;
	case "blocker": {
	    add_action("do_block","",1);
	    break;
	}
    }
    remove_call_out("check_room");
    call_out("check_room",2);
}

int do_block(string arg)
{	
    object me=this_object();
    object who=this_player();
    string verb=query_verb();
    int t;
    
    if(wizardp(who) && !visible(who)) return 0;
    if(me->is_fighting()) return 0;

    if(verb!="go" &&
	    verb!="fly" &&
	    !(environment() && environment()->query("exits/" + verb)))
	return 0;

    if(who->query_temp("mieyao/allow_to_go")) {
	who->delete_temp("mieyao/allow_to_go");
	who->delete_temp("mieyao/leave_time");
	return 0;
    }
    t=who->query_temp("mieyao/leave_time");
    if(t>0 && time()>t) {
	who->delete_temp("mieyao/leave_time");
	message_vision("$n³Ë$NÒ»¸ö²»×¢Òâ£¬¼±Ã¦ÁïÁË¹ýÈ¥¡£\n",me,who);
	return 0;
    }
    if(t==0) {
        t=time()+30+random(90);
        who->set_temp("mieyao/leave_time",t);
	message_vision("$NÃÍµØÌø¹ýÀ´À¹ÔÚ$nÃæÇ°£¬¸ßÉù½ÐµÀ£º\n"+
		"          [1;32m´ËÉ½ÊÇÎÒ¿ª£¬´ËÊ÷ÊÇÎÒÔÔ£¡[2;37;0m\n"+
		"          [33mÒª´ò´ËÂ·¹ý£¬ÁôÏÂÂòÂ·²Æ£¡[2;37;0m\n\n",me,who);
    } 
    
    tell_object(who,me->name()+"[31mÒ»°Ñ×¥×¡ÁËÄã£¡[2;37;0m\n");
    return 1;
}

void unconcious()
{
  if (query("kee")<0 || query("sen")<0) die();
   else ::unconcious();
}

void die()
{
    string owner;
    string skill;
    object owner_ob;
	object me=this_object();
	string str;
	string msg;
	int max_kee, max_sen, ratio, exp_r, pot_r;

        owner = query("owner");

        if( stringp(owner) && objectp(owner_ob = find_player(owner)) ) {
	    if(environment(owner_ob)==environment() && living(owner_ob)) {
         message_vision(death_msg[random(sizeof(death_msg))],owner_ob,this_object());

		    max_kee=query("max_kee");
		    max_sen=query("max_sen");
		    ratio=100*(max_kee-other_kee)/max_kee;
		    if(ratio<0) ratio=0;
		    ratio=ratio*(max_sen-other_sen)/max_sen;
		    if(ratio<0) ratio=0;

		    exp_r=exp_reward*ratio/100;
		    pot_r=pot_reward*ratio/100;
	    } else {
		message_vision("$NËÀÁË¡£\n",this_object());
		exp_r=0;
		pot_r=0;
		ratio=0;
	    }
		    
            exp_r=exp_reward*ratio/100; exp_r=exp_r*2/2;
            pot_r=pot_reward*ratio/100; pot_r=pot_r*2/2; //By tianlin@mhxy for 2001.9.16»Ö¸´Ô­À´×´Ì¬

		    owner_ob->add("combat_exp",exp_r);
		    owner_ob->add("potential",pot_r);

        if (owner_ob->query_temp("mieyao/level")==9)
                {
                        int dx_r=random(4000);
                        owner_ob->add("daoxing",dx_r);
                        tell_object(owner_ob, YEL"ÄãµÃµ½ÁË"+COMBAT_D->chinese_daoxing(dx_r)
        +"µÀÐÐ!"NOR);
      
                        }
                        //added by vikee
		    
		    str="µÃµ½ÁË "+exp_r+"/"+exp_reward+" µãÎäÑ§¾­ÑéºÍ "+
			pot_r+"/"+pot_reward+" µãÇ±ÄÜÍ¨¹ýµÚ "+
			owner_ob->query_temp("mieyao/level")+" ¼¶Ñý"+
			".\n";
		if (owner_ob->query_temp("mieyao/level")==9 && ratio>50) {
          skill=give_reward(owner_ob);
         str+= "²¢ÇÒ±»½±ÀøÁËÒ»¼¶ "+to_chinese(skill)+".\n";
   		if (skill != "none"){
		msg="¾ÝËµ[1;37m"+ owner_ob->query("name")+ "[1;35mÐ­ÖúÌìÍ¥Õ¶Ñý³ýÄ§ÓÐ¹¦,Óñ»Ê´óµÛ´Í[1;33m"+ to_chinese(skill)+ "[1;35mÒ»¼¶¡£[2;37;0m\n";//by tianlin 2001.7.1
     CHANNEL_D->do_channel(me,"rumor",msg);
    }

   }

		    MONITOR_D->report_system_object_msg(owner_ob, str);

		    tell_object(owner_ob, HIY"ÄãµÃµ½ÁË"+chinese_number(exp_r)
			    +"µãÎäÑ§¾­ÑéºÍ"+chinese_number(pot_r)+
			    "µãÇ±ÄÜ£¡\n"NOR);

	            owner_ob->set("mieyao/done",1);
		    
        } else {
	    message_vision("$NËÀÁË¡£\n",this_object());
	}

	destruct(this_object());

}

varargs int receive_wound(string type, int damage, object who)
{
    string owner=query("owner");
    object inv;
    
    if(who && who->query("id")!=owner) {
       if(userp(who) || ((inv=who->query_temp("invoker")) &&
		   inv->query("id")!=owner)) {
	   // can't use other's NPC to help kill.
	 if(damage>0) {
	    switch(type) {
		case "kee": other_kee+=damage; break;
		case "sen": other_sen+=damage; break;
	    }
	 }
       }
    }
    return ::receive_wound(type, damage, who);
}

varargs int receive_damage(string type, int damage, object who)
{
    string owner=query("owner");
    object inv;
    
    if(who && who->query("id")!=owner) {
       if(userp(who) || ((inv=who->query_temp("invoker")) &&
		   inv->query("id")!=owner)) {
	   // can't use other's NPC to help kill.
	if(damage>0) {
	    switch(type) {
		case "kee": other_kee+=damage; break;
		case "sen": other_sen+=damage; break;
	    }
	}
       }
    }
    return ::receive_damage(type, damage, who);
}

// This is called in heart_beat() to perform attack action.
int attack()
{
	object opponent;

	clean_up_enemy();

	opponent = select_opponent();
	if( objectp(opponent) ) {
	        string owner=query("owner");
		
		// if the owner faints, then will not attack
		// and leave. -- mon 3/8/99
		if(opponent->query("id")==owner 
			&& userp(opponent)
			&& !living(opponent)
			&& environment()==environment(opponent)) {
		    call_out("leave",1);
		    return 0;
		}

		set_temp("last_opponent", opponent);
		COMBAT_D->fight(this_object(), opponent);
		return 1;
	} else
		return 0;
}
