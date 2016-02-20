//EDIT BY LUCAS
inherit ROOM;

void create ()
{
  set ("short", "大门");
  set ("long", @LONG 
你面前出现一座宏伟的府邸，依水底崖势而建。红铜铁钉的
大门(gate)外边有一个横匾(bian)，上面写着几个大字。几
个小妖在门外跳闹耍子，一见你，就扑了过来。
LONG);

  set("water", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"hedi6",
])); 
        set("objects", ([
                __DIR__"npc/guai" : 3,
        ]));

        set("item_desc", ([
 "bian" : "匾上横封了八个大字--衡阳峪黑水河神府\n", 
 "gate" : "这是一扇红铜铁钉的大门，使劲砸开吧！\n", 
        ]) );
        setup();
} 
void init ()
{
  add_action ("do_break", "break");
}

int do_break (string arg)
{
  object who = this_player ();
        if( !arg || arg!="gate" )
              return notify_fail("你要砸什么? \n");
    message_vision ("$N大喝一声，使劲朝门上砸去，哄地一声把门砸了个大窟窿！\n",who);
      message_vision ("乓地一声门开了！\n",who);
      who->add("force",-200);
      who->add("mana",-200);
    this_object()->set("exits/east", __DIR__"dayuan");
  return 1;
}


