// 钓鱼.c
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "钓鱼台");
        set("long", @LONG
你走进这里，哇，有好多的人在这里钓鱼呀！不时的传来兴
奋的喊叫声，这肯定又是有谁钓到了大鱼，看到他们忙忙碌碌、
兴奋的样子，你还有什么值得犹豫的，赶快拿好你的鱼杠开始
钓鱼(diao)吧？
LONG );
        set("exits", ([
                  "down" : __DIR__"eastseashore",
                ]));
        set("no_fight", 1);
        set("no_magic", 1);
        set("no_clean_up", 0);
        set("coor/x",0);
	set("coor/y",0);
	set("coor/z",10);
        setup();
}
void init()
{
        add_action("do_fish", "fish");
        add_action("do_fish", "diao");
}

int do_fish(string arg)
{

        object me;
        me = this_player();

        if (me->query("combat_exp") > 50000) {
                message_vision(HIG"泥巴管理员的身影突然出现在一阵烟雾之中。\n" +
            HIR "泥巴管理员对着$N大喝：别想捣乱，经验这么高了还来钓鱼，你该不是想欺负新手吧！\n\n\n"NOR,me);
                    me->move("/d/city/kezhan");
                     return 1;
                                               } else
        if ( !arg || ( arg != "鱼" ) ) return 
                   notify_fail("你要钓什么啊?\n");
        else

        if (me->query("kee") < 20 )
                return notify_fail("你快支持不住了，先歇会儿吧！\n");
        else
                message_vision("$N拿着一把钓鱼杆坐在大石头上钓起鱼来……。\n", me);
        if (me->is_busy())
                return notify_fail ("你还是等这次掉完在说吧！\n");

                switch(random(10)) {  
                        case 0 :             
                             message_vision("$N一提杆，钓到了一条"+ HIR "大鲤鱼"NOR +"，恭喜，恭喜。 \n\n",me);
                               me->add("potential",30+random(2));
                me->add("combat_exp",80+random(7));
                             me->add("kee",-15);
                           break;
                        case 1 :
                             message_vision("$N猛一提杆，钓到了"+ CYN "一个破草帽"NOR +"，晦气，晦气。  \n",me);
                             message_vision(HIW "$N看着破草帽不由的发呆了。  \n\n" NOR,me);
                             me->add("kee",-5);
                           break;
                        case 2 :
                             message_vision("$N鱼漂晃动，$N心里一急，猛的一提杆，$N钓到了"+ RED "一件红色的肚兜。 \n"NOR,me);
                             message_vision(HIB "$N连声叫到：晦气，晦气。 \n\n" NOR,me);
                             me->add("kee",-7);
                           break;
                        case 3 :
                             message_vision("$N一提杆，钓到了一条"+ HIC "鲶鱼"NOR +"，恭喜，恭喜。 \n\n",me);
         me->add("potential",30+random(2));
me->add("combat_exp",80+random(7));
                             me->add("kee",-6);
                           break;
                        case 4 :
                             message_vision("$N一提杆，钓到了一条"+ HIG "鲑鱼"NOR +"，恭喜，恭喜。 \n\n",me);
               me->add("potential",30+random(2));
me->add("combat_exp",80+random(7));
                             me->add("kee",-12);
                           break;
                        case 5 :
                             message_vision("$N一提杆，钓到了一条草鱼，恭喜，恭喜。 \n\n",me);
            me->add("potential",35+random(2));
me->add("combat_exp",78+random(7));
                             me->add("kee",-10);
                           break;
                        case 6 :
                             message_vision("$N一提杆，钓到了一条"+ HIB "鲟鱼"NOR +"，恭喜，恭喜。 \n\n",me);
me->add("potential",33+random(2));
me->add("combat_exp",80+random(7));
                             me->add("kee",-5);
                           break;
                        case 7 :
                             message_vision("$N猛一提杆，钓到了"+ WHT "一个废旧的睡袋"NOR +"，晦气，晦气。 \n",me);
                             message_vision(HIY"$N看着废旧的睡袋，眼睛立刻红了。 \n\n"NOR,me);
                             me->add("kee",-3);
                           break;
                        case 8 :
                             message_vision("$N猛的一提杆，扯的太急了，线断了，鱼跑了，可惜，可惜。 \n",me);
                             message_vision(HIC "$N不由的在心里大骂:ダドパ。 \n\n" NOR,me);
                             me->add("kee",-7);
                           break;
                        default :
                             message_vision("$N一提杆，钓到了一条"+ HIM "娃娃鱼"NOR +"，恭喜，恭喜。 \n\n",me);
me->add("potential",33+random(2));
me->add("combat_exp",80+random(7));
                             me->add("kee",-8);
                           break;    
                                 }         
                         me->start_busy(2);

        return 1;
}
