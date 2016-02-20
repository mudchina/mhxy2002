/* <SecCrypt CPL V3R05> */

// qianmian guai
// mon 8/7/97

inherit NPC;

int MAX_MANA=4000, SPELLS=200, DAOXING=300000;

void copy_status(object me, object ob);

void create()
{
   set_name("妖怪", ({"yao guai", "yao", "guai",}));
   if(random(2)) set("gender", "男性" );
   else set("gender","女性" );
   
   set("age", 30);
   set("long", "\n");
   set("attitude", "heroism");

   set("chat_chance", 5);
   set("chat_msg", ({
      (: random_move :),
        }));
    set("chat_chance_combat", 50);

   set("str", 40);
   set("cor", 25);
   set("cps", 25);
   set("int", 25);

   set("max_kee",50000);
   set("max_gin", 50000);
   set("max_sen", 50000);
   set("force",1000);
   set("max_force", 1000);
   set("max_mana", MAX_MANA);

   set("combat_exp", DAOXING);

   set_skill("force", 140);
   set_skill("unarmed", 140);
   set_skill("parry", 140);

    setup();
    add_money("silver",50);
}


int accept_fight(object ob)
{
   object me;

   me = this_object();

   if (is_fighting()) return 0;

   copy_status(me,ob);

   return 1;
}

void kill_ob(object ob)
{
   object me=this_object();

   command("haha");
   command("say 老虎不发威，你就当我是病猫。");
   copy_status(me,ob);
   ::kill_ob(ob);
}

