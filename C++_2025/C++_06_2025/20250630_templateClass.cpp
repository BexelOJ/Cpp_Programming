#include <iostream>
using namespace std;

// Template class for a simple pair
template <class T1, class T2>
class MyPair {
    T1 first;
    T2 second;
public:
    MyPair(T1 a, T2 b) : first(a), second(b) {}

    void display() {
        cout << "First: " << first << ", Second: " << second << endl;
    }
};

int main() {
    MyPair<int, double> p1(10, 15.5);
    MyPair<string, int> p2("Age", 30);

    p1.display();
    p2.display();

    return 0;
}

