#include <iostream>

struct Data {
    int x = 42;
    int y = 100;

    void print() const {
        std::cout << "Data: x=" << x << ", y=" << y << std::endl;
    }
};

class SmartPtr {
private:
    Data* ptr;

public:
    SmartPtr(Data* p = nullptr) : ptr(p) {}

    // Data member pointers only: return reference
    template<typename T>
    T& operator->*(T Data::* member) {
        return (ptr->*member);
    }

    template<typename T>
    const T& operator->*(T Data::* member) const {
        return (ptr->*member);
    }

    // Member function pointers: return proxy object
    template<typename Ret, typename... Args>
    auto operator->*(Ret(Data::* mem)(Args...)) -> decltype((ptr->*mem)()) {
        return (ptr->*mem)();
    }

    template<typename Ret, typename... Args>
    auto operator->*(Ret(Data::* mem)(Args...) const) const -> decltype((ptr->*mem)()) {
        return (ptr->*mem)();
    }
};

int main() {
    Data obj;
    SmartPtr sp(&obj);

    // Data members work
    int Data::* pmx = &Data::x;
    std::cout << "x: " << sp->*pmx << std::endl;  // 42
    sp->*pmx = 99;
    std::cout << "Modified x: " << sp->*pmx << std::endl;  // 99

    // Member function works
    void (Data:: * print_ptr)() const = &Data::print;
    sp->*print_ptr;  // Calls print()

    return 0;
}


/*
OUTPUT:

x: 42
Modified x: 99
Data: x=99, y=100

*/

