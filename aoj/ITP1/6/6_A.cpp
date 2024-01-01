#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> a(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];


    for(int i = a.size() - 1; 0 <= i; i--){
        cout << a[i];

        if(i != 0) 
          cout << " ";
    }
    cout << endl;

    return 0;
}
