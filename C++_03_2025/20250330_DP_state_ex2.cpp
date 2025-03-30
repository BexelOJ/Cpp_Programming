// Step 1: Define the State Interface
#include <iostream>
#include <string>

// Forward declaration of Context class
class Context;

// State interface: Abstract class for states
class State {
public:
    virtual void open(Context* context) = 0;
    virtual void close(Context* context) = 0;
    virtual void sendData(Context* context, const std::string& data) = 0;
    virtual ~State() = default;
};


// Step 2: Define the Concrete States
// ConcreteState: Closed
class ConcreteStateClosed : public State {
public:
    void open(Context* context) override;
    void close(Context* context) override {
        std::cout << "Connection is already closed." << std::endl;
    }
    void sendData(Context* context, const std::string& data) override {
        std::cout << "Cannot send data. The connection is closed." << std::endl;
    }
};

// ConcreteStateOpen
// ConcreteState: Open
class ConcreteStateOpen : public State {
public:
    void open(Context* context) override {
        std::cout << "Connection is already open." << std::endl;
    }
    void close(Context* context) override;
    void sendData(Context* context, const std::string& data) override {
        std::cout << "Sending data: " << data << std::endl;
    }
};


// ConcreteState: Opening
class ConcreteStateOpening : public State {
public:
    void open(Context* context) override {
        std::cout << "Connection is opening..." << std::endl;
    }
    void close(Context* context) override {
        std::cout << "Cannot close, connection is in opening state." << std::endl;
    }
    void sendData(Context* context, const std::string& data) override {
        std::cout << "Cannot send data, connection is opening." << std::endl;
    }
};


// Step 3: Define the Context Class
// Context class: TCPConnection
class Context {
private:
    State* currentState;

public:
    Context(State* initialState) : currentState(initialState) {}

    void setState(State* newState) {
        currentState = newState;
    }

    void open() {
        currentState->open(this);
    }

    void close() {
        currentState->close(this);
    }

    void sendData(const std::string& data) {
        currentState->sendData(this, data);
    }
};


// Step 4: Implement State Transitions
void ConcreteStateClosed::open(Context* context) {
    std::cout << "Opening connection..." << std::endl;
    context->setState(new ConcreteStateOpening());  // Transition to Opening state
}

void ConcreteStateOpen::close(Context* context) {
    std::cout << "Closing connection..." << std::endl;
    context->setState(new ConcreteStateClosed());  // Transition to Closed state
}

// Step 5: Client Code
int main() {
    // Initial state: Closed
    ConcreteStateClosed* closedState = new ConcreteStateClosed();
    Context* connection = new Context(closedState);

    // Attempt to open the connection (will transition to Opening state)
    connection->open();

    // Now the connection is opening, so we try to send data
    connection->sendData("Hello, world!");

    // Attempt to open again (connection is already opening)
    connection->open();

    // Transition to Open state after some logic
    connection->setState(new ConcreteStateOpen());

    // Now the connection is open, send data successfully
    connection->sendData("Hello, world!");

    // Close the connection (transition to Closed state)
    connection->close();

    return 0;
}

/*
OUTPUT:

Opening connection...
Connection is opening...
Cannot send data, connection is opening.
Connection is already open.
Sending data: Hello, world!
Closing connection...

*/
