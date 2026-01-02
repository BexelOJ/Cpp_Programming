// Step 1: Define the Handler Interface
#include <iostream>
#include <string>

// Abstract Handler
class SupportHandler {
protected:
    SupportHandler* nextHandler;  // The next handler in the chain

public:
    SupportHandler() : nextHandler(nullptr) {}

    // Set the next handler in the chain
    void setNextHandler(SupportHandler* handler) {
        nextHandler = handler;
    }

    // Abstract method to be implemented by concrete handlers
    virtual void handleRequest(const std::string& issue) = 0;
    
    virtual ~SupportHandler() = default;
};


// Step 2: Define Concrete Handlers
// Concrete Handler 1: Level1Support
class Level1Support : public SupportHandler {
public:
    void handleRequest(const std::string& issue) override {
        if (issue == "simple") {
            std::cout << "Level 1 support: Handling simple issue." << std::endl;
        } else if (nextHandler != nullptr) {
            std::cout << "Level 1 support: Escalating to Level 2." << std::endl;
            nextHandler->handleRequest(issue);  // Pass the request to the next handler
        }
    }
};

// Concrete Handler 2: Level2Support
class Level2Support : public SupportHandler {
public:
    void handleRequest(const std::string& issue) override {
        if (issue == "moderate") {
            std::cout << "Level 2 support: Handling moderate issue." << std::endl;
        } else if (nextHandler != nullptr) {
            std::cout << "Level 2 support: Escalating to Level 3." << std::endl;
            nextHandler->handleRequest(issue);  // Pass the request to the next handler
        }
    }
};

// Concrete Handler 3: Level3Support
class Level3Support : public SupportHandler {
public:
    void handleRequest(const std::string& issue) override {
        if (issue == "complex") {
            std::cout << "Level 3 support: Handling complex issue." << std::endl;
        } else {
            std::cout << "Level 3 support: Unable to handle issue. No further escalation possible." << std::endl;
        }
    }
};


// Step 3: Client Code
int main() {
    // Create handlers
    Level1Support* level1 = new Level1Support();
    Level2Support* level2 = new Level2Support();
    Level3Support* level3 = new Level3Support();

    // Set up the chain of responsibility
    level1->setNextHandler(level2);
    level2->setNextHandler(level3);

    // Client initiates requests
    std::cout << "Client: Requesting simple issue." << std::endl;
    level1->handleRequest("simple");  // Level 1 handles this

    std::cout << "\nClient: Requesting moderate issue." << std::endl;
    level1->handleRequest("moderate");  // Escalates to Level 2

    std::cout << "\nClient: Requesting complex issue." << std::endl;
    level1->handleRequest("complex");  // Escalates to Level 3

    // Clean up
    delete level1;
    delete level2;
    delete level3;

    return 0;
}


/*
OUTPUT:

Client: Requesting simple issue.
Level 1 support: Handling simple issue.

Client: Requesting moderate issue.
Level 1 support: Escalating to Level 2.
Level 2 support: Handling moderate issue.

Client: Requesting complex issue.
Level 1 support: Escalating to Level 2.
Level 2 support: Escalating to Level 3.
Level 3 support: Handling complex issue.

*/