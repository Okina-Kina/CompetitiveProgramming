#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

struct Problem{
    private:
        int _n, _x;
    public:
        Problem(int n, int x){
            _n = n;
            _x = x;
        }

        int GetCombinationCount(){
            int combCnt = 0;

            int sum = 0;
            for(int i = 1; i <= _n; i++){                
                for(int j = i+1; j <= _n; j++){
                    for(int k = j+1; k <= _n; k++){
                        sum = i + j + k;
                        if(sum == _x) combCnt++;
                    }                    
                }
            }

            return combCnt;
        }
};

int main(){
    int n = 3;
    int x = 0;

    vector<Problem> probs;
    while(true){
        cin >> n >> x;
        if(n == 0 && x == 0)break;

        probs.push_back(Problem(n,x));       
    }

    for(int i = 0; i < probs.size(); i++)
    {
        cout << probs.at(i).GetCombinationCount() << endl;
    }

    return 0;
}