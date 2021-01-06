#include <iostream>
#include <memory>
using namespace std;

int main()
{
	int m,n,z;
	cin>>n>>m;
	char ditu[m][n],zhongzhuan[m][n];
	
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin>>ditu[i][j];
	cin>>z;
	memcpy(zhongzhuan,ditu,sizeof(ditu));
	for(int x=0;x<z;x++){
		memcpy(ditu,zhongzhuan,sizeof(zhongzhuan));
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++){
		
			if(ditu[i][j]=='X'){
				if(i==0&&j==0){
					if(ditu[i+1][j]=='O')zhongzhuan[i+1][j]='X';
					if(ditu[i][j+1]=='O')zhongzhuan[i][j+1]='X';
				}
				else if(i==m-1&&j==n-1){
					if(ditu[i-1][j]=='O')zhongzhuan[i-1][j]='X';
					if(ditu[i][j-1]=='O')zhongzhuan[i][j-1]='X';
					} 
				else if(i==0&&j==n-1){
					if(ditu[i+1][j]=='O')zhongzhuan[i+1][j]='X';
					if(ditu[i][j-1]=='O')zhongzhuan[i][j-1]='X';
					} 
				else if(i==m-1&&j==0){
					if(ditu[i-1][j]=='O')zhongzhuan[i-1][j]='X';
					if(ditu[i][j+1]=='O')zhongzhuan[i][j+1]='X';
					} 
				else if(i==0&&j!=0&&j!=n-1){
					if(ditu[i+1][j]=='O')zhongzhuan[i+1][j]='X';
					if(ditu[i][j+1]=='O')zhongzhuan[i][j+1]='X';
					if(ditu[i][j-1]=='O')zhongzhuan[i][j-1]='X';
				}
				else if(i!=m-1&&i!=0&&j==0){
					if(ditu[i+1][j]=='O')zhongzhuan[i+1][j]='X';
					if(ditu[i][j+1]=='O')zhongzhuan[i][j+1]='X';
					if(ditu[i-1][j]=='O')zhongzhuan[i-1][j]='X';
				
				}
				else if(i!=m-1&&i!=0&&j==n-1){
					if(ditu[i+1][j]=='O')zhongzhuan[i+1][j]='X';
					if(ditu[i][j-1]=='O')zhongzhuan[i][j-1]='X';
					if(ditu[i-1][j]=='O')zhongzhuan[i-1][j]='X';
				
				}
				else if(i==m-1&&j!=0&&j!=n-1){
					if(ditu[i-1][j]=='O')zhongzhuan[i-1][j]='X';
					if(ditu[i][j+1]=='O')zhongzhuan[i][j+1]='X';
					if(ditu[i][j-1]=='O')zhongzhuan[i][j-1]='X';
				}
				else {
					if(ditu[i-1][j]=='O')zhongzhuan[i-1][j]='X';
					if(ditu[i][j+1]=='O')zhongzhuan[i][j+1]='X';
					if(ditu[i][j-1]=='O')zhongzhuan[i][j-1]='X';
					if(ditu[i+1][j]=='O')zhongzhuan[i+1][j]='X';
				}
			
			}
    	}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		  cout<<zhongzhuan[i][j];
		cout<<endl;
	}
	return 0;
}

