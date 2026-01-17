#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int word_num(char *input);
void word_print(char *input);

int main()
{
    char input[1000];

    printf("本程序会将输入的一行英文句子，分成若干单词每行输出，并统计单词个数\n");
    fgets(input, sizeof(input), stdin);

    //去除换行符
    int len = strlen(input);
    input[len - 1] = '\0';

    int num = word_num(input);
    word_print(input);
    printf("一共%d个单词。\n", num);
}

int word_num(char *input)
{
    int count = 0;
    bool in_word = false;

    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == ' ' || input[i] == '\t')
        {
            //遇到空格或制表符，则说明已经遍历一个单词
            if (in_word)
            {
                in_word = false;
            }
        }
        //遇到非空格或制表符，则遍历到一个新单词
        else
        {
            if (!in_word)
            {
                in_word = true;
                count ++;
            }
        }
    }
    return count;
}

void word_print(char *input)
{
    int count = 0;
    int start = 0;
    bool in_word = false;

    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == ' ' || input[i] == '\t')
        {
            // 如果之前正在读取单词，现在遇到分隔符，表示单词结束
            if (in_word)
            {
                printf("第%d个单词：", ++count);
                for (int j = start; j < i; j++)
                {
                    putchar(input[j]);
                }
                printf("\n");
                in_word = false;
            }
        }
        else
        {
            // 如果之前不在单词中，表示开始一个新单词
            if (!in_word)
            {
                in_word = true;
                start = i;// 记录单词开始位置
            }
        }
    }
    // 处理最后一个单词（如果句子不以分隔符结尾）
    if (in_word)
    {
        printf("第%d个单词：", ++count);
        for (int j = start; input[j] != '\0'; j++)
        {
            putchar(input[j]);
        }
        printf("\n");
    }
}
