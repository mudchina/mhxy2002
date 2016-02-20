//by tianlin 2001/5/1
inherit F_CLEAN_UP;

#include <ansi.h>
#include <obstacle.h>

int telling1 (object who);
int telling2 (object who);

string name;

int main(object me, string arg)
{
	object ob;

	if( !arg ) {
		ob = me;
		name = HIY"Äã";
	} else if (wizardp (me)) {
		ob = find_player(arg);
		if(!ob) ob = find_living(arg);
	
		if(!ob) ob = LOGIN_D->find_body(arg);

		if(!ob || !me->visible(ob)) return notify_fail("Ã»ÓĞÕâ¸öÈË¡£\n");

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
Ö¸Áî¸ñÊ½£ºobstacles <Ä³ÈË>

ÏÔÊ¾Ä³ÈËÎ÷ĞĞÇóÈ¡Õæ¾­µÄ×ÊÁÏ¡£ 

Çë¼û£ºhelp qujing
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
    if (who->query("obstacle/"+names[i])=="done")
    {
      strs[nb] = obstacles[names[i]];
      nb++;
    }
  }

  if (nb == 0)
  {
    write (name+"ÉĞÎ´Î÷ĞĞÇóÈ¡Õæ¾­¡£\n");
  }
  else
  {
    write (name+"Î÷ĞĞÇóÈ¡Õæ¾­ÒÑ¹ıÁË"HIR+chinese_number(nb)+HIY"¹Ø£º[2;37;0m\n");
    who->set("obstacle/number",nb);
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
    if (who->query("obstacle/"+names[i])!="done")
    {
      strs[nb] = obstacles[names[i]];
      nb++;
    }
  }

  if (nb == 0)
  {
    write (name+HIY"Î÷ĞĞÇóÈ¡Õæ¾­ÒÑÀú¾¡ÁËËùÓĞµÄÄÑ¹Ø¡£[2;37;0m\n"NOR);
  }
  else
  {
    write (name+"Î÷ĞĞÇóÈ¡Õæ¾­»¹Ğë¹ı"HIR+chinese_number(nb)+HIY"¹Ø£º[2;37;0m\n");
    strs = (string *)sort_array (strs, 1);
    for (i = 0; i < nb; i++)
    {
      write ("    "+strs[i]+"\n");
    }
  }
  return 1;
}

