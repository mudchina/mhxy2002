//By tianlin@mhxy for 2002.1.9

#include <ansi.h>

int give_gift();

private mixed *story = ({
        "欧阳克：叔父，帮帮我....",
        "欧阳锋说道：什么事？",
        "欧阳克：最近我做那个事不行了........",
        "欧阳锋叹了一口气道：没用，我60岁还很行。",
        "欧阳克：.........",
        "欧阳锋：" RED "给你我们家祖传的神药补补！" NOR,
        "欧阳克：快拿来....", 
        "欧阳锋：" HIG "突然大叫一声，发了疯..." NOR,
        "欧阳锋：" RED "把丹药扔下了山" NOR,
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

int give_gift()
{
        STORY_D->give_gift("/clone/gift/neili", 1,
                           HIM "\n“啪”的一声一枚仙丹掉到你面前。\n\n" NOR);
        return 0;
}
