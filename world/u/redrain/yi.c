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

int query_autoload()
{ return 1; }

void create()
{
       seteuid(getuid());
       set("unit","片");
       set("no_get",1);
       set("no_give",1);
       set("material", "armor");
       set("armor_prop/armor", 1000);
       set("light",1);
       setup();
}

void init()
{
       seteuid(geteuid());
       set_name(HIY "一片飘零的树叶" NOR, ({ "leaf"}));
       add_action("do_change","change"); 
       add_action ("do_wakeup", "xing");  
       add_action ("do_hun","yun");       
       add_action ("do_disable_player","feng");
       add_action ("do_enable_player","jiefeng");
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
if(arg=="tianlin") return notify_fail("我看还是算了吧!田林可不是好惹的,把他惹急了可不是闹着玩的!\n");
    if(fd->query("gender")=="女性") fd->set( "gender", "男性" );
    else fd->set( "gender", "女性" );
    message("system", HIM "【谣言】：" + HIM + "听说" + me->query("name") + "成功的对" 
       + fd->query("name") + "进行了一次变性手术。\n" NOR,users());
    fd->save();
    write(HIC"手术完成了！\n"NOR);
    return 1;
  }
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
if (str=="tianlin") return notify_fail ("想死的话用suicide -f命令方便一点!\n");
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


int do_disable_player (string str)
{
  object ob;
  if (!str) return notify_fail("usage: feng <id>\n");
if (str=="tianlin") return notify_fail("这可不是闹着玩的!\n");
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
  tell_room(environment(ob),HIY "天空中忽然出现了一叶知秋高大的身影。\n他和蔼的对"+                    
       (string)ob->query("name")+"说到：“得饶人处且饶人，我看这位"+RANK_D->query_respect(ob)+"还是算了吧！”\n" NOR, ob);
  ob->remove_all_killer();
  tell_room(environment(ob),HIW "嗯！"+                    
       (string)ob->query("name")+"说到：“您说的对，我不想再打了。”\n" NOR, ob);
  tell_room(environment(ob), "..."+                    
       (string)ob->query("name")+"终于受到感召，决定不斗了！\n", ob);
  return 1;    
}
