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

// Step 3: Define the Proxy Class
class DatabaseProxy : public Database {
private:
    RealDatabase* realDatabase; // The real object (lazy initialized)
    std::string dbName;

public:
    DatabaseProxy(const std::string& dbName) : dbName(dbName), realDatabase(nullptr) {}

    // Initialize the real object only when needed (Lazy initialization)
    void queryDatabase(const std::string& query) override {
        if (realDatabase == nullptr) {
            realDatabase = new RealDatabase(dbName); // Lazy initialization
        }
        std::cout << "Proxy: Logging the query before delegation." << std::endl;
        realDatabase->queryDatabase(query); // Delegate to the real object
    }

    ~DatabaseProxy() {
        if (realDatabase != nullptr) {
            delete realDatabase;
        }
    }
};


// Step 4: Client Code
int main() {
    // Create a proxy for the "MyDB" database
    Database* dbProxy = new DatabaseProxy("MyDB");

    // Query the database through the proxy
    dbProxy->queryDatabase("SELECT * FROM users;");
    dbProxy->queryDatabase("INSERT INTO users (name) VALUES ('Alice');");

    delete dbProxy; // The real database will be disconnected when the proxy is deleted

    return 0;
}



/*
OUTPUT:

Connecting to the database: MyDB
Proxy: Logging the query before delegation.
Querying database (MyDB): SELECT * FROM users;
Proxy: Logging the query before delegation.
Querying database (MyDB): INSERT INTO users (name) VALUES ('Alice');
Disconnecting from the database: MyDB

*/