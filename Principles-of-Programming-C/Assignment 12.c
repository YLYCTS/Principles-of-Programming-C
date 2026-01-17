#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int main()
{

    while(true)
    {
        printf("读取一行字符串，统计串中每个字母出现的次数，大小写不区分，然后按照出现次数从大到小输出。\n");
        printf("输入END程序结束。\n");

        char input[1000];
        char exit[4];
        strcpy(exit, "END");
        int numbers[26] = {0};
        int index[26] = {0};

        // 读取用户输入的一行字符串
        fgets(input, 1000, stdin);

        int length = strlen(input);
        // 如果字符串末尾有换行符，将其替换为字符串结束符
        // 注意：这里使用--length先减减再使用，会修改length的值
        if (length > 0 && input[--length] == '\n')
        {
            input[length] = '\0';
        }
        // 检查用户是否输入了"END"，如果是则结束程序
        if (!strcmp(input, exit))
        {
            return 0;
        }
        // 显示处理后的字符串信息
        printf("字符串s1的长度是%d，内容是：%s\n", length, input);

        // 统计字符串中每个字母出现的次数（不区分大小写）
        for (int i = 0; i < length; i++)
        {
            if (!isalpha(input[i]))
            {
                continue;
            }
            // 将字母转换为小写，然后计算其在字母表中的索引（0-25）
            // 对应字母a-z，并增加该字母的计数
            numbers[tolower(input[i]) - 'a']++;
        }

        // 初始化索引数组，初始顺序为字母表的自然顺序（a-z）
        for (int i = 0; i < 26; i++)
        {
            index[i] = i;
        }

        // 使用选择排序算法对索引数组进行排序
        // 排序依据：字母出现次数（降序排列）
        for (int i = 0; i < 25; i++)
        {
            int max_index = i;
            for (int j = i; j < 26; j++)
            {
                if (numbers[index[max_index]] < numbers[index[j]])
                {
                    max_index = j;
                }
            }

            int tmp = index[i];
            index[i] = index[max_index];
            index[max_index] = tmp;

        }
        // 输出排序结果：按出现次数从大到小输出每个字母及其出现次数
        for (int i = 0; i < 26; i++)
        {
            printf("%c出现的次数是%d次。\n", 'a' + index[i], numbers[index[i]]);
        }
    }
}
