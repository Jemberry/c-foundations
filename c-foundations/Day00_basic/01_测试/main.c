#include <stdio.h>

int main(void){
   
    int arr[10] = { 1,2,3,4,5,6,7,8,9 };
    int *p = arr;

    p++;

    printf("%ld\n", *p);
    printf("%lf\n", *p);

    return 0;
}
