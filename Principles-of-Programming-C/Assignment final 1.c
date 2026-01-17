#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int number(char ch) //十六进制字母转化数字
{
    return (ch - 'a' + 10);
}

int fn(int input)//计算阶乘
{
    if (input == 0)
        return 1;
    return 16 * fn(input - 1);
}

void function(int number)//二进制转换
{
    if (number > 1)
        function(number / 2);
    printf("%d", number % 2);
}
int fun(char ch)//字母转换数字
{
    return (ch - '0');
}



int main(void)
{
    printf("读取一行字符串，将串中的所有16进制数字字符进行转化成对应的10进制和2进制整数。\n");
    printf("若不是0x或者0X开头，输出非法的16进制数。\n");
    printf("输入END，程序退出。\n");

    while(true)//构造循环
    {
        int num = 0;
        int wrong = 0;
        char input[1000];
        char tmp[1000];
        fgets(input, 1000, stdin);//程序的输入
        int len = strlen(input);
        if (len > 0 && input[len - 1] == '\n')//去除换行符
        {
            input[--len] = '\0';
        }
        strcpy(tmp, input);
        if (!strcmp(input, "END"))
        {
            return 0;
        }
        printf("字符串s1的长度是%d，内容是：%s\n", len, tmp);
        for (int i = 0; i < len; i++)//规范化
        {
            input[i] = tolower(input[i]);
        }
        if (input[0] != '0' && input[1] != 'x')//增强鲁棒性
        {
            printf("非法的16进制数值\n");
            continue;
        }
        for (int i = 2; i < len; i++)//增强鲁棒性
        {
            if (isalpha(input[i]) && input[i] > 'f')
            {
                printf("非法的16进制数值\n");
                wrong = 1;
            }
            if (!isalnum(input[i]))
            {
                printf("非法的16进制数值\n");
                wrong = 1;
            }
        }
        if (wrong)
        {
            continue;
        }
        for (int i = 2; i < len; i++)//十进制转换
        {
            if (isalpha(input[i]))
            {
                num += number(input[i]) * fn(len - 1 - i);
            }
            else
            {
                num += fun(input[i]) * fn(len - 1 - i); 
            }
        }
        printf("转化后的10进制整数数字是：%d\n", num);
        printf("转化后的2进制整数数字是：");
        function(num);
        printf("\n");

    }

    return 0;
}