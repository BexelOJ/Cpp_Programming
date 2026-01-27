#include <iostream>
#include <csignal>
#include <unistd.h>

volatile bool interruptFlag = false;

// ISR handler
void handle_interrupt(int sig) {
    interruptFlag = true; // Set the interrupt flag
    std::cout << "\nInterrupt received! ISR executed\n";
}

int main() {
    // Register the ISR (signal handler)
    signal(SIGINT, handle_interrupt);
    int count = 0;
    std::cout << "Program running... Press Ctrl+C to trigger interrupt\n";

    while (true && (count < 5)) {
        // Main program logic
        if (interruptFlag) {
            std::cout << "Handling interrupt logic in main program\n";
            interruptFlag = false; // Reset the interrupt flag
            count++;
            if (count == 5) {
                std::cout << "Exiting Execution in next" << std::endl;
            }
        }
        // Simulate some other work (sleeping)
        sleep(1);
    }

    return 0;
}

/*
OUTPUT:
Program running... Press Ctrl+C to trigger interrupt
^C
Interrupt received! ISR executed
Handling interrupt logic in main program
^C
Interrupt received! ISR executed
Handling interrupt logic in main program
^C
Interrupt received! ISR executed
Handling interrupt logic in main program
^C
Interrupt received! ISR executed
Handling interrupt logic in main program
^C
Interrupt received! ISR executed
Handling interrupt logic in main program
Exiting Execution in next
^C
Interrupt received! ISR executed

*/

