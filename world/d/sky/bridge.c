// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
 
// Room: /d/qujing/wudidong/temple-qiandian.c
// created 6-20-97 pickle
inherit ROOM;

void create ()
{
  set ("short", "[37m°×ÓñÇÅ[m");
  set ("long", @LONG

Ò»×ùÓÃÉÏºÃµÄµá³Ø°×ÓñËùÔìµÄÐ¡ÇÅ,ÇÅÉíÈçºç,ÉÏÃæ»¹¿Ì×ÅÒ»Ð©
²»ÖªµÀÃèÊöÊ²Ã´µÄÍ¼»­.ÇÅµÄÁ½ÅÔÊÇÒ»ÌõÇå³ºµÄÐ¡ºÓ,ºÓÉÏÐÇÐÇµãµã
µØÉú×ÅÒ»Ð©²ÊÁ«,¼¸¶ÔÔ§ÑìÔÚºÓÖÐÓÆÏÐµÄÓÎ×Å,Å¼¶ûÒ²ÄÜ¿´¼ûÒ»Á½Ö»
ÏÉº×´ÓÇÅÉÏ·É¹ý,ÇÅµÄ±±Ãæ(north)¾ÍÊÇÁéÏö±¦µîÁË¡£
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "north" : "Ò»Ï®±ÌÂÌµÄÃÅÁ±£¬´¥Ö®±ùÁ¹£¬¿ÉÒÔÍµÍµ½Ò¿ª(jie)¿´¿´ÀïÃæµÄÄ£Ñù¡£
",
]));
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"nanmenting.c",
  "north" : __DIR__"dadian",
]));
  set("light_up", 1);

  setup();
}

void init()
{
  add_action("do_knock", "jie");
}

int do_knock()
{
  object me=this_player();
  string myrespect=(string)RANK_D->query_respect(me);

  if (me->query("obstacle/sky") != "done")
//   if (!me->query_temp("zhanyao_asked"))  
{
  
  message_vision("$NÇáÇáµÄ½Ò¿ª¹ÒÁ±£¬³¯ÀïÃæ¿´ÁË¿´¡£\n", me);
  message_vision("$N¼ûÃ»ÈË·¢ÏÖ£¬¾ÍÍµÍµµÄÁïÁË½øÈ¥£¬½ôÕÅµÄÁ³ÉÏÂ¶³öÒ»Ë¿Ð¦ÈÝ¡£\n", me);
  me->move(__DIR__"dianmen");
  return 1;
   }
  message_vision("$NÒ»°Ñ³¶ÏÂÁË¹ÒÁ±£¬´óºÈÒ»Éù£¬³åÁË½øÈ¥¡£\n",me);
  me->move(__DIR__"dianmen2");
  return 1;
}






