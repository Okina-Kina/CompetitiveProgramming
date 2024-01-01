#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> a(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    long min = 1000000, max = -1000000, sum = 0;

    for(int i = 0; i < n; i++){
        if(max < a[i])max = a[i];
        if(a[i] < min)min = a[i];
        sum += a[i]; 
    }

    cout 
    << min << " "
    << max << " "
    << sum << endl;

    return 0;
}