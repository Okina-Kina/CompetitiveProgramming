#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

int main(){
    string s,p;
    cin >> s >> p;

    s = s + s;

    if(s.find(p) != string::npos) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}