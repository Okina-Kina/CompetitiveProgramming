#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>

using namespace std;

int main(){
    int a,b,c;
    cin >> a >> b >> c;

    double rad = c * acos(-1)/180;

    double s = a*b*sin(rad) / 2;
    double l = sqrt(pow(a,2) + pow(b,2) - 2*a*b*cos(rad)) + a + b;
    double h = s * 2 / a;

    cout << fixed
         << s << endl
         << l << endl
         << h << endl;

    return 0;
}