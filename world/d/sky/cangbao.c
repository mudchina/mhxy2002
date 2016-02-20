// иЯ╩╟йю╫Г║╓нВсн╪г║╓╟Ф╠╬ё╢ё╝ё╣ё╟
/* <SecCrypt CPL V3R05> */
 
// create by snowcat.c 2/8/1997

inherit ROOM;

void create ()
{
  set ("short", "[33m╡ь╠╕©Б[m");
  set ("long", @LONG

╡ь╠╕©БюОспр╩╨╨╟всЯ╟╦л╗ё╛иосп╦ВюЮцШй╫╠ЬфВ,╩╓╪в║ё
©╢ю╢ожтздЦ©иртвтси╣ддцх║акё║
л╗всио╥еспё╨
  ╫П╦уужё╨          zhao
  ╥Эд╖╣╤ё╨          dao
  фплАвсё╨          zi
  рплЛ╫ё:           jian
  ь╟йв:             bishou
  ╫Пк©╠╕╪в:         jia          

LONG);

  set("exits", ([
        "south"   : __DIR__"neidian.c",
      ]));

  setup();
}

void init ()
{
  add_action ("do_take","take");
  add_action ("do_take","na");
}

int do_take (string arg)
{
  object who = this_player();
  object ob;


  if (! arg)
    return notify_fail ("дЗр╙дцй╡ц╢ё©\n");
  if (arg == "zhao")
    ob = new ("/d/suburb/xkx/shaolin/obj/jingang-zhao");    
  else if (arg == "zi")
  ob = new ("/d/suburb/xkx/shaolin/obj/puti-zi");
  else if (arg == "dao")
    ob = new ("/d/suburb/xkx/shaolin/obj/fumo-dao");    
else if (arg == "jia")
ob = new ("/obj/baojia");
else if (arg == "jian")
ob = new("/d/suburb/xkx/working/obj/yitian-jian");
else if (arg == "bishou")
 ob = new ("/obj/bishou");
else
    return notify_fail ("дЗр╙дцй╡ц╢ё©\n");


  message_vision ("$N╢сл╗иодцфП$n║ё\n",who,ob);
  ob->move(who);


  return 1;
}



