//stockboss.c  彩票商
//by wfei apr 18 2001

inherit F_VENDOR_SALE;
#include <ansi.h>
int check_player();
int report_num();
int do_ready();
int give_rsg();
int check_time();
int tell_num();
int del_num();
int set_up();
//int set_title();

string *num=({
     "一","二","三","四","五",
    "六","七","八","九","零",
              });
void create()
{
    reload("stockboss");
   set_name(HIC"彩票商&&居民注册官"NOR, ({"stock seller", "stock", "seller", "boss","officer"}));
   set("title",HIY"梦幻西游"NOR);
   set("age",19);
   set("gender","女性");
   set("per",40);
   set("attitude", "peaceful");
   set("long",
"她是梦幻西游的彩票出售员，你可以用choose <5位没有重复数字的号码>\n"
"来购买彩票,0开头的号码无效。每人每期最多可以买5张。\n"
"用ask boss about 中奖号码  来查询本期的中奖号码。\n"
"用ask boss about mynum  来查询本期的你现在的彩票号码。\n"
"用ask boss about 中奖   来对奖，以获得2000两黄金，\n"
"如不要黄金，用ask boss about rsg   来换取4个人参果。\n"
"用ask boss about 消号 来消除以前的号码，否则你有了5张就不能再买了\n"
"上期没有买完5张数额的不需消号，在买下期的时候，系统自动消号。\n");
   set("chat_chance",1);
   set("chat_msg",({"想发财的，可以在此买彩票，10GOLD一张，每三天开一次奖，仅设特等奖，每人2000GOLD或RSG4个!\n"}));
   setup();
   set("inquiry", ([
   "中奖":(: check_player :),
  "rsg":(: give_rsg :),
   "人参果":(: give_rsg :),
   "中奖号码":(: report_num :),
   "开奖":(: check_time :),
   "mynum":(: tell_num :),
   "消号":(: del_num :),
//   "注册":(: set_up :),
//   "title":(: set_title :),
      ]));
   }
void init()
{
  if(wizardp(this_player())){
   add_action("do_ready","ready");}
 if(userp(this_player())){
 add_action("do_stock","choose");}
}
int do_ready()
{
   if(time()<query("start_time")||time()<query("start_time")+259200)
     return notify_fail("不是刚开过奖嘛，怎么又来了？等下期吧！\n");
  message("system",HIR"【财政预算】彩票管委会主席--"+BLINK HIB"柳依依"NOR+HIR"： 第"+to_chinese(query("stocknum"))+"期彩票销售金额为"+BLINK HIY""+to_chinese(query("income"))+""NOR+HIR"两黄金！\n"NOR,users());
message("system",HIR"【奖品预告】"+BLINK HIB"柳依依"NOR+HIR"： 第"+to_chinese(query("stocknum"))+"期彩票特奖奖品（第一个兑奖的）为："+BLINK HIY""+to_chinese(4*query("stock_nowin"))+"个人参果"NOR+HIC"或"+BLINK HIY""+to_chinese(2000*query("stock_nowin"))+"两黄金！\n"NOR,users());
  message("system",HIR"【彩票开奖】梦幻西游彩票管委会： 现在准备公开抽选第"+to_chinese(query("stocknum"))+"期彩票特奖中奖号码！\n"NOR,users());
this_object()->set("nosell_time",time());
set("start_time",time());   
set_temp("starting",1);   
 this_object()->delete("income");
   {if(query_temp("asked"))  
    this_object()->delete_temp("asked");}
call_out("start", 60);
   return 1;
    }
void start()
{
if(!query_temp("starts")){
   message("system",HIR"【彩票开奖】梦幻西游彩票管委会： 现在开始抽选第一位号码！\n"NOR,users());
call_out("choose",30);}
else {
message("system",HIR"【彩票开奖】梦幻西游彩票管委会： 第"+to_chinese(query_temp("starts"))+"位号码是"+BLINK HIY""+query_temp("nums")+"\n"NOR,users());
if(query_temp("starts")<5){
message("system",HIR"【彩票开奖】梦幻西游彩票管委会： 现在开始抽选第"+to_chinese(query_temp("starts")+1)+"位号码！\n"NOR,users());
call_out("choose",30);}
else {call_out("finish",30);}
}
}

