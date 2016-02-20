inherit NPC;

void create()
{
       set_name("送信小妖", ({"songxin xiaoyao", "xiaoyao"}));

        set("long","黑水河的小妖，因为脚程快，所以被鼋龙派去送信。\n");
       set("gender", "男性");
       set("age", 20);
        set("per", 10); 
        set("con",30);
        set("str", 25);
        set("combat_exp", 100000);

        set("class", "scholar");
        set("attitude","heroism");
        set("chat_chance",20);
        set("chat_msg", ({
        "小妖慌张地看了看四周，又鬼鬼祟祟地低下头去。\n", 
        "小妖伸手进怀里摸了摸，傻笑了两声。\n",
        }));

        set_skill("parry", 60);  
        set_skill("force", 40); 
        set_skill("spells", 50); 
        set_skill("seashentong", 20); 
        set_skill("dragonstep", 40); 
        set_skill("fork", 60); 
        set_skill("fengbo-cha", 40); 
        set_skill("dragonfight", 40); 
        set_skill("dodge", 60);
        set_skill("unarmed", 40); 

        map_skill("parry", "fengbo-cha");
        map_skill("fork", "fengbo-cha");
        map_skill("unarmed", "dragonfight");
        map_skill("dodge", "dragonstep"); 
        map_skill("spells", "seashentong");
        map_skill("force", "dragonforce");
        set("force", 500);
        set("max_force", 500);
        set("force_factor", 20); 
        set("mana", 600);
        set("max_mana", 600);
        set("mana_factor", 30);
        set("max_kee", 600);
        set("max_sen", 500);
        setup();
        carry_object("/d/obj/weapon/fork/gangcha")->wield();
        carry_object("/d/qujing/heishui/obj/xiazi");  
}
void kill_ob (object ob)
{
  ::kill_ob(ob);
  call_out ("flee",1,this_object());
}

void flee (object me)
{
   object room = load_object("/obj/empty.c");
 if (random(4) != 1) 
   {
   command("jiuming");
  message_vision ("\n小妖拼命往路边一挤，倏地一下水遁消失了。\n",me);
  me->move(room);
   }
 else
   {
  message_vision ("\n小妖叫道：完了，完了。言讫，吓得心胆俱裂，倒毙在地。\n",me);
  me->die();
  return ;
   }
}

void die (object me)
{
    ::die();
  message_vision ("\n小妖惨嚎一声，倒毙在地\n",me);
}


