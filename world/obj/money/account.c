// account.c

#include <ansi.h>

inherit ITEM;       // /std/item

int do_save(string);
int do_load(string);
void reset_balance(object);

void create()
{
        set_name(CYN"信用卡"NOR, ({ "credit card","credit","card" }) );
        set("unit", "本");
        set("long",@LONG
这是西游记中通用的新式信用卡，上面记录着你在银行中的
存款。望妥善保管，遗失后果自负。
        deposit   <amount> <money_type>     存钱
        deposit   all                       全存
        takeout   <amount> <money_type>     取钱
                     手续费  银子一两
        checkcard                          查账
LONG
        );
        if( clonep() ){
                   set("owner_id",this_player()->query("id"));
                set_default_object(__FILE__);
        }
        set("no_get", 1);   
        set("no_sell", 1);   
        set("no_give", 1);   
        set("no_drop", 1);   
        seteuid(getuid());
}

void init()
{
        if( !environment()->is_character())  destruct(this_object());
        else{
                add_action("do_save", "deposit");
                add_action("do_load", "takeout");
                add_action("do_info", "checkcard");
        }
}

int query_autoload(){ return 1; }

int do_save(string arg)
{
        int amount;
        string money;
        object money_ob,me,coin,silver,gold,cash,tencash;

        if (!arg) return 0;
        me=this_player();
        if (arg=="all")
        {
            coin=present("coin_money",me);
            silver=present("silver_money",me);
            gold=present("gold_money",me);
            cash=present("thousand-cash_money",me);
            tencash=present("ten-thousand-cash",me);
            amount=0;
            if (coin){
              amount+=coin->value();
              destruct(coin);
            }
            if (silver){
              amount+=silver->value();
              destruct(silver);
            }
            if (gold){
              amount+=gold->value();
              destruct(gold);
            }
            if (cash){
              amount+=cash->value();
              destruct(cash);
            }
            if (tencash){
              amount+=tencash->value();
              destruct(tencash);
            }

            me->add("balance",amount);
        }
        else
        {
            if (sscanf(arg,"%d %s",amount,money)!=2)
            {
               amount=-1;
               money=arg;
            }
            else if ( amount < 1 )
                return notify_fail("货币计量至少要一个单位。\n");
            money_ob=present(money+"_money",me);
            if (!money_ob) return notify_fail("你身上没有这种货币。\n");
            if (amount==-1)
            {
                amount=money_ob->query_amount();
                if (!amount)
                        return notify_fail("你身上没有这种货币。\n");
            }
            else if( money_ob->query_amount() < amount )
                return notify_fail("你身上没有那多"+money_ob->query("name")+"。\n");
            money_ob->add_amount(-amount);
            me->add("balance",money_ob->query("base_value")*amount);
            if (!money_ob->query_amount()) destruct(money_ob);
        }
        write("OK.\n");
        reset_balance(me);
        return 1;
}

int do_load(string arg)
{
        int amount,bv,rich,old=0,tm=0,tmm=0;
        string money;
        object money_ob,me;

        if (!arg) return 0;
        me=this_player();
        if (sscanf(arg,"%d %s",amount,money)!=2)
        {
                amount=-1;
                money=arg;
        }
        
        rich=me->query("balance");
        if (!rich) return notify_fail("你在本银行没有任何存款!\n");
        money_ob=present(money+"_money",me);
        if (!money_ob)
        {
                if(file_size("/clone/money/"+money+".c")<0) return notify_fail("没有这种货币!\n");
                money_ob=new("/clone/money/"+money);
                money_ob->move(me);
                old=-1;
        }
        bv = money_ob->query("base_value");
        if (amount==-1) amount=rich/bv;
        else if( rich < amount*bv + 100 )
              
{
   write("你的帐号上没有那多"+money_ob->query("name") + "!\n");
  money_ob->add_amount(old);     
       return 1;
} 
       if(amount*bv < 0)  
            {
            money_ob->add_amount(old);
               write("你不要诈骗哦?
\n");
        return 1;
}
        me->add("balance",-amount*bv-100);
      /*  tm = (int)(amount+old-(int)(amount*0.2));
        tmm = (int)tm;*/
        money_ob->add_amount(amount+old);
        write("OK.\n");
        reset_balance(me);
        return 1;
}

int do_info(string arg)
{
        int rich;
        rich=this_player()->query("balance");
        if (!rich)        write("目前, 你在银行里没有任何存款!\n");
        else
        {
                write("目前, 你在银行里有:\n");
                if (rich/10000)
                write( chinese_number(rich/10000) +"两黄金");
                rich=rich%10000;
                if (rich/100)   write(chinese_number(rich/100)+"两银子");
                rich=rich%100;
                if (rich)       write(chinese_number(rich) + "文钱");
                write("\n");
        }
        return 1;
}

void reset_balance(object me)
{
    int allowed=me->query("combat_exp");
    int removed_gold;
    string myid=me->query("id");
    string NPCNAME="铁算盘";

    if(allowed<1000) allowed=1000;
    if(allowed>100000) allowed=100000;
    allowed *= 2500;//each year can have 250 gold, range 250-25000. 
    if( (me->query("balance")) > allowed){
        me->set("balance_old", me->query("balance"));
        me->set("balance", allowed);
        removed_gold = (me->query("balance_old") - me->query("balance"))/10000;
        log_file("MONEY_RESET", ctime( time() )+"：鳌大人收缴了"+me->query("name")+"("+me->query("id")+")"+removed_gold+"两黄金。\n");
        tell_object(me, GRN+NPCNAME+"在你的耳边悄声说道："+RANK_D->query_respect(me)+
           "，这、这真不知怎么说是好．．．\n"NOR);
        tell_object(me, GRN+NPCNAME+"在你的耳边悄声说道："+
           "昨日魏大人派人前来察案，发觉你老的黄金来路．．．\n"NOR);
        tell_object(me, GRN+NPCNAME+"在你的耳边悄声说道："+
        "若不是在下帮你老辩解，你老的钱就全都充公了．．．\n"NOR);
    }
}

string query_destruct_msg()
{ 
   return HIB+"你看到一张蓝色卡片掉了下来，但是怎么找也找不着,真气人!\n"+NOR;
}
