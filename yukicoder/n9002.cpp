#include <iostream>
#include <string>

using namespace std;

int main() {
    long n;
    string s;

    // 標準入力から、空白や改行で区切られた整数と文字列を読み込む。
    cin >> n;

    for(int i = 1; i <= n; i++){
        if(i % 3 ==0) s += "Fizz";
        if(i % 5 ==0) s += "Buzz";
        
        if(i % 3 != 0 && i % 5 != 0) s += to_string(i);

        if(i != n) s += "\n";
    }

    cout << s << endl;

    return 0;
}