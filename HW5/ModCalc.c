#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(void){
    double enterNum;
    double enterPower;
    double enterMod;
    double resultMod;

    printf("Enter the number: ");
    scanf("%lf", &enterNum);

    printf("Enter the power: ");
    scanf("%lf", &enterPower);

    printf("Enter MOD power: ");
    scanf("%lf", &enterMod);

    resultMod = pow(enterNum, enterPower);

    printf("The result is: %lf", fmod(resultMod,enterMod));
    
    return 0;
}