// by happ@YSZZ
inherit ROOM;
#include <hen.h>

void create ()
{
  set ("short", "²ÝµØ");
  set ("long", @LONG

        Ò»Æ¬ÂÌÒñÒñµÄ²ÝµØ¾ø¶ÔÊÇÔ¼»á£¨[1;36mdate[m£©µÄºÃµØ·½Å¶¡£

LONG);
  set("exits", ([ /* sizeof() == 4 */
        "east": __DIR__"jw",
]));

        setup();
}

void init()
{
        add_action("do_date","date");
}

int do_date()
{
        object ob = this_player();
        int i = 100 + random(50);

        if( ob->query("hen/money") < i )
                return notify_fail("Ã»ÓÐÇ®Ò²È¥Ô¼»á£¿\n");

        ob->command_function("cls");
        ob->command_function("shape");
        ob->add("hen/money",-i);
        ob->add("hen/happy",12);
        ob->add("hen/life",-5);
        ob->add("hen/satisfy",12);
        ob->add("hen/dirty",8);
        ob->add("hen/affection",-1);
        cat(DATE);
        return 1;
}
