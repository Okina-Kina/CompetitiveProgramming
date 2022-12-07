#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int n = 0;
    cin >> n;

    int bgn=0, end =0;
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> bgn >> end;
        sum += abs(bgn-end);
    }

    int restBgn = 0;
    cin >> restBgn;

    int ideaVal = (n+1) * 3;
    int restEnd = restBgn + (ideaVal - sum);

    cout << restEnd << endl;
}