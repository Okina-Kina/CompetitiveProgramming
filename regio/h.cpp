#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int max = 0;
    int min = 9999999;
    vector<int> n(5);

    for(int i = 0; i < 5; i++){
        cin >> n[i];
        if(max < n[i]) max = n[i];
        if(n[i] < min) min = n[i];
    }

    int sum = 0;
    for(int i = 0; i < 5; i++){
        sum += n[i];
    }
    sum -= max + min;
    cout << sum << endl;
}
 