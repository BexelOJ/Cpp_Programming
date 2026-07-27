#include <cstdio>
#include <iostream>

int main(){
    printf("Hello World\n");

    char arr_one[] = "Hello";
    char arr_two[] = "World";
    char space[] = " ";
    const char* cptr = "Hi i am in America";

    std::cout<<arr_one<<std::endl;
    std::cout << arr_two << std::endl;
    std::cout << space << std::endl;

    printf("Other repre: %s %s\n\n", arr_one, arr_two);

    std::cout<<cptr<< std::endl;
    std::cout << *cptr << std::endl;

}


