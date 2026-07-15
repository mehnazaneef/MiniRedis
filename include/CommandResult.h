#pragma once

#include <string>

struct CommandResult
{
    bool success;
    std::string message;

    CommandResult(bool success,
        std::string message)
        : success(success),
        message(std::move(message))
    {
    }

    static CommandResult ok(std::string message)
    {
        return CommandResult(
            true,
            std::move(message)
        );
    }

    static CommandResult error(std::string message)
    {
        return CommandResult(
            false,
            std::move(message)
        );
    }
};