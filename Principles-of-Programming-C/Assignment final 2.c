#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct student//构造结构体
{
    char name[100];
    int grade;
}student;

int main(void)
{
    //文件的输入与输出
    FILE *file;
    file = fopen("info.txt", "r");

    FILE *fl;
    fl = fopen("info2.txt", "w");
    //构造计数变量
    int cnt = 0;
    student input[1000];
    char buffer[1000];
    //文件的逐行读取
    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        
        char num[100];
        int cntname = 0;
        int cntnum = 0;
        int len = strlen(buffer);//去除换行符
        if (len > 0 && buffer[len - 1] == '\n')
        {
            buffer[--len] = '\0';
        }
        //文件的规范化输入
        for (int i= 0; i < len; i++)
        {
            if (isalpha(buffer[i]))
            {
                input[cnt].name[i] = buffer[i];
                cntname++;
            }
            if (isdigit(buffer[i]))
            {
                num[cntnum++] = buffer[i];
            }         
        }
        //变量转换
        input[cnt].name[cntname] = '\0';
        num[cntnum] = '\0';
        int tmp = atoi(num);
        input[cnt].grade = tmp;
        cnt++;
        
    }
    printf("%s", input[1].name);
    fclose(file);
    //选择排序
    for (int i = 0; i < cnt; i++)
    {
        student max = input[i];
        int maxIndex = i;
        for (int j = i; j < cnt; j++)
        {
            if (max.grade < input[j].grade)
            {
                max = input[j];
                maxIndex = j;
            }
        }
        student tmp = input[i];
        input[i] = input[maxIndex];
        input[maxIndex] = tmp;
    }
    //文件的输出
    for (int i = 0; i < cnt; i++)
    {
        fprintf(fl, "%s,%d\n", input[i].name, input[i].grade);
    }
    fclose(fl);
    return 0;
}