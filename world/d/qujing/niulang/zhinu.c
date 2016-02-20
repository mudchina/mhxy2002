//change.c
#include <ansi.h>
inherit NPC;
void create()
{
           set_name("Ö¯Å®", ({"zhi nu", "zhinu", "xian"}));
       set("long",
"Î÷ÍõÄ¸µÄÍâÉûÅ®¡£ÒòÎªË½×ÔÏÂ·²ÓëÅ£ÀÉÏà°®£¬¶ø±»·£ÒøºÓÓÀ¸ô£¬\nÖ»ÓÐÃ¿ÄêµÄÆßÔÂ³õÆß²ÅÄÜÈµÇÅÏà»á¡£\n");
       set("gender", "Å®ÐÔ");
       set("age", 20);
       set("class", "xian");
        set("title", HIM"Íû·òÐÄÇÐ"NOR);
       set("attitude", "friendly");
       set("rank_info/respect", "ÏÉ¹Ã");
       set("per", 30);
	set("int", 30);
         set("max_kee", 1500);
         set("max_gin", 1500);
         set("max_sen", 1500);
         set("force", 1200);
         set("max_force", 1200);
       set("force_factor", 50);
         set("max_mana", 1200);
         set("mana", 1200);
         set("mana_factor", 80);
         set("combat_exp", 800000);
        //   carry_object("/d/moon/obj/luoyi")->wear();
         //    carry_object("/d/obj/flower/rose")->wear();
 setup();   
}

void announce_success (object who)
{
  int i;

if (who->query("combat_exp") < 1000000)
    return;
  if (who->query("obstacle/niulang") == "done")
    return;
  if (!who->query_temp("daqiao")||!who->query_temp("ask_niulang"))
    return;
  i = random(24000);
  who->set("obstacle/niulang","done");
  who->add("combat_exp",i);
  command("chat "+who->query("name")+"´óÖÇ´óÓÂ£¬ÖúÎÒÓë·ò¾ýÍÅÔ²£¡");
message("channel:chat",HIY"¡¾¹ý¹ØÕ¶½«¡¿¹ÛÒôÆÐÈø(guanyin pusa)£º"+who->query("name")+"´³¹ýÎ÷ÐÐÈ¡¾­[1;37mµÚÈýÊ®Áù¹Ø£¡\n"NOR,users());//this is by tianlin 2001.5.8

  tell_object (who,"ÄãÓ®µÃÁË"+COMBAT_D->chinese_daoxing(i)+"µÄµÀÐÐ£¡\n");
  who->save();
}

