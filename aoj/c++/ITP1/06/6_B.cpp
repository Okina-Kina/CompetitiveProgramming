#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

int main(){
    int n;
    cin >> n;

    const int size = 13;
    vector<bool> s(size), h(size), c(size), d(size);

    for(int i = 0; i < size; i++)
        s[i] = h[i] = c[i] = d[i] = false;

    for(int i = 0; i < n; i++){
        char kind;
        int number;
        cin >> kind >> number;    
        
        switch(kind){
            case 'S':
                s[number - 1] = true;
                break;
            case 'H':
                h[number - 1] = true;
                break;
            case 'C':
                c[number - 1] = true;
                break;
            case 'D':
                d[number - 1] = true;
                break;
        }
    }

    for(int i = 0; i < size; i++)
        if(!s[i]) cout << "S " << i+1 << endl;

    for(int i = 0; i < size; i++)
        if(!h[i]) cout << "H " << i+1 << endl;

    for(int i = 0; i < size; i++)
        if(!c[i]) cout << "C " << i+1 << endl;

    for(int i = 0; i < size; i++)
        if(!d[i]) cout << "D " << i+1 << endl;
   
    return 0;
}