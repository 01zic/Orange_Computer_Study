//直接插入排序的增量为1，在直接插入排序的基础上重新设置增量分组排序并逐步缩减增量到1
//在直接插入排序的基础上添加增量的循环条件
#include<stdio.h>
void ShellSort(int* a, int N);
int main()
{
    int N;
    scanf("%d", &N);
    int a[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }
    ShellSort(a, N);
    for (int i = 0; i < N; i++)
    {
        printf("%d ", a[i]);
    }
}
void ShellSort(int* a, int N)
{
    for (int incre = N / 2; incre >= 1; incre /= 2)//设置增量为数组长度的一半并逐步对半取值，直到增量为1
    {
        for (int i = incre;  i < N; i++)//在直接插入排序的基础上修改增量的值
        {
            int temp = a[i];//待排序的值
            int j = i - incre;
            while (j >= 0 && a[j] > temp)
            {
                a[j + incre] = a[j];
                j-=incre;
            }
            a[j + incre] = temp;//插入待排序的值
        }

    }
}
********************************************************************************************************************************
//希尔排序的基本思想是按照增量进行分组比较
//可以用交换函数来对每一个分组进行排序
#include<stdio.h>
#define swap(a,b) (a^=b,b^=a,a^=b)//宏定义交换函数
void ShellSort(int* a, int N);
int main()
{
    int N;
    scanf("%d", &N);
    int a[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }
    ShellSort(a, N);
    for (int i = 0; i < N; i++)
    {
        printf("%d ", a[i]);
    }
}
void ShellSort(int* a, int N)
{
    for (int incre = N / 2; incre >= 1; incre /= 2)//设置增量为数组长度的一半并逐步对半取值，直到增量为1
    {
        for (int i = incre;  i < N; i++)//在直接插入排序的基础上修改增量的值
        {
            while (a[i-incre]>a[i] )//比较每一个分组的大小，然后按照从小到大的顺序进行交换
            {
                swap(a[i - incre], a[i]);
            }
        
        }

    }
}
