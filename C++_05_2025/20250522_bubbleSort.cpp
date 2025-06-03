#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::vector<int> vec = {5,3,1,2,4};

    for(auto& n : vec)
        std::cout<<n<<" ";
    std::cout<<std::endl;

    //int temp = 0;
    for(int i=0; i<vec.size()-1; i++){
        for(int j=0; j<vec.size()-i-1; j++){
            if(vec[j] > vec[j+1]){
                // temp = vec[j];
                // vec[j] = vec[j+1];
                // vec[j+1] = temp;
                std::swap(vec[j], vec[j+1]);
            }
        }
    }

    for(auto& n : vec)
        std::cout<<n<<" ";    
    std::cout<<std::endl;


    return 0;
}


