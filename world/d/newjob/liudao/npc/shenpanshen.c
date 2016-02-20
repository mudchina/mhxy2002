// created 19/3/2001 by Repoo and Xuexu
inherit NPC;
string try_me();
inherit F_MASTER;
#include <ansi.h>
void create()
{
set_name(HIW"审判之神"NOR, ({"shenpan shen","shen"}));
set("long","一个掌握着审判你生死权力的天神，你回答他的一字一句将成为生死的关键。\n");
set("title", HIR"红袍老人"NOR);
set("gender", "男性");
set("age", 80);
set("class", "yaomo");
set("attitude", "friendly");
set("rank_info/respect", "审判之神");
set("per", 30);
set("int", 30);
set("max_kee", 3500);
//       set("max_gin", 3500);
set("max_sen", 3500);
set("force", 10000);
set("max_force", 5000);
set("force_factor", 500);
set("max_mana", 5000);
set("mana", 10000);
set("mana_factor", 500);
set("combat_exp", 5000000);
set("daoxing", 6000000);
set("eff_dx", 200000);
set("nkgain", 350);
set_skill("literate", 180);
set_skill("dodge", 220);
set_skill("force", 220);
set_skill("parry", 220);
set_skill("sword", 220);
set_skill("spells", 400);
set_skill("dengxian-dafa", 400);
set_skill("ningxie-force", 400);
set_skill("bainiao-jian", 230);
set_skill("xiaoyaoyou", 220);
map_skill("spells", "dengxian-dafa");
map_skill("force", "ningxie-force");
map_skill("dodge", "xiaoyaoyou");
map_skill("sword", "bainiao-jian");
map_skill("parry", "bainiao-jian");
    set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                   (: cast_spell, "jieti" :),   
        }) );
set("inquiry", ([
      "饿鬼界": (: try_me :),
]));
create_family("大雪山", 2, "弟子");
setup();
carry_object("/d/obj/armor/jinjia")->wear();
}
void init()
{
        add_action("do_answer", "answer");
        add_action("do_look", "look");
}
int do_answer(string arg)
{
    object me = this_object();
     object ob = this_player();
        if( !arg ) return notify_fail("老夫听不懂，请answer yes or no\n");
        message_vision("$N答道：" + arg + "\n", this_player());
        if( arg== "yes" ) {
           if(this_player()->query("PKS") == 0)
          {
message_vision("$N答道：你说了让你后悔的谎话。这里是神圣的审判之殿，你要付出代价。\n", me);
         command("kill " + ob->query("id"));
       return 1;
          }
          {
    ob->set_temp("eguijie/chanhui",1);
    message_vision("$N答道：还算老实，不过你必须为死者的灵魂忏悔！\n", me);
        return 1;
           }
          }
          else
          {
       if( arg== "no" ) {
         if(this_player()->query("PKS") != 0 )
         {
message_vision("$N冷笑一声：你说了让你后悔的谎话。现在就按照你所说的话而付出代价吧！\n", me);
         command("kill " + ob->query("id"));
        return 1;
         }
          }
          else
          {
command("say 老夫不听无稽之谈，请你自重。\n");
       return 1;
          }
command("say 不错，老夫这就送你前去见主宰之神罗睺。\n");
          return 1;
}
}
string try_me()
{
          return "你曾经杀过人没有(answer)？\n";
}
int do_look(string arg)
{
     object me = this_player();
     if(arg == me->query("id"))
   {
command("say 看什么看，自己杀没杀过人不知道吗?\n");
   return 1;
   }
   else
   {
    return 0;
}
}
void die()
{
 object ob;
ob = new("/d/newjob/liudao/npc/shenpanshen");
ob->move("/d/newjob/liudao/shenpanshi");
destruct (this_object());
  unconcious();  
return;
}
