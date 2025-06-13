#include <iostream>
#include <memory>
using namespace std;

struct A {
    void say_hello() { cout << "Hello from A\n"; }
};

int main() {
    shared_ptr<A> sp = make_shared<A>();
    shared_ptr<A> sp2 = sp;  // shared ownership
    cout << "Reference count: " << sp.use_count() << endl;
    weak_ptr<A> wp = sp;  // weak reference

    cout << "Reference count: " << sp.use_count() << endl;

    if (auto spt = wp.lock()) {  // safe to access
        spt->say_hello();
        cout << "Reference count: " << sp.use_count() << endl;
    }

    cout << "Reference count: " << sp2.use_count() << endl;
    sp.reset();  // destroy object
    cout << "Reference count: " << sp2.use_count() << endl;
    sp2.reset();
    cout << "Reference count: " << sp2.use_count() << endl;

    if (wp.expired()) {
        cout << "Object no longer exists.\n";
    }

    return 0;
}

