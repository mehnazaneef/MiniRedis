#include "RedisDB.h"

void RedisDB::set(const std::string& key,
    const std::string& value)
{
    m_database[key] = Entry{ value };
}

std::string RedisDB::get(const std::string& key) const
{
    auto it = m_database.find(key);

    if (it == m_database.end())
    {
        return "";
    }

    return it->second.value;
}

bool RedisDB::exists(const std::string& key) const
{
    return m_database.find(key) != m_database.end();
}

bool RedisDB::remove(const std::string& key)
{
    return m_database.erase(key) > 0;
}

void RedisDB::clear()
{
    m_database.clear();
}

std::size_t RedisDB::size() const
{
    return m_database.size();
}

bool RedisDB::empty() const
{
    return m_database.empty();
}