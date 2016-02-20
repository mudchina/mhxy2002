// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */

inherit NPC;

string *names = ({
  "骅骊马",
  "骐骥马",
  "紫燕马",
  "超光马",
  "赤兔马",
  "追风马",
  "奔霄马",
  "绝尘马",
});

void create()
{
  set_name(names[random(sizeof(names))], ({"tian-ma","horse", "ma"}));
  set("race", "野兽");
  set("age", 20);
  set("long", "一匹能腾云驾雾的天马,日行千里,夜走八百,可以骑(ride)。\n");
//  set("combat_exp", 50000);
  set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
//  set("verbs", ({ "bite"}));

 // set("chat_chance", 1);
 // set_skill("dodge", 100);
 // set_skill("parry", 100);
 // set_skill("unarmed", 100);
 // set("ride/msg", "骑");
 // set("ride/dodge", 20+random(6));
 // set_temp("apply/dodge", 40);
 // set_temp("apply/attack", 40);
 // set_temp("apply/armor", 40);

  setup();
}
void init()
{
        add_action("do_ride", "ride");
}
int do_ride(string arg)
{
        object me = this_player();
        if (!id(arg))
                return notify_fail("你要骑什么？\n");
        if (this_player()->query_temp("marks/骑") ) {
                       write("你已经骑在马上了。\n");
                        return 1;
        }
        else {
               message("vision",this_player()->name() + "翻身上马。\n",
                        environment(me), ({me}) );
               write("你一个翻身,上了马背,姿式极为潇洒。\n");
                this_player()->set_temp("marks/骑", 1);
        return 1;
        }
}
