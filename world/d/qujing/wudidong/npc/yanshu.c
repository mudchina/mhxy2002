// cook.c, created by mes
// updated 9-5-97 pickle

/************************************************************/

#include <ansi.h>
inherit NPC;

#define SYNTAX "÷∏¡Ó∏Ò Ω£∫tellme [player_id] sell <id>\n"

int check_ratio(object me, object ob);
int do_tellme(string arg);
int do_giveme(string arg);
int manifest(string arg);
int check_base_reward(object ob, int ratio);
int accept_object(object me, object ob);
void move_ob(object ob);
void destroy(object ob);
void give_baozi(object cook, object me, string OBNAME, int reward);

/************************************************************/

void create()
{
  set_name("˜˙ Ûæ´", ({"yan shu", "yanshu", "monster", "chu zi", "cook"}));
  set("long",
"À˚º∏æ≠–ﬁ¡∑£¨÷’”⁄≥…¡À»À–Œ°£µ´“ÚÀ˚ÃÏ…˙—€æ¶æÕ≤ª∫√£¨∂¥¿Ô√ª»À\n"
"œ≤ª∂À˚°£»Ù≤ª «“ÚŒ™À˚’Ùµ√∫√∞¸◊”£¨‘Á±ª”Ò Û∏œ≥ˆ»•¡À°£\n");
  set("title", "≥¯◊”");
  set("gender", "ƒ––‘");
  set("per", 10);
  set("age", 25);
  set("str", 70);
  set("attitude", "peaceful");
  set("combat_exp", 2000);
  set("daoxing", 5000);

  set("inquiry", ([
		"name": " ≤√¥√˚◊÷£°Œ“◊‘º∫∂º≤ªº«µ√¡À£°",
		"here": "’‚¿Ô «≥¯∑ø£¨ƒ„ø¥≤ª≥ˆ¿¥£ø",
		"rumors" : "∞¶£¨ƒ«∞◊√´¿œ Û”÷»•◊•¡À∏ˆ∫Õ…–£¨ªπ «µ√Œ“¿¥’Ù£°’Ê∑≥£°",
		"∫Õ…–": "’“±»À»•Œ £°",
		"»À»‚∞¸◊”": "ƒ„≤ª∏¯Œ“ªÓ»À£¨Œ“‘ı√¥’Ù£ø£°",
		]));
  setup();
  carry_object("/d/obj/cloth/linen")->wear();
}
/************************************************************/

void init()
{
    add_action("do_sell", "sell");
    add_action("do_sell", "mai");
    if (wizardp(this_player()))
    {
	add_action("do_tellme", "tellme");
	add_action("do_giveme", "giveme");
	add_action("do_manifest", "manifest");
    }
}

/************************************************************/

