#include <iostream>
#include <vector>

using namespace std;

class Resource {
private:
    vector<int> *data;
    string name;

public:
    // Regular constructor
    Resource(const string& n, int size) : name(n) {
        data = new vector<int>(size, 42);
        cout << "Constructor called for " << name << endl;
    }

    // Copy constructor
    Resource(const Resource& other) : name(other.name + "_copy") {
        data = new vector<int>(*other.data);
        cout << "Copy constructor called for " << name << endl;
    }

    // Move constructor
    Resource(Resource&& other) noexcept : name(move(other.name)), data(other.data) {
        other.data = nullptr;
        cout << "Move constructor called for " << name << endl;
    }

    // Move assignment operator
    Resource& operator=(Resource&& other) noexcept {
        if (this != &other) {
            cout << "Move assignment called for " << name << endl;

            // Clean up current resources
            delete data;

            // Steal resources
            name = move(other.name);
            data = other.data;
            other.data = nullptr;
        }
        return *this;
    }

    // Copy assignment operator
    Resource& operator=(const Resource& other) {
        if (this != &other) {
            cout << "Copy assignment called for " << name << endl;
            delete data;
            data = new vector<int>(*other.data);
            name = other.name + "_copy";
        }
        return *this;
    }

    ~Resource() {
        delete data;
        cout << "Destructor called for " << name << endl;
    }

    void display() const {
        if (data) {
            cout << name << ": size=" << data->size() << endl;
        }
        else {
            cout << name << ": empty (moved from)" << endl;
        }
    }
};

Resource createResource() {
    Resource temp("created", 10);
    return temp;  // Move constructor or RVO
}

int main() {
    cout << "=== 1. Regular construction ===" << endl;
    Resource r1("r1", 5);
    r1.display();

    cout << "\n=== 2. Copy construction ===" << endl;
    Resource r2 = r1;  // Copy constructor
    r2.display();

    cout << "\n=== 3. Move construction ===" << endl;
    Resource r3 = Resource("temp", 3);  // Temporary object
    Resource r4 = move(r3);  // Move constructor
    r4.display();

    cout << "\n=== 4. Move assignment ===" << endl;
    Resource r5("r5", 2);
    r5 = Resource("temp2", 4);  // Move assignment
    r5.display();

    cout << "\n=== 5. Return value optimization ===" << endl;
    Resource r6 = createResource();
    r6.display();

    return 0;
}


