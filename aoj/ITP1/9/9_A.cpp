#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<map>
#include<cctype>

using namespace std;

int main(){
    string w;
    cin >> w;

    vector<string> t;
    string tmp;
    while(cin >> tmp){
        t.push_back(tmp);
    }


    int findCnt = 0;
    for(int i = 0; i < t.size(); i++){
        transform(t.at(i).begin(),t.at(i).end(), t.at(i).begin(), ::tolower);
        if(t.at(i) == w) findCnt++;
    }

    cout << findCnt << endl;

    return 0;
}