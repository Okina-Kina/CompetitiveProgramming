#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    long n;
    cin >> n;

    vector<long> a(n);
    for(int i = 0; i < n; i++) cin >> a.at(i);

    long s = 0;
    for(auto i = 0; i < n; i++) s += a.at(i);

    cout << s << endl;


    return 0;
}