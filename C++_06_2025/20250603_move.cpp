#include <iostream>
#include <cstring>

class MyString {
    char* data;

public:
    // Constructor
    MyString(const char* str) {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
        std::cout << "Constructor\n";
    }

    // Destructor
    ~MyString() {
        delete[] data;
    }

    // Copy Constructor
    MyString(const MyString& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
        std::cout << "Copy Constructor\n";
    }

    // Move Constructor
    MyString(MyString&& other) noexcept {
        data = other.data;
        other.data = nullptr;
        std::cout << "Move Constructor\n";
    }

    // Move Assignment
    MyString& operator=(MyString&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            other.data = nullptr;
        }
        std::cout << "Move Assignment\n";
        return *this;
    }

    void show() const {
        std::cout << "Data: " << (data ? data : "null") << "\n";
    }
};

int main() {
    MyString a("Hello");
    a.show();
    MyString b = std::move(a);  // Move Constructor
    b.show();
    MyString c;
    c = std::move(b);  // Move Assignment
    b.show();
    a.show();  // Now 'a' is in a "moved-from" state
}

