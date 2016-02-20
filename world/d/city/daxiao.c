// By tianlin 2001.5.1
// Room: /city/daxiao.c

inherit ROOM;

int sos(int,int);
void fresh(object ob);
void create()
{
        set("short", "∂ƒ≥°");
        set("long", @LONG
’‚¿Ô «∂ƒ(play)°∏¥Û–°°πµƒ∑øº‰£¨«Ω…œπ“◊≈“ªøÈ≈∆◊”(paizi)°£
Œ˜±ﬂµƒ∑øº‰ «¥Û∂ƒº“ÕÊµƒµÿ∑Ω°£
LONG );
        set("item_desc", ([
                "paizi" :
"±æ∂ƒ≥°–¬ø™∑≈∂ƒ°∏¥Û–°°π’˝¥¶”⁄≤‚ ‘Ω◊∂Œ°£\n"
"°∏¥Û–°°π∂ƒ∑®£∫\n"
"π≤”√»˝¡£…´◊”»ˆ‘⁄“ª÷ªÕÎ¿Ô£¨…´◊”µ„ ˝◊‹∫Õ£∫\n"
"       Àƒ ÷¡  Æ Œ™°∏–°°π£¨\n"
"        Æ“ª ÷¡  Æ∆ﬂ Œ™°∏¥Û°π£¨\n"
"       »˝¡£…´◊”µ„ ˝œ‡Õ¨£¨‘Ú¥Û–°Õ®≥‘°£\n"
"\nø™¥Û≈‚¥Û£¨ø™–°≈‚–°£¨“ª≈‚“ª°£\n"
"\n±æ∂ƒ≥°Ω” ‹∏˜÷÷ªı±“º∞π¶∑Úµƒµ„ ˝Œ™∂ƒ◊¢°£\n"
"\n∂ƒ◊¢Œ™“ª«ßµΩ∂˛ÕÚŒÂ°£\n",
        ]));
        set("exits", ([
                "south" : __DIR__"dongmen",
        ]));
//	set("no_clean_up", 0);
        set("no_fight", "1");
        setup();
}

void init()
{
        add_action("do_gamble", "play");
}

