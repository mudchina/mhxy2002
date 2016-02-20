// 发礼物房
// idea@yqyl
inherit ROOM;
#include <ansi.h>

void yyy(string arg);
string file;

void create()
{
	set("short", "礼品房");
	set("long", @LONG
这里是巫师送礼品给玩家的房子(song)。
LONG
	);
	
	set("exits", ([
		"west" : __DIR__"wizroom"
	]));
	
	setup();
}

void init()
{
	add_action("do_song", "song");
	add_action("do_sheding", "sheding");
}

int do_song()
{
	object who = this_player();
	object present;
	if ( wiz_level(who)<wiz_level("(arch)") ) 
		return notify_fail("要arch及以上巫师执行。\n");
	if (!file) return notify_fail("请设定送啥(sheding <file>)\n");
	
	present = load_object(file);
	if (!present) return notify_fail("没有"+file+"这个东西。\n");
	
	write(present->query("name")+"("+present->query("id")+")给每个人，确定吗？[Y/N]\n");
	input_to ((: yyy :));
	return 1;
}

void yyy(string arg)
{
	object *allp = users();
	object present;
	int i;
	
          log_file("liwu",sprintf("%s  本次礼物%s，舒畅%s\n",ctime(time()),file
		,this_player()->query("id") ));
	if (arg == "y" || arg == "Y")
	{
		for(i=0;i<sizeof(allp);i++)
		{
			present = new(file);
			present->move(allp[i]);
                          tell_object(allp[i],HIY"巫师发礼品喽！天上掉下个"NOR+present->query("name")
				+HIY"落在你手中。\n"NOR);
			log_file("liwu",sprintf("%s(%s)get it\n",allp[i]->query("name")
			,allp[i]->query("id")));
		}
	} else write("取消。\n");
}

int do_sheding(string arg)
{
	object who=this_player();
	object present;
	if ( wiz_level(who)<wiz_level("(arch)") ) 
		return notify_fail("要arch及以上巫师执行。\n");
		
	if (!arg ) return notify_fail("请设定送啥(sheding <file>)\n");
	
	present = load_object(arg);
	if (!present) return notify_fail("没有"+arg+"这个东西。\n");
	
	file = arg;
	write("ok\n");
	return 1;
}
