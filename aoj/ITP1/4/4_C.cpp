#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

int main(){
    vector<int> a,b;
    vector<string> op;

    int tmpA, tmpB;
    string tmpOp;

    while(true){
        cin >> tmpA >> tmpOp >> tmpB;
        if(tmpOp == "?")break;
        
        a.push_back(tmpA);
        b.push_back(tmpB);
        op.push_back(tmpOp);
    }

    for(int i = 0; i < a.size(); i++){
        if(op[i] == "+")
            cout << a[i] + b[i] << endl;
        if(op[i] == "-")
            cout << a[i] - b[i] << endl;
        if(op[i] == "*")
            cout << a[i] * b[i] << endl;
        if(op[i] == "/")
            cout << a[i] / b[i] << endl;
    }

    return 0;
}