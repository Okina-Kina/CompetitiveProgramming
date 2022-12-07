#include <iostream>
using namespace std;

int main(void){
    int max = 0;
    int min = 9999999;

    for(int i = 0; i < 5; i++){
        int tmp = 0;
        cin >> tmp;
        if(max < tmp) max = tmp;
        if(tmp < min) min = tmp;
    }
    cout << max << endl << min << endl;
}