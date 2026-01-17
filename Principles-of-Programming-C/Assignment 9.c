#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void ClearBuffferInput(void); // 清除输入缓冲区
void Input(char **original, char **substring); // 输入字符串函数
void Search(char *original, char *substring); // 搜索子串函数

int main(void)
{
    // 初始化字符串指针为NULL
    char *original = NULL;
    char *substring = NULL;
    printf("=====================================\n");
    printf("       字符串查找匹配应用\n");
    printf("=====================================\n");

    // 主循环：显示菜单并处理用户选择
    while (true)
    {
        int key = 0;
        printf("\n请选择操作:\n");
        printf("1. 输入原字符串和子串：\n");
        printf("2. 输出子串在原字符串中所有出现的位置索引：\n");
        printf("3. 退出\n");
        printf("请输入选项 (1-3):");

        // 验证用户输入：必须是1-3的整数
        while (scanf("%d", &key) !=  1 || key < 1 || key >3)
        {
            ClearBuffferInput();
            printf("请您输入选项 (1-3)，为正整数，请重新来！\n");
        }
        ClearBuffferInput();

       // 根据用户选择执行相应操作
        switch (key) {
            case 1:
                Input(&original, &substring); // 输入字符串：传递指针的地址（二级指针）
                break;
            case 2:
                Search(original, substring); // 搜索子串：传递指针（一级指针）
                break;
            case 3:
                printf("感谢使用字符串查找匹配应用!\n");
                free(original);
                free(substring);
                return 0;
        }
    }
}

void ClearBuffferInput(void)
{
    while (getchar() != '\n');
}

void Input(char **original, char **substring)
{
    // 动态分配内存：为两个字符串各分配1000个字符的空间
    *original = malloc(1000 * sizeof(char));
    *substring = malloc(1000 * sizeof(char));

    printf("请输入一行原串：\n");

    fgets(*original, 1000, stdin);
    int length_ori = strlen(*original);
    (*original)[--length_ori] = '\0'; // 移除末尾的换行符
    printf("原串s1的长度是%d，内容是：%s\n", length_ori, *original);

    printf("请输入一行子串：\n");
    fgets(*substring, 1000, stdin);
    int length_sub = strlen(*substring);
    (*substring)[--length_sub] = '\0'; // 移除末尾的换行符
    printf("子串s2的长度是%d，内容是：%s\n", length_sub, *substring);
}

void Search(char *original, char *substring)
{
    // 检查字符串是否已输入
    if (original == NULL || substring == NULL)
    {
        printf("请先通过菜单1设置两个字符串的值。\n");
        return;
    }
    printf("查找结果：\n");
    int length_ori = strlen(original);
    int length_sub = strlen(substring);

    // 外层循环：遍历原字符串中所有可能的起始位置
    for (int i = 0; i <= length_ori - length_sub; i++)
    {
        int match = 1;
        if (original[i] == substring[0] )
        {
            // 内层循环：比较剩余字符
            for (int j = 1; j < length_sub; j++)
            {
                if (original[i + j] != substring[j])
                {
                    match = 0;
                    break;
                }
            }
            if(match)
            {
                printf("在原串的%d位置找到子串\n", i);
            }
        }
    }
}
