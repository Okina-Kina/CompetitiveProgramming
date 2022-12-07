#include <iostream>
using namespace std;

int main(void){
    double sum = 0;
    double avg = 0;
    for(int i = 0; i < 5; i++){
        int tmp = 0;
        cin >> tmp;
        sum += tmp;        
    }

    avg = ((double)sum) / 5;
    cout << avg << endl;
}