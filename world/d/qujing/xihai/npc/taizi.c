//EDIT BY LUCAS
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int ask_chubing();
string expell_me(object me);



void create()
{
       set_name("摩昂", ({"mo ang","mo","ang"}));

        set("long","西海龙太子，翻江倒海雄。傲啸四海身，九霄自在神。\n");
       set("gender", "男性");
       set("age", 20);
       set("int", 25);
       set("title", "西海太子");
       set("attitude", "peaceful");
       set("combat_exp", 3000000);
       set("rank_info/respect", "太子殿下");
       set("class","dragon");
       set("per", 30);
       set("max_kee", 2000);
       set("max_sen", 1000);
       set("force", 2000);
       set("max_force", 2000);
       set("force_factor", 50);
       set("max_mana", 2000);
       set("mana", 2000);
       set("mana_factor", 100); 
         set("inquiry", ([
     "出兵": (: ask_chubing:),
     "降妖": (: ask_chubing:),
     "除妖": (: ask_chubing:),
     "灭妖": (: ask_chubing:),
        ]));
       set_skill("literate", 100);
       set_skill("unarmed", 200);
       set_skill("dodge", 150);
       set_skill("force", 120);
       set_skill("parry", 150);
       set_skill("fork", 150);
       set_skill("spells", 180);
       set_skill("seashentong", 140);
       set_skill("dragonfight", 150);
       set_skill("dragonforce", 160);
       set_skill("fengbo-cha", 150);
       set_skill("dragonstep", 130);
       map_skill("spells", "seashentong");
       map_skill("unarmed", "dragonfight");
       map_skill("force", "dragonforce");
       map_skill("fork", "fengbo-cha");
       map_skill("parry", "fengbo-cha");
       map_skill("dodge", "dragonstep");


    create_family("东海龙宫", 2, "水族");
        setup();

        carry_object("/d/sea/obj/longpao")->wear();
        carry_object("/d/sea/obj/tuotiancha")->wield();
}

int ask_chubing()
{
   object me, ob;
   me = this_player();
   ob = this_object();

            if(me->query("xinguan/heishui")=="done") { 
            command("say 难道我那表弟又做了什么伤天害理的事吗？\n");
    return 1;
   } 

    if( environment(this_object())->query("short") != "龙子居"){ 
    command("say 我们不是已经出兵了吗？请快快降妖吧。\n");
    return 1;
   } 
   if(!me->query_temp("王命")){
    command("say "+RANK_D->query_respect(me)+"未得父王同意，小龙不敢擅自出兵。");
    command("say "+RANK_D->query_respect(me)+"还是先请禀告父王吧。");
    return 1;
   }

   command("ah");
   command("kick");
   call_out("zuo",2);
   return 1;
}
void zuo()
{
   object me, ob;
   me = this_player();
   ob = this_object();
        
   command("say 这孽畜如此无礼，胆大妄为，既然父王有命，小龙愿出兵擒之。");
   call_out("dun",2);
}
void dun()
{
   object me, ob;
   me = this_player();
   ob = this_object();
        
   command("say "+RANK_D->query_respect(me)+"请随小龙一道，借水遁速往。");
   call_out("xian",2);
}
void xian()
{
   object me, ob;
   me = this_player();
   ob = this_object();
        
   message_vision(HIW"$N大吼一声，霹雳交加，现出法身，只见祥云朵朵，虬须狰狞，原来是八爪金龙。\n"NOR,ob);
   call_out("shui",1);
}
void shui()
{
   object me, ob;
   me = this_player();
   ob = this_object();
        
   message_vision(HIC"$N大口一张，只见西海之水汹涌而来，忽然集结成团，将二人与大群虾兵蟹将席卷在内。\n"NOR,ob,me); 
   call_out("wait",2);
}
void wait()
{
   object me, ob;
   me = this_player();
   ob = this_object();

   me->move("/d/qujing/xihai/water");
   ob->move("/d/qujing/xihai/water");
   me->delete_temp("王命");
   call_out("swim_in_water",1,me);
}
void swim_in_water(object me)
{
  object ob = this_object();

  string *msgs = ({
    "$N只见四周水幕晶莹剔透，水幕外无数水族悠闲浮游。\n",
    "水幕外一条大鲨鱼张开血盆大口，对$N嘿嘿奸笑了几声。\n",
    "水幕外是万丈深海之下，里面却干燥适意，$N不由羡慕起海神奇术。\n",
  });

  message_vision(msgs[random(sizeof(msgs))],me);
  me->add_temp("swiming",1);
  if(me->query_temp("swiming")>5+random(7)){
   me->move("/d/qujing/heishui/xuanya");
   ob->move("/d/qujing/heishui/xuanya");
  message_vision(HIC"$N大喝一声：临兵斗者皆阵列在前！言讫，水幕哗地散开，却已经到了黑水之境。\n"NOR,ob);
  call_out("nofight",2);
    return;
  }
  call_out("swim_in_water",random(9),me);
}  
void nofight()
{
   object me, ob;
   me = this_player();
   ob = this_object();
        
   command("say 小龙与妖物份属至亲，不便动武。");
   call_out("xia",2);
}
void xia()
{
   object me, ob;
   me = this_player();
   ob = this_object();
        
  command("say "+RANK_D->query_respect(me)+"请下水擒妖，小龙在此擂鼓助威。");
  call_out("shout",1);
}
void shout()
{
   object me, ob;
   me = this_player();
   ob = this_object();
        
  command("say 小的们，且为"+RANK_D->query_respect(me)+"擂鼓助威！");
  call_out("bing",1);
}
void bing()
{
   object me, ob;
   me = this_player();
   ob = this_object();
        
  message_vision(HIY"一众虾兵蟹将喧嚣大吼："+RANK_D->query_respect(me)+"必胜！"+RANK_D->query_respect(me)+"必胜！\n"NOR,me);
    me->delete_temp("swiming");
    me->add_temp("fight",1);
}

