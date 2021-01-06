#include<iostream>
#include<cctype>
using namespace std;
#define STACK_SIZE 64 /*ջ��С*/
#define TOP_OF_STACK -1 /*ջ��λ��*/
typedef int ElementType; /*ջԪ������*/

#define SUCCESS 0
#define FAILURE -1

/*����ջ�ṹ*/
typedef struct StackInfo
{
    int topOfStack; /*��¼ջ��λ��*/
    ElementType stack[STACK_SIZE]; /*ջ���飬Ҳ����ʹ�ö�̬����ʵ��*/
}StackInfo_st;


int stack_push(StackInfo_st *s,ElementType value);
int stack_pop(StackInfo_st *s,ElementType *value);
int stack_top(StackInfo_st *s,ElementType *value);
int stack_is_full(StackInfo_st *s);
int stack_is_empty(StackInfo_st *s);


/*��ջ��0��ʾ�ɣ���0��ʾ����*/
int stack_push(StackInfo_st *s,ElementType value)
{
    if(stack_is_full(s))
        return FAILURE;
    /*������topOfStack���ٸ�ֵ*/
    s->topOfStack++;
    s->stack[s->topOfStack] = value;
    return SUCCESS;
}

/*��ջ*/
int stack_pop(StackInfo_st *s,ElementType *value)
{
 /*�����ж�ջ�Ƿ�Ϊ��*/
    if(stack_is_empty(s))
        return FAILURE;
    *value = s->stack[s->topOfStack];
    s->topOfStack--;
    return SUCCESS;
}
/*����ջ��Ԫ��*/
int stack_top(StackInfo_st *s,ElementType *value)
{
    /*�����ж�ջ�Ƿ�Ϊ��*/
    if(stack_is_empty(s))
    {
     
            return FAILURE;
    }
    *value = s->stack[s->topOfStack];
    return SUCCESS;
}

/*�ж�ջ�Ƿ�������������1��δ������0*/
int stack_is_full(StackInfo_st *s)
{
    return s->topOfStack == STACK_SIZE - 1;
}
/*�ж�ջ�Ƿ�Ϊ�գ��շ���1���ǿշ���0*/
int stack_is_empty(StackInfo_st *s)
{
    return s->topOfStack == - 1;
}

/*���ڼ�¼���ŵ����ȼ��������˷���һЩ�ڴ棬�����Ż�*/
static char priority[128] = {0};
void priorityInit()
{
    /*��ʼ�����ȼ���ֵԽС�����ȼ�Խ��*/
    priority['+'] = 4;
    priority['-'] = 4;
    priority['*'] = 3;
    priority['/'] = 3;
    priority['('] = 1;
    priority[')'] = 1;


}
/*�Ƚ�����������ȼ�,op1���ȼ�����op2ʱ�����ش���0��ֵ*/
int priorityCompare(char op1,char op2)
{
    return priority[op2] - priority[op1];
}
/*��ջ�������Ͳ��������м���*/
int calcOp(StackInfo_st *nums,StackInfo_st *ops,int nowOp)
{
    int a ,b,op;
    stack_pop(ops,&op);

    if(SUCCESS != stack_pop(nums,&b))
    {
   
        return -1;
    }
    if(SUCCESS != stack_pop(nums,&a))
    {
     
        return 0;
    }
    

  
    switch(op)
    {
        case '+':
        {
      
            stack_push(nums,a+b);
            break;
        }
        case '-':
        {
            stack_push(nums,a-b);
            break;
        }
        case '*':
        {

            stack_push(nums,a*b);
            break;
        }
        case '/':
        {
        
            stack_push(nums,a/b);
            break;
        }
    }
    return 1;
}
int calc(const char* exp,int *result)
{
    if(NULL == exp || NULL == result)
        return FAILURE;
    /*����ջ�����ڱ�����*/
    StackInfo_st nums;
    nums.topOfStack = TOP_OF_STACK;
    
    /*���ڱ��������*/
    StackInfo_st ops;
    ops.topOfStack = TOP_OF_STACK;
    int index = 0;
    /*���ڱ�ǣ��ж���һ���Ƿ�Ϊ����*/
    int flag = 0;
    int temp = 0;
    int op ;
    while(0 != *exp)
    {   
        /*���������*/
        if(isdigit(*exp))
        {
     
             /*�����һ���������֣���ȡ��ջ������*/
            if(1 == flag)
               {
            
                stack_pop(&nums,&temp);
            
                }
            else
                temp = 0;
            flag = 1;
            temp = 10 * temp + *exp-'0';
     
            stack_push(&nums,temp);
        }
        /*����ǲ�����*/
        else if('/' == *exp || '*' == *exp || '+' == *exp || '-' == *exp)
        {
            flag = 0;
           
            while((ops.topOfStack > TOP_OF_STACK )&&(SUCCESS == stack_top(&ops,&op))&&'(' != op && ')'!=op&&(priorityCompare(*exp,op) <= 0))
            {
                calcOp(&nums, &ops,*exp);
            }
       
            stack_push(&ops,*exp);
        }
        /*������ֱ����ջ*/
        else if('(' == *exp )
        {
        
            flag = 0;
            stack_push(&ops,*exp);
        }
        /*�����ţ�����*/
        else if(')' ==*exp )
        {
   
            flag = 0;
            /*������ʱ�����ϼ��㣬ֱ������������*/
            while(SUCCESS == stack_top(&ops,&op) && '(' != op)
            {
                calcOp(&nums, &ops,*exp);
            }
            stack_pop(&ops,&op);
        }
        else
        {
            flag=0;
        }
     
        exp++;
    }
    /*����ʣ������ջ������*/
    while((!stack_is_empty(&ops)) && (!stack_is_empty(&nums)))
    {
        if(!calcOp(&nums, &ops,0));
   
    }
    stack_pop(&nums,&temp);
    /*���ջ�л������ݣ�˵�����ʽ����*/
    if((!stack_is_empty(&ops)) || (!stack_is_empty(&nums)));
  
    
    if(SUCCESS == stack_pop(&nums,&temp));
    
    *result = temp;
     return 0;
}
int main()
{

    int result;
    priorityInit();
    char exp[20];
	cin>>exp;
    calc(exp,&result);
    cout<<result<<endl;
    return 0;
}

