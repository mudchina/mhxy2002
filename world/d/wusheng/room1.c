// changan wusheng
// room1.c

inherit ROOM;

void create()
{
  set ("short", "武圣大殿");
  set ("long", @LONG

孔武大帝之圣殿，四处飘渺着从八个盘龙大鼎中升出的紫烟。仔
细看看该八个大鼎，乃远古之物，鼎中溢出的丝丝紫烟，烟中带
香，整个大殿各种香气飘逸，无不令人心旷神怡。八个鼎中还泛
着八种幽光，使整个大殿不用任何火光也日夜通明。
LONG);
set("exits", ([ /* sizeof() == 4 */
"northwest": __DIR__"room4",
"north": __DIR__"shijie5",
"northeast": __DIR__"room5",
"west": __DIR__"room3",
"east": __DIR__"room2",
"south": __DIR__"guangchang",
]));
set("objects", ([
               "/d/wusheng/obj/danlu": 1,
]));
          set("no_clean_up", 0);
        set("outdoors", 1);
        setup();
}
void init()
{
        object who=this_player();
        if( (string)who->query("family/family_name")=="武圣门" ) {
        call_out("heal_up", 9, who);
        }
	remove_call_out("sounding");
	call_out("sounding", random(10), this_object());
}
int sounding(object where)
{
    string *msgs=({
    "八个大鼎中同时飘出一阵紫烟。\n",
    "八个大鼎中的灵光同时闪了几闪。\n",
    "紫烟灵光混合后在大殿中轻舞飞扬。\n",
    "飞舞的光烟化做一条神龙。\n",
  });
  tell_room (where,msgs[random(sizeof(msgs))]);
}

int heal_up(object who)
{
        if( !who || environment(who) != this_object() ){
		 return 1;
	}
/*
	if( (int)who->query("max_sen")==(int)who->query("eff_sen")
	&& 	(int)who->query("max_kee")==(int)who->query("max_kee") ){
		return 1;
	}
	
*/
        who->set("eff_gin", (int)who->query("max_gin"));
        who->set("eff_kee", (int)who->query("max_kee"));
        who->set("eff_sen", (int)who->query("max_sen"));

        message_vision("阵阵紫烟飘向$N，$N深深吸了几口气。\n", who);
        write("你觉得自己的精神气血一下子都恢复了。\n");

	if( (int)who->query("food") < (int)who->max_food_capacity() )
		who->set("food", (int)who->max_food_capacity());
	if( (int)who->query("water")< (int)who->max_water_capacity())
		who->set("water", (int)who->max_water_capacity());


        return 1;
}
