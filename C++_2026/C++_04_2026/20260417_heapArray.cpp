#include <iostream>

int arr_3[5] = {100,200,300};

int main(){
    int n = 10;
    int *arr_1 = new int[n]{1,2,3};
    int arr_2[10] = {10,20,30,40};

    for(int i=0; i<n; i++){
        std::cout<<*(arr_1+i)<<" ";
    }
    std::cout<<std::endl;

    //std::cout<<*arr<<std::endl;
    std::cout<<arr_1<<std::endl;
    std::cout<<arr_1 + 1<<std::endl;
    std::cout<<arr_1+2<<std::endl;        
    std::cout<<std::endl;

    std::cout<<*&arr_1[0]<<std::endl;
    std::cout<<arr_1 + 1<<std::endl;
    std::cout<<arr_1+2<<std::endl;       

    std::cout<<arr_3[1]<<std::endl;
    std::cout<<arr_3[2]<<std::endl;     
    std::cout<<arr_3[3]<<std::endl;  

    //std::cout<<arr_1<<std::endl;  
    std::cout<<*(&arr_1[0])<<std::endl;
    std::cout<<*&arr_1[1]<<std::endl;  
    std::cout<<&arr_1[2]<<std::endl;
    std::cout<<&arr_1[3]<<std::endl;


    delete[] arr_1;

    return 0;
}


