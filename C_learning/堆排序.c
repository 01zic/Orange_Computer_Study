//堆排序
//堆分为大根堆和小根堆，是一个完全二叉树结构
//大根堆就是每一个父结点都大于它的子结点，小根堆就是每一个父结点都小于它的子结点
/*
数学形式：
1.规定第一个元素的索引值为0
2.每一个父结点 i 对应的左子结点为 2 * i + 1，对应的右结点为2 * i +2
3.父节点的最大索引值为n/2-1
4.大根堆:a[i]>a[2*i+1]&&a[i]>a[2*i+2]
5.小根堆:a[i]<a[2*i+1]&&a[i]<a[2*i+2]
*/
/*堆排序基本思路：
1.构建一个大根堆
1.1一个向下调整的函数
1.2一个初始化并排序的函数
2.将大根堆的第一个元素与最后一个元素交换，并固定最后一个元素
3.重复1、2的过程直到从小到大排序完成
*/
#include<stdio.h>
#define swap(a,b) (a^=b,b^=a,a^=b)//宏定义交换函数
void BigHeap_Down(int* a, int start, int end);//声明向下调整的函数
void HeapSort(int* a, int N);//声明初始化并排序的函数
int main()//测试函数
{
    int N;
    scanf("%d", &N);
    int a[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d ", &a[i]);
    }
    HeapSort(a, N);
    for (int i = 0; i < N; i++)
    {
        printf("%d ", a[i]);
    }

}
void BigHeap_Down(int* a, int start,int end)//定义向下调整的函数
{
    int current = start;//储存父节点的位置
    int cu_left = 2*current+1;//子节点
    for (; cu_left <=end; current=cu_left, cu_left=2*current+1)//从传入的起点开始，到终点结束，每次循环结束都将重置父节点并重置对应的左结点
    {
        if (cu_left < end && a[cu_left] < a[cu_left + 1]) //比较左右子节点的值大小，右边大则左边索引值加一得到右边索引值，否则还是左边索引值
        {
            cu_left++;
        }
        if (a[current] >=a[cu_left])//如果父节点大于子节点中的最大值就结束
        {
            break;
        }
        else
        {
            swap(a[cu_left], a[current]);//交换使得父节点的值大于左右子节点，完成一次小的大根堆排序
        }
    }

}
void HeapSort(int* a, int N)//定义初始化和排序函数
{
    for (int i = N / 2 - 1; i >= 0; i--)//初始化大根堆，从最大的父节点索引值开始向上构建大根堆
    {
        BigHeap_Down(a, i, N - 1);
    }
    for (int i = N-1; i>0; i--)//将第一位最大的值与最后一位交换，然后重新进行大根堆排序，多次重复直到完成排序
    {
        swap(a[0], a[i]);
        BigHeap_Down(a, 0, i-1);
    }
}
