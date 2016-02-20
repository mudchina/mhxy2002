inherit ITEM;

int do_move(string arg);

void init()
{
        add_action("do_move", "move");
}

void create()
{
        set_name("镇纸", ({"zhenzhi","zhen zhi"}));
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "\n这是一个紫铜镇纸，油光亮滑，看来有人经常动(move)它\n");
                set("unit", "各");
                set("material", "steel");
                set("no_get", "\n你试着拿下镇纸，但却发现它被固定在桌上，你耗了九牛二虎之力，也没拿下来。\n");
        }
        setup();
}

int do_move(string arg)
{
        object me;
        string dir;
        me = this_player();
        if( !arg ) {
                return notify_fail("你要移动什么?\n");
        }

        if( arg=="zhenzhi" ) {
                if(!me->query_temp("mishi"))
                message_vision("\n$N扳了紫铜镇纸几下，发现它可以左右扳动。\n", this_player());
                if(me->query_temp("mishi"))
                {
                message_vision(
                "$N轻轻转动紫铜镇纸，忽然墙壁哄地一声翻转过来，将$N带入密室。\n", this_player());
                me->move("/d/qujing/heishui/mishi");
                me->delete_temp("mishi");
                }
        }
        if( sscanf(arg, "zhenzhi %s", dir)==1 ) {
                if( dir=="left" ) {
                message_vision("$N将紫铜镇纸轻轻往左移了一下，感觉好象触动到了什么机关枢纽。\n", this_player());
                if(!me->query_temp("move"))
                me->set_temp("move", 1);
                else 
                me->set_temp("move", 0);
                return 1;
                }
                if( dir=="right" ) {
                        message_vision("$N将紫铜镇纸轻轻往右移了一下，感觉好象触动到了什么机关枢纽。\n", this_player());
                if (me->query_temp("move") )        
                        {
                        me->set_temp("mishi", 1); 
                        me->delete_temp("move");
                        }
                return 1;
                }
                else {
                        write("你要把紫铜镇纸往哪移动？\n");
                        return 1;
                      }
        }
return 1;
}

