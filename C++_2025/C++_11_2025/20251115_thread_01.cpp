#include <iostream>
#include <string>
#include <thread>

using namespace std;

void function_one() {
 std::cout<<"Function : function_one called "<<std::endl; 
 std::cout << std::endl;
// std::cout << "t1 id : " << t1.get_id() << std::endl;
}
/*
int function_delay() {
    for (int i = 0; i < 1000; )
        {
            i++;
        }
    return 0;
   }
   */
int main() {
    std::thread t1(function_one);/* This is a comment*/
    std::cout << "T1 ID : " << std::this_thread::get_id() << std::endl;
    std::cout << "t1 id : " << t1.get_id() << std::endl;
    t1.join();
    //t1.detach();


    std::thread t2(function_one);
    std::cout << "T2 ID : " << std::this_thread::get_id() << std::endl;
    std::cout << "t2 id : " << t2.get_id() << std::endl;
    t2.join();


    std::thread t3(function_one);
    std::cout << "T3 ID : " << std::this_thread::get_id() << std::endl;
    std::cout << "t3 id : " << t3.get_id() << std::endl;
    t3.join();


    auto function_delay = []() {
        for (int i = 0; i < 100;)
            {
                i++;
            }
        };

    //function_delay();

    std::cout << "Exiting Main Function, Good Bye" <<std::endl;
    
    return 0;
}



