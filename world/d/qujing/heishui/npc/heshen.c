inherit NPC;
#include <ansi.h>
int ask_guai();

void create()
{
       set_name("黑水河神", ({"heishui heshen","heshen"})); 
       set("long","这是黑水河神，当年也曾在此叱咤风云，如今却被关在这里。\n");
       set("gender", "男性");
       set("age", 200);
       set("int", 25);
       set("attitude", "peaceful");
       set("combat_exp", 1000000);
       set("rank_info/respect", "尊神");
       set("per", 30);
       set("max_kee", 1000);
       set("max_sen", 8000);
       set("force", 1500);
       set("max_force", 1500);
       set("force_factor", 30);
       set("max_mana", 2000);
       set("mana", 2000);
       set("mana_factor", 50); 
        set("chat_msg", ({
                "河神叹道:我若能离开这里,必要告到玉帝面前!\n",
                "那妖孽好生猖獗!不但占我府邸，还囚我于此。\n",
        }) );
         set("inquiry", ([
     "妖怪": (: ask_guai:),
     "yaoguai": (: ask_guai:),
     "yao guai": (: ask_guai:),
     "来历": (: ask_guai:),
     "妖怪来历": (: ask_guai:),
     "鼋龙": (: ask_guai:),
     "妖龙": (: ask_guai:),
        ]));
       set_skill("literate", 100);
       set_skill("unarmed", 100);
       set_skill("dodge", 150);
       set_skill("force", 120);
       set_skill("parry", 100);
       set_skill("sword", 150);
       set_skill("spells", 180);
       set_skill("dao", 180);
       set_skill("puti-zhi", 120);
       set_skill("wuxiangforce", 140);
       set_skill("fonxansword", 100);
       set_skill("jindouyun", 130);
       map_skill("spells", "dao");
       map_skill("unarmed", "puti-zhi");
       map_skill("force", "wuxiangforce");
       map_skill("sword", "fonxansword");
       map_skill("parry", "fonxansword");
       map_skill("dodge", "jindouyun");


        setup();

        carry_object("/d/lingtai/obj/daoguan")->wear();
        carry_object("/d/lingtai/obj/cloth")->wear();
}

int ask_guai()
{       object me;        
        me=this_player();

        if(me->query("xinguan/heishui")=="done") {
                command("say 老是麻烦"+RANK_D->query_respect(me)+ ",我都不好意思了。\n");
                command("sigh2");
                return 1;
        }       
        if( me->query_temp("heshen")) {
                command("say "+RANK_D->query_respect(me)+ "还没去找西海龙王吗？\n");
                command("sigh2");
                command("say " +RANK_D->query_respect(me)+ "请尽快动身，小神只怕时日无多了。\n");
                return 1;
        }
        command("sigh");
        call_out("shen",2);
        me->set_temp("heshen",1);
        return 1;
}

void shen()
{
     object me;        
     me=this_player();
        
    command("say 小神本是此河河神，主管黑水，倒也风调雨顺。\n");
   call_out("nie",2);
}
void nie()
{
     object me;        
     me=this_player();
        
        command("say 那孽畜本是西海龙王之外甥，前些年乘江潮至此。\n");
   call_out("duo",2);
}

void duo()
{
     object me;        
     me=this_player();
        
   command("say 然后夺我府邸，囚我于此，我多番递状，却被那西海龙王拦下。\n");
   call_out("jiu",2);
}
void jiu()
{
     object me;        
     me=this_player();
        
        command("say 万望" +RANK_D->query_respect(me)+ "与我伸冤。\n");
   call_out("bow",2);
}
void bow()
{
     object me;        
     me=this_player();
        
   command("bow");
}

