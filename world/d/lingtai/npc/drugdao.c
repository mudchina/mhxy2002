/* 妖神之争 1.0 */

inherit NPC;

mapping *way;
object cart;
object protector;
string oldlong;

mapping *read_table(string);
void give_reward();
void to_rob();
void be_protect();
void go();

void create()
{
        object ob;
        set_name("送药道士", ({"drug daoshi"}) );
        set("gender", "男性" );
        set("age", 25);
    set("combat_exp",1000000);
        set("attitude", "friendly");
        set("vendetta_mark", "authority");
        set("per",22);
        set("chat_chance", 15);
    set("chat_msg",({
        "道士说道：“前途不知是否安全。”\n",
        "道士满脸焦急：这批药物真是城中所急需。\n",
    }) );
    set("force",4000);
        set("max_force",2000);
        set("force_factor",100);
        set("max_mana",2000);
    set("mana",40000);
        set("mana_factor",100);
        
        set_skill("stick",120);
        set_skill("parry",120);
        set_skill("qianjun-bang",150);
        set_skill("force",140);
        set_skill("wuxiangforce",150);
        set_skill("jindouyun",150);
        set_skill("dodge",150);
        set_skill("spells",140);
        set_skill("dao",150);
        
        map_skill("stick","qianjun-bang");
        map_skill("parry","qianjun-bang");
        map_skill("force","wuxiangforce");
        map_skill("dodge","jindouyun");
        map_skill("spells","dao");

      set("chat_chance_combat",90);
      set("chat_msg_combat", ({
        "道士大喊道：“人心不古，连药物也有人要劫。”\n",
        (: perform_action, "stick.qiankun" :),
        (: cast_spell, "dingshen" :),
        (: cast_spell, "light" :),
        (: cast_spell, "thunder" :),
        (: be_protect :)
    }) );
        

        setup();
        add_money("silver", 50);
    carry_object("/d/lingtai/obj/cloth")->wear();
    carry_object("/d/lingtai/obj/bang")->wield();
}

void init()
{
  add_action("do_husong","husong");
}

int do_husong(string arg)
{
    object me=this_player();
    
    if((string)me->query("family/family_name")!="方寸山三星洞")
        return notify_fail("云阳真人摇了摇头：您不是本门中人。\n");
    if(environment(me)->query("short")!="讲经堂"||this_object()->query("be_husong"))
        return notify_fail("云阳真人摇了摇头：这次的药材已经有人护送了，不劳您的大架。\n");
    if(me->query("faith")<800)
        return notify_fail("云阳真人摇了摇头：你的能力值得怀疑！\n");
        
    this_object()->set("be_husong",1);
    me->set_temp("protecting",cart);
    me->set_leader(this_object());
    protector=me;
    tell_object(me,"云阳真人对你笑了笑，道：那么就有劳您护送这一趟了。\n");
    call_out("wait_go",5);    
    return 1;
}

void wait_go(object where)
{
   tell_room(where,"云阳真人说道：你马上准备好行装，准备出发。\n");
   command("nod");      
   command("say 不知谁愿来护送(husong)我？");   
//   oldlong=where->query("long");
  // where->set("long",oldlong+"\n现有一批药材准备送往长安城，需护卫(husong)一名。\n");
   call_out("begin_go",5,where);
}

void begin_go(object where)
{
   tell_room(where,"云阳真人说道：是时候，你们该出发了。\n");
   command("say 那好，我们这就出发！");
//   where->set("long",oldlong);
// go();
   call_out("go",5);
}

