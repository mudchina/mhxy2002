// By tianlin@MHXY. 2001.5.8 
// name.c

#include <ansi.h>
#include <dbase.h>

static string *my_id;

string *query_my_id()
{
  return my_id;
}

void set_name(string name, string *id)
{
  set("name", name);
  set("id", id[0]);
  my_id = id;
}

int id(string str)
{
  string *applied_id;

  if( this_player() && !this_player()->visible(this_object()) ) return 0;

  if( pointerp(applied_id = query_temp("apply/id")) 
  &&  sizeof(applied_id) ) 
   if( member_array(str, applied_id)!=-1 )
    return 1;
   else
    return 0;
    
  // If apply/id exists, this object is "pretending" something, don't
  // recognize original id to prevent breaking the pretending with "id"
  // command.

  if( pointerp(my_id) && member_array(str, my_id)!=-1 )
   return 1;
  else
   return 0;
}

string *parse_command_id_list()
{
  string *applied_id;

  if( pointerp(applied_id = query_temp("apply/id")) 
  &&  sizeof(applied_id) )
   return applied_id;
  else
   return my_id;
}

varargs string name(int raw)
{
  string str, *mask;
  
  if( !raw && sizeof(mask = query_temp("apply/name")) )
   return mask[sizeof(mask)-1];
  else {
   if( stringp(str = query("name")) )
    return str;
   else
    return file_name(this_object());
  }
}

varargs string short(int raw)
{
  int i;
  string title, nick, job_title, xuewei, str, *mask;
//add by bear
string drgree,guard,bang_name;
  
  if( !stringp(str = query("short")) )
   str = name(raw) + "(" + capitalize(query("id")) + ")";

  if( !this_object()->is_character() ) return str;
  if (!raw) {
	if ((int)query_temp("pending/exercising") != 0)
			return HIY+name() + "盘膝而坐,正在修炼内力。"NOR;
	else if ((int)query_temp("pending/meditating") != 0)
			return HIC+name() + "两眼微闭,盘膝而坐,正在冥思修炼法力."NOR;
     }

  if( !raw && sizeof(mask = query_temp("apply/short")) )
   str = (string)mask[sizeof(mask)-1];
  else {
   if( stringp(nick = query("nickname")) )
    str = sprintf("「%s」%s", nick, str);

        if( !raw && sizeof(mask = query_temp("apply/title")) )
            title = (string)mask[sizeof(mask)-1];
        else
          title = query("title");
   if( stringp(title) )
    str = sprintf("%s%s%s", title,(nick?"":" "), str);

                if( stringp(job_title = query("job_title")) )
                        str = sprintf("%s %s",job_title, str); 
//add by tianlin@Mhxy for 2002.3.6 join
                if( stringp(xuewei = query("xuewei")) )
                        str = sprintf("%s %s",xuewei, str); 
// add by bear
    if (stringp(bang_name=query("bang/name")))
     {
	if (stringp(drgree=query("bang/degree")))
	  bang_name=bang_name+drgree;
	bang_name=HIC+bang_name+NOR;
        str = sprintf("%s%s%s%s",bang_name,(title?"":""),(nick?"":""),str);
     }
    if(stringp(guard=query("guard")))
    str = sprintf("%s%s%s%s%s",guard,(bang_name?"":""),(title?"":""),
    (nick?"":""),str);

  }

  if( !raw ) {
   if( this_object()->is_ghost() ) str = HIB "(鬼气) " NOR + str;
   if( this_object()->is_fighting() ) str += HIR " <战斗中>" NOR;
   if( this_object()->query("thief") ) str += HIC " <梦幻西游大盗>" NOR;
   if( query_temp("doing_xiudao") ) str += HIY " <修道中>" NOR;
   if( this_object()->query("PKS")>0 ) str += HIR " <杀人犯>"NOR;
   if( query_temp("netdead") ) str += HIG " <断线中>" NOR;
   if( in_input() ) str += HIC " <输入文字中>" NOR;
   if( in_edit() ) str += HIY " <编辑档案中>" NOR;
   if( interactive(this_object())
		&&	query_idle( this_object() ) > 180 &&!query_temp("ext_info") )
		{
			 this_object()->improve_skill("idle-force",1);
			 str +=HIM"<发呆"+ chinese_number(query_idle(this_object())/60) + "分钟>" NOR;
		}
   if( this_object()->query("env/invisibility") ) str += HIC"<隐身中>"NOR;
   //	if ( this_object()->is_busy() ) str += HIG " < busy 中 >" NOR;
   if( !living(this_object()) ) str += HIR + query("disable_type") + NOR;
  }

  return str;
}

varargs string long(int raw)
{
  string str, extra, *mask;
  
  if( !raw && sizeof(mask = query_temp("apply/long")) )
   str = mask[sizeof(mask)-1];
  else if( !stringp(str = query("long")) )
   str = short(raw) + "。\n";

  if( stringp(extra = this_object()->extra_long()) )
   str += extra;

  return str;
}

