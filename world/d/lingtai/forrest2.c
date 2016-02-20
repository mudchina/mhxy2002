// иЯ╩╟йю╫Г║╓нВсн╪г║╓╟Ф╠╬ё╢ё╝ё╣ё╟
/* <SecCrypt CPL V3R05> */
 
// Room: some place in нВеё╨ьжч
// forrest.c

inherit ROOM;

void create()
{
  set ("short", "[0;32mкийВаж[m");
  set ("long", @LONG

киажж╝жп╥гЁё╣д╟╣ё╛╧Боъх╚╠╩хГи║хГ╦г╣дйВж╕╣╡в║ё╝жэн╖©╢
╡╩╣╫р╩╦Жхкс╟ё╛дЦж╩дэйжцЧвейВ╦ир╩╡╫╡╫въё╝ЁЩак╫еоб╣д©щ
ж╕╥╒ЁЖ╠╩╡х╤ой╠╣д╡р╫пё╛ж╩спр╩п╘нчад╣дп║ЁФнчад╣д╫пвеё╝
LONG);
set("exits", ([ /* sizeof() == 4 */
"north" : __DIR__"forrest",

]));
set("objects", ([ /* sizeof() == 2 */
"/d/lingtai/obj/shuzhi": 2]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}