void go()
{
        int i,j;
        object robber;
        string *cmds;
        object me = this_player();

        remove_call_out("go");
        for(i=0;i<sizeof(way);i++)
        {
                if (base_name(environment()) != way[i]["room_file"]) continue;
                cmds=explode(way[i]["cmd_table"],";");
                break;
        }
        robber=present("mengmian dahan",environment());
        if (this_object()->is_fighting() || (robber && robber->name()=="蒙面大汉"))
        {
                command("say 风紧，风紧");
                call_out("go",5);
                return;
        }
        if (random(100)<15)
        {
                to_rob();
                call_out("go",10);
                return;
        }
        for(j=0;j<sizeof(cmds);j++)
                command(cmds[j]);
        cart=new("/d/lingtai/obj/cart");
        cart->move(environment());
        message_vision("药材车隆隆驶了过来。\n",this_object());
                        
       /* if (way[i]["delay_time"] < 1 )
        {
                give_reward();
                return;
        }*/
 //       call_out("go",way[i]["delay_time"]);
        call_out("go", 1 );
        return;
}       
void be_protect()
{
        int i,j,flag;
        object *inv,*enemy;
        
        inv=all_inventory(environment());
        enemy=query_enemy();
// if one of the protectors wants to kill... then heis out of the loop
        for(j=0;j<sizeof(enemy);j++)
                enemy[j]->delete_temp("protecting");

        for (i=0;i<sizeof(inv);i++)
                if (objectp(cart) && inv[i]->query_temp("protecting")==cart)
                {
                        flag=1;
                        for(j=0;j<sizeof(enemy);j++)
                        {
                                inv[i]->kill_ob(enemy[j]);
                                enemy[j]->kill_ob(inv[i]);
                        }
            }
        if(!flag) return;
        message_vision("$N喊道：“你赶快挡住！”\n",this_object());
        
}        
void get_quest(string file)
{   
        way=read_table(file);
}
void to_rob()
{
        int i;
        object robber;
        
        message_vision("忽然间跳出一群劫匪！\n",this_object());
        for (i=0;i<=random(5)+1;i++)
        {
                robber=new(__DIR__"jiefei");
                robber->move(environment());
                robber->kill_ob(this_object());
                this_object()->kill_ob(robber);
                robber->set_leader(this_object());
        }
        be_protect();
        
}
        
mapping *read_table(string file)
{
        string *line, *field, *format;
        mapping *data;
        int i, rn, fn;

        line = explode(read_file(file), "\n");
        data = ({});
        for(i=0; i<sizeof(line); i++) {
                if( line[i]=="" || line[i][0]=='#' ) continue;
                if( !pointerp(field) ) {
                        field = explode( line[i], ":" );
                        continue;
                }
                if( !pointerp(format) ) {
                        format = explode( line[i], ":" );
                        continue;
                }
                break;
        }

        for( rn = 0, fn = 0; i<sizeof(line); i++) {
                if( line[i]=="" || line[i][0]=='#' ) continue;
                if( !fn ) data += ({ allocate_mapping(sizeof(field)) });
                sscanf( line[i], format[fn], data[rn][field[fn]] );
                fn = (++fn) % sizeof(field);
                if( !fn ) ++rn;
        }
        return data;
}
void set_protector(object prot)
{       protector=prot; }
object query_protector()
{       return protector;       }

void set_cart(object dartcart)
{       cart=dartcart;  }
object query_cart()
{       return cart;    }

void die()
{
        object killer,where;
        object *inv,pro_team;
        int values;
        int i;
        
        values=0;
        killer=query_temp("last_damage_from");
        if (objectp(protector))
        {
             protector->add("faith",-5);
             protector->save();
             tell_object(protector,"天空传来了云阳真人的怒斥：\n");
             tell_object(protector,"连这一点事情都办不好，一堆废物！\n");
        }
        
        if (objectp(killer))
        {
                command("chat 药材被"+killer->query("name")+"抢走了！");
                message_vision(killer->query("name")+"打开药材车，搬走了其中的药材！\n");
                inv=all_inventory(cart);
                for(i=0;i<sizeof(inv);i++)
                {
                        if (userp(killer))
                        {
                                inv[i]->move(killer);
                        }
                        else
                                destruct(inv[i]);
                }
                destruct(cart);
                where=environment(killer);
                while(killer=present("mengmian dahan",where))destruct(killer);
        }
        
        ::die();
}
void give_reward()
{   
        object *inv,pro_team;
        int i,reward;

        reward=6000+random(4000);
        if (objectp(protector)) 
        {
                pro_team=protector;
                pro_team->add("faith",10);
                pro_team->add("combat_exp",reward);
                pro_team->add("potential",reward/3);
                pro_team->save();
                tell_object(pro_team,"空中传来了云阳真人的话语：好样的，不愧为方寸门下弟子。\n");
        }
                
        destruct(cart);
        inv=all_inventory(environment());

        for (i=0;i<sizeof(inv);i++)
                if (inv[i]->query_temp("protecting")==cart && !userp(inv[i]))
                        destruct(inv[i]);
        destruct(this_object());
        
        return;
}
