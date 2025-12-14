#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int lengthString(std::string* str) {
    return strlen(str);
}

int main() {
    std::string str1 = "India";
    int res = lengthString(str1);
    
    return 0;
}

