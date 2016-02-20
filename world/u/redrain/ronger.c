//ronger.c
#include <ansi.h>
#include <dbase.h>
inherit NPC;

void create()
{
       set_name(HIW"容儿"NOR, ({"rong er", "ronger"}));
       set("long",
"神仙孤狼的女朋友，芳名"HIM"容儿"NOR"。\n");
       set("title", HIC"孤狼行宫女主"NOR);
       set("gender", "女性");
       set("age", 22);
       set("class", "xian");
       set("attitude", "friendly");
       set("rank_info/respect", "神仙姐姐");
       set("per", 100);
       set("str", 30);
       set("looking", HIW"长的美丽动人，国色天香，就连嫦娥西施也比她逊色太多。"NOR);
       set("bellicosity", 1000);

       set("int", 40);
       set("max_kee", 10000);
       set("max_gin", 10000);
       set("max_sen", 10000);
       set("force", 100000);
       set("max_force", 7500);
       set("force_factor", 100);
       set("max_mana", 7500);
       set("mana", 100000);
       set("mana_factor", 100);
       set("combat_exp", 2000000);
  set("daoxing", 3500000);


        set("eff_dx", 200000);
        set("nkgain", 350);

       set_skill("literate", 500);
       set_skill("unarmed", 500);
       set_skill("dodge", 500);
       set_skill("force", 500);
       set_skill("parry", 500);
       set_skill("sword", 500);
       set_skill("spells", 500);
        set_skill("moonshentong", 500);
        set_skill("baihua-zhang", 500);
        set_skill("moonforce", 500);
        set_skill("snowsword", 500);
        set_skill("moondance", 500);
        map_skill("spells", "moonshentong");
        map_skill("unarmed", "baihua-zhang");
        map_skill("force", "moonforce");
        map_skill("sword", "snowsword");
        map_skill("parry", "snowsword");
        map_skill("dodge", "moondance");
   set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
     (: cast_spell, "arrow" :),
        }) );
        set("chat_chance",20);
        set("chat_msg", ({
        "容儿低头轻声说道：为什么我的孤狼哥哥到现在还没回来呢？\n",
        "容儿悠悠的叹了一口气。\n",
        "容儿红着脸说：我好想我的孤狼哥哥。\n", 
        }));

        setup();
        carry_object("/d/moon/obj/luoyi")->wear();
        carry_object("/d/ourhome/obj/shoes")->wear();
        carry_object("/d/obj/flower/rose")->wear();
      carry_object("/u/redrain/baoyi")->wear();
        carry_object("/u/redrain/sword")->wield();
}

void die()
{
  if (environment())
  message("sound", "\n只听蓉儿仰天轻声叫道：孤狼郎君，快来救我啊！\n", environment());
  message("sound", "\n孤狼突然出现在一阵烟雾中，手一挥，顿时一片红光罩住了容儿！\n\n", environment());
  set("eff_kee", 90000);
  set("eff_gin", 90000);
  set("eff_sen", 90000);
  set("kee", 90000);
  set("gin", 90000);
  set("sen", 90000);
  set("force", 100000);
  set("mana", 100000);
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting()
        && !this_player()->query("env/invisibility") ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
        say( "蓉儿红着脸说：这位" + RANK_D->query_respect(ob) +
"，你可曾看到我的孤狼哥哥？\n");
}


