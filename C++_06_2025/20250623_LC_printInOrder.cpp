#include <functional>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <iostream>

using namespace std;

class Foo {
private:
    mutex mtx;
    condition_variable cv;
    int state;

public:
    Foo() : state(0) { }

    void first(function<void()> printFirst) {
        unique_lock<mutex> lock(mtx);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        state = 1;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this] { return state >= 1; });
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        state = 2;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this] { return state >= 2; });
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};

int main() {
    Foo foo;

    thread t1([&]() { foo.first([]() { cout << "first\n"; }); });
    thread t2([&]() { foo.second([]() { cout << "second\n"; }); });
    thread t3([&]() { foo.third([]() { cout << "third\n"; }); });

    t1.join();
    t2.join();
    t3.join();

    return 0;
}


