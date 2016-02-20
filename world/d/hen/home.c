// by happ@YSZZ
inherit ROOM;
#include <hen.h>

void create ()
{
  set ("short", "¼¦ÎÑ×Ü²¿");
  set ("long", @LONG

        Èç¹ûÄãÈÕ³£Éú»îÖÐ²»Ïë°ÑÐ¡¼¦´øÔÚÉíÉÏ£¬¿ÉÒÔ°ÑÐ¡¼¦£¨[1;32mfang[m£©ÔÚÕâ£¬
    ÒªÊÇÄãÏëÄîÄãµÄÐ¡¼¦£¬¾Íµ½Õâºô»½£¨[1;33mhuhuan[m£©ÄãµÄ±¦±´°É£¡

LONG);
  set("exits", ([ /* sizeof() == 4 */
        "east": __DIR__"room",
]));

        setup();
}

void init()
{
        add_action("do_fang","fang");
        add_action("do_huhuan","huhuan");

}
int do_fang()
{
        object ob = this_player();
        object where = this_object();
        object hen = present("zhandou ji",ob);

      if(!hen) return notify_fail("ÄãÉíÉÏÃ»¼¦,·ÅÊ²Ã´·Å! \n");

        ob->command_function("kiss_hen");
        tell_room(where,ob->name()+"ºÍËûµÄÐ¡¼¦ÎÇ±ðÀ­*^_^*\n");
        destruct(hen);
        return 1;
}

int do_huhuan()
{
        object ob = this_player();
        object where = this_object();
        object hen = present("zhandou ji",ob);
        object newhen=new(__DIR__"npc/hen");

        if(  hen ) 
                return notify_fail("Ð¡¼¦²»ÔÚÄãÉíÉÏÂð£¿\n");

        if(! ob->query("hen") )
                return 0;

        newhen->move(ob);
        tell_room(where,"Ð¡¼¦¼ûµ½"+ob->name()+"£¬Ò»ÏÂ¾ÍÌøµ½"+ob->name()+"µÄ»³Àï¡£\n");
        return 1;
}
        
