#include <bits/stdc++.h>
using namespace std;

int main() {
    
    // 標準入力から、空白や改行で区切られた整数と文字列を読み込む。
    cin >> n;

    while(n > b){
        b *= 2;
        count++;
    }

    cout << count << endl;

    // 整数と文字列を空白で区切って、標準出力に書き出す。
    return 0;
}