//By tianlin@mhxy for 2002.1.9

#include <ansi.h>
int give_gift();
mixed *story = 
({
        "华山之巅，云雾旋绕、仙气升腾。",
        ""HIM"【雄霸公告】"NOR+WHT"华山长老风清扬决定与武当始祖张三丰于猴年马月鸡日猪时",
        "            举行华山论剑，一决高下！",
        "风清扬傲然说道：“念你是武当始祖的份上，且让你先出招！”",
        "张三丰面色由红变紫，唰的一声抽出寒光闪闪的"HIC"真武剑"NOR+WHT"，道：“那我就不",
        "客气了！”",
        "张三丰使出太极剑法"HIR"「缠」"NOR+WHT"字诀，连递数个虚招企图扰乱风清扬的攻势。",
        "风清扬hoho的奸笑了两声。",
        "风清扬举剑画弧，默潜独孤九剑之"HIY"「破式总诀」"NOR+WHT", 绵绵剑意，漫天铺地袭",
        "向张三丰。",
        "张三丰顿时觉得眼前一花，手腕一麻，手中"HIC"真武剑"NOR+WHT"脱手而出！",
        (: give_gift :),
        "“啊！啊！！这……这怎么可能？？？”张三丰大叫。",
        "风清扬收回风泉宝剑，看着面红耳赤的张三丰，说：“ben，我就等着你",
        "出剑，是不是很后悔啊，乖，别哭，等下给你买棒棒糖……嘿嘿……",
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
        STORY_D->give_gift("/clone/gift/obj/zwsword", 1,
                           HIM "\n一把蓝幽幽的"HIC"真武剑"HIM"从天而降，擦过你的鼻尖，\n"
                           +"深深地插入你脚边的泥土里，把你吓出一身冷汗。\n" NOR);
        return 1;
}
