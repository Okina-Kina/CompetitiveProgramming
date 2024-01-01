#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> B(9);

    for(auto& b:B) cin >> b;

    int ans = 0, sum = 0;
    for(int i = 1; i <= 10; i++)ans+=i;
    for(int i = 0; i < B.size(); i++) ans -= B.at(i);


    cout << ans << endl;

    return 0;
}