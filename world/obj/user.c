// user.c
//By tianlin@mhxy for 2002.2.25.加入特殊法宝自动载入模块
#include <ansi.h>
#include <origin.h>
#include <user.h>
#include <command.h>

inherit CHARACTER;
inherit F_AUTOLOAD;
inherit F_SAVE;
inherit F_BACKUP;
inherit F_ENCODING;

static int last_age_set;

void create()
{
        ::create();
        set_name("使用者物件", ({ "user object", "user", "object" }) );
}

void terminal_type(string term_type)
{
        set_temp("terminal_type", term_type);
        message("system", "终端机型态设定为 " + term_type + "。\n", this_object());
}

void reset()
{
        if( (int)query("potential") - (int)query("learned_points") < 100 )
                add("potential", 1);
        if( (int)query("thief") > 0 )
                add("thief", -1 );
}

// This is used by F_SAVE to determine the filename to save our data.
string query_save_file()
{
        string id;

        id = query("id", 1);
        if( !id ) id = geteuid();
        if( !id ) id = getuid();
        if( !stringp(id) ) return 0;
        return sprintf(DATA_DIR "user/%c/%s", id[0], id);
}

// save(1) will only save player data, do not touch autoload.
// used by /feature/vendor_sale.
// normal save should use save() or save(0).
// mon 5/12/98
int save(int raw)
{
        int res;

        if(!raw) save_autoload();
        res = ::save();
        if(!raw) clean_up_autoload();           // To save memory
        return res;
}

int backup()
{
        int res;

        save_autoload();
        res = ::backup();
        clean_up_autoload();            // To save memory
        return res;
}

// This function updates player's age, called by heart_beat()
void update_age()
{
        int userage;
        string suserage;
        
       if(environment()&&environment()->query("no_time")){
        
        last_age_set = time();
        return;
    }
        if( !last_age_set ) last_age_set = time();
        add("mud_age", time() - last_age_set);
        last_age_set = time();
        //set("age",14 + (int)query("age_modify")/86400 + (int)query("mud_age")/ 86400);
        userage=14 + (int)query("age_modify")/86400 + (int)query("mud_age")/ 86400;
        set("age", userage);
        suserage=sprintf("%d",userage);
 if((int)query("mud_age")%86400 < 3600&&!query("shengri/"+suserage)&&userage>14)
              {
       if(query("combat_exp")<20000) return;
     tell_object(this_object(),"祝你生日快乐！恭喜你将获得特别的生日礼物。\n");
     //tell_object(this_object(),"去牡丹宴厅找精灵要生日礼物去吧。\n");
           this_object()->set("shengri/"+suserage,1);
           this_object()->set("birthday",1);
   message("channel:chat",HIR"【"HIW"梦幻西游"HIR"】"HIG"精灵使："+HIR"好象"+query("name")+HIR"的"+suserage+"岁生日到了，我已经给你准备好了生日礼物!\n"NOR,users());
 }
        
}

void setup()
{
   mapping   fabao_map;
   string  *fabao_list, *id_list, *t_list;
   string  *special_id_list, *special_t_list;   
   int i;
   object newob,special_fabao,newob2;
   string fabao_id,special_fabao_id;   

   // We want set age first before new player got initialized with
   // random age.
   update_age();

   ::setup();
   restore_autoload();

    // here We restore the self-made fabao
   fabao_map = query("fabao");
    if( !mapp(fabao_map) && !query("special_fabao"))
     return;
   if(mapp(fabao_map))
   {
   fabao_list = keys(fabao_map);
   for(i=0; i<sizeof(fabao_list); i++)  {
        newob = new("/obj/fabao");
        if( newob )   {
            newob->set("owner_id", query("id"));
            newob->set("series_no", fabao_map[fabao_list[i]]);
            if( !newob->restore() )   {
          tell_object(this_object(), "不能 restore fabao. \n");
          destruct(newob);
          continue;
          }
          fabao_id = (string)newob->query("id");
//added by let
          if(!fabao_id) return;
          fabao_id = replace_string(fabao_id, " ", "_");
          newob->set("id", fabao_id);
          seteuid(fabao_id);
          export_uid(newob);
          seteuid(getuid());

          id_list = ({ fabao_id });
          t_list = explode(fabao_id, "_");
          if( sizeof(t_list) > 1)   {
          id_list += t_list;
          }
          newob->set_name(newob->query("name"), id_list);
          if( stringp(newob->query("default_file")) )
          newob->set_default_object( newob->query("default_file") );

          newob->save();
          newob->move(this_object());
          }
       }
   }
//如果有特殊法宝由忘川24/11/1999增加
   switch( query("special_fabao") )
   {
   case 0://没有特殊法宝
   return;
   case 1://逃跑类
   special_fabao = new("/d/obj/tfabao/tfabao1");
   break;
   case 2://收取类
   special_fabao = new("/d/obj/tfabao/tfabao2");
   special_fabao->set_max_encumbrance(50000);
   break;
   case 3://攻击类
   special_fabao = new("/d/obj/tfabao/tfabao3");
   break;
   }
   if(!special_fabao)
   {
   tell_object(this_object(), "不能恢复特殊法宝。\n");
   return;
   }

   newob2 = new("/obj/Tfabao");
   if(newob2)
   {
   newob2->set("owner_id", query("id"));
   if( !newob2->restore() )
   {
   tell_object(this_object(), "不能恢复特殊法宝。\n");
   destruct(newob2);
   return;
   }
   special_fabao_id = (string)newob2->query("id");
   if(!special_fabao_id) return;
   special_fabao_id = replace_string(special_fabao_id, " ", "_");
   special_fabao->set("id", special_fabao_id);
   seteuid(special_fabao_id);
   export_uid(special_fabao);
   seteuid(getuid());
   special_id_list = ({ special_fabao_id });
   special_t_list = explode(special_fabao_id, "_");
   if( sizeof(special_t_list) > 1)
   {
   special_id_list += special_t_list;
   }
   special_fabao->set_name(newob2->query("name"), special_id_list);
   special_fabao->set("owner_id",query("id"));
   special_fabao->set("long", newob2->query("long"));
   special_fabao->set("unit", newob2->query("unit"));
   special_fabao->set("special_fabao", newob2->query("special_fabao"));
   newob2->save();
   special_fabao->move(this_object());
   destruct(newob2);
   }
}


