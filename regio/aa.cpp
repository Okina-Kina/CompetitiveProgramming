#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int n;
    cin >> n;

    vector<int> s(n);
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }

    int max = 0;
    int Si = 0;
    for(int i =0; i < n; i++){
       int prevSi = Si;
       int sum = prevSi + s[i];

       if(0 < sum)Si = sum;
       else Si = 0;
       
       if(Si > max)max = Si;
    }

    cout << max << endl;

}