void choose()
{
 int i; 
   object me=this_object();
    string numb;
 numb=num[random(sizeof(num))];
if(numb=="一"){set_temp("nums",1);}
if(numb=="二"){set_temp("nums",2);}
if(numb=="三"){set_temp("nums",3);}
if(numb=="四"){set_temp("nums",4);}
if(numb=="五"){set_temp("nums",5);}
if(numb=="六"){set_temp("nums",6);}
if(numb=="七"){set_temp("nums",7);}
if(numb=="八"){set_temp("nums",8);}
if(numb=="九"){set_temp("nums",9);}
if(numb=="零"){set_temp("nums",0);}
  {if(query_temp("nums")==query("number/number1")
  ||query_temp("nums")==query("number/number2")
  ||query_temp("nums")==query("number/number3")
  ||query_temp("nums")==query("number/number4")
  ||query_temp("nums")==query("number/number5"))
    { call_out("choose",2);} 
   else {
add_temp("starts",1);
{if(!me->query("number/count")){
me->set("number/number1",query_temp("nums"));
me->add("number/count",1);}
else {
if((int)me->query("number/count")<2){
   me->set("number/number2",query_temp("nums"));
   me->add("number/count",1);}
else if((int)me->query("number/count")<3&&(int)me->query("number/count")>1){
   me->set("number/number3",query_temp("nums"));
   me->add("number/count",1);}
else if((int)me->query("number/count")<4&&(int)me->query("number/count")>2){
   me->set("number/number4",query_temp("nums"));
   me->add("number/count",1);}
else if((int)me->query("number/count")<5&&(int)me->query("number/count")>3){
   me->set("number/number5",query_temp("nums"));
   me->add("number/count",1);}
     }
}

call_out("start",30);
}
}
}

void finish()
{
 object me=this_object(); 
  int num1,num2,num3,num4,num5,num6,num7;
num1=(int)me->query("number/number1");
num2=(int)me->query("number/number2");
num3=(int)me->query("number/number3");
num4=(int)me->query("number/number4");
num5=(int)me->query("number/number5");
me->delete("number/count");
me->delete_temp("nums");
me->delete_temp("starts");
me->delete_temp("starting");
   message("system",HIR"【彩票开奖】梦幻西游彩票管委会： 5位号码已产生！\n"NOR,users());
   message("system",HIR"【彩票开奖】梦幻西游彩票管委会： 第"+to_chinese(query("stocknum"))+"期最后的中奖号码就是：\n"NOR,users());
   message("system",HIR"【彩票开奖】梦幻西游彩票管委会：\n\n\n"+BLINK HIW"                         "+to_chinese(num1)+to_chinese(num2)+to_chinese(num3)+to_chinese(num4)+to_chinese(num5)+"\n"NOR,users());
me->set("number/win",num1*10000+num2*1000+num3*100+num4*10+num5);
me->save();
}

int check_player()
{
object me=this_object();
  object who=this_player();
  object ob;
  int t,stock1,stock2,stock3,stock4,stock5,win;
 win=(int)me->query("number/win");
 stock1=who->query("stock/number1");
 stock2=who->query("stock/number2");
 stock3=who->query("stock/number3");
 stock4=who->query("stock/number4");
 stock5=who->query("stock/number5");
 if(win) {
  if(stock1==win||stock2==win||stock3==win||stock4==win||stock5==win)  {
   if(who->query("stocknum")!=me->query("stocknum")){
  write("你这个号码不是这一期的，已经作废了!\n");
who->move("/u/tianlin/qiushi");
  who->start_busy(300);
  tell_object(who,"你因为涉及伪造彩票数据，被判拘留5分钟！恭喜你....\n");
  message("channel:rumor",HIM"【警方通告】彩票管委会："+who->query("name")+"("+who->query("id")+")因为冒充本期特奖奖票，已被逮捕！\n"NOR,users());
  who->delete("stock");}
  else {
  if(query("stock_nowin")<1) { t=1;}
 else {t=query("stock_nowin");}
  message("system",HIR"【大奖通知】梦幻西游彩票管委会： 第"+to_chinese(query("stocknum"))+"期特奖得主"+who->query("name")+"("+who->query("id")+")前来领奖！获得黄金"+to_chinese(t*2000)+"两！\n"NOR,users());

 message_vision("$N对$n笑嘻嘻的拱手道：“恭喜发财！”\n",me,who);
message_vision("$N对$n说道：“"+to_chinese(t*2000)+"两黄金已经存入你的银行账户。”\n",me,who);
who->add("balance",t*20000000);
  me->set("stock_nowin",0);
who->delete("stock");
 me->save();
 who->save();}
    }
 else {
message_vision("$N对$n说道：“第"+to_chinese(query("stocknum"))+"期中奖号码为："+me->query("number/win")+",你没中！下次好运！”\n",me,who);
who->delete("stock");}}
else {  if(query_temp("starting")){
   write("正在开奖中，还是过一会儿，等有了结果再来问吧！\n");}
else {write("现在还没有开奖，没有中奖号码！\n");}
      }
  return 1;
}

