// by snowcat oct 22 1997
#include <ansi.h>

inherit NPC;

string *names = ({
  "狮驼岭妖怪",
  "无底洞妖怪",
  "火云洞妖怪",
  "碧波谭妖怪",
  "金兜山妖怪",
});

void create()
{
   string str;
   set_name(names[random(sizeof(names))], ({"yao guai", "yao", "guai"}));
   set("long", "来准备杀攻打人间的妖怪。\n");
   set("title", HIR"攻打人间的"NOR);
   set("gender", "男性");
  set("combat_exp", 200000);
  set("age", 30);
  set("per", 25);
  set("attitude", "friendly");
  set("shen_type", 1);
  set("people", "people");
  set("force_factor",60);
  set("max_gin",600);
  set("max_kee",600);
  set("max_sen",600);
  set("max_force",800);
  set("max_mana",800);
  set_skill("unarmed", 200);
  set_skill("dodge", 200);
  set_skill("parry", 200);
  set_skill("force", 200);
   set_skill("wuxing-quan", 90);
   set_skill("baguazhen", 90);
   set_skill("parry", 280);
   set_skill("blade", 260);
   set_skill("yange-blade", 90);
   set_skill("zhenyuan-force", 280);
   map_skill("force", "zhenyuan-force");
   map_skill("unarmed", "wuxing-quan");
   map_skill("dodge", "baguazhen");
   map_skill("blade", "yange-blade");
  setup();
  carry_object("/d/obj/armor/tongjia")->wear();
  carry_object("/d/obj/weapon/blade/blade")->wield();
  set("no_nk_reward",1);
}

void init ()
{
  object ob = this_player();
  object me = this_object();

  if(living(ob))
  call_out("greeting", 1, ob);
}

void greeting(object ob)
{
  if( !ob || environment(ob) != environment() ) return;
  if (ob && interactive(ob))
  {
    if (! ob->query_temp("weishi_kill"))
      message_vision ("$N喝道：贱民无法无天，擅闯禁地！\n",this_object());
    this_object()->kill_ob(ob);
    ob->set_temp("weishi_kill",1);
  }
}
void die()
{
        object ob, me, corpse;
        
        ob = this_object();
        me = query_temp("last_damage_from");
        
        message_vision(WHT"$N大叫一声,大王救我!!倒地而亡。\n"NOR,ob,me);
//        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
//        corpse->move(environment(this_object()));
//        if((int)me->query("combat_exp") < 400000)   {
        message("vision", me->name() + "由于成功的打退了妖怪,增加了400经验400道行和250潜能。\n", me);
        me->add("combat_exp",400);
		me->add("daoxing",400);
		me->add("daoxing",400);
        me->add("potential",250);
        destruct(ob);
//        }
//        message("vision",  "你成功的保卫了祖国。\n", me);
//        me->add("score",2);
//        me->add("shen",10);
//        destruct(ob);
        return;
}
