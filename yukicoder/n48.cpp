#include <bits/stdc++.h>
using namespace std;

int main() {
	int X, Y, L;
	cin >> X >> Y >> L;
	int ans = 0;
	if (X != 0) ans = 1;
	if (Y < 0) ans = 2;
	ans += (abs(X) + L - 1) / L;
	ans += (abs(Y) + L - 1) / L;
	cout << ans << endl;


    // 整数と文字列を空白で区切って、標準出力に書き出す。
    return 0;
}