int do_stock(string arg)
{     object me=this_object();
      object who=this_player();
      int afford,hour,min,sec,hourl,minl,secl;  
if (!arg) return notify_fail("请输入你要买的彩票号码，格式:choose <5位不重复的数字>\n");
 if(sizeof(arg)!=5) return notify_fail("请输入5位不重复的数字。\n");
else if(time()<(int)me->query("nosell_time")||time()<(int)me->query("nosell_time")+86400)
    {
  hourl=(query("nosell_time")+86400-time())%3600;
  minl=hourl%60;
  secl=minl%60;
 hour=(query("nosell_time")+86400-time()-hourl)/3600;
 min=(hourl-minl)/60;
  sec=secl;
message_vision("$N对$n说道：“刚开过奖，暂时不出售彩票,现在专职兑奖和消号。现在\n离第"+to_chinese(query("stocknum")+1)+"期彩票开售还有"+to_chinese(hour)+"小时"+to_chinese(min)+"分钟"+to_chinese(sec)+"秒！欢迎您到时光临！”\n",this_object(),this_player());}
   else {
  if(query("number")) {
     me->delete("number");
  me->add("stocknum",1);
message("system",HIR"【彩票开售通知】梦幻西游彩票管委会： 第"+to_chinese(query("stocknum"))+"期彩票现在开始出售，欢迎大家到kz u n购买！\n"NOR,users());
  {if(query("stock_nowin")>4)  {me->set("stock_nowin",0);}}
  me->add("stock_nowin",1);
message("system",HIR"【奖品预告】"+BLINK HIB"柳依依"NOR+HIR"： 第"+to_chinese(query("stocknum"))+"期彩票特奖奖品（第一个兑奖的）为："+BLINK HIY""+to_chinese(4*query("stock_nowin"))+"个人参果"NOR+HIC"或"+BLINK HIY""+to_chinese(2000*query("stock_nowin"))+"两黄金！\n"NOR,users());
    me->save();}
     if( !(afford=me->can_afford(100000)) )  {
       write("你带的钱不够,10两黄金一张彩票。\n");
           return 1;}
else if( afford == 2 )  {
      write("现金交易，不收银票。你带的现金不够。\n");
      return 1;}
else if(who->query("stock/buys")>4){
write("你已经买了5张了，要买下期再买吧！\n");}
  else {
if(who->query("stock/number1")==(int)arg
||who->query("stock/number2")==(int)arg
||who->query("stock/number3")==(int)arg
||who->query("stock/number4")==(int)arg)
  {    write("你已经买过这个号了！\n");}
   else {   
   who->pay_money(100000);
this_object()->add("income",10);
{if(query("income")>0&&query("income")%100==0){
message("system",HIR"【财政预算】彩票管委会主席--"+BLINK HIB"柳依依"NOR+HIR"： 第"+to_chinese(query("stocknum"))+"期彩票到现在，销售金额为"+BLINK HIY""+to_chinese(query("income"))+""NOR+HIR"两黄金！\n"NOR,users());
message("system",HIR"【奖品预告】"+BLINK HIB"柳依依"NOR+HIR"： 第"+to_chinese(query("stocknum"))+"期彩票特奖奖品（第一个兑奖的）为："+BLINK HIY""+to_chinese(4*query("stock_nowin"))+"个人参果"NOR+HIC"或"+BLINK HIY""+to_chinese(2000*query("stock_nowin"))+"两黄金！\n"NOR,users());
message("system",HIR"【彩票广告】梦幻西游彩票管委会： 第"+to_chinese(query("stocknum"))+"期彩票现在正在出售，欢迎大家到kz u n购买！谢谢大家的支持！\n"NOR,users());}
}
   {if(who->query("stocknum")!=me->query("stocknum")){
   who->delete("stock");
 who->set("stocknum",(int)me->query("stocknum"));}}
this_object()->save();
   message_vision("$N拿出10两金子，交给了$n。\n",who,me);
  message_vision("$N点了点钱，在电脑上打出一张彩票给$n。\n",me,who);
  write("你买的彩票号码是"+arg+"\n");
message_vision("$N对$n说道：“你的彩票已计入你的数据！”\n",me,who);
  {if(!who->query("stock/buys")){
 who->set("stock/number1",(int)arg);}
 else if(who->query("stock/buys")==1){
 who->set("stock/number2",(int)arg);}
else if(who->query("stock/buys")==2){
 who->set("stock/number3",(int)arg);}
else if(who->query("stock/buys")==3){
 who->set("stock/number4",(int)arg);}
else if(who->query("stock/buys")==4){
 who->set("stock/number5",(int)arg);}
    }
who->add("stock/buys",1);}
         }
    }
   return 1;
}

