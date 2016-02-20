//paimaiwu.c by litchi

inherit ROOM;

void create ()
{
        set ("short", "福威镖局");
        set ("long", @LONG

福威镖局。

在这里可以押镖
命令：
   要任务: ask lin about job
   赶镖车: gan che to 方向
   完成任务后回来 ask lin about over 
   如果你实在完不成任务。。。只好赔给他50两黄金了：（

LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
          "southwest" : "/d/city/dongmen",
        ]));
        set("objects", 
        ([ //sizeof() == 1
                "/u/tianlin/quest/biao/linzhennan":1,
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
//      replace_program(ROOM);
}

void init()
{
  add_action("do_fight", "fight");
  add_action("do_kill", "kill");
  add_action("do_steal", "steal");
  add_action("do_cast", "cast");
  add_action("do_ji","ji");
  add_action("do_throw","throw");
  add_action("do_list","list");
  add_action("do_yao","yao");
}

void die()
{
 return;
}

int do_fight(string arg)
{
  object who = this_player();
  object me = this_object();

  if (arg && present(arg,environment(who))==me)
  {
        message_vision("$N看样子想打架，但林镇南轻身飘开,剩下$N楞楞的站在那里。\n",who);
     return 1;
  }
  return 0;
}

int do_kill(string arg)
{
  object who = this_player();
  object me = this_object();

  if (arg && present(arg,environment(who))==me)
  {
message_vision("$N看样子想杀死林镇南，但林镇南是小学毕业,没跟$N一般见识。\n",who);

    return 1;
  }
  return 0;
}

int do_cast(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision("$N对着林镇南结结巴巴的念了几句咒语，自己都感觉难听死了。\n",who);

  return 1;
}
int do_steal(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision("$N想偷东西，但总是有贼心没贼胆。\n",who);

  return 1;
}


int do_ji(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision("$N想祭法宝，前思后想，还是没敢。\n",who);

  return 1;
}

int do_throw(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision("$N掏出暗器，看了看林镇南，信心不足，又把暗器收了起来。\n",who);

  return 1;
}
