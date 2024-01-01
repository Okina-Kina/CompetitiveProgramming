#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for(auto& i : a)cin >> i;

    sort(a.begin(),a.end(),greater<int>());

    int sum = 0;
    for(int i = 0; i < a.size(); i++){
        if(i % 2 == 0)sum += a.at(i);
        else sum -= a.at(i);
    }

    cout << sum << endl;

    return 0;
}

