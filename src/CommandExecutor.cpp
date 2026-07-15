#include "CommandExecutor.h"


CommandExecutor::CommandExecutor(RedisDB& database)
    : m_database(database)
{
}


CommandResult CommandExecutor::execute(
    const Command& command)
{
    switch (command.type)
    {
    case CommandType::Set:
        return executeSet(command);

    case CommandType::Get:
        return executeGet(command);

    case CommandType::Del:
        return executeDel(command);

    case CommandType::Exists:
        return executeExists(command);

    case CommandType::Clear:
        return executeClear(command);

    default:
        return invalidCommand();
    }
}


CommandResult CommandExecutor::executeSet(
    const Command& command)
{
    if (command.arguments.size() != 2)
        return CommandResult::error(
            "ERR wrong number of arguments for SET"
        );


    m_database.set(
        command.arguments[0],
        command.arguments[1]
    );


    return CommandResult::ok("OK");
}


CommandResult CommandExecutor::executeGet(
    const Command& command)
{
    if (command.arguments.size() != 1)
        return CommandResult::error(
            "ERR wrong number of arguments for GET"
        );


    auto value =
        m_database.get(command.arguments[0]);


    if (!value)
        return CommandResult::ok("(nil)");


    return CommandResult::ok(*value);
}


CommandResult CommandExecutor::executeDel(
    const Command& command)
{
    if (command.arguments.size() != 1)
        return CommandResult::error(
            "ERR wrong number of arguments for DEL"
        );


    bool removed =
        m_database.remove(command.arguments[0]);


    return CommandResult::ok(
        removed ? "1" : "0"
    );
}


CommandResult CommandExecutor::executeExists(
    const Command& command)
{
    if (command.arguments.size() != 1)
        return CommandResult::error(
            "ERR wrong number of arguments for EXISTS"
        );


    return CommandResult::ok(
        m_database.exists(command.arguments[0])
        ? "1"
        : "0"
    );
}


CommandResult CommandExecutor::executeClear(
    const Command& command)
{
    if (!command.arguments.empty())
        return CommandResult::error(
            "ERR CLEAR takes no arguments"
        );


    m_database.clear();

    return CommandResult::ok("OK");
}


CommandResult CommandExecutor::invalidCommand()
{
    return CommandResult::error(
        "ERR unknown command"
    );
}