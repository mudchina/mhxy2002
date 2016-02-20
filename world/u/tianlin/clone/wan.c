// wan.c 气血大补丸

#include <ansi.h>

inherit ITEM;

void create()
{
            set_name(HIR"气血"HIY"大补丸"NOR, ({ "wan","dabu wan" }) );
        set("long",
HIG"气血大补丸是以绯村剑心的秘方，采集九种珍贵药材，费时三年炼制而成的灵丹。有强身健体之功效\n"NOR);
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
          ob->set("daoxing",2000000);
           ob->set("max_kee",1000);
           ob->set("max_sen",1000);
              ob->set("eff_kee",1000);
              ob->set("eff_sen",1000);
             ob->set("kee",1000);
             ob->set("sen",1000);
            ob->set("combat_exp",1600000);
          ob->set("potential",15000);
         ob->set("max_force",2000);
          ob->set("max_mana",2000);
         ob->set("force",2000);
         ob->set("mana",2000);
         ob->set("maximum_force",2000);
         ob->set("maximum_mana",2000);
           ob->add("balance",200000);
write(HIR+"你吃下一颗气血大补丸，只觉得一种神力融入你的体内!输入hp看一下吧...\n"NOR);

        message("vision", HIR + ob->name() + 
"吃下一颗气血大补丸，只觉得一种神力融入你的体内!输入hp看一下吧...\n"+NOR,
                environment(ob), ob);
        destruct(this_object());
        return 1;
}
