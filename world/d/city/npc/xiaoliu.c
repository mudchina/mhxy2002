#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

void clear_room();

void create()
{       
       set_name(HIW"姚富贵"NOR, ({"yao fugui", "yao"}));
       set("long",
"姚老板是高家集人，后来挣了钱，开了家布店。\n");
       set("gender", "男性");
        set("title",HIB "布店老板" NOR);
        set("combat_exp", 10000);
       set("age", 36);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("unarmed", 35);
	set_skill("dodge", 30);
	set_skill("parry", 35);
       set("vendor_goods", ([
                "hat": "/d/gao/obj/hat",
                "shoes": "/d/gao/obj/shoes",
                "magua": "/d/gao/obj/magua",
                "pipao": "/d/gao/obj/piyi",
                       "kui": "/clone/armor/kui",
                            "zhanpao": "/clone/armor/pao",
                            "jinjia": "/clone/armor/jinjia",
"rake": "/u/talk/obj1/rake",
                            "shoes": "/clone/armor/shoes",
                            "dun": "/clone/armor/dun1",
"san": "/u/talk/obj1/umbrella",
                              "pifeng": "/clone/armor/jrpf",
                           "zhizheyi": "/clone/armor/zhi",
                           "shoes1": "/clone/armor/shoes1",
                             "zhonggang": "/clone/armor/kj",

]) );
        
              setup();
//          carry_object("/d/obj/cloth/cloth")->wear();
        
}

void init()
{
        ::init();
              add_action("do_vendor_list", "list");
}

