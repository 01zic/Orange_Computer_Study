#include<stdio.h>
void QuickSort(int* a, int left, int right);
int main()
{
    int N;
    scanf("%d", &N);
    int a[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d ", &a[i]);
    }
    QuickSort(a, 0, N-1);
    for (int i = 0; i < N; i++)
    {
        printf("%d", a[i]);
    }
}
void QuickSort(int* a, int left, int right)
{
    if (left > right)//判断左边起始的值是否小于右边起始的值
    {
        return ;
    }
    int i = left;//设置变量使用起始值，保留原来变量，便于后面用于交换
    int j = right;
    int benchmark;//基准值
    benchmark = a[i];//将左边的第一个值设置为基准值
    while (i != j)//当两个值相等的时候停止
    {
        while (j > i && a[j] >= benchmark)//从左边开始寻找小于基准值的位置，找到后停止
            j--;
        while (j > i && a[i] <= benchmark)//从右边开始寻找大于基准值的位置，找到后停止
            i++;
        if (j > i)//两边停止之后，先判断左边的位置是否小于右边的位置，如果是，则交换两个位置的值
        {
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }//当左边位置等于右边位置的时候，第一轮交换结束，将基准值与两个相遇位置的值交换
    a[left] = a[i];
    a[i] = benchmark;
    QuickSort(a, left, i - 1);//将第一次相遇的位置左边的序列进行递归
    QuickSort(a, i + 1, right);//将第一次相遇的位置右边的序列进行递归
}
