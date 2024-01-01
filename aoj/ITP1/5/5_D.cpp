#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

int main(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        if(i % 3 == 0){
             cout << " " << i;
             continue;
        }

        int x = i;
        while(0 < x){
            if(x % 10 == 3){
              cout << " " << i;
              break;
            }

            x /= 10;
        }
    }

    cout << endl;

    return 0;
}