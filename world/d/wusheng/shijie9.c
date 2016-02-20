// changan wusheng
// shijie9.c

inherit ROOM;

void create()
{
  set ("short", "石阶");
  set ("long", @LONG

走过了火云洞，看见地上有一堆干草，上面有好象被火烧焦了，
刚好就是一个野兽形状。望眼看去，原来山上还有一座房子。
LONG);
set("exits", ([ /* sizeof() == 4 */
"north": __DIR__"room6",
"south": __DIR__"huoyun19",
]));
set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/huoqilin" : 1,
]));
        set("no_clean_up", 0);
        set("outdoors", 1);
        setup();
}

