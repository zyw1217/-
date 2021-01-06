//
// Created by 74113 on 2020/12/21.
//

#include <iostream>

int func1(int a, int i);

void func2(int &c, int a, int i);

void func3(int *pInt, int a, int b);

using namespace std;
int main() {
    cout << "Hello, World!" << endl;
    int a,b;
    cin>>a>>b;
    cout << "a=" << a <<"\tb=" << b << endl;
    //方式1 通过返回值将新数c传给主函数
    int c = func1(a, b);

    //方式2 通过引用参数将新数传给主函数
    int c2;
    func2(c2 , a, b);

    //方式3
    int c3;
    func3(&c3, a, b);

    cout<< "通过返回值获得的新数c=" << c << endl;
    cout<< "通过引用参数获得的新数c=" << c2 << endl;
    cout<< "通过指针参数获得的新数c=" << c3 << endl;
    return 0;

}




//通过返回值将新数c传给主函数
int func1(int a, int b){
    //a的十位和个位依次存放在c数的十位和千位上，
    //b的十位和个位依次存放在c数的个位和百位上
    int ret = a/10 * 10 + a % 10 * 1000 + b / 10 + b % 10 * 100;
    return ret;
}
//通过引用参数将新数传给主函数
void func2(int &c, int a, int b) {
    c = a/10 * 10 + a % 10 * 1000 + b / 10 + b % 10 * 100;
}

//通过指针型参数将新数传给主函数
void func3(int *c3, int a, int b) {
    *c3 = a / 10 * 10 + a % 10 * 1000 + b / 10 + b % 10 * 100;
}