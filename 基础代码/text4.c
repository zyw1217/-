#include<stdio.h>
#include<string.h>
#define N 99
int main()
{
	int i,j,C;char str[N][N];
	int m,n,k=0;//nΪ�У�mΪ��
	scanf("%d %d\n",&m,&n);
    for(i=0;i<=n-1;i++)
	{    
		char *p;
		p=str[0];//str[0]Ϊ��ָ��,pָ��0��0��Ԫ�أ�p=a[0]+jָ��0��j��Ԫ�ء�
		for (i=0;i<n;i++)
			gets(str[i]);
	}
	scanf("%d",&C);
	while(k<C)
	{
		for(i=0;i<=n-1;i++)
			for(j=0;j<=m-1;j++)
			{
				if(str[i][j]=='X'&&i!=0&&i!=3)
				{
					if(str[i][j+1]!='P')
					{   //ȫ��ΪX
						if(str[i][j+1]!='X'&& str[i][j-1]!='X'&& str[i-1][j]!='X'&& str[i+1][j]!='X')
						{str[i][j-1]='A';str[i][j+1]='A';str[i-1][j]='A';str[i+1][j]='A';k++;}
						//һ��ΪX
						else if(str[i][j+1]=='X'&& str[i][j-1]!='X'&& str[i-1][j]!='X'&& str[i+1][j]!='X')
						{str[i][j-1]='A';str[i-1][j]='A';str[i+1][j]='A';k++;}
						else if(str[i][j+1]!='X'&& str[i][j-1]=='X'&& str[i-1][j]!='X'&& str[i+1][j]!='X')
						{str[i][j+1]='A';str[i-1][j]='A';str[i+1][j]='A';k++;}
						else if(str[i][j+1]!='X'&& str[i][j-1]!='X'&& str[i-1][j]=='X'&& str[i+1][j]!='X')
						{str[i][j-1]='A';str[i][j+1]='A';str[i+1][j]='A';k++;}
						else if(str[i][j+1]!='X'&& str[i][j-1]!='X'&& str[i-1][j]!='X'&& str[i+1][j]=='X')
						{str[i][j-1]='A';str[i][j+1]='A';str[i-1][j]='A';k++;}
                        //����ΪX
						else if(str[i][j+1]=='X'&& str[i][j-1]=='X'&& str[i-1][j]!='X'&& str[i+1][j]!='X')
						{str[i-1][j]='A';str[i+1][j]='A';k++;}
						else if(str[i][j+1]=='X'&& str[i][j-1]!='X'&& str[i-1][j]=='X'&& str[i+1][j]!='X')
						{str[i][j-1]='A';str[i+1][j]='A';k++;}
						else if(str[i][j+1]=='X'&& str[i][j-1]!='X'&& str[i-1][j]!='X'&& str[i+1][j]=='X')
						{str[i][j-1]='A';str[i-1][j]='A';k++;}
						else if(str[i][j+1]!='X'&& str[i][j-1]=='X'&& str[i-1][j]=='X'&& str[i+1][j]!='X')
						{str[i][j+1]='A';str[i+1][j]='A';k++;}
						else if(str[i][j+1]!='X'&& str[i][j-1]=='X'&& str[i-1][j]!='X'&& str[i+1][j]=='X')
						{str[i][j+1]='A';str[i-1][j]='A';k++;}
						else if(str[i][j+1]!='X'&& str[i][j-1]!='X'&& str[i-1][j]=='X'&& str[i+1][j]=='X')
						{str[i][j-1]='A';str[i][j+1]='A';k++;}
						//����ΪX
						else if(str[i][j+1]=='X'&& str[i][j-1]=='X'&& str[i-1][j]=='X'&& str[i+1][j]!='X')
						{str[i+1][j]='A';k++;}
						else if(str[i][j+1]!='X'&& str[i][j-1]=='X'&& str[i-1][j]=='X'&& str[i+1][j]=='X')
						{str[i][j+1]='A';k++;}
						else if(str[i][j+1]=='X'&& str[i][j-1]!='X'&& str[i-1][j]=='X'&& str[i+1][j]=='X')
						{str[i][j-1]='A';k++;}
						else if(str[i][j+1]=='X'&& str[i][j-1]=='X'&& str[i-1][j]!='X'&& str[i+1][j]=='X')
						{str[i+1][j]='A';k++;}
						
					}
					else if(str[i][j+1]=='P')
					{
						//ȫ��ΪX
						if(str[i][j-1]!='X'&& str[i-1][j]!='X'&& str[i+1][j]!='X')
						{str[i][j-1]='A';str[i-1][j]='A';str[i+1][j]='A';k++;}
						//������ΪX
						else if(str[i][j-1]=='X'&& str[i-1][j]!='X'&& str[i+1][j]!='X')
						{str[i-1][j]='A';str[i+1][j]='A';k++;}
						else if(str[i][j-1]!='X'&& str[i-1][j]=='X'&& str[i+1][j]!='X')
						{str[i][j-1]='A';str[i+1][j]='A';k++;}
						else if(str[i][j-1]!='X'&& str[i-1][j]!='X'&& str[i+1][j]=='X')
						{str[i][j-1]='A';str[i-1][j]='A';k++;}
						//һ����ΪX
                        else if(str[i][j-1]=='X'&& str[i-1][j]=='X'&& str[i+1][j]!='X')
						{str[i+1][j]='A';k++;}
                        else if(str[i][j-1]=='X'&& str[i-1][j]!='X'&& str[i+1][j]=='X')
						{str[i-1][j]='A';k++;}
                        else if(str[i][j-1]!='X'&& str[i-1][j]=='X'&& str[i+1][j]=='X')
						{str[i][j-1]='A';k++;}

					}
				}
				else if(str[i][j]=='X'&&i==0&&i!=3)
				{	
					if(str[i][j+1]!='P')
					{//ȫ��ΪX
						if(str[i][j+1]!='X'&& str[i][j-1]!='X'&& str[i+1][j]!='X')
						{str[i][j-1]='A';str[i][j+1]='A';str[i+1][j]='A';k++;}
						//������ΪX
						else if(str[i][j+1]=='X'&& str[i][j-1]!='X'&& str[i+1][j]!='X')
						{str[i][j-1]='A';str[i+1][j]='A';k++;}
						else if(str[i][j+1]!='X'&& str[i][j-1]=='X'&& str[i+1][j]!='X')
						{str[i][j+1]='A';str[i+1][j]='A';k++;}
						else if(str[i][j+1]!='X'&& str[i][j-1]!='X'&& str[i+1][j]=='X')
						{str[i][j-1]='A';str[i][j+1]='A';k++;}
						//һ������X
						else if(str[i][j+1]!='X'&& str[i][j-1]=='X'&& str[i+1][j]=='X')
						{str[i][j+1]='A';k++;}
						else if(str[i][j+1]=='X'&& str[i][j-1]!='X'&& str[i+1][j]=='X')
						{str[i][j-1]='A';}
						else if(str[i][j+1]=='X'&& str[i][j-1]=='X'&& str[i+1][j]!='X')
						{str[i+1][j]='A';k++;}
					}
					else if(str[i][j+1]=='P')
					{
						if(str[i][j-1]!='X'&& str[i+1][j]!='X')
						{str[i][j-1]='A';str[i+1][j]='A';k++;}
						else if(str[i][j-1]=='X'&& str[i+1][j]!='X')
						{str[i+1][j]='A';k++;}
						else if(str[i][j-1]!='X'&& str[i+1][j]=='X')
						{str[i][j-1]='A';k++;}
					}
				}
				else if (str[i][j]=='X'&&i!=0&&i==3)
				{
					if(str[i][j+1]!='P')
					{   //ȫ��ΪX
						if(str[i][j+1]!='X'&& str[i][j-1]!='X'&& str[i-1][j]!='X')
						{str[i][j-1]='A';str[i][j+1]='A';str[i-1][j]='A';k++;}
						//������ΪX
						else if(str[i][j+1]=='X'&& str[i][j-1]!='X'&& str[i-1][j]!='X')
						{str[i][j-1]='A';str[i-1][j]='A';k++;}
						else if(str[i][j+1]!='X'&& str[i][j-1]=='X'&& str[i-1][j]!='X')
						{str[i][j+1]='A';str[i-1][j]='A';k++;}
						else if(str[i][j+1]!='X'&& str[i][j-1]!='X'&& str[i-1][j]=='X')
						{str[i][j-1]='A';str[i][j+1]='A';k++;}
						//һ����ΪX
						else if(str[i][j+1]!='X'&& str[i][j-1]=='X'&& str[i-1][j]=='X')
						{str[i][j+1]='A';}
						else if(str[i][j+1]=='X'&& str[i][j-1]!='X'&& str[i-1][j]=='X')
						{str[i][j-1]='A';}
						else if(str[i][j+1]=='X'&& str[i][j-1]=='X'&& str[i-1][j]!='X')
						{str[i-1][j]='A';k++;}
					}
					else if(str[i][j+1]=='P')
					{
						if(str[i][j-1]!='X'&& str[i-1][j]!='X')
						{str[i][j-1]='A';str[i-1][j]='A';k++;}
						else if(str[i][j-1]=='X'&& str[i-1][j]!='X')
						{str[i-1][j]='A';k++;}
						else if(str[i][j-1]!='X'&& str[i-1][j]=='X')
						{str[i][j-1]='A';k++;}
					}
				}
			}
		for(i=0;i<=n-1;i++)
			for(j=0;j<=m-1;j++)
			{
				if(str[i][j]=='A')
					str[i][j]='X';
			}
	}
    for(i=0;i<=n-1;i++)
	{    
		for(j=0;j<=m-1;j++)
			printf("%c",str[i][j]);
		printf("\n");
	}

}
