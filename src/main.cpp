#include <iostream>

#include "RedisDB.h"
#include "CommandParser.h"
#include "CommandExecutor.h"

int main()
{
    RedisDB db;

    CommandParser parser;

    CommandExecutor executor(db);


    auto command =
        parser.parse(
            "SET name Mehnaz"
        );


    auto result =
        executor.execute(command);


    std::cout << result.message;

    return 0;
}