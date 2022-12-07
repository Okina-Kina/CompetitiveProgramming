#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int n = 0;
    cin >> n;

    int i = 0;

    int idx, value;
    pair<int,int> maxPair;

    for(i = 0; i < n; i++){
        cin >> idx >> value;
        if(maxPair.second < value){
            maxPair.first = idx;
            maxPair.second =value;
        }
    }

    cout << maxPair.first << endl;
}