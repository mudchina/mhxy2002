//By tianlin@mhxy for 2002.1.27

inherit ROOM;
int block_cmd(string);
void create ()
{
        set ("short", "第一宫：白羊宫");
        set ("long", @LONG

    :iW$$$$Wi:          :uWW$$$WWx
  :W$$$####$$$$W:    :i$$$$*###*$$$x
  $$$?      ~#$$$X  :$$$#~      ~$$$
  $$$          $$$X:$$$~         8$$!
  #$$i  ~      ~$$$$$$!   :   ~ x$$$
   #$$$WWi$$    ?$$$$$    8$WiW$$$#
     ~""""      ~$$$$!      """""
                 $$$$~  菲利塞斯(Phrixus)乃奈波勒(Nepele)之子，
                 $$$$~蒙上奸污碧雅蒂□ (Biadice)的不白之冤，而被判处死刑，
                 $$$$:临刑之前一只金色的公羊及时将他和妹妹海□(Helle) 一
                 $$$$~起背走不幸的是，妹妹因不胜颠簸，一时眼花落下羊背，
                ~$$$$ 菲利塞斯则安然获救，他将公羊献给宙斯当祭礼，宙斯将
                 ?$$? 它的形象化为天上的星座。后来杰生为了夺取这金羊的羊
                      毛，还展开了一段精彩的冒险故事。

LONG);


        set("exits", ([
        "northup"    :       __DIR__"by2jn1",
            "eastdown"  :       __DIR__"toby2",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/baiyang" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}
int valid_leave(object me, string dir)
{
        if (me->query("12gong/baiyang","done"))
        return ::valid_leave(me, dir);
        if (dir == "northup" ) {
        if (objectp(present("bai yang", environment(me)))&&!wizardp(me))
        return notify_fail("阿雷斯冷笑一声：先过我这关再说！\n");
        }   
        return ::valid_leave(me, dir);
}
void init()
{
    add_action("block_cmd", "", 1);
}
int block_cmd(string args)
{
string verb;
verb = query_verb();
    if (verb == "zhaohuan") return 1;
    return 0;
}