int give_rsg()
{
 object me=this_object();
  object who=this_player();
  object ob1,ob2,ob3,ob4;
  int t,stock1,stock2,stock3,stock4,stock5,win,i;
 win=(int)me->query("number/win");
 stock1=who->query("stock/number1");
 stock2=who->query("stock/number2");
 stock3=who->query("stock/number3");
 stock4=who->query("stock/number4");
 stock5=who->query("stock/number5");
if(win) {
 if(stock1==win||stock2==win||stock3==win||stock4==win||stock5==win)  {
   if(who->query("stocknum")!=me->query("stocknum")){
  write("你这个号码不是这一期的，已经作废了!\n");
who->move("/u/tianlin/qiushi");
  who->start_busy(300);
  tell_object(who,"你因为涉及伪造彩票数据，被判拘留5分钟！恭喜你....\n");
  who->delete("stock");
message("channel:rumor",HIM"【警方通告】彩票管委会："+who->query("name")+"("+who->query("id")+")因为冒充本期特奖奖票，已被逮捕！\n"NOR,users());}
   else {
  if(query("stock_nowin")<1) { t=1;}
 else {t=query("stock_nowin");}
   for(i=0; i<t; i++) { 
 ob1=new("/d/obj/drug/renshen-guo");
 ob2=new("/d/obj/drug/renshen-guo");
 ob3=new("/d/obj/drug/renshen-guo");
 ob4=new("/d/obj/drug/renshen-guo");
 ob1->move(who);
 ob2->move(who);
 ob3->move(who);
 ob4->move(who);}
 message_vision("$N对$n说道：“你既然不要黄金，那就给你"+to_chinese(4*t)+"个人参果吧！”\n",me,who);
 message_vision("$N给$n"+to_chinese(4*t)+"个人参果。\n",me,who);
  message("system",HIR"【大奖通知】梦幻西游彩票管委会： 第"+to_chinese(query("stocknum"))+"期特奖得主"+who->query("name")+"("+who->query("id")+")前来领奖！获得人参果"+to_chinese(4*t)+"个！\n"NOR,users());
  me->set("stock_nowin",0);
who->delete("stock");
who->save();
me->save();}
   }
 else { write("你没中奖，怎么换人参果呀？\n");
  who->delete("stock");}}
else {  if(query_temp("starting")){
   write("正在开奖中，还是过一会儿，等有了结果再来问吧！\n");}
  else {write("现在还没有开奖，没有中奖号码！\n");}
       }
return 1;
}
int report_num()
{
if(this_object()->query("number/win")) {
message_vision("$N告诉$n道：“第"+to_chinese(query("stocknum"))+"期特奖中奖号码为："+this_object()->query("number/win")+",你中了没？”\n",this_object(),this_player());
      }
else {write("现在还没有开过奖，没有中奖号码！\n");  }
  return 1;
}
int check_time()
{
  int hour,min,sec,hourl,minl,secl;
if(time()>query("start_time")+259200)  {
  if(!query_temp("asked")){
message("system",HIR"【彩票开奖】梦幻西游彩票管委会： 应"+this_player()->query("name")+"("+this_player()->query("id")+")的要求，彩票系统进入抽奖倒计时！\n"NOR,users());
    set_temp("asked",1);
    call_out("do_ready",10);}
   else {
  write("你是不是晕了?现在不正在开奖吗！\n");}  }
else if(time()<query("nosell_time")||time()<query("nosell_time")+86400){
message_vision("$N对$n说道：“刚开过奖,现在专职兑奖和消号。现在离第"+to_chinese(query("stocknum")+1)+"期彩票开奖还很远!”\n",this_object(),this_player());}
   else {
  hourl=(query("start_time")+259200-time())%3600;
  minl=hourl%60;
  secl=minl%60;

 hour=(query("start_time")+259200-time()-hourl)/3600;
 min=(hourl-minl)/60;
  sec=secl;
message_vision("$N对$n说道：“现在离第"+to_chinese(query("stocknum"))+"期彩票开奖还有"+to_chinese(hour)+"小时"+to_chinese(min)+"分钟"+to_chinese(sec)+"秒！”\n",this_object(),this_player());
message_vision("$N对$n说道：“谢谢你对我们彩票系统的支持，但现在还没到开奖时间，待会儿吧！”\n",this_object(),this_player());}
   return 1;
}
int tell_num()
{
  object who=this_player();
  int num;
  num=this_player()->query("stocknum");
    if(who->query("stock")){
   if(who->query("stock/buys")==1){
   write("你现在有第"+to_chinese(num)+"期号码一个："+who->query("stock/number1")+"\n");}
   if(who->query("stock/buys")==2){
   write("你现在有第"+to_chinese(num)+"期号码两个：\n"+who->query("stock/number1")+"       "+who->query("stock/number2")+"\n");}
   if(who->query("stock/buys")==3){
   write("你现在有第"+to_chinese(num)+"期号码三个：\n"+who->query("stock/number1")+"      "+who->query("stock/number2")+"      "+who->query("stock/number3")+"\n");}

   if(who->query("stock/buys")==4){
   write("你现在有第"+to_chinese(num)+"期号码四个：\n"+who->query("stock/number1")+"   "+who->query("stock/number2")+"    "+who->query("stock/number3")+"    "+who->query("stock/number4")+"\n");}
   if(who->query("stock/buys")==5){
   write("你现在有第"+to_chinese(num)+"期号码五个：\n"+who->query("stock/number1")+"   "+who->query("stock/number2")+"    "+who->query("stock/number3")+"    "+who->query("stock/number4")+"     "+who->query("stock/number5")+"\n");}
}
   else {write("你现在没有任何号码！\n");}
   return 1;
}
int del_num()
{
  object me=this_object();
  object who=this_player();
  if(who->query("stock")){
if(who->query("stocknum")!=query("stocknum")){
message_vision("$N对$n说道：“OK !你以前的彩票号码删除了，你可以继续买了！”\n",me,who);
 who->delete("stock");
  who->save();}
   else {
message_vision("$N对$n说道：“你要删除的是这一期的号码，请用ask boss about 中奖  看看！”\n",me,who);}
                 }
   else {
message_vision("$N对$n说道：“你都没有彩票，问什么消号呀？”\n",me,who);}
  return 1;
}
int set_up()
{
       object who=this_player();
       object me=this_object();
       mapping skill_status;
      int temp,i,nopass;
       string *sname;

     if(who->query("set_up")){
   tell_object(who,HIR"\n     你已经是梦幻西游的注册居民了！\n"NOR);}
   else {
    if(who->query("combat_exp")<1000000||who->query("daoxing")<1000000){
   tell_object(who,"   你的武学或道行太低！\n");}
    else {
   if(mapp(skill_status = who->query_skills())){
      skill_status = who->query_skills();
     sname = keys(skill_status);
       temp = sizeof(skill_status);
     for (i = 0; i < temp; i++){
           if(who->query_skill(sname[i],1)<150)
          nopass+=1;}
     if(nopass) {
 tell_object(who,"   你有"+chinese_number(nopass)+"项技能没能达到150级，不能注册！\n");}
    else {
     me->add("setupnum",1);
   who->set("set_up/number",me->query("setupnum"));
   me->save();
tell_object(who,"你是梦幻西游的老玩家，替你注册理所当然了，但以后你要为本站的发展多做贡献才是！\n");
message("system",HIW"【户口统计委员会】:本站老玩家"+who->query("name")+"("+who->query("id")+")愿意恪守诺言，\n为了本站的健康发展尽心尽力！现被批准为梦幻西游第"+to_chinese(query("setupnum"))+"位注册居民！\n"NOR,users());
  who->set("title",HIW"梦幻西游NO."+to_chinese(query("setupnum"))+"注册居民"NOR+who->query("title"));
   who->save();}
    }
      }
        }
     return 1;
}
int set_title()
{ 
       object who=this_player();
    if(who->query("set_up")){
       who->set("title",HIW"梦幻西游NO."+to_chinese(who->query("set_up/number"))+"注册居民"NOR+who->query("title"));
   message_vision("$N对$n说道:“OK !”\n",this_object(),who);}
    else {
       message_vision("$N对$n说道:“先用ask officer about 注册   来注册!”\n",this_object(),who);}
    return 1;
}

