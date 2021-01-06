#include<iostream>
#include<stdio.h>
#include<stack>
using std::stack;
using namespace std;
//字符数组计算函数
double CalcuChar(char *InputChar);
//优先级高低判断函数,运算优先级：（） > */ > +-
int priority(char c);
//比较当前字符和符号栈栈顶元素优先级高低
bool ComparaPriority(char a, char b);
//计算函数，计算格式为“A（+or-or*or/）B”
int CalcuAB(int left, char op, int right);
int main()
{
    int Result;
    int Length;
    cout << "目测字符串长度为：";
    cin >> Length;
    char *InputChar=new char[Length];
    cout << "请输入要计算的表达式（要求：数字最大99,连续输入不要有空格）：";
    cin >> InputChar;
    //调用计算函数，传递字符数组
    Result=CalcuChar(&InputChar[0]);
    cout << "计算的结果为：" << Result << endl;
    delete[] InputChar;
}
double CalcuChar(char* InputChar)
{
    //创建操作数栈
    stack<int> NumberStack;
    //创建符号栈
    stack<char> SymbolStack;
    int UnitTens=0;         //两位数载体
    int LeftNumberA;   //A
    int RightNumnerB;  //B
    char Operator = '\0';    // + - * /
    //遍历需要计算的字符串
    //算法思想：遍历
    for (int i = 0; InputChar[i] != '\0'; i++)
    {
        if (InputChar[i] == '+' || InputChar[i] == '-' || InputChar[i] == '*' || InputChar[i] == '/' || InputChar[i] == '(' || InputChar[i] == ')')
        {
            //当前遍历到的符号位‘（’,则进行入栈操作
            if (InputChar[i] == '(')
            {
                SymbolStack.push(InputChar[i]);
            }
            //当前符号是‘）’，执行出栈栈操作，直到碰到左括号
            else if (InputChar[i] == ')')
            {
                //出栈顺序，先确定栈顶非‘（’，防止表达式为空
                while (SymbolStack.top() != '(')
                {
                    //B先出栈
                    RightNumnerB = NumberStack.top();
                    NumberStack.pop();
                    //A再出栈
                    LeftNumberA = NumberStack.top();
                    NumberStack.pop();
                    //A和B运算类型出栈
                    Operator = SymbolStack.top();
                    SymbolStack.pop();
                    //调用计算模块，并将计算结果入数字栈
                    NumberStack.push(CalcuAB(LeftNumberA, Operator, RightNumnerB));
                }
                SymbolStack.pop();//?????????????????????
            }
            else//如果是其他操作符，判断优先级
            {
                //P判定符号栈是否为空
                if (SymbolStack.empty())
                {
                    SymbolStack.push(InputChar[i]);
                }
                else
                {
                    //栈顶元素优先级比当前运算符优先级高，且栈顶符号不是左括号
                    while (!SymbolStack.empty() && ComparaPriority(SymbolStack.top(), InputChar[i]) && SymbolStack.top() != '(')
                    {   
                        //B
                        RightNumnerB = NumberStack.top();
                        NumberStack.pop();
                        //A
                        LeftNumberA = NumberStack.top();
                        NumberStack.pop();
                        //运算符
                        Operator = SymbolStack.top();
                        SymbolStack.pop();
                        //计算
                        NumberStack.push(CalcuAB(LeftNumberA, Operator, RightNumnerB));
                    }
                    SymbolStack.push(InputChar[i]);
                }
            }

        }
        //如果是数字，直接进行入栈操作
        if ((InputChar[i] - '0') >= 0 && (InputChar[i] - '0') <= 9)
        {
            //继续判断下一位是否为数字，此处数字最多位数为两位
            while ((InputChar[i] - '0') >= 0 && (InputChar[i] - '0') <= 9)
            {
                UnitTens = 10 * UnitTens + (InputChar[i] - '0');
                i++;
            }
            NumberStack.push(UnitTens);
            i--;
            UnitTens = 0;
        }

    }
    //直至清空符号栈
    while (!SymbolStack.empty())
    {
        RightNumnerB = NumberStack.top();
        NumberStack.pop();
        LeftNumberA = NumberStack.top();
        NumberStack.pop();
        Operator = SymbolStack.top();
        SymbolStack.pop();
        NumberStack.push(CalcuAB(LeftNumberA, Operator, RightNumnerB));
    }
    return NumberStack.top();
}
//优先级判断模块
int priority(char c)
{
    switch (c)
    {
    case'+':
    case'-':
        return 1;
    case'*':
    case'/':
        return 2;
    case'(':
    case')':
        return 3;
    }
}
bool ComparaPriority(char a, char b)
{
    if (priority(a) >= priority(b))
    {
        return true;
    }
    else
    {
        return false;
    }
}
//数字计算模块
int CalcuAB(int left, char op, int right)
{
    switch (op)
    {
    case '+':
        return left + right;
    case '-':
        return left - right;
    case '*':
        return left * right;
    case '/':
        return left / right;
    }
}