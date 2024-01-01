#include <iostream>

using namespace std;

int main(void){
    int min = 99999999;
    for(int i = 0; i < 5; i++){
        int tmp = 0;
        cin >> tmp;
        if(tmp < min) min = tmp;
    }
    cout << min << endl;
}