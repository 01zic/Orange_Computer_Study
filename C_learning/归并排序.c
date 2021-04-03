#include<stdio.h>
#include<stdlib.h>
void Merge(int* a, int start, int mid, int end);
void MergeSort(int* a, int start, int end);
int main()
{
    int N;
    scanf("%d", &N);
    int a[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }
    MergeSort(a, 0, N - 1);
    for (int i = 0; i < N; i++)
    {
        printf("%d ", a[i]);
    }
}
void MergeSort(int* a, int start, int end)//递归进行分拆和归并
{
    if (start < end)//分拆至差值为1
    {   int mid = (start+end) / 2;
        MergeSort(a, start, mid);
        MergeSort(a, mid + 1, end);
        Merge(a, start, mid, end);
    }
}
void Merge(int* a, int start, int mid, int end)//对数组进行归并
{
    int* result = (int*)malloc(sizeof(int) * (end - start + 1));
    int i = start ;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= end)
    {
        if (a[i] < a[j])
        {
            result[k++] = a[i++];
        }
        else
        {
            result[k++] = a[j++];
        }
    }
    while(i <= mid)
    {
        result[k++] = a[i++];
    }
    while(j <= end)
    {
        result[k++] = a[j++];
    }
    for (int i = 0; i < k; i++)
    {
        a[start+i] = result[i];
    }
    free(result);
}
