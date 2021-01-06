#include<iostream>
#include<stdio.h>
#include<stack>
using std::stack;
using namespace std;
//�ַ�������㺯��
double CalcuChar(char *InputChar);
//���ȼ��ߵ��жϺ���,�������ȼ������� > */ > +-
int priority(char c);
//�Ƚϵ�ǰ�ַ��ͷ���ջջ��Ԫ�����ȼ��ߵ�
bool ComparaPriority(char a, char b);
//���㺯���������ʽΪ��A��+or-or*or/��B��
int CalcuAB(int left, char op, int right);
int main()
{
    int Result;
    int Length;
    cout << "Ŀ���ַ�������Ϊ��";
    cin >> Length;
    char *InputChar=new char[Length];
    cout << "������Ҫ����ı��ʽ��Ҫ���������99,�������벻Ҫ�пո񣩣�";
    cin >> InputChar;
    //���ü��㺯���������ַ�����
    Result=CalcuChar(&InputChar[0]);
    cout << "����Ľ��Ϊ��" << Result << endl;
    delete[] InputChar;
}
double CalcuChar(char* InputChar)
{
    //����������ջ
    stack<int> NumberStack;
    //��������ջ
    stack<char> SymbolStack;
    int UnitTens=0;         //��λ������
    int LeftNumberA;   //A
    int RightNumnerB;  //B
    char Operator = '\0';    // + - * /
    //������Ҫ������ַ���
    //�㷨˼�룺����
    for (int i = 0; InputChar[i] != '\0'; i++)
    {
        if (InputChar[i] == '+' || InputChar[i] == '-' || InputChar[i] == '*' || InputChar[i] == '/' || InputChar[i] == '(' || InputChar[i] == ')')
        {
            //��ǰ�������ķ���λ������,�������ջ����
            if (InputChar[i] == '(')
            {
                SymbolStack.push(InputChar[i]);
            }
            //��ǰ�����ǡ�������ִ�г�ջջ������ֱ������������
            else if (InputChar[i] == ')')
            {
                //��ջ˳����ȷ��ջ���ǡ���������ֹ���ʽΪ��
                while (SymbolStack.top() != '(')
                {
                    //B�ȳ�ջ
                    RightNumnerB = NumberStack.top();
                    NumberStack.pop();
                    //A�ٳ�ջ
                    LeftNumberA = NumberStack.top();
                    NumberStack.pop();
                    //A��B�������ͳ�ջ
                    Operator = SymbolStack.top();
                    SymbolStack.pop();
                    //���ü���ģ�飬����������������ջ
                    NumberStack.push(CalcuAB(LeftNumberA, Operator, RightNumnerB));
                }
                SymbolStack.pop();//?????????????????????
            }
            else//������������������ж����ȼ�
            {
                //P�ж�����ջ�Ƿ�Ϊ��
                if (SymbolStack.empty())
                {
                    SymbolStack.push(InputChar[i]);
                }
                else
                {
                    //ջ��Ԫ�����ȼ��ȵ�ǰ��������ȼ��ߣ���ջ�����Ų���������
                    while (!SymbolStack.empty() && ComparaPriority(SymbolStack.top(), InputChar[i]) && SymbolStack.top() != '(')
                    {   
                        //B
                        RightNumnerB = NumberStack.top();
                        NumberStack.pop();
                        //A
                        LeftNumberA = NumberStack.top();
                        NumberStack.pop();
                        //�����
                        Operator = SymbolStack.top();
                        SymbolStack.pop();
                        //����
                        NumberStack.push(CalcuAB(LeftNumberA, Operator, RightNumnerB));
                    }
                    SymbolStack.push(InputChar[i]);
                }
            }

        }
        //��������֣�ֱ�ӽ�����ջ����
        if ((InputChar[i] - '0') >= 0 && (InputChar[i] - '0') <= 9)
        {
            //�����ж���һλ�Ƿ�Ϊ���֣��˴��������λ��Ϊ��λ
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
    //ֱ����շ���ջ
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
//���ȼ��ж�ģ��
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
//���ּ���ģ��
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