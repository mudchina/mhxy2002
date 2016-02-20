// literate.c

#include <ansi.h>

inherit ITEM;

void create()
{
   int i;
        set_name(HIB"《"HIY"地藏半天经"HIB"》"NOR, ({"book"}));
        set_weight(500);
        i=random(15);
   if( clonep() ) 
                set_default_object(__FILE__);
        else {
     set("long","一本看起来很神秘的小册子。\n");
                set("unit", "本");
     set("value", 0);
           set("material", "paper");
        if( i>=14)
                set("skill", ([
                        "name":"parry",  
                        "jing_cost": 20,  
                        "difficulty": 20,
                        "max_skill": 40,
                ]) );
        else if( i>=13)
               set("skill", ([
                        "name":"stick",
                        "jing_cost": 20,
                        "difficulty": 20,
                        "max_skill": 40,
                ]) );
        else if(i>=12)
                set("skill", ([
                        "name":"throwing",
                        "jing_cost": 20,
                        "difficulty": 20,
                        "max_skill": 40, 
                ]) );
         else if(i>=11)
                set("skill", ([
                        "name":"literate",
                        "jing_cost": 20,   
                        "difficulty": 20, 
                        "max_skill": 40,
                ]) ); 
         else if(i>=10)
                set("skill", ([
                        "name":"unarmed",
                        "jing_cost": 20,   
                        "difficulty": 20, 
                        "max_skill": 40,
                ]) ); 
         else if( i>=9)
               set("skill", ([
                        "name":"dodge",
                        "jing_cost": 20,
                        "difficulty": 20,
                        "max_skill": 40,
               ]) );
         else if(i>=8)
                set("skill", ([
                        "name":"blade",
                        "jing_cost": 20,
                        "difficulty": 20,
                        "max_skill": 40, 
                ]) );
        else if(i>=7)
                set("skill", ([
                   "name":"spells",
                        "jing_cost": 20,   
                        "difficulty": 20, 
                        "max_skill": 40,
                ]) ); 
        else if(i>=6)
                set("skill", ([
                        "name":"hammer",
                        "jing_cost": 20,   
                        "difficulty": 20, 
                        "max_skill": 40,
                ]) ); 
        else if(i>=5)
                set("skill", ([
                        "name":"staff",
                        "jing_cost": 20,   
                        "difficulty": 20, 
                        "max_skill": 40,
                ]) ); 
        else if(i>=4)
                set("skill", ([
                        "name":"spells",
                        "jing_cost": 20,   
                        "difficulty": 20, 
                        "max_skill": 40,
                ]) ); 
        else if(i>=3)
                set("skill", ([
                        "name":"spear",
                        "jing_cost": 20,   
                        "difficulty": 20, 
                        "max_skill": 40,
                ]) ); 
        else if(i>=2)
                set("skill", ([
                        "name":"staff",
                        "jing_cost": 20,   
                        "difficulty": 20, 
                        "max_skill": 40,
                ]) ); 
        else if(i>=1)
                set("skill", ([
                     "name":"whip",
                        "jing_cost": 20,   
                        "difficulty": 20, 
                        "max_skill": 40,
                ]) ); 
        else 
                set("skill", ([
                        "name":"sword",
                        "jing_cost": 20,   
                        "difficulty": 20, 
                        "max_skill": 40,
                ]) ); 

   }
}

void destruct_me(object where, object me)
{
  message_vision("$n化为点点纸屑，如蝶舞般随风飘去了。\n",where,me);
  destruct (me);
}

void init()
{
  object me = this_object();
  object where = environment();

  if (userp(where))
  {
    if (me->query("owned"))
    {
      if (me->query("owned")!=where->query("id"))
      {
        call_out("destruct_me",1,where,me);
      }
    }
    else
    {
      me->set("owned",where->query("id"));
    }
  }
}

