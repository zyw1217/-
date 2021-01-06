#include <iostream>
using namespace std;

int xuandawang(int m,int n)
{
	int shuzu[m],biaozhi[m],a,c,d,x=0;
	for(int i=0;i<m;i++)
	{
		shuzu[i]=i+1;
		biaozhi[i]=1;
	}
	
	for(int i=1;i<m;i++){
	a=n;
	while(1){
	
		if(biaozhi[x]==1){
			a=a-1;	
			}
		x++;while(biaozhi[x]==0)x++;
		if(x>=m)x=x-m;
	
		if(a==1)break;
		}
	biaozhi[x]=0;
	}
	for(int i=0;i<m;i++)
		if(biaozhi[i]==1)d=i;
	c=shuzu[d];
	return c;
}

int main ()
{
	int m,n,c;
	cin>>m>>n;
	c=xuandawang(m,n);
	cout<<"按照"<<m<<"个猴子，数"<<n<<"个数的方法，猴王是"<<c<<"号";
	return 0;
}
循环链表：
#include <iostream>  
using namespace std;  

struct monkey              
{  
	int num;                  
	monkey *next;            
};  

monkey *head,*tail;         

void creat(int m)          
{                                           
	monkey *p,*q;         
	p=new monkey;          
	p->num=1;              
	p->next=NULL;         
	head=p;                  
	q=p;                   
	for(int i=2;i<=m;i++)     
		{  
  		p=new monkey;      
  		p->num=i;                
 		q->next=p;           
		q=p;                  
		p->next=NULL;      
		}  
	tail=q;               
	tail->next=head;     
}  


void select(int n)  
{                     
	int x=0;             
	monkey *p,*q;       
	q=tail;            
	do                    
	{  
 		p=q->next;        
		x=x+1;        
  		if(x%n==0)   
		{  
  	 		//cout<<"被删除的猴子号为"<<p->num<<"号\n";     
			q->next=p->next;       
			delete p;                
			p=NULL;    
		}    
		else  
   		q=p;              
	}while(q!=q->next);      
	head=q;                   
}                              

int main()                   
{  
int m,n;                  
head=NULL;               
cin>>m>>n;;                 
creat(m);              
select(n);              
cout<<"按照"<<m<<"个猴子，数"<<n<<"个数的方法，猴王是"<<head->num<<"号";
delete head;           
return 0;  
}  

