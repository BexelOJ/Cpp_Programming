#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <chrono>

using namespace std;

// Shared data structure: queue and mutex
std::queue<std::string> messageQueue;
std::mutex queueMutex;

// Producer thread function (adds messages to the queue)
void producer() {
    std::string messages[] = { "Message 1", "Message 2", "Message 3", "Message 4" };
    for (const auto& msg : messages) {
        std::this_thread::sleep_for(std::chrono::seconds(1));  // Simulate some work
        {
            std::lock_guard<std::mutex> lock(queueMutex);  // Lock the queue
            messageQueue.push(msg);  // Push message into the queue
        }
        std::cout << "Producer: " << msg << " added to the queue.\n";
    }
}

// Consumer thread function (reads messages from the queue)
void consumer() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(2));  // Simulate some work
        std::lock_guard<std::mutex> lock(queueMutex);  // Lock the queue
        if (!messageQueue.empty()) {
            std::string msg = messageQueue.front();
            messageQueue.pop();  // Consume the message
            std::cout << "Consumer: " << msg << " processed.\n";
        }
    }
}

int main() {
    std::thread producerThread(producer);  // Create producer thread
    std::thread consumerThread(consumer);  // Create consumer thread

    // Join the threads to ensure they finish before main exits
    producerThread.join();
    consumerThread.join();

    return 0;
}
