#include <iostream>
using namespace std;
struct Stu{
    int id;
    float ChineseScore;
    float MathScore;
    float EnglishScore;
    float TotalScore;
};
void sort(Stu &n1, Stu &n2){
    Stu temp{};
    temp = n1;
    n1 = n2;
    n2 = temp;
}
int main(){
    Stu stu[99];

    cout << "排序问题（奖学金）" << endl;
    int n;
//    cout << "参加评选人数：";
    cin >> n;
    cout << endl;
    //赋值
    for (int i = 0; i < n; ++i) {
        stu[i].id = i + 1;
        cin >> stu[i].ChineseScore >> stu[i].MathScore >> stu[i].EnglishScore;
        stu[i].TotalScore = stu[i].ChineseScore + stu[i].MathScore + stu[i].EnglishScore;
        cout << endl;
    }
    //排序
    for (int j = 0; j < n; ++j) {
        //总成绩
        for (int k = j + 1; k < n; ++k) {
            //总成绩
            if (stu[j].TotalScore <= stu[k].TotalScore) {
                //语文
                if (stu[j].TotalScore == stu[k].TotalScore){
                    if (stu[j].ChineseScore <= stu[k].ChineseScore) {
                        //学号
                        if (stu[j].ChineseScore == stu[k].ChineseScore) {
                            if (stu[j].id > stu[k].id) {
                                sort(stu[j], stu[k]);
                                continue;
                            } else {
                                continue;
                            }
                        }else{
                            sort(stu[j], stu[k]);
                            continue;
                        }
                    }
                }else{
                    sort(stu[j], stu[k]);
                }
            }

        }
        cout << stu[j].id << " " << stu[j].TotalScore << "\t";
    }
    //奖学金获得者
    cout << endl;
    cout << "奖学金获得者为" << endl;
    for (int i = 0; i < 5; ++i) {

        cout << stu[i].id << " " << stu[i].TotalScore << endl;
    }
    return 0;
}
