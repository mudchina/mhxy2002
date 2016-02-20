//by tianlin 2001.8.11ĞŞ¸Ä

#include <ansi.h>
inherit NPC;
int say_zhu();
int test_jing(object ob);
void announce_start();
void announce_finish(object ob);

void create()
{
  set_name("Áé¼ªÆĞÈø", ({"lingji pusa", "pusa"}));
  set("long", "Ò»Î»´ÈÃ¼ÉÆÄ¿µÄÀÏÈË£¬ÎÅËµ·¨Á¦¸ßÇ¿£¬
ÔÚ´ËÉèÔº½²¾­´«µÀ£¬¶É»¯ÊÀÈË¡£\n");
  set("gender", "ÄĞĞÔ");
  set("age", 80);
  set("attitude", "friendly");
  set("combat_exp", 2000000);
  set("per", 100);
  set_skill("dodge", 200);
  set_skill("force", 200);
  set_skill("spells",190);
  set_skill("unarmed",200);
  set_skill("buddhism", 190);
  set_skill("jienan-zhi", 200);
  set_skill("lotusmove", 160);
  set_skill("lotusforce",180);
  map_skill("force","lotusforce");
  map_skill("unarmed", "jienan-zhi");
  map_skill("dodge", "lotusmove");
  map_skill("spells", "buddhism");
  set("max_sen",3000);
  set("max_gee",3000);
  set("max_gin",3000);
  set("force",3000);
  set("max_force",3000);
  set("max_mana",3000);
  set("mana",3000);
  set("force_factor",175);
  set("mana_factor",100);
  set("chat_chance_combat", 60);
  set("chat_msg_combat", ({
	(: cast_spell, "bighammer" :),
        }) );
   set("inquiry",([
		  "Öé": (: say_zhu :),
		  "¶¨·çÖé": (: say_zhu :),
                "zhu":(: say_zhu :),
                "name":"ÀÏñÄÁé¼ª¡£",
		  "here": "ÕâÀïÊÇÀÏñÄ½²¾­µÄµØ·½£¬Ğ¡ĞëÃÖÉ½£¡",
		  "rumors":"ËµÀ´²ÑÀ¢£¬ÀÏñÄµÄ¶¨·çÖé¾¹±»Ñı¹ÖµÁÁËÈ¥£¡",
                "·üÄ§":(:test_jing:),
                "book":(:test_jing:),
		  ]));

  setup();

  carry_object("/d/qujing/huangfeng/obj/jiasha")->wear();
}

int say_zhu()
{
  object  me=this_player();
  
  if (me->query("obstacle/huangfeng") == "done"||me->query("obstacle/yz") != "done")
	message_vision("Ïò$N¹ªÉíÒ»Ğ»£¬ÑÔµÀ£º¡°Ê©Ö÷·ÅĞÄ£¬ÀÏñÄÒÑ½«¶¨·çÖéÊÕÍ×ÁË£¬²»»áÔÙ¶ª¡£¡±\n",me);
    else
	{
	command("sigh");
	command("say ÈıÌìÇ°£¬±»ÄÇ¹ÖÒ»ÕóÒõ·çÉãÁËÈ¥£¬ÌıËµ²ØÓÚËûÄÇºóÔ°Ö®ÖĞÁË¡£\n");
	}
return 1;
}

void announce_start()
{
    command("chat ¸÷Î»Ê©Ö÷ÇëÁË£¡");
    command("chat ½µÄ§±¦¼®½ñÄê³öÊÀ£¬Çë¸÷Î»ÓĞÔµÈËÇ°À´Ò»ÊÔ¡£");
}

void announce_finish(object ob)
{
  ob->delete("fumo2_gived");
  remove_call_out("announce_finish");
  command("chat ½µÄ§±¦Â¼½«ÓÚÏÂÒ»¸öÂÖ»Ø³öÊÀ£¬µ«Íûµ½Ê±¸÷Î»Ê©Ö÷Ç°À´Ò»ÊÔ£¡");
}

int test_jing(object ob)
{     
   object who=this_player();
   object book;
   object where=environment();
      
      if(ob->query("fumo2_gived")) {
          command("sigh "+who->query("id"));
      message_vision("$NÌ¾Ï¢µÀ£º¡°Ê©Ö÷À´ÍíÁË£¬·üÄ§±¦Â¼ÒÑ¾­ÔùÓëÓĞÔµÈËÁË£¬Ö»ÄÜµÈÏÂÒ»´Î£¡\n",ob);
             return 1;
          }
   if(!where->query("book_give_can")) {
      message_vision("$NĞ¦µÀ£¬Ê±ºòÎ´µ½£¬ÕâÎ»Ê©Ö÷ÇÒµÈÆ¶É®µ±ÖÚĞû²¼,ÔÙÀ´²»³Ù£¡\n",ob);
             return 1;
      }
   if(who->query_skill("force", 1) < 100 ) {
    message_vision("$NÎ¢ºÏË«ÑÛ£¬Ì¾ÁË¿ÚÆø£ºÕâÎ»Ê©Ö÷¶Ô·üÄ§ĞÄ·¨µÄÁìÎò»¹²»¹»»ğºò£¬¿ÖÅÂ½µ²»ÁËÑıÄ§¡£\n", ob,who);
           return 1;
      }
   if (who->query("fumo2") ) {
     message_vision("$NºÏÕÆµÀ£ºÊ©Ö÷ÒÑ¾­»ñµÃ¹ı´ËÊéÁË¡£Ôµ·İÒ»ËµÊµ·ÇĞéÍı£¬¿ÉÓö¶ø²»¿ÉÇóÒ²¡£Ê©Ö÷Çë»Ø°É£¡\n", ob);
           return 1;
      }
   book=new("/d/obj/book/forcebook2");
   book->move(who);
       who->set("fumo2", 1);
     ob->set("fumo2_gived",1);
     where->delete("book_give_can");
       message_vision("$N´Ó»³ÖĞÈ¡³ö±¾·üÄ§ĞÄ¾­µİ¸ø$n£¬Î¢Ğ¦µÀ£¬µ«ÍûÊ©Ö÷²»¸ºËùÍĞ£¬½µÄ§ÎÀµÀ£¡\n", ob,who);
     command("chat "+who->query("name")+"Ê©Ö÷¸£ÔµÉîºñ£¬»ñµÃ·üÄ§É½ĞÄ¾­Ò»±¾£¡");
     remove_call_out("announce_finish");
     call_out("announce_finish",600,ob);
     return 1;
}

void call_out_announce_success(object who)
{
	call_out("say_hi",1,who);
	call_out("announce_success",2,who);
}

void say_hi(object who)
{
  message_vision ("\n°ë¿ÕÖĞ£¬Áé¼ªÆĞÈøÏò$NÎ¢Ğ¦ÖÂĞ»¡£\n",who);
}

void die()
{
      int i;
      object *inv;
          object me=this_player();

    if( environment() ) {
             message("sound", "\nÁé¼ªÆĞÈøÒ¡Í·Ì¾µÀ£º´ó·¨Î´ÕÃ£¬¹éÈ¥¹éÈ¥,°¢ÃÖÍÓ·ğ£¡\n\n", environment());
             command("sigh");
             message("sound", "\nÁé¼ªÆĞÈøÔ¾ÉÏ°Ë×¦½ğÁú£¬¼ÜÏéÔÆ¶øÍùÎ÷·½È¥ÁË¡£¡£¡£\n\n", environment());
    inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++)
              {
	     if (inv[i]->query("no_drop")) continue;
                 inv[i]->move(environment(me));
	   }
          }
      destruct(me);
 }

