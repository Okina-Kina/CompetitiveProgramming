#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int i;
int n;
map<string,int> datas;

int main(void){
    cin >> n;

    string s;
    int v;
    // input
    for(i = 0; i < n; i++){
        cin >> s >> v;

        if(datas[s] != 0) datas[s] += v;
        else datas[s] = v;
    }

    // compare key
    vector<pair<string,int>> pairs;
    for(const auto &data : datas){
        pairs.emplace_back(data);
    }

    datas.clear();

    sort(pairs.begin(), pairs.end(),
    [](const pair<string,int> &s1, const pair<string,int> &s2){
        if(s1.first.length() != s2.first.length()) return s1.first.length() < s2.first.length();
        return s1.first < s2.first;
    });

    for(auto it = pairs.begin(); it != pairs.end(); it++){
        cout << it->first << " "  << it->second << endl;
    }

}