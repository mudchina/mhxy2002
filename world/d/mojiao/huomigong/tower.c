inherit ROOM;
void create ()
{
  set ("short", "诛仙殿");   
  set ("long", @LONG   
总算出了火魔宫，你眼前一亮，居然有一个大厅，里面还有一个人。
LONG);

    set("exits", ([ 
               "north" : __DIR__"tower1",
               "west" : __DIR__"tower2",
               "east" : __DIR__"darkhole",
               "south" : __DIR__"tower4",
                 ]));
    set("objects",([
"/d/mojiao/npc/mingwang" : 1,
                 ]));
        set("no_magic",1);
        set("no_fight",1);
    setup();
}
