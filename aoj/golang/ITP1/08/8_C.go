#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

int main(){
    vector<string> lines;
    string tmp;

    while(cin >> tmp){
        lines.push_back(tmp);
    }

    int sum = 0;

    for(int i = 'a'; i <= 'z'; i++){
        sum = 0;
        for(int j = 0; j < lines.size(); j++){
            for(int k = 0; k < lines.at(j).size(); k++){
                char c = tolower(lines.at(j).at(k));
                if(int(c) == i)sum++;
            }
        }        
        cout << char(i) << " : " << sum << endl;
    }

    return 0;
}