#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

int main(){
    int a,b,c;
    cin >> a >> b >> c;

    int ans = 0;
    for(int i = a; i <= b; i++){
        if(c % i == 0) ans++;
    }

    cout << ans << endl;

    return 0;
}