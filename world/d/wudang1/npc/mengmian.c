//By tianlin@mhxy for 2001.9.25
//部分优化

inherit NPC;

void create()
{
        set_name("蒙面大汉", ({ "dahan" }));
        set("long",
                "他是一个蒙面大汉。\n");
        set("gender", "男性");
        set("age", 30);
        set("attitude", "aggressive");
        set("shen_type", 1);

        set("str", 30);
        set("int", 30);
        set("con", 35);
        set("dex", 30);

        set("max_kee", 400+random(1200));
        set("max_sen", 200);
        set("force", 1500);
        set("max_force", 1200);
        set("mana", 1990);
        set("max_mana", 1990);

        set("combat_exp", 1122000+random(211000));
        set("daoxing", 1132000+random(112000));

        set_skill("force", 160);
        set_skill("dodge", 140);
        set_skill("unarmed", 160);
        set_skill("parry", 180);
        set_skill("blade", 190);
        set_skill("kugu-blade", 190);
        set_skill("taoism", 120);

        map_skill("parry", "kugu-blade");
        map_skill("blade", "kugu-blade");

        setup();
        carry_object("/clone/weapon/gangdao")->wield();
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
		me->kill_ob(guard[i]);
	}
	command("kill zhike");
}
