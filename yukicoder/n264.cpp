#include <bits/stdc++.h>
using namespace std;

int main() {
   int n,k;

   cin >> n >> k;

    // あいこ
   if(n == k) cout << "Drew" << endl;
   
   else if(n + k != 2){
       if(n - k < 0) cout << "Won" << endl;
       else cout << "Lost" << endl;
   }
   else{
       if(n - k < 0) cout << "Lost" << endl;
       else cout << "Won" << endl;
   }


    return 0;
}

