// Room: /d/wiz/wizroom.c

inherit ROOM;
#include <ansi.h>

int block_cmd();

void create ()
{
  set ("short","巫师会议厅");
  set ("long", @LONG

这里是巫师聊天讨论的地方，如果巫师们要开会的话，也多半会选在这
里举行。

以下是巫师应遵守的规则，相关惩罚由神或大巫师执行，欢迎玩家检举违规巫师。
1 玩家应该遵守所有玩家应遵守的规定,但有关杀档案之惩情节轻重减轻或加重。
2 禁止将未经 QC 合格之物件、或非测试目的所制造的任何物件给予玩家或放置在玩家於正
  常状态下接触得到的任何房间或物件中。以测试目的制造之物件应於事前徵求神或大巫师
  之同意才能进行玩家测试，测试者并应负相关之错误修复、损害/利益还原之责任，若为
   具危险行之测试应该和玩家商议或和在线wiz商议
3 禁止利用巫师指令替玩家查看物件之属性、状态、功能等非排除错误状况必须事项。
4 禁止修改玩家状态，此处之玩家状态包括所有人为状态之改变，以及所有可储存之状态
5 禁止使用巫师人物和玩家建立任何系统所定义之人际关系，如师徒、组队。
6 以上禁止事项若有触犯者，视情节轻重予以口头警告、降级、除名等处分。 
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"system",
  "north" : __DIR__"jobroom",
  "sleeve": __DIR__"sleeveroom",
  "guest": __DIR__"guest",
  "east": __DIR__"liwu",
  "jail":__DIR__"punish",
  "south":__DIR__"newsroom",
  "kz": "/d/city/kezhan",
  "enter": "/d/wiz/outjail",
  "down": "/u/tianlin/workroom",
 ]));

  set("wiz_board",1);

  setup();
  call_other("/obj/board/wizard_b", "???");
}

void init()
{   
        if (!wizardp(this_player()))
          add_action("block_cmd","",1);   
}

int block_cmd()
{
       string verb = query_verb();

       if (verb=="say") return 0; //allow say
       if (verb=="chat") return 0;
       if (verb=="quit") return 0;
if (verb=="look") return 0;
if (verb=="post") return 0;
if (verb=="read") return 0;
       return 1;
}

