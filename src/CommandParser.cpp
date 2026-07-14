#include "CommandParser.h"

#include <algorithm>
#include <cctype>
#include <sstream>
#include <unordered_map>

namespace
{
    const std::unordered_map<std::string, CommandType> commandLookup =
    {
        {"SET", CommandType::Set},
        {"GET", CommandType::Get},
        {"DEL", CommandType::Del},
        {"EXISTS", CommandType::Exists},
        {"CLEAR", CommandType::Clear}
    };
}

Command CommandParser::parse(const std::string& input) const
{
    Command command;

    std::istringstream stream(input);
    std::string token;

    // Read command
    if (!(stream >> token))
    {
        return command;
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

    auto it = commandLookup.find(upperCommand);

    if (it != commandLookup.end())
    {
        return it->second;
    }

    return CommandType::Invalid;
}