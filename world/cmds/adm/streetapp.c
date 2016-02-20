// streetapp.c zip@hero 2000.1.29 扩展街道
#define __ROOMDIR__ "/p/fystreet/"
inherit F_CLEAN_UP;
int main()
{  string filename,file;
   object room,me;
   int i;
   me=this_player();room=environment(me);
   if(room->query("exits/north")) return notify_fail("往北已经有路了！！\n");
   if(room->query("coor/z")!=0) return notify_fail("你只能扩展西游街！！\n");
   if(room->query("coor/x")!=50) return notify_fail("你只能扩展西游街！！\n");
   if(room->query("coor/y")<30) return notify_fail("你只能扩展西游街！！\n");
   i=(room->query("coor/y")-20)/10;
filename=__ROOMDIR__"street"+(string)i+".c";file=read_file(filename);
   file=replace_string(file,"#define ID "+(string)i,"#define ID "+(string)(i+1));
   filename=__ROOMDIR__"street"+(string)(i+1)+".c";write_file(filename,file,1);i++;
filename=__ROOMDIR__"street000.c";file=read_file(filename);
   file=replace_string(file,"#define ID 100","#define ID "+(string)(i)+"00");
   filename=__ROOMDIR__"street"+(string)i+"00.c";write_file(filename,file,1);
   file=replace_string(file,"#define ID "+(string)(i)+"00","#define ID "+(string)(i)+"01");
   filename=__ROOMDIR__"street"+(string)i+"01.c";write_file(filename,file,1);
filename=__ROOMDIR__"street"+(string)(i-1)+".c";file=read_file(filename);
   file=replace_string(file,"//","");write_file(filename,file,1);
   message_vision("$N夹七夹八胡乱摸出一大堆卡片往空中一扔，喊到：改建卡！改建卡！\n",me);
   write("3 file(s) copied. 1 file(s) modified.\n");
   message_vision("嘁哩嚓哪还真出来一片空地，西游街看起来又长了一些。\n",me);
return 1;
}

