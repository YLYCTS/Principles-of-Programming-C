#include <stdio.h>
//定义函数
int find_max(int count, int outcome[]);
int find_min(int count, int outcome[]);
int summation(int count, int outcome[]);

int main(void)
{
    int weight = 0;
    char unit;
    int outcome[100];
    int count = 0;
    while (1)
    {
        printf("欢迎来到货物质量单位统一换算系统。1千克=1000克,1镑=16盎司,1镑=454克。\n");
        printf("请输入货物的质量数(正整数)。\n");

        //判断是否为正常输入
    renew_1:
        if ((scanf("%d", &weight)) != 1 || weight < 0 || weight > 10000)
        {
            printf("非法输入，需要[0,10000]闭区间的正整数。\n");
            while (getchar() != '\n')
                ;
            goto renew_1;
        }
        if (weight >= 0 && weight <= 10000)
        {
            printf("请输入货物的质量单位(g,G-克,k,K-千克,o,O-盎司,p,P-镑）,输入x程序退出。\n");
            while (getchar() != '\n')
                ;
            if ((scanf("%c", &unit)) != 1)
            {
                printf("非法输入,需要(g,G-克,k,K-千克,o,O-盎司,p,P-镑）,输入x程序退出。\n");
                while (getchar() != '\n')
                    ;
                    continue;
            }
            //根据选择，进行单位换算
            switch (unit)
            {
                case 'g':
                case 'G':
                    outcome[count++] = weight;
                    printf("第%d个货物的质量是%d克\n", count, outcome[count - 1]);
                    continue;
                case 'k':
                case 'K':
                    outcome[count++] = weight * 1000;
                    printf("第%d个货物的质量是%d克\n", count, outcome[count - 1]);
                    continue;
                case 'o':
                case 'O':
                    outcome[count++] = (int) (weight * 454 / 16.0 + 0.5);
                    printf("第%d个货物的质量是%d克\n", count, outcome[count - 1]);
                    continue;
                case 'p':
                case 'P':
                    outcome[count++] = weight * 454;
                    printf("第%d个货物的质量是%d克\n", count, outcome[count - 1]);
                    continue;
                case 'x':
                    //最后进行总结
                    printf("最重货物的质量是%d克\n", find_max(count, outcome));
                    printf("最轻货物的质量是%d克\n", find_min(count, outcome));
                    printf("货物的全部总质量是%d克\n", summation(count, outcome));
                    printf("货物的平局质量是%d克\n", (int) (summation(count, outcome) / (float) count + 0.5));
                    return 0;
                default:
                    printf("非法输入,需要(g,G-克,k,K-千克,o,O-盎司,p,P-镑）,输入x程序退出。\n");
                    continue;
            }
        }
    }
    return 0;
}

//寻找最大值
int find_max(int count, int outcome[])
{
    int max = outcome[0];
    for (int i = 1; i < count; i++)
    {
        if (max < outcome[i])
        {
            max = outcome[i];
        }
    }
    return max;
}

//寻找最小值
int find_min(int count, int outcome[])
{
    int min = outcome[0];
    for (int i = 1; i < count; i++)
    {
        if (min > outcome[i])
        {
            min = outcome[i];
        }
    }
    return min;
}

//对所有货物的质量进行求和
int summation(int count, int outcome[])
{
    int sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += outcome[i];
    }
    return sum;
}
