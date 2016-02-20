#include <mudlib.h>
#include <armor.h>
#include <ansi.h>
#include <dbase.h>
#include <command.h>
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
set("long",@LONG
    这是田林的魔法披风，有着神奇的魔力。
LONG
);
  set("unit","件");
  set("material", "cloth");
  set("armor_prop/armor", 300);
  set("armor_type", "cape");
  set("light",1);
  setup();
}

void init()
{
  object me;
  seteuid(geteuid());
  me = this_player();
  if (me)
      set_name ("田林的魔法师披风", ({ "cloak", "pifeng" }));
  else
      set_name (HIM"田林的魔法师披风"NOR, ({ "cloak", "pifeng" }));
              add_action("rsgrsg", "rsgrsg");
               add_action("money", "money");
  add_action("help","help");
               add_action("bank", "bank");
                 add_action("mymap", "mymap");
  this_player()->set_temp("heat",1);
}
int help(string str)
{
  if (str!="cloak") return 0;
write(@Help
    你现在可以使用以下的几个命令:
1.bank id---查看这个id的钱庄存款
2.rsgrsg id---查看这个id吃过多少个人参果
3.money <number> <type>---取出哪种钱币的多少数目>
Help
);
return 1;
}
    int bank(string arg)
{
                int age,gold,silver,coin,temp;
    object me;
        if(!arg) 
                return notify_fail("你想查谁的存款？\n");
me=this_player();
 message_vision(HIY "$N口中念了几句咒文，眼中突然精光一闪，大喝一声“铁算盘何在！”\n只见铁算盘慌慌张张地报着帐本跑过来，在$N耳边低声说了几句话。\n" NOR, me);
        me = find_player(arg);
        if(!me) {
            me=present(arg,environment(this_player()));
              if(me && !living(me)) me=0;
        }
          if( !me ) me = find_living(arg);
          if(!me || (me->query("env/invisibility") && wizardp(me) ))
                return notify_fail("奇怪，找不到这个人．．．\n");
          age = me->query("balance");        
gold=age/10000;
temp=age-gold*10000;
silver=temp/100;
coin=temp-silver*100;
        write("铁算盘告诉你："+me->query("name")+"在钱庄有" + chinese_number(gold) + "两黄金"+chinese_number(silver)+"两白银"+chinese_number(coin)+"文铜板.\n");
        return 1;
}
      int rsgrsg(string arg)
  {
              int rsg_number;
      object me;
          if(!arg) 
                  return notify_fail("你想查谁吃了多少人参果？\n");
me=this_player();
message_vision(HIY "$N口中念了几句咒文，眼中突然精光一闪，大喝一声“六耳猕猴何在！”\n只见六耳猕猴一个筋斗云从花果山飞了过来，在$N耳边低声说了几句话。\n" NOR, me);
          me = find_player(arg);
          if(!me) {
             me=present(arg,environment(this_player()));
                if(me && !living(me)) me=0;
          }
            if( !me ) me = find_living(arg);
            if(!me || (me->query("env/invisibility") && wizardp(me) ))
                  return notify_fail("奇怪，找不到这个人．．．\n");
           rsg_number = me->query("rsg_eaten");   
 write("六耳猕猴告诉你："+me->query("name")+"已经吃了" + chinese_number(rsg_number) + "枚人参果了。\n");
          return 1;
}
int money (string arg)
{
        string kind;
        int amount;
        object n_money;
        if( !arg || sscanf(arg, "%d %s", amount, kind)!=2 )
          return notify_fail("[cloak]: wave <多少钱> <钱币种类>\n");
        n_money = present(kind + "_money", this_player());
        if( !n_money && file_size("/obj/money/" + kind + ".c") < 0 )
                return notify_fail("你摇了半天却什麽也没有出来。\n");
        if( amount < 1 )
                return notify_fail("你摇了半天却什麽也没有出来。\n");
        if( !n_money ) {
                n_money = new("/obj/money/" + kind);
                n_money->move(this_player());
                n_money->set_amount(amount);
        } else
 n_money->add_amount(amount);
message_vision( sprintf("$N开始施展点金术，突然变出了%s%s%s。\n",
                        chinese_number(amount),
                        n_money->query("base_unit"),
                        n_money->query("name")),
                this_player());
        return 1;
}

