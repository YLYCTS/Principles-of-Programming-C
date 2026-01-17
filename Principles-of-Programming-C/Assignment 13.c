#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 定义链表节点
typedef struct node {
    char value;
    struct node* next;
    int place;
}node;

node* creatNode(void); //创建表头
void insertNode(node* first, char* input);//插入链表内容
void freeNode(node* first);//释放链表内存

int main(void)
{
    char END[5];
    strcpy(END, "END");
    while(true)
    {
        char input[1000];

        printf("请输入一行连续无空格的字母串，输入END程序结束。\n");
        //传入字符串
        fgets(input, sizeof(input), stdin);
        int len =strlen(input);
        //删除换行符
        if (len > 0 && input[len - 1] == '\n')
        {
            input[len - 1] = '\0';
            len--;
        }
        //检测是否退出
        if (!strcmp(END, input))
        {
            return 0;
        }
        printf("字符串s1的长度是%d，内容是：%s\n", len, input);
        printf("按照ASCII码排好序的字母串是：\n");
        //使用冒泡排序，对数组进行升序
        for (int i = 0; i < len; i++)
        {
            char min = input[i];
            int index = i;
            for (int j = i + 1; j < len; j++)
            {
                if (min > input[j])
                {
                    min = input[j];
                    index = j;
                }
            }
            char tmp = input[i];
            input[i] = min;
            input[index] = tmp;
        }
        printf("%s\n", input);
        printf("以下根据排好序的字符串，进行构建循环单链表，并输出:\n");
        //进行链表操作
        node* first = creatNode();
        insertNode(first, input);
        for (node* out= first; out->next != NULL; out = out->next)
        {
            printf("The data of %d node is \"%c\"。\n", out->place, out->value);
        }
        freeNode(first);
        printf("进行free释放循环单链表的每个节点。\n");
    }
}
node* creatNode(void)
{
    node* head = (node*)malloc(sizeof(node));
    if (head == NULL)
    {
        return NULL;
    }
    head->next = NULL;
    return head;
}

void insertNode(node* first, char* input)
{
    for(int i = 0; input[i] != '\0'; i++)
    {
        node* body = (node*)malloc(sizeof(node));
        first->next = body;
        first->place = i + 1;
        first->value = input[i];
        body->next = NULL;
        first = body;
    }
}

void freeNode(node* first)
{
    node* nextNode;
    while(first != NULL)
    {
        nextNode = first->next;
        free(first);
        first = nextNode;
    }
}
