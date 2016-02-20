//【蜀山派】mhxy-yushu 2001/2
inherit ROOM;
void create ()
{
  set ("short","破庙");
  set ("long", @LONG

这个小庙已经破旧不堪，里面什么也没有。正殿里四壁透风，房顶漏水，几
座难以辨认的泥像个个缺胳膊少腿。中间有个已经不成样子的佛像，也看不
出来是谁，佛像前面还有个香炉。不知道村人为什么不把这个破庙给拆了。
LONG);
  
  set("exits", ([      
     "west" : __DIR__"road4",
 ]));
   setup();
}









