#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int cnt = 0;
    cin >> cnt;

    int fst = 0, snd = 0;
    int s1 = 0, s2 = 0;
    for(int i = 0; i < cnt; i++){
        cin >> fst >> snd;
        if(fst < snd) s2 += snd;
        else if(fst == snd);
        else s1 += fst;
    }
    if(s1 < s2) cout << s2 << endl;
    else cout << s1 << endl;

}