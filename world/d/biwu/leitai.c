// Room: /u/biwu/leitai.c
// Date: bye linxue([1;37mажя╘[2;37;0m) Thu Apr 29 18:48:28 1999
inherit ROOM;

void create()
{
	set("short", "ючл╗ио");
	set("long", @LONG
уБюОйгр╩╦Жб╤лЛючл╗обцФё╛йгнДажхкнО╠хнД╣д╣ь╥╫ё╛р╡йг╫╜╨Че╝
вс╬ыпп╠хнДупгв╣д╫о╪╪Ё║кЫ║ё╠ъиоспр╩╦Ж╠ЬфВ╪э(jia)ё╛дЦ©иртх║сц╨о
йж╣д╠ЬфВ╨м╥ю╬ъ║ёхГ╧Шр╩гп╬мпВё╛©иртйДхК(ok)ё╛хойДйг(giveup)ё╛
хГ╧Шц╩сп╤тйжак©иртсцё╗quitё╘обх╔║ё

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"biwu",
]));
	set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
