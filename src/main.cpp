#include <iostream>
#include <string>

#include "RedisDB.h"
#include "CommandParser.h"
#include "CommandExecutor.h"


int main()
{
    RedisDB database;

    CommandParser parser;

    CommandExecutor executor(database);


    std::cout << "=================================\n";
    std::cout << "        Mini Redis Server\n";
    std::cout << "=================================\n";
    std::cout << "Supported commands:\n";
    std::cout << "SET key value\n";
    std::cout << "GET key\n";
    std::cout << "DEL key\n";
    std::cout << "EXISTS key\n";
    std::cout << "CLEAR\n";
    std::cout << "Type 'exit' to quit\n\n";


    while (true)
    {
        std::cout << "MiniRedis> ";


        std::string input;

        std::getline(
            std::cin,
            input
        );


        // Handle Ctrl+D / EOF
        if (!std::cin)
        {
            break;
        }


        // Ignore empty input
        if (input.empty())
        {
            continue;
        }


        // CLI-only command
        if (input == "exit" ||
            input == "EXIT" ||
            input == "quit")
        {
            break;
        }


        Command command =
            parser.parse(input);


        CommandResult result =
            executor.execute(command);


        if (result.success)
        {
            std::cout
                << result.message
                << "\n";
        }
        else
        {
            std::cout
                << result.message
                << "\n";
        }
    }


    std::cout << "\nShutting down Mini Redis...\n";


    return 0;
}