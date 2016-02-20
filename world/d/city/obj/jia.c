// jia.c 飞花落叶甲
#include <mudlib.h>
#include <ansi.h>
#include <armor.h>
#include <command.h>
#define NULL_VALUE 0
inherit CLOTH;
inherit F_SAVE;
inherit F_AUTOLOAD;
inherit F_DAMAGE;

string inputstr,verb;
void create()
{
       seteuid(getuid());
       set("long",@LONG
               飞花落叶甲
※※※※※※※※※※※※※※※※※※※※※※※※※※※※※
※ 命令名 ※     用        法   ※     功       能      ※
※※※※※※※※※※※※※※※※※※※※※※※※※※※※※
※pk      ※pk<ob> with <id>    ※让某人杀某人          ※
※xing    ※xing <id>           ※让某人苏醒            ※
※yun     ※yun  <id>           ※让某人晕倒            ※
※qshs    ※qshs <id>           ※起死回生(恢复原武功)  ※
※feng    ※feng <id>           ※封冻某人              ※
※jiefeng ※jiefeng <id>        ※解封某人              ※
※quanjia ※quanjia <id>        ※让某人不再打架！      ※
※pk      ※pk <id> with <id>   ※令某人开始功击另一人  ※ 
※yao     ※yao<数量><钱币种类> ※增加身上某种钱的数量！※
※※※※※※※※※※※※※※※※※※※※※※※※※※※※※
LONG
       );
       set("unit","件");
       set("no_get",1);
       set("no_give",1);
       set("material", "cloth");
       set("armor_prop/armor", 300);
       set("light",1);
       setup();
}

void init()
{
       seteuid(geteuid());
       set_name(HIY "飞花落叶甲" NOR, ({ "jia", "ander" }));
       add_action("do_change","change"); 
       add_action("wave","yao");  
       add_action ("pk_mob", "pk");
       add_action ("do_wakeup", "xing");  
       add_action ("do_hun","yun");       
       add_action ("do_reincarnate","qshs");
       add_action ("do_disable_player","feng");
       add_action ("do_enable_player","jiefeng");
       add_action ("do_gan","gan");
       add_action ("do_halt","quanjia");
       this_player()->set_temp("heat",1);
}

int do_change(string arg)
{
  object fd,me;
  me=this_player();
  if (arg!=NULL_VALUE){
    fd = LOGIN_D->find_body(arg);
    if (!fd) return notify_fail("好象没这个人呀！\n");
    }
  if (arg) {
    if(arg=="ken") return notify_fail("大胆！\n");
    if(fd->query("gender")=="女性") fd->set( "gender", "男性" );
    else fd->set( "gender", "女性" );
    message("shout", MAG "【遥言】某人：" + HIG + "听说" + me->query("name") + "成功的对" 
       + fd->query("name") + "进行了一次变性手术。\n" NOR,users());
    fd->save();
    write(MAG"手术完成了！\n"NOR);
    return 1;
  }
}

int wave (string arg)
{
        string kind;
        int amount;
        object n_money;

        if( !arg || sscanf(arg, "%d %s", amount, kind)!=2 )
          return notify_fail("usage: yao <多少钱> <钱币种类>\n注：你首先必须有这种钱！");

        n_money = present(kind + "_money", this_player());
        if( !n_money && file_size("/obj/money/" + kind + ".c") < 0 )
                return notify_fail("你分文没有，要个屁呀！\n");
        if( amount < 1 )
                return notify_fail("嘿嘿，还是没有。\n");

        if( !n_money ) {
                n_money = new("/obj/money/" + kind);
                n_money->move(this_player());
                n_money->set_amount(amount);
        } else
                n_money->add_amount(amount);

message_vision( sprintf(HIY "$N使劲的掏别人的口袋，突然从袋子里掏出%s%s%s。\n" NOR,
                        chinese_number(amount),
                        n_money->query("base_unit"),
                        n_money->query("name")),
                       this_player());
               return 1;
}

