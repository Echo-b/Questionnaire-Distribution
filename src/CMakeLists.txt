cmake_minimum_required(VERSION 3.15)
project(Questionaire)

set(CMAKE_CXX_STANDARD 11)
# aux_source_directory(${PROJECT_SOURCE_DIR} SRC)

# file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

file(GLOB SRC ${PROJECT_SOURCE_DIR}/*.cpp)

# 排除不需要的文件
list(REMOVE_ITEM SRC 
    "${PROJECT_SOURCE_DIR}/client.cpp"
    "${PROJECT_SOURCE_DIR}/test.cpp"
)

find_package(jsoncpp REQUIRED)

find_path(HIREDIS_INCLUDE_DIR hiredis/hiredis.h)
find_library(HIREDIS_LIBRARIES hiredis)

set(MYSQL_INCLUDE_DIR "/usr/include/mysql") 
set(MYSQL_LIBRARIES "/usr/lib/x86_64-linux-gnu/libmysqlclient.so")  


add_executable(server ${SRC})

add_executable(client client.cpp)

target_link_libraries(server jsoncpp ${MYSQL_LIBRARIES} ${HIREDIS_LIBRARIES})
target_link_libraries(client jsoncpp)

