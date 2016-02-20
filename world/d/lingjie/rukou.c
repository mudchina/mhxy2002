#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "灵界入口");
  set ("long", 

"一座座高山相连，密林丛生，从山中透出阵阵烟雾，\n"+
"让人不禁有些胆寒，高山中突出来一块巨石（stone),\n"+
"巨石仿佛刻着这个字，可因时间太久，已有些褪色，\n"+
"朦胧中仿佛可以看见三个大字:\n"
YEL"               压  龙  石       \n" NOR 
);
  
  set("item_desc", ([ /* sizeof() == 1 */
  "stone" : "
\t\t\t巨
\t\t\t石
\t\t\t压
\t\t\t龙
\t\t\t有
\t\t\t来 
\t\t\t无
\t\t\t回

",
]));
  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/laozhe" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
//  "enter" : __DIR__"lingjie0",
   "westup" : __DIR__"lingjie",
   "down":"/d/dntg/sky/jiashan",
]));
  set("outdoors", "lingjie");
  set("no_magic", 1);

  setup();
}

void init()
{
	add_action("open_down", "open" );
}

int open_down()
{
        object lingjie;

        if( !(lingjie = find_object(__DIR__"lingjie0")) )
                lingjie = load_object(__DIR__"lingjie0");

        if( lingjie = find_object(__DIR__"lingjie0") ) 
        {
                set("exits/enter", __DIR__"lingjie0");
                message("vision", "是来拜师的吧? 嘿嘿.. 好,那就请进吧。\n", this_object() );
		message("vision", "快,请进。记住,这里只进不出呀!\n", lingjie );
        set("long", @LONG
    
灵界入口已打开,里面一片漆黑,既然来了,就进去看看
吧!
LONG);
	}
	
        call_out("close_down", 150);

        return 1;
}

int close_down()
{
        object lingjie;

	message("vision", "轰隆一声,压龙石又退回到了原处。\n", this_object() );
	if( lingjie= find_object(__DIR__"lingjie0")) {
	message("vision", "轰隆一声,压龙石又退回到了原处。\n", lingjie);
	lingjie->delete("exits/out");
	}

        delete("exits/enter");
        set("long", 
    
"一座座高山相连，密林丛生，从山中透出阵阵烟雾，\n"+
"让人不禁有些胆寒，高山中突出来一块巨石（stone),\n"+
"巨石仿佛刻着这个字，可因时间太久，已有些褪色，\n"+
"朦胧中仿佛可以看见三个大字:\n"
YEL"               压  龙  石       \n" NOR 
);
return 1;
}



