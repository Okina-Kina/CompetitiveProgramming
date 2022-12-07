#include <bits/stdc++.h>
using namespace std;

int calc_happy_day(vector<int> months, int num){
    int x = 0, y = 0;
    int sum = 0;

    for(int j = 0; j < months.size(); j++){
        x = months.at(j);
        for(int k = 1; k <= num; k++){
            y = (k / 10) + (k % 10);
            // cout << "x:" + to_string(x) + "/y:" + to_string(y) << endl;
            if(x == y) sum++;
        }
    }

    return sum;
}

int main() {
   vector<int> a = {1,3,5,7,8,10,12};
   vector<int> b = {2};
   vector<int> c = {4,6,9,11};
   int x = 0, y = 0;
   int sum = 0;

    sum += calc_happy_day(a,31);
    sum += calc_happy_day(b,28);
    sum += calc_happy_day(c,30);

    cout << sum << endl;

    return 0;
}

