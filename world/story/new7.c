//By tianlin@mhxy for 2002.1.9

#include <ansi.h>

string give_gift();
mixed *story = ({
      "观音：  孙悟空，你这个畜牲，你本来答应如来佛祖护送你师傅唐三藏",
      "        去取西经，你居然跟牛魔王串通起来要吃你师傅，你知不知道",
      "        你犯了弥天大罪？",
      "孙悟空：少罗嗦！你追了我三天三夜，因为你是女人我才不杀你，不要",
      "        以为我怕了你了！",
      "唐僧：  悟空，你怎么可以这样跟观音姐姐讲话呢？",
      "悟空：  哗！不要吵！",
      "唐僧：  你又在吓我！",
      "观音：  你不是怕我又为什么要打伤紫霞仙子抢走她的"HIY"月光宝盒"NOR+WHT"，你不",
      "        就是想躲开我吗？",
      "悟空：  既然躲不了那老孙就跟你绝一死战！",
      "       (悟空将"HIY"月光宝盒"NOR+WHT"随手一抛，正好砸在某人头上。)",
      (: give_gift :),
      "唐僧：  又干什么？",
      "        (俩人正要动手，突然……)",
      "唐僧：  喂喂喂！大家不要生气，生气会犯了嗔戒的！悟空你也太调皮",
      "        了，我跟你说过叫你不要乱扔东西，你怎么又…你看我还没说",
      "        完你又把棍子给扔掉了！月光宝盒是宝物，你把他扔掉会污染",
      "        环境，要是砸到小朋友怎么办？就算砸不到小朋友砸到那些花",
      "        花草草也是不对的！",
      "        (悟空一把抓住唐僧手中的月光宝盒)",
      "唐僧：  干什么？",
      "悟空：  放手！",
      "唐僧：  你想要啊？悟空，你要是想要的话你就说话嘛，你不说我怎么",
      "        知道你想要呢，虽然你很有诚意地看着我，可是你还是要跟我",
      "        说你想要的。你真的想要吗？那你就拿去吧！你不是真的想要",
      "        吧？难道你真的想要吗？……",
      "        悟空：我Kao！",
      "         (悟空一拳将唐僧打倒。)",
});


void create()
{
        seteuid(getuid());
}

mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}

string give_gift()
{
        
        int i;
        object env,ob;
        object *players;
        string msg;

        players = users();
        if (sizeof(players) >= 10)
        {
                for (i = 0; i < 10; i++)
                {
                        ob = players[random(sizeof(players))];
                        if (wizardp(ob)) continue;
                        if (ob->is_fighting()) continue;
                        if (!environment(ob)) continue;
                        if (ob->query_temp("netdead")) continue;
                        
                                
                }
                if(!ob) return "";
                tell_object(ob,"你突然觉的头上一阵疼痛，原来月光宝砸中你了!\n");
                if(random(3)==0)
                ob->unconcious();
                msg="天上掉了一个盒子，将"+ob->name()+"给砸晕了.......\n";
                env=environment(ob);
                if (objectp(env))
                        tell_room(env, msg);
        }

        CHANNEL_D->do_channel( this_object(),"rumor",HIM"好像有人被砸晕了....................\n"NOR);
        return HIM "好像有人被砸晕了....................\n" NOR;
}
