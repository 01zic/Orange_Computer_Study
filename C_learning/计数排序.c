#include<stdio.h>
#include<stdlib.h>
int GetMax(int* a, int N);
void countingSort(int* a, int N, int K);
int main()
{
    int N;
    scanf("%d ", &N);
    int a[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d ", &a[i]);
    }
    int aMax = GetMax(a, N);
    countingSort(a, N, aMax);
    for (int i = 0; i < N; i++)
    {
        printf("%d ", a[i]);
    }

}
int GetMax(int* a, int N)
{
    int result = 0;
    for (int i = 0; i < N; i++)
    {
        if (a[i] > result)
            result = a[i];
    }
    return result;
}

void countingSort(int* a, int N, int K)
{
    int* b, * c;
    b = (int*)malloc(sizeof(int) * N);
    c = (int*)malloc(sizeof(int) * K);
    for (int i = 0; i <= K; i++)//初始化计数数组
    {
        c[i] = 0;
    }
    for (int i = 0; i < N; i++)//对待排序数组的每一个元素个数进行统计
    {
        c[a[i]] += 1;
    }
    for (int i = 1; i <= K; i++)//统计小于等于对应元素的个数
    {
        c[i] = c[i - 1] + c[i];
    }
    for (int i = N-1; i >=0; i--)//从最后一位元素向前遍历
    {
        b[c[a[i]]-1] = a[i];
        c[a[i]] -= 1;
    }
    for (int i = 0; i < N; i++)//保存排序好的数组
    {
        a[i] = b[i];
    }
    free(b);
    free(c);
}
