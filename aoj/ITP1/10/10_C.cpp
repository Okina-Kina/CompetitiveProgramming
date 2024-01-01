#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>

using namespace std;

int main(){

    while(true){
        int n;
        cin >> n;

        if(n == 0) break;

        vector<int> s(n);
        for(int i = 0; i < n; i++)
            cin >> s.at(i);

        double a = 0;
        double m = 0;

        // 平均
        double sum = 0;
        for(int i = 0; i < n; i++){
            sum += s.at(i);
        }
        m = sum / n;

        // 分散
        for(int i = 0; i < n; i++){
            a += pow(s.at(i) - m, 2);
        }

        // 標準偏差
        a = sqrt(a/n);

        cout << fixed 
             << a << endl;
    }
    return 0;
}