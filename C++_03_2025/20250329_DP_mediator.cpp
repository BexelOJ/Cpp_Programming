// Step 1: Define the Mediator Interface
#include <iostream>
#include <vector>
#include <string>

// Mediator Interface
class ChatMediator {
public:
    virtual void sendMessage(const std::string& message, const std::string& userName) = 0;
    virtual void addUser(class User* user) = 0;
    virtual ~ChatMediator() = default;
};


// Step 2: Define the Colleague (User) Interface
// Colleague: User
class User {
protected:
    ChatMediator* mediator;
    std::string name;

public:
    User(ChatMediator* mediator, const std::string& name) : mediator(mediator), name(name) {}

    virtual void send(const std::string& message) = 0;
    virtual void receive(const std::string& message) = 0;
    virtual ~User() = default;
};


// Step 3: Define the Concrete Mediator (ChatRoom)
// Concrete Mediator: ChatRoom
class ChatRoom : public ChatMediator {
private:
    std::vector<User*> users;

public:
    void sendMessage(const std::string& message, const std::string& userName) override {
        for (User* user : users) {
            if (user->getName() != userName) {
                user->receive(message);
            }
        }
    }

    void addUser(User* user) override {
        users.push_back(user);
    }
};


// Step 4: Define Concrete Colleague (User Implementations)
// Concrete Colleague: UserA
class UserA : public User {
public:
    UserA(ChatMediator* mediator, const std::string& name) : User(mediator, name) {}

    void send(const std::string& message) override {
        std::cout << name << " sends message: " << message << std::endl;
        mediator->sendMessage(message, name);
    }

    void receive(const std::string& message) override {
        std::cout << name << " receives message: " << message << std::endl;
    }
};

// Concrete Colleague: UserB
class UserB : public User {
public:
    UserB(ChatMediator* mediator, const std::string& name) : User(mediator, name) {}

    void send(const std::string& message) override {
        std::cout << name << " sends message: " << message << std::endl;
        mediator->sendMessage(message, name);
    }

    void receive(const std::string& message) override {
        std::cout << name << " receives message: " << message << std::endl;
    }
};


// Step 5: Client Code
int main() {
    ChatMediator* chatRoom = new ChatRoom();

    User* user1 = new UserA(chatRoom, "Alice");
    User* user2 = new UserB(chatRoom, "Bob");

    chatRoom->addUser(user1);
    chatRoom->addUser(user2);

    user1->send("Hello, Bob!");
    user2->send("Hi, Alice! How are you?");

    delete user1;
    delete user2;
    delete chatRoom;

    return 0;
}


/*
OUTPUT:

Alice sends message: Hello, Bob!
Bob receives message: Hello, Bob!
Bob sends message: Hi, Alice! How are you?
Alice receives message: Hi, Alice! How are you?

*/