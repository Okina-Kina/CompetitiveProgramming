#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int sum = 0;
    // 標準入力から、空白や改行で区切られた整数と文字列を読み込む。
    cin >> s;

    for(const auto& c : s){
        if(isdigit(c)) sum += int(c-'0');
    }


    cout << sum << endl;

    // 整数と文字列を空白で区切って、標準出力に書き出す。
    return 0;
}