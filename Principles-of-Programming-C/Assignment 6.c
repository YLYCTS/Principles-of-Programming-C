#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 函数声明
void wall(char alph, int high, int width);      // 绘制实心矩形（墙）
void frame(char alph, int high, int width);     // 绘制空心矩形（框）
void triangle(char alph, int high, int width);  // 绘制直角三角形

int main()
{
    // 主循环，持续运行直到用户选择退出
    while(true)
    {
        int image = 0, high = 0, width = 0;  // 存储用户选择的图形类型、高度和宽度
        char alph[100];                       // 存储用户输入的填充字符

        // 提示用户选择要绘制的图形类型
        printf("请输入要绘制的图形：1-墙  2-框  3-三角， 输入-1结束。注意：对于所有输入我们采用能用则用，不行报错的原则。\n");

        // 验证图形类型输入：必须是1、2、3或-1
        while(!scanf("%d", &image) || (image != 1 && image != 2 && image != 3 && image != (-1)))
        {
            printf("类型不符合要求，请重新来！\n");
            while (getchar() != '\n');  // 清空输入缓冲区
            continue;
        }
        while (getchar() != '\n');      // 清空输入缓冲区中的换行符

        // 如果用户输入-1，退出程序
        if (image == -1)
            break;

        // 获取填充字符
        printf("请输入图形的填充字母\n");
        fgets(alph, 100, stdin);        // 读取一行输入，包括空格

        // 验证高度输入：必须是1-3000之间的整数
        printf("请输入高度\n");
        while(!scanf("%d", &high) || (high < 1 || high > 3000))
        {
            printf("非法输入，需要[1,3000]闭区间的正整数。\n");
            while (getchar() != '\n');  // 清空输入缓冲区
            continue;
        }
        while (getchar() != '\n');      // 清空输入缓冲区中的换行符

        // 验证宽度输入：必须是1-3000之间的整数
        printf("请输入宽度\n");
        while(!scanf("%d", &width) || (width < 1 || width > 3000))
        {
            printf("非法输入，需要[1,3000]闭区间的正整数。\n");
            while (getchar() != '\n');  // 清空输入缓冲区
            continue;
        }
        while (getchar() != '\n');      // 清空输入缓冲区中的换行符

        // 根据用户选择的图形类型调用相应的绘制函数
        switch (image)
        {
            case 1:
                wall(alph[0], high, width);      // 绘制实心矩形
                break;
            case 2:
                frame(alph[0], high, width);     // 绘制空心矩形
                break;
            case 3:
                triangle(alph[0], high, width);  // 绘制直角三角形
                break;
        }
    }

    return 0;  // 程序正常结束
}

void wall(char alph, int high, int width)
{
    // 循环绘制每一行
    for (int i = 0; i < high; i++)
    {
        // 在当前行绘制指定宽度的字符
        for (int j = 0; j < width; j ++)
        {
            printf("%c", alph);
        }
        printf("\n");  // 换行到下一行
    }
}

void frame(char alph, int high, int width)
{
    // 如果高度大于1，绘制顶部边框
    if (high != 1)
    {
        for (int i = 0; i < width; i++)
        {
            printf("%c", alph);
        }
        printf("\n");
    }

    // 绘制中间部分（两侧边框和中间空格）
    for (int i = 0; i < high - 2; i++)
    {
        printf("%c", alph);  // 左侧边框
        // 绘制中间空格部分
        for (int j = 0; j < width - 2; j ++)
        {
            printf(" ");
        }
        printf("%c\n", alph);  // 右侧边框并换行
    }

    // 绘制底部边框
    for (int i = 0; i < width; i++)
    {
        printf("%c", alph);
    }
    printf("\n");
}

void triangle(char alph, int high, int width)
{
    // 确定三角形的实际行数（取高度和宽度中的较大值）
    int max = high;
    if (max < width)
    {
        max = width;
    }

    // 绘制三角形：每行的字符数等于行号+1
    for (int i = 0; i < max; i++)
    {
        // 当前行绘制 i+1 个字符
        for (int j = 0; j < i + 1; j ++)
        {
            printf("%c", alph);
        }
        printf("\n");  // 换行到下一行
    }
}
