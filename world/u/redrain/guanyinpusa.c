// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// guanyin.c 观音菩萨
// By Dream Dec. 19, 1996

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

int do_drop(object, object);
string ask_me();

void create()
{
   set_name("观音菩萨", ({ "guanyin pusa", "guanyin", "pusa" }));
   set("title", "救苦救难大慈大悲");
   set("long", @LONG
理圆四德，智满金身。眉如小月，眼似双星。兰心欣紫竹，
蕙性爱得藤。她就是落伽山上慈悲主，潮音洞里活观音。
LONG);
   set("gender", "女性");
   set("age", 35);
   set("attitude", "peaceful");
   set("rank_info/self", "贫僧");
   set("rank_info/respect", "菩萨娘娘");
   set("class", "bonze");
           set("str",24);
   set("per",100);//means no rong-mao description.
   set("max_kee", 5000);
   set("max_gin", 5000);
   set("max_sen", 5000);
   set("force", 4000);
   set("max_force", 2000);
   set("force_factor", 145);
   set("max_mana", 3000);
   set("mana", 6000);
   set("mana_factor", 150);
   set("combat_exp", 4000000);
   set_skill("literate", 250);
   set_skill("spells", 400);
   set_skill("buddhism", 400);
   set_skill("unarmed", 350);
   set_skill("jienan-zhi", 350);
   set_skill("dodge", 380);
   set_skill("lotusmove", 360);
   set_skill("parry", 350);
   set_skill("force", 380);
   set_skill("lotusforce", 380);
   set_skill("staff", 350);
   set_skill("lunhui-zhang", 300);
   set_skill("spear", 300);
   map_skill("spells", "buddhism");
   map_skill("unarmed", "jienan-zhi");
   map_skill("dodge", "lotusmove");
   map_skill("force", "lotusforce");
   map_skill("parry", "lunhui-zhang");
   map_skill("staff", "lunhui-zhang");
   set("chat_chance_combat", 80);
   set("chat_msg_combat", ({
     (: cast_spell, "bighammer" :),
   }) );
   set("inquiry", ([
        "伏魔"     : (: ask_me :),
   ]));

   //hehe, since guanyin was killed several times
   //let's use cast bighammer to protect her...weiqi:)
   create_family("南海普陀山", 1, "菩萨");

   set("no_clean_up", 1);
   setup();
   carry_object("/d/nanhai/obj/jiasha")->wear();
   carry_object("/d/nanhai/obj/nine-ring")->wield();
}

//add by lpg

string ask_me()
{
        object obj;
   if((int)this_player()->query("combat_exp") < 280000 )
     return "你那点道行还想伏魔？\n";
   message_vision("观音对$N笑道：你用howdo试试缘分\n", this_player());
   return "快试...";
}

void init()
{
   add_action("do_how", "howdo");

   if( query("started") != 1 )
   {
     set("started", 1);
     call_out("generate_book", 36000);//10 hours
   }
}

void generate_book()
{
   remove_call_out("generate_book");
   set("available", 1);
}

int do_how(string arg)
{
   object me, book;

   me = this_player();

   if( query("available") == 1 )
   {
     set("available", 0);
     book = new("/d/obj/book/forcebook2");
     book -> move(this_player());
     message_vision("真有缘，给你。\n", me);
     command("chat "+this_player()->query("name")+"有缘，得到《伏魔山心经下卷》！");

     remove_call_out("generate_book");
     call_out("generate_book", 36000);//10 hours

     return 1;
   }
   else return
     notify_fail("你来的不是时候。\n");
}

int clean_up()
{
   return 0;
}
//end.lpg

void attempt_apprentice(object ob)
{
   if (!((string)ob->query("bonze/class") =="bonze" )) {
     command("say 我佛门神通广大，" + RANK_D->query_respect(ob) + "欲成正果，先入我门。\n");
     write("看样子观音菩萨对你未剃度出家颇为不快。\n");
     return;
   }   
   if (((int)ob->query_skill("buddhism", 1) < 80 )) {
     command("say " + RANK_D->query_respect(ob) + "不在佛法上苦修，恐怕难成正果。\n");
     return;
   }
   command("pat " + ob->query("id") );
   command("say 好！这才是我佛门的好弟子。只要多加努力，定可早成正果。\n");

   command("recruit " + ob->query("id") );
   return;   
}
void die()
{
   int i;
   string file;
   object *inv;

        if( environment() ) {
        message("sound", "\n\n观音菩萨摇头叹道：刚离迷障，又入魔障，世间疾苦，何人度之！\n\n", environment());
        command("sigh");
        message("sound", "\n观音菩萨驾祥云，登彩雾，径往西方去了。。。\n\n", environment());
        inv = all_inventory(this_object());
   for(i=0; i<sizeof(inv); i++) {
     if (inv[i]->query("no_drop")) continue;
     do_drop(this_object(), inv[i]);
//     if (stringp(file = find_command("drop")) && 
//        call_other(file, "do_drop", this_object(), inv[i])) ;
   }
   }

   destruct(this_object());
}

int do_drop(object me, object obj) {
  if (obj->move(environment(me))) {
      //d_mana>0 is for "bian". mon 11/05/97
      if((obj->query_temp("d_mana"))>0) {
            if( obj->query_temp("is_living")==1 )
                 message_vision("$N将$n从背上放了下来，躺在地上。\n", me, obj);
            else {
                 message_vision( sprintf("$N丢下一%s$n。\n",
                 undefinedp(obj->query_temp("unit"))?
                    "个":obj->query_temp("unit")
                         ), me, obj );
           }
      } else {
           if( obj->is_character() )
                  message_vision("$N将$n从背上放了下来，躺在地上。\n", me, obj);
           else {
             message_vision( sprintf("$N丢下一%s$n。\n", obj->query("unit")),
                     me, obj );
             if( !obj->query("value") && !obj->value() ) {
                tell_object(me,"因为这样东西并不值钱，所以人们并不会注意到它的存在
        。\n");
                destruct(obj);
             }
           }
      }
      return 1;
  }
  return 0;
}


void unconcious()
{
   die();
}
//LPG 19990925 真假美猴王
void announce_success (object who)
{
  int i;

  if (who->query("obstacle/liuer-mihou") == "done")
    return;
  if (! who->query_temp("obstacle/liuer-mihou/liuer-mihou_killed"))
    return;
  i = random(600);
  who->add("obstacle/number",1);
  who->set("obstacle/liuer-mihou","done");
  who->add("combat_exp",i+4000);
  command("chat "+who->query("name")+"识破假猴王，取回包裹！");
  command("chat "+who->query("name")+"顺利闯过西行又一关！");
  tell_object (who,"你赢得了"+chinese_number(4)+"年"+
               chinese_number(i/4)+"天"+
               chinese_number((i-(i/4)*4)*3)+"时辰的道行！\n");
  who->save();
}

