
mapping* quests=({    
        (["quest_type" : "sweep", "location" : "小院",]),
        (["quest_type" : "sweep", "location" : "正院",]),
        (["quest_type" : "sweep", "location" : "后院",]),
        (["quest_type" : "sweep", "location" : "厢房",]),
        (["quest_type" : "sweep", "location" : "练功室",]),
        (["quest_type" : "sweep", "location" : "卧室",]),
        (["quest_type" : "sweep", "location" : "讲经堂",]),
        (["quest_type" : "sweep", "location" : "厨房",]),
        (["quest_type" : "sweep", "location" : "经阁",]),
        (["quest_type" : "sweep", "location" : "小室",]),
        (["quest_type" : "write",]),
        (["quest_type" : "carry",]),
        (["quest_type" : "dig",]),
  });
  
void create()
{
        seteuid(getuid());
}

mapping query_quest()
{
        return quests[random(sizeof(quests))];
}
