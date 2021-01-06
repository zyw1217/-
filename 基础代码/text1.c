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
	printf(" ‰»Îa∫Õb£∫\n");
    scanf("%d£¨%d", &a,&b);
    fun(a, b);
	c = fun(a, b);
    printf("c=%d\n",c);
	return 0;}
