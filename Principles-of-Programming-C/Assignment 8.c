#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int key = 1;
    printf("有一种加密算法，若明文是字母则将其减少一个整数key值(整数【1，10】之间，若不是则保持不变。\n");
    printf("请输入一段明文，根据key，加密后并输出其密文。\n");
    printf("当输入key为10时，程序退出\n");

    while (key != 10) // 主循环，当key不等于10时持续运行
    {
        printf("请输入key值(整数【1，10】之间):\n");
        // 输入验证循环：确保输入的是有效整数且在指定范围内
        while (!scanf("%d", &key) || key < 1 || key > 10)
        {
            printf("输入的数值不对，【1，10】之间，key为10时，程序退出。\n");
            while(getchar() != '\n'); // 清空输入缓冲区，防止无限循环
        }
        printf("key值是：%d", key);
        if (key == 10)
        {
            return 0;
        }
        printf("请输入明文字符串:\n");
        char input[100], after[100];
        scanf("%s", input);
        int length = strlen(input);
        after[length] = '\0';
        for (int i = 0; i < length; i++)
        {
            if (isalpha(input[i])) // 检查当前字符是否为字母
            {
                after[i] = input[i] - key; // 对字母字符进行加密：减去key值
            }
            else
            {
                after[i] = input[i]; // 非字母字符保持不变
            }
        }
        printf("明文字符串是：%s\n", input);
        printf("加密后的密文字符串是：%s\n", after);
    }
}
