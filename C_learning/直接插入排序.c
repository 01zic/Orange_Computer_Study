#include<stdio.h>
void InsertSort(int* a, int N);
int main()
{
    int N;
    scanf("%d", &N);
    int a[N];
    for (int i = 0; i < N; i++) 
    {
        scanf("%d", &a[i]);
    }
    InsertSort(a, N);
    for (int i = 0; i < N; i++)
    {
        printf("%d ", a[i]);
    }
}
void InsertSort(int* a, int N)//从每一个基准元素开始向左比较，如果大于基准元素就将元素后移，否则就插入基准元素
{
    
    for (int i = 1; i < N; i++)
    {
        int temp = a[i];
        int j = i - 1;
        while (j>=0&&a[j]>temp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}

