#include <bits/stdc++.h>
using namespace std;

int main() {
   long l,m,n;
   int sum = 0;

   cin >> l >> m >> n;

   // 1￥ → 25￥
   // 25￥ → 100;
   if(n / 25 != 0) m += n/25;
   n = (n%25);
//    cout << "￥1:" + to_string(n) << endl;

   if(m/4 != 0) l += m/4;
   m = (m % 4);
//    cout << "￥25:" + to_string(m) << endl;

   if(l/10 != 0) l = l%10;
   
//    cout << "￥100:" + to_string(l) << endl;

   sum = l + m + n;

   // ¥100 → ¥1000
   cout << to_string(sum) << endl;

    return 0;
}