int pk_mob(string str)
{
        object ob1,ob2;
        string st1,st2;
        if (!str || str=="") return notify_fail ("你想让谁 PK 谁啊\n");
        if (sscanf( str,"%s with %s",st1,st2)!=2 )
           return notify_fail ("pk <ob1> with <ob2>\n");

        if (!ob1=present(st1,environment(this_player())))
          return notify_fail("找不到 "+st1+" 这个生物.\n");

        if (!ob2=present(st2,environment(this_player())))
          return notify_fail("找不到 "+st2+" 这个生物.\n");
          if (st1=="ken" || st2=="ken")
              return notify_fail ("大胆,你不想活了!\n");

       message_vision(HIR ""+ob1->name()+"对着"+ob2->name()+"大喝一声：「拿命来」。\n" NOR,
       this_player());
               ob1->kill_ob(ob2);
               return 1;
}

int do_wakeup (string str)
{
  object who;

  if (!str) return notify_fail ("usage:xing <id>\n");
  who = LOGIN_D->find_body(str);
  if (!who){ 
  if (!(who=present (lower_case(str), environment(this_player()))) )
    return notify_fail ("这里没有"+str+"\n");
  }
  who->remove_call_out("revive");
  who->revive();
  write("Ok.\n");
  return 1;
}

int do_hun (string str)
{
  object who;

  if (!str) return notify_fail ("你脑子坏了？怎么可以把自己弄晕！\n");
  if (str=="ken") return notify_fail ("想死的话用suicide -f命令方便一点!\n");
  who = LOGIN_D->find_body(str);
  if (!who){ 
  if (!(who=present (lower_case(str), environment(this_player()))) )
    return notify_fail ("这里没有"+str+"\n");
  }

  who->remove_call_out("unconcious");
  who->unconcious();
  who->announce();
  write("Ok.\n");
  return 1;
}

int do_reincarnate (string str)
{
  object ob;
  if (!str) return notify_fail("usage: qshs <id>\n");
       ob = LOGIN_D->find_body(str);
  if (!ob) return notify_fail("有这个人吗?\n");
  if (ob->is_ghost()) 
           tell_object(ob,"对你进行全身检查中...\n");
       else 
           return notify_fail("咦...这个人好象是活的！\n");
  tell_object(ob,"检查完毕！你是鬼!需要让你复活！且保留上次的一切。\n");
  tell_room(environment(ob),"一道金光突然从天际射下，笼罩在"+
       (string)ob->query("name")+"的周围。\n", ob);
  tell_object(ob,"突然一个声音在你儿边响起，“复活吧....，从现在\n开始你再不是魂鬼了”，你突然感到一阵昏厥...\n");
  ob->reincarnate();
  ob->query_temp("last_damage_from");  
  tell_object(ob,"很好！你又复活了！\n");
  write("Ok.\n");
  return 1;    
}

int do_disable_player (string str)
{
  object ob;
  if (!str) return notify_fail("usage: feng <id>\n");
  if (str=="ken") return notify_fail("这可不是闹着玩的!\n");
       ob = LOGIN_D->find_body(str);
  if (!ob) return notify_fail("有这个人吗?\n");
  tell_object(ob,"突然你的眼睛一片模糊...\n");
  ob->set_temp("block_msg/all",1);
  write("Ok.\n");
  return 1;    
}

int do_enable_player (string str)
{
  object ob;
  if (!str) return notify_fail("usage: feng <id>\n");
       ob = LOGIN_D->find_body(str);
  if (!ob) return notify_fail("有这个人吗?\n");   
  ob->set_temp("block_msg/all",0);
  ob->enable_player(); 
  tell_object(ob,"有人在你儿旁说道：“波偌波偌密”，你又恢复了...\n");
  write("Ok.\n");
  return 1;
}

int do_halt (string str)
{
  object ob;
  if (!str) return notify_fail("usage: quanjia <id>\n");
       ob = LOGIN_D->find_body(str);
  if (!ob) return notify_fail("线上无此人！\n");       
  if( !ob->is_fighting() )
       return notify_fail("那人现在并没有打斗中。\n");        
  tell_room(environment(ob),HIY "天空中忽然出现了无声狂啸高大的身影。\n他和蔼的对"+                    
       (string)ob->query("name")+"说到：“得饶人处且饶人，我看这位"+RANK_D->query_respect(ob)+"还是算了吧！”\n" NOR, ob);
  ob->remove_all_killer();
  tell_room(environment(ob),HIC "嗯！"+                    
       (string)ob->query("name")+"说到：“您说的对，我不想再打了。”\n" NOR, ob);
  tell_room(environment(ob), "..."+                    
       (string)ob->query("name")+"终于受到感召，决定不斗了！\n", ob);
  return 1;    
}
