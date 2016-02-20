// by cih 10/01/2002
// Room: /d/kaifeng/huayuan4
inherit ROOM;

void create()
{
  set("short", "念园");
   set("long", @LONG

天蓬府邸里的花园。这里种满了鲜花。不知道为什么花儿都开
着。各种各样的花儿争奇斗艳，万紫千红别有意味。居然还有
梅花和牡丹一决高下！听说这些都是当年长娥和高小姐喜欢的
可见我们可爱的天蓬还是个痴情种子呢！
LONG
   );
   set("exits", ([ /* sizeof() == 4 */
    "north" : __DIR__"zlou1",
    "southwest" : __DIR__"huayuan3",
    "south" : __DIR__"huayuan5",
    "southeast" : __DIR__"huayuan6",
]));
    
   set("outdoors", "kaifeng");
   setup();
   replace_program(ROOM);
}
