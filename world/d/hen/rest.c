// by happ@YSZZ
inherit ROOM;
#include <hen.h>

void create ()
{
  set ("short", "ÐÝÏ¢ÊÒ");
  set ("long", @LONG

        ÕâÊÇÐ¡¼¦Ë¯¾õµÄµØ·½£¬Èç¹ûÄãµÄÐ¡¼¦ÀÛÁË£¬ÄÇ¾Í[1;32m shui [mÒ»»á°É¡£

LONG);

  set("exits", ([ /* sizeof() == 4 */
        "west": __DIR__"road2",
]));

        setup();
}

void init()
{
                add_action("do_rest","shui");
}

int do_rest()
{
        object ob = this_player();
        
        if( !present("zhandou ji",ob) ) return 0;

        ob->command_function("cls");
        ob->add("hen/life",-1);
        ob->command_function("shape");

        switch(random(2))
        {
                case 0:
                cat(REST1);
                break;
                case 1:
                cat(REST2);
                break;
        }
        ( ob->query("hen/tired") <= 20 )?ob->set("hen/tired",0):ob->add("hen/tired",-20);
        return 1;
}
