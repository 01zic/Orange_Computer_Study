//测试一个程序运行时间的函数
//预定义头文件include<time.h>
//方法clock：捕捉程序运行开始到clock()被调用是所耗费的时间，这个时间单位是clock tick，即“时钟打点”
//clock_t是clock()函数返回的变量类型
//时间（以秒为单位）是由 clock 函数返回的值除以 CLOCKS_PER_SEC 所得的值。 CLK_TCK 是等效的，但被视为已过时。
//如果程序运行的时间太短，我们可以重复运行这个程序，例如一万次，十万次。。。然后除以总次数返回运行一次程序所需要的时间
#include<stdio.h>
#include<time.h>
double duration;
clock_t start, end;
int main()
{
    start = clock();//计入从main函数开始一共走过了多少个clock tick
    Function();//函数自行填入
    end = clock();//计入从main函数开始到现在一共走过了多少个clock tick
    duration = (double)(end-start) / CLOCKS_PER_SEC;//以秒为单位

}
*********************************************************
