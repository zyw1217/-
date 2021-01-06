#include <iostream>
using namespace std;

class Monkey{
    //id 为编号 status 0/1 淘汰/未淘汰
    int id;
    int status;
public:
    int getId() const {
        return id;
    }

    void setId(int id) {
        Monkey::id = id;
    }

    int getStatus() const {
        return status;
    }

    void setStatus(int i) {
        Monkey::status = i;
    }
};

int main (){
    int m = 0, n = 0, deNum, add = 0;
    cout << "猴子总数: m=";
    cin >> m;
    deNum = m;
    cout << "淘汰的次序: n=";
    cin >> n;
    Monkey monkey[99];
    // 赋予初值，和初始状态
    for (int i = 0; i < m+1; ++i) {
        monkey[i].setId(i);
        monkey[i].setStatus(1);
    }

    int outNum = 0;
    int res = 1;
    int out;
    //开始淘汰
    //
    while (deNum > 1) {
        for (int i = res; outNum < n; ++i) {
            if (i > m)
                i = 1;
            //判断数到的猴子是否已被淘汰
            if (monkey[i].getStatus() == 1){
                outNum++;
                if (outNum == n)
                    out = i;
            }
        }
        monkey[out].setStatus(0);
        deNum--;
        outNum = 0;
        res = out;

    }
    int king = 0;
    for (int j = 1; j <= m; ++j) {
        cout << "编号"<<monkey[j].getId() << "状态" << monkey[j].getStatus() << "\t";
        if (monkey[j].getStatus() == 1)
            king = j;
    }
    cout << endl;
    cout << "猴王是" << monkey[king].getId();
    return 0;
}