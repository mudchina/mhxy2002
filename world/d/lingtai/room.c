// иЯ╩╟йю╫Г║╓нВсн╪г║╓╟Ф╠╬ё╢ё╝ё╣ё╟
/* <SecCrypt CPL V3R05> */
 
// Room: some place in нВеё╨ьжч
// inside2.c

inherit ROOM;

void create()
{
  set ("short", "[0;31mяЧл╗[m");
  set ("long", @LONG

р╩вЫяЧл╗╦ъ╦ътзиоё╛╪ШдгфплАвФй╕╤квЬтзл╗иоё╛а╫╠ъспхЩй╝╦Жп║
оийла╒л╗об║ёжэн╖╟зиХх╚йгои╪рфВ╬ъё╛спр╩жжк╣╡╩ЁЖ╣доИ╨мё╛сж
м╦вев╞яо║ё
LONG);
set("exits", ([ /* sizeof() == 4 */
"out": __DIR__"houlang5",
"north":__DIR__"taiji",
]));
set("objects", ([
                __DIR__"npc/puti": 1 ]) );
        set("no_clean_up", 0);
        setup();
}

int valid_leave(object me,string dir)
{
  if(dir=="north")
     if(me->query("class")!="taoist")return notify_fail("дЦ╠╩р╩╣ю╫П╧Б╠фак╩ью╢║ё\n");
     else if(me->query("faith")<8000)
            return notify_fail("дЦ╠╩р╩╣ю╫П╧Б╠фак╩ью╢║ё\n");
        return ::valid_leave(me,dir);    
}
