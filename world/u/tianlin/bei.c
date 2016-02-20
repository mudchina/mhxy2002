// jinian bei by tianlin@mhxy 2001/5/1

#include <ansi.h>

inherit ITEM;

void create()
{
           set_name(""CYN"※"NOR""RED"梦幻西游纪念碑"CYN"※"NOR"", ({"jinian bei", "bei" }));
        set("long", "梦幻西游的各种排名，可以用read来看。\n");
     set("no_get", "你疯了连梦幻西游开站的纪念碑都想偷走。\n");
}

void init()
{
  add_action("do_read","read");
}


int do_read(string type)
{
  if (! type)
    write("/adm/daemons/toptend"->query_type());
  else
 write("/adm/daemons/toptend"->topten_query(type));
return 1;

}
