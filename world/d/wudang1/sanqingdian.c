//By tianlin@mhxy for 2001.9.27
//部分优化

inherit ROOM;

void create()
{
        set("short", "三清殿");
        set("long", @LONG
这里是凌霄宫的三清殿，是武当派会客的地点。供着元始天尊、太上道
君和天上老君的神像，香案上香烟缭绕。靠墙放着几张太师椅，地上放着几
个蒲团。东西两侧是走廊，北边是练武的广场，南边是后院。
LONG );
        set("valid_startroom", 1);
        set("exits", ([
                "north" : __DIR__"guangchang",
                "south" : __DIR__"houyuan",
                "east"  : __DIR__"donglang1",
                "west"  : __DIR__"xilang",
        ]));
        set("objects", ([
                __DIR__"npc/guxu" : 1,
                __DIR__"npc/song" : 1,
                __DIR__"npc/zhangmen" : 1,
        ]));
//        set("no_clean_up", 0);
        setup();
  call_other("/obj/board/wudang_b", "???");
}

void init()
{
        object me;
        mapping skill_status;
        string *sname;
        int i, level;
        float exper;

        me = this_player();

        exper = to_float(me->query("combat_exp"));

        if ( !(skill_status = me->query_skills()) ) return;
        sname  = keys(skill_status);

        for(i=0; i<sizeof(skill_status); i++)
        {
                level = skill_status[sname[i]];
                if( pow(to_float(level), 3.0) / 10.0 > exper
                && exper > 100.0
                && sname[i] != "buddhism"
                && sname[i] != "literate"
                && sname[i] != "taoism" )
                {
                        level = ceil( pow( exper*10.0, 0.333333) );
                        me->set_skill(sname[i], level);
                }
        }
}
