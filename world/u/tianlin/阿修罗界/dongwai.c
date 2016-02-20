#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "穷极魔洞外");
	set ("long", @LONG

这里就是囚禁魔佛无天的地方。门上写着“穷极魔洞外”五字。
门前守卫森严。你注意到门上挂着一块大锁，看来想进去极为不易。

LONG);

	set("exits", 
	([ //sizeof() == 4
		"up" : __DIR__"diyu18",
	]));
	
	set("objects", 
	([ //sizeof() == 1
               __DIR__"npc/gui" : 2,
               __DIR__"npc/jinchanzi" : 1,
	]));

	setup();
}
void init()
{
        add_action("do_open", "open");
}

int do_open(string arg)
{
        object me, key, nroom;

        me = this_player();

        if( !arg || arg != "door" ) 
                return notify_fail("你要打开什么？\n");

if( !(key = present("qiongji zhishi", me)) ) 
                return notify_fail("没有钥匙怎么开门？\n");

        if( !(nroom = find_object(__DIR__"modong")) )
                nroom = load_object(__DIR__"modong");

        set("exits/north", __DIR__"modong");
        nroom->set("exits/south", __FILE__);
        message("vision", "你拿出钥匙，打开铁门。\n", this_object() );
                       message("channel:rumor", HIR+"【阿修罗界】无天哈哈大笑了几声。！\n"+NOR,users());
        message("channel:rumor", HIR+"【阿修罗界】魔佛无天（wu tian): "+me->query("name")+"助我脱困，得我无上绝学-乾坤图！\n"+NOR,users());
        message("channel:rumor", HIY+"【佛界】如来佛祖 (rulai fo): "+me->query("name")+"居然如此胆大妄为，真是罪不可恕！\n"+NOR,users());
        destruct(key);
        return 1;
}
