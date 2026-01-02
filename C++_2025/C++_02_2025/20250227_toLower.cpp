#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string input;
    
    // Ask for user input
    cout << "Enter a string: ";
    getline(cin, input);
    
    // Convert each character to lowercase
    for (int i = 0; i < input.length(); ++i) {
        input[i] = tolower(input[i]);
    }
    
    // Output the result
    cout << "Lowercase string: " << input << endl;

    return 0;
}
