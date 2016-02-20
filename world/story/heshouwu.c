//By tianlin@mhxy for 2002.1.9

#include <ansi.h>

string give_gift();

private mixed *story = ({
"一座不知名的破庙内。",
"张果老：？？？谁在破庙里煮汤喝呀？",
"突然一声咕噜声传来，原来是张果老的肚子在叫了",
"张果老：哎吆吆...该吃点东西了！", 
"一阵香味传来。",
"张果老：好香呀！",
"张果老顺着香味找去...",
"张果老：？？？谁在破庙里煮汤喝呀？",
"这下可以填饱肚子了，哈哈！",
"张果老转念一想：偷吃别人的东西，有点不太好吧...",
"管他呢，先填饱肚子再说！",
"天道祖师：哎呀，死土驴敢偷喝我的汤！着打！",
"张果老吓了一跳，把汤给打翻了。",
"汤里掉出一个行状似人的东西，入土不见了",
"张果老：不好！快跑！",
"张果老象一溜烟似的，转眼不见了。",
"天道祖师冲着张果老的背影大叫：张果老!我跟你没完!!",
        (: give_gift :)

});

void create()
{
        seteuid(getuid());
}

mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}

string give_gift()
{
         STORY_D->give_gift("/clone/gift/obj/heshou-wu", 1,
                           HIM "\n“啪”的一声一枚酷似人行的东西掉到你面前。正向地里钻去\n\n" NOR);
return HIM "听说天道祖师正在寻找失落的何首乌。\n" NOR;
}


