#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

int main(){
    vector<int>h,w;

    while(true){
        int tmpH, tmpW;
        cin >> tmpH >> tmpW;

        if(tmpH ==0 && tmpW == 0)break;

        h.push_back(tmpH);
        w.push_back(tmpW);
    }

    for(int n = 0; n < h.size(); n++){
        for(int i = 0; i < h[n]; i++){
            for(int j = 0; j < w[n]; j++ ){
                if(i == 0 || i == h[n] -1
                || j == 0 || j == w[n] - 1)cout << "#";
                else cout << ".";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}