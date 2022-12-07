#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int mul = 0;
    int point = 0;
    int result = 0;

    for(int i = 0; i < 3; i++){
        cin >> mul >> point;
        result += mul * point;
    }    

    cout << result << endl;
}