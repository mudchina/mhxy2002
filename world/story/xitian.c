//By tianlin@mhxy for 2002.1.9

#include <ansi.h>

string give_gift();

private mixed *story = ({
        "西天，大雷音寺大殿内。",
        "如来：今天有事秉奏，无事退朝。",
        "两旁十八罗汉："HIC"威"NOR+WHT"～～～～～～～"HIM"武"NOR+WHT"～～～～～～～～～。",
        "如来正准备离开，突然一个人走了出来。",
        "观音：我佛如来，泽被苍生，战无不胜，攻无不克，千秋万载，一统天庭。",
        "如来：有话快说，有屁快放。",
        "观音：自从唐僧取了真经，唐半偈取了真解，西天一直没有外宾来访，旅游",
        "      业从此一落千丈。要想个法子才行啊。",
        "如来：这倒是个问题，观音大士可有良策？",
        "观音：不如再写个什么经让他们来取，这样我们也可再把雷音寺搞成旅游胜",
        "      地，说不定还可以开辟一条经书之路什么的呢！",
        "如来：嗯，不错，这件事情就交给你去办了。",
        "观音：这件事情小的已经早就办好了。",
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
         STORY_D->give_gift("/clone/gift/obj/book", 1,
                           HIM "\n“啪”的一声一本《地藏半天经》掉到你面前。\n\n" NOR);
        return HIM "听说西天至宝《地藏半天经》重现人间。\n" NOR;
}

