#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

struct Score{
    int _m,_f,_r;

public:
    Score(int m ,int f,int r){
        _m = m;
        _f = f;
        _r = r;
    }

    string GetGrade(){
        if(_m == -1 || _f == -1) return "F";
        if(80 <= _m + _f) return "A";
        if(65 <= _m + _f && _m + _f < 80) return "B";
        if(50 <= _m + _f && _m + _f < 65) return "C";
        if(30 <= _m + _f && _m + _f < 50 && 50 <= _r) return "C";
        if(30 <= _m + _f && _m + _f < 50) return "D";
        return "F";
    }
};

int main(){
    vector<Score> datas;

    while(true){
        int m,f,r;
        cin >> m >> f >> r;
        if(m == -1 && f == -1 && r == -1)break;

        datas.push_back(Score(m,f,r));
    }

    for(int i = 0; i < datas.size(); i++){    
        cout << datas[i].GetGrade() << endl;
    }

    return 0;
}