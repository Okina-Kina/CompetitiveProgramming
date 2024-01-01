#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

int main(){
    vector<int> x,y;
    int tmpX = 1,tmpY = 1;

    while(true){
        cin >> tmpX >> tmpY;
        if(tmpX == 0 && tmpY == 0)break;

        x.push_back(tmpX);
        y.push_back(tmpY);
    }

    for(int i = 0; i < x.size(); i++){
        if(x[i] < y[i])
            cout << x[i] << " " << y[i] << endl;
        else 
            cout << y[i] << " " << x[i] << endl;
    
    }
    

    return 0;
}