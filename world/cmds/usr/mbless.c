#include <ansi.h>

inherit F_CLEAN_UP;

string *color = ({
    RED, GRN, YEL, BLK, MAG, BLU, CYN, WHT, 
    HIR, HIG, HIY, HIB, HIM, HIC, HIW, });
string *color1 = ({
    RED, GRN, YEL, MAG, BLU, CYN, 
    });

void input_number(string arg);
void show_emote(string* arg,string text);

string *pic = ({ @TEXT
        __   __
       /  \./  \/\_
   __{^\_ _}_   )  }/^\
  /  /\_/^\._}_/  //  /
 (  (__{(@)}\__}.//_/__A____A_______A_____A_____A_____A___A___A______
  \__/{/(_)\_}  )\\ \\---v-----V-----V---Y--v----Y----v---V-----v---
    (   (__)_)_/  )\ \>
     \__/     \__/\/\/
   \__,--'


TEXT,
@TEXT

           ,g  8b ,g                 ,g        8g   8g
       o8888"  88 Y8     .od888888888P"       88'  88'
         88    88 "        88  88  88        88'  88888888b
     8888888888888888   d88888888888888b    888  88  oo  88
         88    88       88    88      88   8'88 8'   88  P'
         88,o  88 o9,     888888888888       88    8 88
         88P   88,8P         88              88   o8 88 g
       ,888    888'         88888888b        88   8' 88 `8,
      d8'88   g88          88 gg ,88'        88  ,P  88  8b
      8' 88 oP 88,        d8' `g88'          88  8   88  `P
         88    `88 g     o8'  gg88b,         88 f    88
        d8'      `b'    o8  oP'   "Y8ao      88     d8'
TEXT,

@TEXT
 .        *                  . . . .  .   .  + .
            "You Are Here" .   .  +  . . .
.                 |      .  .   .    .    . .
                  |     .    .    . +.    +  .
                 \|/            .       .   . .
        . .       V          .    * . . .  .  +   .
           +     ☆           .   .      +
                            .       . +  .+. .
  .                      .     . + .  . .     .      .
           .      .    .     . .   . . .
      *             .    . .  +    .  .           .
          .     .    .  +   . .  *  .       .
               . + .  .  .  .. +  .
.      .  .  .  *   .  *  . +..  .            *
 .      .   . .   .   .   . .  +   .    .            +
TEXT,
@TEXT
 ..           .           .        .     .   .
  *     \     |   /               + . :      *   .            .    *
  .   ---   /    \   ---       .     .   . .     .     *       .
   .       | ~  ~ |        .        . . . .  .   .  + .
      ---   \__O_/   ---         :     .   .  +  . . .
     .      /  |    .  . .     . .   .   .   . .   +  .     +
   .   *  . .      . .    . .  +    .  ...     - O -. .
          .     . + .  .  .  .. +  ..       . / |
 ..      .  .  .  *   .  *  . +..  .            *
  .      .   . .   .   .   . .  +   .    .            +

  .      .   . .   .   .   . .  +   .    .            +

                                   .&______~*@*~______&.           *
                                 "w/%%%%%%%%%%%%%%%%%%%\w"        ***
      __/M__                    p-p_|__|__|_____|__|__|_q-q      **Y**
 ____|O_^_O|___________________[EEEEM==M==MM===MM==M==MEEEE]-__....|....

    ＤＯ ＹＯＵ ＦＥＥＬ ＴＨＥ ＬＯＶＥ ＴＯＮＩＧＨＴ？
TEXT,
@TEXT

             * *   * * *   * *
            *    *    *  *    *
        <========     *==     *==<<<<<<
             *       *       *
               *   *   *   *
                 *       *


TEXT,
  @TEXT
            ...  :``..':
             : ````.'   :''::'
           ..:..  :     .'' :
        ``.    `:    .'     :
            :    :   :        :
             :   :   :         :
             :    :   :        :
              :    :   :..''''``::.
               : ...:..'     .''
               .'   .'  .::::'
              :..'''``:::::::
              '         `::::
                          `::.
                           `::
                            :::.
                 ..:```.:'`. ::'`.
               ..'      `:.: ::
              .:        .:``:::
              .:    ..''     :::
               : .''          ::
                :             ::
                               :
                               :
                               :
                               :
                               :
                               .

TEXT,
@TEXT
         .     .                                   .     .
    ...  :``..':                              ...  :``..':
     : ````.'   :''::'                         : ````.'   :''::'
   ..:..  :     .'' :                        ..:..  :     .'' :
