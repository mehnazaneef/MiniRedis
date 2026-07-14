#include "CommandParser.h"

#include <algorithm>
#include <cctype>
#include <sstream>

Command CommandParser::parse(const std::string& input) const
{
    Command command;

    std::istringstream stream(input);

    std::string token;

    // Read the command name
    if (!(stream >> token))
    {
        return command; // Invalid (default)
    }

    command.type = parseCommandType(token);

    // Read remaining arguments
    while (stream >> token)
    {
        command.arguments.push_back(token);
    }

    return command;
}

CommandType CommandParser::parseCommandType(const std::string& command) const
{
    std::string upperCommand = command;

    std::transform(
        upperCommand.begin(),
        upperCommand.end(),
        upperCommand.begin(),
        [](unsigned char c)
        {
            return static_cast<char>(std::toupper(c));
        });

    if (upperCommand == "SET")
    {
        return CommandType::Set;
    }

    if (upperCommand == "GET")
    {
        return CommandType::Get;
    }

    if (upperCommand == "DEL")
    {
        return CommandType::Del;
    }

    if (upperCommand == "EXISTS")
    {
        return CommandType::Exists;
    }

    if (upperCommand == "CLEAR")
    {
        return CommandType::Clear;
    }

    return CommandType::Invalid;
}