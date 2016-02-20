// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 

inherit NPC;

void create()
{
        set_name("广心子", ({"guang xinzi", "guang"}));
        set("gender", "男性" );
        set("age", 43);
        set("long", "方寸山三星洞第二代弟子中的杰出人物，他毕生钻研法术，\n在道学心法上极有成就。\n");
        set("combat_exp", 800000);
        set("attitude", "friendly");
        create_family("方寸山三星洞", 2, "高徒");
        set("int", 25);
        set("class", "taoist");

        set("eff_dx", 700000);
        set("nkgain", 300);

        set_skill("unarmed", 110);
        set_skill("dodge", 110);
        set_skill("parry", 110);
        set_skill("spells", 110);  
        set_skill("dao", 110);
        set_skill("literate", 110);
        set_skill("stick", 80);  
        set_skill("qianjun-bang", 80);
        set_skill("puti-zhi", 110);  
        set_skill("jindouyun", 110);
        set_skill("dodge", 110);
        set_skill("force", 110);   
        set_skill("wuxiangforce", 110);

        map_skill("spells", "dao");
        map_skill("unarmed", "puti-zhi");
        map_skill("force", "wuxiangforce");
        map_skill("stick", "qianjun-bang");
        map_skill("parry", "qianjun-bang");
        map_skill("dodge", "jindouyun");


        set("per", 30);
        set("str", 25);
        set("max_kee", 1500);
        set("max_gin", 1500);
        set("max_sen", 1500);
        set("force", 2000);
        set("max_force", 1000);
        set("force_factor", 20);
        set("mana", 3000);
        set("max_mana", 1500);
        set("mana_factor", 60);
        setup();
        carry_object("/d/lingtai/obj/daoguan")->wear();
        carry_object("/d/lingtai/obj/cloth")->wear();
        carry_object("/d/lingtai/obj/bang")->wield();
}

void init()
{
	::init();

	if (interactive(this_player()) && this_player()->query_temp("fighting"))
	{
		SKILL_D("dao")->cast_spell(this_object(),"light",this_player());
		this_player()->add_temp("beat_count", 1);
	}       
}
