#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

void clear_room();

void create()
{
        set_name("ÏôÏô", ({"xiao xiao", "xiao"}));
  set("title", "¶ñÄï×Ó");
   set("gender", "Å®ÐÔ");
set("long", "ÀÏÓ¢ÐÛÏôÕñÔ¶µÄÐ¡Å®¶ù£¬±øÆ÷ÆÌÅ®ÀÏ°å¡£ 10  ÓÉÓÚÐ×ÂùºÝ¶¾£¬½­ºþÈË³Æ£¢¶ñÄï×Ó£¢¡£\n");
       set("age", 26);
       set("per", 14);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("unarmed", 10);
       set("max_price",20);
        set("vendor_goods", ([
  "fenghuang":"/clone/armor/fenghuang",
          "fork":"/clone/armor/fork",
            "dashenbian":"/clone/armor/whip",
       "kaishanchui":"/clone/armor/hammer",
            "shenweibang":"/clone/armor/bang",
    "damodao":"/clone/armor/blade",
     "jian":"/clone/armor/sword",
 "tianmochu":"/clone/armor/staff",
     "dianjinqiang":"/clone/armor/spear",
      "mace":"/clone/armor/mace",
]) );
        
              setup();
//    carry_object("/d/obj/cloth/cloth")->wear();
        
}

void init()
{
        ::init();
              add_action("do_vendor_list", "list");
}
