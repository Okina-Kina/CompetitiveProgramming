#include <bits/stdc++.h>
using namespace std;

int main() {
    int k,n,f;
    cin >> k >> n >> f;

    vector<int> a(f);
    for(int i = 0; i < f; i++) cin >> a.at(i);

    //全粒
    int all = k * n;

    for(auto i : a) all -= i;

    if(all < 0)    cout << -1 << endl;
    else cout << all << endl;

    return 0;
}