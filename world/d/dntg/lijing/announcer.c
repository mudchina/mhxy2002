
#include <ansi.h>
inherit NPC;

void create() {

  set_name("Ì«°×½ðÐÇ",({"taibai jinxing"}));
  setup();
}

void announce(object winner,object env) {
  call_out("announce1",2,winner,env);
}

void announce1(object winner,object env) {

  if (winner->query("dntg/lijing")!="done") {
    command("chat ·îÓñµÛÊ¥Ö¼£¬"+winner->query("name")+RANK_D->query_respect(winner)+
                  "Îä¹¦¸ÇÊÀ£¬·¨Êõ³¬Èº£¬¼Ó·âÎª[1;31mÆëÌì´óÊ¥£¡[2;37;0m");
//    command("rumor ³ÇÏÂÖ®ÃË£¬É¥È¨Èè¹ú£¬²Ò²Ò²Ò¡£¡£¡£")
    winner->add("cor",2);
    tell_object(winner,HIC"ÄãµÃµ½ÁËÁ½µãµ¨Ê¶£¡\n"NOR);
    winner->set_temp("apply/title",({HIR"ÆëÌì´óÊ¥"NOR}));
   winner->set("dntg/lijing","done");
  env->set("host",winner);
  }

  destruct(this_object());
}
