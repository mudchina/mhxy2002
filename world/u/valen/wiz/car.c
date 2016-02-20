// By tianlin 2001.5.8

#include <ansi.h>
#include <weapon.h>
inherit SWORD;
string check_ip(object ob, object *user);
void create()
{
        set_name(HIG"直升飞机"NOR, ({ "flyto" }) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "架");
                set("value", 500000);
                set("long", "一架军用的直升飞机。\n");        
    }
        setup();
        init_sword(100);
}
void init()
{
        add_action("do_flyto","flyto");
}
int do_flyto(string arg)
{
        int flyto_inventory = 0;
        object obj,me;
        string msg;
        me=this_player();
        if( !arg ) return notify_fail("你要去哪里？\n");
        if( sscanf(arg, "-i %s", arg) ) flyto_inventory = 1;
        if( !arg ) return notify_fail("你要去哪里？\n");
        obj = find_player(arg);
        if(!obj) obj = find_living(arg);
        if(!obj || !me->visible(obj)) {
                arg = resolve_path(me->query("cwd"), arg);
                if( !sscanf(arg, "%*s.c") ) arg += ".c";
                if( !(obj = find_object(arg)) ) {
                        if( file_size(arg)>=0 )
                                return me->move(arg);
                        return notify_fail("没有这个玩家、生物、或地方。\n");
                }
        }
        if(!flyto_inventory && environment(obj))
                obj = environment(obj);
        if( !obj ) return notify_fail("这个物件没有环境可以 flyto。\n");
    if( stringp(msg = me->query("env/msg_mout")) )
       {if (msg!="") message_vision(msg+"\n", me);}
        else
              message_vision(HIC"$N轰的一声把飞机发动起来往高空飞去!\n"NOR, me);
        me->move(obj);
                message_vision(HIC"$N找了个地方把飞机停下来,自己休息了一会!\n"NOR, me);
        if( stringp(msg = me->query("env/msg_min")) )
       {if (msg!="") message_vision(msg+"\n", me);}
        else
              message_vision("", me);
        return 1;
}