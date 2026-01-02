#include <iostream>
#include <vector>
#include <cstddef>

int main() {
    std::vector<int> data = {1,2,3,4,5};

    int n = sizeof(data);
    std::cout << "Size of vector object = " << n << std::endl;

    for (size_t i = 0; i < data.size(); i++) { 
        std::cout << data[i] << std::endl;
    }

    int si = data.size();
    std::cout << "No of Elements : " <<si << std::endl;

    int ca = data.capacity();
    std::cout << "No of Elements : " << ca << std::endl;



    return 0;
}


