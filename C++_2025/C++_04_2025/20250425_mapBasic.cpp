#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, int> myMap;

    // Insert 10 key-value pairs
    myMap["apple"] = 5;
    myMap["banana"] = 2;
    myMap["cherry"] = 7;
    myMap["date"] = 3;
    myMap["elderberry"] = 8;
    myMap["fig"] = 6;
    myMap["grape"] = 4;
    myMap["honeydew"] = 9;
    myMap["kiwi"] = 1;
    myMap["lemon"] = 10;

    // Print the contents of the map
    // for (const auto& pair : myMap) {
    //     cout << pair.first << ": " << pair.second << endl;
    // }

    map<string, int>::iterator it;
    it = myMap.find("honeydew");
    if (it != myMap.end()) {
        cout << "Found banana: " << it->first << endl;
        cout << "Found banana: " << it->second << endl;
    } else {
        cout << "banana not found" << endl;
    }

    return 0;
}


