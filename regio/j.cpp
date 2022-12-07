#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


int main(void){
    int n = 5;
    vector<int> bars(n);

    // input
    for(int i = 0; i < n; i++){
        cin >> bars[i];
    }
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            for(int k = j+1; k < n; k++){
                int sub = bars[i] - bars[j];
                int sum = bars[i] + bars[j];
                if(abs(sub) < bars[k] && bars[k] < sum)count++;
            }
        }
    }

    cout << count << endl;
}