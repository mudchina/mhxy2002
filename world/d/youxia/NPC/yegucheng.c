
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 //created 23-06-2001 海上飘(piao)

//yegucheng.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
string give_map(object me);
// string expell_me(object me);
int do_yes(string arg);


void create()
{
       set_name("叶孤城", ({ "ye gucheng", "ye", "ye gucheng" }) );

       set("long", "白云城主以前充满了尊荣和光采．而现在．．．．
他知道那被唐门暗器所伤的伤口已完全溃烂．．．\n");
      set("faith",4000);
       set("gender", "男性");
     set("title", HIW "白云城主"NOR);
   set("class", "youxia");
       set("age", 34);
       set("attitude", "friendly");
        create_family("江湖浪子", 1, "绿");
       set("per", 30);
   set("int", 30);
   set("str", 30);
   set("cps", 30);
       set("max_kee", 2000);
       set("max_gin", 1100);
       set("max_sen", 2000);
       set("force", 8000);
       set("max_force", 3000);
       set("force_factor", 160);
       set("max_mana", 3000);
       set("mana", 8000);
       set("mana_factor", 100);
       set("combat_exp", 2000000);
       set("daoxing", 2000000);
        set("eff_dx", 250000);
        set("nkgain", 400);
            set("chat_chance", 10);
        set("chat_msg", ({
            "叶孤城从点点血斑的白袍撕下一条布条。\n叶孤城用从点点血斑的白袍撕下的布条替自己裹伤。\n",
   }) );
       set_skill("parry", 250);
           set_skill("sword", 250);
     set_skill("baiyun-sword", 250);
     set_skill("spells", 250);
     set_skill("tianjijue", 250);
     map_skill("sword", "baiyun-sword");
   map_skill("parry", "baiyun-sword");
   map_skill("spells", "tianjijue");
        

        set("inquiry", ([
//     "离开": (: expell_me :),
//      "leave": (: expell_me :),
        "白云剑谱" : (: give_map :),

]) );

setup();
        carry_object("/d/youxia/obj/bsword")->wield();
        carry_object("/d/youxia/obj/whitecloth")->wear();
carry_object("/d/youxia/obj/bcloth")->wear();
}


void attempt_apprentice(object ob)
{
   if ( (string)ob->query("family/family_name")=="江湖浪子") {
   if (((int)ob->query("combat_exp") < 1000000 )) {
   command("say 这位"+ RANK_D->query_respect(ob) + "你武功低微．．．．还是几年后再来找我吧。\n");
   return;
   }
        command("smile");
   command("say 很好，原来这位"  + RANK_D->query_respect(ob) +"是游侠儿的徒弟，好吧，本城主就收你为徒！\n");
        command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，他日必定有成。\n");
       command("recruit " + ob->query("id") );
  ob->set("title", HIC"叶孤城亲授弟子"NOR);
  return;
   }
   command("shake");
   command("say " + RANK_D->query_respect(ob) + "既然已经派入他门,还是另寻他人吧！\n");
        return;
}
/*
string expell_me(object me)
{       me=this_player();
        if((string)me->query("family/family_name")=="江湖浪子") {
                command("say 你既是不肯再做游侠，为师却有几句话说。");
                me->set_temp("betray", 1);
     command("say 我们虽不是正式的门派，但国有国法，侠有侠规！");
                return ("既是要离去，却需受本城主的惩罚，你可愿意(agree)?");
        }
        return ("本城主不知。");
}
*/
void init()
{
      ::init();
//      re_rank(this_player())
//       add_action("do_agree", "agree");
      add_action("do_fuming","fuming");
      add_action("do_yes", "yes");
}


/*
int do_agree(string arg)
{
        if(this_player()->query_temp("betray")) {
                message_vision("$N答道：弟子愿意。\n\n", this_player());
     this_player()->add("betray/count", 1);
     this_player()->add("betray/fangcun", 1);
                command("say 既是我游侠之中容不下你，便自行离去吧！");
this_player()->set("combat_exp", this_player()->query("combat_exp")*80/100);
this_player()->set("combat_exp", this_player()->query("daoxing")*80/100);
                this_player()->delete_skill("piaoxiang");
                this_player()->delete_skill("wuji-force");
                this_player()->delete_skill("tianjijue");
                this_player()->delete("family");
                this_player()->delete("class");
                this_player()->set("title", "普通百姓");
             this_player()->set("faith",0);
     this_player()->save();
                command("say 江湖风波，善恶无形，好自为之。。。\n");
                return 1;
                }
        return 0;
}

*/
string give_map(object me)
{
        me=this_player();
        me->set_temp("need_map", 1);
        return "如今我落难在此，"HIW"〖白云剑谱〗"HIC"是我毕生武功的精华,你想要吗(yes)？"NOR"\n";
}


int do_yes(string arg)
{
        object me;

        me=this_player();
        
        if(me->query_temp("need_map")) 
        {
                message_vision("$N答道：想要！\n\n", me);

               if(me->query("family/family_name") != "江湖浪子" )
                return notify_fail("叶孤城说道：想骗本门派的秘籍，没门！\n");

                if( query("no_map") == 0 )
                {
                        message_vision("叶孤城说道：好！那我给你这本剑谱吧！\n", me);
                        me->set_temp("need_map", 0);

                        carry_object("/d/youxia/obj/jianpu");
                        command("give baiyun jianpu to " + me->query("id"));
                        set("no_map", 1);
                        call_out("regenerate", 480);
                }
                else
                {
                        message_vision("叶孤城说道：我本来想给你一本剑谱的，但是刚才被人要走了。\n", me);
                }

                return 1;
        }
        return 0;
}

int regenerate()
{
        set("no_map", 0);
        return 1;
}



