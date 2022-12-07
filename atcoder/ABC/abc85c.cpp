#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Y;
    cin >> N >> Y;

    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            int k = N - (i + j);
            int sum = 10000*i + 5000*j + 1000 * k;

            if(0 <= k && i + j + k == N && Y == sum){
                cout << to_string(i) + " " + to_string(j) + " " +to_string(k) << endl;
                return 0;
                }
            }
        }
    cout << "-1 -1 -1" << endl;


    return 0;
}

