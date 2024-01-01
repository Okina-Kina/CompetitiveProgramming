#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

int main(){
    string line;

    getline(cin,line);

    for(int i = 0; i < line.size(); i++){
        // 小文字→大文字
        if('a' <= line.at(i) && line.at(i) <= 'z')
            line.at(i) = toupper(line.at(i));
        // 大文字→小文字
        else 
            line.at(i)  = tolower(line.at(i));
    }

    cout << line << endl;

    return 0;
}