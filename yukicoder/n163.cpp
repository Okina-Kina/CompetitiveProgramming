#include <bits/stdc++.h>
using namespace std;

int main() {
   string s, o;

   cin >> s;

   for(const auto& c : s){
       if(isupper(c)) o += tolower(c);
       if(islower(c)) o += toupper(c);
    }

   cout << o << endl;

    return 0;
}