void unconcious()
{
	die();
}

void announce_success (object who)
{
  int i;
  object zhu;
  if (who->query("combat_exp") < 100000)
   {
     message_vision("°ë¿ÕÖĞ£¬Áé¼ªÆĞÈø¶Ô×Å$NÌ¾ÁË¿ÚÆø£¬µÀĞĞ²»¹»£¬ÒàÊÇÍ÷È»£¡\n",who);
     return;
   }
  if (who->query("obstacle/huangfeng") == "done")
       return;
  if (who->query_temp("obstacle/huangfeng_zhu_getted")==0)
    return;
  if( !(zhu = present("dingfeng zhu", who)) ) 
       return;
  if (who->query_temp("obstacle/huangfeng_huangfengguai_killed")==0)
    return;
  i = random(500);
  message_vision("°ë¿ÕÖĞ£¬Áé¼ªÆĞÈø°ÑÊÖÒ»ÕĞ£¬¶¨·çÖé´Ó$NÉíÉÏÆÆ¿Õ¶øÈ¥£¬ÎÈÎÈµÄ¶¨ÔÚÆĞÈøµÄÊÖÖĞ¡£\n",who);
   destruct(zhu);
  who->delete_temp("obstacle/huangfeng_zhu_getted");
  who->add("obstacle/number",1);
  who->set("obstacle/huangfeng","done");
  who->add("combat_exp",i+4000);
  command("chat "+who->query("name")+"»Æ·çÁë½µ·ş»Æ·ç¹Ö£¬Îª·ğ×æÑ°»Ø¶¨·çÖé£¡");
message("channel:chat",HIY"¡¾¹ı¹ØÕ¶½«¡¿¹ÛÒôÆĞÈø(guanyin pusa)£º"+who->query("name")+"´³¹ıÎ÷ĞĞÈ¡¾­[1;37mµÚÁù¹Ø£¡\n"NOR,users());//this is by tianlin 2001.5.8
  tell_object (who,"ÄãÓ®µÃÁË"+chinese_number(4)+"Äê"+
               chinese_number(i/4)+"Ìì"+
               chinese_number((i-(i/4)*4)*3)+"Ê±³½µÄµÀĞĞ£¡\n");
  who->save();
}

