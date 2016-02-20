inherit ROOM;
void init();
void create()
{
        set("short", "龙冢");
        set("long", @LONG 
枯骨遍地，奇珍满屋，这里就是龙族成员死后的埋骨之所，
只见满屋奇形怪状的龙骨骷髅中，有一具骷髅(skeleton)
身披一件雪白皮甲，傲然坐在龙冢正中，虽然已成白骨，
仍给人一种威猛绝伦，霸绝天下的感觉。
LONG);
        set("exits", ([
            "out" : __DIR__"yandong",
        ]));
        set("remove_available" , 1);
        set("item_desc", ([
      "skeleton" : "这是当年纵横西海的神龙，乃昔年蚩尤坐骑，后被敖顺\n所杀，但就连敖顺也敬其气节，将其葬在龙冢之内。他\n身穿一件白色皮甲，你可以试着脱(remove)下来\n",
        ]) );
        setup();
}

void init()
{
           object me = this_player();
        add_action("do_remove", "remove");
            me->set_temp("long", 0); 
}

int do_remove(string arg)
{
       object me,obj,killer;

       me = this_player();
       if( !arg || arg!="skeleton" )
              return notify_fail("你要脱什么? \n");
       if ( query("remove_available") )
       {
         message_vision("$N恭恭敬敬地对枯骨磕了三个响头,将龙皮甲取下。
\n",this_player() );
         obj = new (__DIR__"obj/jia");
         obj->move(me);
         add("remove_available", -1);
         me->start_busy(3);
         if ( me->query_temp("long") ) return 1;
         killer = new (__DIR__"npc/kulou") ;
         message_vision("\n地上骷髅突然飞起组合，变成一条骷髅龙，气势汹汹向$N扑来。\n"
         "对$N喝道：贼子敢尔！连龙神的东西你也敢动！\n", me);
         killer->move(environment(me));
         killer->kill_ob(me);
         me->set_temp("long", 1);
       return 1;
       }
    message_vision ("$N高高兴兴地伸手向骷髅抓去，却什么也没拿到。\n",me);  
    message_vision ("原来龙皮甲早就被人拿走了。\n",me);  

       return 1;
}

int valid_leave(object me, string dir)
{
        if (objectp(present("kulou long", environment(me))) && 
                     (dir == "out")&& living(present("kulou long", environment(me))))
                return notify_fail("骷髅龙挡住门口，要跟你决一死战。\n");
        return ::valid_leave(me, dir);
}

