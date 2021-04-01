#include<stdio.h>
void SelectSort(int* a, int N);
int main()
{
    int N;
    scanf("%d", &N);
    int a[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d ", &a[i]);
    }
    SelectSort(a, N);
    for (int i = 0; i < N; i++)
    {
        printf("%d ", a[i]);
    }
}
void SelectSort(int* a, int N)//从第一个数到最后一个数依顺序将最小的数放在最前面，可以实现升序排列
{
    for (int i = 0; i < N-1; i++)
    {
        int record = i;
        for (int j = i + 1; j < N - 1; j++)
        {
            if (a[record] > a[j])//改变符号可以实现降序
                record = j;
        }
        int t = a[i];
        a[i] = a[record];
        a[record] = t;
        record = i;
    }
}


