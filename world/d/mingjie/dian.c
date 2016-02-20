// by HAPP@YSZZ

inherit ROOM;

void create ()
{
        set ("short", "冥王的神殿");
        set ("long",
             @LONG
                  /^\
                /     \
 |           | (       ) |           |
/^\ |       /^\ \     / /^\       | /^\
|O|/^\     (   )|-----|(   )     /^\|O|
|_||-| |^-^|---||-----||---|^-^| |-||_|
|O||O| |/^\|/^\||  |  ||/^\|/^\| |O||O|
|-||-| ||_|||_||| /^\ |||_|||_|| |-||-|
|O||O| |/^\|/^\||(   )||/^\|/^\| |O||O|
|-||-| ||_|||_||||   ||||_|||_|| |-||-|

唯一能通往极乐净土的地方
LONG);

  set("no_fight", 1);
  set("no_magic", 1);

        set("exits", ([
        "southup"  :       __DIR__"tu4",        
        ]));

         set("objects", ([ 
 	"/d/mingjie/npc/panduola":1,
        
]));

        setup();
}
