//yao.c 妖怪

inherit NPC;

void create()
{
        set_name("妖怪", ({ "dahan" }));
        set("long",
                "他是一个妖怪。\n");
        set("gender", "男性");
        set("age", 30);
        set("attitude", "aggressive");
        set("shen_type", 1);

        set("str", 30);
        set("int", 30);
        set("con", 35);
        set("dex", 30);

        set("max_kee", 400+random(200));
        set("max_sen", 200);
        set("force", 1000);
        set("max_force",1000);
         set("force_factor",1);

        set("combat_exp", 2000+random(2000));

        set_skill("force", 60);
        set_skill("dodge", 40);
        set_skill("parry", 40);
        set_skill("blade", 40);
      set_skill("bingpo-blade",100);
        set_skill("ningxie-force", 30);
        set_skill("xiaoyaoyou", 50);

        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "bingpo-blade");
        map_skill("blade", "bingpo-blade");
        map_skill("force", "ningxie-force");

        set("chat_chance_combat", 40);
/*        set("chat_msg_combat", ({
                (: perform_action, "blade.kugu" :),
        }) );*/

        

        setup();
        carry_object("/d/obj/weapon/blade/blade")->wield();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob=this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        object *guard,me;
        int i;
        me=this_object();
        guard = all_inventory(environment(me));
        for(i=0; i<sizeof(guard); i++)
        {
                if( !living(guard[i]) || guard[i]==me ) continue;
      if(guard[i]->query_temp("in_guard"))
      {
           me->kill_ob(guard[i]);
           guard[i]->kill_ob(me);
       } 
        }
}

void die()
{
object ob = this_object();
object *inv;
    int i;

    inv = all_inventory(ob);
    for(i=0; i<sizeof(inv); i++)
    {
        destruct(inv[i]);
     }
return ::die();
}
