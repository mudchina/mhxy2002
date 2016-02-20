#include <ansi.h>
#include <command.h>
inherit F_DBASE;
inherit F_CLEAN_UP;

void create() 
{
        set("channel_id", "惩罚精灵(chengfa)");
}

int main(object me, string arg)
{
        int i;
        object ob,room;
        object *inv, link_ob;
                        
    if (!arg) return 0;                    
        ob=find_player(arg);
        if (!ob) return notify_fail("没有这个人\n");
        if(  wiz_level(me) <= wiz_level(ob) ) 
                 return notify_fail("你没有这个权力。\n");
        CHANNEL_D->do_channel(this_object(), "sys",
                me->name()+"把"+ob->name() + "(" + ob->query("id") + ")被送进了禁闭室！");
          CHANNEL_D->do_channel(this_object(), "rumor",
                ob->name() + "被送进了古惑仔 "+HIW"禁闭室"NOR);
        if(!room =find_object("/d/wiz/punish"))
        room = load_object("/d/wiz/punish");
        ob->move(room);
        ob->save();
        return 1;
}