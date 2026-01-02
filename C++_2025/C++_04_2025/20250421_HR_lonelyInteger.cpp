#include <iostream>
#include <vector>

int lonelyinteger(std::vector<int> a) {
    int result = 0;
    for (int num : a) {
        result ^= num;
    }
    return result;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::cout << lonelyinteger(a) << std::endl;
    return 0;
}

