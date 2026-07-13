#pragma once

#include <string>
#include <unordered_map>

struct Entry
{
    std::string value;
};

class RedisDB
{
public:

    RedisDB() = default;
    ~RedisDB() = default;

    // Disable copy for now
    RedisDB(const RedisDB&) = delete;
    RedisDB& operator=(const RedisDB&) = delete;

    // Allow move
    RedisDB(RedisDB&&) = default;
    RedisDB& operator=(RedisDB&&) = default;

public:

    void set(const std::string& key,
        const std::string& value);

    std::string get(const std::string& key) const;

    bool exists(const std::string& key) const;

    bool remove(const std::string& key);

    void clear();

    std::size_t size() const;

    bool empty() const;

private:

    std::unordered_map<std::string, Entry> m_database;
};