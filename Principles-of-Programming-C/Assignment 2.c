#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

long long factorial(int input);

int main()
{
    char input[1000];
    int num[50];
    int count = 0;
    int i = 0;
    int tmp = 0;


    while(1)
    {
    int quit = 0;
    int exit = 0;

    printf("请输入需要计算阶乘的正整数[1,20]，输入-1时程序退出\n");

    fgets(input, sizeof(input), stdin);

    //判断是否有脏输入，若有脏输入，则重新输入
    while(input[tmp] != '\0')
    {
        if (isalpha(input[tmp]) && (input[tmp] != '-' && input[tmp] != '+'))
        {
            exit = 1;
        }
        tmp++;
    }
    if (exit == 1)
    {
        printf("非法输入，");
        continue;
    }

    //将输入的字符串中的数字，转化为整型变量的数字
    while(input[i] != '\0' && input[i] != '\n')
    {
        while (input[i] == ' ')
        {
            i ++;
        }
        if (isdigit(input[i]) || ((input[i] == '+' || input[i] == '-') && isdigit(input[i + 1])))
            {
                char num_str[20];
                int j = 0;

                if(input[i] == '+' || input[i] == '-')
                {
                    num_str[j++] = input[i++];
                }

                while(isdigit(input[i]))
                {
                    num_str[j++] = input[i++];
                }
                num_str[j] ='\0';

                num[count++] = atoi(num_str);
            }
    }
    for (int i = 0; i < count; i++)
    {
        if(num[i] >= 1 && num[i] <= 20)
        {
            printf("%d的阶乘是%lld\n", num[i], factorial(num[i]));
        }

        else if (num[i] == -1)
        {
            quit = 1;
        }
    }
        if ( quit == 1)
    {
        break;
    }
    }
}
//阶乘函数
long long factorial(int input)
{
    long long tmp;
    if (input <= 0)
    {
        return 1;
    }
    tmp = input * factorial(input -1);

    return tmp;
}
