#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

int main(){
    int a,b;
    cin >> a >> b;

    int d = a/b;
    int r = a%b;
    double f = (double)a/b;

    cout << fixed
         << d << " " 
         << r << " "
         << setprecision(8)
         << f << endl;

    return 0;
}