#pragma once

#include <vector>
#include <string>

enum class CommandType {
	Set,
	Get,
	Del,
	Exists,
	Clear,
	Invalid
};

struct Command
{
	CommandType type = CommandType::Invalid;
	std::vector<std::string> arguments;
};