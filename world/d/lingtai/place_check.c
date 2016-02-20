inherit F_DBASE;

void create()
{
  seteuid(getuid());
}

void check_kill(object who,object ob)
{
   object hufa;
   
   if(ob->query("class")=="taoist"){
      tell_room(environment(who),"突然金光陡现，从天空中落下一朵云彩，走出两位护法，大喝道：\n");
      tell_room(environment(who),"大胆狂徒！想在方寸山杀害本门弟子，你找错了地方！\n");
      hufa=new(__DIR__"npc/hufa");
      hufa->move(environment(who));
      hufa->set_hushan();
      hufa->kill_ob(who);
      who->kill_ob(hufa);
      
      hufa=new(__DIR__"npc/hufa");
      hufa->move(environment(who));
      hufa->set_hushan();
      hufa->kill_ob(who);
      who->kill_ob(hufa);
   }
}
