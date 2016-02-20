
#include <ansi.h>
inherit ITEM;
void setup()
{}
void init()
{
        add_action("do_eat", "eat");
}
void create()
{
string *names = ({
  "[33mÀ°Ó£ÌÒ[m",
  "[31mÊìÃ·×Ó[m",
  "[32mÏÊÁúÑÛ[m",
  "[33m»ğÀóÖ¦[m",
  "[34mÍÃÍ·Àæ[m",
  "[35m¼¦ĞÄÔæ[m",
  "[36mÏãÌÒ[m",
  "[31mÀî×Ó[m",
  "[32mÑîÃ·[m",
  "[33mÎ÷¹Ï[m",
  "[35mÊÁ×Ó[m",
  "[36mÊ¯Áñ[m",
  "[31mÆÏÌÑ[m",
  "[32mÒ¬×Ó[m",
  "[1;33m½Û×Ó[m",
});

string *ids = ({
    "la yingtao",
    "shu meizi",
    "xian longyan",
    "huo lizhi",
    "tutou li",
    "jixin zao",
    "xiang tao",
    "li zi",
    "yang mei",
    "xi gua",
    "shi zi",
    "shi liu",
    "pu tao",
    "ye zi",
    "ju zi",
});

  int i = random(sizeof(names));
  set_name(names[i], ({ids[i]}));
  set("unit","¸ö");
  set("value",50);
  setup();
}

int do_eat(string arg)
{
      object me = this_player(), ob = this_object();
        if (!id(arg))
        return notify_fail("ÄãÒª³ÔÊ²Ã´£¿\n");
    me->set("food",me->max_food_capacity());
    me->set("water",me->max_water_capacity());
        message_vision(HIC"$N³ÔÏÂÒ»¸ö"+ob->query("name")+"£¬²»½ûÁ¬ÉùËµµÀ£º¡°»¨¹ûÉ½ÕæÄË¸£µØÒ²¡£\n"NOR,me);
        destruct(this_object());
        return 1;
}
