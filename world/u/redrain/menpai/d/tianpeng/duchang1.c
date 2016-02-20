//by mhsj@gslxz /2001/7/31
inherit ROOM;

int room_status = 0;
int *res = allocate(5);

int random2 (int i)
{
  return (random(i)+uptime()) % i;
}

mapping qians = ([ 
  "dqq" : "[1;33m´óÇ¬Ç©[2;37;0m",
  "dkq" : "[37m´óÀ¤Ç©[2;37;0m",
  "xqq" : "[1;35mĞ¡Ç¬Ç©[2;37;0m",
  "xkq" : "[35mĞ¡À¤Ç©[2;37;0m",
  "qq"  : "[1;31mÇ¬Ç©[2;37;0m",
  "kq"  : "[31mÀ¤Ç©[2;37;0m",
 ]); 

void create()
{
  set ("short", "ÑºÇ©·¿");
  set ("long", @LONG

Ò»ÈºÈËÎ§×Å×ÏÌ´Ä¾´ó×À¶ø×ø£¬Ê×Ï¯×ù×ÅÒ»Î»Ç©·¿Ğ¡Í¯£¬ÕıÔÚÒ»±¾Õı
¾­µØ´ÓÏâ½ğºÚºĞÀïÂıÓÆÓÆÒ»¸ùÒ»¸ùÍùÍâ³é³öÇ¬À¤Ç©£¬ÂëÔÚ×ÀÃæÉÏ¡£

Ç½ÉÏÓĞÒ»ØÒĞ´×Å£º
    [1;33m´óÇ¬Ç©[2;37;0m[33m£¨È«²¿Îå¸ù½ÔÎªÇ¬Ç©£©£ºÒ»Ó®ÈıÊ®¶ş[2;37;0m
    [37m´óÀ¤Ç©[33m£¨È«²¿Îå¸ù½ÔÎªÀ¤Ç©£©£ºÒ»Ó®ÈıÊ®¶ş[2;37;0m
    [1;35mĞ¡Ç¬Ç©[2;37;0m[33m£¨Á¬ĞøËÄ¸ù½ÔÎªÇ¬Ç©£©£ºÒ»Ó®Ê®Áù[2;37;0m
    [35mĞ¡À¤Ç©[33m£¨Á¬ĞøËÄ¸ù½ÔÎªÀ¤Ç©£©£ºÒ»Ó®Ê®Áù[2;37;0m
      [1;31mÇ¬Ç©[2;37;0m[33m£¨ÈÎÒâÈı¸ù½ÔÎªÇ¬Ç©£©£ºÒ»Ó®¶ş[2;37;0m
      [31mÀ¤Ç©[33m£¨ÈÎÒâÈı¸ù½ÔÎªÀ¤Ç©£©£ºÒ»Ó®¶ş[2;37;0m

ØÒ½ÇÓĞÒ»¸öÅÆ×Ó[1;31m(paizi)[2;37;0m¡£

LONG);

  set("item_desc",([
    "paizi" : "Ñº[1;33m´óÇ¬Ç©[2;37;0m£º qian dqq <amount> <money>\n"+ 
              "Ñº[37m´óÀ¤Ç©[2;37;0m£º qian dkq <amount> <money>\n"+ 
              "Ñº[1;35mĞ¡Ç¬Ç©[2;37;0m£º qian xqq <amount> <money>\n"+ 
              "Ñº[35mĞ¡À¤Ç©[2;37;0m£º qian xkq <amount> <money>\n"+ 
              "Ñº[1;31mÇ¬Ç©[2;37;0m£º   qian qq <amount> <money>\n"+ 
              "Ñº[31mÀ¤Ç©[2;37;0m£º   qian kq <amount> <money>\n",
  ])); 
  set("exits", ([ /* sizeof() == 1 */
      "eastdown" : __DIR__"pianting",
  ]));
  set("objects", ([ /* sizeof() == 1 */
    __DIR__"npc/qianke" : 1,
  ]));
  set("light_up", 1);
  set("no_fight", 1);
  set("no_magic", 1);
  setup();
}

void init ()
{
  add_action ("do_qian","qian");
   add_action("do_quit","fly");
    add_action("do_quit","exit");

  add_action("do_quit","quit");  

  if (room_status > 0)
    return;

  remove_call_out ("gamble_prepare");
  remove_call_out ("gamble_start");
  remove_call_out ("gamble_perform");
  remove_call_out ("gamble_finish");
  call_out ("gamble_prepare",2);
  room_status = 1;
}
  int do_quit(string arg)
  {
  write(this_player()->query("name")+"[5m[31m£¬Äã¸ÉÊ²Ã´£¬ÓÃBUGÄª£¬ÕâÀïÖ»¿ÉÒÔ¶Ä²©£¡[2;37;0m\n");
  return 1;
  }

int do_qian (string arg)
{
  object me = this_player();
  string what;
  int amount;
  string money;
  object ob;

  if (! arg ||
      sscanf (arg,"%s %d %s",what,amount,money) != 3)
    return notify_fail("[1;33mÇëÊ¹ÓÃ£º[41m qian <ÑºÇ©ÖÖÀà> <ÊıÄ¿> <»õ±Ò> [2;37;0m\n");

  if (what != "dqq" &&
      what != "dkq" &&
      what != "xqq" &&
      what != "xkq" &&
      what != "qq" &&
      what != "kq")
    return notify_fail("ÄãÒªÑºÊ²Ã´Ç©£¿\n");

  ob = present (money+"_money", me);
  if (! ob)
    return notify_fail("ÄãÉíÉÏÃ»ÓĞÕâÖÖ»õ±Ò¡£\n");
  if (amount < 1)
    return notify_fail("Çë¶àÑºÒ»Ğ©Ç®¡£\n");
  if (amount > ob->query_amount())
    return notify_fail("ÄãÉíÉÏµÄÇ®²»¹»Ñº¡£\n");

  if (me->query_temp ("gamble_qian/amount") > 0)
    return notify_fail("ÄãÒÑ¾­Ñº¹ıÁË¡£\n");

  if (room_status > 1)
    return notify_fail("ÏÖÔÚÕıÔÚ¶ÄÄØ£¬ÉÔµÈÆ¬¿Ì¡£\n");

  me->set_temp("gamble_qian/kind",what);
  me->set_temp("gamble_qian/amount",amount);
  me->set_temp("gamble_qian/money",money);
  message_vision (sprintf("$NÄÃ³ö%s%s%s£¬ÑºÔÚ%sÉÏ¡£\n",
                          chinese_number(amount),
                          ob->query("base_unit"),
                          ob->query("name"),
                          qians[what]),
                  me);
  if (amount == ob->query_amount())
    destruct (ob);
  else
    ob->add_amount(-amount);

  return 1;
}

int valid_leave(object me, string dir)
{
  if (dir == "eastdown")
  {
    if (me->query_temp ("gamble_qian/amount") > 0) 
      message_vision ("$NÈÓÏÂÑºÇ©µÄÇ®¡£\n",me);
    me->delete_temp("gamble_qian");
  }
  return ::valid_leave(me,dir);
}

void gamble_prepare ()
{
  object room = this_object();
  object *inv;
  int i;

  tell_room (room,"½ø±¦½«Ò»´óÊøÇ©ÔÚ×ÀÉÏ»©À²À²µØÑ¸ËÙÏ´ÁËÒ»±é¡£\n");
  tell_room (room,"Ï´Ç©Ö®ºó£¬½ø±¦Å¾µØÒ»Éù½«Ç©×°ÈëÏâ½ğºÚºĞ£¬½ĞµÀ£º¿ªÑº£¡\n");
  
  inv=all_inventory();
  i=sizeof(inv);
  while(i--) {
      if(userp(inv[i])) {
         room_status = 1;
         call_out ("gamble_start",25);
	 return;
      }
  }
  room_status=0;
  return;
}
 
void gamble_start ()
{
  object room = this_object();
  tell_room (room,"½ø±¦º°Éù£ºÍ£Ñº£¡\n");
  tell_room (room,"È»ºó±ÕÉÏÑÛ¾¦£¬½«Ïâ½ğºÚºĞ´ò¿ª´ÓÀï¿ªÊ¼ÍùÍâ³éÇ©¡£\n");
  room_status = 2;
  call_out ("gamble_perform",3,0);
  call_out ("gamble_perform",6,1);
  call_out ("gamble_perform",9,2);
  call_out ("gamble_perform",12,3);
  call_out ("gamble_perform",15,4);
  call_out ("gamble_finish",18);
}

void gamble_perform (int i)
{
  object room = this_object();

  switch (random2(2))
  {
    case 0:
    {
      tell_room (room,"\n[33m¡õ¡õ  À¤  Ç©  ¡õ¡õ[2;37;0m\n");
      res[i] = 0;
      break;
    }
    case 1:
    {
      tell_room (room,"\n[37m¡õ¡õ  Ç¬  Ç©  ¡õ¡õ[2;37;0m\n");
      res[i] = 1;
      break;
    }
  }
}

void player_wins (object who, int total)
{
  object money = new ("/obj/money/"+who->query_temp("gamble_qian/money"));
  int amount = who->query_temp("gamble_qian/amount");
  total = total * amount;
  money->set_amount(total);
  message_vision (sprintf("$NÓ®ÁË%s%s%s£¡\n",
                          chinese_number(total),
                          money->query("base_unit"),
                          money->query("name")),
                  who);
  money->move(who);
}

void player_loses (object who, int total)
{
  object money = new ("/obj/money/"+who->query_temp("gamble_qian/money"));
  total = who->query_temp("gamble_qian/amount");
  message_vision (sprintf("½ø±¦½«$NÑºÔÚÅÌÖĞµÄ%s%s%sÊÕ×ß¡£\n",
                          chinese_number(total),
                          money->query("base_unit"),
                          money->query("name")),
                  who);
  destruct (money);
}

void gamble_finish ()
{
  string win;
  int total, i;
  object room = this_object();
  object *list = all_inventory(room);
  if (res[0]==1 && res[1]==1 && res[2]==1 && res[3]==1 && res[4]==1)
  {
    total = 32;
    win = "dqq";
  }
  else if (res[0]==0 && res[1]==0 && res[2]==0 && res[3]==0 && res[4]==0)
  {
    total = 32;
    win = "dkq";
  }
  else if ((res[0]==1 && res[1]==1 && res[2]==1 && res[3]==1) ||
           (res[1]==1 && res[2]==1 && res[3]==1 && res[4]==1))
  {
    total = 16;
    win = "xqq";
  }
  else if ((res[0]==0 && res[1]==0 && res[2]==0 && res[3]==0) ||
           (res[1]==0 && res[2]==0 && res[3]==0 && res[4]==0))
  {
    total = 16;
    win = "xkq";
  }
  else 
  {
    int r = 0;
    total = 2;
    for (i = 0; i < 5; i++)
      r += res[i];
    if (r >= 3)
      win = "qq";
    else
      win = "kq";
  }
  tell_room (room,"\n½ø±¦Õö¿ªÑÛ¾¦£¬Ñ¸ËÙ¿´Ò»ÑÛ×ÀÃæ£¬½ĞµÀ£º"+qians[win]+"£¡\n");
  i = sizeof(list);
  while (i--)
  {
    if (!userp(list[i]))
      continue;
    if (list[i]->query_temp("gamble_qian/kind") == win)
      player_wins(list[i],total);
    else if (list[i]->query_temp("gamble_qian/kind"))
      player_loses(list[i],total);
    list[i]->delete_temp("gamble_qian");
  }
  tell_room (room,"\n");
  call_out ("gamble_prepare",5);
}
