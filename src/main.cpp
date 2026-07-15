#include <iostream>

#include "RedisDB.h"

int main()
{
    RedisDB db;

    db.set("name", "Mehnaz");
    db.set("language", "C++");

    auto value = db.get("name");

    if (value.has_value())
    {
        std::cout << "name = " << *value << '\n';
    }
    else
    {
        std::cout << "Key not found\n";
    }

    auto missing = db.get("salary");

    if (missing)
    {
        std::cout << *missing << '\n';
    }
    else
    {
        std::cout << "salary does not exist\n";
    }

    return 0;
}