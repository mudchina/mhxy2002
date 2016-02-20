//By tianlin@mhxy for 2002.1.9

#include <ansi.h>
string give_gift();
mixed *story = 
({
        "某天hxsd正在宁远城内，提笼架鸟满街遛，忽然集市上一阵骚动",
        "某人：不好啦，野羊山土匪下山啦，大家快跑啊！……",
        "没等hxsd反应过来，一伙土匪已经窜到他面前，抽出西瓜刀……",
        "土匪：不许动，把所有值钱的东西交出来！",
        "hxsd想大声呼救，结果发现没有一个人了，都溜的精光，跑的比球还快。",
        "没办法，看着刀已经抵上了前胸后背，形势危急……",
        "“快点！m d，大爷没时间跟你磨蹭！”土匪头子大叫。",
        "hxsd“嘿嘿”地奸笑了两声，“勒索我？谁勒谁呀？”",
        "只见hxsd高举双手，大喝：“去死把!”, 只见天上一道电光闪过，",
        "咆哮的雷暴自天而降，向着地上奔去……",
        (: give_gift :),
        "……",
        "………………",
        "土匪头子吓了半晌，破口大骂：“n n d，你这家伙玩的什么把戏？”",
        "hxsd心中一凛，“坏了，劈错了，如今三十六计，惟有上计……”",
        "于是hxsd迅速键入“home”……",
        "只见一阵烟雾过後，hxsd的身影已经不见了。",
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
        
        int i;
        object env,ob;
        object *players;
        string msg;

        players = users();
        if (sizeof(players) >= 5)
        {
                for (i = 0; i < 5; i++)
                {
                        ob = players[random(sizeof(players))];
                        if (wizardp(ob)) continue;
                        if (ob->is_fighting()) continue;
                        if (!environment(ob)) continue;
                        if (ob->query_temp("netdead")) continue;
                        
                                
                }
                if(!ob) return "";
               tell_object(ob,HIW"一阵轰隆隆的雷声响过，一道闪电从天而降，不偏不倚\n"
                		"的砸到你头上，你登时就晕了过去……\n\n" NOR);
                ob->unconcious();
                msg=HIW"天上降下一道闪电，将"+ob->name()+"劈晕了.......\n"NOR;
                env=environment(ob);
                if (objectp(env))
                        tell_room(env, msg);
        }

        CHANNEL_D->do_channel( this_object(),"rumor",HIM"好像有人被闪电劈中了....................\n"NOR);
        return HIM "好像有人被闪电劈中了....................\n" NOR;
}
