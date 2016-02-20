// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */

// Room: /d/4world/center.c
inherit ROOM;

void create ()
{
  set ("short", "[37m°Ë°ÙÀïÌìºÓ[m");
  set ("long", @LONG
Õâ¾ÍÊÇ°Ë°ÙÀïÌìºÓÁË,¹ûÈ»ÊÇºÆºÆµ´µ´,Ò»ÍûÎÞ¼Ê.
ºÓ±ßµÄË®²ÝÉõÊÇ·áÊ¢,Äã²»ÓÉµØÏë°ÑÂí·Å(fang)³ö
È¥.
LONG);
  set("exits", ([
  "east" : __DIR__"xitian",
]));

  setup();
}
void init()
{
    add_action("do_fang", "fang");
    set("no_clean_up", 0);
        setup();
}

int do_fang(string arg)
{
        object me, ob, a, b;
        me=this_player();
        if ( !arg || ((arg != "horse") ))
                return notify_fail("ÄãÒª°ÑÊ²Ã´·Å³öÈ¥£¿\n");
  if ( !present("tian-ma", this_player()) )
     return notify_fail("ÄãÉíÃ»´øÌìÂí,·ÅÊ²Ã´·Å°¡!!\n");
  if(objectp(a=present("tianpeng yuanshuai", environment(me))))
  return notify_fail("ÌìÅîÔªË§´óºÈÒ»Éù:Ð¡Ôô,¿´¼û±¾Ë§À´ÁË»¹¸ÒÍµÎÒµÄË®²Ý!!\n");
  if(!me->query_temp("marks/Æï"))
  return notify_fail("Äã»¹Ã»È¥ÆïÉÏÌìÂí,ÔõÃ´ÄÜ°ÑËü·Å³öÈ¥ÄØ!!!\n");
//  if(!me->query_temp("give_horse"))
//  return notify_fail("ÕâÂí¿ÖÅÂ²»ÊÇÄã×Ô¼ºÈ¥ÓùÂí¼àÒªµÄ°É!!\n");
  message_vision("$NÏÂÁËÂí,°ÑÂíÇ£µ½ºÓ±ß,ÈÃËü×ÔÐÐ³Ô²Ý¡£\n",me);
  message_vision("Ö»Ìý¼û»©À²À²Ò»ÉùË®Ïì,ÌìºÓÖÐ×ê³öÁË¼¸ÌõÈËÓ°!!\n",me);
  me->delete_temp("marks/Æï",1);
  ob=present("tianpeng yuanshuai");
     if( !ob) {
  seteuid(getuid());
  ob=new("/d/sky/npc/zhu");
}
  ob->move(__DIR__"river");
   return 1;
}
