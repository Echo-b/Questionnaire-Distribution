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