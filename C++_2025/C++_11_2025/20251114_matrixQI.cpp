#include<iostream>

using namespace std;

int main() {
    int arr[4][4] = { {0,1,1,1},{1,0,1,1},{1,1,1,1},{1,1,1,1}};
    int sav[4][4] = { {0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0} };

    std::cout << "Original Matrix: " << std::endl;
    std::cout << std::endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }


    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (arr[i][j] == 0) {
                sav[i][j] = 1;
                }
            }
        }
    
    
for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {

        if (sav[i][j] == 1) {
            for (int k = 0; k < 4; k++) {
                arr[k][j] = 0;
            }
            for (int l = 0; l < 4; l++) {
                arr[i][l] = 0;
            }
        }
    }
}
std::cout << std::endl;
std::cout << "Final Matrix: " << std::endl;
std::cout << std::endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}



