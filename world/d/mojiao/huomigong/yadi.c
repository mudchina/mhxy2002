inherit ROOM;
#include <ansi.h>
#include <command.h>

void create()
{
        set("short", "崖底");
        set("long", @LONG

在你的面前是一个岩浆湖，翻腾的岩浆不停的拍着岩岸。
岸边有一些矮小的灌木，灌木丛后是一道高耸入云的危
崖(clip)，给人以高不可攀的感觉。
LONG
        );
        set("item_desc", ([
                "细沙": "洁白的沙滩上露出一角旧布。\n",
                "危崖": "崖壁如同刀削的一样般，滑不留人，上面寸草不生。抬头望，\n你隐约可见半崖上突出一块白色的山石。\n",
        ]) );
	set("outdoors","mojiao");
	setup();
}

void init()
{
	add_action("do_climb", "climb");
}



int do_climb(string arg)
{
        object 	me;
	int	mlvl;

	if(!arg || arg != "clip") {
		write("你要爬什么？\n");
		return 1;
	}
	me = this_player();
	mlvl = (int)me->query_skill("dodge");
	if(mlvl < 70) 
		message_vision(HIY "\n$N奋力向上爬去，爬了不到两三丈，只觉的手脚发软，向下滑了下去。\n" NOR, me);
	else {
		message_vision(HIY "\n$N小心翼翼地向上爬去，身形慢慢被云雾遮掩。\n" NOR, me);
		me->move(__DIR__"evil-tang");
	}
	return 1;
}

