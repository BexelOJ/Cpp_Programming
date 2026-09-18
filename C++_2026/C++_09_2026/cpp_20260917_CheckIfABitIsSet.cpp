#include <iostream>

bool isBitSet(unsigned int n, int pos) {
    bool num;
    num = (n & (1 << pos));
    if (num == true) {
        return true;
    }
    else {
        return false;
    }
}


int main() {
    int n = 0;
    int pos = 0 ;
    std::cout << "Enter the number and position " << std::endl;
    std::cin >> n >> pos;
   

    bool res = isBitSet(n, pos);
    std::cout << res << std::endl;

    return 0;
}


/*

and - Logical AND - &&
not - Logical NOT - !
or - Logical OR - |

bitand - bitwise AND - &
bitor - bitwise OR - |
compl - bitWise NOT - ~

*/


