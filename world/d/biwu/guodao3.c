// Room: /u/biwu/guodao3.c
// Date: bye linxue([1;37mажя╘[2;37;0m) Fri Apr 30 09:45:45 1999
inherit ROOM;

void create()
{
	set("short", "╠хнД╢С╩АуЩце");
	set("long", @LONG
уБйг╠хнД╢С╩А╣дуЩце©з,╦Вб╥нДажхкй©тф╪╞╢к╢╕ё╛╢С╪р╦Ж╦Жд╕х╜
╡ауфё╛т╬т╬сШйт║ёа╫цШ╫Урбнюр╩вСр╩ср╣ду╬тз╢Сце©зё╛н╛Ёжве╠хнД╢С
╩А╣джхпР║ё╧╚ф╫вср╡тзуБ╦╨тП╢С╩А╣дуЩЁё╫Ьпп║ё
н║╤К╣д╢Сцеио╦ъпЭвеЁ╞м╒╩й╣ш[0;5;37mа[5mж[5mя[5m╘[0mсЫ╢м╣д╫Пьр

[35m                      рт  нД  ╩А  ся[0m

[35m                      ╣Ц  ╣╫  н╙  ж╧[0m


LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"guodao2",
  "enter" : __DIR__"biwu",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guard" : 2,
]));
	set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
