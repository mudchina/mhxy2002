//[4;53m[1;31mBy tianlin@mhxy for 2001.9.27[2;37;0m
//²¿·ÖÓÅ»¯

inherit ROOM;

string* books = ({
        "laozi1",
        "daodejing-i",
        "laozi2",
        "daodejing-i",
        "laozi8",
        "daodejing-i",
        "laozi13",
        "laozi1",
        "laozi16",
        "daodejing-i",
        "laozi18"
});

void create()
{
        set("short", "²Ø¾­¸ó");
        set("long", @LONG
ÕâÀïÊÇ²Ø¾­¸ó£¬¿¿Ç½ÊÇÒ»ÅÅÊé¼Ü£¬°ÚÂúÁËµÀ½ÌµÄµä¼®¡£ÖĞÑëÓĞÒ»¸ö³¤·½
ĞÎµÄ´ó×À×Ó£¬ÉÏÃæÒ²¶ÑÂúÁËÊé¡£Ò»¸öµÀÍ¯ÕıÔÚÕûÀíÊé¼®¡£
LONG );
        set("exits", ([
                "southdown" : __DIR__"xilang",
        ]));
        set("objects", ([
                __DIR__"npc/daotong" : 3,
                "clone/book/"+books[random(sizeof(books))] : 1,
                "clone/book/"+books[random(sizeof(books))] : 1
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
