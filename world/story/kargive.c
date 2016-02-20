//By tianlin@mhxy for 2002.1.9

#include <ansi.h>

string give_gift();

private mixed *story = ({
        "岳不群：最近真倒霉....",
        "岳夫人说道：倒什么霉？",
        "岳不群：最近真倒霉....",
        "岳不群叹了一口气道：最近辟邪剑法没练成， 鸡鸡到没了......。",
        "岳夫人：.........",
        "岳夫人：" HIY "本门有一种吃了可以变好运的神药！" NOR,
        "岳不群：快拿来....", 
        "岳夫人：" HIG "不好，掉下山了！" NOR,
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
        STORY_D->give_gift("/clone/gift/karwan", 1,
                           HIM "\n“啪”的一声一枚仙丹掉到你面前。\n\n" NOR);
        return 0;
}
