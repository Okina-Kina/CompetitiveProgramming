#include <bits/stdc++.h>
using namespace std;
string divide[4] = {"dream", "dreamer", "erase", "eraser"};

int main() {
    string S;
    cin >> S;


    S = regex_replace(S, regex("eraser"), "0"); // 使われていない文字("0")に置換
    S = regex_replace(S, regex("erase"), "0");
    S = regex_replace(S, regex("dreamer"), "0");
    S = regex_replace(S, regex("dream"), "0");
    S = regex_replace(S, regex("0"), ""); // "0"を消す
    cout << (S == "" ? "YES" : "NO") << endl;
    return 0;
}
