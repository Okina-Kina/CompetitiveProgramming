#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,a,b;
    cin >> n >> a >> b;

    string s = "";
    int ans = 0;

    for(int i = 0; i <= n; i++){

        s = to_string(i);
        int sum = 0;

        for(auto c : s) sum += (c - '0');
        
        if(a <= sum && sum <= b)ans += i;
    }

    cout << ans << endl;
    
    return 0;
}

