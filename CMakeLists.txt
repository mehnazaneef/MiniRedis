cmake_minimum_required(VERSION 3.20)

project(MiniRedis)

set(CMAKE_CXX_STANDARD 17)


include_directories(
    include
)


add_executable(
    MiniRedis

    src/main.cpp
    src/RedisDB.cpp
  "include/Command.h" "include/CommandParser.h" "src/CommandParser.cpp" "include/CommandResult.h" "include/CommandExecutor.h" "src/CommandExecutor.cpp")