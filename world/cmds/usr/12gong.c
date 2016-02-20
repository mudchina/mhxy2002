//by tianlin@mhxy for 二零零一年八月十九日一点二十三分三十七秒 星期七
//局部修改

inherit F_CLEAN_UP;

#include <ansi.h>
#include <12gong.h>

int telling1 (object who);
int telling2 (object who);

string name;

int main(object me, string arg)
{
        object ob;

        if( !arg ) {
                ob = me;
                name = HIC"你";
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
指令格式：12gong <某人>

显示某人十二宫的资料。 
请见：help 12gong
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
    if (who->query("12gong/"+names[i])=="done")
    {
      strs[nb] = obstacles[names[i]];
      nb++;
    }
  }
  if (nb == 0)
  {
    write (name+"尚未闯过"NOR+HIW"十二"NOR+HIC"宫。\n");
  }
  else
  {
    write (name+""NOR+HIW"十二"NOR+HIC"宫已闯过了"BLINK+HIR+chinese_number(nb)+NOR+HIC"宫：\n");
    who->set("12gong/number",nb);
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
    if (who->query("12gong/"+names[i])!="done")
    {
      strs[nb] = obstacles[names[i]];
      nb++;
    }
  }

  if (nb == 0)
  {
    write (name+HIC"历尽磨难闯完了"NOR+HIW"十二"NOR+HIC"宫。\n");
  }
  else
  {
    write (name+""NOR+HIW"十二"NOR+HIC"宫还须闯"HIR+chinese_number(nb)+HIC"宫：\n");
    strs = (string *)sort_array (strs, 1);
    for (i = 0; i < nb; i++)
    {
      write ("    "+strs[i]+"\n");
    }
  }
  return 1;
}

