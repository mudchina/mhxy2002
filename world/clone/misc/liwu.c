#include <ansi.h>;
inherit ITEM;

void create()
{
        set_name("[1;32m¹ú[33mÇì[36mÀñ[35mÎï[m", ({"liwu"}));
               set("unit", "¸ö");
                set("long",
                "×£ºØËùÓĞµÄÑıÉñÖ®ÕùµÄÅóÓÑÃÇ¿ìÀÖ£¬Çë´ò¿ª(dakai)ÎÒÃÇµÄÀñÎï.\n");
                set("value", 0);
                set_weight(10);
        setup();
}
void init()
{
        add_action("do_dakai", "dakai");
}

int do_dakai(string arg)
{
        object me = this_player();
        object ob ;
        if (arg == "liwu")
        {    
    ob = new("/clone/food/cake");
        ob->move(me);
tell_object(me,"[1;32mÄãĞ¡ĞÄµÄ²ğ¿ªÀñÎï£¬ĞÄÏëÀïÃæÊÇÊ²Ã´ºÃ¶«Î÷ÄØ¡£[m\n");
        return 1;
        }
        if (!id(arg))
        return notify_fail("ÄãÒª´ò¿ªÊ²Ã´£¿\n");
}
