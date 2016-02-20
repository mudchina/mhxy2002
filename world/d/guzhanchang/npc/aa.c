#include <ansi.h>
inherit NPC;

void create()
{
    set_name(HIY "天极" NOR, ({"tian ji", "tian", "ji"}));
    set("title", HIR "天外天守护神" NOR);
    set("long", "传说是盘古的滴血化身。其轮回精华之中,无生无灭。\n");
    set("gender", "男性");
    set("age", 13500);
    set("str", 40);
    set("per", 40);
    set("attitude", "peaceful");
    set("combat_exp", 10000000);
    set("daoxing", 10000000);
    set("eff_kee", 10000);
    set("eff_sen", 10000);
    set("max_kee", 10000);
    set("max_sen", 10000);
    set("sen", 10000);
    set("kee", 10000);
    set("max_force", 10000);
    set("max_mana", 10000);    set("mana", 10000);
    set("force", 20000);
    set("force_factor",  500);
    set("mana_factor", 500);
    set_skill("seashentong", 400 );
    set_skill("dragonforce", 400 );
     set_skill("zhenyuan-force", 400 );
     set_skill("taiyi", 400 );
    set_skill("taoism", 400 );
    set_skill("lengquan-force", 400 );
    set_skill("baguazhou", 400 );
    set_skill("gouhunshu", 400 );
    set_skill("tonsillit", 400 );
    set_skill("force", 400 );
    set_skill("moonshentong", 400 );
    set_skill("moonforce", 400 );
    set_skill("buddhism", 400 );
    set_skill("lotusforce", 400 );
    set_skill("xiantian", 400 );
    set_skill("feisheng", 400 );
    set_skill("jiuyin-xinjing", 400 );
    set_skill("pansi-dafa", 400 ); 
    set_skill("dao", 400 );
    set_skill("sword", 400 );
    set_skill("wuxiangforce", 400 );
    set_skill("ningxie-force", 400 );
    set_skill("dengxian-dafa", 400 );    set_skill("huomoforce", 400 );
    set_skill("pingtian-dafa", 400 );
    set_skill("yaofa", 400 );
    set_skill("huntian-qigong", 400 );
    set_skill("unarmed", 400 );
    set_skill("spells", 400 );    
       set_skill("force", 400 );
    set_skill("dodge", 400 );
    set_skill("parry", 400 );
      map_skill("force", "dragonforce");
      map_skill("spells", "taoism");

    set("chat_chance_combat", 60);
    set("chat_msg_combat", ({
        (: cast_spell, "fu" :),
        (: cast_spell, "jianshen" :),
(: exert_function, "roar" :),
(: exert_function, "shield" :),
}));
      setup();

}

int accept_fight(object me)
{
        write(CYN "天极歪着头想了想，说道：好吧。\n" NOR);
        return 1;
}
int recognize_apprentice(object me)
{
      object ob = this_player();

        if( ( ob->query("family/family_name") != "将军府"
            && ob->query("family/family_name") != "武圣门" 
            && ob->query("family/family_name") != "蜀山剑派"
            && ob->query("family/family_name") != "阎罗地府"
            && ob->query("family/family_name") != "东海龙宫" 
            && ob->query("family/family_name") != "方寸山三星洞"
            && ob->query("family/family_name") != "南海普陀山"
            && ob->query("family/family_name") != "月宫"
            && ob->query("family/family_name") != "五庄观" 
            && ob->query("family/family_name") != "盘丝洞"
            && ob->query("family/family_name") != "陷空山无底洞"
            && ob->query("family/family_name") != "大雪山"
            && ob->query("family/family_name") != "火云洞")
            || ob->query("combat_exp")  < 2000000 )
             return notify_fail( HIR "看起来天极想杀死你！\n"NOR);
             return 1;
}

