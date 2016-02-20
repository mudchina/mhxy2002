// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// guanyin.c 观音菩萨
// By Dream Dec. 19, 1996

inherit NPC;


void create()
{
   set_name("观音菩萨", ({ "guanyin pusa", "guanyin", "pusa" }));
   set("title", "救苦救难大慈大悲");
   set("long", @LONG
理圆四德，智满金身。眉如小月，眼似双星。兰心欣紫竹，
蕙性爱得藤。她就是落伽山上慈悲主，潮音洞里活观音。
LONG);
   set("gender", "女性");
   set("age", 35);
   set("attitude", "peaceful");
   set("rank_info/self", "贫僧");
   set("rank_info/respect", "菩萨娘娘");
   set("class", "bonze");
           set("str",24);
   set("per",100);//means no rong-mao description.
   set("max_kee", 3000);
   set("max_gin", 3000);
   set("max_sen", 3000);
   set("force", 3000);
   set("max_force", 2000);
   set("force_factor", 100);
   set("max_mana", 2000);
   set("mana", 4000);
   set("mana_factor", 100);
   set("combat_exp", 2000000);
   set_skill("literate", 150);
   set_skill("spells", 200);
   set_skill("buddhism", 200);
   set_skill("unarmed", 150);
   set_skill("jienan-zhi", 150);
   set_skill("dodge", 180);
   set_skill("lotusmove", 160);
   set_skill("parry", 150);
   set_skill("force", 180);
   set_skill("lotusforce", 180);
   set_skill("staff", 150);
   set_skill("lunhui-zhang", 180);
   set_skill("spear", 150);
   map_skill("spells", "buddhism");
   map_skill("unarmed", "jienan-zhi");
   map_skill("dodge", "lotusmove");
   map_skill("force", "lotusforce");
   map_skill("parry", "lunhui-zhang");
   map_skill("staff", "lunhui-zhang");
   set("chat_chance_combat", 80);
   set("chat_msg_combat", ({
     (: cast_spell, "bighammer" :),
   }) );
   //hehe, since guanyin was killed several times
   //let's use cast bighammer to protect her...weiqi:)
   create_family("南海普陀山", 1, "菩萨");

   setup();
   carry_object("/d/nanhai/obj/jiasha")->wear();
   carry_object("/d/nanhai/obj/nine-ring")->wield();
}


void die()
{       
        object me = this_object();
        object ob = query_temp("my_killer");
        if(ob) {ob->set_temp("guanyin_killed",1);
            call_out ("puti_appearing",1,ob);  }

        if( environment() ) {
        message("sound", "\n\n观音菩萨摇头叹道：刚离迷障，又入魔障，世间疾苦，何人度之！\n\n", environment());
        command("sigh");
        message("sound", "\n观音菩萨驾祥云，登彩雾，径往西方去了。。。\n\n", environment());
   
   }
   load_object("/obj/empty");
   me->move("/obj/empty");
   call_out ("destruct_me",3,me);

}

void unconcious()
{
   die();
}

void destruct_me()
{
   destruct(this_object());
}
