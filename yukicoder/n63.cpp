#include <bits/stdc++.h>
using namespace std;

int main() {
    long l,k;
    cin >> l >> k;

    int i = 0;
    int ans = 0;
    int count = 0;

    while(0 <= i){
        i = (l-k*2*(count+1));
        if(0 < i) count++;
        else break;
    }

    ans = (count * k);

    cout << ans << endl;

    return 0;
}