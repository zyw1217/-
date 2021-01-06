#include"iostream"
#include "stack"
#include "string"
#include <cctype>
using namespace std;
 
bool IsOne(char c) {
	return (c == '+' || c == '-');
}
bool IsTwo(char c)
{
	return (c == '*' || c == '/');
}
string infix_postfix(string infix) {
	stack<char>stack;
	string result;
	for ( unsigned int i = 0; i < infix.size(); i++) 
	{
		if (isdigit(infix[i]) || infix[i] == '.')
		{
			while (isdigit(infix[i]) || infix[i] == '.')
			{
				result += infix[i++];
			}
			i--;
			result += ' ';
		}
		else if (IsOne(infix[i])) {

			while (stack.size() && (IsOne(stack.top()) || IsTwo(stack.top()))) {
				result += stack.top();
				stack.pop();
			}
			stack.push(infix[i]);
		}
		else if (infix[i] == ')') {
			while (stack.top() != '(') {
				result += stack.top();
				stack.pop();
			}
			stack.pop();
		}
		else if (IsTwo(infix[i])) {
			while (stack.size() && IsTwo(stack.top()))
			{
				result += stack.top();
				stack.pop();
			}
			stack.push(infix[i]);
		}
		else
			stack.push(infix[i]);
	}
	while (stack.size())
	{
		result += stack.top();
		stack.pop();
	}
	return result;
}
 
double TenTimes(int n) {
	double res = 1;
	for (int i = 0; i < n; i++) {
		res *= 10;
	}
	return res;
}
double Achieve(string s) {
	double res = 0;
	char c;
	int dec = 0;
	for (unsigned int i = 0; i < s.size(); i++) {
		c = s[i];
		if (c == '.')dec = i;
		else if (!dec)res = res * 10 + c - '0';
		else res += (c - '0') / TenTimes(i - dec);
	}
	return res;
}
double Calculate(string s) {
	double res ,t;
	stack<double>num;
	string temp;
	for (unsigned int i = 0; i < s.size(); i++) {
		temp = "";
		if (isdigit(s[i]) || s[i] == '.') {
			while (isdigit(s[i]) || s[i] == '.') {
				temp += s[i++];
				num.push(Achieve(temp));
			}
		}
		else {
			switch (s[i])
			{
			case '+':
				t = num.top();
				num.pop(); 
				t += num.top();
				num.pop();
				num.push(t);
				break;
			case '-':
				t = num.top();
				num.pop();
				t=num.top() - t;
				num.pop();
				num.push(t);
				break;
			default:
				cerr << "Fatal Error:Result would be wrong!" << endl;
				system("pause");
				break;
			}
		}
		}
	res = num.top();
	return res;
	}
int main() {
	string mid, result;
	cin >> mid;
	result = infix_postfix(mid);
	cout << Calculate(result) << endl;
	system("pause");
	return 0;
}
