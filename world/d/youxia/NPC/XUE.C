// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by night 24/7/2000


inherit F_VENDOR_SALE;

void create()
{
  reload("xuyi_xue_laoban");
  set_name("薛老板", ({"xue laoban", "xue", "laopan"}));
  set("shop_id", ({"laoban", "xue"}));
  set("gender", "男性");
  set("combat_exp", 2000);
  set("age", 40);
  set("per", 30);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);
  set("vendor_goods", ([
        "skirt": "/d/xuyi/obj/ziskirt",
        "doupeng": "/d/xuyi/obj/doupeng",
        "guazi": "/d/xuyi/obj/guazi",
        "scarf": "/d/xuyi/obj/scarf",
        "ao": "/d/xuyi/obj/kenao",
      ]) );

  setup();
  carry_object("/d/xuyi/obj/guazi")->wear();
  carry_object("/d/xuyi/obj/scarf")->wear();
}

void init()
{
  ::init();
  add_action("do_vendor_list", "list");
}

