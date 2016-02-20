//by tianlin 2001/5/1
//By tianlin@mhxy for 2001.12.29´ÓÐÂÐÞ¸Ä
#include <ansi.h>
inherit ITEM;
int do_open(string arg);
void create()
{
  set_name(HIR "ÀñÎï" NOR,({"gift"}));
  set("long","ÕâÊÇÒ»·ÝÀñÎï£¬Äã¿ÉÒÔÊÔ×Å´ò¿ª("+HIG+"open"+NOR+")À´¿´¿´¡£");
  set("unit","·Ý");
  set("value", 0);
  setup();
}

void init()
{
   if (!wizardp(this_player())) {
    set("no_get","Õâ¸ö¶«Î÷ÄÃ²»ÆðÀ´¡£\n");
    set("no_give","ÕâÃ´Õä¹óµÄ¶«Î÷£¬ÄÄÄÜËæ±ã¸øÈË£¿\n");
    set("no_drop","ÕâÃ´±¦¹óµÄ¶«Î÷£¬ÈÓÁË¶à¿ÉÏ§Ñ½£¡\n");
    set("no_sell","Õâ¶«Î÷²»ÄÜÂô¡£\n");
   }
    if(this_player()==environment())
  add_action("do_open", "open");

}

int do_open(string arg)
{
  object yudi;
  object obj;
  object guai,bi,bonnet;
  object me=this_player();
  if (!arg && arg!="liwu") return notify_fail("ÄãÒª´ò¿ªÊ²Ã´?\n");
  if (me->query("newbie_liwu")) return notify_fail("ÄãÒÑ¾­ÄÃ¹ýÀñÎïÁË£¬ÔõÃ´»¹ÏëÒª£¿\n");
  message_vision(HIG"$N°ÑÀñÎïºÐÇáÇáµÄ´ò¿ª£¬Ò»µÀ¹âÃ¢´ÓÌì¶ø½µ£¬$N±»Õâ¹âÃ¢°ü×¡£¬$N¾õµÃ»ëÉí³äÂúÁËÁ¦Á¿!\n" NOR,me);

  me->add("potential",100000); 
  me->add("combat_exp",80000); 
  me->add("daoxing",16000); 
  me->add("force",400);
  me->add("max_force",400);
  me->add("max_mana",400);
  me->add("mana",400);
  me->add("maximum_force",400);
  me->add("maximum_mana",400);
  me->add("bellicosity",100); 
  me->add("rsg_eaten",16);  
  me->add("faith",500);  
  me->add("weiwang",100);  
 // me->set_skill("force",40);
//  me->set_skill("dodge",40);
//  me->set_skill("parry",40);
 // me->set_skill("sword",60);
 // me->set_skill("staff",60);
 // me->set_skill("spells",40);
 // me->set_skill("stick",60);
//  me->set_skill("unarmed",60);
//  me->set_skill("literate",40);
 // me->set_skill("archery",60);
//  me->set_skill("rake",60);
 // me->set_skill("whip",60);
 // me->set_skill("zouxiao",60);
//  me->set_skill("axe",60);
 // me->set_skill("mace",60);
 // me->set_skill("spear",60);
 // me->set_skill("throwing",60);
//  me->set_skill("blade",60);
 // me->set_skill("fork",60);
 // me->set_skill("hammer",60);
 // me->add("mud_age",86400);//¸øÍæ¼Ò¼ÓÉÏ1ÌìµÄmudage.by tianlin
  tell_object(me,HIW"Äã±»½±ÀøÁË£º\n" +
  chinese_number(80000) + "µãÊµÕ½¾­Ñé¡£\n"+        
  chinese_number(100000) + "µãÇ±ÄÜ¡£\n"+
  chinese_number(16)    + "ÄêµÀÐÐ¡£\n"+ 
  chinese_number(100) + "µãÉ±Æø¡£\n"+
  chinese_number(100) + "µãÃÅÅÉÍþÍû¡£\n"+
  chinese_number(500) + "µãÃÅÅÉÖÒ³Ï¶È¡£\n"+
  chinese_number(400) + "µãÄÚÁ¦¡£\n"+
  chinese_number(400) + "µã·¨Á¦¡£\n"+
 // chinese_number(5) + "ÖÖ»ù±¾¼¼ÄÜ¡£\n"+
  "Ê®Áù¸öÈË²Î¹û,ÇëÓÃscore2²é¿´£¡\n"NOR+BLINK+HBRED+HIW"ÒÔ¼°ÈýÖÖ·¨±¦!ÇëÕäÏ§Ê¹ÓÃ.\n" NOR);
 
  me->set("newbie_liwu",1);
  yudi = new("/d/dntg/sky/npc/yuhuang.c");
  yudi->command_function("rumor ÌýËµÒ»¸öÃû½Ð[37m"+me->name()+"[2;37;0m[1;35mµÄÈË£¬µÃµ½ÁË[1;33mÀñÎï°ü[2;37;0m[1;35m£¬¿ªÊ¼ÁËËûµÄÉúÑÄ...[2;37;0m\n");
  guai = new ("/u/tianlin/wuqi/gift/guai");
  guai->move(this_player());
  bi = new ("/u/tianlin/wuqi/gift/bi");
  bi->move(this_player());
  bonnet = new ("/u/tianlin/wuqi/gift/bonnet");
  bonnet->move(this_player());
  destruct(yudi);
  destruct(this_object());
  return 1;
}

