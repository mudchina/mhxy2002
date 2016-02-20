/* 妖神之争 2.0 */
// by happ 2000.9.14
//By tianlin@Mhxy for 2002.1.20,修改

#include <ansi.h>
inherit NPC;
int random_go(object me, string* dirs,int i);
mapping maps;

string *first_name = ({ "四眼","软体","变色","三脚","巨头","长牙" });
string *last_name  = ({ "生物","异形","爬行物","怪物","怪兽" });

void create()
{
  string name;
  name = first_name[random(sizeof(first_name))];
  name += last_name[random(sizeof(last_name))]+NOR;
  set_name(name, ({"guai shou","beast"}));
  set("title",HIR"来杀我"HIY"大唐"HIR"的"NOR);
  set("age", 25 + random(10) );
  set("max_kee", 500*(1+random(5)) );
  set("kee",query("max_kee"));
  set("max_sen", 500*(1+random(5)) );
  set("sen",query("max_sen"));
  set("max_force", 1500*(1+random(5)) );
  set("force_factor", 20*(1+random(5)) );
  set("force", 1800);
  set("max_mana", 1500*(1+random(5)) );
  set("mana_factor", 20*(1+random(5)) );
  set("mana", 1800);
  set("combat_exp", 200000*(1+ random(5)) );
  set("daoxing", 200000*(1+ random(5)) );
  set_skill("sword", 20*(random(10)+1));
  set_skill("westsword", 20*(random(10)+1));
  set_skill("unarmed",20*(random(10)+1));
  set_skill("parry",20*(random(10)+1));
  set_skill("dodge",20*(random(10)+1));
  set_skill("balei",20*(random(10)+1));
  set_skill("boxing",20*(random(10)+1));
  map_skill("sword", "westsword");
  map_skill("unarmed","boxing");
  map_skill("parry", "westsword");
  map_skill("dodge", "balei");  
        set("chat_chance",90);
        set("chat_msg", ({ 
                (: random_move :)
                }));

  setup();
  carry_object("/d/obj/weapon/sword/westsword")->wield();
}

void init()
{
   object ob=this_player(), me=this_object();
   ::init();
                   remove_call_out("greeting");
                   call_out("greeting",30*60);
}
void greeting()
{
        object me=this_object();
        tell_room(environment(me),"只见怪兽瞬间冲上了九天，消逝在云中！\n");

        destruct(me);
}

int random_go(object me, string* dirs,int i)
{
        int j,k,m;
        object  newob;
        mixed*  file;

        me=this_object();

        if( !sizeof(dirs) )  return 1;

        file = get_dir( dirs[i]+"*.c",-1);
        if( !sizeof(file) )             return 1;

        k = sizeof(file);

      while(1)  {
           j = random(k);
           if( file[j][1] > 0 )         break;     
                  }

     if( (newob=find_object(dirs[i]+file[j][0])) ) 
        j = random(k);

     if( (newob=find_object(dirs[i]+file[j][0])) )

          {
                me->move( newob );
          }

        else  {
                seteuid(getuid(me));
                newob = new(dirs[i]+file[j][0]);
                if (newob)   
                        me->move(newob);
        else   {
                        tell_object(me, "Error.\n");
                }
        }  
        return 1;

}

void kill_ob(object ob)
{
  set_temp("my_killer",ob);
  ::kill_ob(ob);
}

void die()
{
        object ob=this_object()->query_temp("my_killer");
        if(ob) {
        ob->add("combat_exp",500);
        ob->add("daoxing",500);
        ob->add("potential",200);
        ob->add_temp("guaishou_number",1);
        tell_object(ob,HIC"\n你杀死怪兽有功,得到唐王的赏赐"NOR);
        tell_object(ob,"\n你得到500点武学经验500点道行和200点潜能！\n");
        }
        ::die();
}


