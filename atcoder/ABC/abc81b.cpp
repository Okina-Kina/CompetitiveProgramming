#include <bits/stdc++.h>
using namespace std;

int calc_sum(vector<int> a){
    int sum = 0;
    for(int i = 0; i < a.size(); i++){
        sum += a.at(i);
    }

    return sum;
}


int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for(auto& i : a) cin >> i;

    int sum = 0,cnt = 0;

    while(calc_sum(a) % 2 == 0){
        for(int i = 0; i < a.size(); i++){
            if(a.at(i) % 2 != 0){
                cout << cnt << endl;
                return 0;
            } 
            a.at(i) /= 2;
        }
        cnt++;
    }
    
    cout << cnt << endl;

    return 0;
}

