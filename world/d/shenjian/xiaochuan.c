// LLY@FYSY
// boat.c
inherit ROOM;
void create()
{
 set("short", "木船");
 set("long", @LONG
上得船来，你可以发现船中不但有酒有菜，还有一张琴，一枰棋，一卷书，
一块光滑坚硬的石头。
LONG
 );
    set("objects", ([
        __DIR__"npc/xzg": 1 ,
        __DIR__"obj/cbook" : 1,
        __DIR__"obj/cqi" : 1,
        __DIR__"obj/cqin" : 1,
__DIR__"obj/cstone" : 1,
         ]) );
  set("coor/x",-1110);

	set("coor/y",65);

	set("coor/z",-5);
set("no_magic",1);
 setup();
}   

void boat_run(int counter)
{
 object dest;
 object *inv;
 int i;

 inv=all_inventory(this_object());		
 for (i=0;i<sizeof(inv);i++)
 if (userp(inv[i]))
  {
   if (query_temp("mark/dest")=="sjhupan1")
    switch(counter)
     {
      case 0 :  message("vision","小船慢慢的离开了岸边,水波荡漾，倒映着满天夕阳，远处的翠云峰更美如图画。\n",this_object());
                break;
      case 1 :  message("vision","谢掌柜傲笑着说道∶到神剑山庄去的人，我已看得多了，每个人上了这条船後，做的事都不一样！\n",this_object());
                break;
      case 2 :  message("vision","谢掌框道；有的人一上船就拚命喝酒,也有的人喜欢抚琴，看书，甚至还有的人喜欢一个人打棋谱。\n",this_object());
                break;
      case 3 :  message("vision", "夕阳淡了，暮色浓了,远处的青山，已渐渐的隐没在浓浓的暮色里，就像是一幅已褪了色的图画。\n",this_object());
                break;
      case 4 :  message("vision", "你忽然想起了很多事，很多不该想的事。现在你这一去，是不是还能活着回来？\n你想起了自己的童年，想起了那些青春时的游伴。也想起了那些死在你手下的人。其中有多少人是不该死的？\n",this_object());
                break;
      case 5 :  message("vision","可是你现在却全都想起来了，想得很乱。就在你思想最乱的时候，你看见了一个人，就站在秋夕暮中，绿水湖畔。\n",this_object());
                set("exits/up",__DIR__"sjhupan1");
                if (!objectp(dest=find_object(__DIR__"sjhupan1")))
                dest=load_object(__DIR__"sjhupan1");
                set_temp("mark/dest","jiujia2");
                dest->set("exits/down",__DIR__"xiaochuan");
                message("vision","一条小船缓缓驶了过来。\n",dest);
                call_out("leave",10,dest);
                return;
     } 
    else
     switch(counter)
      {
       case 0 :  message("vision","谢掌柜正坐在灯下独酌,你默默的在他对面坐下，倒了杯酒。\n",this_object());
                 break;
       case 1 :  message("vision","船离岸了慢慢的驶入凄凉的夜色中，静静的湖水间。\n",this_object());
                 break;
       case 2 :  message("vision","静静的湖水，静静的夜色。\n",this_object());
                 break;
       case 3 :  message("vision", "小船缓缓的在湖面上漂移着。\n",this_object());
                 break;
       case 4 :  message("vision", "轻舟已在湖心。\n",this_object());
                 break;
       case 5 :  message("vision","望船外：今宵酒醒何处？杨柳岸，晓风残月!你发现船已经靠岸了。\n",this_object());
                 set("exits/up",__DIR__"jiujia2");
                 if (!objectp(dest=find_object(__DIR__"jiujia2")))
                 dest=load_object(__DIR__"jiujia2");
                 set_temp("mark/dest","sjhupan1");
                 dest->set("exits/down",__DIR__"xiaochuan");
                 message("vision","一条小船缓缓驶了过来。\n",dest);
                 call_out("leave",10,dest);
                 return;
     } 
   call_out("boat_run",3,counter+1);
   return;
  }
}

void leave(object dest)
{
 object *inv;
 object oob;
 int i;
 inv=all_inventory(this_object());		
 for (i=0;i<sizeof(inv);i++)
  if (userp(inv[i]))
   {
    message("vision","船慢慢的往湖水中央漂走了。\n",dest);
    if (query_temp("mark/dest")=="sjhupan1")
     message("vision","小船向远处的神剑山庄划去。\n",this_object());
     else message("vision","小船向远处的谢家村划去。\n",this_object());
    delete("exits/up");
    dest->delete("exits/down");
    call_out("boat_run",3,0);
    return;                    
   }
 message("vision","船慢慢的往湖水中央漂走了。\n",dest);          
 delete("exits/up");
 dest->delete("exits/down");
 return;
}
