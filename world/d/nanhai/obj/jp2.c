//Cracked by Roath
// …Òª∞ ¿ΩÁ°§Œ˜”Œº«°§∞Ê±æ£¥£Æ£µ£∞
/* <SecCrypt CPL V3R05> */
 
// jingping.c æª∆ø 

inherit ITEM;
inherit F_LIQUID;
#include <ansi.h>

void create()
{
   set_name("æª∆ø", ({"jingping", "bottle"}));
   set_weight(1000);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("long", "ƒœ∫£π€“Ù ¢ÀÆµƒæª∆ø°£\n");
     set("unit", "∏ˆ");
     set("value", 5000);
     set("max_liquid", 500);
   }

   // because a container can contain different liquid
   // we set it to contain wine at the beginning
   set("liquid", ([
     "type": "water",
     "name": " •ÀÆ",
     "remaining": 10,
     "drunk_apply": 20,
   ]));
}
void init()
{
        add_action("do_pour","pour");
}

int do_pour(string arg)
{
        object ob = this_player();
        object where = environment();


        if( ! arg || arg != "water" )
                return notify_fail("ƒ„“™∞— ≤√¥¥”æ≤∆ø÷–µπ≥ˆ¿¥£ø\n");
        if( !environment(environment())->query("killed") )
                return notify_fail("’‚¿Ô”√≤ª◊≈æª∆ø°£\n");                
        if( query("liquid/remaining") < 1 )
                return notify_fail("∆ø◊”÷–µƒ •ÀÆ“—æ≠±ª∫»π‚¡À°£\n");

        if( environment(environment())->query("short") != "π˚ ˜…œ" )
                return notify_fail("ƒ„±Õ¸¡À◊‘º∫“™»•∏…¬Ôµƒ£ø\n");

        message_vision("$N∞—æ≤∆ø÷–µƒÀÆ¬˝¬˝µƒµπ…œ È…œ£¨∆Êº£∑¢…˙¡À°£\n",ob);
        message_vision("»À≤Œπ˚ ˜¬Ì…œæÕ∑¢≥ˆ¡Àƒ€—ø°£\n",ob);
        remove_call_out("reware");
        call_out("reward",3,ob);
        return 1;
}

void reward(object ob)
{
        int i;

        string name=ob->query("name");

        if( ob->query("obstacle/wuzhuang") == "done" )
                return;
        if(! ob->query("obstacle/village") )
                return;
        if( !ob->query("kill_tree") )
                return;

  i = random(600);
  ob->add("obstacle/number",1);
  ob->set("obstacle/wuzhuang","done");
        ob->add("daoxing",i+8000);
  message("channel:chat",HIC"°æœ–¡ƒ°ø’Ú‘™¥Ûœ…(Zhenyuan daxian)£∫"+name+"ŒÂ◊Øπ€æ»ªÓ»À≤Œπ˚ ˜°£\n"NOR,users());
message("channel:chat",HIY"°æπ˝πÿ’∂Ω´°øπ€“Ù∆–»¯(guanyin pusa)£∫"+ob->query("name")+"¥≥π˝Œ˜––»°æ≠[1;37mµ⁄æ≈πÿ£°\n"NOR,users());
  tell_object (ob,"ƒ„”Æµ√¡À"+chinese_number(4)+"ƒÍ"+
               chinese_number(i/4)+"ÃÏ"+
               chinese_number((i-(i/4)*4)*3)+" ±≥Ωµƒµ¿––£°\n");
  ob->save();
  ob->delete("kill_tree");
  destruct(this_object());
  return;

}
