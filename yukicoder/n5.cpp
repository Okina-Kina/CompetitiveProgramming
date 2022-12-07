#include <bits/stdc++.h>
using namespace std;

int main() {
    int l,n;
    cin >> l >> n;

    vector<int> w(n);
    for(int i = 0; i < n; i++) cin >> w.at(i);

    sort(w.begin(), w.end(), less<int>());
    
    int ans = 0;
    for(;ans < n; ans++){
        l -= w[ans];
        if(l < 0)break;
    }

    cout << ans << endl;

    return 0;
}