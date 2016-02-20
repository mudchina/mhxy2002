//By tianlin@mhxy for 2002.1.20,修改

#include <net/daemons.h>
#include <net/macros.h>
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
   mapping mud_list;
   mapping mud_svc;
   mixed *muds;
   string output, output1, output2="";
   int loop, size, pplno, total;
   int count=0;
   int show_all=0;

   if( !find_object(DNS_MASTER) )
     return notify_fail("网路精灵并没有被载入，请先将网路精灵载入。\n");

   //   Obtain mapping containing mud data
   mud_list = (mapping)DNS_MASTER->query_muds();

   // so we recognise ourselves as a DNS mud
   mud_svc = DNS_MASTER->query_svc() + ([ Mud_name() : 0 ]);

   if(!mud_list)
     return notify_fail( MUD_NAME + "目前并没有跟网路上其他 Mud 取得联系。\n");

   //   Get list of all mud names within name server
   muds = keys( mud_list ) - ({ "DEFAULT" });

   //   Place mudlist into alphabetical format
   muds = sort_array(muds, 1);
     count = sizeof(muds); 
   //    If mudname provided, search server's database for a match
   //   and display its cooresponding address
if(arg && arg != "" && arg != "ALL" && arg != "ES" ) {
                arg = htonn(arg);
                if(!mapp( mud_list[arg] )) {
                        write(MUD_NAME + "并没有和这个 Mud 取得联系。\n");
                        return 1;
                }
                
   /*if(arg && arg != "") {
           if(arg=="-a") 
        show_all=1;
           else {
     arg = htonn(arg);

     if(!mapp( mud_list[arg] )) {
        write(MUD_NAME + "并没有和这个 Mud 取得联系。\n");
        return 1;
     }*/
  if( wizardp(me) && !me->query("env/debug") )
  printf("有关 %s 的资讯：\n%O\n", arg, mud_list[arg]);
   else  
                        printf("\n"HIR"有关"HIW" %s "NOR+HIR"的资讯：\n"
                                HIC"╭───────────────────╮\n"NOR
                                HIC"│"NOR+YEL"中文名称："NOR+CYN"  %s\t\t        "HIC"│\n"
                                HIC"│"NOR+YEL"语言："NOR+CYN"      %s\t\t        "HIC"│\n"
                                HIC"│"NOR+YEL"版本： "NOR+CYN"     %s\t"HIC"│\n"
                                HIC"│"NOR+YEL"MudOS："NOR+CYN"     %s\t        "HIC"│\n"
                                HIC"│"NOR+YEL"Mudlib："NOR+CYN"    %s\t"HIC"│\n"
                                HIC"│"NOR+YEL"主机： "NOR+CYN"     %s\t        "HIC"│\n"
                                HIC"│"NOR+YEL"端口： "NOR+CYN"     %s\t\t"HIC"        │\n"
                                HIC"│"NOR+YEL"状态： "NOR+CYN"     %s\t\t"HIC"        │\n"
                                HIC"│"NOR+YEL"在线玩家："NOR+CYN"  %s\t\t        "HIC"│\n"
                                HIC"│"NOR+YEL"当地时间："NOR+CYN"  %s"HIC"  │\n"
                                HIC"╰───────────────────╯\n\n"NOR,
                                mud_list[arg]["NAME"],
                                undefinedp(mud_list[arg]["MUDNAME"])?
                                "不详":mud_list[arg]["MUDNAME"],
                                undefinedp(mud_list[arg]["ENCODING"])?
                                "不详":(mud_list[arg]["ENCODING"]=="GB"?"简体汉字":"繁体汉字"),
                                undefinedp(mud_list[arg]["VERSION"])?
                                "不详":mud_list[arg]["VERSION"],
                                undefinedp(mud_list[arg]["DRIVER"])?
                                "不详":mud_list[arg]["DRIVER"],
                                undefinedp(mud_list[arg]["MUDLIB"])?
                                "不详":mud_list[arg]["MUDLIB"],
                                mud_list[arg]["HOSTADDRESS"],
                                mud_list[arg]["PORT"],
                                mud_list[arg]["_dns_no_contact"]<1?
                                "连线":"断开",
                                undefinedp(mud_list[arg]["USERS"])?
                                "不详":mud_list[arg]["USERS"],
                                undefinedp(mud_list[arg]["TIME"])?
                                "不详":mud_list[arg]["TIME"],
                                );
                return 1;
        }
   output = "\n\n"+
BRED WHT+"中文名称          Mud    国际网路位址      端口      当地时间     在线玩家\n"NOR+
HIW+"─────────────────────────────────────\n"NOR;
      
   total = 0;
   //   Loop through mud list and store one by one
   for(loop = 0, size = sizeof(muds); loop<size; loop++) {
           string mudname,mudtime;     
                mudname= mud_list[muds[loop]]["MUDNAME"] ; 
                if(strlen(mudname)>17) mudname=mudname[0..16];
     mudtime=mud_list[muds[loop]]["TIME"];
        output1 = sprintf(BBLU+YEL"%-17s %-6s %-16s  %-5s %15s %5s\n"NOR, 
        mudname,
              upper_case(muds[loop]),
        mud_list[muds[loop]]["HOSTADDRESS"],
        mud_list[muds[loop]]["PORT"],
             undefinedp(mud_list[muds[loop]]["TIME"])?
        "                ":
        mudtime[0..15],
        undefinedp(mud_list[muds[loop]]["USERS"]) ?
        "":""+mud_list[muds[loop]]["USERS"] );
         if (undefinedp(mud_list[muds[loop]]["USERS"]))
        pplno = 0;
         else
        sscanf(mud_list[muds[loop]]["USERS"], "%d", pplno);
               total += pplno;
         if(mud_list[muds[loop]]["MUDLIB"]=="MHXY"
               || mud_list[muds[loop]]["MUDLIB"]=="HLXY"
               || mud_list[muds[loop]]["MUDLIB"]=="XLQY"
               || mud_list[muds[loop]]["MUDLIB"]=="DTXY"
               || mud_list[muds[loop]]["MUDLIB"]=="hlxy"
               || mud_list[muds[loop]]["MUDLIB"]=="XYJ"
               || mud_list[muds[loop]]["PORTUDP"]=="6670"
               || mud_list[muds[loop]]["TCP"]=="all"
               )
           output2=output1+output2; 
                    else if(show_all==1)
           output2=output2+output1;
                   }
   output+=output2;
     output+=
HIW"─────────────────────────────────────\n"NOR;
    output+="共有 "YEL+ sprintf("%d", count-1) + NOR" 个中文 Mud 与"WHT+MUD_NAME+CYN"青岛站"NOR"互连，本站有 "YEL+sprintf("%d",total)+NOR" 位使用者连线中。\n";
   //   Display dumped mudlist output through user's more pager
   this_player()->start_more( output );

   return 1;
}

int help()
{
        write(@HELP

指令格式： mudlist               列出连线中的梦幻西游站点
           mudlist -ALL          列出连线中的所有Ｍｕｄ
           mudlist <Mud 名称>    列出指定Ｍｕｄ的信息

HELP
   );
   return 1;
}