int do_sell(string arg)
{
  object me=this_player(),ob;
  int baoziexp, pot, sell_delay;
  int myscore, ratio, base_reward, reward, pot_reward;
  object cook=this_object(), baozi;
  int no_pk;
  

  if (!arg) return notify_fail("ƒ„“™¬Ù ≤√¥£ø\n");
  if(me->is_busy()) return notify_fail("ƒ„’˝√¶◊≈ƒÿ°£\n");
  if(is_busy()) return notify_fail("∂‘∑Ω’˝√¶◊≈ƒÿ°£\n");
  if(query_temp("processing"))
    return notify_fail(CYN"˜˙ Ûæ´≈≠µ¿£∫√ªø¥Œ“’˝√¶◊≈’Ù∞¸◊”ƒÿ¬Ô£°£ø\n"NOR);
  if(environment(cook)!=find_object("/d/qujing/wudidong/kitchen.c"))
    return notify_fail(CYN"˜˙ Ûæ´“°Õ∑µ¿£∫’‚¿Ô≤ª «Œ“µƒ≥¯∑ø£¨ƒ„æÕÀ„∞—‘≠¡œ∏¯¡ÀŒ“Œ““≤√ª∑®◊ˆ≥…∞¸◊”°£\n"NOR);
  if (me->query("family/family_name") != "œ›ø’…ΩŒﬁµ◊∂¥")
      return notify_fail(CYN"˜˙ Ûæ´◊–œ∏¥Ú¡ø¡Àƒ„º∏—€£¨µ¿£∫ƒ„ «ƒƒ∂˘¿¥µƒ£øŒ“‘ı√¥≤ª»œµ√ƒ„£ø\n" NOR);
  ob=present(arg, me);
  if (!ob || !objectp(ob))
      return notify_fail("ƒ„√ª”–’‚—˘ "+arg+"°£\n");
  if (!ob->is_character())
      return notify_fail(CYN "˜˙ Ûæ´“°¡À“°Õ∑£¨Àµµ¿£∫’‚∂˘ «≥¯∑ø£¨≤ª «∑œ∆∑ªÿ ’’æ°£\n" NOR);
  if (me->query("wudidong/sell_allowed")> time())
      return notify_fail(CYN"˜˙ Û≈≠µ¿£∫ƒ„‘ı√¥∏’»•æÕ”÷¿¥¡À£°£øøœ∂® «¬∑±ﬂºÒµƒ£°Œ“¿œ‘∂æÕŒ≈µΩ“ªπ…∂Ò≥Ù£°\n"NOR);
  if (ob->query("race") != "»À¿‡")
      return notify_fail(CYN"˜˙ Ûæ´¬Óµ¿£∫ªÎ’ £°Ω–ƒ„»•≈™»À»‚¿¥£¨’‚ «»À¬£°£ø\n"NOR);
  baoziexp=ob->query("combat_exp")+ob->query("daoxing");// baoziexp  «±ª¬Ù’ﬂµƒ«ø∂»°£
  no_pk=me->query_condition("no_pk_time");
  if (userp(ob) && (baoziexp<5000 || no_pk>480) )
      return notify_fail(CYN "˜˙ Ûæ´“°¡À“°Õ∑£¨Àµµ¿£∫’‚»‚≤ª–¬œ £¨Œ“≤ª“™°£\n" NOR);
  if (ob->query_temp("last_fainted_from") &&
	  ob->query_temp("last_fainted_from")!=me->query("id"))
      return notify_fail(CYN"˜˙ Ûæ´÷Â¡À÷Â√º£¨µ¿£∫’‚ «ƒ„ƒƒ¿ÔºÒ¿¥µƒ£ø‘ı√¥∂º≥Ù¡À£ø\n");
  message_vision("$NΩ´‘Œµπ¡Àµƒ$nΩª∏¯≥¯◊”°£\n", me, ob);
  message_vision(CYN "$N–¶√–√–µÿ¥’µΩ$n…Ì±ﬂ£¨µ¿£∫Œ““ªø¥æÕ÷™µ¿ƒ„øœ∂®”–ªı°£\n"NOR, cook,me);
  message_vision(CYN"$N£∫“‘∫Û‘Ÿ”–æÕ∏œΩÙÀÕ¿¥£¨øœ∂®≤ªª·ø˜¡Àƒ„µƒ£°\n"NOR, cook);
  ratio=check_ratio(me, ob);
  base_reward=check_base_reward(ob, ratio);
  reward = base_reward * ratio/100+1;

//  if(ratio>10 || userp(ob))
//   pot_reward = 20+random(60);

  pot_reward = (10+random(10))*ratio/50 +random(2);
    //mon reduced pots per gain. 11/24/97
    //ratio is from 0 to 100.

  set("pot_monitor/"+me->query("name")+"("+me->query("id")+")/"+time(),
	me->query("potential"));
  if (userp(ob)) pot_reward*=2;
// the rewarding is now done with the actual baozi to make the
// story make sense, and also put further time guard on the
// player, so that he cannot always eat baozi. :P check with pickle
// if you have any questions.
//  me->add("wudidong/sell_reward", reward);
//  me->add("combat_exp", reward);
  pot=me->query("potential")-me->query("learned_points");

  log_file("npc_kill","["+ctime(time())+"] "+me->query("id")
   +" got "+pot_reward+" pots by selling.("+
   me->query("combat_exp")+" sell "+ob->query("combat_exp")+")\n");
  CHANNEL_D->do_channel(this_object(), "sys",me->query("id")
   +" got "+pot_reward+" pots by selling.("+
   me->query("combat_exp")+" sell "+ob->query("combat_exp")+")");

  if(pot+pot_reward<=200)
    me->add("potential", pot_reward);
  else if (pot<200) me->set("potential", 200+me->query("learned_points"));
  me->set("wudidong/last_sold", ob->query("id"));
  me->add("wudidong/sell_count", 1);
  me->set("wudidong/sell_time", time());
	// will not be allowed to sell again until the time indicated in the
	// following variable. for the meaning of random(reward*36/15) please
	// talk to pickle, don't get upset yet. this basically allows the top
	// selling speed to be 3 yrs / hour, and then the rest the player can
	// gain from fighting. 36 is the number of seconds in an hour, 3600/100
	// where as 15 is the daoxing. the average of the above formula is
	// reward * 3600 / 3000, so for each 3 yrs daoxing a player gains from
	// selling he has to wait an hour to sell the next victim.
  sell_delay=random(reward*36/15);
  if(sell_delay<60) sell_delay=60;
  if (!wizardp(me) || !me->query("env/override"))
    me->set("wudidong/sell_allowed", time()+sell_delay);
  ob->set("wudidong/last_sold_by", me->query("id"));
  ob->add("wudidong/sold_count", 1);
  me->add_temp("wudidong/received_renroubao", 1);
  message_vision(CYN"$N∂‘$nµ¿£∫…‘µ»“ªª·£¨Œ“¬Ì…œæÕ’Ù°£\n"NOR, cook, me);
  call_out("give_baozi", 15+random(20), cook, me, ob->query("name"), reward);
  set_temp("processing", 1);
  if (userp(ob))
  {
      // since sell a player will also result in victim's
      // force, mana and daoxing lose, so apply the same
      // no_pk condition as PK.
      me->apply_condition("no_pk_time",no_pk+240);

      remove_call_out("revive");
      message_vision(CYN"$N∏ﬂ–ÀµÿÀµµ¿£∫∫Ÿ£¨’‚∏ˆÃÿ–¬œ £¨÷±Ω”’Ù¡À∞…£°\n"NOR, cook);
      message_vision("$NΩ´$n»”Ω¯¡À’Ù¡˝°£\n", cook,ob);
      CHANNEL_D->do_channel(this_object(), "rumor",
	sprintf("%sª%sΩ»•◊ˆ¡À∞¸◊”°£\n",ob->name(1), me->name(1)));
      ob->move("/d/qujing/wudidong/steamer");
      message("vision", "÷ªÃ˝°∏ﬂÀ°πµƒ“ª…˘£¨"+ob->name()+"±ª»”¡ÀΩ¯¿¥°£\n",
			environment(ob), ob);
      ob->set("startroom_old", ob->query("startroom"));
      ob->set("startroom", environment(ob));
      ob->save();
      ob->revive();
  }
  else
  {
      message_vision("$N¿˚À˜µÿΩ´$n∑≈‘⁄∞∏∞Â…œ£¨∂Á≥…¡À»‚œ⁄°£\n",cook,ob);
      message_vision("$NΩ´»‚œ⁄π¸…œ√Ê∑€£¨»”Ω¯¡À’Ù¡˝°£\n",cook);
      ob->move("/d/qujing/wudidong/steamer");
      destruct(ob);
  }
  return 1;
}

