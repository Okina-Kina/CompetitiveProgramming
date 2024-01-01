#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int pizzaValue = 0;
    vector<int> topCnt(3);
    int topValue;
    int result = 0;

    cin >> pizzaValue;
    for(int i = 0; i < 3; i++){
        cin >> topCnt[i];
    }    
    for(int i = 0; i < 3; i++){
        cin >> topValue;
        result += topCnt[i] * topValue;
    }    

    cout << result + pizzaValue << endl;
}