//fuhuo.c Write By Double@XHC
inherit F_CLEAN_UP;

int main(object me, string str)
{ 
  object ob;
  if (!str) return notify_fail("usage: fuhuo <id>\n");
       ob = LOGIN_D->find_body(str);
  if (!ob) return notify_fail("有这个人吗?\n");
  if (ob->is_ghost()) {
    tell_object(ob,"对你进行全身检查中...\n");
    tell_object(ob,"检查完毕！你是鬼!需要让你复活！且保留上次的一切。\n");
    tell_object(ob,"突然一个声音在你儿边响起，“复活吧....，从现在\n开始你再不是魂鬼了”，你突然感到一阵昏厥...\n");
  }
  tell_room(environment(ob),"一道金光突然从天际射下，笼罩在"+(string)ob->query("name")+"的周围。\n", ob);
  ob->reincarnate_wiz();
  ob->query_temp("last_damage_from");  
  ob->add("combat_exp", (int)ob->query("combat_exp") / 40);
  if( (int)ob->query("potential") > (int)ob->query("learned_points"))
    ob->add("potential",(int)ob->query("potential") - (int)ob->query("learned_points") );
  ob->skill_death_recover();
  ob->add("daoxing",ob->query("death/dx_loss"));
  ob->set("kill/killer_name","(relive)");
  ob->add("kill/killer_die",-1);
  ob->save();
  tell_object(ob,"很好！你又复活了！原来是巫师"+me->name(1)+"救了你！\n");
  write("Ok.\n");
  if ( userp(ob))
  write_file("/log/static/fuhuo",sprintf("%s   将   %s 复活 on %s\n",
  me->name(1),ob->name(1), ctime(time()) ));
  return 1;    
}

int help(object me)
{
write(@HELP
指令格式 : fuhuo <某人>

可以让某人起死回生。
HELP
    );
    return 1;
}
