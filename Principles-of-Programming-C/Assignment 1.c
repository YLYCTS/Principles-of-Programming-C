#include <stdio.h>
int main (void)
{
    double a;

    printf("华氏温度 ---> 摄氏温度 \n");

    for (int i  = 0; i <= 300; i += 30)
    {
        a =  5 * (i - 32) / 9.0;
        printf("   %3d      %7.3f \n", i, a);
    }

    printf("\n摄氏温度 ---> 华氏温度\n");

    for (int i = 0; i <= 300; i+= 30)
    {
        a = i * 9 / 5 + 32;
        printf("   %3d       %7.3f\n", i, a);
    }

    char input;

    // Wait for user to input 'q' to quit
    do
    {
        printf("Please input q to quit\n");
        input = getchar();
        getchar();
    }while (input != 'q');
}
