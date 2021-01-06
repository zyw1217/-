#include<stdio.h>
#include<malloc.h>
struct Node
{
       int data;
       struct Node *next;
};//建立一个节点结构体
int main()
{
       struct Node *head, *s, *q, *t;
       int n, m, count=0, i;
       scanf("%d",&n);
       scanf("%d",&m);
       for(i=0; i<m; i++)
       {
              s=(struct Node *)malloc(sizeof(struct Node));
              s->data=i+1;
              s->next=NULL;
              if(i==0)
              {
                     head=s;
                     q=head;

              }
              else
              {
                     q->next=s;
                     q=q->next;
              }
       }//建立链表
       q->next=head;//形成循环单链表
       q=head;
       while(q->next!=head)
       {
              q=q->next;

       }
       q=head;
       do {
              count++;
              if(count==n-1)
              {
                     t=q->next;
                     q->next=t->next;
                     count=0;
                     free(t);
              }
              q=q->next;
       }
       while(q->next!=q);
       printf("%d\n ",q->data);

}