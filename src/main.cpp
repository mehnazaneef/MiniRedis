#include <iostream>

#include "CommandParser.h"

int main()
{
    CommandParser parser;

    while (true)
    {
        std::cout << "> ";

        std::string input;
        std::getline(std::cin, input);

        Command command = parser.parse(input);

        std::cout << "Command Type: ";

        switch (command.type)
        {
        case CommandType::Set:
            std::cout << "SET";
            break;

        case CommandType::Get:
            std::cout << "GET";
            break;

        case CommandType::Del:
            std::cout << "DEL";
            break;

        case CommandType::Exists:
            std::cout << "EXISTS";
            break;

        case CommandType::Clear:
            std::cout << "CLEAR";
            break;

        default:
            std::cout << "INVALID";
            break;
        }

        std::cout << "\nArguments:\n";

        for (const auto& argument : command.arguments)
        {
            std::cout << "  - " << argument << '\n';
        }

        std::cout << '\n';
    }

    return 0;
}