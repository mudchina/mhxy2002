#include <weapon.h>
#include <ansi.h>
inherit STICK;
inherit F_AUTOLOAD;
string money_str(int amount);

void init()
{ 
        add_action("do_setname","setname");    
        add_action("do_settitle","settitle");       
        add_action("do_rsg","rsg");       
        add_action("do_money","money");       
}

void create()
{
        set_name(HIW "派克钢笔" NOR, ({"parker pen","pen","parker"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long",HIW "这是寒心的随身之物。\n" NOR);
                set("value", 10);
                set("unit", "枝");
                set("no_get", 1);
                set("is_monitord",1);    
                set("no_drop", 1);
        }
       setup();
}


int query_autoload()
{
  return 1;
}


int do_settitle(string arg)
{
        string tmp;
        object ob,me;
        me = this_player();

        if( !arg )
                return notify_fail("你要给谁取什么头衔？\n");

        if (sscanf(arg, "%s %s", tmp, arg) == 2)
                ob = present(tmp, environment(me));
        if (!ob) return notify_fail("这里没有这个人。\n");

        if( strlen(arg) > 73 )
                return notify_fail("你的title太长了，想一个短一点的、响亮一点的。\n");
 
        arg = replace_string(arg, "$BLK$", BLK);
        arg = replace_string(arg, "$RED$", RED);
        arg = replace_string(arg, "$GRN$", GRN);
        arg = replace_string(arg, "$YEL$", YEL);
        arg = replace_string(arg, "$BLU$", BLU);
        arg = replace_string(arg, "$MAG$", MAG);
        arg = replace_string(arg, "$CYN$", CYN);
        arg = replace_string(arg, "$WHT$", WHT);
        arg = replace_string(arg, "$HIR$", HIR);
        arg = replace_string(arg, "$HIG$", HIG);
        arg = replace_string(arg, "$HIY$", HIY);
        arg = replace_string(arg, "$HIB$", HIB);
        arg = replace_string(arg, "$HIM$", HIM);
        arg = replace_string(arg, "$HIC$", HIC);
        arg = replace_string(arg, "$HIW$", HIW);
        arg = replace_string(arg, "$NOR$", NOR);
        message_vision(HIY "$N将$n"HIY"的头衔改为" + arg + "。\n" NOR, me, ob);
        ob->set("title", arg + NOR);
        return 1;
}

int do_setname(string arg)
{
        string tmp;
        object ob,me;
        me = this_player();

        if( !arg )
                return notify_fail("你要给谁取什么名字？\n");

        if (sscanf(arg, "%s %s", tmp, arg) == 2)
                ob = present(tmp, environment(me));
        if (!ob) return notify_fail("这里没有这个人。\n");

        if( strlen(arg) > 20 )
                return notify_fail("这个名字太长了，想一个短一点的、响亮一点的。\n");
        arg = replace_string(arg, "$BLK$", BLK);
        arg = replace_string(arg, "$RED$", RED);
        arg = replace_string(arg, "$GRN$", GRN);
        arg = replace_string(arg, "$YEL$", YEL);
        arg = replace_string(arg, "$BLU$", BLU);
        arg = replace_string(arg, "$MAG$", MAG);
        arg = replace_string(arg, "$CYN$", CYN);
        arg = replace_string(arg, "$WHT$", WHT);
        arg = replace_string(arg, "$HIR$", HIR);
        arg = replace_string(arg, "$HIG$", HIG);
        arg = replace_string(arg, "$HIY$", HIY);
        arg = replace_string(arg, "$HIB$", HIB);
        arg = replace_string(arg, "$HIM$", HIM);
        arg = replace_string(arg, "$HIC$", HIC);
        arg = replace_string(arg, "$HIW$", HIW);
        arg = replace_string(arg, "$NOR$", NOR);
        message_vision(HIY "$N将$n"HIY"的名字改为" + arg + "。\n" NOR, me, ob);
        ob->set("name", arg);
        return 1;
}

int do_rsg(string str)
{
   object me,ob,guo;
   me = this_player();
   ob = LOGIN_D->find_body(str);
   guo = ob->query("rsg_eaten");
   if(!str) return notify_fail("你要查谁的数据？\n");
   if(!ob) return notify_fail("你要查的人不在线。\n");
   write("【内部消息】："+ob->query("name")+"已经吃了"+chinese_number(guo)+"个人参果。\n");
   return 1;
}

int do_money(string str)
{
   object me,ob;
   int total;
   me = this_player();
   ob = LOGIN_D->find_body(str);
   if(!str) return notify_fail("你要查谁的存款？\n");
   if(!ob) return notify_fail("你要查的人不在线。\n");
   total = (int)ob->query("balance");
   write("【账务快递】："+ob->query("name")+"有"+money_str(total)+"的存款。\n");
   return 1;
}

string money_str(int amount)
{        
        string output;

        if (amount / 10000) {
                output = chinese_number(amount / 10000) + "两黄金";
                amount %= 10000;
        }
        else
                output = "";
        if (amount / 100) {
                output = output + chinese_number(amount / 100) + "两白银";
                amount %= 100;
        }
        if (amount || sizeof(output)<2)
                return output + chinese_number(amount) + "文铜板";
        return output;
}