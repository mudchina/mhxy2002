//by mhsj@gslxz /2001/7/31
inherit ROOM;

int room_status = 0;
int *big = allocate(2);
int *res = allocate(2);

int random2 (int i)
{
  return (random(i)+uptime()) % i;
}

mapping gutous = ([ 
  "tc" : "[1;33mÍ·²Ê[2;37;0m",
  "sd" : "[37mË«¶Ô[2;37;0m",
  "qx" : "[1;31mÆßĞÇ[2;37;0m",
  "sx" : "[31mÉ¢ĞÇ[2;37;0m",
 ]); 

void create()
{
  set ("short", "¹Ç÷»·¿");
  set ("long", @LONG

ÕâÀï°Ú×ÅÒ»¸ö°ËÏÉ×À£¬ÖĞ¼ä°Ú×ÅÒ»¸öÒøÅÌ¡£¶Ä¿ÍÃÇÕı¾Û¾«»áÉñµØÏÂ¶Ä¡£
ÕıÏ¯ÊÇÒ»Î»ÅÖ×Ó£¬ÊÖÀï²»¶ÏÍæÅª×ÅÒ»¶ÔÓñ÷»£¬Ëû¾ÍÊÇÕâÀïµÄÕĞ²Æ¡£

Ç½ÉÏ¹ÒÓĞÒ»¸öØÒ£¬ÉÏÃæĞ´×Å£º
    [1;33mÍ·²Ê[2;37;0m[33m£¨÷»ÊıÓÉÃ¿´Î¿ªÅÌÇ°È·¶¨£©      £ºÒ»Ó®ÈıÊ®Áù[2;37;0m
    [37mË«¶Ô[33m£¨Á½÷»ºÅÏàÍ¬£¬ÇÒÎªÅ¼Êı£©      £ºÒ»Ó®Ê®¶ş[2;37;0m
    [1;31mÆßĞÇ[2;37;0m[33m£¨Á½÷»Ö®ºÍÎªÆß£©              £ºÒ»Ó®Áù[2;37;0m
[31m    É¢ĞÇ[33m£¨Á½÷»Ö®ºÍÎªÈı£¬Îå£¬¾Å£¬Ê®Ò»£©£ºÒ»Ó®Èı[2;37;0m

ØÒ½ÇÓĞÒ»¸öÅÆ×Ó[1;31m(paizi)[2;37;0m¡£

LONG);

  set("item_desc",([
    "paizi" : "Ñº[1;33mÍ·²Ê÷»[2;37;0m£º gutou tc <amount> <money>\n"+ 
              "Ñº[37mË«¶Ô÷»[2;37;0m£º gutou sd <amount> <money>\n"+ 
              "Ñº[1;31mÆßĞÇ÷»[2;37;0m£º gutou qx <amount> <money>\n"+ 
              "Ñº[31mÉ¢ĞÇ÷»[2;37;0m£º gutou sx <amount> <money>\n" 
  ])); 
  set("objects", ([ /* sizeof() == 1 */
    __DIR__"npc/zhuangd" : 1,
  ]));
  set("exits", ([ /* sizeof() == 1 */
      "westdown" : __DIR__"pianting",
  ]));
  set("light_up", 1);
  set("no_fight", 1);
  set("no_magic", 1);
  setup();
}

void init ()
{
  add_action ("do_gutou","gutou");
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

int do_gutou (string arg)
{
  object me = this_player();
  string what;
  int amount;
  string money;
  object ob;

  if (! arg ||
      sscanf (arg,"%s %d %s",what,amount,money) != 3)
    return notify_fail("ÇëÊ¹ÓÃ£º gutou <Ñº÷»ÖÖÀà> <ÊıÄ¿> <»õ±Ò>\n");

  if (what != "tc" &&
      what != "sd" &&
      what != "qx" &&
      what != "sx")
    return notify_fail("ÄãÒªÑºÊ²Ã´÷»£¿\n");

  ob = present (money+"_money", me);
  if (! ob)
    return notify_fail("ÄãÉíÉÏÃ»ÓĞÕâÖÖ»õ±Ò¡£\n");
  if (amount < 1)
    return notify_fail("Çë¶àÑºÒ»Ğ©Ç®¡£\n");
  if (amount > ob->query_amount())
    return notify_fail("ÄãÉíÉÏµÄÇ®²»¹»Ñº¡£\n");

  if (me->query_temp ("gamble_gutou/amount") > 0)
    return notify_fail("ÄãÒÑ¾­Ñº¹ıÁË¡£\n");

  if (room_status > 1)
    return notify_fail("ÏÖÔÚÕıÔÚ¶ÄÄØ£¬ÉÔµÈÆ¬¿Ì¡£\n");

  me->set_temp("gamble_gutou/kind",what);
  me->set_temp("gamble_gutou/amount",amount);
  me->set_temp("gamble_gutou/money",money);
  message_vision (sprintf("$NÄÃ³ö%s%s%s£¬ÑºÔÚ%sÉÏ¡£\n",
                          chinese_number(amount),
                          ob->query("base_unit"),
                          ob->query("name"),
                          gutous[what]),
                  me);
  if (amount == ob->query_amount())
    destruct (ob);
  else
    ob->add_amount(-amount);

  return 1;
}

int valid_leave(object me, string dir)
{
  if (dir == "westdown")
  {
    if (me->query_temp ("gamble_gutou/amount") > 0) 
      message_vision ("$NÈÓÏÂÑº÷»µÄÇ®¡£\n",me);
    me->delete_temp("gamble_gutou");
  }
  return ::valid_leave(me,dir);
}

void display_gutou (object room, int i)
{
  string str;
  switch (i)
  {
    case 1:
    {
      str = 
"[37m©°©¤©¤©¤©´[2;37;0m\n"+
"[37m©¦¡¡¡¡¡¡©¦[2;37;0m\n"+
"[37m©¦¡¡[1;31m¡ñ[2;37;0m[37m¡¡©¦[2;37;0m\n"+
"[37m©¦¡¡¡¡¡¡©¦[2;37;0m\n"+
"[37m©¸©¤©¤©¤©¼[2;37;0m\n";

      break;
    } 
    case 2:
    {
      str = 
"[37m©°©¤©¤©¤©´[2;37;0m\n"+
"[37m©¦¡¡¡¡¡¡©¦[2;37;0m\n"+
"[37m©¦[1;31m¡ñ¡¡¡ñ[2;37;0m[37m©¦[2;37;0m\n"+
"[37m©¦¡¡¡¡¡¡©¦[2;37;0m\n"+
"[37m©¸©¤©¤©¤©¼[2;37;0m\n";
      break;
    } 
    case 3:
    {
      str =
"[37m©°©¤©¤©¤©´[2;37;0m\n"+
"[37m©¦[1;31m¡ñ[2;37;0m[37m¡¡¡¡©¦[2;37;0m\n"+
"[37m©¦[1;31m¡¡¡ñ[2;37;0m[37m¡¡©¦[2;37;0m\n"+
"[37m©¦¡¡[1;31m¡¡¡ñ[2;37;0m[37m©¦[2;37;0m\n"+
"[37m©¸©¤©¤©¤©¼[2;37;0m\n";
      break;
    } 
    case 4:
    {
      str = 
"[37m©°©¤©¤©¤©´[2;37;0m\n"+
"[37m©¦[1;31m¡ñ¡¡¡ñ[2;37;0m[37m©¦[2;37;0m\n"+
"[37m©¦¡¡¡¡¡¡©¦[2;37;0m\n"+
"[37m©¦[1;31m¡ñ¡¡¡ñ[2;37;0m[37m©¦[2;37;0m\n"+
"[37m©¸©¤©¤©¤©¼[2;37;0m\n";
      break;
    } 
    case 5:
    {
      str =
"[37m©°©¤©¤©¤©´[2;37;0m\n"+
"[37m©¦[1;31m¡ñ¡¡¡ñ[2;37;0m[37m©¦[2;37;0m\n"+
"[37m©¦[1;31m¡¡¡ñ[2;37;0m[37m¡¡©¦[2;37;0m\n"+
"[37m©¦[1;31m¡ñ¡¡¡ñ[2;37;0m[37m©¦[2;37;0m\n"+
"[37m©¸©¤©¤©¤©¼[2;37;0m\n";
      break;
    } 
    case 6:
    {
      str = 
"[37m©°©¤©¤©¤©´[2;37;0m\n"+
"[37m©¦[1;31m¡ñ¡¡¡ñ[2;37;0m[37m©¦[2;37;0m\n"+
"[37m©¦[1;31m¡ñ¡¡¡ñ[2;37;0m[37m©¦[2;37;0m\n"+
"[37m©¦[1;31m¡ñ¡¡¡ñ[2;37;0m[37m©¦[2;37;0m\n"+
"[37m©¸©¤©¤©¤©¼[2;37;0m\n";
      break;
    } 
  }
  tell_room (room,str);
}

int rdm()
{
  return random2(6)+1;
}

void gamble_prepare ()
{
  object room = this_object();
  tell_room (room,"ÕĞ²Æ³ªµÀ£ºĞÂ¿ªÅÌ£¡Ô¤½ĞÍ·²Ê£¡\n");
  tell_room (room,"ÕĞ²Æ½«Á½Ã¶Óñ÷»ÍùÒøÅÌÖĞÒ»Èö¡£\n");
  big[0] = rdm();
  big[1] = rdm();
  // keep two numbers different for a probability == 1/36
  while (big[0] == big[1])
  {
    reset_eval_cost();
    big[1] = rdm();
  }
  display_gutou (room,big[0]);
  display_gutou (room,big[1]);
  tell_room (room,"ÕĞ²Æ½ĞµÀ£ºÍ·²Ê÷»ºÅ"+chinese_number(big[0])+
                  chinese_number(big[1])+"£¡\n");
  tell_room (room,"½Ó×ÅÕĞ²ÆÂéÀûµØË³ÊÖ½«Óñ÷»´ÓÅÌÖĞÊÕ»Ø£ºÏÖÔÚ¿ªÅÌÑºÇ®£¡\n");
  room_status = 1;
  call_out ("gamble_start",24);
}
 
void gamble_start ()
{
  object room = this_object();
  tell_room (room,"ÕĞ²Æº°Éù£º·âÅÌÍ£Ñº£¡\n");
  tell_room (room,"ÓÖ²¹µÀ£º±¾ÅÌÍ·²Ê÷»ºÅÊÇ"+chinese_number(big[0])+
                  chinese_number(big[1])+"¡£\n");
  tell_room (room,"È»ºó½«Á½Ã¶Óñ÷»ÈÓ½øÁ½¸ö½ğÖÑ£¬Ò»ÊÖ³ÖÒ»ÖÑÒ¡½«ÆğÀ´¡£\n");
  room_status = 2;
  call_out ("gamble_perform",6,0);
  call_out ("gamble_perform",12,1);
  call_out ("gamble_finish",18);
}

void gamble_perform (int i)
{
  object room = this_object();

  tell_room (room,"½ğÖÑµ¹¿ÛÔÚÒøÅÌÉÏ£¬Óñ÷»¹öÁË³öÀ´¡£\n");
  res[i] = rdm();
  display_gutou (room,res[i]);
}

void player_wins (object who, int total)
{
  object money = new ("/obj/money/"+who->query_temp("gamble_gutou/money"));
  int amount = who->query_temp("gamble_gutou/amount");
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
  object money = new ("/obj/money/"+who->query_temp("gamble_gutou/money"));
  total = who->query_temp("gamble_gutou/amount");
  message_vision (sprintf("ÕĞ²Æ½«$NÑºÔÚÒøÅÌÖĞµÄ%s%s%sÊÕ×ß¡£\n",
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
  if (res[0]==big[0] && res[1]==big[1])
  {
    total = 36;
    win = "tc";
  }
  else if (res[0]==res[1] && (res[0]/2*2 == res[0]))
  {
    total = 12;
    win = "sd";
  }
  else 
  {
    int r = res[0]+res[1];
    if (r==7)
    {
      total = 6;
      win = "qx";
    }
    else if (r==3 || r==5 || r==9 || r==11) 
    {
      total = 3;
      win = "sx";
    }
    else
    {
      total = 0;
      win = "none of them";
    }
  }
  if (total == 0)
    tell_room (room,"ÕĞ²Æ½ĞµÀ£º"+chinese_number(res[0])+
                    chinese_number(res[1])+"¡­¡­¿ÕÅÌ£¡\n");
  else
    tell_room (room,"ÕĞ²Æ½ĞµÀ£º"+chinese_number(res[0])+
                    chinese_number(res[1])+"¡­¡­"+gutous[win]+"£¡\n");
  i = sizeof(list);
  while (i--)
  {
    if (!userp(list[i]))
      continue;
    if (list[i]->query_temp("gamble_gutou/kind") == win)
      player_wins(list[i],total);
    else if (list[i]->query_temp("gamble_gutou/kind"))
      player_loses(list[i],total);
    list[i]->delete_temp("gamble_gutou");
  }
  tell_room (room,"\n");
  if(sizeof(filter_array(all_inventory(this_object()), (:userp:))))
  call_out ("gamble_prepare",5);
  else
  room_status=0;
}
