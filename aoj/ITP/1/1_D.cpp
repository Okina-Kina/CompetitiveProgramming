#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

   int h =  n/3600;
   int m =  (n/60)%60;
   int s =  n%60;

    cout << h;
    cout << ":" << m;
    cout << ":" << s << endl;

    return 0;
}