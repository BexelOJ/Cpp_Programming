#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void print(int a, int b){
    char num[] = {"zero", "one", "two", "three", "four",
        "five", "six", "seven", "eight", "nine"};

    for (int i = a; i <= b; i++) {
        if (i >= 0 && i <= 9) {
            printf("%s\n", num[i]);
        } else if (i % 2 == 0) {
            printf("even\n");
        } else {
            printf("odd\n");
        }
    }
}



int main() 
{
    int a, b;
    scanf("%d\n%d", &a, &b);
  	// Complete the code.
    print(a,b);
    return 0;
}

