#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>

using namespace std;

int main(){
    double r;
    cin >> r;

    double area = r * r * M_PI;
    double length = 2 * r * M_PI;

    cout << fixed
         << setprecision(6)
         << area << " " << length << endl;

    return 0;
}