#ifndef _REDISCONN_
#define _REDISCONN_

#include <hiredis/hiredis.h>
#include <iostream>
#include <string>
#include <memory>
#include <sstream>
using namespace std;

class redisConn
{
private:
    redisContext *r_redis = nullptr;

public:
    redisConn();
    bool connect(string ip, uint32_t port);
    string get(string key);
    string execute(string command);
    bool set(string key, string value);
    bool update(string key, string value);
    bool del(string key);
    void log(string info, string parm = "");
    string setCommand(string type, string key, string value = "");
    ~redisConn();
};

#endif