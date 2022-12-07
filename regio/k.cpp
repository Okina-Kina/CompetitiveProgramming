#include <iostream>
#include <vector>
#include<iomanip>
using namespace std;

int main(void){
    vector<pair<int,int>> values;    
    int n = 0;
    cin >> n;

    int sum = 0;
    double ave = 0;
    int tmp = 0;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        sum += tmp;
    }

    ave = ((double)sum)/n;

    cout << fixed << setprecision(1) << sum << " " << ave << endl;
}