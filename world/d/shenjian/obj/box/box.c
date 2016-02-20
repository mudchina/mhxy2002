#include <ansi.h>

inherit ITEM;

void create()

           {
        set_name("箱子", ({ "woodcase" , "case"}) );

        set_weight(500);

        set_max_encumbrance(40000);

        if( clonep() )

        set_default_object(__FILE__);

        else 
        {

                set("unit", "口");

                set("long",

		"一口陈旧平凡，决不会引起任何人注意的箱子。扁扁的一口箱子，有一尺多宽，两尺多长，整个箱子用暗褐色的牛皮包着。你可用它（make）或（remake）出当今武林中的任何神兵利器。\n");
        
}

            }
int is_container()
 { return 1; }

void init()

         {
	add_action("do_make","make");
}

int do_make(string arg)
      
{
	object me;

	object obj;

	me=this_player();

        if(environment()==this_player() && (int) this_player()->query("sen")>250)

{		
	if(!arg) return 0;

	{
	me->set("sen",1);

             if(arg=="ningsword")
        {obj=new(__DIR__"nsword");
         obj->move(me);
        
write("你将手中的箱子打开，用其中的零件拼成了一把凝碧剑。\n");}

             if(arg=="yunblade")
        {obj=new(__DIR__"yunblade");
         obj->move(me);
        
write("你将手中的箱子打开，用其中的零件拼成了一把瀚海云烟。\n");}     	
		                     if(arg=="bloomblade")
        {obj=new(__DIR__"bloomblade");
         obj->move(me);
        
write("你将手中的箱子打开，用其中的零件拼成了一把血刀。\n");}
    
        if(arg=="wandao") 
        {obj=new(__DIR__"lou");
         obj->move(me);
        
write("你将手中的箱子打开，用其中的零件拼成了一把圆月弯刀。\n");}

             if(arg=="feidao")
        {obj=new(__DIR__"xlfd");
         obj->move(me);
        
write("你将手中的箱子打开，用其中的零件拼成了一把小李飞刀。\n");}

             if(arg=="cangqiong")
        {obj=new(__DIR__"cq");
         obj->move(me);
        
write("你将手中的箱子打开，用其中的零件拼成了一把苍穹神剑。\n");}
             if(arg=="long-blade")
        {obj=new(__DIR__"long-blade");
         obj->move(me);
        
write("你将手中的箱子打开，用其中的零件拼成了一把闪电龙鳞劈。\n");}

             if(arg=="seasword")
        {obj=new(__DIR__"seasword");
         obj->move(me);
        
write("你将手中的箱子打开，用其中的零件拼成了一把海渊剑。\n");}	
   if(arg=="staff")
        {obj=new(__DIR__"jgstaff");
         obj->move(me);
        
write("你将手中的箱子打开，用其中的零件拼成了一把金光禅杖。\n");}	
   if(arg=="rustysword")
        {obj=new(__DIR__"musword");
         obj->move(me);
        
write("你将手中的箱子打开，用其中的零件拼成了一把绑着一块木头的锈铁片。\n");}	
   if(arg=="hammer")
        {obj=new(__DIR__"starhammer");
         obj->move(me);
        
write("你将手中的箱子打开，用其中的零件拼成了一把流星锤。\n");}	
   if(arg=="whip")
        {obj=new(__DIR__"cbwhip");
         obj->move(me);
        
write("你将手中的箱子打开，用其中的零件拼成了一把慈悲鞭。\n");}	
   if(arg=="windblade")
        {obj=new(__DIR__"dafeng");
         obj->move(me);
        
write("你将手中的箱子打开，用其中的零件拼成了一把大风刀。\n");}	
   if(arg=="darksword")
        {obj=new(__DIR__"yasword");
         obj->move(me);
        
write("你将手中的箱子打开，用其中的零件拼成了一把雅乌古剑。\n");}	
   if(arg=="soulcrasher")
        {obj=new(__DIR__"xuesword");
         obj->move(me);
        
write("你将手中的箱子打开，用其中的零件拼成了一把寒天吹血。\n");}	
   if(arg=="fulongblade")
        {obj=new(__DIR__"dragonblade");
         obj->move(me);
        
write("你将手中的箱子打开，用其中的零件拼成了一把伏龙宝刀。\n");}	
   if(arg=="fireblade")
        {obj=new(__DIR__"fireblade");
         obj->move(me);
        
write("你将手中的箱子打开，用其中的零件拼成了一把火焰长刀。\n");}	
   if(arg=="deitysword")
        {obj=new(__DIR__"deitysword");
         obj->move(me);
        
write("你将手中的箱子打开，用其中的零件拼成了一把天下无双。\n");}		
if(arg=="jewelsword")
        {obj=new(__DIR__"jewelsword");
         obj->move(me);
        
write("你将手中的箱子打开，用其中的零件拼成了一把镶着十三颗明珠的剑。\n");}
 destruct(this_object());
	}

	return 1;
}

        return 0;
}