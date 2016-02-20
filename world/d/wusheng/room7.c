// changan wusheng
// room7.c

inherit ROOM;

void create()
{
  set ("short", "帝王殿");
  set ("long", @LONG

殿堂中有一个如天神般的人站在那里，他就是武圣门的开山鼻祖
——孔圣武帝。
LONG);
set("exits", ([ /* sizeof() == 4 */
"west": __DIR__"room8",
"south": __DIR__"room6",
"east": __DIR__"room9",
]));
set("objects", ([
        __DIR__"npc/kongwu": 1 ]) );
        set("no_clean_up", 0);
        set("outdoors", 1);
        setup();
}

void init ()
{
  add_action ("do_climb","climb");
}

int do_climb ()
{
  object who = this_player ();
  string midong = __DIR__"midong1";

  message_vision ("$N攀住墙壁，向上爬去。\n",who);  
  if (who->is_busy() || who->is_fighting() || 
	  present ("yao guai",this_object()))
  {
    message_vision ("$N从墙壁上滑了下来！\n",who);  
    return 1;
  }
  midong[strlen(midong)-1] = '1'+random(5);
  who->move(midong);
  who->start_busy(2,2);

	if( random(2) ) {
  call_out ("sleeping",1,who);
  return 1;
	}
  call_out("fainting",1,who);
  return 1;
}

void sleeping (object who)
{
  message_vision ("秘洞里散发着一股甜甜的香气，$N顿时昏昏然。\n\n",who);  
  message_vision ("$N勉强眨了眨惺忪的眼睛，打了个哈欠。\n",who);  
  who->set("last_sleep",time()-270);
  who->interrupt_me();
  who->command_function("sleep"); 
}
void fainting (object who)
{
	message_vision("突然从暗口中喷出一股紫烟，$N顿时头重脚轻，身不由己 ... \n", who);
	who->unconcious();
}