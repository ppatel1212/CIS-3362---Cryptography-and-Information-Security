#include <stdlib.h>
#include <stdio.h>
#include <math.h>


int getPrimRoot(int a, int p);


int main(void){
    int i, j, getInt, lowTriv, flag = 0;

    //Obtain the integer (2-1000)
    printf("Enter n.\n");
    scanf("%d", &getInt);

    //Use for loop to go through the numbers to see if they are prime
    for(i = 0, j = 2; i < getInt; i++, j++){

        //printf("\n\n%d\n\n", j); j kept getting stuck at 2. move var 'j'

        if((getInt % j == 0) && (getInt != j)){
            flag = 1;
            lowTriv = j;
            break;
        }
    }

    if(flag == 1)
        printf("%d is not prime. It's smallest non-trivial divisor is %d\n", getInt, lowTriv);
    
    if(flag == 0){+
        printf("%d is prime.\n", getInt);
        printf("Its primitive roots are: ");

        for(i = 2; i < getInt; i++){
            if(getPrimRoot(i, getInt) != 0)
            printf("%d ", i);
        } 
    }

    return 0;
}


int getPrimRoot(int a, int p){
    //Use exp var in for loop. using pow() will need to use double making complicated
    int i, j, k, exp, temp, flag = 0;
    int counter;
    int holdArr[p-1];

    for(exp = 1; exp <= p-1; exp++){
        temp = 0;
        //The for loop below will put a to the exponent
        for(i=1; i<=exp; i++){
            if(i == 1)
                temp = a;
            else
                temp *= a;
        }

        holdArr[exp-1] = temp % p;
    }

    // ***************************************************************************
    /*printf("%d Array vals: ", a);
    for(i = 0; i < p; i++)
        printf("%d ", holdArr[i]);*/

    //Loop through the array to determine if a number ----- temp % p is repeated
    //****************************************************************************

    for(j = 1; j <= p-1; j ++){
        counter = 0;
        for(k = 0; k < p-1; k++){
            if(holdArr[k] == j)
                counter++;
            if(counter > 1){
                flag = 1;
                break;
            }
        }
    }

    if(flag == 1)
        return 0;

    return a;
}