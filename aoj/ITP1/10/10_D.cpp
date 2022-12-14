#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> x(n),y(n);
    for(int i = 0; i < n; i++){
        cin >> x.at(i);
    }

    for(int i = 0; i < n; i++){
        cin >> y.at(i);
    }


    double dist = 0;

    // p = 1
    for(int i = 0; i < n; i++){
        dist += abs(x.at(i) - y.at(i));
    }

    cout << fixed << dist << endl;

    // p = 2
    dist = 0;
    for(int i = 0; i < n; i++){
        dist += pow(abs(x.at(i)-y.at(i)), 2);
    }

    cout << fixed << sqrt(dist) << endl;

    // p = 3
    dist = 0;
    for(int i = 0; i < n; i++){
        dist += pow(abs(x.at(i) - y.at(i)), 3);
    }
    cout << fixed << cbrt(dist) << endl;

    // p = ∞
    double max = 0;
    for(int i = 0; i < n; i++){
        if(max < abs(x.at(i)-y.at(i)))
            max = abs(x.at(i) - y.at(i));
    }
    dist = max;

    cout << fixed << dist << endl;

    return 0;
}