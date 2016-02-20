//jianshen.c by yushu 2001.2
inherit NPC;
void check_fight (object npc, object me);
int accept_fight(object me);
void player_win(object me);
void player_lose(object me);
#include <ansi.h>
void create()
{
       set_name("剑神", ({"jianshen","shen"}));
       set("gender", "男性");
       set("age", 120);
	set("class", "xiake");
       set("attitude", "friendly");
       set("rank_info/respect", "老师祖");
       set("per", 26);
	set("looking", "玉面多光润，苍髯颌下飘，金睛飞火焰，长目过眉梢。");
	set("shushan/jianshen_cast", 1);
	set("int", 30);
       set("max_kee", 5000);
       set("max_gin", 1000);
       set("max_sen", 5000);
       set("force", 5000);
       set("max_force", 2500);
       set("force_factor", 150);
       set("max_mana", 2500);
       set("mana", 5000);
       set("mana_factor", 150);
       set("combat_exp", 500000);
	set("daoxing", 800000);
       set_skill("literate", 120);
       set_skill("dodge", 150);
       set_skill("parry", 150);
       set_skill("unarmed", 150);
       set_skill("fumozhang",150); 
	set_skill("sword", 150);
	set_skill("songhe-sword", 160);
	set_skill("spells", 160);
	set_skill("xianfeng-spells", 160);
	set_skill("shushan-force", 160);
	set_skill("force", 160);
       set_skill("zuixian-steps", 150);
       map_skill("force", "shushan-force");
	map_skill("sword", "songhe-sword");
       map_skill("spells","xianfeng-spells");
	map_skill("parry", "songhe-sword");
	map_skill("dodge", "zuixian-steps");
       map_skill("unarmed","fumozhang");
       set("chat_chance_combat", 60);
       set("chat_msg_combat", ({
		  (: cast_spell, "jianshen" :),
        }) );
        setup();
        carry_object("/d/obj/cloth/mangpao")->wear();
}

void check_fight (object npc, object me)
{
  int npc_kee, my_kee, my_ratio, npc_ratio;
  int npc_max_kee, my_max_kee;
 
  my_kee = me->query("kee");
  npc_kee = npc->query("kee");
  my_max_kee = me->query("max_kee");
  npc_max_kee = npc->query("max_kee");
  my_ratio=my_kee*100/my_max_kee;
  npc_ratio=npc_kee*100/npc_max_kee;

  if (is_fighting())
  {
    call_out ("check_fight",2,npc,me);
    return;
  }
  if (query_temp("last_opponent")!=me) return;
  if (!present(me, environment(npc)))
    return;
  if(npc->query("kee")*100/npc->query("max_kee")
   < me->query("kee")*100/me->query("max_kee"))
    call_out("player_win", 1, me);
  else call_out("player_lose", 1, me);
  return;
}

int accept_fight(object me)
{
      set("kee", query("max_kee"));
      set("force", query("max_force"));
      remove_call_out("check_fight");
      call_out("check_fight", 1, this_object(), me);
      return 1;
}

void player_win(object me)
{
    this_object()->delete_temp("last_opponent");
    command("say 佩服!佩服!果然是习武之才。");
    command("say 我就把剑神这个法术教给你把。");
    command("say 后会有期！！！");
    me->set("shushan/jianshen_cast",1);
    me->move("d/shushan/tianshi");
    return;
}

void player_lose(object me)
{
    this_object()->delete_temp("last_opponent");
    command("say "+RANK_D->query_respect(me) +"不必气馁，再接再厉！");
    return;
}
