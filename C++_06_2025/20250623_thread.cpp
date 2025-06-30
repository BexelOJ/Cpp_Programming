#include <iostream>
#include <thread>

using namespace std;

void task() {
    cout << "Running task" << endl;
}

int main() {
    thread t(task); // Create and start the thread
    //t.join();       // Wait for the thread to finish
    t.detach();
    return 0;
}






