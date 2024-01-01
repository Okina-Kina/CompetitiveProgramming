#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

int main(){
    int r,c;
    cin >> r >> c;

    vector<vector<int>> sheet(r+1, vector<int>(c+1));

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> sheet.at(i).at(j);
        }
    }

    for(int i = 0; i < c; i++){
        int sum = 0;
        for(int j = 0; j < r; j++)sum += sheet.at(j).at(i);

        sheet.at(r).at(i) = sum;
    }


    for(int i = 0; i < r+1; i++){
        for(int j = 0; j < c+1; j++){
            if(j == c){
                int sum = 0;
                for(int k = 0; k < c; k++)sum += sheet.at(i).at(k);

                cout << sum;
            }
            else
               cout << sheet.at(i).at(j) << " ";
          
        }
        cout << endl;
    }

    return 0;
}