#include <iostream>
using namespace std;

int fun1 (int a,int b)
{
	int a1,a2,b1,b2,c;
	a1=a/10;
	a2=a%10;
	b1=b/10;
	b2=b%10;
	c=b1+a1*10+b2*100+a2*1000;
	return c;
}

void fun2 (int &a,int &b)
{
	int a1,a2,b1,b2,c;
	a1=a/10;
	a2=a%10;
	b1=b/10;
	b2=b%10;
	b=b1+a1*10+b2*100+a2*1000;

}

void fun3 (int *a,int *b)
{
	int a1,a2,b1,b2,c;
	a1=*a/10;
	a2=*a%10;
	b1=*b/10;
	b2=*b%10;
	*b=b1+a1*10+b2*100+a2*1000;

}

int main ()
{
	int a,b,c1,c3;
	cin>>a>>b;
//	c1=fun1(a,b); 
//	cout<<c1<<endl;
//	fun2(a,b); 
//	cout<<b<<endl;
	fun3(&a,&b); 
	cout<<b<<endl;
	return 0;
}

