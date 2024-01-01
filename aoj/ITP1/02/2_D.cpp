#include<iostream>

using namespace std;

int main(){
    int w,h;
    int x,y;
    int r;

    cin >> w >> h >> x >> y >> r;

    if(x-r < 0 
    || w < x + r
    || y-r < 0
    || h < y + r)
        cout << "No" << endl;

    else 
        cout << "Yes" << endl;

    return 0;
}