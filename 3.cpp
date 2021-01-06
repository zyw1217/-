#include<iostream>
using namespace std;

struct jxj{
    int yuwen,shuxue,waiyu,zongfen;
    int id;
    };
    
jxj student[10];

void paixu(int n)
{
	for(int i=n-1;i>=1;i--)
        for(int j=1;j<=i;j++)
        {    if(student[j].zongfen<student[j+1].zongfen)            
            swap(student[j],student[j+1]);
            else if((student[j].zongfen==student[j+1].zongfen)&&(student[j].yuwen<student[j+1].yuwen))
              swap(student[j],student[j+1]);    
            else if((student[j].zongfen==student[j+1].zongfen)&&(student[j].yuwen==student[j+1].yuwen)&&student[j].id>student[j+1].id)
                swap(student[j],student[j+1]);
        }    
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	student[i].id=i;
        cin>>student[i].yuwen>>student[i].shuxue>>student[i].waiyu;
        student[i].zongfen=student[i].shuxue+student[i].yuwen+student[i].waiyu;
    }
	paixu(n);
    for(int i=1;i<=5;i++)
    cout<<student[i].id<<" "<<student[i].zongfen<<endl;
    return 0;
}

