#include <iostream>
#include <csignal>
#include <unistd.h>

volatile bool interruptFlag = false;

// ISR handler
void handle_interrupt(int sig) {
    interruptFlag = true; // Set the interrupt flag
    std::cout << "\nInterrupt received! ISR executed.\n";
}

int main() {
    // Register the ISR (signal handler)
    signal(SIGINT, handle_interrupt);

    std::cout << "Program running... Press Ctrl+C to trigger interrupt.\n";

    while (true) {
        // Main program logic
        if (interruptFlag) {
            std::cout << "Handling interrupt logic in main program.\n";
            interruptFlag = false; // Reset the interrupt flag
        }
        // Simulate some other work (sleeping)
        sleep(1);
    }

    return 0;
}

