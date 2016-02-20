#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"圣殿五层"NOR);
        set("long", @LONG
这里已是圣殿的五层了,不知还要走多久才能到头,虽是在屋
里面,但也感到有些高处不胜寒的意思。这里的空气也渐渐
有些稀薄了，道行不高的人还是不要轻易前进的好。
LONG
        );
        set("exits", ([
                "up" : __DIR__"shengdian6",
                "down" : __DIR__"shengdian4",
                "enter" : __DIR__"shenghan",
        ]) );
        set("coor/x",-1020);
        set("coor/y",-70);
        set("coor/z",-150);
        setup();
}

int valid_leave (object who, string dir)
{
  int to_die = who->query("daoxing") < 100000;

  to_die = 0;
  
  if (dir == "down")
    return 1;

  if (who->query("daoxing")>100000)
    return 1;

  switch (random(3))
  {
    case 0:
    {
      message_vision ("你只觉这里的空气实在少的可怜，一阵的昏天黑地的感觉向你袭来！\n\n",who);
      message_vision ("$N勉强走了几步，摔倒在地。\n",who);
      who->unconcious();

      if (to_die)
      {
        who->delete_temp("last_damage_from");
        who->set_temp("death_msg","因为缺氧死掉了。");
        who->die();
        who->save();
      }

      break;
    }
    case 1:
    {
      message_vision ("感到浑身不自在，也不知是那里出了问题！\n\n",who);
      message_vision ("$N勉强走了几步，摔倒在地。\n",who);
      who->unconcious();
      if (to_die)
      {
        who->delete_temp("last_damage_from");
        who->set_temp("death_msg","在灵界被活活憋死了。");
        who->die();
        who->save();
      }
      break;
    }
    case 2:
    {
      message_vision ("果然是高处不胜寒呀，哎！\n\n",who);
      message_vision ("$N勉强走了几步，摔倒在地。\n",who);
      who->unconcious();
      if (to_die)
      {
        who->delete_temp("last_damage_from");
        who->set_temp("death_msg","被寒气活埋了。");
        who->die();
        who->save();
      }
      break;
    }
  }  
  if (!to_die)
    call_out ("moving",1,who);
  //return notify_fail("你一阵地转天旋……\n");
  return ::valid_leave(who, dir);
}

void moving (object who)
{
  who->move(__DIR__"shengdian3");        
}

