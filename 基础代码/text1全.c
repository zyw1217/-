.//（1）通过返回值将新数c传给主函数；
#include <stdio.h>
int fun(int a, int b)
{   int c, asw, agw, bsw, bgw;
	asw = a/10;
	agw = a%10;
	bsw = b/10;
	bgw = b%10;
	c = asw * 10 + agw * 1000 + bsw + bgw * 100;
	return(c);
};
main()
{   int a, b, c;
	printf("输入a和b：\n");
    scanf_s("%d，%d", &a,&b);
    int fun(a, b);
	c = fun(a, b);
    printf("c=%d\n",c);
	return 0;}
//（2）通过引用参数将新数传给主函数：
#include <stdio.h>
void fun(int a, int b, int &n)
{
	int  asw, agw, bsw, bgw;
	asw = a / 10;
	agw = a % 10;
	bsw = b / 10;
	bgw = b % 10;
	n = asw * 10 + agw * 1000 + bsw + bgw * 100;
};
int main()
{
	int a, b;
	printf("输入a和b：\n");
	scanf_s("%d，%d", &a, &b);
	int n;
	fun(a, b, n);
	printf("结果为%d\n", n);
	return 0;
}
//(3)通过指针型参数将新数传给主函数:
#include <stdio.h>
void fun(int a, int b,long *c)
{
	int  asw, agw, bsw, bgw, * p;
	asw = a / 10;
	agw = a % 10;
	bsw = b / 10;
	bgw = b % 10;
	*c = asw * 10 + agw * 1000 + bsw + bgw * 100;
};
int main()
{
	int a, b;
	printf("输入a和b：\n");
	scanf_s("%d，%d", &a, &b);
	long c;
	fun(a, b,&c);
	printf("结果为:%d\n", c);
	return 0;
}
