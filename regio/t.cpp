#include <iostream>
#include <vector>
using namespace std;

int main(void){
  int n = 0;
  cin >> n;

  int cnt = 0;
  int sub = 1000 - n;

   for(sub; 500 <= sub; sub -=500) cnt++;
   for(sub; 100 <= sub; sub -=100) cnt++;
   for(sub; 50 <= sub; sub -=50) cnt++;
   for(sub; 10 <= sub; sub -=10) cnt++;
   for(sub; 5 <= sub; sub -=5) cnt++;
   for(sub; 1 <= sub; sub -=1) cnt++;

  cout << cnt << endl;
}