``.    `:    .'     :                     ``.    `:    .'     :
    :    :   :        :                       :    :   :        :
     :   :   :         :                       :   :   :         :
     :    :   :        :                       :    :   :        :
      :    :   :..''''``::.                     :    :   :..''''``::.
       : ...:..'     .''                         : ...:..'     .''
       .'   .'  .::::'                           .'   .'  .::::'
      :..'''``:::::::                           :..'''``:::::::
      '         `::::                           ,         `::::
                  `::.                                      `::.
                   `::                                       `::
               :::.                                      :::.
         ..:```.:'`. ::'`.                         ..:```.:'`. ::'`.
       ..'      `:.: ::                          ..'      `:.: ::
       ..'      `:.: ::                          ..'      `:.: ::
      .:        .:``:::                         .:        .:``:::
      .:    ..''     :::                        .:    ..''     :::
       : .''         .::                         : .''         .::
        :          .'`::                          :          .'`::
                       ::                                        ::
                       ::                                        ::
                        :                                         :
                        :                                         :
                        :                                         :
TEXT,

@TEXT

                      .      .'
                       :`...' `.,'  '
                   `.  ' .**.  ; ; ':
                   ` ``:`****,'  .' :
                 ..::.  ``**":.''   `.
               .:    `: ; `,'        :
              `:    `   :         ;
                   :   :   :        ;
                   :    :   :     .:
                    :    :   :..,'  ``::.
                     `....:..'  ..:;''
                     .:   . ...::::
                    ,'''''``:::::::
                              `::::
                                `::.
                                 `::
                          . ,.    ::::'      ,..
                        .'.'  ``.  ::      .'.. `.
                       '        .: ::    ,'.'     .
                     .' ,'    .::::::   ,.'    .:::.
                   .' .'  ..:'     ::: .,   .;'     ~
                  ,;::;.::''        ::.:..::'
                 ~                  ::;'
                 ~                  ::;'
                                    ::
                                  ,:::
                                    ::.
                                    `::
                                     ::
                                     ::
                                     ::
                                     ::
TEXT, });

int main(object me,string arg)
{
    object male, female, env;
    string id1, id2, name1, name2;

    env = environment(me);

    if( !arg || sscanf(arg, "%s with %s", id1, id2) != 2 )
        return notify_fail("指令格式：mbless MALE with FEMALE\n");

//    if( !objectp(male = get_object( id1 ) ) 
//        || !objectp(female = get_object ( id2 ) ) )
    if(!objectp(male = present(id1, environment(me))) ||
       !objectp(female = present(id2, environment(me))))
        return notify_fail("这里没有这两个人哦~~\n");

    if ( ! living( male ) || ! living (female) )
        return notify_fail("看清楚点，那不是活的。\n");
  if(( male->query("gender") != "男性" &&  male->query("gender") != "雄性")
        ||(female->query("gender") != "女性" &&female->query("gender")!="雌性"))
        return notify_fail("老兄，不要错点鸳鸯哦~\n");

    name1 = male->query("name");
    name2 = female->query("name");

    if ((me->query("kee")<100) ||
        (me->query("gin")<100) ||
        (me->query("force")<100))
        return notify_fail("你没有精神祝福人家了 !\n");
    me->set("kee",10);
    me->set("gin",10);
    me->set("force",10);

//    if ( !me->query("env/score") )
    message_vision(CYN"$N虔诚地双手合十，默默地祈祷道：爱神\n"
            "呀，请赐予" + name1 + "和" +
            name2 + "幸福吧！愿他们会\n"
            "永远相亲相爱，互相扶持，爱火永不熄灭！\n",
                me);
    call_out("show_picture", 2 + random( 3 ), name1, name2);
    return 1;
}

void show_picture(string name1, string name2)
{
    string str;
    str = GRN "只听见东方轰隆隆地响了一声，一个姣美的女声\n"
        "响起：\n\t" HIM + name1 + 
       NOR "" BLU "和" NOR "" HIM + name2 + NOR "" BLU"将在我的庇护下永远\n"
        "幸福！我以爱神的名义起誓！\n\n\n" NOR;
    message("marry",str, users());
    call_out("show_flower", 2, name1, name2);
}

void show_flower(string name1, string name2)
{
    string str;
    str = "天空中突然闪出一道绚丽的火花，一个巨大的图案逐渐\n"
          "显现：\n";
    str += color1[random(sizeof(color1))] + pic[random(sizeof(pic))] + NOR;
    str += YEL "四下里隐隐传来众人深沉的祝福声：\n";
         message("marry", str, users());
    if ( random( 2) )
        call_out( "show_flower",2 + random ( 3 ),name1,name2 );
}

