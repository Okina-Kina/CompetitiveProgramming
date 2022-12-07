#include <bits/stdc++.h>
using namespace std;

int main() {
   long a,b;

   cin >> a >> b;

    for(int i = a; i <= b; i++){
        string s = to_string(i);

        // 3の倍数
        if(i % 3 == 0)cout << s << endl;
        else if(s.find("3") != string::npos)cout << s << endl;
    }

    return 0;
}

