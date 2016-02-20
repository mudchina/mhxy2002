// 神话世界·西游记·版本（世纪）
/* <SecCrypt CPL V3R05> */

inherit ROOM;


void create()
{
        set("short", "黄泉摆渡船");
        set("long", @LONG

一叶小舟，最多也就能载七、八个人。天间星加路
手持长竹篙，正在船尾撑船。
LONG );
        set("no_clean_up", 0);
        set("outdoors", "changan");
        setup();
        replace_program(ROOM);
}

