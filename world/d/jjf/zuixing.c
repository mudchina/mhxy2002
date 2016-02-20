// created 6-8-97 pickle
// Room: /d/jjf/zuixing.c
 
inherit ROOM;
 
void create ()
{
  set ("short", "×íÐÇÂ¥");
  set ("long", @LONG

Ì«×ÓÀî½¨³ÉºÍÈý×ÓÀîÔª¼ª¶Ô¸ß×æÓùÖ¼Æð÷è÷ë¸óÊ®·Ö²»Âú£¬ÈÏÎªÕâÊÇ¶Ô
ÇØÍõµÄÆ«°®¡£ÓÚÊÇ¶þÈËÇî¶þ¸®Ö®×Ê£¬ÔÚ÷è÷ë¸ó¶ÔÃæÔìÁËÒ»×ù¼°Æä»ªÀö
ºêÎ°µÄ²ÊÂ¥£¬Ãû[35m¡¸×íÐÇÂ¥¡¹[2;37;0m¡£ÎªÁËÎüÒý°ÙÐÕÇ°À´¹Û¿´£¬¶þÈËÉõÖÁ²»Ï§
·¢ËÍÊ³ÎïÇ®²Æ¡£
LONG);

  set("no_fight", 1);
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/qinbing-jian" : 1,
  __DIR__"npc/qinbing-qi" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/city/xuanwu-n0",
  "up" : __DIR__"zuixing2",
]));

  setup();
}
int valid_leave(object me, string dir)
{
  if(me->query("env/invisibility")) return ::valid_leave(me, dir);
  if(dir == "up" && objectp(present("qin bing", environment(me))))
    {
       if (member_array("qin bing",me->parse_command_id_list())==-1
          && member_array("qin bing",me->parse_command_id_list())==-1 )
         return notify_fail("Ç×±øºÈµÀ£ºÏÐÔÓÈËµÈ²»µÃÂÒ´³£¡\n");
    }
  return ::valid_leave(me, dir);
}

void init()
{
  add_action("do_kan", "kan3");
  add_action("do_kan", "¿³");
  add_action("do_kan", "chop");
}
int do_kan(string arg)
{
  object me=this_player(), here=this_object(), ob, zhuzi;
  int kar=me->query_kar();
 
  if( (!arg || arg != "Öù×Ó") && (arg != "zhuzi" && arg!="pillar"))
    return notify_fail("ÄãÒª´ÓÄÄÀïÏÂÊÖ£¿\n");
  if( !(ob = me->query_temp("weapon")) || (string)ob->query("skill_type") != "axe" )
    return notify_fail("Ã»Ë³ÊÖµÄ¼Ò»ïÔõÃ´²ðµÃ¶¯£¿\n");
 if(objectp(present("qin bing", environment(me))))
    return notify_fail("¿´Ñù×ÓÒªÏë²ðÂ¥£¬ÏÈµÃ°ÑÇ×±øÁÏÀíÁË£¡\n");
  if(!me->query_temp("mark/jjf×íÐÇÂ¥¶þÂ¥broken"))
    return notify_fail("»¹Ã»ÔÒ¶þÂ¥ÄØ£¬¾ÍÀ´´òÒ»Â¥µÄÖ÷Òâ£¿\n");
  here->add("pending/breakdown", 1);
  if (here->query("broken"))
    return notify_fail("Öù×Ó¶¼ËúÁË£¬»¹¿³Ê²Ã´¿³£¿ÒªÃüµÄ¿ì³öÈ¥°É£¡\n");
  message_vision("$NÓÃ×ãÁË¾¢£¬Ò»¸«ÂÕÏò²ÊÂ¥µÄÖù×Ó£¡Ö»¼û¼¸Æ¬Ä¾Æ¬ËÄÉ¢·É¿ª¡£\n", me);
  if (here->query("pending/breakdown") >= (int)(40 - kar)/5 )
    {
      message_vision("Ö»ÌýÒ»Éù¾ÞÏì£¬Ö§³Å·¿×ÓµÄÖù×Ó´ÓÖÐÕÛ¶Ï£¬Õû×ù×íÐÇÂ¥ËúÁËÏÂÀ´£¡\n", me);
      message_vision("$NËäÈ»¸ãµÃ»ÒÍ·ÍÁÁ³£¬µ«¾ÓÈ»Ã»ÓÐÊÜÉË£¡´óÃü²»ËÀ£¬»¹ÊÇ¸Ï½ô³öÈ¥°É£¡\n", me);
      here->set("long", @LONG

ÕâÀïÔø¾­ÊÇÒ»×ùºÀ»ªÆøÅÉµÄ²ÊÂ¥£¬µ«²»ÖªÎªºÎ±»ÈË²ðµôÁË£¬Ö»Ê£Ò»Æ¬
·ÏÐæ¡£¼¸¿éÀÃÄ¾Í·ÏÂÃæµ½´¦¶¼ÊÇ¾Æ±­Íë¿êµÄËéÆ¬¡£°ë½Ø±»¿³¶ÏµÄÖù×Ó
µ¹ÔÚÃÅ±ß¡£
LONG);
      me->delete_temp("mark/jjf×íÐÇÂ¥¶þÂ¥broken");
      here->set("broken", 1);
      here->set("outdoors", 1);
      zhuzi=new(__DIR__"obj/zhuzi");
      zhuzi->move(here);
      here->set("exits", ([ /* sizeof() == 1 */
  "west" : "/d/city/xuanwu-n0",
]));

    }
  me->receive_damage("kee", (int)me->query("max_kee")/4);
  return 1;
}
