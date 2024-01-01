#include <iostream>
#include<tuple>
#include <vector>
using namespace std;



int main(void){
    int n = 10;
    int point = 301;
    int index = 0;

    vector<int> values(3);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            cin >> values[j];
            int prev = point;
            if(0 <= prev - values[j])  point = prev - values[j];
        }
        if(point == 0){
            index = i + 1;
            break;
        }
    }
    cout << index << endl;
}