#include<stdio.h>
int main()//普通版
{
    int N;
    scanf("%d", &N);
    int a[N];
    for (int i = 0; i < N; i++)//初始化数组
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < N-1; i++)//从数组第一个元素开始两两比较，将每一轮比较的最大值赋值给每一轮的最后一个元素
    {
        for (int j = 0; j < N - 1 - i; j++)
        {
            int t;
            if (a[j] > a[j + 1])
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
    for (int i = 0; i < N; i++)//输出数组
    {
        printf("%d ", a[i]);
    }
}
************************************************************************************
#include<stdio.h>//函数版
void BubbleSort(int N, int a[]);
int main()
{
    int N;
    scanf("%d", &N);
    int a[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }
    BubbleSort(N, a);
    for (int i = 0; i < N; i++)
    {
        printf("%d ", a[i]);
    }
   
}
void BubbleSort(int N, int a[])
{
  
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - 1 - i; j++)
        {
            int t;
            if (a[j] > a[j + 1])
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}
