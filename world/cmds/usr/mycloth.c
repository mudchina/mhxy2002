// 黄金圣衣召唤 by LitChi 2001/8/12
#include <ansi.h>
inherit F_CLEAN_UP;

int help(object me);
int main(object me, string arg)
{
        object ob, *inv;
        string cloth_name, cloth_id;
        int i;
        
        if (!me->query("12gong/all") || me->query("12gong/number") < 12 )
          return notify_fail("你未打完黄金十二宫。\n");
        
        inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++) {
            if(inv[i]->query("id") == "huangjin shengyi") return notify_fail("黄金圣衣就在你身上，你还召唤什么？！\n");
        }       
        cloth_name = me->query("12gong/cloth_name");
        if(!cloth_name) cloth_name = "黄金圣衣";
        cloth_name = HIY+cloth_name+NOR;
        cloth_id = me->query("12gong/cloth_id");
        if(!cloth_id) cloth_id = "huangjin shengyi";
        
        ob = new("/d/12gong/obj/gold_cloth");
        ob->set_name(cloth_name,({cloth_id}));
        ob->setup();
        ob->move(me);
        message_vision("$N大叫一声：“黄金圣衣～～～！！”，只见天空中出现了一件$n，准确的落在了$N身上！\n",me,ob);
        "/cmds/std/wear"->main(me,cloth_id);
        
        return 1;

}

int help(object me)
{
write(@HELP
指令格式 : mycloth
 
如果你打过了黄金十二宫，可以用这个命令召唤自己的圣衣。 
 
HELP
    );
    return 1;
}

