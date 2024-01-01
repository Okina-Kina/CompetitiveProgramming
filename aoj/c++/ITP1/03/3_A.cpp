#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

int main(){
    vector<int> x;
    int tmp;

    while(true){
        cin >> tmp;
        if(tmp == 0)break;
        
        x.push_back(tmp);
    }

    for(int i = 0; i < x.size(); i++){
        cout << "Case " << i+1 << ": " << x[i] << endl;
    }

    return 0;
}