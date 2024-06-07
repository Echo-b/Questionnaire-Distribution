#include "redisConnPool.h"

redisConnPool::redisConnPool()
{
    for (int i = 0; i < r_minSize; ++i)
    {
        redisConn *conn = new redisConn;
        r_redisConnQ.push(conn);
    }
}

redisConnPool::~redisConnPool()
{
    while (!r_redisConnQ.empty())
    {
        redisConn *conn = r_redisConnQ.front();
        r_redisConnQ.pop();
        delete conn;
    }
}

redisConnPool *redisConnPool::getRedisConnPool()
{
    static redisConnPool r_pool;
    return &r_pool;
}

shared_ptr<redisConn> redisConnPool::getRedisConn()
{
}

bool redisConnPool::parseJsonFile()
{
    ifstream ifs("reconf.json");
    Json::Reader rd;
    Json::Value root;
    rd.parse(ifs,root);
    if(root.isObject()){
        ip = root["ip"].asString();
        port = root["port"].asUInt();
        r_maxSize;
        r_minSize;
        r_timeout;
        r_maxIdleTime;

    }
    
}

void redisConnPool::produceConn()
{
}

void redisConnPool::recycleConn()
{
}

void redisConnPool::createConn()
{
    redisConn *conn = new redisConn();
    conn->connect(ip, port);
    conn->refreshAliveTime();
    r_redisConnQ.push(conn);
}