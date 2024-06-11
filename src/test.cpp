#include "getdata.cpp"

bool storeDataToRedis(redisConnPool *pool, string key, string value){
    // redisConn *conn = new redisConn();
    shared_ptr<redisConn> conn = pool->getRedisConn();
    return conn->set(key,value);
}

string getDataFromRedis(redisConnPool *pool, string key){
    shared_ptr<redisConn> conn = pool->getRedisConn();
     // 从 Redis 中检索 JSON 数据
    return conn->get(key);

}


void test(){
#if 1
    string data = getQuestionnaireData();
    std::cout << data << std::endl;
#else
    redisConnPool *pool = redisConnPool::getRedisConnPool();
    shared_ptr<redisConn> conn = pool->getRedisConn();
    string infos = R"([{"description":"ask students some infos","fields":"["name", "gender","advice"]","id":"1","type":"ask"}])";
    // conn->del("infos");
    std::cout << conn->set("infos", infos) << std::endl;
    // getDataFromRedis();
    std::cout <<  conn->get("infos") << std::endl;
#endif
}
int main(){
    test();
    return 0;
}