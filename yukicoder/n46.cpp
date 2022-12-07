#include <bits/stdc++.h>
using namespace std;

int main(){

    int a,b;
    cin >> a >> b;

    // 整数値の切り上げ
    long s = (a + (b-1))/a;

    cout << s << endl;

    return 0;
}