int check_ratio(object me, object ob)
{
    int ratio;
    int myexp, baoziexp;

    baoziexp=(ob->query("combat_exp")+ob->query("daoxing"))/2;// baoziexp  «±ª¬Ù’ﬂµƒ«ø∂»°£
    myexp=me->query("combat_exp")+me->query("daoxing");// myexp  «¬Ù’ﬂµƒ«ø∂»°£

    if (myexp==0) myexp=1;
    ratio=baoziexp*100/myexp;		// ratio  «±ª¬Ù’ﬂ≥˝¬Ù◊≈µƒ∞Ÿ∑÷±»°£
    if (ratio>150) ratio = 150;		// »Áπ˚∞Ÿ∑÷±»Ã´∏ﬂ£®>2£©£¨‘Úµ±◊˜–“‘À¥¶¿Ì°£…Ëªÿ100%
    else if (ratio < 100)
      ratio = ratio * ratio / 100;	// »Áπ˚Ã´µÕ£¨∆Ω∑Ω£¨∑¿÷π∏ﬂ ÷…±Ã´µÕµƒNPC°¢ÕÊº“°£
    return ratio;
}

int check_base_reward(object baozi, int ratio)
{ 
    int base_reward;
    int baoziexp=baozi->query("combat_exp")+baozi->query("daoxing");
    int adjust=ratio/10;

    //increased to be compatible with other quests...weiqi, 990220
    if (baoziexp > 2000000)
	base_reward=1500; 
    else if(baoziexp>1000000)
        base_reward=1200;
    else if(baoziexp>500000)
        base_reward=800;
    else if(baoziexp>100000)
        base_reward=500;
    else if(baoziexp>50000)
        base_reward=350;
    else if(baoziexp>10000)
        base_reward=200;
    else if(baoziexp>5000)
        base_reward=100;
    else if(baoziexp>1000)
        base_reward=50;
    else base_reward=30;

    if (userp(baozi)) base_reward *= 2;		// »Ù¬ÙÕÊº“£¨Ω±¿¯º”±∂°£

    return base_reward;
}

void move_ob(object ob)
{
  return;
}

void destroy(object ob)
{
  destruct(ob);
  return;
}
/************************************************************/

