//By tianlin@mhxy for 2002.1.9

#include <ansi.h>
int give_gift();
mixed *story = 
({
        "一天，韦小宝收到老娘发来的E-mail：",
        "“小宝啊，最近生意不好啊，怎么如今的男人对女人不感兴趣了？”",
        "小宝想了想，跑去找康熙，说如此如此……",
        "康熙：你？不会吧，打死我也不信你会对女人没兴趣。",
        "小宝：哎呀不是我啦，是老娘也就是你弟弟我的兄弟的外甥的舅妈",
        "      开的丽春院最近没什么生意啊！",
        "康熙：恩？有这种事？好，最近吴三桂那小子运了一批从天竺进口的",
        "      XX药，我就御赐给你，以解燃眉之急。",
        "小宝大喜，搂着康熙的肩膀：好小子，够朋友，我这就差人给老娘送",
        "去啦！",        
        "小宝一阵旋风似的飞出宫门。",
        "康熙笑了没多久，忽然想起来，大惊失色：",
        "天啊，晚上我怎么办？",
        "………………",
        (: give_gift :),
});

void create()
{
        seteuid(getuid());
}

mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}

int give_gift()
{
        STORY_D->give_gift("/clone/gift/obj/mcyao", 1,
                           HIM "\n小宝赶到你面前，对你说：就拜托你啦！\n\n" NOR);
        return 0;
}
