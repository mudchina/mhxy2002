// by happ@YSZZ
inherit ROOM;
#include <hen.h>

void create ()
{
  set ("short", "¹«Ô°");
  set ("long", @LONG


        ÔÚ¹«Ô°ÀïÃæ»á·¢ÉúÐí¶àÓÐÈ¤µÄÊÂÇéÅ¶£¬Èç¹ûÄãÃ»ÓÐÊÂ£¬¾Í¿ÉÒÔºÍ
    ÄàµÄÐ¡¼¦Ò»ÆðÀ´Õâ¸öµØ·½É¢²½£¬ÊäÈë [1;32mwalk [m¡£

LONG);

  set("exits", ([ /* sizeof() == 4 */
        "west": __DIR__"road5",
]));

        setup();
}

void init()
{
        add_action("do_walk","walk");
}

int do_walk()
{
        object ob = this_player();

        switch(random(10))
        {

                case 0:
                ob->add("hen/money",100);
                ob->command_function("cls");
                ob->command_function("shape");
                cat(PICKMONEY);
                ob->add("hen/dirty",6);
                ob->add("hen/happy",6);
                ob->add("hen/satisfy",6);
                break;

                case 1:
                ob->command_function("cls");
                ob->command_function("shape");
                cat(FRIEND1);
                ob->add("hen/dirty",6);
                ob->add("hen/happy",6);
                ob->add("hen/satisfy",6);
                break;

                case 2:
                ob->command_function("cls");
                ob->command_function("shape");
                cat(FRIEND2);
                ob->add("hen/dirty",6);
                ob->add("hen/happy",6);
                ob->add("hen/satisfy",6);
                break;

                case 3:
                ob->add("hen/money",-100);
                ob->command_function("cls");
                ob->command_function("shape");
                cat(LOSEMONEY);
                ob->add("hen/dirty",6);
                ob->add("hen/happy",6);
                ob->add("hen/satisfy",6);
                break;

                case 4:
                ob->add("hen/money",-50);
                ob->command_function("cls");
                ob->command_function("shape");
                cat(SPEND);
                ob->add("hen/dirty",6);
                ob->add("hen/happy",6);
                ob->add("hen/satisfy",6);
                break;

                case 5:
                ob->command_function("cls");
                ob->command_function("shape");
                cat(PICKTOY1);
                ob->add("hen/dirty",6);
                ob->add("hen/happy",6);
                ob->add("hen/satisfy",6);
                ob->add("hen/inventory/toy",1);
                break;

                case 6:
                ob->command_function("cls");
                ob->command_function("shape");
                cat(PICKTOY2);
                ob->add("hen/dirty",6);
                ob->add("hen/happy",6);
                ob->add("hen/satisfy",6);
                ob->add("hen/inventory/toy",1);
                break;

                case 6:
                ob->command_function("cls");
                ob->command_function("shape");
                cat(SHIT);
                ob->add("hen/dirty",10);
                ob->add("hen/happy",-1);
                ob->add("hen/satisfy",-1);
                break;

                default:
                ob->command_function("cls");
                ob->command_function("shape");
                cat(WALK);
                ob->add("hen/dirty",6);
        }
        ob->add("hen/affection",1);
        ob->start_busy(1);
        return 1;
}
