
#include <ansi.h>

inherit ROOM;

void init() {

  set("long",@LONG

Ò»Æ¬¿ªÀ«µÄ²ÝµØ£¬±»ºï×ÓÃÇµ±×÷ËûÃÇµÄ½Ì¾ü³¡£¬Ö»¼ûÆäÖÐÒ»¸öÑÏËàµÄ
Í¨±³Ô³Ö¸»Ó×ÅÒ»ÁÐÁÐ£¬Ò»ÅÅÅÅ×ß¹ýÀ´µÄºï×Ó±ø¡£²ÝµØµÄ±±²àÊú×ÅÒ»¸ù
Ê®ÕÉ¶à¸ßµÄÆì¸Ë£¬ÉÏÃæ¹Ò×ÅÒ»Ãæ´óÆì(flag)£¬ÔÚ·çÖÐìªìªÆ®Îè¡£
LONG);

  add_action("do_start",({"raise","gua","sheng","hang"}));
  add_action("do_look","look");

}

int do_look(string arg) {
  object me=this_player();

  if (!arg || arg!="flag") return 0;
  write ("Ò»ÃæÈý³ß¼û·½µÄ´óìºÆì£¬Ó­·çÆ®Õ¹¡£\n");
  if (query("host")) write("ÆìÉÏÐå×Å"+HIR"ÆëÌì´óÊ¥[1;33m"+
        query("host")->query("name")+NOR"¼¸¸ö´ó×Ö¡£\n\n");
   else write("·çÌ«´ó£¬¿´²»Çå³þÆìÉÏÃæÐ´×ÅÊ²Ã´¡£\n\n");
  return 1;
}

int do_start(string arg) {
   object me=this_player();
   object host=query("host");
   object lijing;

   if (!arg || arg!="flag") return notify_fail("ÄãÒª×öÊ²Ã´£¿\n");
   if (host)
      return notify_fail(host->query("name")+"ÒÑÔÚ´ËÕ¼É½ÎªÍõÁË¡£\n");   
   if (me->query("combat_exp")<100000)
     return notify_fail("Æì¸ËÌ«¸ßÁË£¬Äã¹¦·òÌ«²î£¬¹Ò²»ÉÏÈ¥¡£\n");
   if (me->query("dntg/lijing")=="done")
     return notify_fail("ÄãÉÏ´ÎÒÑ¾­¹ý×ãÆëÌì´óÊ¥ñ«ÁË£¬Õâ´ÎÁô¸ø±ðÈËÍæ°É¡£\n");

   set("host",me);
   message_vision(HIG"$N½«[1;31m¡°ÆëÌì´óÊ¥¡±[2;37;0mµÄ´óÆì¹ÒÉÏÆì¸Ë¡£\n"NOR,me);
   message_vision(HIG"$N¸ßÉùÐû²¼£º¡°´Ó½ñÈÕÆð£¬"+RANK_D->query_self_rude(me)
     +"¾ÍÊÇ[1;31mÆëÌì´óÊ¥[2;37;0m£¬ÓëÓñµÛÀÏ¶ùÆ½ÆðÆ½×ø£¡¡±\n"NOR,me);

  lijing=new("/d/dntg/lijing/lijing");
  lijing->move(environment(me));
  lijing->set("target",me);
  lijing->start();
   
  return 1;
}
