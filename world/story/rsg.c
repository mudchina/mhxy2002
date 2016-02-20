//By tianlin@mhxy for 2002.1.9

#include <ansi.h>

string give_gift();

private mixed *story = ({
"五庄观，人参果院内。",
"悟空：八戒，你看这树上的果果样子甚是可爱.......",
"八戒谗的口水流了一地，眼睛死死的盯着人参果：真想尝尝。",
"沙僧：听说人参果三千年才成熟一次，吃了可以长生不老。",
"悟空：真的？该不是镇元那老头自抬身价，骗玉皇那个白痴的吧？",
"沙僧摇了摇头：看果长的样子就知道是真的！",
"悟空：KAO！看样子也能看出来？",
"八戒：猴哥，去“借”几个咱们品尝一下，万一这果不甜，嫦娥姐姐",
"      吃了碜牙就糟了。",
"悟空：这个....万一师傅责怪下来....",
"沙僧：师傅责怪下来就说是风吹下来的。",
"悟空：今天天气晴朗，万里无云，何来风？",
HIW"众默然。"NOR,
"八戒嘻嘻笑到：“这有何难？看俺老猪解决此事”，说罢转过身，高翘屁屁，",
"只听“卟~~~~~~~~”，一阵臭风吹去，众人被熏的昏天晕地,人参果也随风而去。",
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
         STORY_D->give_gift("/clone/gift/obj/renshen-guo", 1,
                           HIM "\n“啪”的一声一枚酷似人参果的东西掉到你面前。正向地里钻去\n\n" NOR);
return HIM "听说人参果被盗，玉皇大帝已经下旨追回。\n" NOR;
}


