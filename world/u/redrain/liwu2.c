//wuchangdan.c
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
  HIW"ÇÉ¿ËÁ¦"NOR,
 HIW "´ó°×ÍÃÄÌÌÇ"NOR,
  HIW"ÄÌÓÍµ°¸â"NOR,
  HIG"ÌØÖÆÃµ¹åÌÇ"NOR,
  HIC"¾ÆÐÄÇÉ¿ËÁ¦"NOR,
  HIG"»­Ã¼ÌÇ"NOR,
  YEL"»ð¹ø"NOR,
  HIB"Ó£ÌÒÍè×Ó"NOR,
  HIG"°ô°ôÌÇ"NOR,
  GRN"ÍÞ¹þ¹þ"NOR,
  HIC"ÉÏºÃ¼Ñ"NOR,
  HIR"ÏºÌõ"NOR,
  HIY"ÀÖ°ÙÊÏ"NOR,
  HIG"¿ÏµÂ¼¦"NOR,
  GRN"³¤ÊÙ¸â"NOR,
  HIC"³¤ÊÙÃæ"NOR,
  HIY"ÅîÀ³ÊÙÌÒ"NOR,
});
  int i = random(17)+1;
  string str;
  set_name(names[random(sizeof(names))], ({"li wu","liwu"}));

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "¿é");
                set("long", "ºÃºÃÁ·°É~!\n");
        }
        setup();
}

int do_eat(string arg)
{
        object me = this_player();

        if (!id(arg))
        return notify_fail("ÄãÒª³ÔÊ²Ã´£¿\n");

        if( me->query("eaten_liwu") )
        return notify_fail("ÄãºÃÏó³Ô¹ýÁË°É£¡\n");

        me->add("combat_exp",5000 );
        me->add("potential", 5000);
        me->add("daoxing",5000 );

        tell_object(me,"ºìÓê×£Äã¹ýÄê¿ìÀÖ£¡\n");
        me->set("eaten_liwu",1);
        
        call_out("des",1);
        //destruct(this_object());
        return 1;
}
void des()
{
        destruct(this_object());
}

