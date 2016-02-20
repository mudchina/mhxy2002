// LLY@FYSY
inherit ROOM;

void create()
{
        set("short", "绿水湖湖底");

        set("long", @LONG
绿水湖的湖水清澈冰凉，各式各样的鱼儿在你的面前游来游去,偶尔还有几簌水草从面前漂过。
LONG
        );
              set("exits", ([ 
  "south" : __DIR__"hudi1", "north" : __DIR__"hudi4",

]));

	set("objects",([
			__DIR__"obj/fish" : 1,
       	]) );
set("item_desc", ([
                "水草": "水草中好象有什么东西随着水光一闪,你可以找找(search)看。\n",
                "grass" : "水草中好象有什么东西随着水光一闪,你可以找找(search)看。\n",
              ]) );
                       set("coor/x",-1065);

	               set("coor/y",35);

	               set("coor/z",-10);


set("no_magic",1);
	
setup();

}



void init()
{
   add_action("do_search", "search");
}

int do_search(string arg)
{
   object me, obj;
   int llvl;

   me = this_player();
   llvl = (int)me->query("kar");
   if(!me->query_temp("marks/yansword") && !query("got")) {
	set("got",1);
      if (llvl > 19) {  
         if(random(40) <= llvl) {
            message_vision("$N在漂来漂去的水草中到处搜索。\n", me);
            tell_object(me, "你在水草中找到一把长剑。\n"); 
            message("vision", me->name()+"从水草中抽出一把长剑。\n", environment(me), me);
            obj = new(__DIR__"obj/jewelsword");
            obj->move(me);
            me->set_temp("marks/yansword", 1);
            return 1;
         } 
         message_vision("$N在漂来漂去的水草中到处搜索。\n", me);
         tell_object(me, "水草随着流水漂走了，你什么也没找到。\n");
         return 1;
      }
      else {
         if(random(200) <= llvl) {
            message_vision("$N在漂来漂去的水草中到处搜索。\n", me);
            tell_object(me, "你在水草中找到一把长剑。\n"); 
            message("vision", me->name()+"从水草中抽出一把长剑。\n", environment(me), me);
            obj = new(__DIR__"obj/jewelsword");
            obj->move(me);
            me->set_temp("marks/yansword", 1);
            return 1;
         }
         message_vision("$N在漂来漂去的水草中到处搜索了好一阵。\n", me);
         tell_object(me, "水草随着流水漂走了，你什么也没找到。\n");
         return 1;
      }
      return 1;
   }
   message_vision("$N在漂来漂去的水草中到处搜索。\n", me);
   tell_object(me, "水草随着流水漂走了，你什么也没找到。\n");
   return 1;
}
void reset()
{
::reset();
delete("got");
}
