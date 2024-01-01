#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    vector<int> n;
    int tmp = 0;
    
    for(int i = 0; i < 3; i++){
        cin >> tmp;
        n.push_back(tmp);
    }

    sort(n.begin(), n.end());

    for(int i = 0; i < 3; i++){
        if(i != 2)
            cout << n[i] << " ";
        else  
            cout << n[i] << endl;
    }

    return 0;
}