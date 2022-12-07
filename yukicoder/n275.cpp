#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a.at(i);


    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(a.at(j) < a.at(i)){
                int tmp = a.at(i);
                a.at(i) = a.at(j);
                a.at(j) = tmp;
            }
        }
    }

    double r = 0;

    if(n % 2 == 0){
        r = a.at(n/2-1) + a.at(n/2);
        r /= 2;   
    }
    else if(n % 2 != 0)
        r = (a.at(n/2));        

    cout << r << endl;

    return 0;
}