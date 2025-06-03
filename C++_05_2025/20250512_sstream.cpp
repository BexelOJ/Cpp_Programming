#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // Example string
    string str = "C Plus Plus";
    // Create a stringstream object
    stringstream ss;
    // Use the stringstream to read the string
    ss << str;
    // Create a string to hold each word
    string word;
    // Create a vector to hold the words
    vector<string> words;

    // Split the string into words
    while (ss >> word) {
        words.push_back(word);
    }

    // Output words in reverse order
    for (int i = words.size() - 1; i >= 0; --i) {
        std::cout << words[i];
        if (i > 0)
            cout << " ";
    }

    cout<<endl;
    return 0;
}

