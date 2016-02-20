
#include <ansi.h>

inherit NPC;

void create()
{
  set_name("Ì«ÉÏÀÏ¾ý",({"taishang laojun","laojun","dao"}));
  set("gender", "ÄÐÐÔ");
  set("age", 55);
  set("long", "    \nÌ«ÉÏÀÏ¾ý¡£\n");

  set("attitude", "peaceful");
  set("class", "taoist");
  set("combat_exp", 2000000);
  set("daoxing", 4000000);
  set("kee", 400);
  set("max_kee", 400);
  set("sen", 400);
  set("max_sen", 400);
  set("force", 400);
  set("max_force", 400);
  set("mana", 400);
  set("max_mana", 400);
  set("force_factor", 5);
  set("mana_factor", 10);



  set_skill("spells", 30);
  set_skill("dao", 30);
  set_skill("dodge", 60);
  set_skill("parry", 40);
  set_skill("unarmed", 30);


  set("inquiry", ([
  "here"   : "ÕâÀï¾ÍÊÇ¶µÂÊ¹¬£¬ÄãÀ´ÕâÀï¸ÉÊ²Ã´£¿",
]));


setup();

carry_object("/d/lingtai/obj/cloth")->wear();

}


void init()
{

  object who;

  ::init();
  if( interactive(who = this_player()) && !is_fighting() ) 
    {
     remove_call_out("greeting");
     call_out("greeting", 1, who);
    }
}


void greeting(object who)
{
  object me = this_object();
  if (who->query("dntg/laojunlu")=="allow")
    {
    me->command("kick");
        who->set("dntg/laojunlu","allow");
    me->command("chat ´óÊÂ²»ºÃ£¡"HIR+who->query("name")+HIC" ´Ó°ËØÔÂ¯ÖÐÌÓ³öÀ´ÁË¡«¡«¡«¡«");
    remove_call_out("leave_laojunlu");
    call_out("leave_laojunlu", 1, who);  
    } 
}

int leave_laojunlu(object who)
{
    who = this_player();
message("channel:rumor", HIC"¡¾Ì¸ÌìËµµØ¡¿"HIR+who->query("name")+"Ò»½ÅÌß·­ÀÏ¾ýÂ¯,Å­»ðÖ±³å¾ÅÏö¡«¡«¡«¡« \n"NOR, users());
    who->command("chat [1;31mÓñµÛÀÏ¶ùÄãµÈ×Å£¬´ýÎÒÕâ¾ÍÉ±ÉÏÁéÏöµî£¬¶áÁËÄãÄÇ»è¾ýµÄ±¦×ù£¡£¡£¡[0m");
    who->move("/d/dntg/sky/tongmingdian");
}