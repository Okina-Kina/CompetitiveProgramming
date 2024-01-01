#include <iostream>
using namespace std;

int main(void){
    int count = 0;
    for(int i = 0; i < 5; i++){
        int tmp = 0;
        cin >> tmp;

        if(tmp%2 != 0)count++;
    }
    cout << count << endl;
}