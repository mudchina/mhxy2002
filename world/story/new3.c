//By tianlin@mhxy for 2002.1.9

#include <ansi.h>
int give_gift();
mixed *story = 
({
        "�ϵۣ�Ħ������������������Ǳ�ʥ�������",
        "Ħ��������ΰ���������һֱ���ҵ����ߡ�",
        "�ϵۣ������ܺã��㿴�����˼������ɱ��Ѫ�����������뾻�����ǡ�",
        "Ħ����ȫ�ܵ�������Ӧ����ô���أ�",
        "�ϵۣ����롢��ʥ���������ǣ��л������Ѿ�а������顣",
        "Ħ����ร�My God��",
        "�ϵۣ���ʲô������",
        "Ħ��������û��û�С���",
        "�ϵۣ��Ǿ����ˣ��Ͽ��ʥ�������̸��ɡ�",
        "Ħ�����õģ������̾�ȥ��",
        "һ��������ϵ������������һ����С���",
        "Ħ�����찡���Ҷ������ˣ�Faint����",
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
                           HIM "\nһ��ɯ��ֽ�Ĺ���ʥ�����������ǰ��\n\n" NOR);
        return 0;
}