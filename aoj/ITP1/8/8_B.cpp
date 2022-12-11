#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

int main(){
    vector<string> x;

    while(true){
        string tmp;
        cin >> tmp;

        if(tmp == "0")break;
        x.push_back(tmp);
    }

    int sum = 0;
    for(int i = 0; i < x.size(); i++){
        sum = 0;
        for(int j = 0; j < x.at(i).size(); j++){
            sum += int(x.at(i).at(j) - '0');                    
        }

        cout << sum << endl;
    }


    return 0;
}