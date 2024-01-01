#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

// ベクトルと行列の積
int main(){
    int n,m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    vector<int> b(m);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a.at(i).at(j);
        }
    }

    for(int i = 0; i < m; i++){
        cin >> b.at(i);
    }

    vector<int> c(n);
    for(int i = 0; i < c.size(); i++)
        c.at(i) = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            c.at(i) += a.at(i).at(j) * b.at(j);
        }
    }   

    for(int i = 0; i < n; i++)
        cout << c.at(i) << endl;

    return 0;
}