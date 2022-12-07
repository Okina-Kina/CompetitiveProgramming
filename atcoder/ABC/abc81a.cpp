#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;

    cin >> s;

    int sum = 0;

    for(auto n : s)
        sum += (n - '0');

    cout << sum << endl;
    
    return 0;
}