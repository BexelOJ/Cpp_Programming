#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

int main(){
    std::string str = "C PLus Plus";
    std::vector<std::string> words;
    std::string word;
    std::stringstream ss;

    ss<<str;

    while(ss>>word)
        words.push_back(word);

    for(auto& n : words)
        std::cout<<n<<" ";
    std::cout<<std::endl;

    std::reverse(words.begin(), words.end());

    for(auto& n : words)
        std::cout<<n<<" ";
    std::cout<<std::endl;

    return 0;
}


