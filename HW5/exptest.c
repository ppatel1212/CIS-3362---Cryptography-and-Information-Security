#include <stdio.h>
#include <stdlib.h>

int main(void){
    int i, j, k=5, exp=3, temp;
    int a = 5;

        for(i=1; i<=exp; i++){
            if(i == 1)
                temp = a;
            else
                temp *= a;
        }

    printf("Temp = %d\n", temp);

    return 0;
}