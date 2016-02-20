//【蜀山派】mhxy-yushu 2001/2
inherit ROOM;
void create ()
{
  set ("short","山涧");
  set ("long", @LONG

你拍了拍脑袋痛苦的爬起来，幸亏没有摔死，你向上面望了望，
看来是不可能爬(climb)上去的。只有往前走了。
LONG);

  set("exits", ([      
         "north" : __DIR__"shanjian2",
 ]));
 setup();
}

void init ()
{
  add_action ("do_climb","climb");
}

int do_climb (string arg)
{
  
  object who = this_player();
  message_vision("$N费力的向上爬去。。。\n",who);
  message_vision ("$N突然脚一滑跌下来了。。。。。\n",who);
  who->unconcious();
  return 1;
}






