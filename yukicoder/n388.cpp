#include <bits/stdc++.h>
using namespace std;

int main() {
    int s,f;
    int n = 1;

    // 標準入力から、空白や改行で区切られた整数と文字列を読み込む。
    cin >> s >> f;

    n += s/f;

    cout << n << endl;

    return 0;
}