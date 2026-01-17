#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int inputFunction(char* input);

int main()
{
    printf("=====================================\n");
    printf("       字符串综合查找替换应用\n");
    printf("=====================================\n");
    while (true)
    {
        printf("请输入原串s1，输入\"END\"时，程序退出\n");

        char input[100], search[100], replace[100];

        int len_input = inputFunction(input);

        if (!strcmp("END", input))
        {
            return 0;
        }
        printf("原串s1的长度是%d，内容是：%s\n", len_input, input);
        printf("请输入查找串s2\n");

        int len_search = inputFunction(search);

        printf("子串s2的长度是%d，内容是：%s\n", len_search, search);
        printf("请输入替换串s3\n");

        int len_replace = inputFunction(replace);

        printf("子串s3的长度是%d，内容是：%s\n", len_replace, replace);

        char result[2000];  // 结果缓冲区，更大以防止溢出
        result[0] = '\0';   // 初始化为空字符串
        int pos = 0;        // 在原字符串中的当前位置

        while (pos < len_input)
        {
            // 查找子串
            int found = 0;
            int i;
            for (i = 0; i < len_search; i++)
            {
                if (pos + i >= len_input || input[pos + i] != search[i])
                {
                    break;
                }
            }
            // 如果找到子串
            if (i == len_search && len_search > 0)
            {
                // 将替换串添加到结果中
                strcat(result, replace);
                pos += len_search;
                found = 1;
            }
            // 如果没有找到子串
            if (!found)
            {
                // 复制当前字符到结果中
                int len = strlen(result);
                result[len] = input[pos];
                result[len + 1] = '\0';
                pos++;
            }
        }
        printf("替换后s1的长度是%lu，内容是：%s\n", strlen(result), result);
    }
}
//封装输入函数，并返回字符串长度
int inputFunction(char* input)
{
    fgets(input, 100, stdin);

    int len = strlen(input);

    if (len > 0 && input[len - 1] == '\n')
    {
        input[--len] = '\0';
    }
    return len;
}
