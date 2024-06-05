#ifndef _REDISCONNPOOL_
#define _REDISCONNPOOL_

#include <iostream>
#include <queue>
#include "redisConn.h"
#include "redisConn.cpp"
#include <thread>
#include <chrono>
#include <condition_variable>

class redisConnPool
{
private:
    std::queue<redisConn *> r_redisConnQ;
    int r_minSize;
    int r_maxSize;

private:
    redisConnPool();

public:
    static redisConnPool *getRedisConnPool();
    redisConnPool(const redisConnPool &obj) = delete;
    redisConnPool &operator=(const redisConnPool &obj) = delete;
    ~redisConnPool();
};

#endif