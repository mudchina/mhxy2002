// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */

// 李靖
//created 4-8-97 pickle
inherit NPC;

void create()
{
        set_name("李靖", ({ "li jing", "li" }) );
        set("title", "托塔天王");
        set("gender", "男性" );
        set("long","
托塔李天王李靖是玉帝殿前一员大将,手中玲珑宝塔是其最得意的法宝。\n");
        set("age",35);
        set("attitude", "peaceful");
        set("str",28);
        set("int",28);
        set("per",30);
        set("bellicosity", 1000);
        set("max_kee",3000);
        set("kee",3000);
        set("max_sen",3000);
        set("sen",3000);
        set("combat_exp",2500000);
        set("force",3200);
        set("max_force",3200);
        set("mana",2000);
        set("max_mana",2000);
        set("force_factor", 80);
        set("mana_factor", 80);

        set("eff_dx", 250000);
        set("nkgain", 350);

        set_skill("spells", 200);
        set_skill("buddhism", 200);
        set_skill("unarmed",120);
        set_skill("parry",180);
        set_skill("dodge",180);
        set_skill("throwing",200);
        set_skill("sanqing-jian",200);
        set_skill("lotusmove", 180);
        set_skill("force",180);
        set_skill("jienan-zhi",180);
        map_skill("dodge", "lotusmove");
        map_skill("unarmed", "jienan-zhi");
        map_skill("spells","buddhism");
        map_skill("parry","sanqing-jian");
       set("chat_chance_combat",80);
  //     set("chat_msg_combat",({
  //     (: cast_spell, "bighammer" :),
// }));
        setup();
        carry_object("/d/obj/weapon/archery/zhentian-arrow")->wield();
        carry_object("/d/obj/weapon/archery/qiankun-bow")->wield();
        carry_object("/d/obj/armor/yinjia")->wear();
}

void destruct_me (object me)
{
  destruct (me);
}


void unconcious ()
{
  die ();
}

int accept_fight(object ob)
{
  ob->apply_condition("killer", 100);
  kill_ob(ob);
  return 1;
}
void die()
{

        if( environment() ) {
        message("sound", "\n\n李靖大惊道：妖孽竟然还如此猖狂！
\n\n", environment());
        message("sound", "\n李靖跌跌撞撞的跑了。。。\n\n", environment
());
        }

        destruct(this_object());
}



void init ()
{
  remove_call_out ("messaging");
  call_out ("messaging",1+random(9),this_object());
}

void messaging (object who)
{
  if (random(2))
    command("sneer");
  else
    command("heng");
}
