// qianmian guai
// mon 8/7/97

inherit NPC;

object curr_user, new_user, curr_env;
object last_steal;
int steal_time=0, fresh=1;
int MAX_MANA=4000, SPELLS=200, DAOXING=300000;
int just_bianed=0, no_player=0, just_steal=0;
int doing_kill=0;

void copy_status(object me, object ob, int power);
string check_give(object obj);
void find_obj();
void find_newplace();
void auto_recovery();
int find_user();
object find_players();

void create()
{
	set_name("安禄山乱兵", ({ "luan bing", "bing" }) );
	set("gender", "男性" );
	set("age", 30);
	set("long", "\n");
	set("attitude", "heroism");

	set("chat_chance", 3);
        set("chat_chance_combat", 3);
	set("str", 40);
	set("cor", 25);
	set("cps", 25);
	set("int", 25);
	set("sxy", 1);

	set("max_kee", 2000);
	set("max_gin", 2000);
	set("max_sen", 2000);
	set("max_force", 2000);
	set("max_mana", MAX_MANA);
	set("mana", MAX_MANA);

	set("combat_exp", DAOXING);

	set_skill("spells",SPELLS);
	set_skill("force", 140); 
	set_skill("unarmed", 140);
	set_skill("dodge", 140);
	set_skill("parry", 140);

        setup();
        add_money("gold", 5);
	carry_object("/d/obj/weapon/blade/blade")->wield();

}

void init()
{
   object me=this_object(), tar=this_player();

   ::init();
   
   if(!environment()) return;
   if(environment()->query("no_fight")) return;

   

}



void to_kill(object tar)
{
    if(doing_kill) return;
    if(!tar || environment(tar)!=environment()) return;
    
    if(tar->query("combat_exp")>1000000)
    copy_status(this_object(), tar, 23);
    else
    copy_status(this_object(), tar, 21);
    doing_kill=1;
    
    call_out("remove_kill",120);
    message_vision("$N对$n说到：杀人偿命，欠债还钱。你这"+
	    RANK_D->query_rude(tar)+"拿命来吧！\n", this_object(), tar);
    if(tar->query("combat_exp")>20000)
	command("follow "+tar->parse_command_id_list()[0]);
    this_object()->kill_ob(tar);
    tar->kill_ob(this_object());
}








void kill_ob(object ob)
{
   object me=this_object();

   if(!doing_kill) 
       copy_status(me,ob,0);
   ::kill_ob(ob);
}

// this copy function is used by some other NPCs also,
// so if need to change here, please consider carefully.
// mon 1/13/99
void copy_status(object me, object ob, int ratio)
{
        mapping hp_status, skill_status, map_status;
        string *sname, *mname;
	int i,j, base=20;

	if(ratio<1) ratio=base;

        // delete old skills.
        if(skill_status = me->query_skills()) {
           sname  = keys(skill_status);
	   j=sizeof(skill_status);
           for(i=0; i<j; i++) {
	     me->delete_skill(sname[i]);
           }
        }

        //copy new skills.
	if (skill_status = ob->query_skills() ) {
	   sname  = keys(skill_status);
	   for(i=0; i<sizeof(skill_status); i++) {
		me->set_skill(sname[i], 
			skill_status[sname[i]]*ratio/base);
	   }
        }
	
	//delete old skill mappings.
	if(map_status = me->query_skill_map()) {
	  mname  = keys(map_status);
	  j=sizeof(map_status);
	  for(i=0; i<j; i++) {
	    me->map_skill(mname[i]);
          }
        }
         
        //add new skill mappings.
	if (map_status = ob->query_skill_map()) {
	  mname  = keys(map_status);
	  for(i=0; i<sizeof(map_status); i++) {
		me->map_skill(mname[i], map_status[mname[i]]);
	  }
        }

	hp_status = ob->query_entire_dbase();

	me->set("str", hp_status["str"]*ratio/base);
	me->set("int", hp_status["int"]);
	me->set("con", hp_status["con"]);
	me->set("cps", hp_status["cps"]);
	me->set("cor", hp_status["cor"]);
	me->set("spi", hp_status["spi"]);
	me->set("per", hp_status["per"]);
	me->set("kar", hp_status["kar"]);
 
        if(fresh==1) {
	        fresh=0;
		me->set("eff_kee",    hp_status["max_kee"]*ratio/base);
		me->set("eff_gin",  hp_status["max_gin"]*ratio/base);
		me->set("eff_sen",  hp_status["max_sen"]*ratio/base);

		me->set("max_mana",     hp_status["maximum_mana"]*ratio/base);
		me->set("mana",     hp_status["maximum_mana"]*2*ratio/base);
		me->set("kee",        hp_status["max_kee"]*ratio/base);
		me->set("gin",        hp_status["max_gin"]*ratio/base);
		me->set("sen",        hp_status["max_sen"]*ratio/base);

                me->set("eff_dx", me->query("combat_exp"));
	        if(COMBAT_D->check_family(ob->query("family/family_name"))
	           >0)
	        me->set("eff_dx", -me->query("eff_dx"));

		if(me->query("combat_exp")>10000)
		  me->set("nkgain",150); //maximum gain for killing qm.
        }
	me->set("max_kee",    hp_status["max_kee"]*ratio/base);
	me->set("max_gin",  hp_status["max_gin"]*ratio/base);
	me->set("max_sen",  hp_status["max_sen"]*ratio/base);
	me->set("max_force", hp_status["maximum_force"]*ratio/base);
	me->set("force",     hp_status["maximum_force"]*ratio/base);
	me->set("force_factor",     hp_status["force_factor"]*ratio/base);
  	if(ratio>base) {
	    me->set("max_mana",     hp_status["maximum_mana"]*ratio/base);
	    me->set("mana",     hp_status["maximum_mana"]*2*ratio/base);
	    me->set("kee",        hp_status["max_kee"]*ratio/base);
	    me->set("gin",        hp_status["max_gin"]*ratio/base);
	    me->set("sen",        hp_status["max_sen"]*ratio/base);
  	}
	me->set("mana_factor",     hp_status["mana_factor"]*ratio/base);
	me->set("combat_exp",hp_status["combat_exp"]/100*ratio/base*100+
	        hp_status["combat_exp"]/50*ratio/base);
	me->set("daoxing",hp_status["daoxing"]/100*ratio/base*100+
	        hp_status["daoxing"]/50*ratio/base);

	return ;
}

void auto_recovery()
{
        object me=this_object();

	me->set("eff_gin", (int)me->query("max_gin"));
	me->set("gin", (int)me->query("max_gin"));
	me->set("eff_kee", (int)me->query("max_kee"));
	me->set("kee", (int)me->query("max_kee"));
	me->set("eff_sen", (int)me->query("max_sen"));
	me->set("sen", (int)me->query("max_sen"));
        
        me->set("force", (int)me->query("max_force"));
        me->set("atman", (int)me->query("max_atman"));
        me->set("mana", (int)me->query("max_mana"));

        me->delete("eff_dx");
	me->delete("nkgain");

	fresh=1;
}

int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}
void leave()
{
	object owner;
	message("vision",
		 name() + "说道：鸣金收兵了，今天就先回去了吧！\n\n"
		+ name() + "把武器一拖，回头就跑不见了。\n" , environment(),
		this_object() );
	destruct(this_object());
}
