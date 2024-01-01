#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int n = 10;
    int i = 0;

    int tmp = 0;
    int sum = 0;
    for(i = 0; i < n; i++){
        cin >> tmp;
        if(tmp < 40) tmp = 40;
        sum += tmp;
    }    

    int ave = ((double)sum)/(double)n;

    cout << ave << endl;
}