#pragma once

#include <string>

#include "Command.h"

class CommandParser
{
public:

    CommandParser() = default;
    ~CommandParser() = default;

    Command parse(const std::string& input) const;

private:

    CommandType parseCommandType(const std::string& command) const;
};