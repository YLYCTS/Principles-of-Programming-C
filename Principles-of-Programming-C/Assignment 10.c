#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    printf("=====================================\n");
    printf("\t字符串综合比较应用\n");
    printf("=====================================\n");

    char str[3][20] = {"Input", "Compare", "Exit"};//复制命令字符串到数组中
    char strings[3][100] = {"", "", ""};  // 定义字符串数组用于存储用户输入的三个字符串，初始化为空字符串
    while (1)
    {
        printf("\n请输入命令串，进行操作:\n");
        printf("1.\"Input\"--- 输入s1,s2,s3三个字符串：\n");
        printf("2.\"Compare\"--- 比较s1,s2,s3三个字符串字典序大小：\n");
        printf("3.\"Exit\"--- 退出程序\n");

        char command[20];
        int choice = 0, length[4];
        // 获取用户输入的命令
        if (fgets(command, sizeof(command), stdin) == NULL)
        {
            printf("输入错误，请重试。\n");
            continue;
        }

        length[0] = strlen(command);
        // 移除末尾的换行符（如果存在）
        if (command[length[0] - 1] == '\n')
        {
            command[length[0] - 1] = '\0';
        }
        // 将用户输入的命令与预定义命令进行匹配
        for (int i = 0; i < 3; i++)
        {
            if (strcmp(command, str[i]) == 0)// 使用strcmp比较字符串是否相等
            {
                choice = i + 1;
                break;
            }
        }
        if (choice == 0)
        {
            printf("无效命令，请重试。\n");
            continue;
        }
        // 处理Input命令：输入三个字符串
        if (choice == 1)
        {
            for (int i = 0; i < 3; i++)
            {
                printf("请输入字符串 s%d: ", i + 1);
                if (fgets(strings[i], sizeof(strings[i]), stdin) == NULL)
                {
                    printf("输入错误，请重试。\n");
                    i--; // 输入错误，回退索引，重新输入当前字符串
                    continue;
                }
                length[i + 1] = strlen(strings[i]);
                if (strings[i][length[i + 1] - 1] == '\n')
                {
                    strings[i][length[i + 1] - 1] = '\0';
                }
                //打印字符串长度和内容
                printf("字符串s%d的长度为: %d, 内容是%s\n", i + 1, length[i + 1] - 1, strings[i]);
            }

        }
        else if (choice == 2) // Compare
        {
            // 初始化最小和最大字符串的索引为0（假设第一个字符串既是最小也是最大
            int min_index = 0, max_index = 0;
            // 遍历比较每个字符串，找出最小和最大的字符串
            for (int i = 1; i < 3; i++)
            {
                if (strcmp(strings[i], strings[min_index]) < 0)
                {
                    min_index = i;
                }
                if (strcmp(strings[i], strings[max_index]) > 0)
                {
                    max_index = i;
                }
            }

            printf("\n比较结果:\n");
            printf("最小的字符串: %s\n", strings[min_index]);
            printf("最大的字符串: %s\n", strings[max_index]);
        }
        else if (choice == 3)
        {
            printf("退出程序。\n");
            return 0;
        }
    }
}
