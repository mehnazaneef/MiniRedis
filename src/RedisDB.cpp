#include "RedisDB.h"

void RedisDB::set(const std::string& key, const std::string& value) {
	database[key] = value;
}

std::string RedisDB::get(const std::string& key) {
	return database[key];
}

bool RedisDB::exists(const std::string& key) {
	return database.find(key) != database.end();
}