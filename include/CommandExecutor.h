#pragma once

#include "Command.h"
#include "CommandResult.h"
#include "RedisDB.h"

class CommandExecutor
{
public:

    explicit CommandExecutor(RedisDB& database);

    CommandResult execute(const Command& command);

private:

    CommandResult executeSet(
        const Command& command
    );

    CommandResult executeGet(
        const Command& command
    );

    CommandResult executeDel(
        const Command& command
    );

    CommandResult executeExists(
        const Command& command
    );

    CommandResult executeClear(
        const Command& command
    );

    CommandResult invalidCommand();

private:

    RedisDB& m_database;
};