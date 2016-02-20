//shushan2 by yushu@SHXY 2000.12
inherit ROOM;
void create ()
{
  set ("short","祖师殿");
  set ("long", @LONG

蜀山派的祖师殿，上面供奉着蜀山派祖师静虚老祖的石像，
据说静虚老祖目前尚在人世，但除了酒剑仙和蜀山剑圣之外
再没人见过他。
LONG);
   set("exits", ([      
       "north" : __DIR__"shangqing",
       "south" : __DIR__"fangning",
  ]));
   set("objects", ([ 
      __DIR__"npc/jiujianxian" : 1,
      __DIR__"npc/jiantong" : 1,
       ]));

  setup();
}









