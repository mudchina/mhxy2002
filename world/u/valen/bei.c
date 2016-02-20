// jinian bei by tianlin@mhxy 2001/5/1

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(""CYN"¡ù"NOR""RED"[4;53mÃÎ»ÃÎ÷ÓÎ¼ÍÄî±®"NOR""CYN"¡ù"NOR"", ({"jinian bei", "bei" }));
        set("long", "ÃÎ»ÃÎ÷ÓÎµÄ¸÷ÖÖÅÅÃû£¬¿ÉÒÔÓÃreadÀ´¿´¡£\n");
     set("no_get", "Äã·èÁËÁ¬ÃÎ»ÃÎ÷ÓÎ¿ªÕ¾µÄ¼ÍÄî±®¶¼ÏëÍµ×ß¡£\n");
}

void init()
{
  add_action("do_read","read");
}


int do_read(string type)
{
 write("/adm/daemons/toptend"->topten_query(type));
return 1;

}
