// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 

inherit NPC;
#include <ansi.h>
string ask_me();
void create()
{
        set_name("善柔", ({"currency"}));
       set("title", HIG"天外飞仙"NOR);
      set("gender", "女性");
   set("long", "一位绝代风姿的美女,俏立崖间,直欲乘风飞去.\n");
        set("attitude", "peaceful");
        set("combat_exp", 1500000);
   create_family("南海普陀山", 2, "弟子");
   set("age", 16);
   set("per", 100);
        set("str", 30);
        set("int", 30);
        set("cor", 30);
        set("cps", 30);
        set("con", 30);
   set("class", "xian");
   set("rank_info/respect", "善柔");
   set("max_kee", 2500);
   set("max_sen", 2500);
   set("force", 3000);
   set("max_force", 2000);
   set("force_factor", 80);
   set("max_mana", 3000);
   set("mana", 5000);
   set("mana_factor", 100);

   set_skill("spells", 200);
   set_skill("buddhism", 200);
   set_skill("force", 160);
  set_skill("huntian-qigong", 180);
   set_skill("parry", 160);
   set_skill("dodge", 160);
   set_skill("moondance", 160);
   set_skill("unarmed", 160);
   set_skill("yinfeng-zhua", 160);
   set_skill("sword", 160);
   set_skill("sanqing-jian", 160);

   map_skill("spells", "buddhism");
   map_skill("force", "huntian-qigong");
   map_skill("dodge", "moondance");
   map_skill("unarmed", "yinfeng-zhua");
   map_skill("sword", "sanqing-jian");
  set("chat_chance_combat", 75);
  set("chat_msg_combat", ({
  (: exert_function, "zhangqi" :),
  (: cast_spell, "bighammer" :)
}));
        set("inquiry", ([
                "青索剑"   : (: ask_me :),
                "紫郢剑"   : "紫郢剑和青索剑本是一对,可它在月影妹妹那儿!\n",
                "月影"     : "听说月影妹妹在泰山,也不知是真是假!\n",
                "泰山"     : "不就是东岳吗,武林盟主也在那!\n",
        ]));

   set("time", 1);
   setup();
   carry_object("/d/obj/cloth/skirt")->wear();
  carry_object("/d/obj/weapon/sword/qinghong")->wield();
}

string ask_me()
{
        object ob;
           
    
       if (this_object()->is_fighting())
         return "没见老娘正打着吗, 以后再说吧!\n";

   if ( present("qingsuo-sword", this_player()) )
     return "青索剑不正在你身上吗!!\n";
        if ( present("qingsuo-sword", environment()) )
       return "你身边不就有一把青索剑吗!!\n";

   if(query("time") <1 )
     return "不巧，不巧，我也没了！\n";

     say("善柔说道: 那到要看你够不够格拿了, 放马过来吧!\n");
     this_player()->set_temp("currency_fight", 1);
     return ("嘿嘿！\n");
}


int accept_fight(object who)
{
     object me;
    me = this_object();
     if (!who->query_temp("currency_fight")){
     command("say 不打不打,没见本姑娘正等人吧!!\n");
         return 0;
   }
       // added by snowcat on 6/22/1997
   if (me->is_fighting()){
     command("say 不打不打!\n");
     return 0;
   }
   say("善柔笑道: 本姑娘闯荡江湖这么久了, 也从没悚过谁!\n");
   me->set("eff_kee", (int)me->query("max_kee"));
        me->set("kee", (int)me->query("max_kee"));
        me->set("eff_sen", (int)me->query("max_sen"));
        me->set("sen", (int)me->query("max_sen"));

     who->set_temp("currency_fight",0);
     remove_call_out("check_fight");
     call_out("check_fight", 1, me, who);
     return 1;
}

void player_win (object me, object who)
{
   object obj;
       // added by snowcat on 6/22/1997
        if (me->query("time")<=0)
                return;
   obj=new("/d/obj/weapon/dagger/qingsuo-sword");
   command("sigh");   
   say("善柔叹了一口气: 本姑娘在这等人等了这么久,功夫都荒废了!\n");
   say("善柔笑道: 当真是长江后浪推前浪,一代新人胜旧人!\n");
        obj->move(who);
        me->add("time", -1);
message_vision("善柔对$N嫣然一笑道: 这青索剑今日就赠给你了!\n", who);
   call_out("reg", 750);
}
int reg()
{
   object me, obj; 
   me=this_object();
   me->set("time",1);

//add weapon in case anyone took it already.
   if( !me->query_temp("weapon")){
     obj=new("/d/obj/weapon/sword/qinghong");
     obj->move(me);
     command("wield all");
   }   
   return 1;
}
void player_lose (object me, object who)
{
     string msg;
     msg = RANK_D->query_respect(who);
   
   command("jump");
   say("善柔安慰道:"+msg+"别灰心,回家好好练武吧,来日方长嘛!\n");
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
         call_out ("check_fight",1,me,who);
         return;
     }

     if (!present(who, environment(me)))
         return;

   // changed by snowcat on 6/24/1997
   // bug abuse: player can exert recover when fight stops,
   //if ((my_kee*100/my_max_kee) <=(whos_kee*100/whos_max_kee) )
   //      player_win (me, who);
   //else player_lose (me, who);
   if ((my_kee*100/my_max_kee) <= 50)
     player_win (me, who);
   else if ((whos_kee*100/whos_max_kee) <= 50)
     player_lose (me, who);

}

void die()
{

        if( environment() ) {
 message("sound", "\n\n只听一声凤鸣,善柔化作一道青霞直飞九天而去。。。\n\n
半空中有人轻笑了一声,怎么姐姐这么晚才来。。。\n\n", environment());
        }

        destruct(this_object());
}




