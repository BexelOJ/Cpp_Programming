// print longest consecutive numbers

#include <iostream>
#include <vector>

int main()
{
    int arr[] = {30, 37, 38, 39, 18, 14, 15, 20, 22, 25};
    int s = (sizeof(arr)/sizeof(arr[0])), count=1, index =0, max_count = 0;
    int i=0;

        for(int i=0; i<s; i++){
                if(arr[i]+1 == arr[i+1]){
                    count++;
                    //std::cout<<"Count "<<count<<std::endl;
                } 
                else {
                    if(count > max_count){
                        max_count = count;
                        index = (i+1) - count;
                    }
                    count = 1;
                }
        }
                      
    //std::cout<<"Index "<<index<<std::endl;
    //std::cout<<"Max Count "<<max_count<<std::endl;
    for(int i=index; i<=max_count; i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
    return 0;
}

// 30, 37, 38, 39, 18, 14, 15, 20, 22, 25


