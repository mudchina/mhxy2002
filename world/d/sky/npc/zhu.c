// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */

inherit NPC;
string ask_me();
void create()
{
  set_name("天蓬元帅", ({ "tianpeng yuanshuai","yuanshuai","shuai","zhu" }));
  set("age", 600);
  set("gender", "男性");
  set("long", "他就是掌管八百里天河的天蓬元帅了,长得五大三粗!!\n");
  set("attitude", "peaceful");
  set("str", 50);
  set("per", 10);
  set("combat_exp", 1200000);
  set("max_kee", 2500);
  set("max_sen", 2500);
  set("max_force", 1500);
  set("force", 2500);
  set("force_factor", 150);
  set("mana_factor", 150);
  set("max_mana",2500);
  set("mana",2500);
  set_skill("unarmed", 190);
  set_skill("dodge", 160);
  set_skill("parry", 160);
  set_skill("rake", 150);
  set_skill("force", 180);
  set_skill("spells", 180);
  set_skill("baguazhou", 180);
  set_skill("yanxing-steps", 170);
  set_skill("skyriver-rake", 180);
  map_skill("force", "lengquan-force");
  map_skill("spells", "baguazhou");
  map_skill("rake", "skyriver-rake");
  map_skill("parry", "skyriver-rake");
  map_skill("dodge", "yanxing-steps");
  set("chat_chance",10);
  set("chat_msg",({
  "天蓬元帅自言自语道: 玉帝派我来管这八百里天河,就是因为我水里功夫高.\n",
  "天蓬元帅想到那天在瑶池遇见了嫦娥,不由叹道:真是一个绝代的美人儿!\n",
  "天蓬元帅自言自语道: 听说最近来了天宫来了一个弼马温!\n",
  "天蓬元帅道: 要是我能搞到雪饮杯,那可就好了!\n",
  "天蓬元帅说道: 听说这弼马温挺不安份的,找个机会我一定要揍他一顿!\n",
  }));
  set("inquiry", ([
  "比武": "就凭你那两下子,也想跟本帅比划!!\n",
  "弼马温":  (: ask_me :),
  "嫦娥": "听说雪饮杯是嫦娥仙子心爱之物,要是老子能搞到就好了!\n",
  ]));
  setup();
  carry_object("/d/kaifeng/obj/jiuchipa")->wield();
  carry_object("/d/obj/armor/tongjia")->wear();
}
string ask_me()
{
command("say 弼马温是未入流的小官,连七品都算不上,只是个马夫而已!\n");
command("say 我看你长得尖嘴猴鳃的,跟那厮的长相有三分相似!\n");
this_player()->set_temp("fight_zhu",1);
return "呵呵!\n";
}
int accept_object(object who, object ob)
{
 if((string)ob->query("id") !="snowglass"){
 command("say 这是什么破烂玩意啊!!");
 return 0;
}
else {
 command("smile");
 command("say 太好了,我终于搞到雪饮杯了.");
 command("say 不过你要想在这里放马,还是得胜过我才行!");
 this_player()->set_temp("zhu_fight", 1);
 return 1;
}
}
int accept_fight(object who)
{
 object me;
 me = this_object();
     if (!who->query_temp("fight_zhu"))
{
     command("say 本帅跟你无冤无仇的,跟你动手干什么!!\n");
     return 0;
}
     if (!who->query_temp("zhu_fight"))
{
     command("say 就算你那三脚猫的招式,也想跟本帅动手!!\n");
         return 0;
 }

 say("天蓬元帅道:今天本帅就陪你过几招吧!\n");
  me->set("eff_kee", (int)me->query("max_kee"));
        me->set("kee", (int)me->query("max_kee"));
        me->set("eff_sen", (int)me->query("max_sen"));
        me->set("sen", (int)me->query("max_sen"));
     remove_call_out("check_fight");
     call_out("check_fight", 1, me, who);
     return 1;
}
void player_win(object me,object who)
{
  me = this_object();
 call_out("zhu_appearing",1,who);
 command("chat 呵呵！");
 destruct(me);
 this_player()->delete_temp("zhu_fight",1);
 this_player()->delete_temp("fight_zhu",1);
 return ;
}
void zhu_appearing (object who)
{
  object zhu = new ("/d/sky/npc/zhu");
  zhu->announce_success (who);
  destruct (zhu);
}
void announce_success (object who)
{
  int i;

/*
  if (who->query("combat_exp") < 10000)
    return;
  if (who->query("obstacle/riverpass") == "done")
    return;
*/
  i = random(800);
  who->set("obstacle/riverpass","done");
  who->add("combat_exp",i+3000);
  command("chat "+who->query("name")+"天河扬威,智胜天蓬元帅！");
  command("chat "+who->query("name")+"顺利闯过西行又一关！");
  tell_object (who,"你赢得了"+chinese_number(3)+"年"+
               chinese_number(i/4)+"天"+
               chinese_number((i-(i/4)*4)*3)+"时辰的道行！\n");
  who->save();
}
void player_lose (object me, object who)
{
     string msg;
     msg = RANK_D->query_respect(who);

   command("jump");
   say("天蓬元帅笑道:我早就说过本帅的功夫是一等一的了!\n");
}
void check_fight (object me, object who)
{
     int my_kee, whos_kee;
     int my_max_kee, whos_max_kee;

   if(!who) return;
     my_kee = me->query("kee");
     whos_kee = who->query("kee");
     my_max_kee = me->query("max_kee");
     whos_max_kee = who->query("max_kee");

     if (me->is_fighting()){
         remove_call_out("check_fight");
         call_out ("check_fight",1,me,who);
         return;
     }

     if (!present(who, environment(me)))
         return;

   if ((my_kee*100/my_max_kee) <= 50)
     player_win (me, who);
   else if ((whos_kee*100/whos_max_kee) <= 50)
     player_lose (me, who);
}
