// 灵月仙界 by Calvin
#include <ansi.h>
inherit ROOM;
void create()
{
set ("short","灵月仙界");
set ("long",@LONG
           人间烦不在 自由只清闲
                         寂寞多空洞 仙界逍又遥
LONG);
set("exits",([
]));

        set("objects", 
        ([ //sizeof() == 1
        "/d/longzhu/npc/buma" : 1,
        ]));

set("outdoors", 0);
set("no_clean_up", 1);
set("valid_startroom", 1);
setup();
}
void init()
{
object who=this_player();
if( (string)who->query("gender")=="男性" || (string)who->query("gender")=="女性" )
add_action("do_stop", "exert");
add_action("do_stop", "cast");
add_action("do_stop", "kill");
add_action("do_stop", "fight");
add_action("do_stop", "perform");
add_action("do_stop", "apply");
add_action("do_stop", "sleep");
add_action("do_stop", "exercise");
add_action("do_stop", "meditate");
{
call_out("heal_up", 9, who);
}
remove_call_out("sounding");
call_out("sounding", random(10), this_object());
}
int sounding(object where)
{
string *msgs=({
HIG"几只蝴蝶轻轻地在你面前飞过。\n"NOR,
HIY"远处飘来几朵美丽的彩云。\n"NOR,
HIY"几丝雨点飘落在你的身上,温柔多至。\n"NOR,
HIC"阵阵花香飘来,那香味令人陶醉。\n"NOR,
});
tell_room (where,msgs[random(sizeof(msgs))]);
}
int heal_up(object who)
{
if( !who || environment(who) != this_object() )
{
return 1;
}
who->set("eff_gin", (int)who->query("max_gin")*50/100);
who->set("eff_kee", (int)who->query("max_kee")*50/100);
who->set("eff_sen", (int)who->query("max_sen")*50/100);
message_vision(HIW"布玛指着$N说道:什么风把$N给吹我这灵月仙界来啦!\n"NOR, who);
write(YEL"布玛满脸的高兴样,真是无比漂亮。\n"NOR);
if( (int)who->query("food") < (int)who->max_food_capacity() )
who->set("food", (int)who->max_food_capacity());
if( (int)who->query("water")< (int)who->max_water_capacity())
who->set("water", (int)who->max_water_capacity());
return 1;
}
int do_stop(string arg)
{
object who = this_player();
object me = this_object();
message_vision(HIR"远远传来"NOR+HIC"布玛"NOR+HIR"的叫骂声：“谁让$N来我这乱砍乱糟蹋的,请$N回去吧!”\n"NOR,who);
return 1;
}
