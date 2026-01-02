#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string input = "C Plus Plus";
    vector<string> words;
    string word;

    // Use stringstream to split the string by spaces
    stringstream ss(input);
    while (ss >> word) {
        words.push_back(word);
    }

    // Reverse the words
    reverse(words.begin(), words.end());

    // Print the reversed words
    for (string w : words) {
        cout << w << " ";
    }
    cout << endl;

    return 0;
}
