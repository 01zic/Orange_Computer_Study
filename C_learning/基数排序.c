/*基本思想：
十进制的数的每一位都是在0-9之间的值
我们将一个无序的数组按照数组元素的位数从低到高
再按照0-9之间进行分配
然后将每一次分配完成的值重新排入原来的数组
重复多次直到数组元素的最高位*/
#include<stdio.h>
#include<stdlib.h>//动态分配内存函数
#define MAX_INDEX 10//0-9的序列
#define NUMBER_DIGHTS 20//假定数组元素的最高位数为20
int GetNumberInPoint(int number, int point);//获取数组元素指定位数上的值
void RadixSort(int* a, int N);//对数组进行基数排序
int main()
{
    int N;
    scanf("%d", &N);
    int a[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }
   RadixSort(a,N);
    for (int i = 0; i < N; i++)
    {
        printf("%d ", a[i]);
    }
}
int GetNumberInPoint(int number, int point)
{
    int temp = 1;
    for (; point >1; point--)
    {
        temp *= 10;
    }
    return (number / temp) % 10;
}
void RadixSort(int* a, int N)
{
    int *TemporaryArr[MAX_INDEX];//创建一个临时数组
    /*为临时数组分配内存，初始化临时数组，将数组每一行的第一个元素初始化为0，每一行的第一个元素作为每一行元素个数的计数值，所以每一行分配最大N+1个元素的内*/
    for (int i = 0; i< MAX_INDEX ;i++)
    {
        TemporaryArr[i] = (int*)malloc(sizeof(int) * (N+1));
        TemporaryArr[i][0] = 0;
    }
    for (int point = 1; point <= NUMBER_DIGHTS; point++)//遍历数组元素的所有位数
    {
       /*将数组所有元素对应的同一位数上的值按照0-9的序列分配*/
        for (int i = 0; i < N; i++)//遍历数组所有的元素
        {
          int RIndex= GetNumberInPoint(a[i], point);//获取数组元素上同一位数上的值作为行数
          int CIndex = ++TemporaryArr[RIndex][0];//每一行从0开始计数，并获取每一行相对应的列数
           TemporaryArr[RIndex][CIndex] = a[i];//将数组元素分配到相应的位置
        }
      /*将分配到0-9序列的数组元素重新按照0-9的顺序赋值给原来的数组*/
        for (int rIndex = 0,i=0; rIndex < MAX_INDEX; rIndex++)//从每一行开始遍历
        {
            for (int cIndex = 1; cIndex <= TemporaryArr[rIndex][0]; cIndex++)//每一行的第二列开始往后遍历
            {
                a[i++] = TemporaryArr[rIndex][cIndex];//按照0-9序列的顺序从上到下将所有的元素赋值给原来的数组
            }
            TemporaryArr[rIndex][0] = 0;//分配完每一行之后重置这一行的统计的元素个数值
        }
        
    }
}

