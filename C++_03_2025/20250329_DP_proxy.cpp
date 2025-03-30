// Step 1: Define the Subject Interface
#include <iostream>
#include <string>

// Subject Interface
class Database {
public:
    virtual void queryDatabase(const std::string& query) = 0;
    virtual ~Database() = default;
};


// Step 2: Define the RealSubject Class
class RealDatabase : public Database {
private:
    std::string name;

public:
    RealDatabase(const std::string& dbName) : name(dbName) {
        std::cout << "Connecting to the database: " << name << std::endl;
    }

    void queryDatabase(const std::string& query) override {
        std::cout << "Querying database (" << name << "): " << query << std::endl;
    }

    ~RealDatabase() {
        std::cout << "Disconnecting from the database: " << name << std::endl;
    }
};

// 

//