private void user_dump(int type)
{
        switch(type) {
                case DUMP_NET_DEAD:
                        tell_room( environment(), query("name") + "断线超过"
                                + chinese_number(NET_DEAD_TIMEOUT/60)
                                + "分钟，自动退出这个世界。\n");
                //      command("quit");
                        // mon 7/5/98 to force quit.
                        QUIT_CMD->main(this_object(),"",1);
                        break;
                case DUMP_IDLE:
       if((!query("env/invisibility") || !wizardp(this_object() )) && !environment(this_object())->query("chat_room") ){
                        tell_object( this_object(), "对不起，您已经发呆超过 " 
                                + IDLE_TIMEOUT/60 + " 分钟了，请下次再来。\n");
                        tell_room( environment(), "一阵风吹来，将发呆中的" + query("name")
                                + "化为一堆飞灰，消失了。\n", ({this_object()}));
                        //command("quit");
                        // mon 7/5/98
                        QUIT_CMD->main(this_object(),"",1);
                                   
                        return;
                      }
                      
                       if(in_input()&&(!wizardp(this_object() ))){
                        tell_object( this_object(), "对不起，您已经输入文字发呆超过 " 
                                + IDLE_TIMEOUT/60 + " 分钟了，请下次再来。\n");
                        tell_room( environment(), "一阵风吹来，将输入文字发呆中的" + query("name")
                                + "化为一堆飞灰，消失了。\n", ({this_object()}));
                        //command("quit");
                        // mon 7/5/98
                        QUIT_CMD->main(this_object(),"",1);
                                   
                        return;
                      }
                      break;
                default: return;
        }
}

// net_dead: called by the gamedriver when an interactive player loses
// his network connection to the mud.
private void net_dead()
{
        object link_ob;

        if( objectp(link_ob = query_temp("link_ob")) )  {
          if(!link_ob->is_character()) {
            link_ob->set("last_on", time());
            link_ob->set("last_from", query_ip_name(this_object()));
            link_ob->save();
          }
        }

        if( userp(this_object()) ) 
            CHANNEL_D->do_channel(this_object(), "sys", "断线了。",0,1);

        // used in logind for IP check
        set_temp("netdead_ip", query_ip_number(this_object()));

    remove_call_out("do_net_dead");
    call_out("do_net_dead",15);
}

// delay the actual net_dead mark to prevent
// use net_dead to avoid killing.
// mon 7/5/98
private void do_net_dead()
{
        object link_ob;

        if(!this_object()) return;

        // not net_dead any more.
        if(interactive(this_object())) return;

        set_heart_beat(0);
        if( objectp(link_ob = query_temp("link_ob")) )  {
          destruct(link_ob);
        }

        // Stop fighting, we'll be back soon.
        add_netdead_enemy();
        remove_all_enemy();

        set_temp("netdead", 1);
        if( userp(this_object()) ) {
            call_out("user_dump", NET_DEAD_TIMEOUT, DUMP_NET_DEAD);
            if (!this_object()->query("env/invisibility"))
                tell_room(environment(), query("name") + "断线了。\n", this_object());
        } else {
                command("quit");
        }
}

// reconnect: called by the LOGIN_D when a netdead player reconnects.
void reconnect()
{
        set_heart_beat(1);
        set_temp("netdead",0);
        remove_netdead_enemy();
        remove_call_out("user_dump");
        remove_call_out("do_net_dead");
        tell_object(this_object(), "重新连线完毕。\n");
}

