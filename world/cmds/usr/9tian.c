//by tianlin@mhxy for 二零零一年八月十九日一点二十三分三十七秒 星期七
//局部修改

inherit F_CLEAN_UP;

#include <ansi.h>
#include <9tian.h>

int telling1 (object who);
int telling2 (object who);

string name;

int main(object me, string arg)
{
        object ob;

        if( !arg ) {
                ob = me;
                name = "你";
        } else if (wizardp (me)) {
                ob = find_player(arg);
                if(!ob) ob = find_living(arg);
                if(!ob) ob = LOGIN_D->find_body(arg);
                if(!ob || !me->visible(ob)) return notify_fail("没有这个人。\n");
                name = ob->query("name");
        } else
                return 0;

        telling1(ob);
        telling2(ob);

        return 1;
}

int help()
{
        write(@TEXT
指令格式：9tian <某人>

显示某人九重天的资料。 
请见：help 9tian
TEXT
        );
        return 1;
}

int telling1 (object who)
{
  int size = sizeof(obstacles);
  string *names = keys(obstacles);
  string *strs = allocate (size);
  int nb = 0;
  int i;

  for (i = 0; i < size; i++)
  {
    strs[i] = "none";
  }

  for (i = 0; i < size; i++)
  {
    if (who->query("9sky/"+names[i])=="done")
    {
      strs[nb] = obstacles[names[i]];
      nb++;
    }
  }
  if (nb == 0)
  {
    write (name+"尚未闯过九重天。\n");
  }
  else
  {
    write (name+"九重天已闯过了"BLINK+HIR+chinese_number(nb)+NOR"关：\n");
    who->set("9sky/number",nb);
    strs = (string *)sort_array (strs, 1);
    for (i = 0; i < nb; i++)
    {
      write ("    "+strs[i]+"\n");
    }
  }
  return 1;
}

int telling2 (object who)
{
  int size = sizeof(obstacles);
  string *names = keys(obstacles);
  string *strs = allocate (size);
  int nb = 0;
  int i;

  for (i = 0; i < size; i++)
  {
    strs[i] = "none";
  }

  for (i = 0; i < size; i++)
  {
    if (who->query("9sky/"+names[i])!="done")
    {
      strs[nb] = obstacles[names[i]];
      nb++;
    }
  }

  if (nb == 0)
  {
    write (name+"历尽磨难闯完了九重天。\n");
  }
  else
  {
    write (name+"九重天还须闯"HIR+chinese_number(nb)+NOR"关：\n");
    strs = (string *)sort_array (strs, 1);
    for (i = 0; i < nb; i++)
    {
      write ("    "+strs[i]+"\n");
    }
  }
  return 1;
}

