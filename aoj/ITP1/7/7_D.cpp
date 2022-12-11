#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

int main(){
    long n,m,l;
    cin >> n >> m >> l;

    vector<vector<long>> a(n,vector<long>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a.at(i).at(j);

    vector<vector<long>> b(m,vector<long>(l));
    for(int i = 0; i < m; i++)
        for(int j = 0; j < l; j++)
            cin >> b.at(i).at(j);

    vector<vector<long>> c(n,vector<long>(l));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < l; j++)
            c.at(i).at(j) = 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < l; j++)
            for(int k = 0; k < m; k++)
                c.at(i).at(j) += a.at(i).at(k) * b.at(k).at(j);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < l; j++){
            cout << c.at(i).at(j);
            if(j < l-1)  cout << " ";
        }
        cout << endl;
    }

    return 0;
}