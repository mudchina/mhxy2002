//【蜀山派】mhxy-yushu 2001/2
inherit F_VENDOR_SALE;
void create()
{
  reload("shushan_jiuboss");
  set_name("马老板", ({"ma laoban", "laoban","boss"}));
  set("shop_id", ({"laoban", "ma", "boss"}));
  set("gender", "男性");
  set("title", "酒店老板");
  set("combat_exp", 10000);
  set("age", 50);
  set("per", 34);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 50);
  set("vendor_goods", ([
        "lachang": "/d/obj/food/dishes/dish01",
        "ziji": "/d/obj/food/dishes/dish02",
        "menrou": "/d/obj/food/dishes/dish03",
        "xunyu": "/d/obj/food/dishes/dish04",
        "paigu": "/d/obj/food/dishes/dish05",
        "rousi": "/d/obj/food/dishes/dish06",
        "daxia": "/d/obj/food/dishes/dish07",
        "kaoya": "/d/obj/food/dishes/dish08",
        "sue": "/d/obj/food/dishes/dish09",
        "jiding": "/d/obj/food/dishes/dish10",
        "dusi": "/d/obj/food/dishes/dish11",
        "feipian": "/d/obj/food/dishes/dish12",
  ]));
  setup();
  carry_object("/d/obj/cloth/choupao")->wear();
}
void init()
{
  ::init();
  add_action("do_vendor_list", "list");
  remove_call_out ("heheing");
  call_out ("heheing",5+random(10),this_object());
}
void heheing (object who)
{
  if (random(2))
    command("hoho");
  else
    command("smile");
}
