#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>

using namespace std;

int main(){
    double x1, y1;
    double x2, y2;

    cin >> x1 >> y1 >> x2 >> y2;

    double dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

    cout << fixed << setprecision(6)
         << dist  << endl;

    return 0;
}