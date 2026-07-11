#include <iostream>

#include "RedisDB.h"

int main()
{
    RedisDB db;

    // Insert some key-value pairs
    db.set("name", "Mehnaz");
    db.set("language", "C++");
    db.set("project", "MiniRedis");

    // Retrieve and print values
    std::cout << "name: " << db.get("name") << '\n';
    std::cout << "language: " << db.get("language") << '\n';
    std::cout << "project: " << db.get("project") << '\n';

    // Check if a key exists
    std::cout << "\nChecking if 'name' exists: "
        << (db.exists("name") ? "Yes" : "No") << '\n';

    std::cout << "Checking if 'age' exists: "
        << (db.exists("age") ? "Yes" : "No") << '\n';

    return 0;
}