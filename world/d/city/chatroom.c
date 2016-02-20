// By tianlin@mhxy for 2001.9.3

inherit ROOM;
#include <ansi.h>
int block_cmd(string);

void create ()
{
        set ("short", "ÁÄÌìÊÒ");
        set ("long", @LONG

       [5m [1;35m .[2;37;0m[1;35m           .       .     . [5m : [2;37;0m[1;35m.    [1;36m¡ñ[1;35m    .   .     .     .    [5m . :[2;37;0m[1;35m   .  
 [1;35m .     [1;32m¥ß           [1;35m: .    .        .       .             : .    .     .     
   [1;32m ¥ß ¥ß¥ß  [1;35m  .                [1;32m¥ß   [1;35m .    [5m.             [5m .[2;37;0m          [1;32m¥ß    ¥ß  
   [1;32m¥ß¥ß¥ß¥ß   [1;34m¨¨€¨€¨         [1;32m¥ß¥ß     [1;35m .          [5m.[2;37;0m[1;35m           .   [1;32m¥ß¥ß  ¥ß¥ß  
    [1;31m©g  ©g   [1;34m¨¨~[1;37mÌï[1;34m¨~¨|¨|¨‡     [1;31m©g        [1;37m¥í [1;35m  .           [1;37m¥í        [1;31m©g    ©g      
 [1;37m ¨n¨n¨n¨n¨n¨h[1;34m¨~¨~¨~[1;37mÌï[1;34m¨~[1;37m¨h¨n¨n¨n¨n¨n¨n¨n¨n¨e               ¨b¨n¨n¨n¨n¨n¨n¨n¨n 
                                                 
       [1;35m£è£å£ì£ì£ï¡¡£â£á£â£ù¡¡      £÷£å£ì£ã£ï£í£å¡¡£ù£ï£õ[2;37;0m   

LONG);
        set("exits", ([     
 "north" : "/d/city/kezhan",
   "east" : "/u/gua/damen",
   "enter" : "/u/valen/guardroom",
        ]));
        set("chat_room",1);
  set("objects", ([ /* sizeof() == 2 */
        "/u/tianlin/lovechao" : 1,
        "/u/tianlin/npc/meirongshi" : 1,
]));

        set("no_fight", 1);
        set("no_magic", 1);
        setup();
}

void init()
{       
        int i;
        object ob = this_player();
         //  ob->set("channels","none");
          // ob->command_function("cls");
        object me = this_player();
        tell_room( environment(me), HIG"¡¾"HIR"ÏµÍ³¾«Áé"HIG"¡¿£º"HIG"ÈÈÁÒ»¶Ó­£¬"HIY+me->query("title")+" " +me->query("name")+"("+me->query("id")+")"+HIG"À´µ½"BLINK+HIC"ÃÎ»ÃÎ÷ÓÎ"NOR+HIG"ÁÄÌìÊÒ£¡\n"NOR);
        tell_room( environment(me), "ÇëÓÃ[4;53m[1;31mhelp talk[2;37;0mÀ´ÁË½â[4;53m[1;31mtalk[2;37;0m´ó·¨!!!!\n"NOR);

           ob->set("chat/enter_time",time());
    add_action("block_cmd", "", 1);
    add_action("do_create","create");
    add_action("do_join","join");
    add_action("do_kickout","kk");
    add_action("do_leave","leave");
    add_action("do_say","say");
    add_action("do_list","list");
    add_action("do_lock","lock");
    add_action("do_open","unlock");
    add_action("do_look","look");
       add_action("do_exert","exert");
}

int block_cmd(string args)
{
        object ob = this_player();
        string verb;
        verb = query_verb();
        if ( verb == "chat" ) return 1;
        if ( verb == "bian" ) return 1;
        if ( verb == "exert" ) return 1;
        if ( verb == "who" ) return 1;
        if ( verb == "rumor*" ) return 1;
        if ( verb == "top" ) return 1;
        if ( verb == "chat*" ) return 1;
        if ( verb == "rumor" ) return 1;
        if ( verb == "quit" ) return 1;
        if ( verb == "ys" ) return 1;
        if ( verb == "mp" ) return 1;
        if ( verb == "drop" ) return 1;
        return 0;
}
int valid_leave(object me, string dir)
{
        if(me->query("id")=="hunhun" ||me->query("id")=="zhangrui")
        return ::valid_leave(me, dir);
if( dir=="enter" && !wizardp(me) )
          return notify_fail("ÄÇÀïÖ»ÓĞ»¶»¶²ÅÄÜ½øÈ¥¡£\n");
        return ::valid_leave(me, dir);
        if( me->query_temp("chat/room_name") )
                return notify_fail("Äã»¹ÔÚÁÄÌìÊÒÀïÃæ£¬»¹ÊÇÏÈ(leave)°É¡£\n");

        (       time() - me->query("chat/enter_time") < 120 ) ?
me->improve_skill("talk", 0) : me->improve_skill("talk",10);

      //  tell_object(me,HIG"Ğ»Ğ»£¬»¶Ó­ÔÙ´Î»İ¹ËÃÎ»ÃÎ÷ÓÎÁÄÌìÊÒ¡£\n"NOR);   
        me->delete("chat/enter_time");
        return ::valid_leave(me, dir);
}

int do_create(string arg)
   
{
        object ob = this_player();
        object where = this_object();
        int x,i;
        object *list;
        list = all_inventory(this_object());
        i = strlen(arg);

        if( ! arg )
                return notify_fail("ÄãÒª´´½¨Ê²Ã´ÁÄÌìÊÒ£¿\n");
      
         while(i--) 
                if( arg[i]<=' ' ) {
                        write("¶Ô²»Æğ£¬ÄãµÄÁÄÌìÊÒ²»ÄÜÓÃ¿ØÖÆ×ÖÔª¡£\n");
                        return 1;
                }
        
        if( ob->query_temp("chat/leader") == 1 )
                return notify_fail("ÄúÏÖÔÚÒÑ¾­ÊÇÁÄÌìÊÒµÄÖ÷ÈË¡£\n");

        list = all_inventory(this_object());

           for(x=0;x<sizeof(list);x++) {
              if(list[x]->query_temp("chat/room_name") == arg )
           return notify_fail(HIC"¶Ô²»Æğ£¬ÒÑ¾­ÓĞÈËÊ¹ÓÃÕâ¸öÁÄÌìÊÒ£¡\n"NOR);
            }

        tell_object(ob,HIR"Äú´´½¨ÁË "HIC+arg+HIR" ÁÄÌìÊÒ¡£\n"NOR);
        ob->set_temp("chat/room_name",arg);
        ob->set_temp("chat/leader",1);
        return 1;
}

int do_list()
{
       
        object *list;
        string name;
        int i;
        list = all_inventory(this_object());

        if( !pointerp( list->query_temp("chat/room_name") ))
            return notify_fail(HIC"ÏÖÔÚÃ»ÓĞÈÎºÎÁÄÌìÊÒ¡£\n"NOR);
        write("ÏÖÔÚÒÑ¾­´´½¨µÄÁÄÌìÊÒÓĞ£º\n" );
    write(HIC"¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n"NOR);
        for(i=0;i<sizeof(list);i++)
           {
         if(! list[i]->query_temp("chat/leader") )  continue;
        write(HIG+list[i]->name()+NOR+"  µÄ  "+HIY+name=list[i]->query_temp("chat/room_name")+NOR+"  ÁÄÌìÊÒ\n");
        }
    write(HIC"¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n"NOR);
        return 1;
}

int do_join(string arg)
{
        object ob = this_player();
        int x;
        object *list;        
        list = all_inventory(this_object());

        if( ! arg)
                return notify_fail("ÄãÒª¼ÓÈëÊ²Ã´ÁÄÌìÊÒ£¿\n");

        if( ob->query_temp("chat/room_name") &&
         arg != ob->query_temp("chat/room_name") )
                return notify_fail("ÇëÏÈÀë¿ª(leave)ÁÄÌìÊÒ£¡\n");

        if( arg == ob->query_temp("chat/room_name") )
                   return notify_fail("ÄãÒÑ¾­ÔÚÕâ¸öÁÄÌìÊÒÀïÃæ¡£\n");

          for(x=0;x<sizeof(list);x++)
           {
           if( list[x]->query_temp("chat/room_name") &&
               arg != list[x]->query_temp("chat/room_name") )
            return notify_fail(HIC"¶Ô²»Æğ£¬Ã»ÓĞÕâ¸öÁÄÌìÊÒ£¡\n"NOR);
           }

          for(x=0;x<sizeof(list);x++)
           {
           if( arg == list[x]->query_temp("chat/room_name") && 
                      list[x]->query_temp("chat/lock") == 1 )
            return notify_fail(HIC"¶Ô²»Æğ£¬·¿¼äÒÑ¾­ÉÏËø£¡\n"NOR);
           }


        ob->set_temp("chat/room_name",arg);
          for(x=0;x<sizeof(list);x++)
           {
        tell_object(list[x],ob->name()+"½øÈëÁËÁÄÌìÊÒ¡£\n"NOR);
          }
       return 1;
   }

int do_leave()
{
        object ob = this_player();
        object where=this_object();

        if ( ! ob->query_temp("chat/room_name") )
                return notify_fail("ÄãÏÖÔÚÃ»ÓĞ¼ÓÈëÈÎºÎÁÄÌìÊÒ¡£\n");

        tell_room(where,ob->name()+"Àë¿ªÁË  "+HIC+ob->query_temp("chat/room_name")+NOR+"  ÁÄÌìÊÒ¡£\n");

        ob->delete_temp("chat");
        return 1;
}

int do_kickout(string arg)
{
        int x;
        object ob = this_player();
        object target;
        object *list;
        list = all_inventory(this_object());
   
        if( ! arg )
                return notify_fail("ÄãÒªÌßË­£¿\n");

        if( ! ob->query_temp("chat/leader") )
                return notify_fail("Äã²»ÊÇÕâ¸ö·¿¼äµÄÀÏ´ó£¡\n");        

        target=find_player(arg);
        if( target == ob )
                return notify_fail("Äã»¹ÊÇ×Ô¼ºÀë¿ª°É¡£\n");

        for(x=0;x<sizeof(list);x++)
           {
           if( target->query_temp("chat/room_name") !=
             list[x]->query_temp("chat/room_name") )
            return notify_fail(HIC"¶Ô²»Æğ£¬Õâ¸öÁÄÌìÊÒÀïÃæÃ»ÓĞÕâ¸öÈË£¡\n"NOR);
           }

        target->delete_temp("chat/room_name");
        tell_room(this_object(),target->name()+"±»ÀÏ´óÌßÁË³öÈ¥¡£\n"NOR);
        return 1;
}

   int do_lock()
{
        object ob = this_player();

        if( ! ob->query_temp("chat/leader") )
                return notify_fail("Äã²»ÊÇ·¿¼äµÄÀÏ´ó¡£\n");

        if( ! ob->query_temp("chat/room_name") )
                return notify_fail("ÄãÃ»ÓĞ¼ÓÈëÈÎºÎÒ»¸öÁÄÌìÊÒ¡£\n");

        ob->set_temp("chat/lock",1);
        tell_object(ob,"Äã°Ñ·¿¼äËøÁËÆğÀ´¡£\n");
        return 1;
}
        
int do_open()
{
        object ob = this_player();

        if( ! ob->query_temp("chat/leader") )
                return notify_fail("Äã²»ÊÇ·¿¼äµÄÀÏ´ó¡£\n");

        if( ! ob->query_temp("chat/room_name") )
   
                return notify_fail("ÄãÃ»ÓĞ¼ÓÈëÈÎºÎÒ»¸öÁÄÌìÊÒ¡£\n");

        ob->delete_temp("chat/lock");
        tell_object(ob,"Äã°Ñ·¿¼ä´ò¿ªÁË¡£\n");
        return 1;
}

int do_say(string arg)
{
        object me = this_player();
        object *ob,*target;
        int i;
        string meroom,obroom;
        string outarg;
        meroom = (string)me->query_temp("chat/room_name");
        if(!meroom) return notify_fail("Äã»¹ÊÇÏÈ¼ÓÈë»òÔòÏÈ´´½¨Ò»¸öÁÄÌìÊÒ£¡\n");
        ob=all_inventory(this_object());
        i = sizeof(ob);
        while (i--) {
                obroom = (string)ob[i]->query_temp("chat/room_name");
                if ( meroom == obroom ) 
                {
                        if (sizeof(target)==0)
                                   target=({ob[i]});
                         else
                                target+=({ob[i]});
                }
        }
        if(!stringp(outarg = arg))
                outarg = "£®£®£®£®£®";
        message("vision", HIC"¡¾"GRN+me->query_temp("chat/room_name")+HIC"·¿¼ä¡¿"GRN +
        me->query("name") + NOR"(" MAG+ capitalize(me->query("id")) + NOR")" +
        "ËµµÀ£º" HIC+ outarg + "\n" NOR, target);
        tell_room(this_object(),HIR"©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤\n"NOR);
        return 1;
}

int do_look()
{
        object me = this_player();
        object *ob,*target;
        int i,x,m;
        string meroom,obroom;
        meroom = (string)me->query_temp("chat/room_name");
        if(!meroom) return notify_fail("Äã»¹ÊÇÏÈ¼ÓÈë»òÔòÏÈ´´½¨Ò»¸öÁÄÌìÊÒ£¡\n");
        ob=all_inventory(this_object());
           i = sizeof(ob);
        while (i--) {
                obroom = (string)ob[i]->query_temp("chat/room_name");
                if ( meroom == obroom )
                {
                        if (sizeof(target)==0)
                                target=({ob[i]});
                         else
                                target+=({ob[i]});
                }
        }
   write("ÄãËùÔÚµÄ "+HIC+me->query_temp("chat/room_name")+NOR+" ÁÄÌìÊÒÈËÎïÓĞ£º\n");
    write(HIC"¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n"NOR);
        for(x=0;x<sizeof(target);x++)
        {
       
         for(m=0;m<sizeof(target);m++)
        if(m%3==2) printf("\n");
        if(target[x]->query_temp("chat/leader"))
        write(HIM+target[x]->name()+"   "NOR);
        else 
        write(GRN+target[x]->name()+"   "NOR);
        }
       write(HIC"\n¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n"NOR);
    write("ºìÉ«±íÊ¾ÁÄÌìÊÒÖ÷ÈË£¬¾ßÌåhelp talk\n");

       return 1;
}
int do_exert(string arg)
{
    tell_object(this_player(), "°²È«ÇøÄÚ½ûÖ¹ÔË¶¯¡£\n");
    return 1;
}
