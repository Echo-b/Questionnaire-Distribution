#include "mysqlConnPool.h"
#include "mysqlConnPool.cpp"
#include "redisConnPool.h"
#include "redisConnPool.cpp"


string loadDataFromMysql(){
    mysqlConnPool* pool = mysqlConnPool::getmysqlConnPool();
    shared_ptr<mysqlConn> conn = pool->getMysqlConn();
    string sql = "select * from infos";
    bool flag = conn->query(sql);
    cout << flag << endl;

    Json::Value root;
    Json::FastWriter writer;
    Json::Value infos;
    // Json::Value fields;

    while(conn->next()){
        infos["id"] = conn->getvalue(0);
        infos["type"] = conn->getvalue(1);
        infos["description"] = conn->getvalue(2);
        infos["fields"] = conn->getvalue(3);
    }
    root.append(infos);
    string str = writer.write(root);
    return str;
}

bool storeDataToRedis(redisConnPool *pool, string key, string value){
    // redisConn *conn = new redisConn();
    shared_ptr<redisConn> conn = pool->getRedisConn();
    return conn->set(key,value);
}

string getDataFromRedis(redisConnPool *pool, string key){
    shared_ptr<redisConn> conn = pool->getRedisConn();
    return conn->get(key); 
}

string getQuestionnaireData(){
     string infos = loadDataFromMysql();

    // store it to redis
    cout << infos << endl;
    redisConnPool *pool = redisConnPool::getRedisConnPool();
    storeDataToRedis(pool, "infos", infos);

    // get data from redis
    infos = getDataFromRedis(pool, "infos");
    cout << infos << endl;
    return infos;
}
