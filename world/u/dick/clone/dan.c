// wan.c 气血大补丸

#include <ansi.h>

inherit ITEM;

string *names = ({
  "感激涕零地",
  "狼吞虎咽地",
  "贼头贼脑地",
  "文质彬彬地",
  "高高兴兴地",
});

void create()
{
            set_name(HIB"逍遥丹"NOR, ({ "xiaoyao dan","dan" }) );
        set("long",
HIB"这是雨点采集了九种珍贵药材，费时三年炼制而成的灵丹。有强身健体之功效.\n"NOR);
        set("unit", "粒");
        set("weight", 5);
        set("value", 100);
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object ob,what;
	  int bonus;
        if( !id(arg) ) return notify_fail("你要吃什麽？\n");

        ob=this_player();
	what=this_object();
      int i=random(sizeof(names));
      string hoho=names[i];

//	message_vision("$N拿起一颗$n,"+hoho+"吃了下去...",ob,what);
	  bonus=200+random(300);
	  if (ob->query("family/family_name")=="蜀山剑派")
		bonus=bonus*2;
        ob->add("potential",bonus);
write(HIR+"你得到了"+chinese_number(bonus)+"点潜能!\n"NOR,
               environment(ob), ob);
        destruct(this_object());
        return 1;
}
