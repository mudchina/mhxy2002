//modified by vikee for xlqy for NK_DX
//2000-11-23 16:21


inherit NPC;
void create()
{
        set_name("天将", ({ "tian jiang", "tianjiang", "jiang" }) );
        set("gender", "男性" );
	set("long",
		"守护九重天入口的天将\n"
	);
	set("age",50);
	set("attitude", "heroism");
	set("str",40);
	set("int",30);
	set("max_kee",3100);
	set("kee",3100);
	set("max_sen",3100);
	set("sen",3100);
	set("combat_exp",5000000);
        set("daoxing",5000000);
	set("force",2500);
	set("max_force",1500);
	set("mana",2500);
	set("max_mana",1600);
	set("force_factor", 120);
	set("mana_factor",120);

        set("eff_dx", 1500000);
        set("nkgain", 800);
	
	set_skill("unarmed",340);
	set_skill("yingzhaogong", 340);
	set_skill("parry",340);
	set_skill("dodge",340);
	set_skill("stick",340);
	set_skill("kusang-bang",340);
	set_skill("force",340);
	set_skill("spells", 340);
	set_skill("moshenbu", 340);
	map_skill("dodge", "moshenbu");
	map_skill("parry", "kusang-bang");
	map_skill("stick", "kusang-bang");
	map_skill("unarmed", "yingzhaogong");

	setup();
	carry_object("/d/sea/obj/dragonstick")->wield();
	carry_object("/d/obj/armor/jinjia")->wear();
}


void init()
{
        add_action("do_none","perform");
        add_action("do_none","cast");
        add_action("do_none","ji");
}
int do_none()
{
        object me = this_object();
        message_vision("此乃天界，岂容你乱来？\n",me);
        return 1;
} 
