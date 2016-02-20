//By tianlin@mhxy for 2001.10.10

#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

void clear_room();

void create()
{
       set_name(HIB"韩老板"NOR, ({"han laoban", "han", "laoban", "boss"}));
       set("title", HIR"物品店"NOR);
       set("gender", "男性");
       set("long", "他是一个和蔼可亲的中年人,一看到他不管他的东西好不好,就想买.\n");
       set("age", 21);
       set("per", 14);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("unarmed", 10000);
       set("max_price",20);
       set("vendor_goods", ([
            "yuchang":"/d/shenjian/obj/shop/yuchangjian",
            "zicheng":"/d/shenjian/obj/shop/zicheng",
            "qingzhu":"/d/shenjian/obj/shop/qingzhu",
            "qingxia":"/d/shenjian/obj/shop/qingxia",
            "kandao":"/d/shenjian/obj/shop/kandao",
]) );
        
              setup();
    carry_object("/obj/cloth")->wear();
        
}

void init()
{
        ::init();
              add_action("do_vendor_list", "list");
}
