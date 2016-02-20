//By tianlin@Mhxy for 2002.1.8
#include <ansi.h>

inherit ITEM;

void create()
{
            set_name(HIC"灾难丸"NOR, ({ "wan","zainan wan" }) );
        set("long",
HIG"这是由全体巫师对所有玩家的一点补偿.\n"NOR);
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
        object ob;
        if( !id(arg) ) return notify_fail("你要吃什麽？\n");

          if( living( this_player())==0) return 0;

          if( living( this_player())==0) return 0;

         ob=this_player(); 
         ob->set("combat_exp",300000);
 ob->set("daoxing",200000);
 ob->set("per",40);
 ob->set("kar",40);
 ob->set("int",40);
 ob->set("cps",40);
 ob->set("cor",40);
 ob->set("cps",40);
 ob->set("str",40);
         ob->set("max_force",1500);
         ob->set("max_mana",1500);
         ob->set("force",1500);
         ob->set("mana",1500);
         ob->set("maximum_force",1500);
         ob->set("maximum_mana",1500);
write(HIR+"你吃下一颗灾难丸，只觉得一种神力融入你的体内!输入hp看一下吧...\n"NOR);

        message("vision", HIR + ob->name() + 
"吃下一颗灾难丸，只觉得一种神力融入你的体内!输入hp看一下吧...\n"+NOR,
                environment(ob), ob);
        destruct(this_object());
        return 1;
}
