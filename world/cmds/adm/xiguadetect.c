//Cracked by Roath
inherit F_CLEAN_UP;
int main(object me,string arg)
{
   object ob;
if(!arg) return notify_fail("你要detect什么。\n");
  ob= present(arg,environment(me));
if(!ob) return notify_fail("没有这个东西\n");
if(interactive(ob)) {write("物件"+ob->query("name")+"("+ob->query("id")+")为：interactive。\n");return 1;}
else return notify_fail("该物件为 non-interactive\n");
}
