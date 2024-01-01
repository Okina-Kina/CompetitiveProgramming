#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

int main(){
    string f;
    int m;
    
    while(true){
        cin >> f >> m;

        if(f == "-")break;

        vector<int> h(m);
        for(int i = 0; i < h.size(); i++){
            cin >> h.at(i);
        }

        string tmp(f);
        for(int i = 0; i < h.size(); i++){
            for(int j = 0; j < h.at(i); j++){
                tmp += tmp.at(0);
                tmp.erase(tmp.begin());
            }
        }

        f = tmp;
        cout << f << endl;
    }

    return 0;
}