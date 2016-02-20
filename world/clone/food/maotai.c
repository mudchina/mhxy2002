// wineskin.c  ¾Æ´ü

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("[1;36mÃ©Ì¨[m", ({"maotai"}));
        set_weight(700);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "ÕâÊÇÒ»Æ¿´æÁË°ÙÄêµÄÃ©Ì¨.\n");
                set("unit", "¸ö");
                set("value", 20);
                set("max_liquid", 15);
        }

        // because a container can contain different liquid
        // we set it to contain wine at the beginning
        set("liquid", ([
                "type": "alcohol",
                "name": "Ã×¾Æ",
                "remaining": 10000000,
                "drunk_supply": 6,
        ]));
}

