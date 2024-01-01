#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

int main(){
    int n;
    cin >> n;

    int building = 4, floor = 3, room = 10;
    int house[building][floor][room];

    for(int i = 0; i < building; i++)
        for(int j = 0; j < floor; j++)
            for(int k = 0; k < room; k++)
            house[i][j][k] = 0;

    int b,f,r,v;
    for(int i = 0; i < n; i++){
        cin >> b >> f >> r >> v;
        house[b-1][f-1][r-1] += v;
    }

    for(int i = 0; i < building; i++){
        for(int j = 0; j < floor; j++){
            for(int k = 0; k < room; k++){
                cout << " " << house[i][j][k];
            }
            cout << endl;
        }
        if(i < building -1)
            cout << "####################" << endl;   
    }

    return 0;
}