void copy_status(object me, object ob)
{
  mapping hp_status, skill_status, map_status;
  string *sname, *mname;
  int i,j,skillmax;
  object weap;


        //copy new skills.
   if (skill_status = ob->query_skills() ) {
      sname  = keys(skill_status);
      skillmax = skill_status[sname[0]];
      for(i=1; i<sizeof(skill_status); i++) {
      if(skill_status[sname[i]]>skillmax)
       skillmax=skill_status[sname[i]];
      }
   }

 switch(random(6)){
        case 0:
            set("chat_msg_combat", ({
                 (: perform_action, "stick.qiankun" :),
                 (: perform_action, "stick.pili" :),
                 (: cast_spell, "light" :),
                 (: cast_spell, "dingshen" :),
                 (: cast_spell, "thunder" :),
             }));
  
             me->set_skill("stick",skillmax/2+random(skillmax/2));
             me->set_skill("qianjun-bang",skillmax/2+random(skillmax/2));
             me->set_skill("spells",skillmax/2+random(skillmax/2));
             me->set_skill("dao",skillmax/2+random(skillmax/2));
             me->set_skill("dodge",skillmax/2+random(skillmax/2));
             me->set_skill("jindouyun",skillmax/2+random(skillmax/2));

             map_skill("spells", "dao");
             map_skill("stick", "qianjun-bang");
             map_skill("parry", "qianjun-bang");
             map_skill("dodge", "jindouyun");
             weap=new("/d/lingtai/obj/bang.c");
             weap->move(this_object());
             weap->wield();
             break;
         case 1:
            set("chat_msg_combat", ({
               (: perform_action, "sword.toulin" :),
            }));

           me->set_skill("sword",skillmax/2+random(skillmax/2));
           me->set_skill("birds-sword",skillmax/2+random(skillmax/2));
           me->set_skill("spells",skillmax/2+random(skillmax/2));
           me->set_skill("dodge",skillmax/2+random(skillmax/2));
           me->set_skill("xiaoyaoyou",skillmax/2+random(skillmax/2));
           me->set_skill("ningxie-force",180);  
           
           map_skill("spells", "dengxian-dafa");
           map_skill("sword", "birds-sword");
           map_skill("parry", "birds-sword");
           map_skill("dodge", "xiaoyaoyou");
           map_skill("force","ningxie-force");  
           
           weap=new("/d/obj/weapon/sword/feijian.c");
           weap->move(this_object());
           weap->wield();   
           break;
         case 2:
            set("class","xian");
            set("chat_msg_combat", ({
               (: cast_spell, "mihun" :),
               (: cast_spell, "arrow" :),
               (: perform_action, "sword.wuxue" :),
            }));
           me->set_skill("sword",skillmax/2+random(skillmax/2));
           me->set_skill("snowsword",skillmax/2+random(skillmax/2));
           me->set_skill("spells",skillmax/2+random(skillmax/2));
           me->set_skill("moonshentong",skillmax/2+random(skillmax/2));
           me->set_skill("dodge",skillmax/2+random(skillmax/2));
           me->set_skill("moondance",skillmax/2+random(skillmax/2));
           me->set_skill("moonforce",170);

           map_skill("spells", "moonshentong");
           map_skill("sword", "snowsword");
           map_skill("parry", "snowsword");
           map_skill("dodge", "moondance");
           map_skill("force","moonforce");

           weap=new("/d/obj/weapon/sword/feijian.c");
           weap->move(this_object());
           weap->wield();   
           break;
         case 3:
           set("chat_msg_combat", ({
             (: perform_action, "staff.shenlong" :),
             (: cast_spell, "bighammer" :),
           }));

           me->set_skill("staff",skillmax/2+random(skillmax/2));
           me->set_skill("lunhui-zhang",skillmax/2+random(skillmax/2));
           me->set_skill("spells",skillmax/2+random(skillmax/2));
           me->set_skill("buddhism",skillmax/2+random(skillmax/2));
           me->set_skill("dodge",skillmax/2+random(skillmax/2));
           me->set_skill("lotusmove",skillmax/2+random(skillmax/2));
           me->set_skill("lotusforce",190);
   
           map_skill("spells", "buddhism");
           map_skill("staff", "lunhui-zhang");
           map_skill("parry", "lunhui-zhang");
           map_skill("dodge", "lotusmove");
           map_skill("force","lotusforce");

           weap=new("/d/obj/weapon/staff/budd_staff.c");
           weap->move(this_object());
           weap->wield();   
           break;
         case 4:
           set("class","dragon");
           set("chat_msg_combat", ({
              (: perform_action, "hammer.break" :),
              (: cast_spell, "freez" :),
              (: cast_spell, "breathe" :),
           }));
         
           me->set_skill("hammer",skillmax/2+random(skillmax/2));
           me->set_skill("huntian-hammer",skillmax/2+random(skillmax/2));
           me->set_skill("spells",skillmax/2+random(skillmax/2));
           me->set_skill("seashentong",skillmax/2+random(skillmax/2));
           me->set_skill("dodge",skillmax/2+random(skillmax/2));
           me->set_skill("dragonstep",skillmax/2+random(skillmax/2));
        me->set_skill("dragonforce",160);
   
           map_skill("spells", "seashentong");
           map_skill("hammer", "huntian-hammer");
           map_skill("parry", "huntian-hammer");
           map_skill("dodge", "dragonstep");
        map_skill("force", "dragonforce");

           weap=new("/d/obj/weapon/hammer/bahammer.c");
           weap->move(this_object());
           weap->wield();   
           break;
         case 5: 
           set("class","youling");
           set("chat_msg_combat", ({
            (: perform_action, "whip.three" :),
            (: cast_spell, "gouhun" :),
           }));
        
          me->set_skill("whip",skillmax/2+random(skillmax/2));
          me->set_skill("hellfire-whip",skillmax/2+random(skillmax/2));
          me->set_skill("spells",skillmax/2+random(skillmax/2));
          me->set_skill("gouhunshu",skillmax/2+random(skillmax/2));
          me->set_skill("dodge",skillmax/2+random(skillmax/2));
          me->set_skill("ghost-steps",skillmax/2+random(skillmax/2));

          set_skill("tonsillit",140);
         set_skill("jinghun-zhang",150);
          set_skill("kusang-bang",140);
   
          map_skill("spells", "gouhunshu");
          map_skill("whip", "hellfire-whip");
          map_skill("parry", "hellfire-whip");
          map_skill("dodge", "ghost-steps");
          map_skill("force", "tonsillit");

          weap=new("/d/obj/weapon/whip/longsuo.c");
          weap->move(this_object());
          weap->wield();                       
          break;                     
      }       

   hp_status = ob->query_entire_dbase();

   me->set("str", hp_status["str"]);
   me->set("int", hp_status["int"]);
   me->set("con", hp_status["con"]);
   me->set("cps", hp_status["cps"]);
   me->set("cor", hp_status["cor"]);
   me->set("spi", hp_status["spi"]);
   me->set("per", hp_status["per"]);
   me->set("kar", hp_status["kar"]);

   me->set("eff_kee",    hp_status["eff_kee"]);
   me->set("kee",        hp_status["kee"]);
   me->set("eff_gin",  hp_status["eff_gin"]);
   me->set("gin",      hp_status["gin"]);
   me->set("eff_sen",  hp_status["eff_sen"]);
   me->set("sen",      hp_status["sen"]);

   me->set("max_kee",    hp_status["max_kee"]);
   me->set("max_gin",  hp_status["max_gin"]);
   me->set("max_sen",  hp_status["max_sen"]);
    set("max_force",  hp_status["max_force"]/3+random(hp_status["max_force"]/3));
    set("force",query("max_force"));
    set("max_mana",  hp_status["max_mana"]/3+random(hp_status["max_mana"]/3));
    set("mana",query("max_mana"));
    set("force_factor",skillmax/4);
    set("mana_factor",skillmax/4);
   me->set("combat_exp",hp_status["combat_exp"]);
   return ;
}

void unconcious()
{
   die();
}

void die()
{
   object killer,yao,where;
   int reward;
   string location;
int i,j = 0;
object *inv;

   tell_room(environment(),"只见"+this_object()->query("name")+"现出元神。\n");
   command("say 咱们走着瞧。");
   tell_room(environment(),"说完，元神往地下一钻，消失了。\n");

   if( objectp(killer = query_temp("last_damage_from")) ) {
      if(killer->query("nanhai/mieyao")){
          killer->delete("nanhai");
          j = 1;
}
if(killer->query("moon/mieyao")){
          killer->delete("moon");
          j = 1;
}     
if (j == 1){
          if(killer->query("combat_exp")<1000000)
              killer->add("faith",2+random(4));
          else killer->add("faith",5+random(5));
          reward=killer->query("combat_exp");
          reward=reward/4000;
          killer->add("combat_exp",reward);
          killer->add("potential",reward/4);
          tell_object(killer,"你得到"+chinese_number(reward)+"点道行。\n");
          tell_object(killer,"你得到"+chinese_number(reward/4)+"点潜能。\n");
      }
   }

inv = all_inventory(this_object());
for(i=0; i<sizeof(inv); i++)
            {
                destruct(inv[i]);
            }
   killer->remove_all_killer();
  ::die();
}