int do_gamble(string arg)
{
        int a,b,c;
        int wager, skill, lpoint, tpoint;
        string wtype1, wtype2, wtype0, status;
        object mtype, me;
        mapping lrn;

        int min, max;
        min = 1000;
        max = 25000;

        me = this_player();

      //  if (me->query_temp("casino/mark"))
       //         return notify_fail("ƒ„’‚√¥◊≈º±∞°? ªπ «‘Ÿ∂‡–›œ¢“ªª·∂˘∞… -:)\n");

    if (!arg || sscanf(arg, "%s %s %s %d", wtype0, wtype1, wtype2, wager) !=4)
        return notify_fail("play big|small money|skill <type> <amount>\n"
"eg. play big money silver 3 OR play small skill dodge 10\n");

        if (wtype1 == "money")
        {
                mtype = present(wtype2 + "_money", me);
                if( !mtype)          return notify_fail("ƒ„…Ì…œ√ª”–’‚÷÷ªı±“°£\n");
                if( wager < 1 )        return notify_fail("ƒ„“™—π∂‡…Ÿ∞°?\n");
                if( (int)mtype->query_amount() < wager)
                        return notify_fail("ƒ„…Ì…œ√ª”–ƒ«√¥∂‡" + mtype->query("name") + "°£\n");
                if( wager*(mtype->query("base_value")) < min ||
                    wager*(mtype->query("base_value")) > max )
                        return notify_fail("ƒ„µƒ∂ƒ◊¢≤ª‘⁄œﬁ∂Ó÷Æƒ⁄!\n"
                        "’‚¿Ôµƒœﬁ∂Ó «" + chinese_number(min) + "÷¡" + chinese_number(max) + "°£\n");
        }
        else if (wtype1 == "skill")
        {
                skill = me->query_skill(wtype2, 1);
                if( skill < 1 )
                return notify_fail("ƒ„“™’©∂ƒ∞°? ƒ„∏˘±æ≤ªª·’‚œÓπ¶∑Ú!\n");
                lrn = me->query_learned(wtype2, 1);
                lpoint = (int)lrn[wtype2];
//              message_vision("learned pt: " + lpoint + "\n", me);
                tpoint = lpoint + sos(1, skill);
//              message_vision("total learned pt: " + tpoint + "\n", me);
                if (wager > tpoint) return notify_fail("ƒ„∂ƒ≤ª∆!\n");
                if (wager < min || wager > max)
                        return notify_fail("ƒ„µƒ∂ƒ◊¢≤ª‘⁄œﬁ∂Ó÷Æƒ⁄!\n"
                        "’‚¿Ôµƒœﬁ∂Ó «" + chinese_number(min) + "÷¡" + chinese_number(max) + "°£\n");
        }
        else    return notify_fail("±æ∂ƒ≥°≤ªΩ” ‹’‚÷÷∂ƒ◊¢°£\n");

        if ( (wtype0 != "big") && (wtype0 != "small") )
                return notify_fail("ƒ„“™∂ƒ¥Ûªπ «∂ƒ–°?\n");

        me->set_temp("gamb_t",(me->query_temp("gamb_t") +1));
        if (me->query_temp("gamb_t") > 50)
     /*   {
                call_out("fresh", 300, me);
                me->set_temp("casino/mark", 1);
                return notify_fail(
"’‚Œª" + RANK_D->query_respect(me) + "£¨ƒ„“—æ≠∂ƒ¡À∫‹æ√¡À£¨ªπ «œ»–›œ¢“ªª·∂˘∞…°£\n");
        } */

        a = random(6) + 1;
        b = random(6) + 1;
        c = random(6) + 1;

        message_vision("ø™£∫" + a + "   " + b + "   " + c + "   £¨", me);

        if ((a == b) && (b == c) )
//              message_vision("ø™£∫" + a + " " + b + " " + c " ,¥Û–°Õ®…±°£\n", me);
                message_vision("¥Û–°Õ®…±°£\n", me);
        else if ( (a+b+c) > 10 )
//              message_vision("ø™£∫" + a + " " + b + " " + c " ,≥‘–°≈‚¥Û°£\n", me);
                message_vision("≥‘–°≈‚¥Û°£\n",me);
        else if ( (a+b+c) < 11 )
//              message_vision("ø™£∫" + a + " " + b + " " + c " ,≥‘¥Û≈‚–°°£\n", me);
                message_vision("≥‘¥Û≈‚–°°£\n",me);

        if ( ( (a == b) && (b == c) ) ||
             ( (a+b+c) > 10 && (wtype0 == "small") ) ||
             ( (a+b+c) < 11 && (wtype0 == "big") ) )
                status = "lose";

        if (wtype1 == "money")
        {
                if ( status == "lose") {
        message_vision(me->query("name") + "[33m ‰¡À[2;37;0m" + chinese_number(wager) +
mtype->query("base_unit") + mtype->query("name") + "°£\n", me);
                        mtype->set_amount((int)mtype->query_amount() - wager);
                        mtype->move(me);
                }
                else {
        message_vision(me->query("name") + "[5m[1;37m”Æ¡À[2;37;0m" + chinese_number(wager) +
mtype->query("base_unit") + mtype->query("name") + "°£\n", me);
                        mtype->set_amount((int)mtype->query_amount() + wager);
                        mtype->move(me);
                }
        }
        else if (wtype1 == "skill")
        {
                if ( status == "lose") {
        message_vision(me->query("name") + "[33m ‰¡À[2;37;0m[36m" + chinese_number(wager) +
"µ„[2;37;0m[1;36m" + to_chinese(wtype2) + "[2;37;0mµƒπ¶¡¶°£\n[2;37;0m", me);
                        wager -= lpoint;
                        while (wager > 0)
                        {
                           wager -= skill*skill;
                           skill -= 1;
                        }
                        wager *= -1;
                        if (wager > lpoint) wager -= lpoint;
                        else wager += (lpoint*-1);
                }
                else {
        message_vision(me->query("name") + "[5m[1;37m”Æ¡À[2;37;0m[36m" + chinese_number(wager) +
"µ„[2;37;0m[1;36m" + to_chinese(wtype2) + "[2;37;0mµƒπ¶¡¶°£\n[2;37;0m", me);
                        wager += lpoint;
                        while (wager >= (skill+1)*(skill+1))
                        {
                          skill += 1;
                          wager -= skill*skill;
                        }
                        wager -= lpoint;
                }
                me->set_skill(wtype2, skill);
                me->improve_skill(wtype2, wager);
        }
        return 1;
}

void fresh(object ob)
{
     //   ob->delete_temp("gamb_t");
        ob->delete_temp("casino/mark");
}

int sos(int lower, int upper)
{
        int x,y;
        x = 0;

        while (lower <= upper)
        {
                y = lower*lower;
                x += y;
                lower++;
        }
        return x;
}