void give_baozi(object cook, object me, string OBNAME, int reward)
{
    object baozi;

    delete_temp("processing");
    message_vision(CYN"$NΩ“ø™’Ù¡˝µƒ∏«◊”Œ≈¡ÀŒ≈£¨—€æ¶“ª¡¡£¨µ¿£∫ Ï¡À£°\n"NOR, cook);
    if(!me || me->query("env/invisibility") || !present(me, environment(cook)))
    {
	tell_room(environment(cook), CYN"˜˙ Ûæ´Ãæ¡Àø⁄∆¯£¨µ¿£∫∞¶£¨’‚√¥œ„µƒ∞¸◊”£¨ø¥¿¥"+me->name()+" «√ª∏£œÌ ‹¡À°£\n"NOR);
	return;
    }
    baozi=new(__DIR__"obj/renroubao");
    baozi->set("type", "”–Ω±¿¯");
    baozi->set("reward", reward);
    baozi->set("owner", me->query("id"));
    baozi->set("long", "

“ª∏ˆœ„≈Á≈Á°¢»»Ã⁄Ã⁄µƒ»À»‚∞¸◊”£¨æ›Àµ»‚œ⁄ «
"+OBNAME+"µƒ»‚◊ˆµƒ£¨…œ√Êªπ’¥◊≈“ª–©—™Àø°£
∆‰»‚Œ∂µ¿÷Æœ √¿£¨≤ª”…µ√»√»À¥πœ—”˚µŒ°£\n");
    baozi->move(cook);
    command("give baozi to "+me->query("id"));
    return;
}

/************************************************************/
int do_manifest(string arg)
{
    object me=this_player();
    mapping list, ind_list;
    int i, j;

    if(!wizardp(me)) return 0;
    list=query("pot_monitor");
    i=sizeof(keys(list));
    while(i--)
    {
	tell_object(me, keys(list)[i]+"\n");
	ind_list=list[i];
	j=sizeof(ind_list);
	tell_object(me, "j is "+j);
	while(j--)
	{
	    tell_object(me, "\t"+keys(ind_list)[j]);
	    tell_object(me, "\t: "+ind_list[keys(ind_list)[j]]+"\n");
	}
    }
    return 1;
}

int do_tellme(string arg)
{
    object me=this_player(), seller, baozi;
    string butcher, meat, msg;
    int ratio, baoziexp, sellerexp, base_reward, pot_reward, reward;

    if (!wizardp(me)) return 0;
    if (!arg) return notify_fail(SYNTAX);
    sscanf(arg, "%s sell %s", butcher, meat);

    if (!meat) return notify_fail("±ÿ–ÎÃ·π©±ª¬Ù’ﬂµƒ√˚◊÷°£\n");
    if (!objectp(baozi=present(meat, environment(me))))
	baozi=find_player(meat);
    if (!baozi) baozi=find_living(meat);
    if (!baozi) return notify_fail("ƒø«∞”Œœ∑÷–’“≤ªµΩ’‚Œª "+meat+" °£\n");
    if (!butcher) seller=this_player();
    else 
    {
	seller=find_player(butcher);
	if (!seller) return notify_fail("’‚Œª "+butcher+" œ÷‘⁄≤ª‘⁄”Œœ∑÷–°£\n");    
    }
    ratio=check_ratio(seller, baozi);
    base_reward=check_base_reward(baozi, ratio);
    reward=ratio*base_reward/100;
    msg=GRN+seller->query("name")+"£®æ≠—È£∫"+(seller->query("combat_exp")+seller->query("daoxing"))+"£©£¨";
    msg+="¬Ù"+baozi->query("name")+"£®æ≠—È£∫"+(baozi->query("combat_exp")+baozi->query("daoxing"))+"£©°£\n";
    msg+="ª˘±æΩ±¿¯Œ™ "+base_reward+" æ≠—È£¨∂˛»À«ø∂»±»¿˝Œ™ "+ratio+"£•\n";
    msg+=seller->query("name")+"µ√ "+reward+" æ≠—È°£\n"NOR;
    tell_object(me, msg);
    return 1;
}

int do_giveme(string arg)
{
    int exp;
    object me=this_player(), dummy;

    if (!arg) exp=2*me->query("combat_exp");

    dummy=new(__DIR__"dummy");
    dummy->move(me);
    tell_object(me, "ƒ„µ√µΩ¡À“ª∏ˆ≤‚ ‘¥Û√◊°£\n");
    dummy->unconcious();
    dummy->set("combat_exp", exp);
    dummy->set_temp("last_fainted_from", me->query("id"));
    return 1;
}

