#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

long long Fibonacci(int input);

int main(void)
{
    char input[100];
    int num[50];

    while (1)
    {
        int quit = 0;
        int i = 0;
        int count = 0;
        int tmp = 0;
        int exit = 0;

        printf("请输入需要计算的斐波那契数列的正整数[0,90]之间，输入-1时程序退出。（英文输入）\n");

        fgets(input, sizeof(input), stdin);

        //检测非法输入，若有则重新输入
        while (input[tmp] != '\0' && input[tmp] != '\n')
        {
            if ((isalpha(input[tmp]) || ispunct(input[tmp])) && (input[tmp] != '-' && input[tmp] != '+'))
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
        //将字符类型的输入转化为整数类型
        while (input[i] != '\0' && input[i] != '\n')
        {
            while (input[i] == ' ')
            {
                i++;
            }

            if (isdigit(input[i]) || ((input[i] == '-' || input[i] == '+') && isdigit(input[i + 1])))
            {
                char num_str[20];
                int j = 0;

                if (input[i] == '+' || input[i] == '-')
                {
                    num_str[j++] = input[i++];
                }

                while (isdigit(input[i]))
                {
                    num_str[j++] = input[i++];
                }
                num_str[j] = '\0';

                num[count++] = atoi(num_str);
            }
        }

        //输出结果
        for (int i = 0; i < count; i++)
        {
            if (num[i] >= 1 && num[i] <= 90)
            {
                printf("第%d个斐波那契数值是%lld\n", num[i], Fibonacci(num[i]));
            }

            else if (num[i] == -1)
            {
                quit = 1;
            }

            else
            {
                printf("非法输入，需要[0,90]闭区间的正整数，输入-1时程序退出。\n");
            }
        }

        if (quit == 1)
        {
            break;
        }
    }

}
//计算斐波那契数值
long long Fibonacci(int input)
{
    if (input <= 0)
    {
        return 0;
    }
    if (input == 1)
    {
        return 1;
    }
    long long a = 0, b = 1, c;
    for (int i = 2; i <= input; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}
