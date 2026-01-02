
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>

int main() {
    std::string st = "C Plus Plus";
    std::string str = "Hello, World!";
    std::reverse(str.begin(), str.end());  // Reverse the string
    std::cout << "Reversed string : " << str << std::endl;
    
    std::vector<std::string> words;
    std::string word;
    std::stringstream ss;

    ss<<st;
    
    while(ss>>word){
        words.push_back(word);
    }

    for(auto& n : words)
        std::cout<<n<<" ";
    std::cout<<std::endl;

    std::reverse(words.begin(), words.end());

    for(auto& n : words)
        std::cout<<n<<" ";
    std::cout<<std::endl;
    return 0;
}
            
