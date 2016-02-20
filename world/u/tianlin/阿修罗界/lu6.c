//sgzl

inherit ROOM;
#include <ansi.h>
void create ()
{
set ("short", BLK"ºÚ°µÖ®Ô¨"NOR);
  set ("long", @LONG
[1;31mÕâÀï¾ÍÊÇÍ¨Íù°¢ÐÞÂÞ½çÖ®Â·,Ò»ÌõÍ¨ÏòËÀÍö,[2;37;0m
[1;31mÍ¨ÏòÍ´¿à,Í¨Ïò×ï¶ñµÄºÚ°µÖ®Â·.[2;37;0m
[1;31mËÄÖÜÄ§ÆøÉ­É­,ÈÃÈË²»º®¶øÀõ![2;37;0m
LONG);

  set("exits", ([
      ]));

  set("objects", ([
         __DIR__"npc/gui" : 2,
      ]));

  setup();
}

void init ()
{
  add_action ("do_go", "go");
}

int do_go (string dir)
{
    object who = this_player();
    string *names = ({
    "west",
    "east",
    "south",
    "north",
    });


    if (! dir)
      return 0;

    if (who->query("kee")>50)  who->add("kee",-80); 
    else
      {
      who->unconcious();
      return 1;
      }


    if (random(5))
      {
      message_vision ("$NÅ¬Á¦µØÑ°ÕÒ×Å³ö¿Ú¡£\n",who);
      }
    else
    {
      if (dir != names[random(sizeof(names))])
        {
        message_vision ("$NÖÕÓÚÕÒµ½Ò»Ë¿·ìÏ¶£¬³åÁË³öÈ¥¡£\n",who);
        who->move(__DIR__"men");
        return 1;
        }
      else
        {
        message_vision ("$NÖÕÓÚÕÒµ½Ò»Ë¿·ìÏ¶£¬³åÁË³öÈ¥¡£\n",who);
        who->move(__DIR__"lu2");
        return 1;
        }
    }



  return 0;
}


