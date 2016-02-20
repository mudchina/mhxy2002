//By tianlin@mhxy for 2002.1.9

#include <ansi.h>
int give_gift();
mixed *story = 
({
        "上帝：摩西，当年你出埃及的那本圣经在哪里？",
        "摩西：啊，伟大的主，它一直在我的身边。",
        "上帝：恩，很好，你看现在人间自相残杀，血腥迷漫，我想净化他们。",
        "摩西：全能的主啊，应该怎么办呢？",
        "上帝：我想、把圣经交给他们，感化他们已经邪恶的心灵。",
        "摩西：喔，My God！",
        "上帝：有什么不妥吗？",
        "摩西：啊，没有没有……",
        "上帝：那就行了，赶快把圣经交给教父吧。",
        "摩西：好的，我立刻就去。",
        "一本书从天上掉下来，随后传来一声尖叫……",
        "摩西：天啊，我丢错人了！Faint！！",
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
        STORY_D->give_gift("/clone/gift/obj/bible", 1,
                           HIM "\n一本莎草纸的古老圣经掉到你的面前。\n\n" NOR);
        return 0;
}
