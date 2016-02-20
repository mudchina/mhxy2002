// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// worker.c

inherit NPC;

string* cities=({"changan", "kaifeng", "putuo", "lingtai", "moon"});
string* wenhou=({"这位$R很久不见，一向可好？",
                 "这位$R不在本洞勤修练，在外面闲逛什么！",
                 "最近这位$R灭了多少妖，除了多少魔？"});
                 

void test_player();
int check_time(object me);

object offensive_target(object me)
{
   int sz;
   object *enemy;

   enemy = me->query_enemy();
   if( !enemy || !arrayp(enemy) ) return 0;

   sz = sizeof(enemy);
   if( sz > 4 ) sz = 4;

   if( sz > 0 ) return enemy[random(sz)];
   else return 0;
}


void create()
{
        set_name("慧琉", ({"hui liu"}));
        set("gender", "男性" );
        set("age", 33);
        set("long", "一个相貌堂堂的道士．");
   set("title", "道长");
   set("class", "taoist");
        set("combat_exp", 1000000);
        set("attitude", "peaceful");
        create_family("方寸山三星洞", 4, "弟子");
        set_skill("unarmed", 150);
        set_skill("puti-zhi",160);
        set_skill("dodge", 140);
        set_skill("parry", 180);
        set_skill("force", 180);   
        set_skill("wuxiangforce", 160);
        set_skill("qianjun-bang",180);
        set_skill("stick",160);
        set_skill("spells",160);
        set_skill("dao",180);
                
        map_skill("unarmed","puti-zhi");
        map_skill("stick", "qianjun-bang");
        map_skill("parry", "qianjun-bang");
        map_skill("spells", "dao");
        map_skill("force", "wuxiangforce");

        set("per", 30);
        set("max_kee", 1500);
        set("max_sen", 2000);
        set("force", 3000);
        set("max_force", 2000);
        set("force_factor", 100);
        set("max_mana",2000);
        set("mana",4000);
        set("mana_factor",100);

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "qiankun" :),
                (: perform_action, "leiting" :),
                (: cast_spell, "light" :),
                (: cast_spell, "dingshen" :),
                (: cast_spell, "thunder" :)
        }) );

        setup();
        carry_object("/d/lingtai/obj/daoguan")->wear();
        carry_object("/d/lingtai/obj/cloth")->wear();
        carry_object("/d/lingtai/obj/bang")->wield();
 
}

void init()
{
    object me=this_object();

    test_player();
    remove_call_out("check_time");
    check_time(me);
    
}

int check_time(object me)
{
   object target;
   mapping exits;
   object *inv;
   string *dirs;
   int size,i; //added by mon 8/31/97

    me=this_object();
    command("get gold");
    command("get silver");

    if(!me->is_fighting()){
    	if( query("quest/pending/ask/name")){
    		command("chat "+query("quest/pending/ask/name")+"在哪儿呀？");
    		delete("quest");
    	}
    	if( query("quest/pending/give/name")){
    		command("chat where's"+query("quest/pending/give/name"));
    		delete("quest");
    	}	
    	if(!random(3)){
    	    if(objectp(present("chen guangui",environment())))
    	        command("ask chen about ask");
            if(objectp(present("yin wenjiao",environment())))
    	        command("ask yin about give");
    	}
    	  
        if( !random(40)&& environment()->query("outdoors"))
    	   command("fly "+cities[random(sizeof(cities))]);
    	if( mapp(environment(me)->query_doors()))command("open door");
     	if( !random(3)&&mapp(exits = environment()->query("exits")) ){
            dirs = keys(exits);
            size=sizeof(dirs);
            if(size>0) command("go " + dirs[random(size)]);
        }
        else {
            inv = all_inventory(environment());
            for(i=sizeof(inv)-1;i>=0;i--){
            	if(inv[i]!=me&&inv[i]->is_fighting()){
            	   if(inv[i]->query("class")=="taoist"){
            	   	target=offensive_target(inv[i]);
            	   	if(target->query("class")!="taoist"){
            	   	   command("say 这位"+RANK_D->query_respect(inv[i])+"不必慌张，我来也！");
            	   	   command("kill "+target->query("id")); 	
            	   	   break;
            	   	}
            	   }	
            	}
            }
            if(!random(8)&&!me->is_fighting()&&!me->is_busy()){
            	for(i=sizeof(inv)-1;i>0;i--){
            		if(inv[i]->is_character()&&!inv[i]->is_corpse()&&inv[i]->query("class")!="taoist"&&inv[i]!=me&&!random(4)){
                      if(!userp(inv[i]))
       		           "/daemon/class/puti/dao/preach.c"->select_object(me,inv[i],"gold");
       		           me->start_busy(3);
                           break;
            		}
            	}
            }	
        }
     }
     call_out("check_time",4,me);
}

void test_player()
{
	object me=this_object();
	object who=this_player();
	string msg;
	
	if(who->query("class")==me->query("class")){
		command("hi "+who->query("id"));
		msg = wenhou[random(sizeof(wenhou))];
		msg = replace_string(msg , "$R", RANK_D->query_respect(who));
		command("say "+msg);
	}
}

