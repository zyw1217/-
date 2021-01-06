#include<stdio.h>
#include<cstring>
struct data{
	int chi;
	int eng;
	int math;
	int num;
	int sum;
}a[30],temp;
int main()
{
	int i,j,k,n;
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
	{
		scanf("%d %d %d",&a[i].chi,&a[i].eng,&a[i].math);
		a[i].sum=a[i].chi+a[i].eng+a[i].math;
		a[i].num=i+1;
	}
	for(k=0;k<=n-1;k++)
		for (j=0;j<=n-1;j++)
		{   
			if(a[k].sum>a[j].sum)
			{temp=a[k];a[k]=a[j];a[j]=temp;}
				else if((a[k].sum)==(a[j].sum) && (a[k].chi)>(a[j].chi))
				{temp=a[k];a[k]=a[j];a[j]=temp;}
				else if((a[k].chi)==(a[j].chi) && (a[k].sum)==(a[j].sum) && (a[k].num)<(a[j].num))
				{temp=a[k];a[k]=a[j];a[j]=temp;}
		}
	for(i=0;i<=4;i++)
		printf("%d %d\n",a[i].num ,a[i].sum);
}

