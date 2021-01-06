#include<stdio.h>
int main()
{
    int n,m,a[99],M=0,num=0,i,t=0;
    scanf("%d %d",&n,&m); 
    for(i=0; i<m; i++)
    {
        a[i]=0;
    }
    while(M!=m-1)//剩余最后一只猴子结束循环
    {
        if(a[t]==0)
        {
            num++;t=t%m;
        }
        if(num==n)
        {
            num=0;//num重新计数
            a[t]=1;
            M++;
        }
		t++;
    }
    for(i=0; i<m; i++)
    {
        if(a[i]==0)
        {
            printf("%d",i+1);
            break;
        }
    }
    return 0;
}
