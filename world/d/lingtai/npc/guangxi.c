// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// guang.c

inherit NPC;
inherit F_MASTER;
int borr_me(object ob);
void create()
{
        set_name("广羲子", ({"guang xizi", "guang"}));
        set("title", "经阁总管");
        set("gender", "男性" );
        set("age", 53);
        set("long", "一个看起来慈眉善目的道士，正拿着一本经书读着．\n");
   set("class", "toaist");
        set("combat_exp", 180000);
        set("attitude", "friendly");
      set("faith",1000);
   set("force", 400);
   set("max_force", 400);
   set("force_factor", 40);
   set("max_mana", 400);
   set("mana", 400);
   set("mana_factor", 30);
   set("max_kee", 800);
   set("max_sen", 800);

        set("eff_dx", 60000);
        set("nkgain", 250);

   set_skill("dodge", 80);
   set_skill("parry", 80);
   set_skill("puti-zhi", 80);
   set_skill("jindouyun", 80);
   set_skill("unarmed", 80);
   set_skill("jindouyun", 80);
   set_skill("literate", 100);
   map_skill("dodge", "jindouyun");
   map_skill("unarmed", "puti-zhi");
        set("per", 30);
   set("str", 25);
        create_family("方寸山三星洞", 2, "弟子");

   set("inquiry", ([
                "book": "这里大多是我们道教经典，也有些平常书籍。",
            "道德经": (: borr_me :),
        ]) );
        setup();
carry_object("/d/lingtai/obj/xiangpao")->wear();
   carry_object("/d/lingtai/obj/daoguan")->wear();
}
int borr_me(object ob)
{       object m;
        ob = this_player();
        if ((string)this_player()->query("family/family_name")=="方寸山三星洞") {
     if( (int)this_player()->query_skill("literate", 1) < 10 ) {
        message_vision("$N对$n说：你读书写字太差，借给你恐怕也看不懂啊。\n", this_object(), ob);
        return 1;
     }
     if ( (int)this_object()->query("daode") ) {
        message_vision("$N一拱手，说：刚借出去，明天再来吧！\n", this_object());
        return 1;
     }
                m=new("/d/lingtai/obj/daode");
                m->move(ob);
     this_object()->set("daode", 1);
     message_vision("$N从架上拿下本书来递给$n，说：看在你勤奋的份上，就借给你吧！\n", this_object(), ob);
                return 1;
        }
   message_vision("$N说：我们这里的书不外借！\n", this_object());
   return 1;
}

void init()
{
  ::init();
  if(this_player()->query("lingtai_quest/quest_type")=="抄经"){
    command("say 太好了，这位道长可否帮忙把南华抄将一份？(agree yes/no)");
    this_player()->set_temp("chao_jing",1);
    add_action("do_agree","agree");
  }
}

int do_agree(string arg)
{
  object me=this_player();
  if(!me->query_temp("chao_jing"))return 1;
  me->delete_temp("chao_jing");
  if(arg=="no")return 1;
  if(arg=="yes"){
    command("say 这儿有一卷庄子南华经，你去替我抄了来。");
    message_vision("$N在一张桌子旁坐下，拿起毛笔，聚精会神地抄了起来。\n",me);
    me->start_busy(5);
    call_out("finish_chaojing",5,me);
    return 1;
  }
}

void finish_chaojing(object me)
{
  message_vision("$N抄了许久，终于将一卷经抄完了，松了一口气，只觉得手臂酸软。\n",me);
  command("thank "+me->query("id"));
  me->set("lingtai_quest/done",1);
}
