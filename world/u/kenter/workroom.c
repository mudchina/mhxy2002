//changan city
// [lsg 2000/11/16]
inherit ROOM;

void create ()
{
        set ("short", "凤冀的小草屋");
        set ("long", @LONG

这里是凤冀的草屋,这里面的东东可是好呀,哪个巫师
也没有。
edit，你可以请在线巫师帮你修改，或者ls /doc/help/wiz/
看看我上传的有关巫师的教程。
LONG);
        set("exits", 
        ([ //sizeof() == 2
                "up" : "/d/wiz/wizroom",
                "down" : "/d/city/kezhan",
                        ]));

        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}



