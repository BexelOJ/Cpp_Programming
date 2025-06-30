#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
using namespace std;

int counter = 0;           // Shared resource
mutex mtx;                // Mutex to protect it

void increment(int id) {
    for (int i = 0; i < 1000; ++i) {
        mtx.lock();       // 🔐 lock before modifying shared data
        ++counter;
        mtx.unlock();     // 🔓 unlock after done
    }
}

int main() {
    vector<thread> threads;

    // Launch 10 threads
    for (int i = 0; i < 10; ++i) {
        threads.push_back(thread(increment, i));
    }

    // Join all threads
    for (auto& t : threads) {
        t.join();
    }

    cout << "Final counter value: " << counter << endl;  // Should be 10000

    return 0;
}

