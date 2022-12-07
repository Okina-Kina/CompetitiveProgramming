#include <bits/stdc++.h>
using namespace std;

int main() {
    long d,p;
    cin >> d >> p;

    double yukicoda = (double)p / 100;
    yukicoda *= d;

    d += yukicoda;

    cout << d << endl;

    return 0;
}